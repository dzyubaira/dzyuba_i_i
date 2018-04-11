#include "imagetextwidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

ImageTextWidget::ImageTextWidget( QWidget *parent ) : QWidget( parent ) {
    QGridLayout* layout = new QGridLayout;
    setLayout( layout );
    resize( 600, 300 );
}

ImageTextWidget::~ImageTextWidget() {
}

void ImageTextWidget::setPixmap( const QPixmap& pix ) {
    QLabel* new_label = new QLabel;
    new_label->setPixmap( pix );
    array.push_back(new_label);
    layout()->addWidget(array.back());
}

QPixmap ImageTextWidget::getPixmap(QPoint& point) const {
    for (int i = 0; i < array.size(); i++)
    {
        if(array.at(i)->rect().contains(point))
        {
            return *array.at(i)->pixmap();
            break;
        }
    }
}










