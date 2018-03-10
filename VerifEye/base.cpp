#include "base.h"
namespace verifEye {
	Base::Base(string filename):filename(filename)
	{
		try {
			load_image(rgb_src, filename);
			load_image(gray_src, filename);
			resize();
			halfFace = array2d<rgb_pixel>(257, 128);
		}
		catch (exception e) {
			cout << "ERROR: Opening " << filename <<"\nDescription: "<<e.what()<< endl;
		}
	}

	void Base::resize()
	{
		int num_cols = rgb_src.nc();
		if (num_cols <= 640) {

		}
		else if (num_cols > 640 && num_cols <= 1000) {
			resize_image(0.8, rgb_src);
			resize_image(0.8, gray_src);
		}
		else if (num_cols > 1000 && num_cols <= 1500) {
			resize_image(0.7, rgb_src);
			resize_image(0.7, gray_src);
		}
		else if (num_cols > 1500 && num_cols <= 2000) {
			resize_image(0.7, rgb_src);
			resize_image(0.7, gray_src);
		}
		else if (num_cols > 2000 && num_cols <= 3000) {
			resize_image(0.6, rgb_src);
			resize_image(0.6, gray_src);
		}
		else if (num_cols > 3000) {
			resize_image(0.2, rgb_src);
			resize_image(0.2, gray_src);
		}
	}

	array2d<rgb_pixel>& Base::get_color_src() {
		return rgb_src;
	}

	array2d<unsigned char>& Base::get_gray_src() {
		equalize_histogram(gray_src);
		// image_window win;
		// win.set_image(gray_src);
		// win.wait_until_closed();
		return gray_src;
	}
	void Base::tiltImage()
	{
		std::thread t(&Base::tilt, this);
		t.join();
		//tilt();
	}
	void Base::tilt()
	{
		tiltRad = atan2(face_land[0].part(0).y() - face_land[0].part(1).y(), face_land[0].part(0).x() - face_land[0].part(1).x());
		tiltDeg = tiltRad * (180 / 3.14);
		reqDeg = tiltDeg - 90;
		reqRad = reqDeg * (3.14 / 180);
		array2d<rgb_pixel> copy;
		array2d<unsigned char> copy_gray;
		rotate_image(rgb_src, copy, reqRad);
		rotate_image(gray_src, copy_gray, reqRad);
		assign_image(rgb_src, copy);
		assign_image(gray_src, copy_gray);

		int prevFaceMidx = face_midx;
		int prevFaceMidy = face_midy;
		face_midx = std::cos(reqRad)*(prevFaceMidx - img_midx) - sin(reqRad)*(prevFaceMidy - img_midy) + img_midx;
		face_midy = std::sin(reqRad)*(prevFaceMidx - img_midx) + cos(reqRad)*(prevFaceMidy - img_midy) + img_midy;

		rectangle newResRot = rectangle(face_midx-face_box[0].width()/2-20, face_midy-face_box[0].height()-20, face_midx+face_box[0].width()/2+80, face_midy+face_box[0].height()/2+80);
		array2d<rgb_pixel> newCropRotColor;
		array2d<unsigned char> newCropRotGray;
		extract_image_chip(rgb_src, newResRot, newCropRotColor);
		extract_image_chip(gray_src, newResRot, newCropRotGray);
		assign_image(rgb_src, newCropRotColor);
		assign_image(gray_src, newCropRotGray);
		save_jpeg(rgb_src, rotFp.toStdString());

	}
}