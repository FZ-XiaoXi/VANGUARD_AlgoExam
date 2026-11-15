// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from messages_cpp:msg/ItemInfo.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__FUNCTIONS_H_
#define MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "messages_cpp/msg/rosidl_generator_c__visibility_control.h"

#include "messages_cpp/msg/detail/item_info__struct.h"

/// Initialize msg/ItemInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * messages_cpp__msg__ItemInfo
 * )) before or use
 * messages_cpp__msg__ItemInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__init(messages_cpp__msg__ItemInfo * msg);

/// Finalize msg/ItemInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
void
messages_cpp__msg__ItemInfo__fini(messages_cpp__msg__ItemInfo * msg);

/// Create msg/ItemInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * messages_cpp__msg__ItemInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
messages_cpp__msg__ItemInfo *
messages_cpp__msg__ItemInfo__create();

/// Destroy msg/ItemInfo message.
/**
 * It calls
 * messages_cpp__msg__ItemInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
void
messages_cpp__msg__ItemInfo__destroy(messages_cpp__msg__ItemInfo * msg);

/// Check for msg/ItemInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__are_equal(const messages_cpp__msg__ItemInfo * lhs, const messages_cpp__msg__ItemInfo * rhs);

/// Copy a msg/ItemInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__copy(
  const messages_cpp__msg__ItemInfo * input,
  messages_cpp__msg__ItemInfo * output);

/// Initialize array of msg/ItemInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * messages_cpp__msg__ItemInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__Sequence__init(messages_cpp__msg__ItemInfo__Sequence * array, size_t size);

/// Finalize array of msg/ItemInfo messages.
/**
 * It calls
 * messages_cpp__msg__ItemInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
void
messages_cpp__msg__ItemInfo__Sequence__fini(messages_cpp__msg__ItemInfo__Sequence * array);

/// Create array of msg/ItemInfo messages.
/**
 * It allocates the memory for the array and calls
 * messages_cpp__msg__ItemInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
messages_cpp__msg__ItemInfo__Sequence *
messages_cpp__msg__ItemInfo__Sequence__create(size_t size);

/// Destroy array of msg/ItemInfo messages.
/**
 * It calls
 * messages_cpp__msg__ItemInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
void
messages_cpp__msg__ItemInfo__Sequence__destroy(messages_cpp__msg__ItemInfo__Sequence * array);

/// Check for msg/ItemInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__Sequence__are_equal(const messages_cpp__msg__ItemInfo__Sequence * lhs, const messages_cpp__msg__ItemInfo__Sequence * rhs);

/// Copy an array of msg/ItemInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages_cpp
bool
messages_cpp__msg__ItemInfo__Sequence__copy(
  const messages_cpp__msg__ItemInfo__Sequence * input,
  messages_cpp__msg__ItemInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__FUNCTIONS_H_
