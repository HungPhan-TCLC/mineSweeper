#include <bits/stdc++.h>
using namespace std;


int K,maxcol,maxrow;
int p[1000][1000];
int opened[1000][1000];

void input(){
	for(int i=0;i<maxrow;i++){
		for(int j=0;j<maxcol;j++){
			p[i][j]=0;
			opened[i][j]=0;
		}
	}
}

// count the bom around
int mi_count(int row, int col){
  int near_minum = 0; 
  
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (row + i >= 0 && row + i <= maxrow && col + j >= 0 && col + j <= maxcol && i!=0 && j!=0){
        if (p[row + i][col + j] == 1)
        	near_minum += 1;
      }
    }
  }

  return near_minum;
}

// function creates bom
void gen_mine(){
  time_t t;
  int iminum = 0; // the number bom set up
  srand((unsigned) time(&t));
  while (iminum < K) { 
    p[rand()%maxrow][rand()%maxcol]=1;	
    iminum += 1;
    }
}
void output1(){
	for(int i=0;i<maxrow;i++){
		for(int j=0;j<maxcol;j++){
			cout<<p[i][j]<<' ';
		} cout<<endl;
	}
}
void output2(){
	for(int i=0;i<maxrow;i++){
		for(int j=0;j<maxcol;j++){
			cout<<opened[i][j]<<' ';
		} cout<<endl;
	}
}
int main(){
	cin>>maxrow>>maxcol>>K;
	input();
	gen_mine();
	bool fail=false;
	int x,y;
	do{
		cin>>x>>y;
		if(p[x][y]==1) {
			fail==true;
			cout<<"YOU'RE DEAD!"<<endl;
			output1();	
			break;
		} else {
			opened[x][y]=mi_count(x,y);
			output2();
		}
	} while (fail==false);
}
