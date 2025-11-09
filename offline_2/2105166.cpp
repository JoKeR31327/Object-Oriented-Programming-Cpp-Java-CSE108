#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <ctime> 

using namespace std;

#define GRIDSIZE 4
#define UP      0
#define DOWN    2
#define LEFT    3
#define RIGHT   1
#define MAX_SHOTS 3


/*string to_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}*/


class Position
{

    int x, y;

public:

    Position (int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting Position does not leave the grid
    void moveRight()
{
    if (x < GRIDSIZE - 1) {
        x++;
    } else {
        cout << "Cannot go there. Change your direction." << endl;
    }
}

void moveLeft()
{
    if (x > 0) {
        x--;
    } else {
        cout << "Cannot go there. Change your direction." << endl;
    }
}

void moveUp()
{
    if (y < GRIDSIZE - 1) {
        y++;
    } else {
        cout << "Cannot go there. Change your direction." << endl;
    }
}

void moveDown()
{
    if (y > 0) {
        y--;
    } else {
        cout << "Cannot go there. Change your direction." << endl;
    }
}


    bool isAdjacent(Position p)
    {
        if(((this->x-p.getX()==1 ||  this->x-p.getX()==-1)&&(this->y==p.getY())) || ((this->y-p.getY()==1 ||  this->y-p.getY()==-1)&&(this->x==p.getX())))return true;
        else return false;
    }

    bool isSamePoint(Position p)
    {
         if(this->x-p.getX()==0 && this->y-p.getY()==0)return true;
        else return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

};


class Wumpus
{

    bool killed;
    Position p;

public:

    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        int x,y;
        do {
        x= rand() % GRIDSIZE;
        y= rand() % GRIDSIZE;
    } while (x == 0 && y == 0);
        p = Position(x, y);
        killed = false;
    }

    void kill()
    {
        killed = true;
    }

    Position getPosition()
    {
        return p;
    }

};


class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;
    Position a;

public:

    Player()
    {
        total_shots=MAX_SHOTS;
        p=Position(0,0);
        direction=UP;
    }

    void turnLeft()
    {
        if (direction == UP) {
            direction = LEFT;
        }
        else if (direction == DOWN) {
            direction = RIGHT;
        }
        else if (direction == LEFT) {
            direction=DOWN;
        }
        else if (direction == RIGHT) {
            direction=UP;
        }
        
    }

    void turnRight()
    {
        if (direction == UP) {
            direction = RIGHT;
        }
        else if (direction == DOWN) {
            direction = LEFT;
        }
        else if (direction == LEFT) {
            direction=UP;
        }
        else if (direction == RIGHT) {
            direction=DOWN;
        }
    }

    void moveForward()
    {
        if     (direction==LEFT) p.moveLeft();
        else if(direction==RIGHT)p.moveRight();
        else if(direction==UP)   p.moveUp();
        else if(direction==DOWN) p.moveDown();

    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }
    Position shoot(){
        total_shots--;
        int a_x=p.getX();
        int a_y=p.getY();
        if(total_shots<=0){
        cout<<"no arrows left"<<endl;
        Position arrow(a_x,a_y);
        return arrow;
        }
        else{
        if     (direction==LEFT) a_x--; 
        else if(direction==RIGHT)a_x++;
        else if(direction==UP)   a_y++;
        else if(direction==DOWN) a_y--;
        Position arrow(a_x,a_y);
        return arrow;        
    }
    }
    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP) s = "up";
        if (direction == DOWN) s = "down";
        if (direction == LEFT) s = "left";
        if (direction == RIGHT) s = "right";
        return "Player is moving at direction: " + s;
    }

};



class WumpusWorld
{

private:

    Player player;
    Wumpus wumpus;
    Position gold_Position;
    Position pit;
    bool ended;

public:

    WumpusWorld()
    {
        int Wumpus_x, Wumpus_y, gold_x, gold_y, pit_x, pit_y;
        do{
        Wumpus_x= rand() % GRIDSIZE;
        Wumpus_y= rand() % GRIDSIZE;
        gold_x  = rand() % GRIDSIZE;
        gold_y  = rand() % GRIDSIZE;
        pit_x   = rand() % GRIDSIZE;
        pit_y   = rand() % GRIDSIZE;
    } while (((Wumpus_x==0 && Wumpus_y==0)||(gold_x==0 && gold_y==0)|| (pit_x==0 && pit_y==0))||
         (Wumpus_x == pit_x && Wumpus_y == pit_y) ||
         (gold_x == pit_x && gold_y == pit_y));
         wumpus=Wumpus(Wumpus_x,Wumpus_y);
         gold_Position=Position(gold_x,gold_y);
         pit=Position(pit_x,pit_y);
        
    }

    WumpusWorld(int Wumpus_x, int Wumpus_y)
    {
        wumpus=Wumpus(Wumpus_x,Wumpus_y);
    }

    WumpusWorld(int Wumpus_x, int Wumpus_y, int gold_x, int gold_y)
    {
           wumpus=Wumpus(Wumpus_x,Wumpus_y);
         gold_Position=Position(gold_x,gold_y);
    }

    WumpusWorld(int Wumpus_x, int Wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
         wumpus=Wumpus(Wumpus_x,Wumpus_y);
         gold_Position=Position(gold_x,gold_y);
         pit=Position(pit_x,pit_y);
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        Position arro=player.shoot();
        if(arro.isSamePoint(wumpus.getPosition())){
            cout << "Wumpus is killed!" << endl;
                wumpus.kill();
                wumpus=Wumpus(GRIDSIZE,GRIDSIZE);
        }
        else {cout<<"Lmao, You missed"<<endl;}
        return showGameState();
    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }

        if (player.isAdjacent(pit))
        {
            cout << "breeze!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {   
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(pit))
        {   
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_Position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }

};


int main()
{   
    srand(time(0));
    int c, Wumpus_x, Wumpus_y, gold_x, gold_y, pit_x, pit_y;
    //cin>>Wumpus_x>>Wumpus_y>>gold_x>>gold_y>>pit_x>>pit_y;
    ifstream tx;
    tx.open("input.txt");
    tx>>Wumpus_x>>Wumpus_y>>gold_x>>gold_y>>pit_x>>pit_y;
    tx.close();
    WumpusWorld w(Wumpus_x, Wumpus_y, gold_x, gold_y, pit_x, pit_y);
    WumpusWorld w;
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }
    }
    return 0;
}
