////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//

#include <QApplication>
#include "complex_widget.hpp"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ComplexWidget window;
    window.resize(400, 300);
    window.show();
    return app.exec();

}
