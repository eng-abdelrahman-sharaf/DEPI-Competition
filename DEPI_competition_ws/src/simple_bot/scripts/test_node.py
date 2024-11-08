#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from tf_transformations import euler_from_quaternion
import random
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

        self.position = [0.5,1.7,0.0]   # change the value to the position of the bot

        self.wall_detection_distance = 0.5  # Distance threshold for wall detection

        self.is_avoiding_wall = False
          
    def position_robot_callback(self, msg):
        self.position[0] = msg.pose.pose.position.x
        self.position[1] = msg.pose.pose.position.y
        self.position[2] = msg.pose.pose.position.z
        self.orientation_q = msg.pose.pose.orientation
        self.orientation_list = [self.orientation_q.x, self.orientation_q.y, self.orientation_q.z, self.orientation_q.w]
        (self.roll, self.pitch, self.yaw) = euler_from_quaternion(self.orientation_list)


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
            self.get_logger().info("Wall detected on the left! Rotating  to avoid it.")
            self.stop()  
            self.rotate_right()  
            self.is_avoiding_wall = True  


        elif front_right_range < self.wall_detection_distance and not self.is_avoiding_wall:
            self.get_logger().info("Wall detected on the right! Rotating to avoid it.")
            self.stop() 
            self.rotate_left()  
            self.is_avoiding_wall = True 


        elif self.is_avoiding_wall:
            if front_left_range >= self.wall_detection_distance and front_right_range >= self.wall_detection_distance:
                self.is_avoiding_wall = False  
                self.move_forward()  

    def rotate_left(self):
        twist = Twist()
        twist.angular.z = 0.5  
        self.cmd_vel_publisher.publish(twist)
        self.get_logger().info("Rotating left.")
        
    def rotate_right(self):
        twist = Twist()
        twist.angular.z = -0.5  
        self.cmd_vel_publisher.publish(twist)
        self.get_logger().info("Rotating right.")

    def move_forward(self):
        twist = Twist()
        twist.linear.x = 0.5
        self.cmd_vel_publisher.publish(twist)


    
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