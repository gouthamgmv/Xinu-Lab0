
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
int scgetpid[NPROC];
int scgettime[NPROC];
int sckill[NPROC];
int scsignal[NPROC];
int scsleep[NPROC];
int scwait[NPROC];
int traceOn;
void syscallsummary_start()
{
	traceOn=1;
}
void syscallsummary_stop()
{
	traceOn=0;
}
void printsyscalls()
{
	int i;
	for(i=0;i<NPROC;i++)
	{
		if(scgetpid[i]==1 || scgettime[i]==1 || sckill[i]==1 || scsignal[i]==1 || scsleep[i]==1 || scwait[i]==1)
		{
			printf("\n System call(s) invoked for process %d is/are:", i);
			if(scgetpid[i]==1)
				printf("\n SYSCALL getpid()");
			if(scgettime[i]==1)
				printf("\n SYSCALL gettime()");
			if(sckill[i]==1)
				printf("\n SYSCALL kill()");
			if(scsignal[i]==1)
				printf("\n SYSCALL signal()");
			if(scsleep[i]==1)
				printf("\n SYSCALL sleep()");
			if(scwait[i]==1)
				printf("\n SYSCALL wait()");
			printf("\n\n\n");
		}
	}
	for(i=0;i<NPROC;i++)
	{
		scgetpid[i]=0;
		scgettime[i]=0;
		sckill[i]=0;
		scsignal[i]=0;
		scsleep[i]=0;
		scwait[i]=0;
	}
}