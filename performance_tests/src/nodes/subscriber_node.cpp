#include <performance_tests/subscriber.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "subscriber");
	ros::NodeHandle nh;

	performance_tests::SubscriberTest node(nh);

	ros::spin();

	return 0;
}  
