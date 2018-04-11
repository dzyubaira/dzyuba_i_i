#include "dropwidget.h"

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
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
    path = filePath;
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
    if( event->mimeData()->hasImage() ) {
        event->acceptProposedAction();
    }
}

void DropWidget::dropEvent( QDropEvent* event ) {
    QPixmap pix = QPixmap::fromImage( event->mimeData()->imageData().value< QImage >() );
    setPixmap( pix );
    QString str = path;
    path.append("\\");
    int name = qrand() % 1000;
    QString str1 = QString::number(name);
    name = 0;
    str1.append(".jpeg");
    path.append(str1);
    pix.save(path);
    QMessageBox msg;
    msg.setText("Файл " + str1 + " помещён в папку " + str);
    msg.exec();
    event->acceptProposedAction();
}




























