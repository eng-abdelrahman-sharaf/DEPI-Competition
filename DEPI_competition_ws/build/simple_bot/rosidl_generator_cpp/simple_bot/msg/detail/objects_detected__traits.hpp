// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice

#ifndef SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__TRAITS_HPP_
#define SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "simple_bot/msg/detail/objects_detected__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace simple_bot
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectsDetected & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_ball_detected
  {
    out << "is_ball_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_ball_detected, out);
    out << ", ";
  }

  // member: ball_position
  {
    if (msg.ball_position.size() == 0) {
      out << "ball_position: []";
    } else {
      out << "ball_position: [";
      size_t pending_items = msg.ball_position.size();
      for (auto item : msg.ball_position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_rline_visible
  {
    out << "is_rline_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.is_rline_visible, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectsDetected & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_ball_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_ball_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_ball_detected, out);
    out << "\n";
  }

  // member: ball_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ball_position.size() == 0) {
      out << "ball_position: []\n";
    } else {
      out << "ball_position:\n";
      for (auto item : msg.ball_position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: is_rline_visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_rline_visible: ";
    rosidl_generator_traits::value_to_yaml(msg.is_rline_visible, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectsDetected & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace simple_bot

namespace rosidl_generator_traits
{

[[deprecated("use simple_bot::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const simple_bot::msg::ObjectsDetected & msg,
  std::ostream & out, size_t indentation = 0)
{
  simple_bot::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use simple_bot::msg::to_yaml() instead")]]
inline std::string to_yaml(const simple_bot::msg::ObjectsDetected & msg)
{
  return simple_bot::msg::to_yaml(msg);
}

template<>
inline const char * data_type<simple_bot::msg::ObjectsDetected>()
{
  return "simple_bot::msg::ObjectsDetected";
}

template<>
inline const char * name<simple_bot::msg::ObjectsDetected>()
{
  return "simple_bot/msg/ObjectsDetected";
}

template<>
struct has_fixed_size<simple_bot::msg::ObjectsDetected>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<simple_bot::msg::ObjectsDetected>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<simple_bot::msg::ObjectsDetected>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__TRAITS_HPP_
