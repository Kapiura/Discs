#include "Disc.hpp"
#include "Force.hpp"
#include "Constants.h"


Disc::Disc() {
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

void Disc::update(Force& force) {
  for(auto& el: force.forcesArray)
  {
    glm::vec3 direction = glm::vec3(el.first, el.second, position.z) - position;
    float distance = glm::length(direction);

    if(distance > 0.0f)
    {
      direction = glm::normalize(direction);
    }

    float forceMagnitude = force.force / (distance * distance);
    glm::vec3 attractionForce = direction * forceMagnitude;

    velocity += attractionForce;
  }

  glm::vec3 dragForce = calculateDragForce() / 100000000000000000000000000000.0f;
  velocity -= dragForce;

  position += velocity;

  colision();
  widthChangeUpdate(force);
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

void Disc::widthChangeUpdate(Force& force) {
  float tempWidth = ofGetWidth();
  float tempHeight = ofGetHeight();

  if (tempWidth != force.width) {
    float deltaX = tempWidth - force.width;
    position.x += deltaX / 2.0f;
    force.cx = tempWidth / 2.0f;
    force.width = tempWidth;
  }

  if (tempHeight != force.height) {
    float deltaY = tempHeight - force.height;
    position.y += deltaY / 2.0f;
    force.cy = tempHeight / 2.0f;
    force.height = tempHeight;
  }
}


float Disc::getViscosity() {
    float minViscosity = 0.1f;
    float maxViscosity = 1.0f;
    float normalizedX = position.x / ofGetWidth();
    float normalizedY = position.y / ofGetHeight();

    float viscosityX = minViscosity + normalizedX * (maxViscosity - minViscosity);
    float viscosityY = minViscosity + (1.0f - normalizedY) * (maxViscosity - minViscosity);

    return (viscosityX + viscosityY) / 2.0f;
}


glm::vec3 Disc::calculateDragForce() {
  float viscosity = getViscosity();
  float speed = glm::length(velocity);
  glm::vec3 dragForce =
      -6.0f * PI * viscosity * radius * speed * glm::normalize(velocity);
  return dragForce;
}
