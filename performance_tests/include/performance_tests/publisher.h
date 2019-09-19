#ifndef PERFORMANCE_TESTS_PUBLISHER_H
#define PERFORMANCE_TESTS_PUBLISHER_H


#include <ros/ros.h>
#include <ros/time.h>

#include <performance_tests/SuperAwesome.h>

#include <dynamic_reconfigure/server.h>

#include <performance_tests/perfTestsConfig.h>

namespace performance_tests {
	
	class PublisherTest {
		public:
			explicit PublisherTest(ros::NodeHandle nh);

		private:
			void configCallback(performance_tests::perfTestsConfig &config, uint32_t level);

			void timerCallback(const ros::TimerEvent &event);

			void start();

			void stop();

			ros::NodeHandle nh_;

			ros::Timer timer_;

			ros::Publisher pub_;

			dynamic_reconfigure::Server<performance_tests::perfTestsConfig> dr_srv_;

			std::string message_;

			double rate_;

			bool enable_;
	};
}

#endif
