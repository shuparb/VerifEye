#include "Patient_Detection.h"

Patient_Detection::Patient_Detection(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Patient_Detection();
	ui->setupUi(this);
	ui->pushButton_recog->setVisible(false);
	j = 0;
}

void Patient_Detection::loadPatient(Patient * patient)
{
	this->patient = patient;
	loadProfile();
	loadPreImage();
	loadPostImage();
}

void Patient_Detection::showEvent(QShowEvent * event)
{
	QWidget::showEvent(event);
}

void Patient_Detection::loadProfile()
{
	updateLabel(ui->label_full_name, patient->get_fullname());
	updateLabel(ui->label_eid, patient->get_eid());
	updateLabel(ui->label_hospital, patient->get_hospital());
}

void Patient_Detection::loadPreImage()
{
	QImage preImage = QImage(patient->get_preImage());
	pre_scene = new QGraphicsScene();
	pre_scene->addPixmap(QPixmap::fromImage(preImage));
	ui->graphicsView_preImage->setScene(pre_scene);
	//ui->graphicsView_preImage->fitInView(pre_scene->sceneRect(), Qt::KeepAspectRatio);
}

void Patient_Detection::loadPostImage()
{
	QImage postImage = QImage(patient->get_postImage());
	post_scene = new QGraphicsScene();
	post_scene->addPixmap(QPixmap::fromImage(postImage));
	ui->graphicsView_postImage->setScene(post_scene);
	//ui->graphicsView_postImage->fitInView(post_scene->sceneRect(), Qt::KeepAspectRatio);
}
// const
const int STEP_DETECT1 = 0;
const int STEP_LANDMARK1 = 1;
const int STEP_ROTATE = 2;
const int STEP_DETECT2 = 3;
const int STEP_LANDMARK2 = 4;
void Patient_Detection::doProc(QWidget* parent)
{
	//flash = new QSplashScreen;
	//flash->setPixmap(QPixmap::fromImage(QImage("./load.jpg")));
	switch (j) {
	case STEP_DETECT1:
		//flash->show();
		//flash->showMessage(QString::fromStdString("Finding faces..."));
		detectPreImage();
		detectPostImage();
		detectEyepatch();
		//flash->finish(this);
		break;
	case STEP_LANDMARK1:
		//flash->show();
		//flash->showMessage(QString::fromStdString("Finding facial features..."));
		detectPreLandmark();
		detectPostLandmark();
		//flash->finish(this);
		break;
	case STEP_ROTATE:
		//flash->show();
		//flash->showMessage(QString::fromStdString("Adjusting..."));
		rotatePre();
		rotatePost();
		clearPlots();
		//flash->finish(this);
		break;
	case STEP_DETECT2:
		//flash->show();
		//flash->showMessage(QString::fromStdString("Finding faces..."));

		detectPreImage();
		detectPostImage();
		detectEyepatch();
		//flash->finish(this);
		break;
	case STEP_LANDMARK2:
		//flash->show();
		//flash->showMessage(QString::fromStdString("Finding facial features..."));
		detectPreLandmark();
		detectPostLandmark();
		//flash->finish(this);
		break;
	}
	updatePreInfo();
	updatePreDraw();
	updatePostInfo();
	updatePostDraw();
	j++;
}

void Patient_Detection::detectPreImage()
{
	patient->pre.num_faces = modnn->detector.detect_pre_face(patient->pre.get_gray_src(), patient->pre.face_box);
	patient->pre.img_midx = patient->pre.get_color_src().nc() / 2;
	patient->pre.img_midy = patient->pre.get_color_src().nr() / 2;
	patient->pre.face_midx = patient->pre.face_box[0].left() + patient->pre.face_box[0].width()/ 2;
	patient->pre.face_midy = patient->pre.face_box[0].top() + patient->pre.face_box[0].height() / 2;
}

void Patient_Detection::detectPostImage()
{
	patient->post.num_faces = modnn->detector.detect_post_face(patient->post.get_gray_src(), patient->post.face_box);
	patient->post.img_midx = patient->post.get_color_src().nc() / 2;
	patient->post.img_midy = patient->post.get_color_src().nr() / 2;
	patient->post.face_midx = patient->post.face_box[0].left() + patient->post.face_box[0].width() / 2;
	patient->post.face_midy = patient->post.face_box[0].top() + patient->post.face_box[0].height() / 2;
}

