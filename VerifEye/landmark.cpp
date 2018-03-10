#include "landmark.h"
namespace verifEye {
	Landmark::Landmark() {
		load();
	}
	void Landmark::load()
	{
		try {
			deserialize(PRE_LANDMARK_PATH) >> pre_face_landmark;
			deserialize(POST_LE_LANDMARK_PATH) >> post_face_left_eyepatch_landmark;
			deserialize(POST_RE_LANDMARK_PATH) >> post_face_right_eyepatch_landmark;
		}
		catch (exception e) {
			cout << "LANDMARK LOADING FAILED: " << e.what() << endl;
		}
	}
	int Landmark::detect_pre_face_landmark(array2d<unsigned char>& image, std::vector<rectangle> box, std::vector<full_object_detection>& landmark)
	{
		if (box.size() > 0) {
			full_object_detection l;
			for (auto b : box) {
				l = pre_face_landmark(image, b);
				landmark.push_back(l);
			}
			return 0;
		}
		else {
			return 1;
		}
	}
	int Landmark::detect_post_face_le_landmark(array2d<unsigned char>& image, std::vector<rectangle> box, std::vector<full_object_detection>& landmark)
	{
		if (box.size() > 0) {
			full_object_detection l;
			for (auto b : box) {
				l = post_face_left_eyepatch_landmark(image, b);
				landmark.push_back(l);
			}
			return 0;
		}
		else {
			return 1;
		}
	}
	int Landmark::detect_post_face_re_landmark(array2d<unsigned char>& image, std::vector<rectangle> box, std::vector<full_object_detection>& landmark)
	{
		if (box.size() > 0) {
			full_object_detection l;
			for (auto b : box) {
				l = post_face_right_eyepatch_landmark(image, b);
				landmark.push_back(l);
			}
			return 0;
		}
		else {
			return 1;
		}
	}
}