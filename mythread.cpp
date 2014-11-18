#include "mythread.h"

MyThread::MyThread()
{
}

void MyThread::run()
{
    while(1){
        if((QTime::fromString("12:00:00","hh:mm:ss").operator <(QTime::currentTime()))&&(QTime::fromString("23:59:59.999","hh:mm:ss.zzz").operator >(QTime::currentTime()))){
           emit trigger();
        }
        emit temp();
        sleep(300);
    }
}
