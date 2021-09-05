#include "analysis.h"
#include "report.h"
#include "counting.h"
#include <QSettings>
#include <QFile>
//#include

Analysis::Analysis(QString pathReport, QString pathIni)
{

    QSettings settings(pathIni, QSettings::IniFormat);
    settings.beginGroup( "ANALYSIS" );
    this->period = settings.value("period", 3).toUInt();
    this->lensType = settings.value("lensType").toInt();
    this->cutCount = settings.value("cutCount", 20).toUInt();
    settings.endGroup();

    this->fileReport.setFileName(pathReport);
    fileAnalysis(&fileReport);
}

void Analysis::fileAnalysis(QFile* file)
{
    bool isOpen = file->open(QIODevice::ReadOnly | QIODevice::Text);
    if (isOpen) {
        Counting counting;
        while (!file->atEnd()) {
            QByteArray line = file->readLine();
            if (isRightFormat(line)) {
                //counting.calculateMid(line);
            }
        }
    }
        qFatal("the file cannot be opened");


    //Report report(counting.getMid);
    //report.write;
}



bool Analysis::isRightFormat(QString line)
{

}
