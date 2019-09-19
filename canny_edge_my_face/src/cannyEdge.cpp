#include <canny_edge_my_face/cannyEdge.h>


using namespace cv;
using namespace std;
namespace canny_edge_my_face
{
	CannyEdge::CannyEdge(ros::NodeHandle nh) : it(nh) {
		imgSub_ = it.subscribe("/cv_camera/image_raw", 1, &CannyEdge::process, this);
		imgPub_ = it.advertise("/camera/canny_edge",1);
		imgPubRaw_ = it.advertise("/camera/image_raw", 1);
	}
  
	void CannyEdge::process(const sensor_msgs::ImageConstPtr& srcImg) {
		imgPubRaw_.publish(srcImg);
		cv_bridge::CvImagePtr cv_ptr;
    		try {
			cv_ptr = cv_bridge::toCvCopy(srcImg, sensor_msgs::image_encodings::BGR8);
		}
		catch (cv_bridge::Exception& e) {
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}

		int theshold1 = 50;
		int theshold2 = 100; 
		int kernelSize = 3;

		Mat img;
		cvtColor(cv_ptr->image, img, CV_BGR2GRAY);
		GaussianBlur(img, img, Size(3, 3), 0, 0);
      		Canny(img, img, theshold1, theshold2, kernelSize);
		cvtColor(img, img, CV_GRAY2BGR);
		img = img+cv_ptr->image;

		cv_bridge::CvImage imgBridge = cv_bridge::CvImage(std_msgs::Header(), sensor_msgs::image_encodings::RGB8, img);
		sensor_msgs::Image msg;
		imgBridge.toImageMsg(msg);
		imgPub_.publish(msg);
		
	}
}
