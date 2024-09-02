/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Read a text file which is seperated by space and 
**              assigning the values to the coordinate pointers
**        Date: 27/09/19
**  ==============================================================
*/


#include <stdio.h>
#include <string.h>
#include "fileR.h"

int atoi(const char *str);
void fileR(int* Rows,int* Columns,int* P1,int* P2,int* G1,int* G2,char* str)
{
    
    
    FILE* fp = fopen(str, "r");                     /*Creating the file pointer*/
 
    if (!fp)
        printf("Can't open file\n");                /*If the file is not there printing the error message*/
 
    else {
        
        char buffer[1024];                          /*the string to get the contents of the sentence*/
 
        int row = 0;
        int column = 0;
        int x1;
        int x2;
        char* value;
        
        
 
        while (fgets(buffer,1024, fp))                /*While the end of the file*/
        {
            column = 0;
            row++;
 
           
            value = strtok(buffer, " ");      /*Tokenicing string with space*/
 
            while (value) {
                
                if (column == 0) {
                     x1 = atoi(value);          /*If in the first column convert value to int and assign to x1*/
                    
                }
 
                
                if (column == 1) {
                    x2 = atoi(value);           /*If in the second column convert value to int and assign to x1*/
                    
                }
 
                
                if (column == 2) {

                   

                    if(value[0]=='P')               /*If in the third column and value is equal to P then assigning the x1 x2 values to *P1,*P2*/
                    {
                        *P1 = x1;
                        *P2 = x2;
                        printf("P1 :%d  ",*P1);
                        printf("P2 :%d\n",*P2);

                          
                    }
                    else if(value[0]=='G')          /*If in the third column and value is equal to G then assigning the x1 x2 values to *G1,*G2*/
                    {
                        *G1 = x1;
                        *G2 = x2;
                        printf("G1 :%d  ",*G1);
                        printf("G2 :%d\n",*G2);

                        
                    }
                    else if(value[0]=='X')
                    {
                        printf("X is here");        /*If in the third column and value is equal to X then skip it*/
                    }
                    else                            /*Else assign to *Rows and *Columns respectively */
                    {
                        *Rows = x1;
                        *Columns = x2;
                        printf("row :%d  ",*Rows);
                        printf("col :%d\n",*Columns);

                        
                    }
                    
                }
 
                
                

                value = strtok(NULL, " ");
                column++;
            }
 
            printf("\n");
        }
 
        
        fclose(fp);
    }
    
}