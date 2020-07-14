//
// Created by duonglh on 10/06/2020.
//

#ifndef CLION_BACKGROUND_H
#define CLION_BACKGROUND_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
using namespace std;
class Background {
private:
    int height,width,distance_y,ran1,ran2;
    Sprite wall_up1,wall_up2,wall_up3;
    Sprite wall_down1,wall_down2;
    RectangleShape background;
    RectangleShape way1,way2;
    RenderWindow* window;
    Texture texture_back;
    Texture texture_wall;
    Texture texture_way;
    Vector2f e;
    Font font;
    Text text;
    Music music;

public:
    Background();
    virtual ~Background();
    void init(RenderWindow* window);
    void draw();
    void setpos1();
    void setpos2();
    Vector2f getway();
    int getsizewall();
    int getdistance();
    Vector2f getpos1();
    Vector2f getpos2();




};


#endif //CLION_BACKGROUND_H
