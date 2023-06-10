<gazebo reference="base_link">        
   <sensor type="ray" name="F">
      <pose>0 0 -0.05 0 0 3.14</pose>
      <visualize>true</visualize>
      <update_rate>10</update_rate>
      <ray>
         <scan>
            <horizontal>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0.14</min_angle>
               <max_angle>-0.14</max_angle>
            </horizontal>
            <vertical>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0</min_angle>
               <max_angle>0.03</max_angle> 
            </vertical>
         </scan>
         <range>
            <min>0.01</min>
            <max>1.0</max>
            <resolution>1</resolution>
         </range>
      </ray>
      <plugin filename="libgazebo_ros_range.so" name="gazebo_ros_range">
         <gaussianNoise>0.005</gaussianNoise>
         <alwaysOn>true</alwaysOn>
         <updateRate>10</updateRate>
         <topicName>sensor/ir_front</topicName>
         <frameName>base_link</frameName>
         <radiation>INFRARED</radiation>
         <fov>0.5</fov>
      </plugin>
   </sensor>  
   </gazebo>
   
    <gazebo reference="base_link">        
   <sensor type="ray" name="L">
      <pose>0 0 -0.05 0 0 1.57</pose>
      <visualize>true</visualize>
      <update_rate>10</update_rate>
      <ray>
         <scan>
            <horizontal>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0.14</min_angle>
               <max_angle>-0.14</max_angle>
            </horizontal>
            <vertical>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0</min_angle>
               <max_angle>0.03</max_angle> 
            </vertical>
         </scan>
         <range>
            <min>0.01</min>
            <max>1.0</max>
            <resolution>1</resolution>
         </range>
      </ray>
      <plugin filename="libgazebo_ros_range.so" name="gazebo_ros_range">
         <gaussianNoise>0.005</gaussianNoise>
         <alwaysOn>true</alwaysOn>
         <updateRate>10</updateRate>
         <topicName>sensor/ir_left</topicName>
         <frameName>base_link</frameName>
         <radiation>INFRARED</radiation>
         <fov>0.5</fov>
      </plugin>
   </sensor>  
   </gazebo>
   
    <gazebo reference="base_link">        
   <sensor type="ray" name="R">
      <pose>0 0 -0.05 0 0 -1.57</pose>
      <visualize>true</visualize>
      <update_rate>10</update_rate>
      <ray>
         <scan>
            <horizontal>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0.14</min_angle>
               <max_angle>-0.14</max_angle>
            </horizontal>
            <vertical>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0</min_angle>
               <max_angle>0.03</max_angle> 
            </vertical>
         </scan>
         <range>
            <min>0.01</min>
            <max>1.0</max>
            <resolution>1</resolution>
         </range>
      </ray>
      <plugin filename="libgazebo_ros_range.so" name="gazebo_ros_range">
         <gaussianNoise>0.005</gaussianNoise>
         <alwaysOn>true</alwaysOn>
         <updateRate>10</updateRate>
         <topicName>sensor/ir_right</topicName>
         <frameName>base_link</frameName>
         <radiation>INFRARED</radiation>
         <fov>0.5</fov>
      </plugin>
   </sensor>  
   </gazebo>
   
    <gazebo reference="base_link">        
   <sensor type="ray" name="LS">
      <pose>0 0 -0.05 0 0 2.617</pose>
      <visualize>true</visualize>
      <update_rate>10</update_rate>
      <ray>
         <scan>
            <horizontal>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0.14</min_angle>
               <max_angle>-0.14</max_angle>
            </horizontal>
            <vertical>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0</min_angle>
               <max_angle>0.03</max_angle> 
            </vertical>
         </scan>
         <range>
            <min>0.01</min>
            <max>0.75</max>
            <resolution>1</resolution>
         </range>
      </ray>
      <plugin filename="libgazebo_ros_range.so" name="gazebo_ros_range">
         <gaussianNoise>0.005</gaussianNoise>
         <alwaysOn>true</alwaysOn>
         <updateRate>10</updateRate>
         <topicName>sensor/ir_leftslant</topicName>
         <frameName>base_link</frameName>
         <radiation>INFRARED</radiation>
         <fov>0.5</fov>
      </plugin>
   </sensor>  
   </gazebo>
   
    <gazebo reference="base_link">        
   <sensor type="ray" name="RS">
      <pose>0 0 -0.05 0 0 -2.617</pose>
      <visualize>true</visualize>
      <update_rate>10</update_rate>
      <ray>
         <scan>
            <horizontal>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0.14</min_angle>
               <max_angle>-0.14</max_angle>
            </horizontal>
            <vertical>
               <samples>10</samples>
               <resolution>1</resolution> 
               <min_angle>0</min_angle>
               <max_angle>0.03</max_angle> 
            </vertical>
         </scan>
         <range>
            <min>0.01</min>
            <max>0.75</max>
            <resolution>1</resolution>
         </range>
      </ray>
      <plugin filename="libgazebo_ros_range.so" name="gazebo_ros_range">
         <gaussianNoise>0.005</gaussianNoise>
         <alwaysOn>true</alwaysOn>
         <updateRate>10</updateRate>
         <topicName>sensor/ir_rightslant</topicName>
         <frameName>base_link</frameName>
         <radiation>INFRARED</radiation>
         <fov>0.5</fov>
      </plugin>
   </sensor>  
   </gazebo>
