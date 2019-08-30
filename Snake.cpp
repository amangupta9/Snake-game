#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>

using namespace std;


int width=40,height=20;
int x,y,fruit_x,fruit_y,score,flag;
int snake_x[500],snake_y[500],length=1;
bool game_over;

void setup()
{
    x=width/2;
    y=height/2;
    snake_x[0]=x;
    snake_y[0]=y;
    score=0;
    game_over=0;
    label1:
        fruit_x=rand()%width;
        if (fruit_x==0)
            goto label1;
    label2:
        fruit_y=rand()%height;
        if (fruit_y==0)
            goto label2;
}

void display()
{
    cout<<endl<<"\t\t\t\tSnake Game"<<endl<<endl;
    cout<<"\t\tScore : "<<score<<endl;
    cout<<"For closing the game press x."<<endl<<endl;
    for (int i=0;i<width;i++)
        cout<<"&";
    cout<<endl;
    for (int i=0;i<height;i++)
    {
        int check=0;
        cout<<"&";
        for (int j=0;j<width-2;j++)
        {
            int check=0;
            if (i==y && j==x)
                cout<<"O";
            else if (i==fruit_y && j==fruit_x)
                cout<<"F";
            else
            {
                for (int k=1;k<length;k++)
                {
                    if (i==snake_y[k] && j==snake_x[k])
                    {
                        cout<<"o";
                        check=1;
                        break;
                    }
                }
                if (check==0)
                    cout<<" ";
            }
        }
        cout<<"&"<<endl;
    }
    for (int i=0;i<width;i++)
        cout<<"&";
}

void input()
{
    if (kbhit()) // checking whether there is input from keyboard.
    {
        switch(getch())
        {// By using getch() we are getting the command entered by user.
        case 'a':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'd':
            flag=3;
            break;
        case 'w':
            flag=4;
            break;
        case 'x':
            game_over=1;
            break;
        default:
            break;
        }
    }
}

void logic()
{
    switch(flag)
    {
    case 1:
        x--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x++;
        break;
    case 4:
        y--;
        break;
    default:
        break;
    }
    if (x<-1 || x>=width-1 || y<-2 || y>height)
        game_over=1;
    if (x==fruit_x && y==fruit_y)
    {
        fruit_x=rand()%width;
        fruit_y=rand()%height;
        length++;
        score=score+10;
    }
    // Code to make snake look like moving.
    int prev_x1=snake_x[0],prev_y1=snake_y[0];
    int prev_x2,prev_y2;
    snake_x[0]=x;
    snake_y[0]=y;
        for (int i=1;i<length;i++)
        {
            prev_x2=snake_x[i];
            prev_y2=snake_y[i];
            snake_x[i]=prev_x1;
            snake_y[i]=prev_y1;
            prev_x1=prev_x2;
            prev_y1=prev_y2;
        }
}

int main()
{
    setup();
    while (game_over==0)
    {
        system("cls");
        display();
        input();
        logic();
        for (int i=0;i<5000;i++)
        {
            for (int j=0;j<10000;j++)
            {

            }
        }//to slow speed.
    }
    return 0;
}
