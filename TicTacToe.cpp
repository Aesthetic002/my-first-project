#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> board(3,vector<int>(3,0));
int col=board[0].size();
int row=board.size();

bool checkwin(int player){
    int score=3*player;
    if(board[0][0]+board[0][1]+board[0][2]==score||
    board[0][0]+board[1][0]+board[2][0]==score||
    board[0][0]+board[1][1]+board[2][2]==score||
    board[2][0]+board[2][1]+board[2][2]==score||
    board[2][2]+board[1][2]+board[0][2]==score||
    board[1][0]+board[1][1]+board[1][2]==score||
    board[0][1]+board[1][1]+board[2][1]==score||
    board[2][0]+board[1][1]+board[0][2]==score
    ){
        return true;
    }



    else{
        return false;
    }


}
void insert(int i ,int j,int player){
board[i][j]=player;
}
void print(){
    cout<<"___________"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==1){
                cout<<"|"<<"O"<<"|";
            }
            else if(board[i][j]==-1){
            cout<<"|"<<"X"<<"|";
            }
            else{
                cout<<"| |";
            }
        }cout<<endl;
        cout<<"__________"<<endl;
    }
}

int main(){
    int i,j;
    int player=1;
    int count=0;
    string player1,player2;
    cout<<"Enter Name of Player 1"<<endl;
    cin>>player1;
    cout<<"Enter Name of Player 2"<<endl;
    cin>>player2;
    while((!(checkwin(player)))&& count<=9){
        player*=-1;
        cout<<"Enter nth Row and mth Column"<<endl;
        cin>>i>>j;
        if(i<0||j<0||i>2||j>2){
            cout<<" Out of Bounds"<<endl;
            return 0;
        }
        insert(i,j,player); 
        print();
        count++;
    }
    if(count>9){
        cout<<"It's a draw brother"<<endl;
       
    }
    else if(player==1){
        cout<<player2<<" wins"<<endl;

    }
    else{
        cout<<player1<< " wins"<<endl;
    }
return 0;
}
