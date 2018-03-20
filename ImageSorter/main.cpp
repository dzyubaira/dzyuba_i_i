#include <QApplication>
#include <QCommandLineParser>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(ImageSorter::tr("Image Sorter"));
    QCommandLineParser commandLineParser;
    commandLineParser.addPositionalArgument(ImageSorter::tr("[file]"), ImageSorter::tr("Image file to open."));
    commandLineParser.process(QCoreApplication::arguments());
    ImageSorter imageSorter;
    if (!commandLineParser.positionalArguments().isEmpty()
        //&& !imageViewer.loadRecent(commandLineParser.positionalArguments().front())
            ) {
        return -1;
    }
    imageSorter.show();
    return app.exec();
}
