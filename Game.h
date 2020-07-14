//
// Created by duonglh on 10/06/2020.
//

#ifndef CLION_GAME_H
#define CLION_GAME_H
#include "Bird.h"
#include "Background.h"
#include "SFML/Graphics.hpp"
#include <bits/stdc++.h>
using namespace sf;
using namespace std;
class Game {
private:
    RenderWindow *window;
    VideoMode videoM;
    Event event;
    Background background;
    Bird bird;
    Vector2f wall_up1,wall_up2,pos_bird,pos_way,size_bird;
    int size_wall,distance;
    string title;
    void initWindow();

public:
    Game();
    virtual ~Game();
    void pollEvent();
    bool running();
    void render();
    void update();
    void check();
    void getpos();
};


#endif //CLION_GAME_H
