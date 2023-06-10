#!/usr/bin/env python3
import rospy
from std_msgs.msg import Float64
import sys, select, termios, tty
vel1=0
vel2=0
vel3=0
vel4=0
v1=0
v2=0
v3=0
v4=0
def getKey(key_timeout):
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], key_timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key
rospy.init_node('task3')
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)
velf = 0.1
velb = -0.1
vel0 = 0.00
angular=0.1
angl = -0.1

settings = termios.tcgetattr(sys.stdin)
key_timeout = rospy.get_param("~key_timeout", 0.0)
while not rospy.is_shutdown():
       vel5=vel1+v1
       vel6=vel2+v2
       vel7=vel3+v3
       vel8=vel4+v4

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
           vel1=velf*1.1+vel1
           vel2=velb*1.1+vel2
           vel3=angular*1.1+vel3
           vel4=angl*1.1+vel4
           pub1.publish(vel1)
           pub2.publish(vel1)
           pub3.publish(vel1)
           pub4.publish(vel1)
           
    
          elif c == 's':
           vel1=velf*1.1+vel1
           vel2=velb*1.1+vel2
           vel3=angular*1.1+vel3
           vel4=angl*1.1+vel4
           pub1.publish(vel2)
           pub2.publish(vel2)
           pub3.publish(vel2)
           pub4.publish(vel2)
    
          elif c == 'a':
           vel1=velf*1.1+vel1
           vel2=velb*1.1+vel2
           vel3=angular*1.1+vel3
           vel4=angl*1.1+vel4
           pub1.publish(vel4)
           pub2.publish(vel4)
           pub3.publish(vel3)
           pub4.publish(vel3)
    
          elif c == 'd':
           vel1=velf*1.1+vel1
           vel2=velb*1.1+vel2
           vel3=angular*1.1+vel3
           vel4=angl*1.1+vel4
           pub1.publish(vel3)
           pub2.publish(vel3)
           pub3.publish(vel4)
           pub4.publish(vel4)
           
          elif c == 'y':
           pub1.publish(vel5)
           pub2.publish(vel5)
           pub3.publish(vel5)
           pub4.publish(vel5)
           
          elif c == 'h':
           pub1.publish(vel6)
           pub2.publish(vel6)
           pub3.publish(vel6)
           pub4.publish(vel6)
           
          elif c == 'g':
           pub1.publish(vel8)
           pub2.publish(vel8)
           pub3.publish(vel7)
           pub4.publish(vel7)
           
          elif c == 'j':
           pub1.publish(vel7)
           pub2.publish(vel7)
           pub3.publish(vel8)
           pub4.publish(vel8) 
          
          else:
           pub1.publish(vel0)
           pub2.publish(vel0)
           pub3.publish(vel0)
           pub4.publish(vel0)
          
       elif key == '':
         if(vel1==0):
                v1=vel1+v1
                v2=vel2+v2
                v3=vel3+v3
                v4=vel4+v4
         else:
             v1=vel1
             v2=vel2
             v3=vel3
             v4=vel4
         vel1=0
         vel2=0
         vel3=0
         vel4=0
         pub1.publish(vel0)
         pub2.publish(vel0)
         pub3.publish(vel0)
         pub4.publish(vel0)
       key_timeout = 0.09
