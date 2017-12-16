/*******************************************************************************
	Code
*******************************************************************************/

/*******************************************************************************
	Include files
*******************************************************************************/

#include "board.h"

#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

/*******************************************************************************
	Local variables
*******************************************************************************/

volatile static uint32_t msTicks = 0;

/*******************************************************************************
	Local function declarations
*******************************************************************************/

static void* sysTick( void *threadid );

/*******************************************************************************
	Function definitions
*******************************************************************************/

/**
 * \brief Initializes the board.
 * 
 * Just a dummy.
 */
void bsp_init( void )
{
	printf( "Board initialized\n" );
}

/*............................................................................*/
/**
 * \brief Get the boards name.
 *
 * \return	The board's name.
 */
const char* bsp_getName( void )
{
	return "GNU/Linux PC";
}

/*............................................................................*/
/**
 * \brief Resets the ticks measured by system clock.
 * 
 * Just a dummy.
 */
void bsp_resetTicks()
{
	msTicks = 0U;
}

/*............................................................................*/
/**
 * \brief Enables the systick every millisecond.
 * 
 * Just a dummy.
 * 
 * \return	Always 0
 */
int8_t bsp_setSysTick( void )
{
	/* Reset the clock */
	msTicks = 0U;

	/* Create new thread */
	pthread_t thread;
	long t;
	int rc = pthread_create( &thread, NULL, sysTick, (void *)t );
	if( rc )
	{
		/* Fail */
		return -1;
	}

	/* Success */
	return 0;
}

/*............................................................................*/
/**
 * \brief Get the boards name.
 * 
 * Dummy.
 * 
 * \return	Always zero.
 */
uint32_t bsp_getTicks( void )
{
	return msTicks;
}

/*............................................................................*/

void bsp_setup_led( void )
{
	printf( "Led: as output\n" );
}

/*............................................................................*/

void bsp_led_on( void )
{
	printf( "Led: on\n" );
}

/*............................................................................*/

void bsp_led_off( void )
{
	printf( "Led: off\n" );
}

/*............................................................................*/
/**
 * \brief Toggles the board led.
 * 
 * Dummy.
 */
void bsp_led_toggle( void )
{
	printf( "Led: toggle\n" );
}

/*............................................................................*/

static void* sysTick( void *threadid )
{
	while( 1 )
	{
		msTicks++;
		usleep( 1000U );
	}

	pthread_exit( NULL );
}