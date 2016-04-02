#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
using namespace std;
class Sudoku{
	public:
		Sudoku();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void iniMap();
		void setVariable();
		int Section(int n);
		int checkRepeat(int n,int j);
		void backtrack(int n);
		void cpyMap();
		void change();
		void printOut(int a[]);
		int possible();
		int pos(int i);
		int checkErr();
		static const int mapSize=81;
	private:
		int done;		
		int map[mapSize];
		int ans[mapSize];
		int ansNum;
		int checkRow[9][10];
		int checkCol[9][10];
		int checkSection[9][10];
		int ansType;
		int keepMap[81];
};


