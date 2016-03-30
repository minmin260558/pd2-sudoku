#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

class Sudoku{

   public:	
	Sudoku(){
	   
	   iniMap();  
	   setVariable();
	   
	}

	void iniMap(){
	   for(int i=0;i<mapSize;i++){
		  map[i] = 0;
		  keepMap[i]=0;
	   }  
	}
		
	void setVariable(){

		ansNum = 0;
		ansType = 0;//答案是哪種
		
		for(int i=0;i<9;i++){
			for(int j=0;j<10;j++){

				checkRow[i][j]=0;
				checkCol[i][j]=0;
				checkSection[i][j]=0;

			}
		}

	}
	void printOut(int a[]){
	   cout <<'\n';
	   for(int i=0;i<mapSize;i++){
		   if((i+1)%9==0)
			  cout << a[i] << '\n';
		   else
	 		  cout << a[i] << ' ';	   
	   }
	}


	void giveQuestion(){
	   iniMap();
	   map[0] = 8;
	   map[11] = 3;
	   map[12] = 6;
	   map[19] = 7;
	   map[22] = 9;
	   map[24] = 2;
	   map[28] = 5;
	   map[32] = 7;
	   map[40] = 4;
	   map[41] = 5;
	   map[42] = 7;
	   map[48] = 1;
	   map[52] = 3;
	   map[56] = 1;
	   map[61] = 6;
	   map[62] = 8;
	   map[65] = 8;
	   map[66] = 5;
	   map[70] = 1;
	   map[73] = 9;
	   map[78] = 4;
	   printOut(map);  
	
	}
	int Section(int n){
		int a;
		switch(n){
		case 0:
		case 1:
		case 2:
		case 9:
		case 10:
		case 11:
		case 18:
		case 19:
		case 20:
			   a = 0;
			   break;
		case 3:
		case 4:
		case 5:
		case 12:
		case 13:
		case 14:
		case 21:
		case 22:
		case 23:
			   a = 1;
			   break;
		case 6:
		case 7:
		case 8:
		case 15:
		case 16:
		case 17:
		case 24:
		case 25:
		case 26:
			   a = 2;
			   break;
		case 27:
		case 28:
		case 29:
		case 36:
		case 37:
		case 38:
		case 45:
		case 46:
		case 47:
			   a = 3;
			   break;
		case 30:
		case 31:
		case 32:
		case 39:
		case 40:
		case 41:
		case 48:
		case 49:
		case 50:
			   a = 4;
			   break;
		case 33:
		case 34:
		case 35:
		case 42:
		case 43:
		case 44:
		case 51:
		case 52:
		case 53:
			   a = 5;
			   break;
		case 54:
		case 55:
		case 56:
		case 63:
		case 64:
		case 65:
		case 72:
		case 73:
		case 74:
			   a = 6;
			   break;
		case 57:
		case 58:
		case 59:
		case 66:
		case 67:
		case 68:
		case 75:
		case 76:
		case 77:
			   a = 7;
			   break;
		case 60:
		case 61:
		case 62:
		case 69:
		case 70:
		case 71:
		case 78:
		case 79:
		case 80:
			   a = 8;
			   break;
	
		}
		return a;
	}


	void readIn(){
		iniMap();
		for(int i=0;i < mapSize;i++)
		cin >> map[i];
		for(int i=0;i<mapSize;i++){
			if(map[i]!=0){
				checkRow[(i/9)][map[i]] = 1;
				checkCol[(i%9)][map[i]] = 1;
				checkSection[Section(i)][map[i]] = 1;
			}
		}	

	}
	int  checkRepeat(int n,int j){ //檢查是否重複，重複回傳1
		if(checkRow[n/9][j]!=0||checkCol[n%9][j]!=0||checkSection[Section(n)][j]!=0)
			return 1;
	}
	
