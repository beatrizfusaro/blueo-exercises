#ifndef CANNY_EDGE_MY_FACE_CANNYEDGE_H
#define CANNY_EDGE_MY_FACE_CANNYEDGE_H

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>

namespace canny_edge_my_face {
	class CannyEdge {
		public:
			explicit CannyEdge(ros::NodeHandle nh);

			void process(const sensor_msgs::ImageConstPtr& srcImg);

		private:			

			ros::NodeHandle nh_;

			image_transport::ImageTransport it;
    
			image_transport::Subscriber imgSub_; 

			image_transport::Publisher imgPub_;

			image_transport::Publisher imgPubRaw_;
			
	};

}

#endif
