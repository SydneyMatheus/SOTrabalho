#include "pidproc.h"

int PIDProc::getPId() const
{
    return pId;
}

void PIDProc::setPId(int &value)
{
    pId = value;
}

void PIDProc::pIdSum()
{
    pId++;
}

PIDProc::PIDProc()
{

}
