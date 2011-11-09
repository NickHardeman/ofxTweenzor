#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	// must call this before adding any tweens //
	Tweenzor::init();
	
	paused = false;
	
	_x1 = 200.f;
	_x2 = 200.f;
	_x3 = 200.f;
	_x4 = 200.f;
	_x5 = 200.f;
	_x6 = 200.f;
	_x7 = 200.f;
	_x8 = 200.f;
	_x9 = 200.f;
	_x10 = 200.f;
	
	
	Tweenzor::add(&_x1, 200.f, 900.f, 0.f, 1.f);
	
	// lets set the tween to repeat once
	// it will run once and then repeat once
	
	// the second argument (true) is a ping pong parameter
	// if this is set to true:
	// it will go begin value -> end value
	// and then repeat end value -> begin value
	
	// but if ping pong is set to false:
	// it will go begin value -> end value
	// and then repeat begin value -> end value
	
	Tweenzor::getTween( &_x1 )->setRepeat( 1, true );
	// let's add a listener so we know when this tween is done //
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x1), this, &testApp::onComplete);
	
}

//--------------------------------------------------------------
// this function is called on when the tween is complete //
void testApp::onComplete(float* arg) {
	cout << "testApp :: onComplete : arg = " << *arg << endl;
	float _tarX = 0.f;
	float _begin = 0.f;
	
	// the arg argument is a pointer to the variable passed in when calling Tweenzor::add();
	// if you want to check its value, you must de-reference it by calling *arg
	if (*arg > 300) {
		_tarX = 200.f;
		_begin = 900.f;
	} else {
		_tarX = 900.f;
		_begin = 200.f;
	}
	
	
	Tweenzor::add( &_x1, _begin, _tarX, 0.f, 2.f );
	
	// add the complete listener again so that it will fire again, creating a loop //
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x1), this, &testApp::onComplete);
	
	Tweenzor::add(&_x2, _x2, _tarX, 0.f, 2.f, EASE_IN_OUT_SINE);
	Tweenzor::add(&_x3, _x3, _tarX, 0.f, 2.f, EASE_IN_OUT_QUAD);
	
	Tweenzor::add( &_x4, _x4, _tarX, 0.f, 2.f, EASE_IN_OUT_QUART );
	Tweenzor::add( &_x5, _x5, _tarX, 0.f, 2.f, EASE_IN_OUT_CUBIC );
	Tweenzor::add( &_x6, _x6, _tarX, 0.f, 2.f, EASE_IN_OUT_QUINT );
	Tweenzor::add( &_x7, _x7, _tarX, 0.f, 2.f, EASE_IN_OUT_CIRC );
	Tweenzor::add( &_x8, _x8, _tarX, 0.f, 2.f, EASE_IN_OUT_ELASTIC );
	Tweenzor::add( &_x9, _x9, _tarX, 0.f, 2.f, EASE_IN_OUT_BACK );
	Tweenzor::add( &_x10, _x10, _tarX, 0.f, 2.f, EASE_IN_OUT_BOUNCE );
	
	
	
}

//--------------------------------------------------------------
void testApp::update() {
	Tweenzor::update( ofGetElapsedTimeMillis() );
}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetColor(100, 100, 100);
	for (int i = 0; i < 10; i++) {
		float yPos = (float)i * 50 + 50;
		ofLine(0, yPos, ofGetWidth(), yPos);
	}
	
	ofDrawBitmapString("LINEAR", 20, 47);
	ofDrawBitmapString("IN_OUT_SINE", 20, 97);
	ofDrawBitmapString("IN_OUT_QUAD", 20, 147);
	ofDrawBitmapString("IN_OUT_QUART", 20, 197);
	ofDrawBitmapString("IN_OUT_CUBIC", 20, 247);
	ofDrawBitmapString("IN_OUT_QUINT", 20, 297);
	ofDrawBitmapString("IN_OUT_CIRC", 20, 347);
	ofDrawBitmapString("IN_OUT_ELASTIC", 20, 397);
	ofDrawBitmapString("IN_OUT_BACK", 20, 447);
	ofDrawBitmapString("IN_OUT_BOUNCE", 20, 497);
	
	ofDrawBitmapString("hit space to toggle all tweens\nhit r to reset tweens", 20, 550);
	
	
	ofSetColor(255, 0, 0);
	ofCircle(_x1, 50, 10);
	ofCircle(_x2, 100, 10);
	ofCircle(_x3, 150, 10);
	ofCircle(_x4, 200, 10);
	ofCircle(_x5, 250, 10);
	ofCircle(_x6, 300, 10);
	ofCircle(_x7, 350, 10);
	ofCircle(_x8, 400, 10);
	ofCircle(_x9, 450, 10);
	ofCircle(_x10, 500, 10);
}

//--------------------------------------------------------------
void testApp::exit() {
	Tweenzor::destroy();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == ' ') {
		paused = !paused;
		Tweenzor::toggleAllTweens();
	} else if (key == 'r') {
		Tweenzor::resetAllTweens();
	} else if ( key == 't') {
		float num = 0.f;
		onComplete(&num);
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

