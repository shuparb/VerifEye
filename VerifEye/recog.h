#ifndef RECOG_H
#define RECOG_H
#include <dlib/dnn.h>
#include <string>
#include <qstring.h>

using namespace dlib;
using namespace std;

namespace verifEye {
	template <template <int, template<typename>class, int, typename> class block, int N, template<typename>class BN, typename SUBNET>
	using residual = add_prev1<block<N, BN, 1, tag1<SUBNET>>>;

	template <template <int, template<typename>class, int, typename> class block, int N, template<typename>class BN, typename SUBNET>
	using residual_down = add_prev2<avg_pool<2, 2, 2, 2, skip1<tag2<block<N, BN, 2, tag1<SUBNET>>>>>>;

	template <int N, template <typename> class BN, int stride, typename SUBNET>
	using block = BN<con<N, 3, 3, 1, 1, relu<BN<con<N, 3, 3, stride, stride, SUBNET>>>>>;

	template <int N, typename SUBNET> using ares = relu<residual<block, N, affine, SUBNET>>;
	template <int N, typename SUBNET> using ares_down = relu<residual_down<block, N, affine, SUBNET>>;


	template <typename SUBNET> using alevel0 = ares_down<256, SUBNET>;
	template <typename SUBNET> using alevel1 = ares<256, ares<256, ares_down<256, SUBNET>>>;
	template <typename SUBNET> using alevel2 = ares<128, ares<128, ares_down<128, SUBNET>>>;
	template <typename SUBNET> using alevel3 = ares<64, ares<64, ares<64, ares_down<64, SUBNET>>>>;
	template <typename SUBNET> using alevel4 = ares<32, ares<32, ares<32, SUBNET>>>;

	// finished net 
	using anet_type = loss_metric<fc_no_bias<128, avg_pool_everything<
		alevel0<
		alevel1<
		alevel2<
		alevel3<
		alevel4<
		max_pool<3, 3, 2, 2, relu<affine<con<32, 7, 7, 2, 2,
		input_rgb_image
		>>>>>>>>>>>>;

	static const string NET_PATH = "./models/train_dnn_left_eyepatch_face.dat";

	class Recognizer {
	private:
		std::vector<matrix<rgb_pixel>> faces;
		anet_type net;			// dnn 
	public:
		Recognizer();			// constructor
		float getThreshold();
		std::vector<matrix<float, 0, 1>> getMat(array2d<rgb_pixel>*, array2d<rgb_pixel>*);
		QString getVerdict(double diff);
		QString getAccu(double diff);
	};
}

#endif RECOG_H