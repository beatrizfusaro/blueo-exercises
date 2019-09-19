#include <performance_tests/publisher.h>

namespace performance_tests
{
PublisherTest::PublisherTest(ros::NodeHandle nh) : nh_(nh), message_("hello world"), enable_(true)
{
  dynamic_reconfigure::Server<performance_tests::perfTestsConfig>::CallbackType cb;
  cb = boost::bind(&PublisherTest::configCallback, this, _1, _2);
  dr_srv_.setCallback(cb);

  ros::NodeHandle pnh("~");
  pnh.param("message", message_, message_);
  pnh.param("rate", rate_, rate_);
  pnh.param("enable", enable_, enable_);

  if (enable_)
  {
    start();
  }

  timer_ = nh_.createTimer(ros::Duration(1.0 / rate_), &PublisherTest::timerCallback, this); // Timer based on dynamically input rate
}

void PublisherTest::start()
{
  pub_ = nh_.advertise<performance_tests::SuperAwesome>("chatter", 10);
}

void PublisherTest::stop()
{
  pub_.shutdown();
}

void PublisherTest::timerCallback(const ros::TimerEvent &event __attribute__((unused)))
{
  if (!enable_)
  {
    return;
  }

  performance_tests::SuperAwesome msg;
  msg.message = message_;

  pub_.publish(msg); // Publishes message whenever the timer pings
}

void PublisherTest::configCallback(performance_tests::perfTestsConfig &config, uint32_t level __attribute__((unused)))
{
  message_ = config.message;
  if (rate_ != config.rate)
  {
    rate_ = config.rate;
    timer_ = nh_.createTimer(ros::Duration(1.0 / rate_), &PublisherTest::timerCallback, this); // Updates timer if rate has changed
  }

  if (enable_ != config.enable)
  {
    if (config.enable)
    {
      start();
    }
    else
    {
      stop();
    }
  }
  enable_ = config.enable;
}
}