void Patient_Detection::detectEyepatch()
{
	patient->post.num_eyepatch = modnn->detector.detect_eyepatch(patient->post.get_gray_src(), patient->post.eyepatch_box);
	if (patient->post.calculateEyepatch() == 1)
		detected_eid = "left";
	else if (patient->post.calculateEyepatch() == 2)
		detected_eid = "right";
	else if (patient->post.calculateEyepatch() == 3)
		detected_eid = "none";
	if (detected_eid != patient->get_eid()) {
		QMessageBox::StandardButton disc = QMessageBox::question(this, "Eyepatch ID Conflict: ", "Provided eyepatch id & detected eyepatch ID don't match\nDo you want to choose detected eyepatch?\nPROVIDED: "+patient->get_eid()+"\nDETECTED: "+detected_eid, QMessageBox::Yes | QMessageBox::No);
		if (disc == QMessageBox::Yes) {
			patient->set_eid(detected_eid);
			ui->label_eid->setText(patient->get_eid());
		}
	}
}

void Patient_Detection::detectPreLandmark()
{
	modnn->landmark.detect_pre_face_landmark(patient->pre.get_gray_src(), patient->pre.face_box, patient->pre.face_land);

}

void Patient_Detection::detectPostLandmark()
{
	if (patient->get_eid() == "left") {
		modnn->landmark.detect_post_face_le_landmark(patient->post.get_gray_src(), patient->post.face_box, patient->post.face_land);
	}
	else if (patient->get_eid() == "right") {
		modnn->landmark.detect_post_face_re_landmark(patient->post.get_gray_src(), patient->post.face_box, patient->post.face_land);
	}
	else if (patient->get_eid() == "none") {
		modnn->landmark.detect_pre_face_landmark(patient->post.get_gray_src(), patient->post.face_box, patient->post.face_land);
	}

}

void Patient_Detection::rotatePre()
{
	patient->pre.tiltImage();
}

void Patient_Detection::rotatePost()
{
	patient->post.tiltImage();
}

void Patient_Detection::updatePreInfo()
{
	switch (j) {
	case STEP_DETECT1:
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nNumber of faces found: ") + std::to_string(patient->pre.num_faces)));
		break;
	case STEP_LANDMARK1:
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nLandmarking done...")));
		break;
	case STEP_ROTATE:
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\n----------------------------------------------------------------------------")));
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nFaces found tilted at angle: ") + std::to_string(patient->pre.tiltDeg)));
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nRotating image by angle: ") + std::to_string(patient->pre.reqDeg)));
		break;
	case STEP_DETECT2:
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\n----------------------------------------------------------------------------")));
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nNumber of faces found: ") + std::to_string(patient->pre.num_faces)));
		break;
	case STEP_LANDMARK2:
		updateTextEdit(ui->textEdit_preInfo, QString::fromStdString(std::string("\nLandmarking done...")));
		break;
	}
}

void Patient_Detection::updatePostInfo()
{
	switch (j) {
	case STEP_DETECT1:
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nNumber of faces found: ") + std::to_string(patient->post.num_faces)));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nNumber of eyepatches found: ") + std::to_string(patient->post.num_eyepatch)));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nDetected eyepatch ID found: ") + detected_eid.toStdString()));
		break;
	case STEP_LANDMARK1:
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nLandmarking done...")));
		break;
	case STEP_ROTATE:
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\n----------------------------------------------------------------------------")));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nFaces found tilted at angle: ") + std::to_string(patient->post.tiltDeg)));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nRotating image by angle: ") + std::to_string(patient->post.reqDeg)));
		break;
	case STEP_DETECT2:
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\n----------------------------------------------------------------------------")));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nNumber of faces found: ") + std::to_string(patient->post.num_faces)));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nNumber of eyepatches found: ") + std::to_string(patient->post.num_eyepatch)));
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nDetected eyepatch ID found: ") + detected_eid.toStdString()));
		break;
	case STEP_LANDMARK2:
		updateTextEdit(ui->textEdit_postInfo, QString::fromStdString(std::string("\nLandmarking done...")));
		break;
	}
}

