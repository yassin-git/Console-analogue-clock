#include <stdio.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip> // put_time
#include"Clock.h"
#include <windows.h>

using namespace std;

std::string Matrix[29][60];

//gotoxy function
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
std::string return_current_time_and_date()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "|%a||%d|");
    return ss.str();
}



int main(){
    Clock c = Clock();
    c.Fill(Matrix);
    c.FillArrows(Matrix);
    while (true)
    {
    c.Afficher(Matrix);   
    std::string time;
    time=return_current_time_and_date();
    gotoxy(46,17);
    cout<<".---..--.";
    gotoxy(46,18);
    cout<<time<<endl;
    gotoxy(46,19);
    cout<<"`---'`--'";
    Sleep((DWORD)1000);
    system("cls");
    }

}