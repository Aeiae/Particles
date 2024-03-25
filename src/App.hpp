//
// Created by caleb on 8/19/21.
//

#ifndef PARTICLE_APP_HPP
#define PARTICLE_APP_HPP
#include "includes.hpp"
#include "Particle.hpp"
#include <array>
#include <ctime>
#include <thread>

struct Thr {
    std::thread* thread;
    sf::Clock clock;
    float dt;
};


class App {

private:

    sf::RenderWindow m_window;

    sf::Clock m_clock;
    float m_dt;

    const int m_particleCount;
    const int m_threadCount{};

    float m_fullSpeed;
    float m_slowSpeed;


    sf::Vector2i m_mousePos;

    std::vector<Particle> m_particleArray;
    std::vector<Thr> m_threads;

    std::thread thread;

    void Render();
    void HandleEvents();
    void Update();
    void UpdateDT();
    void UpdateMousePosition();
    void MultithreadUpdate(int threadNum);

public:
    App();

    ~App();

    void Run();

};


#endif //PARTICLE_APP_HPP