void Patient_Detection::updatePreDraw()
{
	QPen pen = QPen(Qt::blue);
	pen.setWidth(20);
	switch (j) {
	case STEP_DETECT1:
		if (patient->pre.face_box.size() > 0) {
			pen.setColor(Qt::blue);
			pen.setWidth(15);
			pre_scene->addRect(patient->pre.face_box[0].left(), patient->pre.face_box[0].top(), patient->pre.face_box[0].width(), patient->pre.face_box[0].height(), pen);
			pen.setColor(Qt::green);
			pre_scene->addRect(getPoint(patient->pre.img_midx, patient->pre.img_midy), pen);
			pen.setColor(Qt::yellow);
			pre_scene->addRect(getPoint(patient->pre.face_midx, patient->pre.face_midy), pen);
		}
		break;
	case STEP_LANDMARK1:
		pen.setColor(Qt::red);
		pen.setWidth(10);
		if (patient->pre.face_box.size() > 0) {
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.head_top).x(), patient->pre.face_land[0].part(patient->pre.head_top).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.chin).x(), patient->pre.face_land[0].part(patient->pre.chin).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lo_lip).x(), patient->pre.face_land[0].part(patient->pre.lo_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_lip).x(), patient->pre.face_land[0].part(patient->pre.lt_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_nose).x(), patient->pre.face_land[0].part(patient->pre.lt_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_nstr).x(), patient->pre.face_land[0].part(patient->pre.lt_nstr).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.mid_nose).x(), patient->pre.face_land[0].part(patient->pre.mid_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_lip).x(), patient->pre.face_land[0].part(patient->pre.rt_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_nose).x(), patient->pre.face_land[0].part(patient->pre.rt_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_nstr).x(), patient->pre.face_land[0].part(patient->pre.rt_nstr).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.l_eye_l).x(), patient->pre.face_land[0].part(patient->pre.l_eye_l).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.l_eye_r).x(), patient->pre.face_land[0].part(patient->pre.l_eye_r).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.r_eye_l).x(), patient->pre.face_land[0].part(patient->pre.r_eye_l).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.r_eye_r).x(), patient->pre.face_land[0].part(patient->pre.r_eye_r).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.up_lip).x(), patient->pre.face_land[0].part(patient->pre.up_lip).y()), pen);

		}
		break;
	case STEP_ROTATE:
		pre_scene->clear();
		pre_scene->addPixmap(QPixmap::fromImage(QImage(patient->pre.rotFp)));
		break;
	case STEP_DETECT2:
		pen.setColor(Qt::blue);
		pen.setWidth(15);
		if (patient->pre.face_box.size() > 0) {
			pre_scene->addRect(patient->pre.face_box[0].left(), patient->pre.face_box[0].top(), patient->pre.face_box[0].width(), patient->pre.face_box[0].height(), pen);
			pen.setColor(Qt::green);
			pre_scene->addRect(getPoint(patient->pre.img_midx, patient->pre.img_midy), pen);
			pen.setColor(Qt::green);
			pre_scene->addRect(getPoint(patient->pre.img_midx, patient->pre.img_midy), pen);
			pen.setColor(Qt::yellow);
			pre_scene->addRect(getPoint(patient->pre.face_midx, patient->pre.face_midy), pen);
		}
		break;
	case STEP_LANDMARK2:
		pen.setColor(Qt::red);
		pen.setWidth(10);
		if (patient->pre.face_land.size() > 0) {
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.head_top).x(), patient->pre.face_land[0].part(patient->pre.head_top).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.chin).x(), patient->pre.face_land[0].part(patient->pre.chin).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lo_lip).x(), patient->pre.face_land[0].part(patient->pre.lo_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_lip).x(), patient->pre.face_land[0].part(patient->pre.lt_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_nose).x(), patient->pre.face_land[0].part(patient->pre.lt_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.lt_nstr).x(), patient->pre.face_land[0].part(patient->pre.lt_nstr).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.mid_nose).x(), patient->pre.face_land[0].part(patient->pre.mid_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_lip).x(), patient->pre.face_land[0].part(patient->pre.rt_lip).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_nose).x(), patient->pre.face_land[0].part(patient->pre.rt_nose).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.rt_nstr).x(), patient->pre.face_land[0].part(patient->pre.rt_nstr).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.l_eye_l).x(), patient->pre.face_land[0].part(patient->pre.l_eye_l).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.l_eye_r).x(), patient->pre.face_land[0].part(patient->pre.l_eye_r).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.r_eye_l).x(), patient->pre.face_land[0].part(patient->pre.r_eye_l).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.r_eye_r).x(), patient->pre.face_land[0].part(patient->pre.r_eye_r).y()), pen);
			pre_scene->addRect(getPoint(patient->pre.face_land[0].part(patient->pre.up_lip).x(), patient->pre.face_land[0].part(patient->pre.up_lip).y()), pen);

		}
		break;
	}
}

