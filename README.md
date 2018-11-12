#ofxTweenzor v 2.0
##C++ Tweening Library

Features:
--------
* Complete events with small footprint
* Ping pongning
* Repeat tweens
* Params structure for easy creation
* OpenFrameworks 007 Examples!

Updates:
--------
* Rearranged folders to addon structure, may have broken visual studio project.
* Added ofFloatColor, ofVec2f, ofVec3f, ofVec4f and ofRectangle tweenable properties (@tiagosr)

* Fixed memory allocation issue!
* Re-worked event structure, so getting tweens and adding listeners is different than previous version
* Complete event now returns pointer to the variable
* added update( millis )
* added some more examples
* ping ponging capable
* can define number of times to repeat a tween before firing a complete event
* added a tween param structure to allow for easier storing and re-initializing tweens with the same params.
* there is no POCO, since it causes problems sometimes.
