#include <performance_tests/subscriber.h>

namespace performance_tests {

	SubscriberTest::SubscriberTest(ros::NodeHandle nh) {
  		sub_ = nh.subscribe("chatter", 10, &SubscriberTest::messageCallback, this);
	}

	void SubscriberTest::messageCallback(const performance_tests::SuperAwesome::ConstPtr &msg) {

		ROS_INFO("%s", msg->message.c_str());
	}
}
