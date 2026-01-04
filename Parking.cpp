#include "Parking.h"

Parking::Parking(QWidget* parent) : QMainWindow(parent)
{
	setupUI();
}

Parking::~Parking()
{
	//Clean UI after Parking object is destroyed
}

void Parking::setupUI() {


	parkHorHeaderList.append({ "Slot", "Vehicle" });
	parkingStats = new QTableWidget();
	parkingStats->setColumnCount(parkHorHeaderList.length());
	parkingStats->setRowCount(5);
	parkingStats->setHorizontalHeaderLabels(parkHorHeaderList);
	parkingStats->horizontalHeader()->setVisible(true);
	parkingStats->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	parkingStats->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


	
	queueHorHeaderList.append({ "Position", "Vehicle Number" });
	queueStats = new QTableWidget();
	queueStats->setColumnCount(queueHorHeaderList.length());
	queueStats->setRowCount(5);
	queueStats->setHorizontalHeaderLabels(queueHorHeaderList);
	queueStats->horizontalHeader()->setVisible(true);
	queueStats->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	queueStats->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	leftBox = new QGroupBox("Parking lot Status:");
	QVBoxLayout* leftBoxLayout = new QVBoxLayout(leftBox);
	leftBoxLayout->setContentsMargins(8, 8, 8, 8);
	leftBoxLayout->addWidget(parkingStats);

	rightBox = new QGroupBox("Waiting Queue:");
	QVBoxLayout* rightBoxLayout = new QVBoxLayout(rightBox);
	rightBoxLayout->setContentsMargins(8, 8, 8, 8);
	rightBoxLayout->addWidget(queueStats);

	splitter = new QSplitter(Qt::Horizontal);
	splitter->addWidget(leftBox);
	splitter->addWidget(rightBox);
	splitter->setHandleWidth(6);
	splitter->setContentsMargins(0, 0, 0, 0);


	//Vehicle Entry and Exit 
	entryLabel = new QLabel("Vehicle Entry:");
	exitLabel = new QLabel("Vehicle Exit:");

	entryHLine = new QFrame();
	entryHLine->setFrameShape(QFrame::HLine);
	entryHLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

	exitHLine = new QFrame();
	exitHLine->setFrameShape(QFrame::HLine);
	exitHLine->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	exitHLine->setContentsMargins(0, 0, 0, 0);

	entryLabelLayout = new QHBoxLayout();
	entryLabelLayout->addWidget(entryLabel);
	entryLabelLayout->addWidget(entryHLine, 1, Qt::AlignBottom);
	entryLabelLayout->setContentsMargins(0, 0, 50, 0);

	exitLabelLayout = new QHBoxLayout();
	exitLabelLayout->addWidget(exitLabel);
	exitLabelLayout->addWidget(exitHLine, 1, Qt::AlignBottom);
	exitLabelLayout->setContentsMargins(0, 0, 50, 0);

	upperLayout = new QHBoxLayout();
	upperLayout->addLayout(entryLabelLayout);
	upperLayout->addLayout(exitVehicleLayout);

	entryVehicleLabel = new QLabel("Vehicle Number:");
	exitVehicleLabel = new QLabel("Vehicle Number:");

	entryLine = new QLineEdit();
	exitLine = new QLineEdit();

	parkVehicleLayout = new QHBoxLayout();
	parkVehicleLayout->addWidget(entryVehicleLabel);
	parkVehicleLayout->addWidget(entryLine);

	exitVehicleLayout = new QHBoxLayout();
	exitVehicleLayout->addWidget(exitVehicleLabel);
	exitVehicleLayout->addWidget(exitLine);

	buttomLayout = new QHBoxLayout();
	buttomLayout->addLayout(parkVehicleLayout);
	buttomLayout->addLayout(exitVehicleLayout);

	parkButton = new QPushButton("Park Vehicle");
	exitButton = new QPushButton("Exit Vehicle");

	buttomLayout = new QHBoxLayout();
	buttomLayout->addWidget(parkButton);
	buttomLayout->addWidget(exitButton);

	QVBoxLayout* entryLayout = new QVBoxLayout();
	entryLayout->addLayout(upperLayout);
	entryLayout->addLayout(buttomLayout);
	entryLayout->addLayout(buttomLayout);

	mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0, 0, 0, 0);
	mainLayout->addLayout(entryLabelLayout);
	mainLayout->addWidget(splitter);
	mainLayout->setStretch(1, 1);

	centralWidget = new QWidget(this);
	centralWidget->setLayout(mainLayout);
	setCentralWidget(centralWidget);

	resize(1000, 650);
	setWindowTitle("Parking Management System");
	setWindowIcon(QIcon("C:\\Users\\achar\\Pictures\\bob.png"));
}