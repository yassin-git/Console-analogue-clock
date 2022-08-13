#include "Clock.h"
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <windows.h>
#include <string>  // string
#include <iostream>

#include <dos.h>
#include <stdio.h>
#include <math.h>


#define radian2degree(a) (a * 57.295779513082)
#define degree2radian(a) (a * 0.017453292519)

using namespace std;



Clock::Clock()
{
   cara='o';
}

Clock::~Clock()
{
}


void Clock::Afficher(string Matrix[29][60]){
    for(int i=0;i<29;++i){
        for (int j=0;j<60;j++){
            if(Matrix[i][j]=="")
                cout<<" ";
            cout<<Matrix[i][j];
        }
        cout<<"\n";
    }
}



void Clock::calcPoints(int radius, int midx, int midy, int x[12], int y[12])
 {
  int x1, y1;
  x[0] = midx, y[0] = midy-radius;
  x[6] = midx, y[6] = midy+radius;
  x[3] = midx+radius, y[3] = midy;
  x[9] = midx-radius, y[9] = midy;

  x1 = (int) ((radius/2)*sqrt(3));
  y1 = (radius/2);
  x[2] = midx+x1, y[2] = midy-y1;
  x[4] = midx+x1, y[4] = midy+y1;
  x[8] = midx-x1, y[8] = midy+y1;
  x[10] = midx-x1, y[10] = midy-y1;

  x1 = radius/2;
  y1 = (int) ((radius/2)*sqrt(3));
  x[1] = midx+x1, y[1] = midy-y1;
  x[5] = midx+x1, y[5] = midy+y1;
  x[7] = midx-x1, y[7] = midy+y1;
  x[11] = midx-x1, y[11] = midy-y1;
  return;
 }
void Clock::Fill(std::string Matrix[29][60]){
    for (int j=0;j<60;j++){
            Matrix[0][j]=cara; 
    }
    for (int j=0;j<60;j++){
            Matrix[28][j]=cara; 
    }
    for (int k=0;k<29;k++){
        Matrix[k][0]=cara;
        Matrix[k][59]=cara;
    }
   //clock_background(Matrix);
   
    calcPoints(12, 30, 14, x, y);
    Matrix[y[0]][x[0]]="1";
    Matrix[y[0]][x[0]+1]="2";
    Matrix[y[1]][x[1]]="1";
    Matrix[y[2]][x[2]]="2";
    Matrix[y[3]][x[3]]="3";
    Matrix[y[4]][x[4]]="4";
    Matrix[y[5]][x[5]]="5";
    Matrix[y[6]][x[6]]="6";
    Matrix[y[7]][x[7]]="7";
    Matrix[y[8]][x[8]]="8";
    Matrix[y[9]][x[9]]="9";
    Matrix[y[10]][x[10]]="1";
    Matrix[y[10]][x[10]+1]="0";
    Matrix[y[11]][x[11]]="1";
    Matrix[y[11]][x[11]+1]="1";

}
void Clock::hour_arrows(std::string Matrix[29][60]){
    Matrix[14][30]="O";
    for (int i=31;i<37;i++){
        Matrix[14][i]="O";
    }
}

void Clock::min_arrows(std::string Matrix[29][60]){
    for (int i=15;i<24;i++){
        Matrix[i][30]="*";
    }
}

void Clock::rotate_point(float cx,float cy,float angle,int *x,int *y)
{
  float s = sin(angle);
  float c = cos(angle);

  // translate point back to origin:
  *x -= cx;
  *y -= cy;

  // rotate point
  float xnew = *x * c - *y * s;
  float ynew = *x * s + *y * c;

  // translate point back:
  *x = xnew + cx;
  *y = ynew + cy;
 return;
}

void Clock::sec_arrows(std::string Matrix[29][60]){
    int i=1,x[]={32,34,36},y[]={16,18,20};

    Matrix[14][30]=".";
    for (int i=0;i<3;i++){
        Matrix[y[i]][x[i]]=".";
    }
    Afficher(Matrix);
    //for (int angle=0;angle<361;angle+=6){
        for (int i=0;i<3;i++){
            Matrix[y[i]][x[i]]="";
        }
        Sleep(1000);
        for (int i=0;i<3;i++){
            int x[]={32,34,36},y[]={16,18,20};
            rotate_point(14,30,degree2radian(6),&x[i],&y[i]);
            Matrix[y[i]][x[i]]=".";
        }
        Matrix[14][30]=".";
        system("cls");
        Afficher(Matrix);
        for (int i=0;i<3;i++){
            Matrix[y[i]][x[i]]="";
        }
        Sleep(1000);
        for (int i=0;i<3;i++){
            int x[]={32,34,36},y[]={16,18,20};
            rotate_point(14,30,degree2radian(12),&x[i],&y[i]);
            Matrix[y[i]][x[i]]=".";
        }
        Matrix[14][30]=".";
        system("cls");
        Afficher(Matrix);
   // }
}

void Clock::FillArrows(std::string Matrix[29][60]){
    hour_arrows(Matrix);
    min_arrows(Matrix);
    //sec_arrows(Matrix);
}






void Clock::get_coordinates(float angle,int* x,int* y){
    float rad=degree2radian(angle);
    *x=2 + 12 * cos(rad);
    *y = 30 + 12 * sin(rad);
}
