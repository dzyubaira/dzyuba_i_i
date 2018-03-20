#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class ImageSorter : public QMainWindow
{
    Q_OBJECT

public:
    ImageSorter();
    bool loadFile(const QString &);
    void loadRecent();

private slots:
    void open();

private:
    void createActions();
    void createMenus();
    void setImage(const QImage &newImage);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor;
};

#endif










