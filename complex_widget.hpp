////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <cmath>

#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H


class ComplexWidget : public QWidget{
    Q_OBJECT

public:
    ComplexWidget();
    double getRealPart();
    double getImaginaryPart();
    double getMagnitude();
    double getPhase();

private: 
    void onButtonPress();

    double phase{};
    double magnitude{};

    QLineEdit* realInput;
    QLineEdit* imgInput;
    QLabel* mag_label;
    QLabel* phase_label;
    QPushButton* updateButton;
    QGridLayout* layout;
};
#endif
