#!/usr/bin/env python

import rospy

from performance_tests.msg import SuperAwesome


def callback(data):
    rospy.loginfo("%s", data.message)


def subscriberTest():
    rospy.Subscriber('chatter', SuperAwesome, callback)


if __name__ == '__main__':
    rospy.init_node('subpython')
    subscriberTest()
    rospy.spin()
