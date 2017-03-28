#include "dialogsort.h"
#include "ui_dialogsort.h"


DialogSort::DialogSort(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DialogSort)
{
    ui->setupUi(this);
    registerEvents();
    stopCalled = false ;
    mutex = new QMutex();
}

DialogSort::~DialogSort()
{
    delete ui;
}

void DialogSort::registerEvents()
{
    int max = 10000;
    ui->pPercentage->setMaximum(max);
    ui->sbCount->setValue(max);
   QThread *thread = new QThread();
   Worker *w =new Worker(max);
   w->moveToThread(thread);

   QObject::connect(thread , SIGNAL(started()), w , SLOT(sort()));
   QObject::connect(w, SIGNAL(valueChanged(int)), this, SLOT(updateWindow(int)));
 //  QObject::connect(ui->btnStart, SIGNAL(clicked(bool)), w, SLOT(start()));
   QObject::connect(ui->btnStart, &QPushButton::clicked, [thread, w, this](){
       qDebug() << "inside btnStart clicked";
       w->start();

       if(ui->btnClose->text() == "Stop") {

       } else if(ui->btnClose->text() == "Close") {
         thread->start();
       }
   });

   QObject::connect(thread, SIGNAL(finished()), w , SLOT(deleteLater()));
   QObject::connect(thread , SIGNAL(finished()), this, SLOT(close()));
   QObject::connect(ui->sbCount, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),  [=](int newValue) {
     ui->pPercentage->setMaximum(newValue);
     w->max = newValue;
   });
   QObject::connect(ui->btnClose, &QPushButton::clicked,[this, w, thread](){
      if(ui->btnClose->text() == "Stop") {

          mutex->lock();
          w->stop();
        //  QThread::msleep(3);


          stopCalled = true ;
            ui->btnStart->setEnabled(true);
          mutex->unlock();
       //   ui->btnStart->setEnabled(true);
          qDebug() << "inside Stop";
      } else if(ui->btnClose->text() == "Close") {
          stopCalled = false;
           thread->quit();
      }
   });

   qDebug() << "DialogSort id = " << QThread::currentThreadId() ;
   //QObject::connect(ui->btnClose, SIGNAL(clicked(bool)), w , SLOT(stop()));
}

void DialogSort::updateWindow(int newValue)
{

      ui->sbCount->setEnabled(false);
  qDebug() << "inside updateWindow" ;
   ui->pPercentage->setValue(newValue);
   int max = ui->pPercentage->maximum();

   if(newValue < max) {
       ui->btnClose->setText("Stop");
        ui->btnStart->setEnabled(false);
   } else if(newValue == max) {
      ui->btnStart->setEnabled(true);
      ui->btnClose->setText("Close");
   }

     if(newValue < max) {
   mutex->lock();
    ui->btnStart->setEnabled(stopCalled);
    stopCalled = false ;
    mutex->unlock();
     }
}
