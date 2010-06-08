/* $Id$ */

struct usart_parameters {
	struct usart *usart;	/* pointer to the hardware device */
	unsigned brgr;		/* Baud rate generator register */
	unsigned flags;		/* flags to driver */
};

/* Flag definitions */

#define UF_CR	1		/* For serial controllers that end line with CR */
#define UF_BREAK 2		/* Enable interrupt on break (framing error) */
	
extern void usart_init( struct usart_parameters *p, int n );
extern char usart_getc( int un );
extern void usart_putc( int un, char c );
extern void usart_interrupt( int un );

/*
 * $Log$
 * Revision 1.2  2010-06-08 18:57:41  jpd
 * Faults and user interrupts now work on SAM7A3
 *
 * Revision 1.1  2010-06-07 00:39:01  jpd
 * Massive reorganization of source tree.
 *
 * Revision 1.2  2010-06-05 17:32:45  jpd
 * More reorganization.
 *
 * Revision 1.1  2009-03-14 22:58:06  jpd
 * Can now run LSE in an ARM SAM7X!
 *
 */