#ifndef MEMORYPROC_H
#define MEMORYPROC_H
#include <QList>
#include "processtest.h"

class MemoryProc
{
    //QList totalmemory;
    //QList<ProcessTest> mainMemProc;
    int memSizeByt;
    int algorithmMode;
    QList<int> vectorMem;
    int memCycles = 0;
    bool memoryWRsinal;

public:
    QList<ProcessTest> mainMemProc;
    ProcessTest Slot = *new ProcessTest("Slot",9999,0);
    MemoryProc();

    QList<ProcessTest> getMainMemProc() const;
    void setMainMemProc(const QList<ProcessTest> &value);
    void WRMem (const ProcessTest processToAdd);
    ProcessTest RDMem (const int pos);
    void killProc (const int pos);
    int getMemSizeByt() const;
    void setMemSizeByt(int value);
    int getAlgorithmMode() const;
    void setAlgorithmMode(int value);
    void algoBestFit(const ProcessTest processToAdd);
    void vectorMemStart();
    int getMemCycles() const;
    void memCyclesSum();
    bool getMemoryWRsinal() const;
    void setMemoryWRsinal(bool value);
};

#endif // MEMORYPROC_H
