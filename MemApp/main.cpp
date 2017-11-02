#include "../view/MemApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MemApp w;
	w.show();
	return a.exec();
}
