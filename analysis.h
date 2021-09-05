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
    unsigned int period;   //время анализа (в днях) от 1 до 365
    int lensType;          //тип линзы для анализа
    unsigned int cutCount; //количество подрезок для статистического анализа
    QFile fileReport;
};

#endif // ANALYSIS_H
