#ifndef DROPWIDGET_H
#define DROPWIDGET_H

#include <imagetextwidget.h>
#include <QDir>

class DropWidget : public ImageTextWidget {
    Q_OBJECT
public:
    explicit DropWidget( QWidget* parent = 0 );

private slots:
    void onLoadImage();

protected:
    void dragEnterEvent( QDragEnterEvent* event );
    void dropEvent( QDropEvent* event );

private:
    QDir* direct;
};

#endif // DROPWIDGET_H







