#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define UNASSIGNED 0
#define N 9
using namespace std;

bool FindUnassignedLocation(int grid[N][N], int &row, int &col); // To check if there is any unassaigned location in the sudoku
bool isSafe(int grid[N][N], int row, int col, int num); // To check if the value-filled is suitable or not
void printGrid(int grid[N][N]);
bool SolveSudoku(int grid[N][N]){
//	printGrid(grid);
	int row, col, num;
	if(!FindUnassignedLocation(grid, row, col))
	 return true;

	for(num=1;num<=9;num++)
	{
		if(isSafe(grid,row,col,num)){
		grid[row][col]=num; // tentative assignment
		if(SolveSudoku(grid)) return true; // successful
		grid[row][col]=UNASSIGNED;
	}
	}
	return false; // This triggers back tracking
}
bool FindUnassignedLocation(int grid[N][N], int &row, int &col){
	for(row=0;row<N;row++)
		for(col=0;col<N;col++)
			if(grid[row][col]==UNASSIGNED)
				return true;

	return false;
}
bool UsedInRow(int grid[N][N], int row, int num){
	for(int col=0;col<N;col++)
		if(grid[row][col]==num)
			return true;
	return false;
}
bool UsedInCol(int grid[N][N], int col, int num){
	for(int row=0;row<N;row++)
		if(grid[row][col]==num)
			return true;
	return false;
}
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
	for(int row=0;row<3;row++)
		for(int col=0;col<3;col++)
			if(grid[row+boxStartRow][col+boxStartCol]==num)
				return true;

	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return (!UsedInRow(grid, row, num)&& !UsedInCol(grid, col, num)&& !UsedInBox(grid, row-row%3, col-col%3, num));
}

void printGrid(int grid[N][N]){
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}

void solve()
{
   int grid[9][9];
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++ ){
			cin>>grid[row][col];
		}
	}
	if(SolveSudoku(grid)==true)
		printGrid(grid);
}

int main(){
     ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
}
