//
// Created by duonglh on 13/06/2020.
//

#ifndef CLION_BIRD_H
#define CLION_BIRD_H
#include "SFML/Graphics.hpp"
#include <bits/stdc++.h>
using namespace sf;
using namespace std;

class Bird {
private:
    RenderWindow* window;
    RectangleShape bird;
    Texture UP,DOWN,MID;
    int direct;
    Clock clock;
    float time;
    vector<Texture>Points_tex;
public:
    Bird();
    virtual ~Bird();
    bool alive;
    int point=0;
    void init(RenderWindow* window);
    void draw();
    void fly();
    void die(float);
    void move();
    void Drawpoints(int);
    Vector2f getpos();
    Vector2f getsize();
};


#endif //CLION_BIRD_H
