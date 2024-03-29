/**
 * @file Clock.h
 * @author Mohamed Yassine Yaich
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CLOCK_H
#define CLOCK_H
/*****************************************************************************************************************************************************
*                                                               Include Files                                                                                                                                             *
*                                                                                                                                                    *                                                                                                                                                  
******************************************************************************************************************************************************/

#include <stdio.h>
#include <string>  // string
/**
 * @brief   Clock Class 
 * 
 */
class Clock
{
private:
    /* data */
    char  cara;
    int x[12];
    int y[12];
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