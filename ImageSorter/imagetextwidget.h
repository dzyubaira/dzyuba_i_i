#ifndef IMAGETEXTWIDGET_H
#define IMAGETEXTWIDGET_H

#include <QWidget>
#include <QVector>

class QLabel;

class ImageTextWidget : public QWidget {
    Q_OBJECT

public:
    ImageTextWidget( QWidget *parent = 0 );
    ~ImageTextWidget();

    void setPixmap( const QPixmap& pix );
    QPixmap getPixmap(QPoint& point) const;

    void setText( const QString& text );
    QString getText() const;

    QList<QLabel*> array;

private:
//    QList<QLabel*> array;
    QLabel* m_imageLabel;
    QLabel* m_textLabel;
};

#endif // IMAGETEXTWIDGET_H
























