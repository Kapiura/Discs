#include "Force.hpp"
#include "Constants.h"

float Force::width = 0.0f; 
float Force::height = 0.0f;
float Force::cx = 0.0f;
float Force::cy = 0.0f;
float Force::force = 0.0f;

Force::Force()
{
  width = ofGetWidth(); 
  height = ofGetHeight();
  cx = ofGetWidth() / 2.0f;
  cy = ofGetHeight() / 2.0f;
  force = FORCE;
  forcesArray.push_back(std::make_pair(cx, cy));
}
