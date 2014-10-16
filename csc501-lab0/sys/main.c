/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

void halt();

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

 
int main()
{
	int mask;
	kprintf("\n\nHello World, Xinu lives\n\n");
	kprintf("\n Enter input:");
	long input;
	scanf("%08x", &input);
	kprintf("\n The input is %08x",input);
	long output=zfunction(input);
	kprintf("\n The output is %08x",output);
	printsegaddress();
	kprintf("\n Enter mask:");
	scanf("%d",&mask);
	kprintf("\n The mask in int is %d and hex is 0x%08x",mask,mask);
	printtos(mask);
	int prA();
	int prB();
	syscallsummary_start();
	resume(create(prA, 200, 25, "Proc11", 1, 1));
	getpid();
	syscallsummary_stop();
	//printprocstks(5,25);
	printsyscalls();
	syscallsummary_start();
	resume(create(prB, 200, 25, "Proc12", 1, 1));
	syscallsummary_stop();
	printsyscalls();
	return 0;
}

prA(int a)
{
	sleep(2);
}


prB(int a)
{
	signal(1);
	sleep(1);
}