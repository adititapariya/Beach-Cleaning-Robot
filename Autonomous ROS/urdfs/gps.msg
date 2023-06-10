<gazebo>
    <plugin name="novatel_gps_sim" filename="libhector_gazebo_ros_gps.so">
      <alwaysOn>1</alwaysOn>
      <updateRate>10.0</updateRate>
      <bodyName>base_link</bodyName>
      <topicName>fix</topicName>
      <velocityTopicName>fix_velocity</velocityTopicName>
      <drift>5.0 5.0 5.0</drift>
      <gaussianNoise>0.1 0.1 0.1</gaussianNoise>
      <velocityDrift>0 0 0</velocityDrift>
      <velocityGaussianNoise>0.1 0.1 0.1</velocityGaussianNoise>
    </plugin>
   </gazebo>
   
   
   <!-- sudo apt-get install ros-noetic-hector-gazebo-plugins-->
