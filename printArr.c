/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Printing the array elements
**        Date: 27/09/19
**  ==============================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "printArr.h"
#include "demoChangeColor.h"




void printArr( char **array,int i1,int j1,int rows,int colmns,int X1,int X2,int nred)  /*The function to print the array*/
{
    system("clear"); /*The clear command to clear the screen everytime the function is called*/

    for (i1 = 0; i1<rows; i1++)  /*the for loop for evey row*/
    {
        for (j1=0; j1 < colmns; j1++) /*the for loop for evey column*/
        {
            if(nred == 0)  /*If the nred was passed as 0*/
            {
                if(array[i1][j1]=='P')       /*If the array index is equal to P print it in blue*/
                {
                    setForeground("blue");
                    printf("%c ", array[i1][j1]);
                    setForeground("reset");
                }
                else if(array[i1][j1]=='G')         /*If the array index is equal to G print it in yellow*/
                {
                    setForeground("yellow");
                    printf("%c ", array[i1][j1]);
                    setForeground("reset");
                }
                
                else
                {
                printf("%c ", array[i1][j1]);  /*printing the array elements*/ 
                }
            }
            else
            {
                    if(array[i1][j1]=='P')  /*If the array index is equal to P print it in blue*/
                {
                    setForeground("blue");
                    printf("%c ", array[i1][j1]);
                    setForeground("reset");
                }
                else if(array[i1][j1]=='G')              /*If the array index is equal to G print it in yellow*/
                {
                    setForeground("yellow");
                    printf("%c ", array[i1][j1]);
                    setForeground("reset");
                }
                else if((i1==X1)&&(j1==X2))              /*If the array index is equal to X print the background in red only if nred is not 0*/
                {
                    setBackground("red");
                    printf("%c ", array[i1][j1]);
                    setBackground("reset");
                }
               
                else
                {
                printf("%c ", array[i1][j1]);  /*printing the array elements*/ 
                }
            }
            

        }
        printf("\n");  /*printing a newline*/


    }
    printf("Press w to go up\n");
    printf("Press s to go down\n");
    printf("Press a to go left\n");
    printf("Press d to go right\n");
    printf("Press u to undo\n");
    


    
}