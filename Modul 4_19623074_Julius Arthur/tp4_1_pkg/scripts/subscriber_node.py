#!/usr/bin/env python3

import rospy
from tp4_1_pkg.msg import Pesan
def callback(data):
    rospy.loginfo("Nama: %s" % data.nama)
    rospy.loginfo("Usia: %ld" % data.usia)
    rospy.loginfo("Tinggi: %lf" % data.tinggi)
    rospy.loginfo("Kehadiran: %s\n" % data.kehadiran)

def talker():
    rospy.init_node("subscriber_node",anonymous = True)
    rospy.Subscriber("topik_py",Pesan,callback)
    rospy.spin()
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass