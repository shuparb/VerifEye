#ifndef PATIENT_H
#define PATIENT_H
#include <direct.h>
#include <qmessagebox.h>
#include <qsqlrecord.h>
#include <qdatetime.h>
#include "db.h"
#include "pre.h"
#include "post.h"
#include "db.h"

using namespace verifEye;

namespace verifEye {
	class Patient {
	private:
		QString basePath = "./db-data";

	public:
		int pid;
		QString dateStrCont;
		QString pidIntCont;
		QString fnameStrCont;
		QString lnameStrCont;
		QString pre_image_pathStrCont;
		QString post_image_pathStrCont;
		QString eidStrCont;
		QString hidIntCont;
		QString hnameStrCont;
		QString hlocStrCont;
		QString stateStrCont;
		QString pre_face_pathStrCont;
		QString post_face_pathStrCont;
		QString pre_hface_pathStrCont;
		QString post_hface_pathStrCont;
		QString pmat_pathStrCont;
		QString resultStrCont;
		QString matStrCont;
		QString verdictStrCont;
		QString real_verdictStrCont;
		int pre_xtend, post_xtend;
		rectangle pre_rectangle, post_rectangle;
		Pre pre;
		Post post;
		Database db;
		std::vector<matrix<float, 0, 1>> mat;
		Patient();
		Patient(int);
		Patient(Patient&);
		Patient(QString fname, QString lname, QString pre_img_path, QString post_img_path, QString eid, QString hid, QString state);
		~Patient();
		QString get_preImage();
		QString get_postImage();
		QString get_fname();
		QString get_lname();
		QString get_fullname();
		QString get_eid();
		QString get_hospital();
		void set_eid(QString);
		void cropPreFullRect();
		void cropPostFullRect();
		void cropPreHalfRect();
		void cropPostHalfRect();
		void saveMat();
		bool saveAll();
	};
}

#endif // !PATIENT_H
