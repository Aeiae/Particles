//
// Created by caleb on 8/19/21.
//

#ifndef PARTICLE_PARTICLE_HPP
#define PARTICLE_PARTICLE_HPP
#include "includes.hpp"
#include <random>
#include <ctime>
#include <cmath>
class Particle {

private:
    const float PI;
    sf::Vertex vertex;
    sf::Vector2f velocity;
    float speed;
    float angle;
public:
    void SetMaxSpeed(float maxSpeed);

private:
    float maxSpeed;

    void Move(float XOffset, float YOffset);
    void determineVelocity(const sf::Vector2i& mousePos);

public:
    Particle();

    const sf::Vertex* GetVertex() const;

    void updateVertex(float dt, const sf::Vector2i& mousePos);
    ~Particle();


};


#endif //PARTICLE_PARTICLE_HPP
