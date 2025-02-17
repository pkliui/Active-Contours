#ifndef SOURCEMANAGER_H
#define SOURCEMANAGER_H

#include <string>

#ifdef __linux__
    #include <opencv2/video/video.hpp>
    #include <opencv2/highgui/highgui.hpp>
#else
    #include <opencv2/videoio/videoio.hpp>
#endif


class SourceManager
{
public:
    SourceManager();

    // Check if the source manager is ready
    bool isVideoReady();
    bool isCameraReady();
    bool isImageReady();

    // Return the selected media
    int getSelectedCamera();
    std::string getSelectedVideo();
    std::string getSelectedImage();

    void setSelectedVideo(std::string selection);
    void setSelectedCamera(int selection);
    void setSelectedImage(std::string selection);

    // Check the system for cameras
    void reloadCameras();

    // Return highest number of available cameras
    int getAvailableCameras();

private:
    bool videoReady;
    bool camerasReady;
    bool imageReady;

    std::string videoFile;
    std::string imageFile;

    int cameraCount;
    int cameraSelection;
};

#endif // SOURCEMANAGER_H
