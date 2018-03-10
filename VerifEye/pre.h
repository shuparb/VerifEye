#ifndef PRE_H
#define PRE_H
#include "base.h"

namespace verifEye {
	class Pre :public Base
	{
	private:
		const double pre_mean_face_shape_x[20] = {
			0.5, 0.5, mean_face_shape_x[45-17], mean_face_shape_x[42-17], mean_face_shape_x[57-17], mean_face_shape_x[54-17], mean_face_shape_x[35-17], 
			mean_face_shape_x[34-17], mean_face_shape_x[33-17], mean_face_shape_x[39-17], mean_face_shape_x[36-17], mean_face_shape_x[48-17],
			mean_face_shape_x[31-17], mean_face_shape_x[32-17], mean_face_shape_x[51-17]
		};
		const double pre_mean_face_shape_y[20] = {
			0.8, 0.2, mean_face_shape_y[45-17], mean_face_shape_y[42-17], mean_face_shape_y[57-17], mean_face_shape_y[54-17], mean_face_shape_y[35-17],
			mean_face_shape_y[34-17], mean_face_shape_y[33-17], mean_face_shape_y[39-17], mean_face_shape_y[36-17], mean_face_shape_y[48-17],
			mean_face_shape_y[31-17], mean_face_shape_y[32-17], mean_face_shape_y[51-17]
		};

	public:
		enum landm_pts {
			chin,
			head_top,
			l_eye_l,
			l_eye_r,
			lo_lip,
			lt_lip,
			lt_nose,
			lt_nstr,
			mid_nose,
			r_eye_l,
			r_eye_r,
			rt_lip,
			rt_nose,
			rt_nstr,
			up_lip
		};
		Pre(string);		// constructor
		chip_details get_face_chip_details(unsigned long xsize = 257, unsigned long ysize = 257, double = 0.2);

	};
}

#endif PRE_H