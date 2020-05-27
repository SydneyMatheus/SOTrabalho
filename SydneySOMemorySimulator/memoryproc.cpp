#include "memoryproc.h"
#include <QDebug>

QList<ProcessTest> MemoryProc::getMainMemProc() const
{
    return mainMemProc;
}

void MemoryProc::setMainMemProc(const QList<ProcessTest> &value)
{
    mainMemProc = value;
}

void MemoryProc::WRMem(const ProcessTest processToAdd)
{

    if(memSizeByt >= processToAdd.getProcSize()){
        algoBestFit(processToAdd);
    }
    else
        qDebug()<<"Não foi possível adicionar na memória (espaço insuficiente)";
}

ProcessTest MemoryProc::RDMem(const int pos)
{
    return mainMemProc.at(pos);
}

void MemoryProc::killProc(const int pos)
{

    memSizeByt = mainMemProc.at(pos).getProcSize() + memSizeByt;
    int tam = mainMemProc.at(pos).getProcSize();

    for(int i=pos; i<=(tam+pos-1);i++)
    {
        qDebug()<<"Vector["<<i<<"] "<<vectorMem[i];
        qDebug()<<"memoryvec["<<i<<"]"<<mainMemProc[i].getPId();
        if((vectorMem[i] == mainMemProc[i].getPId()) && vectorMem[i]!=0)
        {
            vectorMem.replace(i,0);
            mainMemProc.replace(i,Slot);
        }
    }

    for(int i = 0; i<mainMemProc.size(); i++){

        qDebug()<<"ESSE"<<mainMemProc.at(i).getPId();
    }
    qDebug()<<"termino";

}

int MemoryProc::getMemSizeByt() const
{
    return memSizeByt;
}

void MemoryProc::setMemSizeByt(int value)
{
    memSizeByt = value;
}

int MemoryProc::getAlgorithmMode() const
{
    return algorithmMode;
}

void MemoryProc::setAlgorithmMode(int value)
{
    algorithmMode = value;
}

void MemoryProc::algoBestFit(const ProcessTest processToAdd)
{
    bool interval = 0, memoryWR = 0;
    int finishWR = 0;

    for(int i = 0; i<vectorMem.size(); i++)
    {
        if(vectorMem.at(i)==0 && memoryWR ==0)
        {
            for(int j = i; (j-i)<processToAdd.getProcSize();j++)
            {
                if(vectorMem.at(j) != 0)
                {
                    interval = 1;
                }
                else if(interval != 1)
                {
                    memoryWR = 1;
                    memoryWRsinal = 1;
                }
            }
        }

        if(interval == 0 && memoryWR ==1)
        {
            if(finishWR < processToAdd.getProcSize())
            {
                finishWR++;
                vectorMem.replace(i,processToAdd.getPId());
                mainMemProc.replace(i,processToAdd);/////////////////////////////
            }
        }
    }

    for(int i = 0; i<vectorMem.size(); i++){
        qDebug()<<vectorMem.at(i);
    }
    qDebug()<<"termino";
    memSizeByt = memSizeByt - processToAdd.getProcSize();
}

void MemoryProc::vectorMemStart()
{
    memoryWRsinal = 0;
    for(int i =0; i<memSizeByt; i++){
        vectorMem.append(0);
        mainMemProc.append(Slot);
    }
    qDebug()<<"PID Global: "<<Slot.getPIdGlobal();

}

int MemoryProc::getMemCycles() const
{
    return memCycles;
}

void MemoryProc::memCyclesSum()
{
    memCycles++;
    memoryWRsinal = 0;
    //qDebug()<<"TYamanho da Mem: "<<mainMemProc.size();
    for(int i=0; i<mainMemProc.size(); i++)
    {
        if(i == 0)
            mainMemProc[i].procCycleSum();

        if(vectorMem.at(i)!=0)
        {
            if(i>0 && (mainMemProc.at(i-1).getPId()!=mainMemProc.at(i).getPId())){
                mainMemProc[i].procCycleSum();
            }
        }
        if(mainMemProc.at(i).getProcCycleSinceRun()==mainMemProc.at(i).getProcTime())
        {
           killProc(i);
        }
    }
}

bool MemoryProc::getMemoryWRsinal() const
{
    return memoryWRsinal;
}

void MemoryProc::setMemoryWRsinal(bool value)
{
    memoryWRsinal = value;
}

MemoryProc::MemoryProc()
{

}
