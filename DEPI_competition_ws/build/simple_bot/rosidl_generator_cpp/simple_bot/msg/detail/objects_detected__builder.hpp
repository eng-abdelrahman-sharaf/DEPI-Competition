// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice

#ifndef SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__BUILDER_HPP_
#define SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "simple_bot/msg/detail/objects_detected__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace simple_bot
{

namespace msg
{

namespace builder
{

class Init_ObjectsDetected_is_rline_visible
{
public:
  explicit Init_ObjectsDetected_is_rline_visible(::simple_bot::msg::ObjectsDetected & msg)
  : msg_(msg)
  {}
  ::simple_bot::msg::ObjectsDetected is_rline_visible(::simple_bot::msg::ObjectsDetected::_is_rline_visible_type arg)
  {
    msg_.is_rline_visible = std::move(arg);
    return std::move(msg_);
  }

private:
  ::simple_bot::msg::ObjectsDetected msg_;
};

class Init_ObjectsDetected_ball_position
{
public:
  explicit Init_ObjectsDetected_ball_position(::simple_bot::msg::ObjectsDetected & msg)
  : msg_(msg)
  {}
  Init_ObjectsDetected_is_rline_visible ball_position(::simple_bot::msg::ObjectsDetected::_ball_position_type arg)
  {
    msg_.ball_position = std::move(arg);
    return Init_ObjectsDetected_is_rline_visible(msg_);
  }

private:
  ::simple_bot::msg::ObjectsDetected msg_;
};

class Init_ObjectsDetected_is_ball_detected
{
public:
  Init_ObjectsDetected_is_ball_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectsDetected_ball_position is_ball_detected(::simple_bot::msg::ObjectsDetected::_is_ball_detected_type arg)
  {
    msg_.is_ball_detected = std::move(arg);
    return Init_ObjectsDetected_ball_position(msg_);
  }

private:
  ::simple_bot::msg::ObjectsDetected msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::simple_bot::msg::ObjectsDetected>()
{
  return simple_bot::msg::builder::Init_ObjectsDetected_is_ball_detected();
}

}  // namespace simple_bot

#endif  // SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__BUILDER_HPP_
