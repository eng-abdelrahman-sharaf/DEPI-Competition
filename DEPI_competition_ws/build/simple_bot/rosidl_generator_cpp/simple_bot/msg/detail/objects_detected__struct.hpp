// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice

#ifndef SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_HPP_
#define SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__simple_bot__msg__ObjectsDetected __attribute__((deprecated))
#else
# define DEPRECATED__simple_bot__msg__ObjectsDetected __declspec(deprecated)
#endif

namespace simple_bot
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectsDetected_
{
  using Type = ObjectsDetected_<ContainerAllocator>;

  explicit ObjectsDetected_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_ball_detected = false;
      std::fill<typename std::array<int32_t, 3>::iterator, int32_t>(this->ball_position.begin(), this->ball_position.end(), 0l);
      this->is_rline_visible = false;
    }
  }

  explicit ObjectsDetected_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ball_position(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_ball_detected = false;
      std::fill<typename std::array<int32_t, 3>::iterator, int32_t>(this->ball_position.begin(), this->ball_position.end(), 0l);
      this->is_rline_visible = false;
    }
  }

  // field types and members
  using _is_ball_detected_type =
    bool;
  _is_ball_detected_type is_ball_detected;
  using _ball_position_type =
    std::array<int32_t, 3>;
  _ball_position_type ball_position;
  using _is_rline_visible_type =
    bool;
  _is_rline_visible_type is_rline_visible;

  // setters for named parameter idiom
  Type & set__is_ball_detected(
    const bool & _arg)
  {
    this->is_ball_detected = _arg;
    return *this;
  }
  Type & set__ball_position(
    const std::array<int32_t, 3> & _arg)
  {
    this->ball_position = _arg;
    return *this;
  }
  Type & set__is_rline_visible(
    const bool & _arg)
  {
    this->is_rline_visible = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    simple_bot::msg::ObjectsDetected_<ContainerAllocator> *;
  using ConstRawPtr =
    const simple_bot::msg::ObjectsDetected_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      simple_bot::msg::ObjectsDetected_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      simple_bot::msg::ObjectsDetected_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__simple_bot__msg__ObjectsDetected
    std::shared_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__simple_bot__msg__ObjectsDetected
    std::shared_ptr<simple_bot::msg::ObjectsDetected_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectsDetected_ & other) const
  {
    if (this->is_ball_detected != other.is_ball_detected) {
      return false;
    }
    if (this->ball_position != other.ball_position) {
      return false;
    }
    if (this->is_rline_visible != other.is_rline_visible) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectsDetected_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectsDetected_

// alias to use template instance with default allocator
using ObjectsDetected =
  simple_bot::msg::ObjectsDetected_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace simple_bot

#endif  // SIMPLE_BOT__MSG__DETAIL__OBJECTS_DETECTED__STRUCT_HPP_
