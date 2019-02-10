#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int n;
bool chessBoard[MAX][MAX];

bool safeOrNot(int row,int column){
    for(int i=column-1;i>=0;i--) if(chessBoard[row][i]) return false;
    for(int i=row-1,j=column-1;i>=0 and j>=0;i--,j--) if(chessBoard[i][j]) return false;
    for(int i=row+1,j=column-1;i<n and j>=0;i++,j--) if(chessBoard[i][j]) return false;
    return true;
}

bool nQueen(int pos){
    if(pos==n) return true;
    for(int i=0;i<n;i++){
        if(safeOrNot(i,pos)){
            chessBoard[i][pos] = true;
            if(nQueen(pos+1)) return true;
            chessBoard[i][pos] = false;
        }
    }
    return false;
}

void line(){
    for(int i=0;i<n;i++) printf("----");
    printf("\n");
}

void printBoard(){
    line();
    for(int i=0;i<n;i++){
        printf("|");
        for(int j=0;j<n;j++){
            if(chessBoard[i][j]) printf(" Q |");
            else printf("   |");
        }
        printf("\n");
        line();
    }
}

int main(){
    memset(chessBoard,false,sizeof(chessBoard));
    scanf("%d",&n);
    if(nQueen(0)) printBoard();
    else printf("Solution does not exist\n");
    return 0;
}
