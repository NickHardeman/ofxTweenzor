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
	
	static float getValueEase(float $t, float $b, float $c, float $d, int $easeType = 0, float $p = 0, float $a = 0) {
		switch ($easeType) {
			case EASE_LINEAR:
				return TweenFunctions::easeLinear($t, $b, $c, $d);
				
			case EASE_IN_QUAD:
				return TweenFunctions::easeInQuad($t, $b, $c, $d);
			case EASE_OUT_QUAD:
				return TweenFunctions::easeOutQuad($t, $b, $c, $d);
			case EASE_IN_OUT_QUAD:
				return TweenFunctions::easeInOutQuad($t, $b, $c, $d);
		
			case EASE_IN_CUBIC:
				return TweenFunctions::easeInCubic($t, $b, $c, $d);
			case EASE_OUT_CUBIC:
				return TweenFunctions::easeOutCubic($t, $b, $c, $d);
			case EASE_IN_OUT_CUBIC:
				return TweenFunctions::easeInOutCubic($t, $b, $c, $d);
		
			case EASE_IN_QUART:
				return TweenFunctions::easeInQuart($t, $b, $c, $d);
			case EASE_OUT_QUART:
				return TweenFunctions::easeOutQuart($t, $b, $c, $d);
			case EASE_IN_OUT_QUART:
				return TweenFunctions::easeInOutQuart($t, $b, $c, $d);
				
			case EASE_IN_QUINT:
				return TweenFunctions::easeInQuint($t, $b, $c, $d);
			case EASE_OUT_QUINT:
				return TweenFunctions::easeOutQuint($t, $b, $c, $d);
			case EASE_IN_OUT_QUINT:
				return TweenFunctions::easeInOutQuint($t, $b, $c, $d);
				
			case EASE_IN_SINE:
				return TweenFunctions::easeInSine($t, $b, $c, $d);
			case EASE_OUT_SINE:
				return TweenFunctions::easeOutSine($t, $b, $c, $d);
			case EASE_IN_OUT_SINE:
				return TweenFunctions::easeInOutSine($t, $b, $c, $d);
				
			case EASE_IN_EXPO:
				return TweenFunctions::easeInExpo($t, $b, $c, $d);
			case EASE_OUT_EXPO:
				return TweenFunctions::easeOutExpo($t, $b, $c, $d);
			case EASE_IN_OUT_EXPO:
				return TweenFunctions::easeInOutExpo($t, $b, $c, $d);
				
			case EASE_IN_CIRC:
				return TweenFunctions::easeInCirc($t, $b, $c, $d);
			case EASE_OUT_CIRC:
				return TweenFunctions::easeOutCirc($t, $b, $c, $d);
			case EASE_IN_OUT_CIRC:
				return TweenFunctions::easeInOutCirc($t, $b, $c, $d);
		
			case EASE_IN_ELASTIC:
				return TweenFunctions::easeInElastic($t, $b, $c, $d, $p, $a);
			case EASE_OUT_ELASTIC:
				return TweenFunctions::easeOutElastic($t, $b, $c, $d, $p, $a);
			case EASE_IN_OUT_ELASTIC:
				return TweenFunctions::easeInOutElastic($t, $b, $c, $d, $p, $a);
			case EASE_OUT_IN_ELASTIC:
				return TweenFunctions::easeOutInElastic($t, $b, $c, $d, $p, $a);
		
			case EASE_IN_BACK:
				return TweenFunctions::easeInBack($t, $b, $c, $d, $p);
			case EASE_OUT_BACK:
				return TweenFunctions::easeOutBack($t, $b, $c, $d, $p);
			case EASE_IN_OUT_BACK:
				return TweenFunctions::easeInOutBack($t, $b, $c, $d, $p);
			case EASE_OUT_IN_BACK:
				return TweenFunctions::easeOutInBack($t, $b, $c, $d, $p);
		
		
			case EASE_IN_BOUNCE:
				return TweenFunctions::easeInBounce($t, $b, $c, $d);
			case EASE_OUT_BOUNCE:
				return TweenFunctions::easeOutBounce($t, $b, $c, $d);
			case EASE_IN_OUT_BOUNCE:
				return TweenFunctions::easeInOutBounce($t, $b, $c, $d);
			case EASE_OUT_IN_BOUNCE:
				return TweenFunctions::easeOutInBounce($t, $b, $c, $d);
				
			default:
				return TweenFunctions::easeLinear($t, $b, $c, $d);
				break;
				
		}
	
	}
	 
};

#endif

