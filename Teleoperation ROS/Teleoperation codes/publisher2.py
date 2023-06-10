#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64
import sys, select, termios, tty
def getKey(key_timeout):
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], key_timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key
rospy.init_node('task2')
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)
velf = 0.05
velb = -0.07
vel0 = 0.0
angul=0.15
angular=0.17
vel = 0.03

settings = termios.tcgetattr(sys.stdin)
key_timeout = rospy.get_param("~key_timeout", 0.0)
while not rospy.is_shutdown():
       key = getKey(key_timeout)
       c = getKey(key_timeout)  
       if (key == '\x03'):
          key_timeout == 0.0
          key_timeout = None
          break
       if key != '':
          key_timeout == 0.0
          key_timeout = None
          if c == 'w':
           pub1.publish(velf)
           pub2.publish(velf)
           pub3.publish(velf)
           pub4.publish(velf)
    
          elif c == 's':
           pub1.publish(velb)
           pub2.publish(velb)
           pub3.publish(velb)
           pub4.publish(velb)
    
          elif c == 'a':
           pub1.publish(vel)
           pub2.publish(vel)
           pub3.publish(angular)
           pub4.publish(angular)
    
          elif c == 'd':
           pub1.publish(angul)
           pub2.publish(angul)
           pub3.publish(vel)
           pub4.publish(vel)
          
          else:
           pub1.publish(vel0)
           pub2.publish(vel0)
           pub3.publish(vel0)
           pub4.publish(vel0)

       elif key == '':
        pub1.publish(vel0)
        pub2.publish(vel0)
        pub3.publish(vel0)
        pub4.publish(vel0)
       key_timeout = 0.09
