#include "dragwidget.h"
#include "dropwidget.h"
#include <QApplication>

int main( int argc, char* argv[] ) {
    QApplication a( argc, argv );

    DragWidget dragWgt;
    dragWgt.show();

    DropWidget dropWgt;
    dropWgt.show();

    DropWidget dropWgt1;
    dropWgt1.show();

    return a.exec();
}
