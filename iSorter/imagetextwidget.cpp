#include "imagetextwidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>

ImageTextWidget::ImageTextWidget( QWidget *parent ) : QWidget( parent ) {
    QGridLayout* layout = new QGridLayout;
//    layout->addWidget( m_imageLabel = new QLabel());
    for (int i = 0; i < array.size(); i++)
    {
        layout->addWidget( array.at(i));
    }
//    layout->addWidget( m_textLabel = new QLabel( trUtf8( "<Место для подписи>" ) ) );
    setLayout( layout );

//    m_imageLabel->setAlignment( Qt::AlignVCenter | Qt::AlignHCenter );
//    m_textLabel->setAlignment( Qt::AlignHCenter );

    resize( 500, 500 );
}

ImageTextWidget::~ImageTextWidget() {
}

void ImageTextWidget::setPixmap( const QPixmap& pix ) {
    QLabel* new_label = new QLabel;
    new_label->setPixmap( pix );
    array.push_back(new_label);
    layout()->addWidget(new_label);
}

QPixmap ImageTextWidget::getPixmap() const {
    return m_imageLabel->pixmap() ? *m_imageLabel->pixmap() : QPixmap();
}

void ImageTextWidget::setText( const QString& text ) {
    m_textLabel->setText( text );
}

QString ImageTextWidget::getText() const {
    return m_textLabel->text();
}










