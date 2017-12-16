/******************************************************************************
	Includes
******************************************************************************/

#include "board.h"

#include <stdio.h>

/******************************************************************************
	Code
******************************************************************************/

int main( int argc, char *argv[] )
{
	/* Initialize the board */
	bsp_init();

	/* Test led */
	bsp_setup_led();

	/* Enable system tick clock */
	bsp_setSysTick();

	/* Get info */
	printf( "Board name: %s!\n", bsp_getName() );

	/* Loop forever */
	while( 1 )
	{
		/* Every 1sec */
		if( bsp_getTicks() >1000U )
		{
			bsp_resetTicks();
			bsp_led_toggle();
		}
	}

	/* Will never reach here. Will never return... */
	return 0;
}
