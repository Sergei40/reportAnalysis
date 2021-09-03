#include "analysis.h"
#include "report.h"
#include "counting.h"
#include <QSettings>
#include <QFileInfo>
//#include

Analysis::Analysis(QString pathReport, QString pathIni)
{
    QFileInfo fileIni(pathIni);
    QSettings settings(pathIni, QSettings::IniFormat);
    //period = settings.value("period").toInt();

    QFile file(path);
    fileAnalysis(&file);
}

void Analysis::fileAnalysis(QFile *file)
{
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        qFatal("the file cannot be opened");

    Counting counting;
    while (!file->atEnd()) {
        QByteArray line = file->readLine();
        if (isRightFormat(line)) {
            //counting.calculateMid(line);
        }
    }
    //Report report(counting.getMid);
    //report.write;
}



bool Analysis::isRightFormat(QString line)
{

}
