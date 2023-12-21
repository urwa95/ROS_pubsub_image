cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub_image)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)  # Add sensor_msgs package
#find_package(auto_interfaces REQUIRED)

add_executable(talker src/publisher_member_function.cpp)  # Rename publisher file
ament_target_dependencies(talker rclcpp sensor_msgs)  # Add sensor_msgs dependency

add_executable(listener src/subscriber_member_function.cpp)  # Rename subscriber file
ament_target_dependencies(listener rclcpp sensor_msgs)  # Add sensor_msgs dependency

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
