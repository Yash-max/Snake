#define UNICODE
#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;
int nScreenWidth=80;
int nScreenHeight=80;
struct sSnakeSegment{
  int x,y;
};
int main(){

  wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
  for(int i=0;i < nScreenWidth*nScreenHeight;i++) screen[i]=L' ';
  HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE , 0 , NULL , CONSOLE_TEXTMODE_BUFFER , NULL);
  SetConsoleActiveScreenBuffer(hConsole);
  DWORD dwBytesWritten=0;
  list <sSnakeSegment> snake = {{50,10},{51,10},{52,10},{53,10},{54,10},{55,10}};
  bool bdead = false;
  bool bleft=false,bleftOld=false,bright=false,brightOld=false;
  int nfoodX=30,nFoodY=10;
  while(1){

    bleft = (0x8000);

    for(int i=0;i < nScreenWidth*nScreenHeight;i++) screen[i]=L' ';
    for(int i=0;i<nScreenWidth;i++){
      screen[i]=L'#';
      screen[2*nScreenWidth+i]=L'#';
    }
    wsprintf(&screen[nScreenWidth+10],L"Yash Khandelwal     SNAKE     SCORE : ");
    for(auto s : snake){
      screen[s.y * nScreenWidth + s.x] = (bdead)?L'+':L'O';
    }
    screen[snake.front().y * nScreenWidth + snake.front().x] = (bdead)?L'X':L'@';
    screen[nFoodY * nScreenWidth + nfoodX] = L'%';
    WriteConsoleOutputCharacter(hConsole,screen,nScreenWidth*nScreenHeight,{0,0},&dwBytesWritten);
  }

  return 0;
}
