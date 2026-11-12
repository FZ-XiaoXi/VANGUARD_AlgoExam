// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages_cpp:msg/ItemInfo.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_HPP_
#define MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages_cpp__msg__ItemInfo __attribute__((deprecated))
#else
# define DEPRECATED__messages_cpp__msg__ItemInfo __declspec(deprecated)
#endif

namespace messages_cpp
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ItemInfo_
{
  using Type = ItemInfo_<ContainerAllocator>;

  explicit ItemInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->info = "";
    }
  }

  explicit ItemInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->info = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _info_type info;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__info(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages_cpp::msg::ItemInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages_cpp::msg::ItemInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages_cpp::msg::ItemInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages_cpp::msg::ItemInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages_cpp__msg__ItemInfo
    std::shared_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages_cpp__msg__ItemInfo
    std::shared_ptr<messages_cpp::msg::ItemInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ItemInfo_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const ItemInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ItemInfo_

// alias to use template instance with default allocator
using ItemInfo =
  messages_cpp::msg::ItemInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages_cpp

#endif  // MESSAGES_CPP__MSG__DETAIL__ITEM_INFO__STRUCT_HPP_
