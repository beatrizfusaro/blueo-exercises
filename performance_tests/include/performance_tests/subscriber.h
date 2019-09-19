#ifndef PERFORMANCE_TESTS_SUBSCRIBER_H
#define PERFORMANCE_TESTS_SUBSCRIBER_H


#include <ros/ros.h>
#include <ros/time.h>

#include <performance_tests/SuperAwesome.h>

namespace performance_tests {

	class SubscriberTest {
		public:
			explicit SubscriberTest(ros::NodeHandle nh);

			void messageCallback(const performance_tests::SuperAwesome::ConstPtr &msg);

		private:
			ros::Subscriber sub_;
	};
}

#endif  