	void backtrack(int n){
		while(n<81 && map[n]!=0)
			n++;//如果此格已經有數字了(不是零)直接換找下個數字

		if(n == mapSize){
			if(ansType == 0){
				ansType=1;//one solution
				for(int i=0;i<mapSize;i++)
					ans[i] = map[i];
			}	
			else if(ansType == 1)
				ansType == 2;//multi solution
			return;
		}

		if(n == mapSize){
			backtrack(n);
			return;
		}	
		
		for(int j=1;j<=9;j++){
			if(ansType==2)			
			if(checkRepeat(n,j))
				continue;
			checkRow[n/9][j] = 1;
			checkCol[n%9][j] = 1;
			checkSection[Section(n)][j] = 1;
		
			map[n] = j;
			backtrack(n+1);
			if(ansType==2)
				break;//遇到多組解時往回走避免浪費時間
			map[n] = 0;
			
			checkRow[n/9][j] = 0;
			checkCol[n%9][j] = 0;
			checkSection[Section(n)][j] = 0;		

		}

	}
	void solve(){

		backtrack(0);
		if(ansType==1){
			cout <<'1'<<'\n';
			printOut(ans);
		}
		else if(ansType==2)
			cout <<"2"<<'\n';
		else
			cout <<"No Solution"<<'\n';

	}
	void cpyMap(){
		for(int i=0;i<mapSize;i++)
			transMap[i] = map[i];
	}
	void transform(){
		readIn();
		change();
		printOut(transMap);
	}
	void change(){
		srand(time(NULL));
		changeNum(rand()%9+1,rand()%9+1);
		changeRow(rand()%3,rand()%3);
		changeCol(rand()%3,rand()%3);
		rotate(rand()%101);
		flip(rand()%2);
	}
	void changeNum(int a,int b){
		cpyMap();
		for(int i=0;i<mapSize;i++){
			if(map[i]==a)
				transMap[i] = b;
			else if(map[i]==b)
				transMap[i] = a;

		}
	}
	void changeRow(int a,int b){

		cpyMap();
		if(abs(a-b) == 2){
			for(int i=0;i<27;i++)	
				swap(transMap[i],transMap[54+i]);			
			cout<<endl;
			return;
		}
		else if(a==0||b==0){
			for(int i=0;i<27;i++)
				swap(transMap[i],transMap[27+i]);
			cout<<endl;
			return;
		}
		else{
			for(int i=0;i<27;i++)
				swap(transMap[27+i],transMap[54+i]);	
			cout<<endl;
			return;
		}
	}
	void changeCol(int a,int b){
		cpyMap();
		if(abs(a-b)==2){
			for(int i=0;i<=72;i=i+9){
				swap(transMap[i],transMap[i+6]);
				swap(transMap[i+1],transMap[i+7]);
				swap(transMap[i+2],transMap[i+8]);
			}
			return;
		}

		else if(a==0||b==0){
			for(int i=0;i<=72;i=i+9){
				swap(transMap[i],transMap[i+3]);
				swap(transMap[i+1],transMap[i+4]);
				swap(transMap[i+2],transMap[i+5]);
			}
			return;
		}
		else{
			for(int i=3;i<=75;i=i+9){
				swap(transMap[i],transMap[i+3]);
				swap(transMap[i+1],transMap[i+4]);
				swap(transMap[i+2],transMap[i+5]);
			}
			return;
		}

	}
	void rotate(int n){
		cpyMap();			
		for(int i=0;i<n;i++){
			for(int k=0;k<mapSize;k++)			
				keepMap[k]=transMap[k];
			for(int j=0;j<mapSize;j++){
				if(j/9==0)
					transMap[(j+1)*9-1]=keepMap[j];
				else	
					transMap[(j-(9*(j/9)-1))*9-((j/9)+1)]=keepMap[j];
			}
		}
	}
	void flip(int n){
		cpyMap();
		if(n==1){
			for(int i=0;i<=3;i++){//中間(第4列)不用交換
				for(int j=0;j<9;j++)
					swap(transMap[(9*i)+j],transMap[9*(8-i)+j]);//第0~8列,0和8互換,1和7互換,2和6互換....	
			}
		}
		else if(n==0){
			for(int i=0;i<=3;i++){
				for(int j=0;j<9;j++)
					swap(transMap[(9*j)+i],transMap[9*j+(8-i)]);//0和8行互換,1和7互換..
			}
		}
	}

	static const int mapSize = 81;

   private:
	int transMap[mapSize];
	int map[mapSize];
	int ans[mapSize];
	int ansNum;
	int checkRow[9][10];
	int checkCol[9][10];
	int checkSection[9][10];//
	int ansType;//答案是哪種
	int rowPart[81];
	int keepMap[81];
};
int main(){
	Sudoku s1;	
	s1.giveQuestion();
	s1.rotate(3);
	
	return 0;

}
