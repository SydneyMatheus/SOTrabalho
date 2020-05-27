#ifndef PIDPROC_H
#define PIDPROC_H


class PIDProc
{
    int pId = 0;
public:
    PIDProc();
    int getPId() const;
    void setPId(int &value);
    void pIdSum();
};

#endif // PIDPROC_H
