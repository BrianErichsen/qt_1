#ifndef MAINWIDGET_H
#define MAINWIDGET_H

////////////////////////////////////////////////////////////////////////
// Author: Brian Erichsen Fagundes
// Date: 04/11/2024
// MSD - UofU - Spring semester
// CS 6015 Software Engineering
//
// main widget class represents main object where UI is built on
////////////////////////////////////////////////////////////////////////

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QGroupBox>

class mainwidget : public QWidget
{
    Q_OBJECT
public:
    explicit mainwidget(QWidget *parent = nullptr);

private:
    QLabel* firstName;
    QLabel* lastName;
    QLineEdit* firstNametxt;
    QLineEdit* lastNametxt;
    QPushButton* refresh_btn;
    QPushButton* finish_btn;
    QPushButton* reset_btn;

    QTextEdit* resultTxt;
    QVBoxLayout* mainLayout;//represents vertical
    QGridLayout* horizontal;//represents horizontal

    QGroupBox* genderGroupBox;
    QHBoxLayout* genderLayout;

    QSpinBox* age_spin;
    QRadioButton* maleRadioButton;
    QRadioButton* femaleRadioButton;


private slots:
    void fill_text();//for QLineEdit resultTxt and QSpinBox age_spin
    void clear_fields();
    //not using fillSummary for consitency in writing style
    void fill_summary();//for QRadioButton male and female

signals:

};//end of class mainwidget bracket

#endif // MAINWIDGET_H