void Patient_Detection::updatePostDraw()
{
	QPen pen = QPen(Qt::blue);
	pen.setWidth(20);
	switch (j) {
	case STEP_DETECT1:
		pen.setColor(Qt::blue);
		pen.setWidth(15);
		if (patient->post.face_box.size() > 0) {
			post_scene->addRect(patient->post.face_box[0].left(), patient->post.face_box[0].top(), patient->post.face_box[0].width(), patient->post.face_box[0].height(), pen);
		}
		if (patient->post.eyepatch_box.size() > 0) {
			post_scene->addRect(patient->post.eyepatch_box[0].left(), patient->post.eyepatch_box[0].top(), patient->post.eyepatch_box[0].width(), patient->post.eyepatch_box[0].height(), pen);
		}
		pen.setColor(Qt::green);
		post_scene->addRect(getPoint(patient->post.img_midx, patient->post.img_midy), pen);
		pen.setColor(Qt::yellow);
		post_scene->addRect(getPoint(patient->post.face_midx, patient->post.face_midy), pen);
		break;
	case STEP_LANDMARK1:
		pen.setColor(Qt::red);
		pen.setWidth(10);
		if (patient->post.face_land.size() > 0) {
			if (patient->get_eid() == "left") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__head_top).x(), patient->post.face_land[0].part(patient->post.lt__head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__chin).x(), patient->post.face_land[0].part(patient->post.lt__chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lo_lip).x(), patient->post.face_land[0].part(patient->post.lt__lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_lip).x(), patient->post.face_land[0].part(patient->post.lt__lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_nose).x(), patient->post.face_land[0].part(patient->post.lt__lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_nstr).x(), patient->post.face_land[0].part(patient->post.lt__lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__mid_nose).x(), patient->post.face_land[0].part(patient->post.lt__mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_lip).x(), patient->post.face_land[0].part(patient->post.lt__rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_nose).x(), patient->post.face_land[0].part(patient->post.lt__rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_nstr).x(), patient->post.face_land[0].part(patient->post.lt__rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__up_lip).x(), patient->post.face_land[0].part(patient->post.lt__up_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__r_eye_l).x(), patient->post.face_land[0].part(patient->post.lt__r_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__r_eye_r).x(), patient->post.face_land[0].part(patient->post.lt__r_eye_r).y()), pen);
			}
			else if (patient->get_eid() == "right") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__chin).x(), patient->post.face_land[0].part(patient->post.rt__chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__head_top).x(), patient->post.face_land[0].part(patient->post.rt__head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lo_lip).x(), patient->post.face_land[0].part(patient->post.rt__lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_lip).x(), patient->post.face_land[0].part(patient->post.rt__lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_nose).x(), patient->post.face_land[0].part(patient->post.rt__lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_nstr).x(), patient->post.face_land[0].part(patient->post.rt__lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__l_eye_l).x(), patient->post.face_land[0].part(patient->post.rt__l_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__l_eye_r).x(), patient->post.face_land[0].part(patient->post.rt__l_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__mid_nose).x(), patient->post.face_land[0].part(patient->post.rt__mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_lip).x(), patient->post.face_land[0].part(patient->post.rt__rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_nose).x(), patient->post.face_land[0].part(patient->post.rt__rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_nstr).x(), patient->post.face_land[0].part(patient->post.rt__rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__up_lip).x(), patient->post.face_land[0].part(patient->post.rt__up_lip).y()), pen);
			}
			else if (patient->get_eid() == "none") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.head_top).x(), patient->post.face_land[0].part(patient->pre.head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.chin).x(), patient->post.face_land[0].part(patient->pre.chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lo_lip).x(), patient->post.face_land[0].part(patient->pre.lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_lip).x(), patient->post.face_land[0].part(patient->pre.lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_nose).x(), patient->post.face_land[0].part(patient->pre.lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_nstr).x(), patient->post.face_land[0].part(patient->pre.lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.mid_nose).x(), patient->post.face_land[0].part(patient->pre.mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_lip).x(), patient->post.face_land[0].part(patient->pre.rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_nose).x(), patient->post.face_land[0].part(patient->pre.rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_nstr).x(), patient->post.face_land[0].part(patient->pre.rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.l_eye_l).x(), patient->post.face_land[0].part(patient->pre.l_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.l_eye_r).x(), patient->post.face_land[0].part(patient->pre.l_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.r_eye_l).x(), patient->post.face_land[0].part(patient->pre.r_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.r_eye_r).x(), patient->post.face_land[0].part(patient->pre.r_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.up_lip).x(), patient->post.face_land[0].part(patient->pre.up_lip).y()), pen);
			}
		}
		break;
	case STEP_ROTATE:
		post_scene->clear();
		post_scene->addPixmap(QPixmap::fromImage(QImage(patient->post.rotFp)));
		break;
	case STEP_DETECT2:
		pen.setColor(Qt::blue);
		pen.setWidth(15);
			if (patient->post.face_box.size() > 0) {
				post_scene->addRect(patient->post.face_box[0].left(), patient->post.face_box[0].top(), patient->post.face_box[0].width(), patient->post.face_box[0].height(), pen);
			}
			if (patient->post.eyepatch_box.size() > 0) {
				post_scene->addRect(patient->post.eyepatch_box[0].left(), patient->post.eyepatch_box[0].top(), patient->post.eyepatch_box[0].width(), patient->post.eyepatch_box[0].height(), pen);
			}
		pen.setColor(Qt::green);
		post_scene->addRect(getPoint(patient->post.img_midx, patient->post.img_midy), pen);
		pen.setColor(Qt::yellow);
		post_scene->addRect(getPoint(patient->post.face_midx, patient->post.face_midy), pen);
		break;
	case STEP_LANDMARK2:
		pen.setColor(Qt::red);
		pen.setWidth(10);
		if (patient->post.face_land.size() > 0) {
			if (patient->get_eid() == "left") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__head_top).x(), patient->post.face_land[0].part(patient->post.lt__head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__chin).x(), patient->post.face_land[0].part(patient->post.lt__chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lo_lip).x(), patient->post.face_land[0].part(patient->post.lt__lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_lip).x(), patient->post.face_land[0].part(patient->post.lt__lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_nose).x(), patient->post.face_land[0].part(patient->post.lt__lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__lt_nstr).x(), patient->post.face_land[0].part(patient->post.lt__lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__mid_nose).x(), patient->post.face_land[0].part(patient->post.lt__mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_lip).x(), patient->post.face_land[0].part(patient->post.lt__rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_nose).x(), patient->post.face_land[0].part(patient->post.lt__rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__rt_nstr).x(), patient->post.face_land[0].part(patient->post.lt__rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__up_lip).x(), patient->post.face_land[0].part(patient->post.lt__up_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__r_eye_l).x(), patient->post.face_land[0].part(patient->post.lt__r_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.lt__r_eye_r).x(), patient->post.face_land[0].part(patient->post.lt__r_eye_r).y()), pen);
			}
			else if (patient->get_eid() == "right") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__chin).x(), patient->post.face_land[0].part(patient->post.rt__chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__head_top).x(), patient->post.face_land[0].part(patient->post.rt__head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lo_lip).x(), patient->post.face_land[0].part(patient->post.rt__lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_lip).x(), patient->post.face_land[0].part(patient->post.rt__lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_nose).x(), patient->post.face_land[0].part(patient->post.rt__lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__lt_nstr).x(), patient->post.face_land[0].part(patient->post.rt__lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__l_eye_l).x(), patient->post.face_land[0].part(patient->post.rt__l_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__l_eye_r).x(), patient->post.face_land[0].part(patient->post.rt__l_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__mid_nose).x(), patient->post.face_land[0].part(patient->post.rt__mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_lip).x(), patient->post.face_land[0].part(patient->post.rt__rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_nose).x(), patient->post.face_land[0].part(patient->post.rt__rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__rt_nstr).x(), patient->post.face_land[0].part(patient->post.rt__rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->post.rt__up_lip).x(), patient->post.face_land[0].part(patient->post.rt__up_lip).y()), pen);
			}
			else if (patient->get_eid() == "none") {
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.head_top).x(), patient->post.face_land[0].part(patient->pre.head_top).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.chin).x(), patient->post.face_land[0].part(patient->pre.chin).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lo_lip).x(), patient->post.face_land[0].part(patient->pre.lo_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_lip).x(), patient->post.face_land[0].part(patient->pre.lt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_nose).x(), patient->post.face_land[0].part(patient->pre.lt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.lt_nstr).x(), patient->post.face_land[0].part(patient->pre.lt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.mid_nose).x(), patient->post.face_land[0].part(patient->pre.mid_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_lip).x(), patient->post.face_land[0].part(patient->pre.rt_lip).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_nose).x(), patient->post.face_land[0].part(patient->pre.rt_nose).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.rt_nstr).x(), patient->post.face_land[0].part(patient->pre.rt_nstr).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.l_eye_l).x(), patient->post.face_land[0].part(patient->pre.l_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.l_eye_r).x(), patient->post.face_land[0].part(patient->pre.l_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.r_eye_l).x(), patient->post.face_land[0].part(patient->pre.r_eye_l).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.r_eye_r).x(), patient->post.face_land[0].part(patient->pre.r_eye_r).y()), pen);
				post_scene->addRect(getPoint(patient->post.face_land[0].part(patient->pre.up_lip).x(), patient->post.face_land[0].part(patient->pre.up_lip).y()), pen);
			}
		}
		break;
	}
}

