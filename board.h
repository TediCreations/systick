/******************************************************************************
	About
******************************************************************************/

//TODO: Doxygen the about section in file board.h

/**
 * \file board.h
 *
 * \brief	TODO: Write brief
 *
 * Created:			08/12/2017
 *
 * \author	Ilias Kanelis	hkanelhs@yahoo.gr
 */

/**
* \defgroup	Ungrouped	Ungrouped
*
* \code	#include <board.h>	\endcode
*/

/******************************************************************************
	Code
******************************************************************************/

#ifndef BOARD_H_ONLY_ONE_INCLUDE_SAFETY
#define BOARD_H_ONLY_ONE_INCLUDE_SAFETY

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
	Include files
*******************************************************************************/

#include <stdint.h>	/* uint32_t */

/******************************************************************************
	Function declarations
******************************************************************************/

void		bsp_init( void );
const char* bsp_getName( void );

uint32_t	bsp_getTicks( void );
void		bsp_resetTicks( void );
int8_t		bsp_setSysTick( void );

void		bsp_setup_led( void );
void		bsp_led_on( void );
void		bsp_led_off( void );
void		bsp_led_toggle( void );

#ifdef __cplusplus
}
#endif

#endif /* BOARD_H_ONLY_ONE_INCLUDE_SAFETY */
