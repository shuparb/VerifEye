#ifndef DETECTOR_H
#define DETECTOR_H
#include <string>
#include <dlib/image_processing.h>

using namespace std;
using namespace dlib;

namespace verifEye {
	// detectors
	static const string EYEPATCH_DETECTOR_PATH = "./models/EYEPATCH_DETECTION.svm";
	static const string PRE_DETECTOR_PATH = "./models/PRE_DETECTION.svm";
	static const string POST_DETECTOR_PATH = "./models/POST_DETECTION.svm";

	class Detector {
	private:
		object_detector < scan_fhog_pyramid<pyramid_down<14>>> post_face_detector, pre_face_detector;        // pre, post face detectors
		object_detector<scan_fhog_pyramid<pyramid_down<14>>> eyepatch_detector;		// eyepatch detector
	public:
		Detector();		// constructor
		int detect_pre_face(array2d<unsigned char>&, std::vector<rectangle>&);
		int detect_post_face(array2d<unsigned char>&, std::vector<rectangle>&);
		int detect_eyepatch(array2d<unsigned char>&, std::vector<rectangle>&);
	};
}

#endif DETECTOR_H
