#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(40);
	// must call this before adding any tweens //
	Tweenzor::init();
	
	ofSetCircleResolution(32);
	
	paused = false;
	
	center.set( ofGetWidth()*.5, ofGetHeight()*.5 );
	
	_x1 = 200.f;
	_x2 = ofRandom(11, 200);
	_x3 = ofRandom(10, 100);
	_x4 = ofRandom(120, 320);
	_x5 = ofRandom(10, 80);
	_x6 = 200.f;
	_x7 = 200.f;
	_x8 = ofRandom(250, 400);
	_x9 = ofRandom(-100, 100);
	_x10 = 0.f;
	
	// save some params //
	params.setup( &_x2, _x2, ofRandom(11, 200), 0.f, 2.f, EASE_IN_OUT_SINE );
	
	
	Tweenzor::add(&_x1, 0.f, 255.f, 0.f, 2.f);
	// set this to -1 to repeat forever //
	Tweenzor::getTween( &_x1 )->setRepeat( -1, true );
	
	
	Tweenzor::add(params);
	//Tweenzor::getTween( params.property )->setRepeat( 1, true );
	Tweenzor::addCompleteListener( Tweenzor::getTween( params.property ), this, &ofApp::onComplete);
	
	Tweenzor::add(&_x3, _x3, ofRandom(100, 400), 0.f, ofRandom(.5, 1.6), EASE_IN_OUT_QUAD);
	//Tweenzor::getTween( &_x3 )->setRepeat( 1, true );
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x3), this, &ofApp::onComplete);
	
	
	Tweenzor::add( &_x4, _x4, ofRandom(120, 320), .1f, ofRandom(.5, 1.), EASE_IN_OUT_QUART );
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x4), this, &ofApp::onComplete);
	
	Tweenzor::add( &_x5, _x5, ofRandom(10, 80), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_CUBIC );
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x5), this, &ofApp::onComplete);
	
	Tweenzor::add( &_x9, _x9, ofRandom(-100, 100), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_ELASTIC );
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x9), this, &ofApp::onComplete);
	
	Tweenzor::add( &_x8, _x8, ofRandom(250, 400), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_ELASTIC );
	Tweenzor::addCompleteListener( Tweenzor::getTween(&_x8), this, &ofApp::onComplete );
	
	Tweenzor::add(&_x10, 100.f, 255.f, 0.f, 3.f);
	// set this to -1 to repeat forever //
	Tweenzor::getTween( &_x10 )->setRepeat( -1, true );

}

//--------------------------------------------------------------
// this function is called on when the tween is complete //
void ofApp::onComplete(float* arg) {
	//cout << "testApp :: onComplete : arg = " << *arg << endl;
	float _tarX = 0.f;
	float _begin = 0.f;
	if (*arg > 300) {
		_tarX = 200.f;
		_begin = 900.f;
	} else {
		_tarX = 900.f;
		_begin = 200.f;
	}
	
	if(arg == &_x3) {
		//cout << "testApp :: onComplete : yup this is the _x3 var" << endl;
		Tweenzor::add(&_x3, *arg, ofRandom(200, 400), 0.f, ofRandom(.5, 1.6), EASE_IN_OUT_QUAD);
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x3), this, &ofApp::onComplete);
	} else if (arg == &_x2) {
		// update the params //
		params.begin	= *params.property;
		params.end		= ofRandom(11, 200);
		params.duration = ofRandom(.3, 1.1);
		Tweenzor::add( params );
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x2), this, &ofApp::onComplete);
	} else if (arg == &_x4) {
		Tweenzor::add( &_x4, *arg, ofRandom(120, 320), 0.f, ofRandom(.5, 1.), EASE_IN_OUT_QUART );
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x4), this, &ofApp::onComplete);
	} else if (arg == &_x5) {
		Tweenzor::add( &_x5, _x5, ofRandom(10, 80), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_CUBIC );
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x5), this, &ofApp::onComplete);
		
	} else if (arg == &_x9) {
		Tweenzor::add( &_x9, _x9, ofRandom(-200, 200), 0.f, ofRandom(1.75, 2.25f), EASE_IN_OUT_ELASTIC );
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x9), this, &ofApp::onComplete);
	} else {
		Tweenzor::add( &_x6, _x6, ofRandom(20, 100), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_QUINT );
		Tweenzor::add( &_x7, _x7, ofRandom(200, 300), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_CIRC );
		Tweenzor::add( &_x8, _x8, ofRandom(250, 400), 0.f, ofRandom(.75, 1.25f), EASE_IN_OUT_ELASTIC );
		// add a complete listener to _x8, it will overwrite the other tweens, so they will stop abruptly when _x8 is done //
		Tweenzor::addCompleteListener( Tweenzor::getTween(&_x8), this, &ofApp::onComplete );
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
    Tweenzor::update( ofGetElapsedTimeMillis() );
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(100, 100, 100);
	
	
	ofDrawBitmapString("hit space to toggle all tweens\nhit r to reset tweens", 20, ofGetHeight()-80);
	
	ofSetColor(223);
	ofDrawRectangle(_x1, 50., 5.f, 5.f);
	
	ofSetColor(120, 120, 120);
	ofDrawCircle( center.x + (_x9*.1), center.y, _x3 );
	
	ofSetColor(_x1, 150, 150);
	ofDrawCircle( center.x + (_x9*.3), center.y, _x4);
	
	ofSetColor(190);
	ofDrawCircle( center.x + (_x9*.6), center.y, _x2);
	
	ofSetColor(245);
	ofDrawCircle( center.x + (_x9*.9), center.y, _x5);
	
	ofNoFill();
	ofSetColor(_x10);
	ofDrawCircle(center.x + (_x9*.9), center.y, _x6);
	ofDrawCircle(center.x + (_x9*.6), center.y, _x7);
	ofDrawCircle(center.x + (_x9*.4), center.y, _x8);
	
	ofFill();
	
	
	ofSetColor(120);
	ofDrawCircle(center.x+_x9, center.y, 3);
}

//--------------------------------------------------------------
void ofApp::exit() {
	Tweenzor::destroy();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
