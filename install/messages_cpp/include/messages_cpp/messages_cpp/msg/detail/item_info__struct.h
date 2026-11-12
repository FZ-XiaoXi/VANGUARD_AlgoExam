// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages_cpp:msg/ItemInfo.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_H_
#define MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ItemInfo in the package messages_cpp.
typedef struct messages_cpp__msg__ItemInfo
{
  int32_t id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String info;
} messages_cpp__msg__ItemInfo;

// Struct for a sequence of messages_cpp__msg__ItemInfo.
typedef struct messages_cpp__msg__ItemInfo__Sequence
{
  messages_cpp__msg__ItemInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages_cpp__msg__ItemInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_H_
