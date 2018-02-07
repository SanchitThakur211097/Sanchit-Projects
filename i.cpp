#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;
bool gameover;
const int width = 70;
const int height = 20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100],nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void setup(){
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void draw(){
    system("cls");
    for(int i=0;i<width;i++){
       cout<<"!";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0||j==(width-1)){
               cout<<"!";
            }

            if(i == y && j == x){
                cout<<"#";
            }
            else if(i == fruitY && j == fruitX){
                cout<<"f";
            }
            else{
                    bool print=false;
                    for(int k=0;k < nTail; k++){
                        if(tailX[k]==j&&tailY[k]==i){
                            cout<<"*";
                            print=true;
                        }
                    }
            if(!print){
                        cout<<" ";
                    }
            }
        }
        cout<<endl;
    }

    for(int i=0;i<width;i++){
        cout<<"!";
    }
    cout<<endl;
   
    cout<<"        score : "<<score<<endl;
}

void input(){
    if(_kbhit()){
        switch(getch()){
        case 'a':
            dir=LEFT;
            break;
        case 's':
            dir=DOWN;
            break;
        case 'd':
            dir=RIGHT;
            break;
        case 'w':
            dir=UP;
            break;
        case 'x':
            gameover=true;
            break;
        }
    }
}

void logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;

    for(int i=1;i < nTail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(dir){
    case LEFT:
        x--;
        draw();
        break;
    case RIGHT:
        x++;
        draw();
        break;
    case UP:
        y--;
        draw();
        break;
    case DOWN:
        y++;
        draw();
        break;
    }
    if(x>=width || x <0 || y >= height || y <0){
        gameover=true;
    }
    for(int i=0;i<nTail;i++){
        if(tailX[i]==x&&tailY[i]==y)
            gameover=true;
    }
    if(x == fruitX && y == fruitY){
        score+=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main()
{
    setup();
    draw();
    while(!gameover){
        input();
        logic();
        Sleep(100);
    }
    getch();
    return 0;
}
