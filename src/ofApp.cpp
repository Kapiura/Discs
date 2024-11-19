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
    el.update(force);
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto &el : discs)
    el.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  if (ofGetKeyPressed(OF_KEY_CONTROL) && key == 'z' && !force.forcesArray.empty())
    force.forcesArray.pop_back();
  else if(key == OF_KEY_UP)
    Force::force += 10.0f;
  else if(key == OF_KEY_DOWN)
    Force::force -= 10.0f;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) 
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
  force.forcesArray.push_back(std::make_pair(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------

void ofApp::mouseEntered(int x, int y) {
}
//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
