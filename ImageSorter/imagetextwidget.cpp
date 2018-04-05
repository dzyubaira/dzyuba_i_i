#include "imagetextwidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

ImageTextWidget::ImageTextWidget( QWidget *parent ) : QWidget( parent ) {
    QGridLayout* layout = new QGridLayout;
    setLayout( layout );

//    QScrollArea* scrollArea = new QScrollArea;
//    layout->addWidget(scrollArea);
//    scrollArea->setBackgroundRole(QPalette::Dark);
//    scrollArea->setLayout(layout);
//    setCentralWidget(scrollArea);

//    m_imageLabel->setAlignment( Qt::AlignVCenter | Qt::AlignHCenter );
//    m_textLabel->setAlignment( Qt::AlignHCenter );
    resize( 600, 300 );
}

ImageTextWidget::~ImageTextWidget() {
}

void ImageTextWidget::setPixmap( const QPixmap& pix ) {
    QLabel* new_label = new QLabel;
    new_label->setPixmap( pix );
    array.push_back(new_label);
    layout()->addWidget(array.back());
//    new_label->setAlignment( Qt::AlignVCenter | Qt::AlignHCenter );
}

QPixmap ImageTextWidget::getPixmap(QPoint& point) const {
//    return m_imageLabel->pixmap() ? *m_imageLabel->pixmap() : QPixmap();
    for (int i = 0; i < array.size(); i++)
    {
//        QPoint x = mapToGlobal(array.at(i)->pos());
//        if (x == point)
        if(array.at(i)->rect().contains(point))
        {
            return *array.at(i)->pixmap();
            break;
        }
//        else
//        {
//            return *array.back()->pixmap();
//            break;
//        }
    }
}

//void ImageTextWidget::setText( const QString& text ) {
//    m_textLabel->setText( text );
//}

//QString ImageTextWidget::getText() const {
//    return m_textLabel->text();
//}










