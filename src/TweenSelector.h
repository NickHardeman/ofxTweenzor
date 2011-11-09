/*
 *  TweenSelector.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEEN_SELECTOR_
#define _TWEEN_SELECTOR_

#include "ofMain.h"
#include "TweenFunctions.h"

#define EASE_LINEAR				 0

#define EASE_IN_QUAD			 1
#define EASE_OUT_QUAD			 2
#define EASE_IN_OUT_QUAD		 3

#define EASE_IN_CUBIC			 4
#define EASE_OUT_CUBIC			 5
#define EASE_IN_OUT_CUBIC		 6

#define EASE_IN_QUART			 7
#define EASE_OUT_QUART			 8
#define EASE_IN_OUT_QUART		 9

#define EASE_IN_QUINT			 10
#define EASE_OUT_QUINT			 11
#define EASE_IN_OUT_QUINT		 12

#define EASE_IN_SINE			 13
#define EASE_OUT_SINE			 14
#define EASE_IN_OUT_SINE		 15

#define EASE_IN_EXPO			 16
#define EASE_OUT_EXPO			 17
#define EASE_IN_OUT_EXPO		 18

#define EASE_IN_CIRC			 19
#define EASE_OUT_CIRC			 20
#define EASE_IN_OUT_CIRC		 21

#define EASE_IN_ELASTIC			 22
#define EASE_OUT_ELASTIC		 23
#define EASE_IN_OUT_ELASTIC		 24
#define EASE_OUT_IN_ELASTIC		 25

#define EASE_IN_BACK			 26
#define EASE_OUT_BACK			 27
#define	EASE_IN_OUT_BACK		 28
#define EASE_OUT_IN_BACK		 29

#define EASE_IN_BOUNCE			 30
#define EASE_OUT_BOUNCE			 31
#define EASE_IN_OUT_BOUNCE		 32
#define EASE_OUT_IN_BOUNCE		 33

class TweenSelector {
public:
	
	static float getValueEase(float a_t, float a_b, float a_c, float a_d, int a_easeType = 0, float a_p = 0, float a_a = 0) {
		switch (a_easeType) {
			case EASE_LINEAR:
				return TweenFunctions::easeLinear(a_t, a_b, a_c, a_d);
				
			case EASE_IN_QUAD:
				return TweenFunctions::easeInQuad(a_t, a_b, a_c, a_d);
			case EASE_OUT_QUAD:
				return TweenFunctions::easeOutQuad(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_QUAD:
				return TweenFunctions::easeInOutQuad(a_t, a_b, a_c, a_d);
		
			case EASE_IN_CUBIC:
				return TweenFunctions::easeInCubic(a_t, a_b, a_c, a_d);
			case EASE_OUT_CUBIC:
				return TweenFunctions::easeOutCubic(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_CUBIC:
				return TweenFunctions::easeInOutCubic(a_t, a_b, a_c, a_d);
		
			case EASE_IN_QUART:
				return TweenFunctions::easeInQuart(a_t, a_b, a_c, a_d);
			case EASE_OUT_QUART:
				return TweenFunctions::easeOutQuart(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_QUART:
				return TweenFunctions::easeInOutQuart(a_t, a_b, a_c, a_d);
				
			case EASE_IN_QUINT:
				return TweenFunctions::easeInQuint(a_t, a_b, a_c, a_d);
			case EASE_OUT_QUINT:
				return TweenFunctions::easeOutQuint(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_QUINT:
				return TweenFunctions::easeInOutQuint(a_t, a_b, a_c, a_d);
				
			case EASE_IN_SINE:
				return TweenFunctions::easeInSine(a_t, a_b, a_c, a_d);
			case EASE_OUT_SINE:
				return TweenFunctions::easeOutSine(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_SINE:
				return TweenFunctions::easeInOutSine(a_t, a_b, a_c, a_d);
				
			case EASE_IN_EXPO:
				return TweenFunctions::easeInExpo(a_t, a_b, a_c, a_d);
			case EASE_OUT_EXPO:
				return TweenFunctions::easeOutExpo(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_EXPO:
				return TweenFunctions::easeInOutExpo(a_t, a_b, a_c, a_d);
				
			case EASE_IN_CIRC:
				return TweenFunctions::easeInCirc(a_t, a_b, a_c, a_d);
			case EASE_OUT_CIRC:
				return TweenFunctions::easeOutCirc(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_CIRC:
				return TweenFunctions::easeInOutCirc(a_t, a_b, a_c, a_d);
		
			case EASE_IN_ELASTIC:
				return TweenFunctions::easeInElastic(a_t, a_b, a_c, a_d, a_p, a_a);
			case EASE_OUT_ELASTIC:
				return TweenFunctions::easeOutElastic(a_t, a_b, a_c, a_d, a_p, a_a);
			case EASE_IN_OUT_ELASTIC:
				return TweenFunctions::easeInOutElastic(a_t, a_b, a_c, a_d, a_p, a_a);
			case EASE_OUT_IN_ELASTIC:
				return TweenFunctions::easeOutInElastic(a_t, a_b, a_c, a_d, a_p, a_a);
		
			case EASE_IN_BACK:
				return TweenFunctions::easeInBack(a_t, a_b, a_c, a_d, a_p);
			case EASE_OUT_BACK:
				return TweenFunctions::easeOutBack(a_t, a_b, a_c, a_d, a_p);
			case EASE_IN_OUT_BACK:
				return TweenFunctions::easeInOutBack(a_t, a_b, a_c, a_d, a_p);
			case EASE_OUT_IN_BACK:
				return TweenFunctions::easeOutInBack(a_t, a_b, a_c, a_d, a_p);
		
		
			case EASE_IN_BOUNCE:
				return TweenFunctions::easeInBounce(a_t, a_b, a_c, a_d);
			case EASE_OUT_BOUNCE:
				return TweenFunctions::easeOutBounce(a_t, a_b, a_c, a_d);
			case EASE_IN_OUT_BOUNCE:
				return TweenFunctions::easeInOutBounce(a_t, a_b, a_c, a_d);
			case EASE_OUT_IN_BOUNCE:
				return TweenFunctions::easeOutInBounce(a_t, a_b, a_c, a_d);
				
			default:
				return TweenFunctions::easeLinear(a_t, a_b, a_c, a_d);
				break;
				
		}
	
	}
	 
};

#endif

