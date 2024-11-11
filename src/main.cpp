#include "ofApp.h"
#include "ofMain.h"
#define WIDTH 1024
#define HEIGHT 780

int main() {

  // Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
  ofGLWindowSettings settings;
  settings.setSize(WIDTH, HEIGHT);
  settings.windowMode = OF_WINDOW; // can also be OF_FULLSCREEN

  auto window = ofCreateWindow(settings);

  ofRunApp(window, make_shared<ofApp>());
  ofRunMainLoop();
}
