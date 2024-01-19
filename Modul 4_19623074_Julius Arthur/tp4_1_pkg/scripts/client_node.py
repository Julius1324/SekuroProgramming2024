import rospy
from tp4_1_pkg.srv import Magnitude_m , Magnitude_mResponse

def get_mag(x,y,z):
    rospy.init_node("client_node")
    rospy.wait_for_service("magnitude")
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try :
            my_mag = rospy.ServiceProxy("magnitude",Magnitude_m)
            response = my_mag(x,y,z)
            rospy.loginfo(response.magnitude)
            rate.sleep()
        except rospy.ServeException as e:
            print("Service Failed %s", e)

if __name__ == '__main__':
    get_mag(3,4,5)