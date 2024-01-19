#!/usr/bin/env python3

import rospy
from tp4_1_pkg.msg import Pesan

def talker():
    message_pub = rospy.Publisher("topik_py",Pesan,queue_size=10)

    rospy.init_node("publisher_node", anonymous=True)

    rate = rospy.Rate(1)

    rospy.loginfo("Publisher Node Started")
    while not rospy.is_shutdown():
        dataVariabel = Pesan()

        dataVariabel.usia = 17
        dataVariabel.tinggi = 170.5
        dataVariabel.nama = "James"
        dataVariabel.kehadiran = True

        message_pub.publish(dataVariabel)

        rate.sleep()
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass