#include <OpenNI.h>
#include <NiTE.h>
#include <opencv2/opencv.hpp>

int main()
{
    // Initialize OpenNI2 and NiTE2
    openni::OpenNI::initialize();
    nite::NiTE::initialize();

    // Create a device object to interact with the Kinect sensor
    openni::Device device;
    device.open(openni::ANY_DEVICE);

    // Create a color stream to capture color data from the sensor
    openni::VideoStream colorStream;
    colorStream.create(device, openni::SENSOR_COLOR);

    // Create a user tracker to detect and track users in the color stream
    nite::UserTracker userTracker;
    userTracker.create();

    // Start the color stream and user tracker
    colorStream.start();
    userTracker.start(colorStream);

    // Wait for a new color frame to become available
    openni::VideoFrameRef colorFrame;
    colorStream.readFrame(&colorFrame);

    // Convert the color frame to an OpenCV image
    cv::Mat colorImage(colorFrame.getHeight(), colorFrame.getWidth(), CV_8UC3, (void*)colorFrame.getData());

    // Perform image processing on the color image using OpenCV
    // ...

    // Stop the color stream and user tracker
    userTracker.stop();
    colorStream.stop();

    // Destroy the user tracker and color stream
    userTracker.destroy();
    colorStream.destroy();

    // Shutdown OpenNI2 and NiTE2
    nite::NiTE::shutdown();
    openni::OpenNI::shutdown();

    return 0;
}

// compile using --> g++ -o kinect_capture kinect_capture.cpp -lOpenNI2 -lNiTE2 `pkg-config --cflags --libs opencv`
// This command compiles the file and links it against the OpenNI2, NiTE2, and OpenCV libraries.
// Run using --> ./kinect_capture
// This command runs the program and captures a color image from the Kinect sensor, which is displayed on the screen.
