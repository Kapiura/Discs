#pragma once
#include "ofMain.h"

#ifndef FORCES_HPP 
#define FORCES_HPP

class Force {
public:
  Force();

  static float cx;
  static float cy;
  std::vector<std::pair<float, float>>  forcesArray;
  static float force;
  static float width;
  static float height;
};

#endif // FORCES_HPP
