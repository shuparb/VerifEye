#include "detector.h"
namespace verifEye {
	Detector::Detector() {
		try {
			deserialize(PRE_DETECTOR_PATH) >> pre_face_detector;
			deserialize(POST_DETECTOR_PATH) >> post_face_detector;
			deserialize(EYEPATCH_DETECTOR_PATH) >> eyepatch_detector;
		}
		catch (exception e) {
			cout << "DETECTOR LOADING FAILED: " << e.what() << endl;
		}
	}
	int Detector::detect_pre_face(array2d<unsigned char>& image, std::vector<rectangle>& box)
	{
		box = pre_face_detector(image);
		return box.size();
	}
	int Detector::detect_post_face(array2d<unsigned char>& image, std::vector<rectangle>& box)
	{
		box = post_face_detector(image);
		return box.size();
	}
	int Detector::detect_eyepatch(array2d<unsigned char>& image, std::vector<rectangle>& box)
	{
		box = eyepatch_detector(image);
		return box.size();		
	}
}