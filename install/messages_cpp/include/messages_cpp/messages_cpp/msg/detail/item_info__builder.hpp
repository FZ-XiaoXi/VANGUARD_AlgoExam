// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages_cpp:msg/ItemInfo.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__BUILDER_HPP_
#define MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages_cpp/msg/detail/item_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages_cpp
{

namespace msg
{

namespace builder
{

class Init_ItemInfo_info
{
public:
  explicit Init_ItemInfo_info(::messages_cpp::msg::ItemInfo & msg)
  : msg_(msg)
  {}
  ::messages_cpp::msg::ItemInfo info(::messages_cpp::msg::ItemInfo::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages_cpp::msg::ItemInfo msg_;
};

class Init_ItemInfo_name
{
public:
  explicit Init_ItemInfo_name(::messages_cpp::msg::ItemInfo & msg)
  : msg_(msg)
  {}
  Init_ItemInfo_info name(::messages_cpp::msg::ItemInfo::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ItemInfo_info(msg_);
  }

private:
  ::messages_cpp::msg::ItemInfo msg_;
};

class Init_ItemInfo_id
{
public:
  Init_ItemInfo_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ItemInfo_name id(::messages_cpp::msg::ItemInfo::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ItemInfo_name(msg_);
  }

private:
  ::messages_cpp::msg::ItemInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages_cpp::msg::ItemInfo>()
{
  return messages_cpp::msg::builder::Init_ItemInfo_id();
}

}  // namespace messages_cpp

#endif  // MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__BUILDER_HPP_
