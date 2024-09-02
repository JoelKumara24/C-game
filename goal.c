/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Checking if the player has won
**        Date: 27/09/19
**  ==============================================================
*/

#include<stdio.h>
#include "goal.h"

char goal(char **array,int p1,int p2,int g1,int g2,char d)  /*Checking if the player went to the Goal the winning method*/
{
    if(array[p1][p2] == array[g1][g2] ) /*If the coordinates of the P is equal to the coordinates of Goal then pass the message*/
        {
            
            d = 'e';
              

        }
    return d;

}