/* threadTest.c */

/* Author:  Marty Kraimer Date:    26JAN2000 */

/********************COPYRIGHT NOTIFICATION**********************************
This software was developed under a United States Government license
described on the COPYRIGHT_UniversityOfChicago file included as part
of this distribution.
****************************************************************************/

#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>

#include "osiThread.h"
#include "errlog.h"

threadPrivateId privateKey;

static void threadFunc(void *arg)
{
    int myPrivate;
    int argvalue = *(int *)arg;
    myPrivate = argvalue;
    threadPrivateSet(privateKey,(void *)argvalue);
    errlogPrintf("threadFunc %d starting\n",argvalue);
    threadSleep(2.0);
    argvalue = -1;
    argvalue = (int)threadPrivateGet(privateKey);
    errlogPrintf("threadFunc %d stopping myPrivate %d\n",argvalue,myPrivate);
}

void threadTest(int ntasks,int verbose)
{
    unsigned int stackSize;
    threadId *id;
    int i;
    char **name;
    void **arg;
    int startPriority,minPriority,maxPriority;
    int errVerboseSave = errVerbose;

    threadInit ();
    errVerbose = verbose;
    errlogInit(4096);
    id = calloc(ntasks,sizeof(threadId *));
    name = calloc(ntasks,sizeof(char **));
    arg = calloc(ntasks,sizeof(void *));
    errlogPrintf("threadTest starting\n");
    stackSize = threadGetStackSize(threadStackSmall);
    errlogPrintf("stackSize %u\n",stackSize);
    privateKey = threadPrivateCreate();
    for(i=0; i<ntasks; i++) {
        int *argvalue;
        name[i] = calloc(10,sizeof(char));
        sprintf(name[i],"task%d",i);
        arg[i] = calloc(1,sizeof(int));
        argvalue = (int *)arg[i];
        *argvalue = i;
        startPriority = 50+i;
        
        id[i] = threadCreate(name[i],startPriority,stackSize,threadFunc,arg[i]);
        errlogPrintf("threadTest created %d id %p\n",i,id[i]);
        startPriority = threadGetPriority(id[i]);
        threadSetPriority(id[i],threadPriorityMin);
        minPriority = threadGetPriority(id[i]);
        threadSetPriority(id[i],threadPriorityMax);
        maxPriority = threadGetPriority(id[i]);
        threadSetPriority(id[i],50+i);
        if(i==0)errlogPrintf("startPriority %d minPriority %d maxPriority %d\n",
            startPriority,minPriority,maxPriority);
    }
    threadSleep(.1);
    threadShowAll(0);
    threadSleep(5.0);
    errlogPrintf("threadTest terminating\n");
    threadSleep(.5);
    errVerbose = errVerboseSave;
}
