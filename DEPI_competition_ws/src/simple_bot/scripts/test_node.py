#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from std_msgs.msg import Bool
from geometry_msgs.msg import Point32
from tf_transformations import euler_from_quaternion
from simple_bot.msg import ObjectsDetected
import numpy as np

class BallKicker(Node):
    def __init__(self):
        super().__init__('ball_kicker')
        # Publisher for /cmd_vel to control robot movement
        self.cmd_vel_publisher = self.create_publisher(Twist, '/bot1/cmd_vel', 10)
        # Subscriber for the lidar data
        self.lidar_subscriber = self.create_subscription(LaserScan, '/bot1/scan', self.wall_callback, 10)
        #robot position subscriber
        self.position_robot_subscriber = self.create_subscription(Odometry, '/bot1/odom', self.position_robot_callback, 10)
        # Subscriber for the custom message
        self.ball_detection_subscriber = self.create_subscription(ObjectsDetected, '/ball_detection', self.ball_detection_callback, 10)

        self.position = [0.5,1.7,0.0]   # change the value to the position of the bot
        self.ball_position = None       # Ball position

        self.wall_detection_distance = 0.5  # Distance threshold for wall detection
        self.line_avoidance_distance = 0.5  # Distance threshold for line detection
        self.hit_distance = 0.5             # Distance threshold for hitting the ball

        self.is_avoiding_wall = False
        self.orientation_towards_line = False
        self.see_line = True
          
    def position_robot_callback(self, msg):
        self.position[0] = msg.pose.pose.position.x
        self.position[1] = msg.pose.pose.position.y
        self.position[2] = msg.pose.pose.position.z
        self.orientation_q = msg.pose.pose.orientation
        self.orientation_list = [self.orientation_q.x, self.orientation_q.y, self.orientation_q.z, self.orientation_q.w]
        (self.roll, self.pitch, self.yaw) = euler_from_quaternion(self.orientation_list)

        if -self.line_avoidance_distance < self.yaw < self.line_avoidance_distance:  
            self.orientation_towards_line = True
        else:
            self.orientation_towards_line = False
        

    def ball_position_callback(self, msg):
        self.is_ball_detected = msg.is_ball_detected
        self.ball_position = msg.ball_position  
        self.is_rline_visible = msg.is_rline_visible  

        if self.is_ball_detected:
            self.move_towards_ball()
        else:
            self.ball_position = None
            self.search_for_ball()

        if not self.is_rline_visible:
            self.line_avoidance_callback()

    def move_towards_ball(self):
        if self.ball_position is not None:
            dx = self.ball_position[0] - self.position[0]
            dy = self.ball_position[1] - self.position[1]
            distance_to_ball = np.sqrt(dx**2 + dy**2)
            if distance_to_ball > self.hit_distance:
                twist = Twist()
                if self.ball_left():
                    self.rotate_left()
                elif self.ball_right():
                    self.rotate_right()
                elif self.ball_infront():
                    self.move_forward()
                self.cmd_vel_publisher.publish(twist)
            else:
                self.move_forward()


      #**********line avoidance**********
    def line_avoidance_callback(self):
        if self.orientation_towards_line:
            self.stop()
            self.rotate_left()
        else:
            self.move_forward()



       #**********check for ball position**********
    def ball_left(self):
        if self.ball_position is not None:
            if self.ball_position[0] < self.position[0] and self.orientation_towards_line:
                return True
            else:
                return False
    def ball_right(self):
        if self.ball_position is not None:
            if self.ball_position[0] > self.position[0] and self.orientation_towards_line:
                return True
            else:
                return False
            
    def ball_infront(self):
        if self.ball_position is not None:
            if self.ball_position[0] == self.position[0] and self.orientation_towards_line:
                return True
            else:
                return False
            

       #**********wall avoidance**********
    def wall_callback(self, msg):
        #get the laser scan data
        ranges = np.array(msg.ranges)
        angle_min = msg.angle_min
        angle_increment = msg.angle_increment

        front_left_angle = 45  # Left of the robot
        front_right_angle = -45  # Right of the robot

        # get the index of the angles
        front_left_index = int((np.radians(front_left_angle) - angle_min) / angle_increment)
        front_right_index = int((np.radians(front_right_angle) - angle_min) / angle_increment)

        # Get the laser scan data
        front_left_range = np.min(ranges[front_left_index:front_left_index + 30]) 
        front_right_range = np.min(ranges[front_right_index - 30:front_right_index + 1]) 

        if front_left_range < self.wall_detection_distance and not self.is_avoiding_wall:
            self.get_logger().info("Wall detected on the left! Rotating  to avoid it.")  #remove logger if you want not important
            self.stop()  
            self.rotate_right()  
            self.is_avoiding_wall = True  


        elif front_right_range < self.wall_detection_distance and not self.is_avoiding_wall:
            self.get_logger().info("Wall detected on the right! Rotating to avoid it.")  #remove logger if you want not important
            self.stop() 
            self.rotate_left()  
            self.is_avoiding_wall = True 


        elif self.is_avoiding_wall:
            if front_left_range >= self.wall_detection_distance and front_right_range >= self.wall_detection_distance:
                self.is_avoiding_wall = False  
                self.move_forward()  


        #*******movement functions**********
    def rotate_left(self):
        twist = Twist()
        twist.angular.z = 0.5  
        self.cmd_vel_publisher.publish(twist)

    def rotate_right(self):
        twist = Twist()
        twist.angular.z = -0.5  
        self.cmd_vel_publisher.publish(twist)    

    def move_forward(self):
        twist = Twist()
        twist.linear.x = 0.5
        self.cmd_vel_publisher.publish(twist)


            #**********search for ball**********
    def search_for_ball(self):
        twist = Twist()
        if not self.is_ball_detected:
            twist.angular.z = 0.5
            self.cmd_vel_publisher.publish(twist)
        else:
            self.move_towards_ball()


    
    def stop(self):
        twist = Twist()
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.cmd_vel_publisher.publish(twist)



def main(args=None):
    rclpy.init(args=args)
    node = BallKicker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()