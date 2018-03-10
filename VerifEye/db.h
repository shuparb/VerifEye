#ifndef DB_H
#define DB_H
#include<qsqldatabase.h>
#include<qsqldriver.h>
#include<qsqlquery.h>
#include<qsqlquerymodel.h>

namespace verifEye {
	// tables
	static QString patients = "patients";
	static QString hospitals = "hospitals";
	// hospitals's coloumns 
	static QString _hidInt = "hid";
	static QString _hnameStr = "hname";
	static QString _hlocStr = "hloc";
	// patients's coloumns 
	static QString pidInt = "pid";
	static QString fnameStr = "fname";
	static QString lnameStr = "lname";
	static QString pre_image_pathStr = "pre_img_path";
	static QString post_image_pathStr = "post_img_path";
	static QString eidStr = "eid";
		static QString eidStrOptLeft = "left";
		static QString eidStrOptRight = "right";
	static QString hidInt = "hid";
	static QString stateStr = "state";
	static QString verdictStr = "verdict";
	static QString real_verdictStr = "real_verdict";
		static QString verdictStrOptSame = "Same";
		static QString verdictStrOptDifferent = "Different";
	static QString pre_face_pathStr = "pre_face_path";
	static QString post_face_pathStr = "post_face_path";
	static QString pre_hface_pathStr = "pre_hface_path";
	static QString post_hface_pathStr = "post_hface_path";
	static QString pmat_pathStr = "pmat_path";
	static QString result = "result";
		static QString resultStrOptAccept = "accept";
		static QString resultStrOptReject = "reject";
		static QString resultStrOptError = "error";
	class Database {
	private:

	public:
		QSqlDatabase db;
		bool connected;
		Database();
		Database(const std::string);
		bool openDb();
		bool closeDb();
		QString getSingleValueFromQuery(QSqlQuery);
	};
}

#endif DB_H