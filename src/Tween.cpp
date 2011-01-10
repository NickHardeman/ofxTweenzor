/*
 *  Tween.cpp
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tween.h"

// pass in ints for delay and duration as number of frames //
Tween::Tween(float* $property, float $begin, float $end, int $delay, int $duration, int $easeType, float $p, float $a) {
	_useSeconds = false;
	_time = 0.f;
	
	_setup($property, $begin, $end, (float)$delay, (float)$duration, $easeType, $p, $a);
}

// pass in floats for delay and duration as seconds //
Tween::Tween(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType, float $p, float $a) {
	_useSeconds = true;
	// convert seconds to millis //
	$delay = $delay * 1000.f;
	$duration = $duration * 1000.f;
	
	_startTime = ofGetElapsedTimeMillis();
	_time = 0.f;
	
	_setup($property, $begin, $end, $delay, $duration, $easeType, $p, $a);
}

void Tween::_setup(float* $property, float $begin, float $end, float $delay, float $duration, int $easeType, float $p, float $a) {
	_propAdd = $property;
	
	_begin = $begin;
	_end = $end;
	_change = _end - _begin;
	
	_delay = $delay;
	_duration = $duration;
	
	_easeType = $easeType;
	
	_p = $p;
	_a = $a;
	
	_isRunning = true;
	_isComplete = false;
}

void Tween::_onComplete(float args) {
	//cout << "Tween :: onComplete : args = " << args << endl;
	bool t = false;
	if (completeEvent == true) { t = true; }
	//cout << "Tween :: onComplete : true " << t << endl;
	if (completeEvent == true) {
		completeEvent(args);
	}
}

void Tween::_onUpdate( float args ) {
	if (updateEvent == true) updateEvent( args );
}

void Tween::resume() {
	if (!_isComplete) {
		if (!_isRunning) {
			if (_useSeconds) {
				_startTime = ofGetElapsedTimeMillis() - _time;
				_time = (float) ofGetElapsedTimeMillis();
			}
		}
		
		_isRunning = true;
	}
}

void Tween::toggle() {
	if (!_isComplete) {
		if (_isRunning) pause();
		else resume();
	}
}

void Tween::pause() {
	if (!_isComplete) {
		_isRunning = false;
	}
}

void Tween::reset() {
	if (!_isComplete) {
		*_propAdd = _begin;
		
		_startTime = ofGetElapsedTimeMillis();
		_time = 0.f;
		
		_isComplete = false;
	}
}

void Tween::update() {
	if (_useSeconds) {
		if (_isRunning) _time = (float) ofGetElapsedTimeMillis() - _startTime;
	}
	
	if (_time <= _duration + _delay) {
		if (_isRunning) {
			
			if (_time >= _delay) {
				updateProperty();
				_onUpdate( *_propAdd );
			}
			_time += 1.f;
		}
		
	} else {
		// no events in ofxiPhone right now :(
		//ofNotifyEvent(ON_COMPLETE, _event, this);
		if (_isRunning)
			_onComplete(*_propAdd);
		_isComplete = true;
		_isRunning = false;
	}
	
}

void Tween::updateProperty() {
	*_propAdd = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin, _change, _duration, _easeType, _p, _a);
}

void Tween::remove() {
	removeListeners();
}

float* Tween::getProperty() {
	return _propAdd;
}

float Tween::getPropertyValue() {
	return *_propAdd;
}

// if there is a delay, this will bypass it, but preserve the delay property if the tween is reset //
// CAUTION: WHEN USING SECONDS : if this is called when getMillies is less than _time + _delay, it will not work properly//
void Tween::setTimePct(float $pct) {
	if (_useSeconds) {
		_startTime = (float)ofGetElapsedTimeMillis() - _delay - ($pct * _duration);
		_startTime = _startTime < 0.f ? -1 * _startTime : _startTime;
		_time = (float) ofGetElapsedTimeMillis() - _startTime;
	} else {
		_time = _delay + ( $pct * _duration );
	}
}


// GETTERS //

float Tween::getPropertyPct() {
	float pct;
	if (*_propAdd == _begin) {
		pct = 0;
	} else if(*_propAdd == _end) {
		pct = 1;
	} else {
		pct= (*_propAdd - _begin) / (_end - _begin);
	}
	return pct < 0 ? pct * -1 : pct;
}

float Tween::getTimePct() {
	if (_time >= _delay)
		return MAX(_time - (float)_delay, 0.f) / _duration;
	else return 0.f;
}

bool Tween::complete() {
	return _isComplete;
}
bool Tween::running() {
	return _isRunning;
}






