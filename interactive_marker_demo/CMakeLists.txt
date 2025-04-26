cmake_minimum_required(VERSION 3.8)
project(interactive_marker_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(interactive_markers REQUIRED)

add_executable(interactive_marker_server src/interactive_marker_server.cpp)
ament_target_dependencies(interactive_marker_server
  rclcpp
  visualization_msgs
  interactive_markers
)

install(TARGETS
  interactive_marker_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
