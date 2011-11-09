/*
 *  Tween.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEEN_
#define _TWEEN_


#include "ofMain.h"
#include "TweenSelector.h"
#include "TweenEvent.h"

class Tween {
public:
	
	Tween() {};
	
	Tween(float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType, float a_p=0, float a_a=0);
	Tween(float* a_property, int a_millis, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p=0, float a_a=0);
	
	void update(int a_millis);
	void remove();
	
	bool complete();
	bool running();
	
	void pause();
	void resume(int a_millis);
	void toggle(int a_millis);
	void reset(int a_millis);
	
	float* getProperty();
	float getPropertyValue();
	float getPropertyPct();
	void updateProperty();
	float getTimePct();
	void setTimePct(float a_pct, int a_millis = 0);
	
	void setRepeat( int a_repeat, bool a_pingPong=false );
	
	unsigned int eventID;
	
	
private:
	void _setup(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a);
	
	int _startTime;
	
	float _time, _duration, _delay;
	
	float _change, _begin, _end;
	float _initBegin, _initEnd; // store these, since during a ping pong, we need to switch them //
	
	float _a, _p;
	
	float *_propAdd;
	
	int _easeType;
	
	int _repeatTotal; // -1 for unlimited, 0 is no repeat, which is default, 1 will run the first time and then again // 
	int _repeatCount; // how many times has this thing repeated? //
	bool _pingPong; // default: false; true = _begin -> _end, _end -> _begin..., as many times as repeat is set //
	int _dir; // used for _pingPong; if 1 than _begin -> _end; if -1 then _end -> _start //
	
	bool _isComplete;
	bool _isRunning;
	bool _useSeconds;
	
	
};

#endif