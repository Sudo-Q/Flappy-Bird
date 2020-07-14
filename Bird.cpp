//
// Created by duonglh on 13/06/2020.
//

#include "Bird.h"

Bird::Bird() {
    this->UP.loadFromFile("../picture/bluebird-upflap.png");
    this->DOWN.loadFromFile("../picture/bluebird-downflap.png");
    this->MID.loadFromFile("../picture/bluebird-midflap.png");
    Points_tex.resize(10);
    string s;
    for(int i=0;i<10;i++){
        s="";
        s=s+"../picture/"+char(i+'0')+".png";
        Points_tex[i].loadFromFile(s);
    }
    this->direct=50;
    this->alive=true;

}
void Bird::init(RenderWindow* window) {
    this->window=window;
//    this->background.init(this->window);
    this->bird.setSize(Vector2f(65,50));
    this->bird.setPosition(Vector2f(100,100));
    this->bird.setOrigin(Vector2f(25,25));
    this->bird.setRotation(0);
}

void Bird::draw() {
    if(direct==50) {
        bird.setTexture(&UP);
        direct=0;
    }
    else if(direct==25) bird.setTexture(&MID);
    else if(direct==1) bird.setTexture(&DOWN);
    direct++;
    window->draw(bird);
}

void Bird::move() {
    float x = bird.getPosition().x;
    float y = bird.getPosition().y;
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        bird.setPosition(Vector2f(x, y - 0.05f));
        if(bird.getRotation()>=340)
            bird.setRotation(-20);
        else bird.rotate(-1);
        clock.restart();

    } else if (time>=0.5f) {
        bool dd = false;
        float e;
        if(bird.getRotation()>=340 && bird.getRotation()<=360) dd = true;
        if(dd)  e=bird.getRotation()-360;
        else e=bird.getRotation();
        if(e>=60)
            bird.setRotation(60);
        else bird.rotate(0.5f);
        bird.move(Vector2f(0, 0.05f));
    }
    else {
        bird.setRotation(0);
        bird.move(Vector2f(0, 0.03f));

    }
    this->time=this->clock.getElapsedTime().asSeconds();
}

void Bird::fly() {
    move();
    draw();
}

Vector2f Bird::getpos() {
    return bird.getPosition();
}

Vector2f Bird::getsize() {
    return bird.getSize();
}

Bird::~Bird() {

}

void Bird::die(float Y) {
    while (bird.getPosition().y<=Y) bird.move(0,0.02f);

}

void Bird::Drawpoints(int points) {
    int a=points%10;
    points/=10;
    Sprite s1,s2;
    s1.setTexture(Points_tex[points]);
    s1.setScale(Vector2f(2,3));
    s1.setPosition(Vector2f(window->getSize().x/2-25,10));
    s2.setTexture(Points_tex[a]);
    s2.setScale(Vector2f(2,3));
    s2.setPosition(Vector2f(window->getSize().x/2+25,10));
    window->draw(s1);
    window->draw(s2);






}






