# !/usr/bin/env python3
import rospy
import tkinter
from std_msgs.msg import Float64

window=tkinter.Tk()
window.title("TELEOPERATION")

rospy.init_node('gui')
vel1=0.05
vel2=-0.05
vel3=0
pub1 = rospy.Publisher('/farm_bot/leftWheelfront_effort_controller/command', Float64, queue_size = 10)
pub2 = rospy.Publisher('/farm_bot/leftWheelrear_effort_controller/command', Float64, queue_size = 10)
pub3 = rospy.Publisher('/farm_bot/rightWheelfront_effort_controller/command',Float64, queue_size = 10)
pub4 = rospy.Publisher('/farm_bot/rightWheelrear_effort_controller/command', Float64, queue_size = 10)


def left_clicked():
    print("left")
    pub1.publish(vel1) 
    pub2.publish(vel1)
    pub3.publish(vel2)
    pub4.publish(vel2)

def right_clicked():
    print("right")
    pub1.publish(vel2) 
    pub2.publish(vel2)
    pub3.publish(vel1)
    pub4.publish(vel1)

def front_clicked():
    print("front")
    pub1.publish(vel1) 
    pub2.publish(vel1)
    pub3.publish(vel1)
    pub4.publish(vel1)

def back_clicked():
    print("back")
    pub1.publish(vel2) 
    pub2.publish(vel2)
    pub3.publish(vel2)
    pub4.publish(vel2)

def stop():
    print("stop")
    pub1.publish(vel3) 
    pub2.publish(vel3)
    pub3.publish(vel3)
    pub4.publish(vel3)


bt1=tkinter.Button(window,text="LEFT",bg="orange",fg="red",command=lambda:left_clicked())
bt1.grid(column=0,row=1)

bt2=tkinter.Button(window,text="RIGHT",bg="orange",fg="red",command=lambda:right_clicked())
bt2.grid(column=2,row=1)

bt3=tkinter.Button(window,text="FRONT",bg="orange",fg="red",command=lambda:front_clicked())
bt3.grid(column=1,row=0)

bt4=tkinter.Button(window,text="BACK",bg="orange",fg="red",command=lambda:back_clicked())
bt4.grid(column=1,row=2)

bt5=tkinter.Button(window,text="STOP",bg="orange",fg="red",command=lambda:stop())
bt5.grid(column=1,row=1)

window.mainloop()


