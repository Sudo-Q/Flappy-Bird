//
// Created by duonglh on 10/06/2020.
//

#include "Background.h"
Background::Background() {

    this->font.loadFromFile("../Font.ttf");
    this->texture_back.loadFromFile("../picture/background-day.png");
    texture_back.setSmooth(true);
    this->texture_wall.loadFromFile("../picture/pipe-green.png");
    this->texture_way.loadFromFile("../picture/base.png");
    this->text.setFont(font);
    this->music.openFromFile("../blackpink.ogg");
    music.setVolume(50);
    music.setLoop(true);
    music.play();
//    cout<<texture_wall.getSize().x<<' '<<texture_wall.getSize().y<<endl;
}

void Background::init(RenderWindow* window) {
    this->distance_y=150;
    this->window=window;
    this->width=window->getSize().x;
    this->height=window->getSize().y;
    this->background.setSize(Vector2f(width,height));
    this->way1.setSize(Vector2f(width,height/5));
    this->way1.setPosition(Vector2f (0,4*height/5));
    this->way2.setSize(Vector2f(width,height/5));
    this->way2.setPosition(Vector2f (0,4*height/5));
    this->setpos1();
    this->setpos2();
    this->wall_down1.setRotation(180.0f);
    this->wall_down2.setRotation(180.0f);
    this->text.setCharacterSize(20);
    this->text.setFillColor(Color::Red);
    this->text.setStyle(Text::Bold);
    this->text.setPosition(100,200);
    this->text.setString("hello");
    this->background.setTexture(&texture_back);
    this->way1.setTexture(&texture_way);
    this->way2.setTexture(&texture_way);
    this->wall_up1.setTexture(texture_wall);
    this->wall_down1.setTexture(texture_wall);
    this->wall_up2.setTexture(texture_wall);
    this->wall_down2.setTexture(texture_wall);
}

void Background::draw() {
    window->draw(background);
    window->draw(wall_down1);
    window->draw(wall_up1);
    window->draw(wall_down2);
    window->draw(wall_up2);
    window->draw(way1);
//    window->draw(text);

    wall_down1.move(Vector2f(-0.03f,0));
    wall_up1.move(Vector2f(-0.03f,0));
    wall_down2.move(Vector2f(-0.03f,0));
    wall_up2.move(Vector2f(-0.03f,0));
    wall_up3.move(Vector2f(-0.03f,0));
    way1.move(-0.03f,0);
    way2.setPosition(Vector2f(way1.getPosition().x+way1.getSize().x,way1.getPosition().y));
    window->draw(way2);
    if(way1.getPosition().x+way1.getSize().x<=0) way1.setPosition(Vector2f(0,4*height/5));
    if(wall_down1.getPosition().x<=0) setpos1();
    if(wall_down2.getPosition().x<=0) setpos2();
//    cout<<"@ "<<wall_up2.getPosition().x<<' '<<wall_up2.getPosition().y<<endl;
}

Background::~Background() {
//    music.stop();
}

void Background::setpos1() {
    srand(time(0));
    this->ran1=50+rand()%(int)(way1.getPosition().y-50-distance_y);
    this->wall_down1.setTextureRect(IntRect (0,0,texture_wall.getSize().x,ran1));
    this->wall_down1.setPosition(Vector2f(width+width/10,ran1));
    this->wall_up1.setTextureRect(IntRect (0,0,texture_wall.getSize().x,way1.getPosition().y-ran1-distance_y));
    this->wall_up1.setPosition(Vector2f(width,ran1+distance_y));
}

void Background::setpos2() {
    srand(time(0));
    ran2=ran1;
    while (ran2==ran1) this->ran2=50+rand()%(int)(way1.getPosition().y-50-distance_y);
    this->wall_down2.setTextureRect(IntRect (0,0,texture_wall.getSize().x,ran2));
    this->wall_down2.setPosition(Vector2f(wall_up1.getPosition().x+width/10+310,ran2));
    this->wall_up2.setTextureRect(IntRect (0,0,texture_wall.getSize().x,way1.getPosition().y-ran2-distance_y));
    this->wall_up2.setPosition(Vector2f(wall_up1.getPosition().x+310,ran2+distance_y));
}

Vector2f Background::getpos1() {
    return wall_up1.getPosition();
}

Vector2f Background::getpos2() {
    return wall_up2.getPosition();
}

int Background::getsizewall() {
    return texture_wall.getSize().x;
}

Vector2f Background::getway() {
    return way1.getPosition();
}

int Background::getdistance() {
    return distance_y;
}






