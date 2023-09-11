####################################################
# Copyright (c) 2023 M. Kajdak. All rights reserved.
####################################################
cmake_minimum_required(VERSION 3.8)

project(motoros_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(MSG_FILES
    "msg/SetPlatformSpeed.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
    ${MSG_FILES}
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
