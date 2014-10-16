#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
static unsigned long *j;

void printprocstks(int priorityLow, int priorityHigh)
{
	int i;
	struct pentry *proc;
	for(i=0;i<NPROC;i++)
	{
		proc=&proctab[i];
		if(proc->pprio >= priorityLow && proc->pprio <= priorityHigh)
		{
			kprintf("\n The base of the stack is 0x%08x", proc->pbase);
			kprintf("\n The size of the stack is %d", proc->pstklen);
			kprintf("\n The limit of the stack is 0x%08x", proc->plimit);
			if(i==currpid)
			{
				asm("movl %esp, j");
				kprintf("\n The stack pointer is 0x%08x", j);
			}
			else
				kprintf("\n The stack pointer is 0x%08x", proc->pesp);
			kprintf("\n The name of the process is %s", proc->pname);
			kprintf("\n The ID of the process is %d", i);
			kprintf("\n The priority of the process is %d \n \n \n", proc->pprio);
		}
	}
}
