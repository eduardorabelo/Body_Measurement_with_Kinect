/****************************************************************************
* 
*  Computer Vision, Fall 2011
*  New York University
*
*  Created by Otavio Braga (obraga@cs.nyu.edu)
*
****************************************************************************/

#ifndef ANGULAR_SKELETON_H
#define ANGULAR_SKELETON_H

#include <opencv2/core/core.hpp>

// The angular representation is indexed by JointID
enum JointID
{
    SAR_TORSO_YAW,		// Euler angles
    SAR_TORSO_PITCH,
    SAR_TORSO_ROLL,

    // left shoulder
    SAR_LS_INC,
    SAR_LS_AZIMUTH,

    // right shoulder
    SAR_RS_INC,
    SAR_RS_AZIMUTH,

    // left hip
    SAR_LH_INC,
    SAR_LH_AZIMUTH,

    // right hip
    SAR_RH_INC,
    SAR_RH_AZIMUTH,
    
    // left elbow
    SAR_LE_INC,
    SAR_LE_AZIMUTH,
    
    // right elbow
    SAR_RE_INC,
    SAR_RE_AZIMUTH,
    
    // left knee
    SAR_LK_INC,
    SAR_LK_AZIMUTH,
    
    // left knee
    SAR_RK_INC,
    SAR_RK_AZIMUTH,

    SAR_NANGLES
};

enum JointID2
{
    SKEL_HEAD,              
    SKEL_NECK,              
    SKEL_TORSO,             
    SKEL_LEFT_SHOULDER,     
    SKEL_LEFT_ELBOW,        
    SKEL_LEFT_HAND,         
    SKEL_RIGHT_SHOULDER,    
    SKEL_RIGHT_ELBOW,       
    SKEL_RIGHT_HAND,        
    SKEL_LEFT_HIP,          
    SKEL_LEFT_KNEE,         
    SKEL_LEFT_FOOT,         
    SKEL_RIGHT_HIP,         
    SKEL_RIGHT_KNEE,        
    SKEL_RIGHT_FOOT,        
    SKEL_NJOINTS
};

// Compute the skeleton angular representation of the 19 3D joint positions
// stored in 'joints'. The 16 angles are indexed by JointID.
//
// axis: Should hold the principal components of the neck, shoulders (2),
//       torso, and hip (2) joints.
//
//       - axis[0] should be the first principal component, aligned with the
//       longer dimension of the torso, and should be pointing down.
//       - axis[1] is the second principal component, aligned with the line
//       that connectes the shoulders, and pointing in the left-right
//       shoulder direction.
//       - axis[2] should be the cross product of the first two principal
//       components.
//
// !!!!!!!!!!!!!!!!!!!! Implement this !!!!!!!!!!!!!!!!!!!!
void computeSkeletonAngularRepresentation(std::vector<cv::Vec3d> &joints,
                                          cv::vector<double> &angles,
                                          cv::Vec3d axis[3]);

enum PoseID
{
    POSE_HOSTAGE_FORWARD,
    POSE_HOSTAGE_BACKWARDS,
};

// Checks if a pose matches a reference pose
// !!!!!!!!!!!!!!!!!!!! Implement this !!!!!!!!!!!!!!!!!!!!
bool matchAngularPose(cv::vector<double> &pose, PoseID poseid);

#endif // ANGULAR_SKELETON_H
