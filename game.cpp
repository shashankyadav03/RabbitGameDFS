#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void printGame(int,vector<vector<char>>);

bool checkpath(int n,vector<vector<char>> game,int r,int c){
	if(r<0||c<0||r>=n||c>=n)
	    return 0;
	else if(game[r][c]=='X'||game[r][c]=='*')
	    return 0;
	else
		return 1;
	
 
}
 
bool dfs(int n,vector<vector<char>> &game,int r,int c){
	if(!checkpath(n,game,r,c))
		return 0;
	if(game[r][c]=='C')
	    return 1;
	game[r][c]='*';
	bool ans=0;
	ans=dfs(n,game,r+1,c);
	if(ans){
		game[r+1][c]='v';
		return 1;
	}
	
	ans=dfs(n,game,r,c+1);
	if(ans){
		game[r][c+1]='>';
		return 1;
	}
	ans=dfs(n,game,r-1,c);
	if(ans){
		game[r-1][c]='^';
		return 1;
	}
	ans=dfs(n,game,r,c-1);
	if(ans){
		game[r][c-1]='<';
		return 1;
	}
	
	return ans;
 
}
 
void printGame(int n,vector<vector<char>> game){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<" "<<game[i][j]<<" ";
		}
		cout<<endl;
	}
}
 
void fillgame(int n,vector<vector<char>> &game,int r,int c){
	for(int i=0;i<n;i++){
		int ran=n/2;
			while(ran>0){
				int obs=rand()%n;
				if(checkpath(n,game,i-1,obs+1)||i==0)
				game[i][obs]='X';
				ran--;
		}
	}
	game[r][c]='R';
	game[n-1][n-1]='C';
}
void Game(int n){
	vector<vector<char>> game(n);
	for (int i = 0 ; i < n ; i++)
		game[i].resize(n,'_');
	int i=0,c=0;
	fillgame(n,game,0,0);
	printGame(n,game);
	vector<vector<char>>game1=game;
	int result=0;
	while(!result){
	cout<<"Which way to go please choose (r(right) or l(left) or u(up) or d(down) or e(exit)):\n";
	char w;
	cin>>w;
	game[i][c]='*';
	result=1;
	switch(w){
		case 'd':
		if(checkpath(n,game,i+1,c)){
			i++;
			result=0;
			if(game[i][c]=='C'){
			cout<<"\n\n\n\n\n\nHurray! you won \n\n\n\n\n\n\n";
			return;
			}
			game[i][c]='R';
		}
		break;
		case 'r':
		if(checkpath(n,game,i,c+1)){
		c++;
		
		result=0;
		if(game[i][c]=='C'){
			cout<<"\n\n\n\n\n\nHurray! you won\n\n\n\n\n\n\n";
			return;
			}
			game[i][c]='R';
		}
		break;
		case 'u':
		if(checkpath(n,game,i-1,c)){
		i--;
		
		result=0;
		if(game[i][c]=='C'){
			cout<<"\n\n\n\n\n\nHurray! you won\n\n\n\n\n\n\n";
			return;
			}
			game[i][c]='R';
		}
		break;
		case 'l':
		if(checkpath(n,game,i,c-1)){
		c--;
		
		result=0;
		if(game[i][c]=='C'){
			cout<<"\n\n\n\n\n\nHurray! you won!!!\n\n\n\n\n\n";
			return;
			}
			game[i][c]='R';
		}
		break;
		case 'e':
		cout<<"\n\n\n\n\n\nexiting...\n\n\n\n\n\n\n";
		return;
		default:
		game[i][c]='R';
		result=0;
		cout<<"wrong choice, try again \n";
	}
	printGame(n,game);
	}
	if(result==1){
	cout<<"\n\n\nyou lost. Correct path is: \n";
	game=game1;
	if(dfs(n,game,0,0)){
	    game[n-1][n-1]='R';
		printGame(n,game);
	}
	else
	cout<<"\n\nNo path exist\n\n";
}
	
}
int main() {
	cout<<"Welcome to the Help the Rabbit Game\n";
	char playAgain='y';
	while(playAgain=='y'){
		int n=rand()%15+3;
		Game(n);
		cout<<"\n\n\nWanna play again? (y/n)\n";
		cin>>playAgain;
		cout<<endl;
	}
	return 0;
}
