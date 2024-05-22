#pragma once

#include "ofMain.h"
#include "ofxTweenzor.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    float _x1, _x2, _x3, _x4, _x5, _x6, _x7, _x8, _x9, _x10;
	
	bool paused;
	
	void onComplete(float* arg);
};
