#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;
int user;
/*int data[10][10]={{0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
	              {0,0,0,0,0,0,0,0,0,0},
	   	          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0,0}
		         };*/ 
//-----------------------------------------------------
//�T�w���� 
int data[10][10]={{0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
	              {0,0,0,0,0,0,0,0,0,0},
	   	          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
		          {0,0,0,0,0,0,0,0,0,0},
			      {0,0,0,0,0,0,0,0,0,0}
		         };
//---------------------------------------------------
void setColor(int color){ //�]�w��r�C�� : 
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
} 
//----------------------------------------------------
void reset(){    //�@�}�l������ 
	user = 1;
	for(int i = 0;i<21;i++){
		for(int j=0;j<21;j++){
		//	data[i][j] = 0;
		}
	}
}
//----------------------------------------------------------------
int check_data(){ // �P�_�O�_Ĺ�C�� 
	int nCnt;
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			nCnt = 0;
			switch (data[i][j]){			
				case 0: break;
				case 1: nCnt = 0;
						for (int k=0;(k<5)&&((i+k)<10);k++){
							if (data[i+k][j]==1){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 1;
						nCnt = 0;		
						for (int k=0;(k<5)&&((j+k)<10);k++){
							if (data[i][j+k]==1){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 1;
						nCnt = 0;
						for (int k=0;(k<5)&&((j+k)<10)&&((i+k)<10);k++){
							if (data[i+k][j+k]==1){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 1;		
							break;
				case 2: nCnt = 0;
						for (int k=0;(k<5)&&((i+k)<10);k++){
							if (data[i+k][j]==2){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 2;
						nCnt = 0;		
						for (int k=0;(k<5)&&((j+k)<10);k++){
							if (data[i][j+k]==2){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 2;
						nCnt = 0;
						for (int k=0;(k<5)&&((j+k)<10)&&((i+k)<10);k++){
							if (data[i+k][j+k]==2){
								nCnt +=1;
							}
						}
						if(nCnt >= 5)
							return 2;		
							break;	
						}
			if ((nCnt == 5) && (data[i][j] ==1)){
				return 1;
			}
			if ((nCnt == 5) && (data[i][j] ==2)){
				return 2;
			}			
		}
	}
	return 0;
}
//---------------------------------------------------------------
void test(int* x){
    *x = *x + 3; 
} 
 
//------------------------------------------------------------
void new_screen(int xpos, int ypos) {   
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);//���o�ù����� 
    scrn.X = xpos, scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);//�]�w���Ъ���m 
   // HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;//���@�i��� 
    GetConsoleCursorInfo(hOuput, &CursorInfo);//���o�W����Ʃ�b���� 
    CursorInfo.bVisible = false ;//���ܪ�檺���e 
    SetConsoleCursorInfo(hOuput, &CursorInfo);//�^�Ǫ�椺�e 
}
//-------------------------------------------------------
void show_data(){  // �����M�U���Ѥl 
	new_screen(0, 0);
	setColor(7);
	cout << " _ _ _ _ _ _ _ _ _ _ " << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	cout << "|_|_|_|_|_|_|_|_|_|_|" << endl;
	for(int x=0;x<10;x++){
		for(int y=0;y<10;y++){
			switch(data[x][y]){
				case 0:	new_screen(2*y+1,x+1);
						//cout<<"_";
						break;
				case 1: new_screen(2*y+1,x+1);
						setColor(7);
						cout<<"O";
						break;		
				case 2: new_screen(2*y+1,x+1);
						setColor(7);
						cout<<"X";
						break;	
			}		
		}
	}
}
//-------------------------------------------------------
int x, y;   //���� 
void start() {
	x = 1;
	y = 1;
    char key;
    int result = 0; 
    while (true) {
    	result = 0;
        if (kbhit()) {
	        key = getch	();
	        int dx, dy;
	        if((key == 'w'||key == 'W') && x > 1){
	        	int oldx = x;
				x-=1, dx = 1, dy =0;
	        	while((data[x-1][(y-1)/2]!=0) && (x<11) && (x>0)){
	        		x-=1;
				}
				if(x>10)
					x = oldx;
			}else if((key == 'a'||key == 'A' )&& y>2  ){
				int oldy = y;
				y-=2, dx = 0, dy = 2;
				while((data[x-1][((y-1)/2)]!=0) && (y<=19)){
					y-=2;
				}
				if(y>21)
					y = oldy;
			}else if((key == 's'||key == 'S' )&& x<=9 ){
				int oldx = x;
				x+=1, dx = -1, dy = 0;
				while((data[x-1][(y-1)/2]!=0) && (x<11)){
					x+=1;
				}
				if(x>10)
					x = oldx;
				
			}else if((key == 'd'||key == 'D' )&& y<=18){
	    	    int oldy = y;
				y+=2, dx = 0, dy = -2;
				while((data[x-1][(y-1)/2]!=0) && (x<11)){
					y+=2;
				}	
				if(y>19){
					y = oldy;
				}
			}else if((key == ' ') && y<=19){
				new_screen(30,20);
				cout << "hello" ;
				if(data[x-1][(y-1)/2] == 0){
					data[x-1][(y-1)/2] = user;
					if(user == 1){
						user = 2;
					}
					else{
						user = 1;
					}
					result = check_data();
				}	
			}
	    		
				
			show_data();
			Sleep(10);	
			if( x >0 && y > 0 && x < 20 && y < 20){
		    	new_screen(y, x);
				cout<<"T";
			}
			
			//new_screen(y+dy, x+dx);
			//cout<<"_";
		//	new_screen(30,20);
		//		cout << "hello" ;
			new_screen(20, 20);
			setColor(7);
			cout << x << " "<< y << endl;
			if(user == 1){
				cout << "        " << "���a1" <<endl;
			}
			else{
				cout << "        " << "���a2" <<endl ;
			}
			if (result == 1)
				cout << "���a1Ĺ�F" << endl;
			else if(result == 2)
				cout << "���a2Ĺ�F" << endl;	 
			
	    }
	}
}
//--------------------------------------------------------------

//---------------------------------------------------------
int main (){  //�� 
/*	int aa;
	aa = 5;
	test( &aa );
	cout << aa;
	return 1;*/ 
	reset();
	//set_data();
	show_data();
	new_screen(1, 1);
	start();

}
