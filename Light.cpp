//
// Created by ant on 17/10/16.
//

#include <iostream>
#include "Light.h"
#include <random>
Light::Light(sf::Vector2f pos, float rad_min, float rad_max, float exp, sf::Color c) {
    position=pos;
    radius_max = rad_max;
    radius_min = rad_min;
    expand = exp;
    color = c;
    radius = radius_min;
}

Light::~Light()
{
    //std::for_each(_gameObjects.begin(),_gameObjects.end(),GameObjectDeallocator());
}
void Light::Update(float deltatime){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni((int)radius_min,(int)radius_max); // guaranteed unbiased

    auto random_integer = uni(rng);
    radius = random_integer;
    /*
    int direction = rand()%(1-0 + 1);
    if(direction==0 && radius>radius_min)radius -= deltatime*10;
    else if(direction==0)radius += deltatime;
    else if(direction==1 && radius<radius_max)radius += deltatime*10;
    else if(direction==1)radius -= deltatime;
     */
}