// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice

#ifndef SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_H_
#define SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ObjectsDetected in the package simple_bot.
typedef struct simple_bot__msg__ObjectsDetected
{
  bool is_ball_detected;
  /// x , y , z
  int32_t ball_position[3];
  /// true if the red line is visible
  bool is_rline_visible;
} simple_bot__msg__ObjectsDetected;

// Struct for a sequence of simple_bot__msg__ObjectsDetected.
typedef struct simple_bot__msg__ObjectsDetected__Sequence
{
  simple_bot__msg__ObjectsDetected * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} simple_bot__msg__ObjectsDetected__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_H_
