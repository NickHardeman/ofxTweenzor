/*
 *  Functions.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEEN_FUNCTIONS_
#define _TWEEN_FUNCTIONS_

#include "ofMain.h"


/*
 TERMS OF USE - EASING EQUATIONS
 
 Open source under the BSD License.
 
 Copyright © 2001 Robert Penner
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of the author nor the names of contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */ 

class TweenFunctions {
public:
	static float easeLinear(float $t, float $b, float $c, float $d) {
		return $c * $t/$d + $b;
	}
	
	static float easeInQuad(float $t, float $b, float $c, float $d) {
		return $c * ($t /= $d) * $t + $b;
	}
	static float easeOutQuad(float $t, float $b, float $c, float $d) {
		return - $c * ($t /= $d) * ($t-2.f) + $b;
	}
	static float easeInOutQuad(float $t, float $b, float $c, float $d) {
		if ( ($t /= $d/2.f) < 1.f) return $c/2.f * $t * $t + $b;
		return -$c/2 * ( (--$t) * ($t-2.f) - 1.f) + $b;
	}
	
	
	static float easeInCubic(float $t, float $b, float $c, float $d) {
		return $c * pow(($t / $d), 3) + $b;
	}
	static float easeOutCubic(float $t, float $b, float $c, float $d) {
		return $c * (pow($t/$d-1.f, 3) + 1.f) + $b;
	}
	static float easeInOutCubic(float $t, float $b, float $c, float $d) {
		if ( ($t/=$d/2) < 1.f) return $c/2.f * pow($t, 3) + $b;
		return $c/2.f * (pow($t-2.f, 3) + 2.f) + $b;
	}
	
	
	static float easeInQuart(float $t, float $b, float $c, float $d) {
		return $c * pow($t/$d, 4) + $b;
	}
	static float easeOutQuart(float $t, float $b, float $c, float $d) {
		return -$c * (pow($t/$d-1, 4) - 1.f) + $b;
	}
	static float easeInOutQuart(float $t, float $b, float $c, float $d) {
		if ( ($t/=$d/2.f) < 1.f) return $c/2.f * pow($t, 4) + $b;
		return -$c/2.f * (pow($t-2, 4) -2.f) + $b;
	}
	
	
	static float easeInQuint(float $t, float $b, float $c, float $d) {
		return $c * pow($t/$d, 5) + $b;
	}
	static float easeOutQuint(float $t, float $b, float $c, float $d) {
		return $c * (pow($t/$d-1, 5) + 1.f) + $b;
	}
	static float easeInOutQuint(float $t, float $b, float $c, float $d) {
		if ( ($t/=$d/2.f) < 1.f) return $c/2 * pow($t, 5) + $b;
		return $c/2 * (pow($t-2.f, 5) + 2.f) + $b;
	}
	
	
	static float easeInSine(float $t, float $b, float $c, float $d) {
		return $c * (1.f - cos($t/$d * HALF_PI)) + $b;
	}
	static float easeOutSine(float $t, float $b, float $c, float $d) {
		return $c * sin($t/$d * HALF_PI) + $b;
	}
	static float easeInOutSine(float $t, float $b, float $c, float $d) {
		return $c/2 * (1.f - cos(PI * $t/$d)) + $b;
	}
	
	
	static float easeInExpo(float $t, float $b, float $c, float $d) {
		return $c * pow(2.f, 10.f * ($t/$d - 1.f)) + $b;
	}
	static float easeOutExpo(float $t, float $b, float $c, float $d) {
		return $c * (-pow(2.f, -10.f * $t/$d) + 1.f) + $b;
	}
	static float easeInOutExpo(float $t, float $b, float $c, float $d) {
		if ( ($t/=$d/2.f) < 1.f) return $c/2 * pow(2.f, 10.f * ($t - 1.f)) + $b;
		return $c/2 * (-pow(2.f, -10.f * --$t) + 2.f) + $b;
	}
	
	
	static float easeInCirc(float $t, float $b, float $c, float $d) {
		return $c * (1.f - sqrt(1.f - ($t/=$d) * $t)) + $b;
	}
	static float easeOutCirc(float $t, float $b, float $c, float $d) {
		return $c * sqrt(1.f - ($t=$t/$d-1.f) * $t) + $b;
	}
	static float easeInOutCirc(float $t, float $b, float $c, float $d) {
		if ( ($t/=$d/2.f) < 1.f) return $c/2.f * (1.f - sqrt(1.f - $t * $t)) + $b;
		return $c/2.f * (sqrt(1.f - ($t-=2.f) * $t) + 1.f) + $b;
	}
	
	
	
	
	
	
	
	
	/**
	 * Equations
	 * Main equations for the Tweener class
	 *
	 * @author		Zeh Fernando, Nate Chatellier, Arthur Debert
	 * @version		1.0.2
	 * http://code.google.com/p/tweener/
	 */
	
	
	static float easeInElastic(float $t, float $b, float $c, float $d, float $p = 0, float $a = 0) {
		if ($t==0) return $b;
		if (($t/=$d)==1) return $b+$c;
		$p = $p == 0 ? $d * .3 : $p;
		float $s;
		//float a = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float $a_c = $c < 0 ? $c * - 1 : $c;
		if (!($a) || $a < $a_c) {
			$a = $c;
			$s = $p/4;
		} else {
			$s = $p/(2*PI) * asin ($c/$a);
		}
		return -($a*pow(2,10*($t-=1)) * sin( ($t*$d-$s)*(2*PI)/$p )) + $b;
	}
	static float easeOutElastic(float $t, float $b, float $c, float $d, float $p = 0, float $a = 0) {
		if ($t==0) return $b;
		if (($t/=$d)==1) return $b+$c;
		//float p = !Boolean(p_params) || isNaN(p_params.period) ? d*.3 : p_params.period;
		$p = $p == 0 ? $d * .3 : $p;
		float $s;
		//float a = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float $a_c = $c < 0 ? $c * - 1 : $c;
		if (!($a) || $a < $a_c) {
			$a = $c;
			$s = $p/4;
		} else {
			$s = $p/(2*PI) * asin ($c/$a);
		}
		return ($a*pow(2,-10*$t) *sin( ($t*$d-$s)*(2*PI)/$p ) + $c + $b);
	}
	static float easeInOutElastic(float $t, float $b, float $c, float $d, float $p = 0, float $a = 0) {
		if ($t==0) return $b;
		if (($t/=$d/2)==2) return $b+$c;
		//var p:Number = !Boolean(p_params) || isNaN(p_params.period) ? d*(.3*1.5) : p_params.period;
		$p = $p == 0 ? $d*(.3*1.5) : $p;
		float $s;
		//var a:Number = !Boolean(p_params) || isNaN(p_params.amplitude) ? 0 : p_params.amplitude;
		float $a_c = $c < 0 ? $c * - 1 : $c;
		if (!($a) || $a < $a_c) {
			$a = $c;
			$s = $p/4;
		} else {
			$s = $p/(2*PI) * asin ($c/$a);
		}
		if ($t < 1) return -.5*($a*pow(2,10*($t-=1)) * sin( ($t*$d-$s)*(2*PI)/$p )) + $b;
		return $a*pow(2,-10*($t-=1)) * sin( ($t*$d-$s)*(2*PI)/$p )*.5 + $c + $b;
	}
	static float easeOutInElastic(float $t, float $b, float $c, float $d, float $p = 0, float $a = 0) {
		if ($t < $d/2) return easeOutElastic ($t*2, $b, $c/2, $d, $p, $a);
		return easeInElastic(($t*2)-$d, $b+$c/2, $c/2, $d, $p, $a);
	}
	
	
	static float easeInBack(float $t, float $b, float $c, float $d, float $p = 0) {
		// var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		$p = $p == 0 ? 1.70158 : $p;
		return $c*($t/=$d)*$t*(($p+1)*$t - $p) + $b;
	}
	static float easeOutBack(float $t, float $b, float $c, float $d, float $p = 0) {
		//var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		$p = $p == 0 ? 1.70158 : $p;
		return $c*(($t=$t/$d-1)*$t*(($p+1)*$t + $p) + 1) + $b;
	}
	static float easeInOutBack(float $t, float $b, float $c, float $d, float $p = 0) {
		//var s:Number = !Boolean(p_params) || isNaN(p_params.overshoot) ? 1.70158 : p_params.overshoot;
		$p = $p == 0 ? 1.70158 : $p;
		if (($t/=$d/2) < 1) return $c/2*($t*$t*((($p*=(1.525))+1)*$t - $p)) + $b;
		return $c/2*(($t-=2)*$t*((($p*=(1.525))+1)*$t + $p) + 2) + $b;
	}
	static float easeOutInBack(float $t, float $b, float $c, float $d, float $p = 0) {
		if ($t < $d/2) return easeOutBack($t*2, $b, $c/2, $d, $p);
		return easeInBack(($t*2)-$d, $b+$c/2, $c/2, $d, $p);
	}
	
	
	
	
	static float easeInBounce(float $t, float $b, float $c, float $d) {
		return $c - easeOutBounce ($d-$t, 0, $c, $d) + $b;
	}
	
	static float easeOutBounce(float $t, float $b, float $c, float $d) {
		if (($t/=$d) < (1/2.75)) {
			return $c*(7.5625*$t*$t) + $b;
		} else if ($t < (2/2.75)) {
			return $c*(7.5625*($t-=(1.5/2.75))*$t + .75) + $b;
		} else if ($t < (2.5/2.75)) {
			return $c*(7.5625*($t-=(2.25/2.75))*$t + .9375) + $b;
		} else {
			return $c*(7.5625*($t-=(2.625/2.75))*$t + .984375) + $b;
		}
	}
	
	static float easeInOutBounce(float $t, float $b, float $c, float $d) {
		if ($t < $d/2) return easeInBounce ($t*2, 0, $c, $d) * .5 + $b;
		else return easeOutBounce ($t*2-$d, 0, $c, $d) * .5 + $c*.5 + $b;
	}
	
	static float easeOutInBounce(float $t, float $b, float $c, float $d) {
		if ($t < $d/2) return easeOutBounce ($t*2, $b, $c/2, $d);
		return easeInBounce(($t*2)-$d, $b+$c/2, $c/2, $d);
	}
	
};

#endif