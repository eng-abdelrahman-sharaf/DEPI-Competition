// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "simple_bot/msg/detail/objects_detected__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace simple_bot
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ObjectsDetected_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) simple_bot::msg::ObjectsDetected(_init);
}

void ObjectsDetected_fini_function(void * message_memory)
{
  auto typed_message = static_cast<simple_bot::msg::ObjectsDetected *>(message_memory);
  typed_message->~ObjectsDetected();
}

size_t size_function__ObjectsDetected__ball_position(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ObjectsDetected__ball_position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int32_t, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ObjectsDetected__ball_position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int32_t, 3> *>(untyped_member);
  return &member[index];
}

void fetch_function__ObjectsDetected__ball_position(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__ObjectsDetected__ball_position(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__ObjectsDetected__ball_position(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__ObjectsDetected__ball_position(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ObjectsDetected_message_member_array[3] = {
  {
    "is_ball_detected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(simple_bot::msg::ObjectsDetected, is_ball_detected),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "ball_position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(simple_bot::msg::ObjectsDetected, ball_position),  // bytes offset in struct
    nullptr,  // default value
    size_function__ObjectsDetected__ball_position,  // size() function pointer
    get_const_function__ObjectsDetected__ball_position,  // get_const(index) function pointer
    get_function__ObjectsDetected__ball_position,  // get(index) function pointer
    fetch_function__ObjectsDetected__ball_position,  // fetch(index, &value) function pointer
    assign_function__ObjectsDetected__ball_position,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_rline_visible",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(simple_bot::msg::ObjectsDetected, is_rline_visible),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ObjectsDetected_message_members = {
  "simple_bot::msg",  // message namespace
  "ObjectsDetected",  // message name
  3,  // number of fields
  sizeof(simple_bot::msg::ObjectsDetected),
  ObjectsDetected_message_member_array,  // message members
  ObjectsDetected_init_function,  // function to initialize message memory (memory has to be allocated)
  ObjectsDetected_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ObjectsDetected_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ObjectsDetected_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace simple_bot


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<simple_bot::msg::ObjectsDetected>()
{
  return &::simple_bot::msg::rosidl_typesupport_introspection_cpp::ObjectsDetected_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, simple_bot, msg, ObjectsDetected)() {
  return &::simple_bot::msg::rosidl_typesupport_introspection_cpp::ObjectsDetected_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
