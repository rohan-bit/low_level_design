// design a tic - tac -toe 2 player game .

// point in consideration.
/*
    1. 2 player game.
    2. player info will stored.
    3. not a timed event .
    4. toss to start game wheter to give cross or zero.
*/

#include <bits/stdc++.h>

using namespace std;

class Player{
    private :
        int id;
        string fname;
        string lname;
        int win;
        int loss;
        int draw;
    public :
        Player(int id,string fname,string lname){
            this->id = id;
            this->fname = fname;
            this->lname = lname;
            win=0;
            loss=0;
            draw=0;
        }
    
};

class Board
{
    int game_board[3][3];
    public :
    Board()
    {
        memset(game_board,-1,sizeof(game_board));
    }
    int change(int x,int y,int t)
    {
        if(x>=0 && y>=0 && x<3 && y<3 && game_board[x][y]==-1 && t>=0 && t<2)
            {
                game_board[x][y]=t;
                return 0;
            }
        else
            return -1;
    }
};

class Game{
    public :
    int row[3];
    int col[3];
    int d1,d2;
    int curr;
    Board *b1;
    Player *p1,*p2;
    
    Game(Player *p1,Player *p2)
    {
        b1 = new Board();
        this->p1 = p1;
        this->p2 = p2;
        d1=0;
        d2=0;
        curr =-1;
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
    }
    ~Game()
    {
        delete b1;
        delete p1;
        delete p2;
    }
    int toss()
    {   if(curr==-1)
            { 
              curr = rand()%2;
              return curr;
            }
        else
        {
            return 2;
        }
    }
    // getter function
    int whose_chance()
        {
            return curr; 
        }
    void make_move(int x,int y)
    {   
        
        if(b1->change(x,y,curr)==0)
            {   int val=0;
                if(curr==0)
                    {
                        val+=1;
                    }
                else
                    {
                        val-=1;
                    }
                row[x]+=val;
                col[y]+=val;
                if(x==y)
                    d1+=val;
                if((x+y)==2)
                    d2+=val;
                ++curr;
                curr%=2;
            }
        else
            {
                cout<<"INVALID MOVE"<<'\n';
                return ;
            }
        
    }
    // 0 - player1 , 1-player2 ,3-draw,4-inprogress
    int status()
        {
            for(int i=0;i<3;i++)
                {
                    if(row[i]==3 || col[i]==3)
                        {   
                            return 0;
                        }
                    if(row[i]==-3 || col[i]==-3)
                        return 1;
                }
            if(d1==3 || d2==3)
                return 0;
            if(d1==-3 || d2==-3)
                return 1;
            // draw
            bool dr=true;
            
            for(int i=0;i<3;i++)
                {
                    if(!(row[i]==1 || row[i]==-1))
                        {
                            dr=false;
                        }
                    if(!(col[i]==1 || col[i]==-1))
                        dr=false;
                }
            if(!(d1==1 || d1==-1))
                dr=false;
            if(!(d2==1 || d2==-1))
                dr=false;
            if(dr==true)
               return 3;
            return 4;
        }
    
};

int main()
{   Player *p1 = new Player(1,"Rohan","Talwar");
    Player *p2 = new Player(2,"rt","xy");
    Game* g = new Game(p1,p2);
    int x,y;
    int i=5;
    g->toss();
    while((g->status()==3 || g->status()==4))
        {
                    cin>>x>>y;
                    g->make_move(x,y);
        }
    cout<<g->status()<<'\n';
    return 0;
}
