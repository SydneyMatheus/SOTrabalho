#include "processtest.h"
int ProcessTest::pIdGlobal =-1;

QString ProcessTest::getProcName() const
{
    return procName;
}

void ProcessTest::setProcName(const QString &value)
{
    procName = value;
}

float ProcessTest::getProcTime() const
{
    return procTime;
}

void ProcessTest::setProcTime(float value)
{
    procTime = value;
}

int ProcessTest::getProcSize() const
{
    return procSize;
}

void ProcessTest::setProcSize(int value)
{
    procSize = value;
}

int ProcessTest::getPIdGlobal()
{
    return pIdGlobal;
}

void ProcessTest::setPIdGlobal(int value)
{
    pIdGlobal = value;
}

int ProcessTest::getPId() const
{
    return pId;
}

void ProcessTest::setPId(int value)
{
    pId = value;
}

void ProcessTest::procCycleSum()
{
    procCycleSinceRun++;
}

int ProcessTest::getProcCycleSinceRun() const
{
    return procCycleSinceRun;
}

ProcessTest::ProcessTest()
{

}

ProcessTest::ProcessTest(QString procName, int procTime, int procSize, int pId)
    :procName(procName), procTime(procTime), procSize(procSize)
{
    pIdGlobal++;
    setPId(pIdGlobal);
}
