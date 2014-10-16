#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
static unsigned long *i, *j;
void printtos(int mask)
{
	int k;
	asm("movl %ebp, i");
	kprintf("\n The top of stack address before the printtos call instruction is 0x%08x", i+2);
	kprintf("\n The top of stack address after the printtos call instruction is 0x%08x", i);
	asm("movl %esp, j");
	for(k=0;k<6;k++)
	{
		if((*(j+k)&mask)!=0)
			kprintf("\n Content[0x%08x] is 0x%08x", j+k, *(j+k));
	}
}
