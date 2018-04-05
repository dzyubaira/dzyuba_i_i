#include "dropwidget.h"

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include <QFileInfo>
#include <QPainter>
#include <QApplication>

DropWidget::DropWidget( QWidget* parent ) : ImageTextWidget( parent ) {
    setAcceptDrops( true );
    QPushButton* btn = new QPushButton( trUtf8( "Загрузить папку" ) );
    layout()->addWidget( btn );
    connect( btn, SIGNAL( clicked( bool ) ), SLOT( onLoadImage() ) );
}

void DropWidget::onLoadImage() {
    QString filePath = QFileDialog::getExistingDirectory(this,
                                                         QString::fromUtf8("Выбрать папку"),
                                                         QDir::currentPath(),
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    if( !filePath.isEmpty() ) {
        QDir direct = filePath;
        QFileInfoList list = direct.entryInfoList();
        for(int i = 0; i < list.size(); i++)
        {
            QFileInfo fileInfo = list.at(i);
            QString fileName = fileInfo.absoluteFilePath();
            QPixmap pix (fileName);
            setPixmap( pix );
        }
    }
}


void DropWidget::dragEnterEvent( QDragEnterEvent* event ) {
    qDebug() << event->mimeData()->formats();
    if( event->mimeData()->hasImage() ) {
        event->acceptProposedAction();
    }
}

void DropWidget::dropEvent( QDropEvent* event ) {
    QPixmap pix = QPixmap::fromImage( event->mimeData()->imageData().value< QImage >() );
    setPixmap( pix );
//    QString str = direct->filePath()
//    pix.save("dl", "jpg");
//    QImage img = pix.toImage();
//    QString dir = direct;
    QString str = "C:\\Users\\User\\Desktop\\build-DragDropDemo-Desktop_Qt_5_6_3_MSVC2015_64bit-Debug\\Новая папка";
    str.append("\\123.jpg");
    pix.save(str);
    event->acceptProposedAction();
}




























