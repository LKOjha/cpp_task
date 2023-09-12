#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameOver;

const int width = 20;
const int height = 20;
                   
int x, y, fruitX, fruitY, score;

enum eDirection
{
    stop = 0,
    LEFT,  //a
    RIGHT, //d
    UP,    //w
    DOWN   //s
};

eDirection dir;

void setup()
{
    gameOver = false;
    dir = stop;
    x = width ;      //this is for head part location
    y = height ;     //this is for head part location

    fruitX = rand() % width;    //this is for fruit location
    fruitY = rand() % height;   //this is for fruit location

    score = 0;
}

// this function provide the connection between keyboard and the program 
void input()

{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void display()
{   
    system("cls");

    for (int i = 0; i <= width + 2; i++)
    { // for upper wall 
		cout << "#";
	}
	cout << endl;

    for (int i = 0; i<=height; i++)   // for verticle row and column 
	{
		for(int j = 0; j <= width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}

            if (i == y && j == x)  // it will print the head of the snake
			{
				cout << "O";
			}
            
            else if (j == fruitX && i == fruitY) // it will print the fruit randomly
            {
				cout << "*";
			}

            if(j == width)
			{
				cout << "#";
			}
            else 
            {
                cout << " ";
            }
		}
		cout << endl;
	} // ---------> For loop end 

	for (int i = 0; i <= width+2; i++) // for lower wall 
	{
		cout << "#";
	}
	cout << endl;
}

void logic()
{

}
int main()
{
    setup();
    input();
    display();
    
    return 0;
}