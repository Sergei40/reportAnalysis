#include <QCoreApplication>
#include <iostream>
#include <QFileInfo>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "analysis.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 3) qFatal("enter the path to the file");

    QFileInfo report(argv[1]);
    QFileInfo settings(argv[2]);
    bool isTxt = report.completeSuffix() == "txt";
    bool isIni = settings.completeSuffix() == "ini";
    if (report.exists() && report.isFile() && settings.exists() && settings.isFile()) {
        if (isTxt && isIni)
            Analysis analysis(argv[1], argv[2]);
        else
            Analysis analysis(argv[2], argv[1]);
    }
    else
        qFatal("file does not exist");



    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl << argv[1] << std::endl << argv[2] << std::endl;

    return a.exec();
}
