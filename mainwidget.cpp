#include "mainwidget.h"
////////////////////////////////////////////////////////////////////////
// Author: Brian Erichsen Fagundes
// Date: 04/11/2024
// MSD - UofU - Spring semester
// CS 6015 Software Engineering
//
// main widget class implementation
////////////////////////////////////////////////////////////////////////
#include <QGroupBox>
#include <QSpacerItem>
//constructor for creation of mainwidget object
mainwidget::mainwidget(QWidget* parent) : QWidget{parent}
{
    firstName = new QLabel("First Name:");
    lastName = new QLabel("Last Name:");

    firstNametxt = new QLineEdit();//name text for users to type their input
    lastNametxt = new QLineEdit;

    //I think that should make more sense to use refresh to set all fields to nothing and
    //use finish btn to send summary data to result txt box
    refresh_btn = new QPushButton("Refresh");
    reset_btn = new QPushButton("Reset");
    finish_btn = new QPushButton("Finish");
    resultTxt = new QTextEdit;
    //represents the vertical
    mainLayout = new QVBoxLayout;
    //represents the horizontal / grid part
    horizontal = new QGridLayout;

    age_spin = new QSpinBox;//represets the widget that spin different ages
    maleRadioButton = new QRadioButton("Male");//male option
    femaleRadioButton = new QRadioButton("Female");//female option
    //sets the prefix of spinner
    age_spin->setPrefix("Age: ");
    age_spin->setMinimum(0);//sets min range to max range
    //hard to find people age > than 150
    age_spin->setMaximum(150);

    //creates Qgroup so that we may embed gender male / female fields
    genderGroupBox = new QGroupBox;
    genderLayout = new QHBoxLayout;
    QLabel* gender = new QLabel("Gender");
    //adds proper widgets to gender layout
    genderLayout->addWidget(gender, 0);
    genderLayout->addWidget(maleRadioButton, 1);
    genderLayout->addWidget(femaleRadioButton);
    //actually sets layout to exist
    genderGroupBox->setLayout(genderLayout);
    //spacer so that we have a gap between first name field and age spin box
    QSpacerItem* spacer = new QSpacerItem(20, 40, QSizePolicy::Maximum, QSizePolicy::Expanding);


    //sets all horizontal plane
    //row is horizontal and collumn vertical
    horizontal->addWidget(firstName, 0, 0);
    horizontal->addItem(spacer, 0, 2);
    horizontal->addWidget(age_spin, 0, 3);
    horizontal->addWidget(firstNametxt, 0, 1);
    horizontal->addWidget(lastName, 1, 0);
    horizontal->addWidget(lastNametxt, 1, 1);
    horizontal->addWidget(genderGroupBox, 2, 1);
    horizontal->addWidget(refresh_btn, 3, 0);
    mainLayout->addItem(horizontal);//adds horizontal to mainLayout

    mainLayout->addWidget(resultTxt, 1);
    mainLayout->addWidget(reset_btn, 2);
    mainLayout->addWidget(finish_btn, 3);

    setLayout(mainLayout);

    //sets the refresh btn to fill out summary report
    connect(refresh_btn, &QPushButton::clicked, this, &mainwidget::fill_summary);
    //sets the reset btn to clear fields
    connect(reset_btn, &QPushButton::clicked, this, &mainwidget::clear_fields);
    //sets the finish btn to fill out first and last name info into result box
    connect(finish_btn, &QPushButton::clicked, this, &mainwidget::fill_text);
}

void mainwidget::fill_text() {
    QString str;
    str = firstNametxt->text() + " " + lastNametxt->text();
    resultTxt->setText(str);
}

void mainwidget::clear_fields() {
    firstNametxt->clear();
    lastNametxt->clear();
    resultTxt->clear();
    age_spin->clear();
    //creates list that holds all radio type buttons and iterates over list
    QList<QRadioButton*> buttons = genderGroupBox->findChildren<QRadioButton*>();
    for (QRadioButton* button : buttons) {
        button->setAutoExclusive(false);
        button->setChecked(false);
        button->setAutoExclusive(true);
    }
}

void mainwidget::fill_summary() {
    //creates string instance based on given format
    QString summary = "First Name: " + firstNametxt->text() + "\n" +
                      "Last Name: " + lastNametxt->text() + "\n" +
                      "Age: " + QString::number(age_spin->value()) + "\n";
    //checks which of the 2 options are chosen
    if (maleRadioButton->isChecked()) {
        summary += "Gender: Male\n";
    } else if (femaleRadioButton->isChecked()) {
        summary += "Gender: Female\n";
    }
    resultTxt->setText(summary);
}
