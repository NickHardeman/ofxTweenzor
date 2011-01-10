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
	
	static const int COMPLETE	= 1;
	static const int UPDATE		= 2;
	
	Tween() {};
	
	Tween(float* $property, float $begin, float $end, int $delay, int $duration, int $easeType, float $p=0, float $a=0);
	Tween(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType, float $p=0, float $a=0);
	
	void update();
	void remove();
	
	bool complete();
	bool running();
	
	void pause();
	void resume();
	void toggle();
	void reset();
	
	float* getProperty();
	float getPropertyValue();
	float getPropertyPct();
	void updateProperty();
	float getTimePct();
	void setTimePct(float $pct);
	
	typedef TweenEvent<float> TweenEv; 
	TweenEv completeEvent;
	TweenEv updateEvent;
	
	template <class ListenerClass>
	void addListener(int $event, ListenerClass *$listener, void (ListenerClass::*$listenerMethod)(float args)) {
		switch ($event) {
			case COMPLETE:
				removeListener( COMPLETE );
				completeEvent = new TweenEv::T<ListenerClass>($listener, $listenerMethod);
				//if (completeEvent == true)
					//cout << "completeEvent being added " << endl;
				break;
			case UPDATE:
				removeListener( UPDATE );
				updateEvent = new TweenEv::T<ListenerClass>($listener, $listenerMethod);
				break;
			default:
				cout << "type of event not found" << endl;
				break;
		}
	}
	
	void removeListener(int $event) {
		switch ($event) {
			case COMPLETE:
				if (completeEvent == true) {
					//cout << "Tween :: removeListener : there is a complete event" << endl;
					completeEvent.destroy();
					completeEvent = NULL;
				}
				break;
			case UPDATE:
				if (updateEvent == true) {
					//cout << "Tween :: removeListener : there is a update event" << endl;
					updateEvent.destroy();
					updateEvent = NULL;
				}
				break;
			default:
				break;
		}
		
	}
	
	void removeListeners() {removeListener( COMPLETE ); removeListener( UPDATE); };
	
	
private:
	void _setup(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType, float $p, float $a);
	
	int _startTime;
	
	float _time, _duration, _delay;
	
	float _change, _begin, _end;
	
	float _a, _p;
	
	float *_propAdd;
	
	int _easeType;
	
	bool _isComplete;
	bool _isRunning;
	bool _useSeconds;
	
	void _onComplete(float args);
	void _onUpdate( float args );
	
	
};

#endif