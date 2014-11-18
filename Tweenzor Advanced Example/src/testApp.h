#pragma once

#include "ofMain.h"
#include "ofxTweenzor.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float _x1, _x2, _x3, _x4, _x5, _x6, _x7, _x8, _x9, _x10;
	ofVec2f center;
	
	TweenParams params;
	
	bool paused;
	
	//void onUpdate(float args);
	void onComplete(float* arg);
};
