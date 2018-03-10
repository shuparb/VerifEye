#include "patient.h"

verifEye::Patient::Patient() :pre("./pre1.jpg"), post("./left1.jpg")
{

}

verifEye::Patient::Patient(int id) : pre("./pre1.jpg"), post("./left1.jpg")
{
	db = Database("./main.db");
	QSqlQuery query = QSqlQuery(db.db);
	query.exec();
	query.prepare("select pid, date, fname, lname, eid, hname, hloc, state, verdict, real_verdict, pre_face_path, post_face_path, result from patients, hospitals where patients.hid = hospitals.hid and pid="+id);
	if (query.exec()) {
		fnameStrCont = db.getSingleValueFromQuery(query);
	}
}

verifEye::Patient::Patient(Patient& patient):pre(patient.pre_face_pathStrCont.toStdString()), post(patient.post_image_pathStrCont.toStdString())
{
	db = Database("./main.db");
	db.openDb();
	QSqlQuery query = QSqlQuery(db.db);
	int max_pid = 0;
	query.prepare("select max(pid) from patient");
	if (query.exec())
		max_pid = db.getSingleValueFromQuery(query).toInt();
	pid = max_pid + 1;
	_mkdir("./data-db/pid");
	this->fnameStrCont = patient.fnameStrCont;
	this->lnameStrCont = max_pid + 1;
	this->pre_image_pathStrCont = patient.pre_face_pathStrCont;
	this->post_image_pathStrCont = patient.post_face_pathStrCont;
	this->eidStrCont = patient.eidStrCont;
	this->hidIntCont = patient.hidIntCont;
	this->stateStrCont = patient.stateStrCont;
	this->pre.rotFp = "./rot_pre_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
	this->pre.halfFp = "./half_pre_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
	this->pre.fullFp = "./half_pre_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
	this->post.rotFp = "./rot_post_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
	this->post.halfFp = "./half_post_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
	this->post.fullFp = "./half_post_" + fnameStrCont + "_" + lnameStrCont + ".jpg";
}

verifEye::Patient::Patient(QString fname, QString lname, QString pre_img_path, QString post_img_path, QString eid, QString hid, QString state) : pre(pre_img_path.toStdString()), post(post_img_path.toStdString())
{
	db = Database("./main.db");
	db.openDb();
	QSqlQuery query = QSqlQuery(db.db);
	int max_pid = 0;
	query.prepare("select max(pid) from patients");
	if (query.exec())
		max_pid = db.getSingleValueFromQuery(query).toInt();
	pid = max_pid+1;
	std::string dir = "./data-db/" + std::to_string(pid);
	_mkdir(dir.c_str());
	this->fnameStrCont = fname;
	this->lnameStrCont = lname;
	this->pre_image_pathStrCont = pre_img_path;
	this->post_image_pathStrCont = post_img_path;
	this->eidStrCont = eid;
	this->hidIntCont = hid;
	this->stateStrCont = state;
	this->pre.rotFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/rot_pre_.jpg");
	this->pre.halfFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/half_pre_.jpg");
	this->pre.fullFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/full_pre_.jpg");
	this->post.rotFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/rot_post_.jpg");
	this->post.halfFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/half_post_.jpg");
	this->post.fullFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/full_post_.jpg");
	this->pre.ogFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/og_pre_.jpg");
	this->post.ogFp = QString::fromStdString("./data-db/" + std::to_string(pid) + "/og_post_.jpg");
	this->matStrCont = QString::fromStdString("./data-db/" + std::to_string(pid) + "/mat.dat");
	save_jpeg(pre.get_color_src(), pre.ogFp.toStdString());
	save_jpeg(post.get_color_src(), post.ogFp.toStdString());
}

verifEye::Patient::~Patient()
{
	db.closeDb();
}

QString verifEye::Patient::get_preImage()
{
	return pre.ogFp;
}



QString verifEye::Patient::get_postImage()
{
	return post.ogFp;
}

QString verifEye::Patient::get_fname()
{
	return fnameStrCont;
}

QString verifEye::Patient::get_lname()
{
	return lnameStrCont;
}

QString verifEye::Patient::get_fullname()
{
	return fnameStrCont + " " + lnameStrCont;
}

QString verifEye::Patient::get_eid()
{
	return eidStrCont;
}

QString verifEye::Patient::get_hospital()
{
	return hidIntCont;
}

void verifEye::Patient::set_eid(QString newEid){
	eidStrCont = newEid;
}

void verifEye::Patient::cropPreFullRect()
{
	pre_rectangle = rectangle(pre.face_box[0].left(), pre.face_box[0].top(), pre.face_box[0].right(), pre.face_box[0].bottom());
	extract_image_chip(pre.get_color_src(), pre_rectangle, pre.fullFace);
	save_jpeg(pre.fullFace, pre.fullFp.toStdString(), 100);
}

void verifEye::Patient::cropPostFullRect()
{
	post_rectangle = rectangle(post.face_box[0].left(), post.face_box[0].top(), post.face_box[0].right(), post.face_box[0].bottom());
	extract_image_chip(pre.get_color_src(), post_rectangle, post.fullFace);
	save_jpeg(post.fullFace, post.fullFp.toStdString(), 100);
}

