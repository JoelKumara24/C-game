/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Implementing the restrictions of the player movements
**        Date: 27/09/19
**  ==============================================================
*/

#include<stdio.h>
#include "blocks.h"

char blocks(char **array,int p1,int p2,int cols,int rows,char d)
{
    /*Checking if the X is covering the Player or the Goal*/
    if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    

    /*Checking all posibilities of Player or Goal getting blocked with 'X' and with the border*/

    else if((array[p1+1][p2]=='*')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='*')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='*')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='*'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='*')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='*')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='*')&&(array[p1-1][p2]=='X')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='*'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='*')&&(array[p1][p2-1]=='*')&&(array[p1][p2+1]=='X'))
        {
            d = 'e';
        }
    else if((array[p1+1][p2]=='X')&&(array[p1-1][p2]=='*')&&(array[p1][p2-1]=='X')&&(array[p1][p2+1]=='*'))
        {
            d = 'e';
        }
    

    return d;
}