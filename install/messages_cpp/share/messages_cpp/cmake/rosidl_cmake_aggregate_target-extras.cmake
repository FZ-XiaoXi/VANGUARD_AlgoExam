# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target messages_cpp::messages_cpp
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${messages_cpp_TARGETS}.
if(messages_cpp_TARGETS AND NOT TARGET messages_cpp::messages_cpp)
  add_library(messages_cpp::messages_cpp INTERFACE IMPORTED)
  set_target_properties(messages_cpp::messages_cpp PROPERTIES
    INTERFACE_LINK_LIBRARIES "${messages_cpp_TARGETS}")
endif()
