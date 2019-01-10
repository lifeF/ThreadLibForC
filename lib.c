#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "threadlib.h"
#include "threadimp.h"

#ifndef __x86_64__
#error "NOT 64bit" 
#endif


#define DEBUG
#undef DEBUG /* uncomment when you are done! */

/* 
 * Idea here is that, if DEBUG is defined PRINT will be 
 * printf else it would be nothing. 
 * Use PRINT to print all your debug information and when you 
 * undefine DEBUG all that code will be gone :) 
 */ 
#ifdef DEBUG
 #define PRINT   printf
#else 
 #define PRINT(...)
#endif

/* Track the current thread
 */ 
tcb_t __current_thread;

/* You might need other information about the 
 * thread system as well. 
 */
tcb_t current_thread(void)
{
  return __current_thread;
}

void set_current(tcb_t current)
{
  __current_thread = current;
}

/*Creates a new tcb*/
tcb_t newtcb(void)
{ 
  tcb_t dummy = (tcb_t) malloc(sizeof(struct tcb));
	
	/* might want to initialize the fields in the TCB */
	return dummy;
}

int append(tcb_t newguy)
{
  return -1; 
}

int delete_item (tcb_t thread)
{
  return -1;
}


tcb_t schedule(tcb_t current)
{
  /* decide who should run next */
  return current; 

}

void switch_threads(tcb_t newthread /* addr. of new TCB */,
		    tcb_t oldthread /* addr. of old TCB */) {

  /* This is basically a front end to the low-level assembly 
   * code to switch. */
  /* Might have store the SP values back to TCB */ 
  machine_switch(newthread -> sp,oldthread -> sp);

  /* When you do this call, you should return back to this 
   * point in a different thread. 
   * When you are eventually rescheduled, return through 
   * the calling stack 
   */ 
  return; 

}


/*********************************************************
 *                 Thread creation etc 
 *********************************************************/
int create_thread(void (*ip)(void))
{  
  return -1;
}

void yield()
{
  
  tcb_t cur = current_thread();
  tcb_t new = schedule(cur);

  switch_threads(new, cur);
  return; 
}


void delete_thread(void)
{

  /* When a user-level thread calls this you should not 
   * let it run any more but let others run
   * make sure to exit when all user-level threads are dead */   

}

#include <assert.h>
void stop_main(void)
{ 
  /* Main function was not created by our thread management system. 
   * So we have no record of it. So hijack it. 
   * Do not put it into our ready queue, switch to something else.*/

  yield(); 
  assert(!printf("Should not be here %s",__func__));

}

#include <stdlib.h>


/*
 * allocate some space for thread stack.
 * malloc does not give size aligned memory 
 * this is some hack to fix that.
 * You can use the code as is. 
 */
void * malloc_stack() 
{
  /* allocate something aligned at 16
   */
   void *ptr = malloc(STACK_SIZE + 16);
   if (!ptr) return NULL;
   ptr = (void *)(((long int)ptr & (-1 << 4)) + 0x10);
   return ptr;
}


