/*
 *  Tween.cpp
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/20/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tween.h"

//--------------------------------------------------------------
// pass in ints for delay and duration as number of frames //
Tween::Tween(float* a_property, float a_begin, float a_end, int a_delay, int a_duration, int a_easeType, float a_p, float a_a) {
	_useSeconds = false;
	_time		= 0.f;
	
	_setup(a_property, a_begin, a_end, (float)a_delay, (float)a_duration, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
// pass in floats for delay and duration as seconds //
Tween::Tween(float* a_property, int a_millis, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
	_useSeconds = true;
	// convert seconds to millis //
	a_delay		= a_delay * 1000.f;
	a_duration	= a_duration * 1000.f;
	
	_startTime	= a_millis;
	_time = 0.f;
	
	_setup(a_property, a_begin, a_end, a_delay, a_duration, a_easeType, a_p, a_a);
}

//--------------------------------------------------------------
void Tween::_setup(float* a_property, float a_begin, float a_end, float a_delay, float a_duration, int a_easeType, float a_p, float a_a) {
	_propAdd	= a_property;
	
	_begin		= a_begin;
	_end		= a_end;
	_change		= _end - _begin;
	
	_initBegin	= _begin;
	_initEnd	= _end;
	
	_delay		= a_delay;
	_duration	= a_duration;
	
	_easeType	= a_easeType;
	
	_p			= a_p;
	_a			= a_a;
	
	// use setRepeat to alter _repeat and _pingPong //
	_repeatTotal= 0; // dont repeat, only execute once //
	_repeatCount= 0; // we have not repeated at all //
	_pingPong	= false; // dont go back and forth //
	_dir		= 1; // go from _begin -> _end;
	
	_isRunning	= true;
	_isComplete = false;
	
	eventID		= -1;
}

//--------------------------------------------------------------
void Tween::resume(int a_millis) {
	if (!_isComplete) {
		if (!_isRunning) {
			if (_useSeconds) {
				_startTime = a_millis - _time;
				_time = (float) a_millis;
			}
		}
		
		_isRunning = true;
	}
	cout << "Tween :: resume : running: " << _isRunning << endl;
}

//--------------------------------------------------------------
void Tween::toggle(int a_millis) {
	if (!_isComplete) {
		if (_isRunning) pause();
		else resume(a_millis);
	}
	cout << "Tween :: toggle : running= " << _isRunning << endl;
}

//--------------------------------------------------------------
void Tween::pause() {
	if (!_isComplete) {
		_isRunning = false;
	}
	cout << "Tween :: pause : running= " << _isRunning << endl;
}

//--------------------------------------------------------------
void Tween::reset(int a_millis) {
	if (!_isComplete) {
		*_propAdd = _begin;
		
		_startTime = a_millis;
		_time = 0.f;
		
		_isComplete = false;
	}
	cout << "Tween :: reset : running: " << running() << " complete: " << complete() << endl;
}

//--------------------------------------------------------------
void Tween::update(int a_millis) {
	//cout << "Tween :: update : time= " << _time << " duration+delay= " << _duration + _delay << " running: " << running() << " complete: " << complete() << endl;
	
	if (_useSeconds) {
		if (_isRunning) _time = (float) a_millis - _startTime;
	}
	
	if (_time <= _duration + _delay) {
		//cout << "Tween :: update : time= " << _time << " duration+delay= " << _duration + _delay << " running: " << running() << endl;
		if (_isRunning) {
			if (_time >= _delay) {
				updateProperty();
			}
			if (!_useSeconds) _time += 1.f;
		}
	} else {
		// no events in ofxiPhone right now :( well, maybe now there is. :/
		//ofNotifyEvent(ON_COMPLETE, _event, this);
		
		bool bTweenIsComplete = false;
		// lets check on the repeat //
		if(_repeatTotal == 0) {
			bTweenIsComplete = true;
		} else if(_repeatCount >= _repeatTotal) {
			bTweenIsComplete = true;
		} else {
			_repeatCount++;
		}
		if (_repeatTotal == -1) { // run forever //
			bTweenIsComplete = false;
		}
		
		//cout << "Tween :: update : bTweenIsComplete= " << bTweenIsComplete << " _repeatCount= " << _repeatCount << endl;
		
		if(bTweenIsComplete) {
			_isComplete = true;
			_isRunning = false;
			// let's make sure we hit the initial values //
			if(_dir == 1) {
				*_propAdd = _initEnd;
			} else {
				*_propAdd = _initBegin;
			}
			
		} else {
			if (_useSeconds) {
				_startTime = a_millis;
			} else {
				_time = 0;
			}
			_delay = 0;
			if(_pingPong) {
				_dir = _dir == 1 ? -1 : 1;
			}
			// adjust for the proper direction of the tween //
			if(_dir == 1) {
				_begin		= _initBegin;
				_end		= _initEnd;
				_change		= _end - _begin;
			} else {
				_begin		= _initEnd;
				_end		= _initBegin;
				_change		= _end - _begin;
			}
		}
	}
	
}

//--------------------------------------------------------------
void Tween::updateProperty() {
	*_propAdd = TweenSelector::getValueEase(MAX(_time - (float)_delay, 0.f), _begin, _change, _duration, _easeType, _p, _a);
}

//--------------------------------------------------------------
void Tween::remove() {
	//removeListeners();
}

//--------------------------------------------------------------
float* Tween::getProperty() {
	return _propAdd;
}

//--------------------------------------------------------------
float Tween::getPropertyValue() {
	return *_propAdd;
}

// if there is a delay, this will bypass it, but preserve the delay property if the tween is reset //
// CAUTION: WHEN USING SECONDS : if this is called when getMillies is less than _time + _delay, it will not work properly//
//--------------------------------------------------------------
void Tween::setTimePct(float a_pct, int a_millis) {
	if (_useSeconds) {
		_startTime = (float)a_millis - _delay - (a_pct * _duration);
		_startTime = _startTime < 0.f ? -1 * _startTime : _startTime;
		_time = (float) a_millis - _startTime;
	} else {
		_time = _delay + ( a_pct * _duration );
	}
}

//--------------------------------------------------------------
void Tween::setRepeat( int a_repeat, bool a_pingPong ) {
	_repeatTotal	= a_repeat;
	_repeatCount	= 0;
	_pingPong		= a_pingPong;
}


// GETTERS //
//--------------------------------------------------------------
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

//--------------------------------------------------------------
float Tween::getTimePct() {
	if (_time >= _delay)
		return MAX(_time - (float)_delay, 0.f) / _duration;
	else return 0.f;
}

//--------------------------------------------------------------
bool Tween::complete() {
	return _isComplete;
}

//--------------------------------------------------------------
bool Tween::running() {
	return _isRunning;
}






