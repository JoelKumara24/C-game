/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Assigning the X values to random generated numbers
**        Date: 27/09/19
**  ==============================================================
*/

#include<stdio.h>
#include "printx.h"

int random(int low, int high);
void printx(char **array,int rows,int colmns,int *x1,int *x2) /*printing the random X function*/
{
    int X1,X2;
    X1 = random(1,rows-2);       /*Assigning the random number function to row variable*/
    X2 = random(1,colmns-2);     /*Assigning the random number function to column variable*/
    while(array[X1][X2]=='X')    /*The while loop to not get the X overlapped over one another*/
    {
        X1 = random(1,rows-2);      /*Assigning thye random numbers until we geyt a numb er that hasnt been already declared*/
        X2 = random(1,colmns-2); 
    }
    array[X1][X2] = 'X';   /*Assigning the X to the array*/
    *x1 = X1;
    *x2 = X2;


}