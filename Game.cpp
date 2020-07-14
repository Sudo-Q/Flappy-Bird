//
// Created by duonglh on 10/06/2020.
//

#include "Game.h"

Game::Game() {
    this->videoM.height=900;
    this->videoM.width=600;
    this->title="Demo Game";
    this->initWindow();
    this->background.init(this->window);
    this->bird.init(this->window);
    this->pos_way=background.getway();
    this->size_wall=background.getsizewall();

}

Game::~Game() {
    delete this->window;
}
//khởi tạo cửa sổ:
void Game::initWindow() {
    this->window=new RenderWindow(videoM,title);
}

void Game::pollEvent() {
    while (this->window->pollEvent(event)){
        if(this->event.type==Event::Closed)
            this->window->close();
    }
}
//update vị trí của chim và ông nước:
void Game::update() {
    pollEvent();
    getpos();
    check();
}
//ham vẽ:
void Game::render() {
    this->window->clear();
    background.draw();
    bird.fly();
    bird.Drawpoints(bird.point);
    this->window->display();
}

bool Game::running() {
    return this->window->isOpen();
}
//lấy vị trí của chim và ông nước:
void Game::getpos() {
    this->wall_up1=background.getpos1();
    this->wall_up2=background.getpos2();
    this->distance=background.getdistance();
    this->pos_way=background.getway();
    this->pos_bird=bird.getpos();
    this->size_bird=bird.getsize();
}
//kiểm tra xem chim có chết:
void Game::check() {
    if(pos_bird.y+size_bird.y>=pos_way.y+10) bird.alive = false;
    if(pos_bird.y>wall_up1.y-distance+5 && pos_bird.y+size_bird.y<wall_up1.y+25 ){
        if(pos_bird.x>=wall_up1.x+size_wall && pos_bird.x-0.02<=wall_up1.x+size_wall)
        {
            bird.point++;
//            cout<<bird.point<<endl;
        }
    }
    else if(pos_bird.x+size_bird.x/4 >= wall_up1.x &&  pos_bird.x+size_bird.x/4<=wall_up1.x+size_wall ) bird.alive = false;
    else if(pos_bird.x>=wall_up1.x && pos_bird.x<=wall_up1.x) bird.alive=false;
//    else if(pos_bird.x+size_bird.y/4 >= wa ll_up1. &&  pos_bird.x+size_bird.x/4<=wall_up1.x+size_wall ) bird.alive = false;

    if(pos_bird.y>wall_up2.y-distance+5 && pos_bird.y+size_bird.y<wall_up2.y+25){
        if(pos_bird.x>=wall_up2.x+size_wall && pos_bird.x-0.02<=wall_up2.x+size_wall) {
            bird.point++;
//            cout<<bird.point<<endl;
        }
    }
    else if(pos_bird.x+size_bird.x/4 >= wall_up2.x &&  pos_bird.x+size_bird.x/4<=wall_up2.x+size_wall)
           bird.alive = false;
    else if(pos_bird.x>=wall_up2.x && pos_bird.x<=wall_up2.x) bird.alive=false;

    if(bird.alive == false) {
        sleep(seconds(1));
        window->close();
    }

}