void Patient_Detection::clearPlots()
{
	patient->pre.face_box.clear();
	patient->pre.face_land.clear();
	patient->post.face_box.clear();
	patient->post.face_land.clear();
	patient->post.eyepatch_box.clear();
}

void Patient_Detection::loadModnn(Modnn* modnn)
{
	this->modnn = modnn;
}

void Patient_Detection::updateLabel(QLabel* label, QString append)
{
	QString prevText = label->text();
	prevText.append(append);
	label->setText(append);
}

void Patient_Detection::updateTextEdit(QTextEdit* edit, QString append)
{
	QString prevText = edit->toPlainText();
	prevText.append(append);
	edit->setText(prevText);
}

QRectF Patient_Detection::getPoint(int x, int y)
{
	return QRectF(x, y, 5, 5);
}

Patient_Detection::~Patient_Detection()
{
	delete ui;
	delete patient;
	delete pre_scene;
	delete post_scene;
	delete pr;
	delete modnn;
	delete flash;
}
void Patient_Detection::on_pushButton_recog_clicked()
{
	close();
	pr = new Patient_Recognition();
	pr->setWindowModality(Qt::WindowModal);
	pr->loadPatient(patient);
	pr->loadModnn(modnn);
	pr->show();
}
void Patient_Detection::on_graphicsView_preImage_clicked()
{
	QMessageBox::information(this, "CLIECKE", "CLIECK");
}
void Patient_Detection::on_pushButton_preELA_clicked()
{
}
void Patient_Detection::on_pushButton_postELA_clicked()
{
}
void Patient_Detection::on_pushButton_task_clicked() {
	switch (j) {
	case STEP_DETECT1:
		ui->pushButton_task->setText("STEP LANDMARK 1");
		break;
	case STEP_LANDMARK1:
		ui->pushButton_task->setText("STEP ROTATE");
		break;
	case STEP_ROTATE:
		ui->pushButton_task->setText("STEP DETECT 2");
		break;
	case STEP_DETECT2:
		ui->pushButton_task->setText("STEP LANDMARK 2");
		break;
	case STEP_LANDMARK2:
		ui->pushButton_task->setVisible(false);
		ui->pushButton_recog->setVisible(true);
		break;
	}
	doProc(this);
}