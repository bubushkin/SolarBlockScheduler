/*
 * runlevel.h
 *
 *  Created on: Mar 8, 2021
 *      Author: iskandar
 */

#ifndef INCLUDE_RUNLEVEL_H_
#define INCLUDE_RUNLEVEL_H_


#ifdef GREEN_RN
	#define GREEN_MIN 80
	#define GREEN_MAX 100
#endif

#ifdef YELLOW_RN
	#define YELLOW_MIN 20
	#define YELLOW_MAX 79
#endif

#ifdef RED_RN
	#define RED_MIN 6
	#define RED_MAX 19
#endif

#ifdef BLACK_RN
	#define BLACK_MIN 1
	#define BLACK_MAX 5
#endif


#endif /* INCLUDE_RUNLEVEL_H_ */
