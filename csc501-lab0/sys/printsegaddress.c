#include <stdio.h>
extern int etext, edata, end;

void printsegaddress()
{
	kprintf("\n The address of the end of the text segment is  0x%08x", &etext);
	kprintf("\n The address of the end of the data segment is  0x%08x", &edata);
	kprintf("\n The address of the end of the BSS segment is  0x%08x", &end);
	kprintf("\n The contents preceding and after the boundary of the text and data segment is 0x%08x and 0x%08x respectively!", *(&etext-1), *(&etext+1));
	kprintf("\n The contents preceding and after the boundary of the data and BSS segment is 0x%08x and 0x%08x respectively!", *(&edata-1), *(&edata+1));
	kprintf("\n The contents preceding and after the end of the BSS segment is 0x%08x and 0x%08x respectively!", *(&end-1), *(&end+1));
}