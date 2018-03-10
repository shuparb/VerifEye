#include "post.h"
namespace verifEye {
	Post::Post(string filename):Base(filename)
	{
		cout << "Post image: " << filename << endl;
	}
	int Post::calculateEyepatch()
	{
		if (face_box.size()>0 && eyepatch_box.size()>0) {
			int patch_mid_x = (eyepatch_box[0].left() + eyepatch_box[0].width() / 2);
			int l_eye_dist = abs(face_box[0].right() - patch_mid_x);
			int r_eye_dist = abs(face_box[0].left() - patch_mid_x);
			if (l_eye_dist < r_eye_dist)
				return 1;
			else
				return 2;
		}
		return 3;
	}
/*
	std::vector<chip_details> Post::get_face_chip_details(unsigned long, double padding) {
		
		std::vector<chip_details> result;
		std::vector<dpoint> from_points, to_points;
		for (auto a : face_land) {
			for (int i = 0; i < a.num_parts(); i++) {
				if (i == chin || i == head_top)
					continue;
				dpoint p;
				p.x() = (padding + mean_face_shape_x[i]) / (2 * padding + 1);
				p.y() = (padding + mean_face_shape_y[i]) / (2 * padding + 1);
				from_points.push_back(p*size);
				to_points.push_back(a.part(i));
				result.push_back(chip_details(from_points, to_points, chip_dims(size, size)));
			}
		}
		return result;
		
	}*/


}