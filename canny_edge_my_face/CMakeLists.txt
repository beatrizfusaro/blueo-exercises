cmake_minimum_required(VERSION 2.8.3)
project(canny_edge_my_face)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS image_transport cv_bridge sensor_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(cannyEdge src/nodes/cannyEdge_node.cpp src/cannyEdge.cpp)
target_link_libraries(cannyEdge ${catkin_LIBRARIES})
add_dependencies(cannyEdge image_transport)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

install(TARGETS cannyEdge
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
