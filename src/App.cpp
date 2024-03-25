//
// Created by caleb on 8/19/21.
//

#include "App.hpp"

App::App() : m_dt{0.0f}, m_window{SCREEN, "Particle", sf::Style::Fullscreen}, m_particleCount(50000),
m_fullSpeed(10000), m_slowSpeed(1000)
{
    m_window.setVerticalSyncEnabled(true);
    UpdateMousePosition();
    srand(time(nullptr));

    for(int i = 0; i < m_particleCount; i++)
    {
        m_particleArray.emplace_back(&m_mousePos, &m_dt);
    }
}

App::~App() {

}

void App::Update() {
    while(m_window.isOpen()){
        UpdateDT();
        UpdateMousePosition();
        for(auto & i : m_particleArray)
            i.updateVertex();

        HandleEvents();


        Render();
    }
}

void App::Render() {
    m_window.clear();
    for(auto & i : m_particleArray)
        m_window.draw(i.GetVertex(), 1, sf::Points);
    m_window.display();
}

void App::HandleEvents() {
    for(sf::Event event; m_window.pollEvent(event);){
        if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            m_window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            for(auto & i : m_particleArray)
            {
                i.SetMaxSpeed(m_slowSpeed);
            }
        }
        else if(event.type == sf::Event::MouseButtonReleased){
            for(auto & i : m_particleArray)
            {
                i.SetMaxSpeed(m_fullSpeed);
            }
        }
    }

}



void App::UpdateDT() {
    m_dt = m_clock.restart().asSeconds();
}

void App::Run() {
    Update();
}

void App::UpdateMousePosition() {
    m_mousePos = sf::Mouse::getPosition(m_window);
}
