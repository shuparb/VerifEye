#ifndef MODNN_H
#define MODNN_H
#include "detector.h"
#include "landmark.h"
#include "recog.h"

namespace verifEye {
	class Modnn {
	public:
		Detector detector;
		Landmark landmark;
		Recognizer recognizer;
		Modnn();
	};
}

#endif MODNN_H