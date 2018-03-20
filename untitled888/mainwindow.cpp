#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>
#include <QDir>

ImageViewer::ImageViewer()
   : imageLabel(new QLabel)
   , scrollArea(new QScrollArea)
   , scaleFactor(1)
{
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setVisible(false);
    setCentralWidget(scrollArea);

    createActions();

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

//bool ImageViewer::loadFile(const QString &fileName)
//{
//    QImageReader reader(fileName);
//    reader.setAutoTransform(true);
//    const QImage newImage = reader.read();
//    if (newImage.isNull()) {
//        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
//                                 tr("Cannot load %1: %2")
//                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
//        return false;
//    }

//    setImage(newImage);

//    setWindowFilePath(fileName);

//    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
//        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth());
//    statusBar()->showMessage(message);
//    return true;
//}

void ImageViewer::loadRecent()
{
    QString fileName;
        QImage img;
        QDir dir;

//        dir.cd(prjDirectory);

        QLabel* lblList[25];
        for(int i = 1; i < 25; i++)
        {
            fileName = QString::number(i) + ".jpg";
            if(QFile::exists(fileName))
            {
                bool b = img.load(fileName);
                qDebug() << "PhotoTableWindow::initLabels(): file " << fileName << " is found";
                if(!b)
                {
                    QMessageBox::critical(0, tr("Error!"), tr("Cannot load image!"));
                    continue;
                }
                lblList[i]->setPixmap(QPixmap::fromImage(img.scaled(lblList[i]->width(), lblList[i]->height(), Qt::KeepAspectRatio)));
                lblList[i]->repaint();
//                isPhoto[i] = 1;
            }
        }
}

void ImageViewer::setImage(const QImage &newImage)
{
    image = newImage;
    imageLabel->setPixmap(QPixmap::fromImage(image));
    scaleFactor = 1.0;

    scrollArea->setVisible(true);
    imageLabel->adjustSize();
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void ImageViewer::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);
    while (dialog.exec() == QDialog::Accepted) {}
//    QString dir = QFileDialog::getExistingDirectory(this, tr("Choose Directory"),
//                                                        rootDir,
//                                                        QFileDialog::ShowDirsOnly
//                                                        | QFileDialog::DontResolveSymlinks);
}

#ifndef QT_NO_CLIPBOARD
static QImage clipboardImage()
{
    if (const QMimeData *mimeData = QGuiApplication::clipboard()->mimeData()) {
        if (mimeData->hasImage()) {
            const QImage image = qvariant_cast<QImage>(mimeData->imageData());
            if (!image.isNull())
                return image;
        }
    }
    return QImage();
}
#endif

void ImageViewer::createActions()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &ImageViewer::open);
    openAct->setShortcut(QKeySequence::Open);

    fileMenu->addSeparator();
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}







