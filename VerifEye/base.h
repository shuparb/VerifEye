#ifndef BASE_H
#define BASE_H
#include <string>
#include <math.h>
#include <dlib/image_io.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <qstring.h>

using namespace std;
using namespace dlib;

namespace verifEye {
	class Base {
	private:
		string filename;
		array2d<rgb_pixel> rgb_src;		// color image input 
		array2d<unsigned char> gray_src;		// gray image input 
	protected:
		// Average positions of face points 17-67
		const double mean_face_shape_x[100] = {
			0.000213256, 0.0752622, 0.18113, 0.29077, 0.393397, 0.586856, 0.689483, 0.799124,
			0.904991, 0.98004, 0.490127, 0.490127, 0.490127, 0.490127, 0.36688, 0.426036,
			0.490127, 0.554217, 0.613373, 0.121737, 0.187122, 0.265825, 0.334606, 0.260918,
			0.182743, 0.645647, 0.714428, 0.793132, 0.858516, 0.79751, 0.719335, 0.254149,
			0.340985, 0.428858, 0.490127, 0.551395, 0.639268, 0.726104, 0.642159, 0.556721,
			0.490127, 0.423532, 0.338094, 0.290379, 0.428096, 0.490127, 0.552157, 0.689874,
			0.553364, 0.490127, 0.42689
		};
		const double mean_face_shape_y[100] = {
			0.106454, 0.038915, 0.0187482, 0.0344891, 0.0773906, 0.0773906, 0.0344891,
			0.0187482, 0.038915, 0.106454, 0.203352, 0.307009, 0.409805, 0.515625, 0.587326,
			0.609345, 0.628106, 0.609345, 0.587326, 0.216423, 0.178758, 0.179852, 0.231733,
			0.245099, 0.244077, 0.231733, 0.179852, 0.178758, 0.216423, 0.244077, 0.245099,
			0.780233, 0.745405, 0.727388, 0.742578, 0.727388, 0.745405, 0.780233, 0.864805,
			0.902192, 0.909281, 0.902192, 0.864805, 0.784792, 0.778746, 0.785343, 0.778746,
			0.784792, 0.824182, 0.831803, 0.824182
		};
	public:
		int img_midx, img_midy, face_midx, face_midy;
		double tiltRad, tiltDeg, reqRad, reqDeg;
		array2d<rgb_pixel> halfFace;
		array2d<rgb_pixel> halfFace1;
		array2d<rgb_pixel> fullFace;
		QString rotFp, halfFp, fullFp, ogFp;
		int num_faces;
		std::vector<rectangle> face_box;		// detected face boxes
		std::vector<full_object_detection> face_land;		// detected face landmarks
		Base(string);		// constructor
		void resize();
		array2d<rgb_pixel>& get_color_src();		// get color image
		array2d<unsigned char>& get_gray_src();	// get gray image
		void tiltImage();
		void tilt();
	};
}

#endif BASE_H