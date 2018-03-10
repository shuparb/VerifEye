#ifndef LANDMARK_H
#define LANDMARK_H
#include <string>
#include <qobject.h>
#include <dlib/image_processing.h>

using namespace std;
using namespace dlib;

namespace verifEye {
	// landmarking
	static const string PRE_LANDMARK_PATH = "./models/PRE_LANDMARK.dat";
	static const string POST_LE_LANDMARK_PATH = "./models/POST_FACE_LEFT_EYEPATCH_LANDMARK.dat";
	static const string POST_RE_LANDMARK_PATH = "./models/POST_FACE_RIGHT_EYEPATCH_LANDMARK.dat";
	class Landmark{
	private:
		shape_predictor pre_face_landmark, post_face_left_eyepatch_landmark, post_face_right_eyepatch_landmark; // landmark detections
	public:
		Landmark();		// constructor
		void load();
		int detect_pre_face_landmark(array2d<unsigned char>&, std::vector<rectangle>, std::vector<full_object_detection>&);
		int detect_post_face_le_landmark(array2d<unsigned char>&, std::vector<rectangle>, std::vector<full_object_detection>&);
		int detect_post_face_re_landmark(array2d<unsigned char>&, std::vector<rectangle>, std::vector<full_object_detection>&);
	};
}
#endif LANDMARK_H
