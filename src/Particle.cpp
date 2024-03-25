//
// Created by caleb on 8/19/21.
//

#include "Particle.hpp"

Particle::Particle() : speed{10000}, maxSpeed{10000}, velocity(0,0), PI{3.14159}{

    vertex.position = sf::Vector2f(rand() % SCREEN.width, rand() % SCREEN.height);
    //vertex.color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
    vertex.color = sf::Color(	255, 165, 0);

}

Particle::~Particle() {

}

void Particle::Move(float XOffset, float YOffset) {
    vertex.position = sf::Vector2f(vertex.position.x + XOffset, vertex.position.y + YOffset);
}

void Particle::determineVelocity(const sf::Vector2i& mousePos) {

    angle = atan2(mousePos.y - vertex.position.y, mousePos.x - vertex.position.x);
    velocity += sf::Vector2f((std::cos(angle) * PI / 180) * speed, (std::sin(angle) * PI / 180) * speed);
    if(abs(velocity.x) > maxSpeed)velocity.x = maxSpeed * (velocity.x/abs(velocity.x));
    if(abs(velocity.y) > maxSpeed)velocity.y = maxSpeed * (velocity.y/abs(velocity.y));
}

const sf::Vertex* Particle::GetVertex() const {
    return &vertex;
}

void Particle::updateVertex(float dt, const sf::Vector2i& mousePos) {
    determineVelocity(mousePos);
    Move(velocity.x * dt, velocity.y * dt);
}

void Particle::SetMaxSpeed(float maxSpeed) {
    Particle::maxSpeed = maxSpeed;
}
