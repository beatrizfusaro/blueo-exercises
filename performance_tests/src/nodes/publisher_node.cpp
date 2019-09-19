#include <performance_tests/publisher.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  performance_tests::PublisherTest node(nh);
  ros::spin();

  return 0;
}  
