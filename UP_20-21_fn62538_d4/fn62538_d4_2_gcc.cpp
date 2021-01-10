/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Teodora Petkova
* @idnumber 62538
* @task 2
* @compiler GCC
*
*/
#include<iostream>
using namespace std;

struct Board
{
    int m;
    int n;
    bool board[200][200]={{false}};
    Board()
    {
        m=0;
        n=0;
    }
    Board(int _m,int _n)
    {
        m=_m;
        n=_n;
    }
};
Board play;
struct Point
{
    int x;
    int y;
    Point(int _y,int _x)
    {
        y=_y;
        x=_x;
    }
    Point()
    {
        x=0;
        y=0;
    }
};
Point* hourseMove(int startY,int startX)
{
    static Point posibleMoves[8];
    posibleMoves[0]= Point(startY-2,startX-1);
    posibleMoves[1]= Point(startY-2,startX+1);
    posibleMoves[2]= Point(startY-1,startX-2);
    posibleMoves[3]= Point(startY-1,startX+2);
    posibleMoves[4]= Point(startY+1,startX-2);
    posibleMoves[5]= Point(startY+1,startX+2);
    posibleMoves[6]= Point(startY+2,startX-1);
    posibleMoves[7]= Point(startY+2,startX+1);
    return posibleMoves;
}

void print(Point a)
{
    cout<<"("<<a.y<<";"<<a.x<<")";
}

void printB(Board a)
{
    for(int i=0; i<a.m; i++)
    {
        for(int j=0; j<a.n; j++)
        {
           cout<<a.board[i][j];
        }
        cout<<endl;
    }
}

void posibleMoves(int _y,int _x)
{
    Point* a;
    a=hourseMove(_y,_x);
    for(int i=0; i<8; i++)
    {
        if(a[i].x>=0&&a[i].y>=0)
        {
            if(a[i].x<play.n&&a[i].y<play.m)
            {
                play.board[a[i].y][a[i].x]=1;
//                cout<<"Posible Points at ("<<_y<<";"<<_x<<"): \n";
//                print(a[i]);
//                cout<<endl;
            }
        }
    }
}

void updateBoard()
{
    Board currentBoard=play;
    for(int i=0; i<play.m; i++)
    {
        for(int j=0; j<play.n; j++)
        {
            if(currentBoard.board[i][j]==1)
            {
                posibleMoves(i,j);
            }
        }
    }
}

bool canMoveToFinish(int k,int finishX,int finishY)
{
    if(k==0)
    {
        return play.board[finishY][finishX];
    }
    updateBoard();
//    printB(play);
//    cout<<endl;
    return canMoveToFinish(k-1,finishX,finishY);
}


int main()
{
    //input
    int oX=0,oY=0,startX=0,startY=0,finishX=0,finishY=0,numOfMoves=0;
    cin>>oY>>oX;
    if(oY<3||oX<3||oY>200||oX>200){cout<<-1;return 0;}
    cin>>startY>>startX;
    if(oX<startX||oY<startY){cout<<-1;return 0;}
    cin>>finishY>>finishX;
    if(oX<finishX||oY<finishY){cout<<-1;return 0;}
    cin>>numOfMoves;
    if(numOfMoves>30 || numOfMoves<0){cout<<-1;return 0;}
// int oX=8,oY=6,startX=2,startY=1,finishX=0,finishY=3,numOfMoves=2;
    play=Board(oY,oX);
    play.board[startY][startX]=1;
//    printB(play);
//    cout<<endl;
    //output
    if(canMoveToFinish(numOfMoves,finishX,finishY)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    return 0;
}
