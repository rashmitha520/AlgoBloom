
//similar to floodfill
/*
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
*/
#include<bits/stdc++.h>
void print(int** s,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<s[i][j]<<" ";
        
    }
    cout<<endl;
}
void help(int maze[][20],int n,int** s,int x,int y)
{
   if(x==n-1 && y==n-1) 
   {
       s[x][y]=1;
       print(s,n);
       return;
   }
    //orientation doubt
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || s[x][y] ==1){
		return;
	}
    
    s[x][y]=1;
    help(maze,n,s,x-1,y);
    help(maze,n,s,x+1,y);
    help(maze,n,s,x,y-1);
    help(maze,n,s,x,y+1);
    s[x][y]=0;
}
void ratInAMaze(int maze[][20], int n){

 int** s=new int*[n];
    for(int i=0;i<n;i++)
        s[i]=new int[n];
    help(maze,n,s,0,0);


}


