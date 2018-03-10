#ifndef POST_H
#define POST_H
#include "base.h"

namespace verifEye {
	class Post:public Base
	{
	public:
		enum left_ep_landm_pts {
			lt__chin,
			lt__head_top,
			lt__lo_lip,
			lt__lt_lip,
			lt__lt_nose,
			lt__lt_nstr,
			lt__mid_nose,
			lt__r_eye_l,
			lt__r_eye_r,
			lt__rt_lip,
			lt__rt_nose,
			lt__rt_nstr,
			lt__up_lip
		};
		enum right_ep_landm_pts {
			rt__chin,
			rt__head_top,
			rt__l_eye_l,
			rt__l_eye_r,
			rt__lo_lip,
			rt__lt_lip,
			rt__lt_nose,
			rt__lt_nstr,
			rt__mid_nose,
			rt__rt_lip,
			rt__rt_nose,
			rt__rt_nstr,
			rt__up_lip
		};
		std::vector<rectangle> eyepatch_box;
		int num_eyepatch;
		Post(string);
		int calculateEyepatch();
	};
}

#endif POST_H
