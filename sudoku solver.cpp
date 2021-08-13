#include <bits/stdc++.h>
using namespace std;

bool is_possible(int board[9][9],int i, int j, int num){
	for(int a=0;a<9;a++){
		if(board[i][a]==num){return false;}
	}
	for(int a=0;a<9;a++){
		if(board[a][j]==num){return false;}
	}
	int r=i-i%3;
	int c=j-j%3;
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			if(board[a+r][b+c]==num){return false;}
		}
	}
	return true;
}

void solve(int board[9][9],int r, int c){
	int check=0;
	while(r<9){
		while(c<9){
			if(board[r][c]==0){check++;break;}
			c++;
		}
		if(check!=0){break;}
		r++;
		if(r<9){c=0;}
	}
	if(r!=9 && c!=9){
		for(int num=1;num<=9;num++){
			if(is_possible(board,r,c,num)){
				board[r][c]=num;
				solve(board,r,c);
				board[r][c]=0;
			}
		}
	}
	else if(r==9 && c==9){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<board[i][j]<<' ';
			}cout<<endl;
		}
	}
}

int main() {
	freopen("sudoku_input.txt","r",stdin);
	int board[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>board[i][j];
		}
	}
	solve(board,0,0);
	return 0;
}


/*

ZEROES DENOTE BLANKS

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/