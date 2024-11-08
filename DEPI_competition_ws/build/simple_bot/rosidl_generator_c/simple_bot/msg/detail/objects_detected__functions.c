// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from simple_bot:msg/ObjectsDetected.idl
// generated code does not contain a copyright notice
#include "simple_bot/msg/detail/objects_detected__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
simple_bot__msg__ObjectsDetected__init(simple_bot__msg__ObjectsDetected * msg)
{
  if (!msg) {
    return false;
  }
  // is_ball_detected
  // ball_position
  // is_rline_visible
  return true;
}

void
simple_bot__msg__ObjectsDetected__fini(simple_bot__msg__ObjectsDetected * msg)
{
  if (!msg) {
    return;
  }
  // is_ball_detected
  // ball_position
  // is_rline_visible
}

bool
simple_bot__msg__ObjectsDetected__are_equal(const simple_bot__msg__ObjectsDetected * lhs, const simple_bot__msg__ObjectsDetected * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_ball_detected
  if (lhs->is_ball_detected != rhs->is_ball_detected) {
    return false;
  }
  // ball_position
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->ball_position[i] != rhs->ball_position[i]) {
      return false;
    }
  }
  // is_rline_visible
  if (lhs->is_rline_visible != rhs->is_rline_visible) {
    return false;
  }
  return true;
}

bool
simple_bot__msg__ObjectsDetected__copy(
  const simple_bot__msg__ObjectsDetected * input,
  simple_bot__msg__ObjectsDetected * output)
{
  if (!input || !output) {
    return false;
  }
  // is_ball_detected
  output->is_ball_detected = input->is_ball_detected;
  // ball_position
  for (size_t i = 0; i < 3; ++i) {
    output->ball_position[i] = input->ball_position[i];
  }
  // is_rline_visible
  output->is_rline_visible = input->is_rline_visible;
  return true;
}

simple_bot__msg__ObjectsDetected *
simple_bot__msg__ObjectsDetected__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  simple_bot__msg__ObjectsDetected * msg = (simple_bot__msg__ObjectsDetected *)allocator.allocate(sizeof(simple_bot__msg__ObjectsDetected), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(simple_bot__msg__ObjectsDetected));
  bool success = simple_bot__msg__ObjectsDetected__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
simple_bot__msg__ObjectsDetected__destroy(simple_bot__msg__ObjectsDetected * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    simple_bot__msg__ObjectsDetected__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
simple_bot__msg__ObjectsDetected__Sequence__init(simple_bot__msg__ObjectsDetected__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  simple_bot__msg__ObjectsDetected * data = NULL;

  if (size) {
    data = (simple_bot__msg__ObjectsDetected *)allocator.zero_allocate(size, sizeof(simple_bot__msg__ObjectsDetected), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = simple_bot__msg__ObjectsDetected__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        simple_bot__msg__ObjectsDetected__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
simple_bot__msg__ObjectsDetected__Sequence__fini(simple_bot__msg__ObjectsDetected__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      simple_bot__msg__ObjectsDetected__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

simple_bot__msg__ObjectsDetected__Sequence *
simple_bot__msg__ObjectsDetected__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  simple_bot__msg__ObjectsDetected__Sequence * array = (simple_bot__msg__ObjectsDetected__Sequence *)allocator.allocate(sizeof(simple_bot__msg__ObjectsDetected__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = simple_bot__msg__ObjectsDetected__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
simple_bot__msg__ObjectsDetected__Sequence__destroy(simple_bot__msg__ObjectsDetected__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    simple_bot__msg__ObjectsDetected__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
simple_bot__msg__ObjectsDetected__Sequence__are_equal(const simple_bot__msg__ObjectsDetected__Sequence * lhs, const simple_bot__msg__ObjectsDetected__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!simple_bot__msg__ObjectsDetected__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
simple_bot__msg__ObjectsDetected__Sequence__copy(
  const simple_bot__msg__ObjectsDetected__Sequence * input,
  simple_bot__msg__ObjectsDetected__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(simple_bot__msg__ObjectsDetected);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    simple_bot__msg__ObjectsDetected * data =
      (simple_bot__msg__ObjectsDetected *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!simple_bot__msg__ObjectsDetected__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          simple_bot__msg__ObjectsDetected__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!simple_bot__msg__ObjectsDetected__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
