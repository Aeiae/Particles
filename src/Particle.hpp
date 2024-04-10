//
// Created by caleb on 8/19/21.
//

#ifndef PARTICLE_PARTICLE_HPP
#define PARTICLE_PARTICLE_HPP
#include "includes.hpp"
#include <random>
#include <ctime>
#include <cmath>
class Particle : public sf::Vertex{

private:
    const float PI;

    sf::Vector2i* MPos;
    sf::Vector2f velocity;
    float speed;
    float angle;
public:
    void SetMaxSpeed(float maxSpeed);

private:
    float* Pdt;
    float maxSpeed;

    void Move(float XOffset, float YOffset);
    void determineVelocity();

public:
    explicit Particle(sf::Vector2i* MPosition, float* dt);


    void updateVertex();
    ~Particle();


};


#endif //PARTICLE_PARTICLE_HPP
