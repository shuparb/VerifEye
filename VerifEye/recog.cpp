#include "recog.h"
namespace verifEye {
	Recognizer::Recognizer()
	{
		try {
			deserialize(NET_PATH) >> net;
		}
		catch (exception e) {
			cout << "RECOGNIZER LOADING FAILED: " << e.what() << endl;
		}
	}

	std::vector<matrix<float, 0, 1>> Recognizer::getMat(array2d<rgb_pixel>* face11, array2d<rgb_pixel>* face12) {
		matrix<rgb_pixel> face21 = mat(*face11);
		matrix<rgb_pixel> face22 = mat(*face12);
		faces.push_back(face21);
		faces.push_back(face22);
		std::vector<matrix<float, 0, 1>> face_descriptor = net(faces);  // performing the neural network 
		// return length(face_descriptor[1] - face_descriptor[0]);
		return face_descriptor;
	}

	QString Recognizer::getVerdict(double diff)
	{
		if (diff < 0.63) {
			return QString().fromStdString("Same");
		}
		else {
			return QString().fromStdString("Different");
		}
	}

	QString Recognizer::getAccu(double diff)
	{
		if (diff > 0 && diff <= 0.2) {
			return QString().fromStdString("Very High");
		}
		else if (diff > 0.2&&diff <= 0.35) {
			return QString().fromStdString("High");
		}
		else if (diff > 0.35&&diff <= 0.5) {
			return QString().fromStdString("Medium");
		}
		else if (diff > 0.5 && diff <= 0.63) {
			return QString().fromStdString("Low");
		}
		else if (diff > 0.63&&diff <= 0.75) {
			return QString().fromStdString("Low");
		}
		else if (diff > 0.75&&diff <= 0.85) {
			return QString().fromStdString("Medium");
		}
		else if (diff > 0.85&&diff <= 0.9) {
			return QString().fromStdString("High");
		}
		else if (diff > 0.9) {
			return QString().fromStdString("Very High");
		}
		return QString().fromStdString("Invalid");
	}

	float Recognizer::getThreshold() {
		return net.loss_details().get_distance_threshold();
	}
}