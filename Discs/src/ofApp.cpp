#include "ofApp.h"

ofApp::ofApp() : discs(1000) {};
//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(0);
  ofEnableDepthTest();
  ofEnableLighting();

  light.setup();
  light.setPosition(200, 300, 400);
  light.enable();
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto &el : discs)
    el.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto &el : discs)
    el.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
