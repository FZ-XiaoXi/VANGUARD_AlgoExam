#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "messages_cpp__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages_cpp__msg__ItemInfo() -> *const std::ffi::c_void;
}

#[link(name = "messages_cpp__rosidl_generator_c")]
extern "C" {
    fn messages_cpp__msg__ItemInfo__init(msg: *mut ItemInfo) -> bool;
    fn messages_cpp__msg__ItemInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ItemInfo>, size: usize) -> bool;
    fn messages_cpp__msg__ItemInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ItemInfo>);
    fn messages_cpp__msg__ItemInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ItemInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<ItemInfo>) -> bool;
}

// Corresponds to messages_cpp__msg__ItemInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ItemInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub info: rosidl_runtime_rs::String,

}



impl Default for ItemInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages_cpp__msg__ItemInfo__init(&mut msg as *mut _) {
        panic!("Call to messages_cpp__msg__ItemInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ItemInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages_cpp__msg__ItemInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages_cpp__msg__ItemInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages_cpp__msg__ItemInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ItemInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ItemInfo where Self: Sized {
  const TYPE_NAME: &'static str = "messages_cpp/msg/ItemInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages_cpp__msg__ItemInfo() }
  }
}


