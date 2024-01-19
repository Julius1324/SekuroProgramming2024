import rospy
from tp4_1_pkg.srv import Magnitude_m , Magnitude_mResponse
from math import sqrt

def callback(request):
    return Magnitude_mResponse(sqrt(request.x **2 + request.y **2 + request.z **2))

def get_mag():
    rospy.init_node('magnitude_service')
    service = rospy.Service("magnitude",Magnitude_m,callback)
    rospy.spin()
if __name__ == '__main__':
    get_mag()