//
// Created by caleb on 8/19/21.
//

#include "App.hpp"

App::App() : m_dt{0.0f}, m_window{SCREEN, "Particle", sf::Style::Fullscreen}, m_particleCount(200000),
m_fullSpeed(2000), m_slowSpeed(1000), m_threadCount(1)
{
    m_window.setVerticalSyncEnabled(true);
    UpdateMousePosition();
    srand(time(nullptr));

    //std::thread thread(MultithreadUpdate, this, 0);




    Thr thr;
    for(int i = 0; i < m_threadCount; i++)
    {

        thr.dt = 0;
        for(int j = m_particleCount/m_threadCount * i; j < m_particleCount/m_threadCount * (i+1); j++)
        {
            m_particleArray.emplace_back();
        }



    }
    for(int i = 0; i < m_threadCount; i++)
    {
        thr.thread = new std::thread{MultithreadUpdate, this, i};
        m_threads.emplace_back(thr);
    }
}
App::~App() {

}

void App::Update() {
    while(m_window.isOpen()){
        UpdateDT();


        /*
        for(auto & i : m_particleArray)
            i.updateVertex();
        */

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
            for(auto& thr : m_threads)
            {
                thr.thread->join();
            }
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

void App::MultithreadUpdate(int threadNum)
{

    while(m_window.isOpen())
    {
        UpdateMousePosition();
        for(int i = m_particleCount/m_threadCount * threadNum; i < m_particleCount/m_threadCount * (threadNum + 1); i++)
        {
            m_particleArray[i].updateVertex(m_threads[threadNum].dt, m_mousePos);
        }
        m_threads[threadNum].dt = m_threads[threadNum].clock.restart().asSeconds();
    }
}
