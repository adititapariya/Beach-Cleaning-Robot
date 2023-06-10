<gazebo reference="base_link">
    <gravity>true</gravity>
    <sensor name="imu_sensor" type="imu">
     <always_on>true</always_on>
     <update_rate>10</update_rate>
     <visualize>true</visualize>
     <topic>__default_topic__</topic>
     <plugin filename="libgazebo_ros_imu_sensor.so" name="imu_plugin">
      <topicName>imu</topicName>
      <bodyName>imu_link</bodyName>
      <updateRateHZ>10.0</updateRateHZ>
      <gaussianNoise>0.0</gaussianNoise>
      <xyzOffset>0 0 0</xyzOffset>
      <rpyOffset>0 0 -1.57</rpyOffset>
      <frameName>base_link</frameName>
      <initialOrientationAsReference>false</initialOrientationAsReference>
     </plugin>
     <pose>0 0 0 0 0 0</pose>
    </sensor>
   </gazebo>
   <gazebo>
    <plugin name="novatel_gps_sim" filename="libhector_gazebo_ros_gps.so">
      <alwaysOn>1</alwaysOn>
      <updateRate>10</updateRate>
      <bodyName>base_link</bodyName>
      <topicName>fix</topicName>
      <velocityTopicName>fix_velocity</velocityTopicName>
      <gaussianNoise>0.0 0.0 0.0</gaussianNoise>
      <velocityGaussianNoise>0.0 0.0 0.0</velocityGaussianNoise>
    </plugin>
   </gazebo>
