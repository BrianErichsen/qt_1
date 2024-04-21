#include <QApplication>
#include "mainwidget.h"


int main(int argc, char **argv) {
    QApplication app (argc, argv);

    mainwidget *main = new mainwidget();
    //creates instance of mainwidget on the heap hence using new and ptrs
    main->show();

    return app.exec();
}
