/* $Id$ */

/* 

Function to set up the processor environment to execute a standalone C program.
The only initialization that needs to be done before this called is to set the
stack pointer. 

First, it calls app_configure(), which should at least set up the watchdog
configuration and processor clock. This is also a good place to set up other
global peripheral configurations, like clocking and pin assignments. However,
app_configure() may not use static variables, as these may not be initialized,
and may be initialized after it returns.

After app_configure returns, C_startup zeros the "BSS" area, and, if
preprocessor variable COPY_STATIC is set, it copies the initial values of
intialized static variables to working memory.

The last thing this function does is call app_main().

*/

#include <string.h>

/* Memory layout */

extern int bss_start_[], bss_end_[];

#if COPY_STATIC
extern int data_load_[], data_start_[], data_end_[];
#endif

/* application entry points */

extern void app_configure( void );
extern void app_main( void );

void C_startup( void )
{

	app_configure();

/*
Zero the "BSS" area, which holds uninitialized static variables.
*/

	bzero( bss_start_, (void *) bss_end_ - (void *) bss_start_ );
	
/*

Copy initialized static variables from where they're loaded to where they're
used.

*/

#if COPY_STATIC
	bcopy( data_load_, data_start_, 
		(void *) data_end_ - (void *) data_start_ );
#endif

	app_main();

}

/*
 * $Log$
 * Revision 1.2  2010-06-04 18:36:07  jpd
 * Fix byte count.
 *
 * Revision 1.1  2009-03-14 22:58:06  jpd
 * Can now run LSE in an ARM SAM7X!
 *
 */
