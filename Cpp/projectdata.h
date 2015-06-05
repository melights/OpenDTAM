/*
    Boost Software License - Version 1.0 - August 17th, 2003

    Permission is hereby granted, free of charge, to any person or organization
    obtaining a copy of the software and accompanying documentation covered by
    this license (the "Software") to use, reproduce, display, distribute,
    execute, and transmit the Software, and to prepare derivative works of the
    Software, and to permit third-parties to whom the Software is furnished to
    do so, all subject to the following:

    The copyright notices in the Software and this entire statement, including
    the above license grant, this restriction and the following disclaimer,
    must be included in all copies of the Software, in whole or in part, and
    all derivative works of the Software, unless such copies or derivative
    works are solely in the form of machine-executable object code generated by
    a source language processor.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
    SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
    FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/


#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include "QString"
#include "vector"
#include "QMutex"
#include "QMatrix4x4"

// #ifndef VC_APPLE
#include "ptam/CalibImage.h"

//#ifdef VE_UNIX

class ATANCamera;
class Map;
class MapMaker;
class Tracker;
class ARDriver;
class MapViewer;

// #endif

// #ifndef VC_APPLE
#include <cvd/image.h>
#include <cvd/rgb.h>
#include <cvd/byte.h>
// #endif

// #include "external_includes/vtkincludes.h"
#include "external_includes/opencvincludes.h"

//#endif

class ProjectData
{
  public:

  float mBarrelDistortion;

  bool mComputeOpticalFlow , mfeatureInitialized , mIsReadyForDetection , mIsPoseInitialized ;
  bool mNewFeatureDetectionMode , mIsPoseEstimated , mIsReadyForNextPose;

  bool mRunPTAM;
  
//ptam dataset
//#ifdef VE_UNIX
  
  struct PtamData
  {    
    bool mSpaceBarPressed , mResetPressed;
    bool mRender3Dpoints;
    bool mDrawImageData;

    int mPrevNumCams;

    int mCurrMessageId , mPrevMessageId;
    
    unsigned int mNumFrames;
    
    bool mPtamInitialized , mSkipFrame;
    
    int mSaveFrameIndex, mFrameLatency , mNumFrameToSkip;
    
    QString mBasePath;
    
    QString mMessage;
    
  } mPtamData;
  
  
//   vtkSmartPointer< vtkPolyData > mSparsePoints , mSparsePointsNormals;
  
  bool mIsFirstFrame , mSpaceBarPressed , mResetPressed , mRenderMessage , mbGrabNextFrame;

  std::vector< QString > mFramePaths;
  std::vector< QMatrix4x4 > mPoses;
  std::vector< QVector3D > mSparseObjectPoints , mSparsePointNormals;
  QString mPoseDataSetPath;
  QString mKeyFrameDataSetPath;
  
// #ifndef VC_APPLE
  
  std::vector< CalibImage > mvCalibImgs;
  
  CVD::Image< CVD::Rgb< CVD::byte > > mimFrameRGB;
  CVD::Image< CVD::byte > mimFrameBW;
  
  cv::Mat mPrevKeyImage , mCurrentKeyImage;
  
  Map *mpMap; 
  MapMaker *mpMapMaker; 
  Tracker *mpTracker; 
  ATANCamera *mpCamera;
  ARDriver *mpARDriver;
  MapViewer *mpMapViewer;

  void renderPTAMMessage();

  ProjectData();
  
  virtual ~ProjectData();

};

#endif // PROJECTDATA_H
