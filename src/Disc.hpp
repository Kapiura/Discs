#pragma once
#include "ofMain.h"
#include "Force.hpp"

#ifndef DISC_HPP
#define DISC_HPP

class Disc {
public:
  Disc();
  void update(Force& force);
  void colision();
  void draw();
  void widthChangeUpdate(Force& force);
  glm::vec3 calculateDragForce();
  float getViscosity();

  glm::vec3 position;
  glm::vec3 velocity;
  ofColor color;
  float positionDispersion;
  float velocityDispersion;
  ofMaterial material;
  float radius;
  float mass;

  static float cx;
  static float cy;
  std::vector<std::pair<float, float>>  forcesArray;
  static float force;
  static float width;
  static float height;
};

#endif // DISC_HPP
