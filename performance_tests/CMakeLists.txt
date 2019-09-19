cmake_minimum_required(VERSION 2.8.3)
project(performance_tests)

find_package(catkin REQUIRED COMPONENTS dynamic_reconfigure message_generation roscpp rosgraph_msgs rospy std_msgs)

add_message_files(
  FILES
  SuperAwesome.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/perfTests.cfg
)

catkin_package(
  CATKIN_DEPENDS dynamic_reconfigure message_runtime roscpp rosgraph_msgs rospy std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(publisher src/nodes/publisher_node.cpp src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})
add_dependencies(publisher performance_tests_gencfg performance_tests_generate_messages_cpp)

add_executable(subscriber src/subscriber.cpp src/nodes/subscriber_node.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})
add_dependencies(subscriber performance_tests_gencfg performance_tests_generate_messages_cpp)


install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

install(PROGRAMS src/subpython.py src/pubpython.py DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS subscriber publisher
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
