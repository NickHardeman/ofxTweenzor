/*
 *  Tweenzor.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/31/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEENZOR_
#define _TWEENZOR_

#include "Tween.h"

typedef struct _TweenObject {
	_TweenObject(float* $property, float $begin, float $end): _property($property), _begin($begin), _end($end) {}; //constructor
	
	float *_property;
	float _begin, _end;
} TweenObject;

class Tweenzor {
public:
	static Tweenzor* Instance();
	
	static void init();
	static void update();
	static void add(Tween* $tween);
	static void add(float* $property, float $begin, float $end, int $delay, int $duration, int $easeType=EASE_LINEAR, float $p=0, float $a=0);
	static void add(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType=EASE_LINEAR, float $p=0, float $a=0);
	static void add(vector <float *> $properties, float $begin, float $end, float $delay, float $duration, int $easeType=EASE_LINEAR, float $p=0, float $a=0);
	static void add(vector <TweenObject> $properties, float $delay, float $duration, int $easeType=EASE_LINEAR, float $p=0, float $a=0);
	static void removeAllTweens();
	static void removeTweens( float* $property );
	
	static void pauseAllTweens();
	static void resumeAllTweens();
	static void resetAllTweens();
	static void toggleAllTweens();
	
	static int getSize();
	
	static Tween* getTween( float * $property );
	static Tween* getRecentTween();
protected:
	Tweenzor() {};
	
private:
	static Tweenzor* __instance;
	vector <Tween *> _tweens;
};

#endif