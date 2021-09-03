#ifndef ANALYSIS_H
#define ANALYSIS_H
#include <QCoreApplication>
#include <QFile>

class Analysis
{
public:
    Analysis(QString pathReport, QString pathSettings);
    void fileAnalysis(QFile* file);
    void calculateDeviations(QString line);
    bool isRightFormat(QString line);

private:

};

#endif // ANALYSIS_H
