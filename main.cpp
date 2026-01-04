#include "Parking.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Parking* parkingSystem = new Parking();
	parkingSystem->show();

	return app.exec();
}