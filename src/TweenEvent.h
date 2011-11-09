/*
 *  TweenEvent.h
 *  openFrameworks
 *
 *  Created by Nick Hardeman on 10/22/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _TWEEN_EVENT_
#define _TWEEN_EVENT_

#include "ofMain.h"

class Tween;

// event delegation //
/// http://www.codeproject.com/KB/cpp/accppdelegates.aspx //

template <typename Arg>
class TweenEvent {
private:
	
	class Base {
	public:
		virtual ~Base() { }
		virtual void operator()(float* args) = 0;
	};
	Base* pointerino;
	bool _assigned;
	
public: 
	unsigned int ID; // this is the tween that is using it //
	template <typename Class>
	class T : public Base {
		// Signature applied to a pointer-to-member for target class.
		typedef void (Class::*Func)(float* args);
		
		
	private:
		Class* mThis; // Pointer to the object we are delegating to.
		Func   mFunc; // Address of the function on the delegate object.
		
	public:
		
		T(Class* aThis, void (Class::*aFunc)(float* args)) : mThis(aThis), mFunc(aFunc) { }
		
		virtual void operator()(float* args) {
			return (mThis->*mFunc)(args);
		}
		
		
	};
	
	~TweenEvent() {	}//cout << "calling the deconstructor" << endl;}//destroy(); }
	
	TweenEvent() {_assigned = false;}
	// associates with the tween //
	virtual void setID(unsigned int a_id) {
		ID = a_id;
	}
	virtual unsigned int getID() {
		return ID;
	}
	
	void destroy() {
		if (_assigned) {
			//cout << "there is a pointerino" << endl;
			delete pointerino;
			pointerino = NULL;
		}
		_assigned = false;
		//cout << "deleting pointerino _assigned = " << _assigned << endl;
	}
	
	
	TweenEvent& operator = (Base* aPtr) {
		pointerino = aPtr;
		_assigned = true;
		return *this;
	}
	
	bool operator == (const bool& b) {
		return _assigned;
	}
	
	void operator()(float* args) {
		if (pointerino) {
			//cout << "TweenEvent :: operator args = " << *args << "  _assigned = " << _assigned << endl;
			(*pointerino)(args);
		}
	}
	
};	

#endif