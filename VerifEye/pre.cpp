#include "pre.h"
namespace verifEye {
	Pre::Pre(string filename) :Base(filename)
	{
		cout << "Pre image: " << filename << endl;
	}

	/*
	chip_details Pre::get_face_chip_details(unsigned long xsize, unsigned long ysize, double padding) {
		std::vector<dpoint> from_points, to_points;
		full_object_detection a = face_land[0];
		for (unsigned long i = 0; i < a.num_parts(); i++) {
			if (i==chin||i==head_top)
				continue;
			dpoint p;
			p.x() = (padding + mean_face_shape_x[i]) / (2 * padding + 1);
			p.y() = (padding + mean_face_shape_y[i]) / (2 * padding + 1);
			// cout << "Initial: x " << p.x() << " y " << p.y() << endl;
			p.x() *= xsize;
			p.y() *= ysize;
			from_points.push_back(p);
			// cout << "After: x " << p.x() << " y " << p.y() << endl;
			to_points.push_back(a.part(i));
		}
		return chip_details(from_points, to_points, chip_dims(xsize, ysize));
	}
	*/


}