#pragma once
#include "ofMain.h"

#ifndef DISC_HPP
#define DISC_HPP

class Disc {
public:
  Disc();
  void update();
  void colision();
  void draw();
  void widthChangeUpdate();
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
  static float force;
  static float width;
  static float height;
};

#endif // DISC_HPP
