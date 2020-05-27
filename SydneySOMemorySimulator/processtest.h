#ifndef PROCESSTEST_H
#define PROCESSTEST_H
#include <QString>
#include "pidproc.h"

class ProcessTest
{
    QString procName;
    int procTime;
    int procSize;
    static int pIdGlobal;
    int pId;
    int procCycleSinceRun = 0;

public:


    ProcessTest();
    ProcessTest(QString procName, int procTime, int procSize, int pId=0);
    QString getProcName() const;
    void setProcName(const QString &value);
    float getProcTime() const;
    void setProcTime(float value);
    int getProcSize() const;
    void setProcSize(int value);
    static int getPIdGlobal();
    static void setPIdGlobal(int value);
    int getPId() const;
    void setPId(int value);
    void procCycleSum();
    int getProcCycleSinceRun() const;
};

#endif // PROCESSTEST_H
