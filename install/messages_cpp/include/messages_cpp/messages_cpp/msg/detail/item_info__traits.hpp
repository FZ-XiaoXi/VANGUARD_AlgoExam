// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages_cpp:msg/ItemInfo.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__TRAITS_HPP_
#define MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages_cpp/msg/detail/item_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages_cpp
{

namespace msg
{

inline void to_flow_style_yaml(
  const ItemInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: info
  {
    out << "info: ";
    rosidl_generator_traits::value_to_yaml(msg.info, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ItemInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info: ";
    rosidl_generator_traits::value_to_yaml(msg.info, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ItemInfo & msg, bool use_flow_style = false)
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

}  // namespace messages_cpp

namespace rosidl_generator_traits
{

[[deprecated("use messages_cpp::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages_cpp::msg::ItemInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages_cpp::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages_cpp::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages_cpp::msg::ItemInfo & msg)
{
  return messages_cpp::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages_cpp::msg::ItemInfo>()
{
  return "messages_cpp::msg::ItemInfo";
}

template<>
inline const char * name<messages_cpp::msg::ItemInfo>()
{
  return "messages_cpp/msg/ItemInfo";
}

template<>
struct has_fixed_size<messages_cpp::msg::ItemInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages_cpp::msg::ItemInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages_cpp::msg::ItemInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__TRAITS_HPP_
