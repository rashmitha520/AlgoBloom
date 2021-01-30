
/*In Domino Solitaire, you have a grid with two rows and N columns. Each square in the grid contains an integer A. You are given a supply of rectangular 2 × 1 tiles, each of which exactly covers two adjacent squares of the grid. You have to place tiles to cover all the squares in the grid such that each tile covers two squares and no pair of tiles overlap.

The score for a tile is the diﬀerence between the bigger and the smaller number that are covered by the tile. The aim of the game is to maximize the sum of the scores of all the tiles. 

Here is an example of a grid, along with two different tilings and their scores.The score for Tiling 1 is 12 = (9 − 8) + (6 − 2) + (7 − 1) + (3 − 2) while the score for Tiling 2 is 6 = (8 − 6) + (9 − 7) + (3 − 2) + (2 − 1). There are other tilings possible for this grid, but you can check that Tiling 1 has the maximum score among all tilings. Your task is to read the grid of numbers and compute the maximum score that can be achieved by any tiling of the grid.


Your task is to read the grid of numbers and compute the maximum score that can be achieved by any tiling of the grid.*/
#include <iostream>
#include<stdio.h>
using namespace std;
inline int input()
{
    register char c;
    do{
        c=getchar_unlocked();
    }while(c>'9'||c<'0');
    int x=0;
     do{
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
        
    }while(c<='9'&& c>='0');
    return x;
    
}
int main() {
	// your code goes here
		std::ios::sync_with_stdio(false);
	int n=input();
	n++;
	int f[n],l[n];
	for(int i=1;i<n;i++)
	 f[i]=input();
	
	for(int i=1;i<n;i++)
	 l[i]=input();
	
	int s=0,p=0;
	f[0]=f[1];
	l[0]=l[1];
	for(int i=1;i<n;i++ )
	{
	    int h=abs(f[i]-l[i]);
	    int v=abs(f[i]-f[i-1])+abs(l[i]-l[i-1]);
	    int k=max(h+s,v+p);
	    p=s;
	    s=k;
	    
	}
	cout<<s<<endl;
	//return 0;
}
