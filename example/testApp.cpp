#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
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
	
	onComplete(200);
}

void testApp::onUpdate(float args) {
	cout << "on tween update args = " << args << endl;
}

void testApp::onComplete(float args) {
	cout << endl << endl;
	cout << "testApp::onComplete args = " << args << endl;
	float _tarX = 0.f;
	float _begin = 0.f;
	if (args > 300) {
		_tarX = 200.f;
		_begin = 900.f;
	} else {
		_tarX = 900.f;
		_begin = 200.f;
	}
	
	// we must pass in a standard begin if we want to get the same value of 550.f, since _x1 does not finish, since it is paused //
	Tweenzor::add( &_x1, _begin, _tarX, 0.f, 3.f );
	
	// we can pass in a vector of properties to tween, this makes a tween for each property instance, all with the same tween attributes //
	vector <float *> props;
	props.push_back(&_x2);
	Tweenzor::add(props, _x2, _tarX, 0.f, 3.f, EASE_IN_OUT_SINE);
	
	// or pass in a vector of TweenObjects, so that we can control the start and end attributes, but it will still have the same Tween Type //
	vector <TweenObject> objs;
	objs.push_back( TweenObject(&_x3, _x3, _tarX) );
	Tweenzor::add(objs, 0.f, 3.f, EASE_IN_OUT_QUAD);
	
	Tweenzor::add( &_x4, _x4, _tarX, 0.f, 3.f, EASE_IN_OUT_QUART );
	Tweenzor::add( &_x5, _x5, _tarX, 0.f, 3.f, EASE_IN_OUT_CUBIC );
	Tweenzor::add( &_x6, _x6, _tarX, 0.f, 3.f, EASE_IN_OUT_QUINT );
	Tweenzor::add( &_x7, _x7, _tarX, 0.f, 3.f, EASE_IN_OUT_CIRC );
	Tweenzor::add( &_x8, _x8, _tarX, 0.f, 3.f, EASE_IN_OUT_ELASTIC );
	Tweenzor::add( &_x9, _x9, _tarX, 0.f, 3.f, EASE_IN_OUT_BACK );
	Tweenzor::add( &_x10, _x10, _tarX, 0.f, 3.f, EASE_IN_OUT_BOUNCE );
	
	// used to set the time completion, uncomment to get value of 50% time complete LINEAR tween for _x1 //
	/*
	Tweenzor::getTween( &_x1 )->pause();
	// best if used with frames, since when first called, millis are not high enough //
	Tweenzor::getTween( &_x1 )->setTimePct( .5f );
	// we must update the property to make sure, in case the update function is not called on the function //
	Tweenzor::getTween( &_x1 )->updateProperty();
	// we could just use _x1 //
	float tempzor = Tweenzor::getTween( &_x1 )->getPropertyValue();
	cout << "New value should be = " << (_tarX - _x2)  * .5 + _x2 << " Tweenzor::getPropertyValue is " << _x1 << " &_x2 = " << _x2 << endl;
	 */
	
	// could also call the most recently added tween, which would be _x10 //
	//Tweenzor::getRecentTween()->addListener( Tween::COMPLETE, this, &testApp::onComplete);
	
	Tweenzor::getTween( &_x2 )->addListener( Tween::COMPLETE, this, &testApp::onComplete);
}

//--------------------------------------------------------------
void testApp::update() {
	Tweenzor::update();
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
void testApp::keyPressed(int key){
	if (key == ' ') {
		//paused = !paused;
		Tweenzor::toggleAllTweens();
	} else if (key == 'r') {
		Tweenzor::resetAllTweens();
	}
	/*
	if (paused) {
		Tweenzor::pauseAllTweens();
	} else {
		Tweenzor::resumeAllTweens();
	}
	 */
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

