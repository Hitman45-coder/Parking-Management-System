#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Parking.h"
#include <QtWidgets>

class Parking : public QMainWindow
{
    Q_OBJECT

public:
    Parking(QWidget *parent = nullptr);
    ~Parking();

private:
    Ui::ParkingClass ui;

    
    // entry and exit display
    QLabel* entryLabel;
    QLabel* exitLabel;
    QLabel* entryVehicleLabel;
    QLabel* exitVehicleLabel;

    QFrame* entryHLine;
    QFrame* exitHLine;

    QHBoxLayout* entryLabelLayout;
    QHBoxLayout* exitLabelLayout;
    QHBoxLayout* upperLayout;
    QHBoxLayout* buttomLayout;
    QHBoxLayout* parkVehicleLayout;
    QHBoxLayout* exitVehicleLayout;
    QHBoxLayout* buttonLayout;

    QPushButton* parkButton;
    QPushButton* exitButton;

    QLineEdit* entryLine;
    QLineEdit* exitLine;


    // park and queue stats
    QTableWidget* parkingStats;
    QTableWidget* queueStats;

    QStringList parkHorHeaderList;
    QStringList queueHorHeaderList;

    QGroupBox* leftBox;
    QGroupBox* rightBox;

    QVBoxLayout* leftBoxLayout;
    QVBoxLayout* rightBoxLayout;

    QSplitter* splitter;


    // top and mainLayout of display
    QVBoxLayout* entryLayout;
    QVBoxLayout* mainLayout;

    QWidget* centralWidget;


    void setupUI();


};

