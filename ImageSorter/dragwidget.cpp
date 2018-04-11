#include "dragwidget.h"

#include <QDebug>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPushButton>
#include <QBoxLayout>
#include <QFileDialog>
#include <QFileInfo>
#include <QPainter>
#include <QApplication>

DragWidget::DragWidget( QWidget* parent ) : ImageTextWidget( parent ) {
    QPushButton* btn = new QPushButton( trUtf8( "Загрузить папку" ) );
    layout()->addWidget( btn );
    connect( btn, SIGNAL( clicked( bool ) ), SLOT( onLoadImage() ) );
}

void DragWidget::mousePressEvent( QMouseEvent* event ) {
    m_dragStart = event->pos();
}

void DragWidget::mouseMoveEvent( QMouseEvent *event ) {
    if(
            ( event->buttons() & Qt::LeftButton ) &&
            !getPixmap(event->pos()).isNull() &&
            QApplication::startDragDistance() <= ( event->pos() - m_dragStart ).manhattanLength()
    ) {
        QPoint a = event->pos();
        QDrag* drag = new QDrag( this );
        QMimeData* mimeData = new QMimeData;
        mimeData->setImageData( getPixmap(a).toImage() );
        drag->setMimeData( mimeData );
        drag->setPixmap( getPixmap(a) );

        Qt::DropAction result = drag->exec( Qt::MoveAction );
        if( result == Qt::MoveAction ) {
            setPixmap( QPixmap() );
        }
    }
}

void DragWidget::onLoadImage() {
    QString filePath = QFileDialog::getExistingDirectory(this,
                                                         QString::fromUtf8("Выбрать папку"),
                                                         QDir::currentPath(),
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    if( !filePath.isEmpty() ) {
        QDir dir = filePath;
        QFileInfoList list = dir.entryInfoList();
        for(int i = 0; i < list.size(); i++)
        {
            QFileInfo fileInfo = list.at(i);
            QString fileName = fileInfo.absoluteFilePath();
            QPixmap pix (fileName);
            setPixmap( pix );
        }
    }
}











