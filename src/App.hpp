//
// Created by caleb on 8/19/21.
//

#ifndef PARTICLE_APP_HPP
#define PARTICLE_APP_HPP
#include "includes.hpp"
#include "Particle.hpp"
#include <array>
#include <ctime>
class App {

private:

    sf::RenderWindow m_window;

    sf::Clock m_clock;
    float m_dt;

    int m_particleCount;

    float m_fullSpeed;
    float m_slowSpeed;


    sf::Vector2i m_mousePos;

    std::vector<Particle> m_particleArray;

    void Render();
    void HandleEvents();
    void Update();
    void UpdateDT();
    void UpdateMousePosition();

public:
    App();

    ~App();

    void Run();

};


#endif //PARTICLE_APP_HPP
