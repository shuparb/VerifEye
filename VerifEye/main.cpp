#include "VerifEye.h"
#include <direct.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	_mkdir("./data-db");
	QApplication a(argc, argv);
	VerifEye w;
	w.show();
	return a.exec();
}
