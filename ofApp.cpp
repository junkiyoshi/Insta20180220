#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofEnableDepthTest();
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	float radius = 300;

	for (int i = 0; i < 20; i++) {
		
		ofRotate(3);
		//ofRotate(ofGetFrameNum() * 0.05);
		ofColor line_color;
		line_color.setHsb(i * 10, 255, 255);
		ofSetColor(line_color);

		for (int deg = 0; deg < 360; deg += 1) {

			ofVec3f prev_point = make_point(radius, deg - 1);
			ofVec3f point = make_point(radius, deg);
			ofDrawLine(prev_point, point);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_point(float radius, float deg) {

	float x = radius * cos(deg * DEG_TO_RAD);
	float y = radius * sin(deg * DEG_TO_RAD);
	float z = 50.f * sin((deg * 6) * DEG_TO_RAD);

	return ofVec3f(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}