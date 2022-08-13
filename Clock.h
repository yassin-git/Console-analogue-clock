#ifndef CLOCK_H
#define CLOCK_H


#include <stdio.h>
#include <string>  // string
class Clock
{
private:
    /* data */
public:
    Clock();
    ~Clock();
    void Afficher(std::string Matrix[29][60]);
    void get_coordinates(float angle,int* x,int* y);
    std::string return_current_time_and_date();
    void calcPoints(int radius, int midx, int midy, int x[12], int y[12]);
    void Fill(std::string Matrix[29][60]);
    void hour_arrows(std::string Matrix[29][60]);
    void min_arrows(std::string Matrix[29][60]);
    void rotate_point(float cx,float cy,float angle,int *x,int *y);
    void sec_arrows(std::string Matrix[29][60]);
    void FillArrows(std::string Matrix[29][60]);

};
#endif /* CLOCK_H */