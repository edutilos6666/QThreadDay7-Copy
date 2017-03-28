#include "worker.h"


Worker::Worker(int max):
    max(max)
{

}

void Worker::sort()
{
qDebug() << "Worker sort id = " << QThread::currentThreadId() ;
   // if(!stopFlag) {

    QVector<int> vector ;
    vector.reserve(max);
    for(int i=0; i< max ; ++i) {
        vector << (max-i+1);
    }

  //  qDebug() << "inside sort , vector count = " << vector.count();
   for(int i=1; i< max ; ++i) {
       int j = i ;
       QThread::msleep(1);
     //  if(i%10 ==0)
       if(!stopFlag)
       emit valueChanged(i+1);
       else
           --i;
       while(j > i && vector.at(j-1) < vector.at(j)) {
            int temp = vector.at(j);
            vector.replace(j , vector.at(j-1));
            vector.replace(j-1, temp);
            --j;
       }
       //if(i%100 == 0)

   }
//    } else {

//    }
}

void Worker::stop()
{
  stopFlag = true;
}

void Worker::start()
{
  stopFlag = false ;
   // QThread::currentThread()->start();

}
