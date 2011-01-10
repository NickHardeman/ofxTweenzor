/*
 *  Tweenzor.cpp
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/31/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tweenzor.h"

Tweenzor* Tweenzor::__instance = 0;

Tweenzor* Tweenzor::Instance() {
	if (__instance == 0) {
		__instance = new Tweenzor();
	}
	return __instance;
}

void Tweenzor::init() {
	Instance();
}

void Tweenzor::update() {
	// cout << "Tweenzor :: update : " << __instance->_tweens.size() << endl;
	
	for (int i = 0; i < __instance->_tweens.size(); i++) {
		if (__instance->_tweens[i]->complete()) {
			__instance->_tweens[i]->remove();
			__instance->_tweens.erase(__instance->_tweens.begin() + i);
		}
	}
	
	for (int i = 0; i < __instance->_tweens.size(); i++) {
		__instance->_tweens[i]->update();
	}
	
}

void Tweenzor::add(Tween* $tween) {
	removeTweens( $tween->getProperty() );
	__instance->_tweens.push_back( $tween );
}

// add a tween that uses frames as time //
void Tweenzor::add(float* $property, float $begin, float $end, int $delay, int $duration, int $easeType, float $p, float $a) {
	removeTweens( $property );
	__instance->_tweens.push_back( new Tween( $property, $begin, $end, $delay, $duration, $easeType, $p, $a ) );
}

// add a tween in seconds, pass in float for delay and duration //
void Tweenzor::add(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType, float $p, float $a) {
	removeTweens( $property );
	__instance->_tweens.push_back( new Tween( $property, $begin, $end, $delay, $duration, $easeType, $p, $a ) );
}

void Tweenzor::add(vector <float *> $properties, float $begin, float $end, float $delay, float $duration, int $easeType, float $p, float $a) {
	for (int i = 0; i < $properties.size(); i++) {
		removeTweens( $properties[i] );
		__instance->_tweens.push_back( new Tween( $properties[i], $begin, $end, $delay, $duration, $easeType, $p, $a ) );
	}
}

void Tweenzor::add(vector <TweenObject> $properties, float $delay, float $duration, int $easeType, float $p, float $a) {
	for (int i = 0; i < $properties.size(); i++) {
		removeTweens( $properties[i]._property );
		__instance->_tweens.push_back( new Tween( $properties[i]._property, $properties[i]._begin, $properties[i]._end, $delay, $duration, $easeType, $p, $a ) );
	}
}

void Tweenzor::removeTweens( float* $property ) {
	if (__instance->_tweens.size() > 0) {
		for (int i = 0; i < __instance->_tweens.size(); i++) {
			if ( __instance->_tweens[i]->getProperty() == $property ) {
				// cout << "Tweenzor :: removeTween : property = " <<  __instance->_tweens[i]->getProperty() << " = " << $property << endl;
				__instance->_tweens[i]->remove();
				__instance->_tweens.erase(__instance->_tweens.begin() + i);
			}
		}
	}
}

Tween* Tweenzor::getTween( float * $property ) {
	for (int i = 0; i < __instance->_tweens.size(); i++) {
		if ( __instance->_tweens[i]->getProperty() == $property ) {
			//cout << "Tweenzor :: --getTween : property = " <<  __instance->_tweens[i]->getProperty() << " = " << $property << endl;
			return __instance->_tweens[i];
		}
	}
	return NULL;
}

void Tweenzor::removeAllTweens() {
	for (int i = 0; i < __instance->_tweens.size(); i++) {
		__instance->_tweens[i]->remove();
		__instance->_tweens.erase(__instance->_tweens.begin() + i);
	}
	__instance->_tweens.clear();
	
}

void Tweenzor::pauseAllTweens() {
	if (__instance->_tweens.size() > 0) {
		for (int i = 0; i < __instance->_tweens.size(); i++) {
			__instance->_tweens[i]->pause();
		}
	}
}

void Tweenzor::resetAllTweens() {
	if (__instance->_tweens.size() > 0) {
		for (int i = 0; i < __instance->_tweens.size(); i++) {
			__instance->_tweens[i]->reset();
		}
	}
}


void Tweenzor::resumeAllTweens() {
	if (__instance->_tweens.size() > 0) {
		for (int i = 0; i < __instance->_tweens.size(); i++) {
			__instance->_tweens[i]->resume();
		}
	}
}

void Tweenzor::toggleAllTweens() {
	if (__instance->_tweens.size() > 0) {
		for (int i = 0; i < __instance->_tweens.size(); i++) {
			__instance->_tweens[i]->toggle();
		}
	}
}

Tween* Tweenzor::getRecentTween() {
	if (__instance->_tweens.size() > 0) {
		return __instance->_tweens[__instance->_tweens.size() - 1];
	}
}

int Tweenzor::getSize() {
	__instance->_tweens.size();
}







