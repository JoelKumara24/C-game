/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Read a text file which is seperated by space and 
**              assigning the appropriate values to X in the intMatrix
**        Date: 27/09/19
**  ==============================================================
*/


#include <stdio.h>
#include <string.h>
#include "fileRX.h"

/*Same code as the fileR the only difference is when it comes to 3rd column the program only grabs the X printed rows only AND IGNORES THE REST*/

int atoi(const char *str);
void fileRX(char **array,char* str)
{
    
    
    FILE* fp = fopen(str, "r");
 
    if (!fp)
        printf("Can't open file\n");
 
    else {
        
        char buffer[1024];
 
        int row = 0;
        int column = 0;
        int x1;
        int x2;
        char* value;
        
        
 
        while (fgets(buffer,1024, fp)) 
        {
            column = 0;
            row++;
 
           
            value = strtok(buffer, " ");
 
            while (value) {
                
                if (column == 0) {
                     x1 = atoi(value);
                    
                }
 
                
                if (column == 1) {
                    x2 = atoi(value);
                    
                }
 
                
                if (column == 2) {

                   
                    if(value[0]=='X')           /*If in the third column and value is equal to X then assigning the x1 x2 values to the intMatrix and assigning X to that location*/
                    {
                        array[x1][x2] = 'X';

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