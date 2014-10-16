/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	if(traceOn==1)
	{
		scgetpid[currpid]=1;
		kprintf("\n Process %d has executed SYSCALL getpid! \n", currpid);
	}
	return(currpid);
}