void verifEye::Patient::cropPreHalfRect()
{
	if (get_eid() == "left"|| get_eid() == "none") {
		pre_xtend = pre.face_land[0].part(pre.chin).x() > pre.face_land[0].part(pre.head_top).x() ? (pre.face_land[0].part(pre.chin).x() > pre.face_land[0].part(pre.lt_nstr).x() ? pre.face_land[0].part(pre.chin).x() : pre.face_land[0].part(pre.lt_nstr).x()) : (pre.face_land[0].part(pre.head_top).x() > pre.face_land[0].part(pre.lt_nstr).x() ? pre.face_land[0].part(pre.head_top).x() : pre.face_land[0].part(pre.lt_nstr).x());
		pre_rectangle = rectangle(pre.face_box[0].left(), pre.face_box[0].top(), pre_xtend, pre.face_box[0].bottom());
	}
	else if (get_eid() == "right") {
		pre_xtend = pre.face_land[0].part(pre.chin).x() > pre.face_land[0].part(pre.head_top).x() ? (pre.face_land[0].part(pre.chin).x() > pre.face_land[0].part(pre.rt_nstr).x() ? pre.face_land[0].part(pre.chin).x() : pre.face_land[0].part(pre.rt_nstr).x()) : (pre.face_land[0].part(pre.head_top).x() > pre.face_land[0].part(pre.rt_nstr).x() ? pre.face_land[0].part(pre.head_top).x() : pre.face_land[0].part(pre.rt_nstr).x());
		pre_rectangle = rectangle(pre_xtend, pre.face_box[0].top(), pre.face_box[0].right(), pre.face_box[0].bottom());
	}
	extract_image_chip(pre.get_color_src(), pre_rectangle, pre.halfFace1);
	if(get_eid()=="right")
		flip_image_left_right(pre.halfFace1);
	resize_image(pre.halfFace1, pre.halfFace);
	save_jpeg(pre.halfFace, pre.halfFp.toStdString(), 100);
}

void verifEye::Patient::cropPostHalfRect()
{
	if (get_eid() == "left") {
		post_xtend = post.face_land[0].part(post.lt__chin).x() > post.face_land[0].part(post.lt__head_top).x() ? (post.face_land[0].part(post.lt__chin).x() > post.face_land[0].part(post.lt__lt_nstr).x() ? post.face_land[0].part(post.lt__chin).x() : post.face_land[0].part(post.lt__lt_nstr).x()) : (post.face_land[0].part(post.lt__head_top).x() > post.face_land[0].part(post.lt__lt_nstr).x() ? post.face_land[0].part(post.lt__head_top).x() : post.face_land[0].part(post.lt__lt_nstr).x());
		post_rectangle = rectangle(post.face_box[0].left(), post.face_box[0].top(), post_xtend, post.face_box[0].bottom());
	}
	else if (get_eid() == "right") {
		post_xtend = post.face_land[0].part(post.rt__chin).x() > post.face_land[0].part(post.rt__head_top).x() ? (post.face_land[0].part(post.rt__chin).x() > post.face_land[0].part(post.rt__rt_nstr).x() ? post.face_land[0].part(post.rt__chin).x() : post.face_land[0].part(post.rt__rt_nstr).x()) : (post.face_land[0].part(post.rt__head_top).x() > post.face_land[0].part(post.rt__rt_nstr).x() ? post.face_land[0].part(post.rt__head_top).x() : post.face_land[0].part(post.rt__rt_nstr).x());
		post_rectangle = rectangle(post_xtend, post.face_box[0].top(), post.face_box[0].right(), post.face_box[0].bottom());
	}
	else if (get_eid() == "none") {
		post_xtend = post.face_land[0].part(pre.chin).x() > post.face_land[0].part(pre.head_top).x() ? (post.face_land[0].part(pre.chin).x() > post.face_land[0].part(pre.lt_nstr).x() ? post.face_land[0].part(pre.chin).x() : post.face_land[0].part(pre.lt_nstr).x()) : (post.face_land[0].part(pre.head_top).x() > post.face_land[0].part(pre.lt_nstr).x() ? post.face_land[0].part(pre.head_top).x() : post.face_land[0].part(pre.lt_nstr).x());
		post_rectangle = rectangle(post.face_box[0].left(), post.face_box[0].top(), post_xtend, post.face_box[0].bottom());
	}

	extract_image_chip(post.get_color_src(), post_rectangle, post.halfFace1);
	if (get_eid() == "right")
		flip_image_left_right(post.halfFace1);
	resize_image(post.halfFace1, post.halfFace);
	save_jpeg(post.halfFace, post.halfFp.toStdString(), 100);
}

void verifEye::Patient::saveMat()
{
	serialize(matStrCont.toStdString()) << mat;
}

bool verifEye::Patient::saveAll()
{
	saveMat();
	QSqlQuery query = QSqlQuery(db.db);
	query.prepare("insert into patients (date, fname, lname, pre_img_path, post_img_path, eid, hid, verdict, real_verdict, pre_face_path, post_face_path, pre_hface_path, post_hface_path, pre_rot_face_path, post_rot_face_path, pmat_path, state, result) values( '"+QDate::currentDate().toString()+"','" + fnameStrCont + "','" + lnameStrCont + "','"+ pre.ogFp + "','" + post.ogFp + "','" + eidStrCont + "','" + hidIntCont + "','" + verdictStrCont + "','" + real_verdictStrCont + "','" + pre.fullFp + "','" + post.fullFp + "','" + pre.halfFp + "','" + post.halfFp + "','" + pre.rotFp + "','" + post.rotFp + "','" + matStrCont+"','"+stateStrCont+"','"+ resultStrCont +"')");
	if (query.exec()) {
		return true;
	}
	return false;
}
