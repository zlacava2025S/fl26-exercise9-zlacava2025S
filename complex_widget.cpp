////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"

ComplexWidget::ComplexWidget() {
    
    setWindowTitle("Complex Number Calculator");

    realInput = new QLineEdit(this);
    imgInput = new QLineEdit(this);

    mag_label = new QLabel("0", this);
    phase_label = new QLabel("0", this);

    updateButton = new QPushButton("Update", this);

    layout = new QGridLayout(this);

    layout->addWidget(new QLabel("Real part: "), 0, 0);
    layout->addWidget(realInput, 0, 1);

    layout->addWidget(new QLabel("Imaginary part: "), 0, 2);
    layout->addWidget(imgInput, 0, 3);

    layout->addWidget(new QLabel("Magnitude: "), 1, 0);
    layout->addWidget(mag_label, 1, 1);

    layout->addWidget(new QLabel("Phase: "), 1, 2);
    layout->addWidget(phase_label, 1, 3);

    layout->addWidget(updateButton, 2, 3);

    setLayout(layout);

    connect(updateButton, &QPushButton::clicked, this, &ComplexWidget::onButtonPress);

}

double ComplexWidget::getRealPart() {
    return realInput->text().toDouble();
}
double ComplexWidget::getImaginaryPart() {
    return imgInput->text().toDouble();
}
double ComplexWidget::getMagnitude() {
    return std::sqrt(std::pow(getRealPart(), 2) + std::pow(getImaginaryPart(), 2));
}
double ComplexWidget::getPhase() {
    return std::atan2(getImaginaryPart(), getRealPart()) * 180.0 / 3.14159;
}

void ComplexWidget::onButtonPress() {
    mag_label->setText(QString::number(getMagnitude(), 'f', 2));
    phase_label->setText(QString::number(getPhase(), 'f', 2));
}



