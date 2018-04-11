#include "pcommunication.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
#include "app_datapackage.h"
#include "definefile.h"
extern int selfNodeID;


PCommunication* PCommunication::m_instance = new PCommunication();

PCommunication::PCommunication()
{
    IsListen = false;
    p_UserMainWindow = NULL;
}

static bool IsStopListen = false;

void* package_read(void* args)
{
//    QTextStream cin(stdin, QIODevice::ReadOnly);
//    QTextStream cout(stdout, QIODevice::WriteOnly);
//    using namespace std;
//    cout<<"start package_read "<<endl;
////    while(1){
//    struct App_DataPackage recvBuff, *p_recvBuff;
//    p_recvBuff = &recvBuff;
//    char recvStr[sizeof(recvBuff)];
//    bzero(&recvBuff, sizeof(recvBuff));
//    bzero(&recvStr, sizeof(recvStr));
//    cout<<"ready to read socket"<<endl;
//    PCommunication::getInstance()->p_UserMainWindow->readData(recvStr, sizeof(recvStr));
//    cout<<"read socket finish"<<endl;
//    memcpy(&recvBuff, recvStr, sizeof(recvStr));
//    cout<<"recvBuff.data :"<<recvBuff.data_buffer<<endl;
//    pthread_t tid_handler;
//    cout<<"begin package_handler"<<endl;
//    int iRet = pthread_create(&tid_handler, NULL, package_handler, p_recvBuff);
//    /*参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数*/
//    if (iRet){
//        qCritical("handler pthread_create error. iRet=%d, package_type=%d.",iRet,p_recvBuff->Package_type);
//    }

////    }
//    cout<<"package_read finish"<<endl;
}

//void PCommunication::handleRoutTable(App_DataPackage table)
//{
//    QTextStream cin(stdin, QIODevice::ReadOnly);
//    QTextStream cout(stdout, QIODevice::WriteOnly);
//    using namespace std;

//    int tableInt[10];
//    memcpy(tableInt, table.data_buffer, sizeof(tableInt));
//    cout<<"tableInt = ";
//    for(int i = 0 ;i<10;i++){
//        cout<<tableInt[i];
//    }
//    cout<<endl;
//}



//void* package_handler(void *args)
//{
//    struct App_DataPackage *p_package_recv = (struct App_DataPackage *)args;
//    switch(p_package_recv->Package_type)
//    {
//    case 1:
//        PCommunication::getInstance()->p_UserMainWindow->DosendDatatoMainWindow(p_package_recv);
//        break;
//    case 2:
//        PCommunication::getInstance()->p_UserMainWindow->SendSelfNodeID(p_package_recv);
//        break;
//    case 3:
//        PCommunication::getInstance()->p_UserMainWindow->AddNewNode(p_package_recv->data_buffer);
//        PCommunication::getInstance()->p_UserMainWindow->handleRoutTable(p_package_recv->data_buffer);
//        break;
//    case 4:
//        PCommunication::getInstance()->p_UserMainWindow->message_recvhandler(p_package_recv);
//        break;
//    case 5:
//        PCommunication::getInstance()->p_UserMainWindow->fig_recvhandler(p_package_recv);
//        break;
//    default:
//        break;
//    }
//    free(p_package_recv);
//}


bool PCommunication::start_listen()
{
    if(!IsListen)
    {
        pthread_t tid;
        int iRet = pthread_create(&tid, NULL, package_read, NULL);
        /*参数依次是：创建的线程id，线程参数，调用函数名，传入的函数参数*/
        if (iRet){
            qCritical("pthread_create error. iRet=%d",iRet);
            return false;
        }
        IsListen = true;
    }
    return true;
}

bool PCommunication::stop_listen()
{
    IsStopListen = true;
    IsListen = false;
    return true;
}

bool PCommunication::package_write(char *p_buffer, int datalength, int Package_type, int DestinationID, int SourceID)
{
    /*创建共享内存*/
        int shmid;
        shmid = shmget((key_t)SHM_KEY_SEND, sizeof(struct App_DataPackage), 0666 | IPC_CREAT);
        if (shmid == -1)
        {
          qCritical("shmget failed.");
          return false;
        }

        void *shared_memory = NULL;
        shared_memory = shmat(shmid, NULL, 0);
        if (shared_memory == (void *)-1)
        {
          qCritical("shmat failed.");
          return false;
        }
        struct App_DataPackage *p_package_send;
        p_package_send = (struct App_DataPackage *)shared_memory;

        int semid;
        semid = semget(SEM_KEY_SEND,2,0666);
        struct sembuf sembuf1;
        union semun;
        sembuf1.sem_num=1;/*这里指向第2个信号量（sem_num=1）*/
        sembuf1.sem_op=-1;/*操作是-1，因为第2个信号量初始值为1，所以下面不会阻塞*/
        sembuf1.sem_flg=SEM_UNDO;
        semop(semid,&sembuf1,1);/*继续*/
        //todo
        for(int i=0;i<datalength;i++)
            p_package_send->data_buffer[i] = p_buffer[i];
        p_package_send->data_size = datalength;
        p_package_send->Package_type = Package_type;
        p_package_send->DestinationID = DestinationID;
        p_package_send->SourceID = SourceID;
        //delete[] p_buffer;
        p_buffer = NULL;
        sembuf1.sem_num=0;/*这里指向第一个信号量*/
        sembuf1.sem_op=1;/*操作加1*/
        sembuf1.sem_flg=SEM_UNDO;
        semop(semid,&sembuf1,1);/*执行+1后，我们发现，reader阻塞正是由于第一个信号量为0，无法减一，而现在writer先为其加1，那reader就绪！writer继续循环，发现第二个信号量已经减为0，则阻塞了，我们回到reader*/

        /*关闭共享内存*/
        if (shmdt(shared_memory) == -1)
        {
            qCritical("shmdt failed.");
            return false;
        }
        return true;
}

void PCommunication::Build_UserMainWindow()
{
    if(p_UserMainWindow==NULL)
        p_UserMainWindow = new UserMainWindow();
}
