#include "Disc.hpp"
#include "Constants.h"

float Disc::width = 0.0f;
float Disc::height = 0.0f;
float Disc::cx = 0.0f;
float Disc::cy = 0.0f;
float Disc::force = 0.0f;

Disc::Disc() {
  width = ofGetWidth();
  height = ofGetHeight();
  cx = ofGetWidth() / 2.0f;
  cy = ofGetHeight() / 2.0f;
  force = FORCE;
  radius = ofRandom(2.0f, RADIUS);
  mass = radius * 0.5f;
  position.x = ofRandom(radius, ofGetWidth() - radius);
  position.y = ofRandom(radius, ofGetHeight() - radius);
  position.z = 1.0f;
  velocity.x = (ofRandom(-1.0f, 1.0f));
  velocity.y = (ofRandom(-1.0f, 1.0f));
  velocity.z = 0.0f;
  color.r = ofRandom(0.0f, 255.0f);
  color.g = ofRandom(0.0f, 255.0f);
  color.b = ofRandom(0.0f, 255.0f);
  material.setDiffuseColor(color);
  material.setSpecularColor(ofColor(255));
  material.setShininess(64);
}

void Disc::update() {
  glm::vec3 direction = glm::vec3(cx, cy, position.z) - position;
  float distance = glm::length(direction);

  if (distance > 0.0f) {
    direction = glm::normalize(direction);
  }

  float forceMagnitude = force / (distance * distance + 1000.0f);
  glm::vec3 attractionForce = direction * forceMagnitude;

  velocity += attractionForce;

  position += velocity;

  colision();
  widthChangeUpdate();
}

void Disc::colision() {
  float dampingFactor = std::max(1.0f - (radius / RADIUS) * 0.1f, 0.95f);
  dampingFactor *= (1.0f / mass);

  if (position.x - radius < 0.0f) {
    position.x = radius;
    velocity.x *= -0.8f;
    velocity.x *= dampingFactor;
  } else if (position.x + radius > ofGetWidth()) {
    position.x = ofGetWidth() - radius;
    velocity.x *= -0.8f;
    velocity.x *= dampingFactor;
  }

  if (position.y - radius < 0.0f) {
    position.y = radius;
    velocity.y *= -0.8f;
    velocity.y *= dampingFactor;
  } else if (position.y + radius > ofGetHeight()) {
    position.y = ofGetHeight() - radius;
    velocity.y *= -0.8f;
    velocity.y *= dampingFactor;
  }
}

void Disc::draw() {
  material.begin();
  ofSetColor(color);
  ofPushMatrix();
  ofScale(1.0, 1.0, 0.1);
  ofDrawSphere(position, radius);
  ofPopMatrix();
  material.end();
}

void Disc::widthChangeUpdate() {
  float tempWidth = ofGetWidth();
  float tempHeight = ofGetHeight();

  if (tempWidth != width) {
    float deltaX = tempWidth - width;
    position.x += deltaX / 2.0f;
    cx = tempWidth / 2.0f;
    width = tempWidth;
  }

  if (tempHeight != height) {
    float deltaY = tempHeight - height;
    position.y += deltaY / 2.0f;
    cy = tempHeight / 2.0f;
    height = tempHeight;
  }
}
