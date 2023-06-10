Ram Rajavadha
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
rospy.init_node('Harshil')
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command', Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)
f = 0.001
velf = round(f, 3)
b = -0.001
velb = round(b, 3)
stop = 0

settings = termios.tcgetattr(sys.stdin)
key_timeout = rospy.get_param("~key_timeout", 0.0)
while not rospy.is_shutdown():
       key = getKey(key_timeout)
       c = getKey(key_timeout)  
       if key == '\x03':
          key_timeout == 0.0
          key_timeout = None
          break
       if key != '':
          key_timeout == 0.0
          key_timeout = None
          if c == 'w':
            if velf != 0.05:
                velf = velf + 0.001
                velf = round(velf, 3)
                pub1.publish(velf)
                pub2.publish(velf)
                pub3.publish(velf)
                pub4.publish(velf)
            else:
                pub1.publish(0.05)
                pub2.publish(0.05)
                pub3.publish(0.05)
                pub4.publish(0.05)
    
          elif c == 's':
            if velb != -0.05:
                velb = velb - 0.001
                velb = round(velb, 3)
                pub1.publish(velb)
                pub2.publish(velb)
                pub3.publish(velb)
                pub4.publish(velb)
            else:
                pub1.publish(-0.05)
                pub2.publish(-0.05)
                pub3.publish(-0.05)
                pub4.publish(-0.05)
    
          elif c == 'a':
           velf = 0.05
           velb = -0.05
           pub1.publish(5*velb)
           pub2.publish(velf)
           pub3.publish(5*velf)
           pub4.publish(velf)
    
          elif c == 'd':
           velf = 0.05
           velb = -0.05
           pub1.publish(5*velf)
           pub2.publish(velf)
           pub3.publish(5*velb)
           pub4.publish(velf)
          
          elif c == 'e':
           velf += 0.01
           pub1.publish(velf)
           pub2.publish(velf)
           pub3.publish(velf)
           pub4.publish(velf)
        
          elif c == 'q':
           velf -= 0.01
           pub1.publish(velf)
           pub2.publish(velf)
           pub3.publish(velf)
           pub4.publish(velf)

          else:
            while(velf != 0):
                velf = velf - 0.0001
                velf = round(velf, 4)
                pub1.publish(velf)
                pub2.publish(velf)
                pub3.publish(velf)
                pub4.publish(velf)

       if key == '':
        pub1.publish(stop)
        pub2.publish(stop)
        pub3.publish(stop)
        pub4.publish(stop)
       key_timeout = 0.09
