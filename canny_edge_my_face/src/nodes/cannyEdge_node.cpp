#include <canny_edge_my_face/cannyEdge.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "cannyEdge");
  ros::NodeHandle nh;

  canny_edge_my_face::CannyEdge node(nh);
  ros::spin();

  return 0;
}  
