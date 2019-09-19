#!/usr/bin/env python

import rospy

from dynamic_reconfigure.server import Server as DynamicReconfigureServer

from performance_tests.msg import SuperAwesome
from performance_tests.cfg import perfTestsConfig as ConfigType


class PerfTests(object):

    def __init__(self):
        
	self.rate = 10.0
        self.enable = True
        self.server = DynamicReconfigureServer(ConfigType, self.reconfigure_cb)
        self.pub = rospy.Publisher('chatter', SuperAwesome, queue_size=10)
        
	self.rate = rospy.get_param('~rate', 10.0)
        self.enable = rospy.get_param('~enable', True)
        self.message = rospy.get_param('~message', 'hello world')

        if self.enable:
            self.start()
        else:
            self.stop()

        rospy.Timer(rospy.Duration(1.0 / self.rate), self.timer_cb)

    def start(self):
        self.pub = rospy.Publisher('chatter', SuperAwesome, queue_size=10)

    def stop(self):
        self.pub.unregister()

    def timer_cb(self, _event):
        if not self.enable:
            return

        msg = SuperAwesome()
        msg.message = rospy.get_param('~message', self.message)

        self.message = msg.message

        self.pub.publish(msg)

    def reconfigure_cb(self, config, dummy):
        self.message = config["message"]
	
	if self.rate != config["rate"]:
            self.rate = config["rate"]
	    rospy.Timer(rospy.Duration(1.0 / self.rate), self.timer_cb)

        if self.enable != config["enable"]:
            if config["enable"]:
                self.start()
            else:
                self.stop()
        self.enable = config["enable"]

        return config


if __name__ == '__main__':
    rospy.init_node('pubpython')
    try:
        PerfTests()
    except rospy.ROSInterruptException:
        pass
    rospy.spin()
