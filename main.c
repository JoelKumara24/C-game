/*  ==============================================================
**      Author: Joel Kumara 20963675
**     Purpose: Main file of the program
**        Date: 16/10/22
**  ==============================================================
*/



#include <stdio.h>
#include <stdlib.h> 
#include "random.h"
#include "terminal.h"
#include "printx.h"
#include "printArr.h"
#include "goal.h"
#include "blocks.h"
#include "fileR.h"
#include "fileRX.h"
#include "demoChangeColor.h"
#include "linked_list.h"
/*#include "printRedX.h"*/




void initRandom();
char blocks(char **array,int p1,int p2,int cols,int rows,char d);
int main(int argc, char* argv[]) /*Intializing the main function*/
{
    if( argc != 2 )
    {
        printf( "./escape <map_file_name>\n" );
        
    }
    else
    {
        char **intMatrix; 
    LinkedList* list;
    loc tres;
    loc tres1;
    loc res;
    char c,d,k,h;
    int ROWS,COLUMNS,P1,P2,G1,G2,i,j,X1,X2;             /*The integers to get the player and the goal and the border*/

    /*The pointers of the coordinates which we have to pass to the File reading function*/
    int *R;
    int *C;
    int *p1;
    int *p2;
    int *g1;
    int *g2;
    int *x1;
    int *x2;
    int rem;
    int nred;
    int firstu;
    int firstu2;

    /*Initial positions of the player*/

    int constP1;
    int constP2;

    /*Assigning pointers to appropriate locations*/

    R = &ROWS;
    C = &COLUMNS;
    p1 = &P1;
    p2 = &P2;
    g1 = &G1;
    g2 = &G2;
    x1 = &X1;
    x2 = &X2;



    
    rem = 0;
    nred = 1;
    firstu = 0;
    firstu2 = 0;

    list = NULL;
    list = createLinkedList();
    

    /*The File reading method*/


    fileR(R,C,p1,p2,g1,g2,argv[1]);
    

               
    
    constP1 = P1;
    constP2 = P2;

    intMatrix = (char **)malloc(ROWS*sizeof(char*));        /*mallocing the array rows*/

    for(i = 0;i<ROWS; i++)                  /*mallocing the array columns*/
    {
        intMatrix[i] = (char*)malloc(COLUMNS * sizeof(char));
    }

    if(ROWS>=5 &&  COLUMNS>=5 && P1>0 && P2>0 && G1>0 && G2>0  && P1<ROWS-1 && P2<COLUMNS-1 && G1<ROWS-1 && G2<COLUMNS-1)        /*getting rows and columns in range 5 and the goal and player inside the border */
    {
        for (i = 0; i<ROWS; i++)                        /*Assigning the 2D array boundry with stars and the goal and the player */
        {
            for (j=0; j < COLUMNS; j++)
            {
                
                intMatrix[G1][G2] = 'G';
                intMatrix[P1][P2] = 'P';
                intMatrix[i][j] = ' ';
                intMatrix[0][j] = '*';
                intMatrix[i][0] = '*';
                intMatrix[ROWS-1][j] = '*';
                intMatrix[i][COLUMNS-1] = '*';

            }

        }
        fileRX(intMatrix,argv[1]); 
        

        printArr(intMatrix,i,j,ROWS,COLUMNS,X1,X2,nred);   /*Printing the Initial array*/

   

        initRandom();       /*The given random code*/



   
    
    
    

        

        while (d!='e'&& k!='e'&& h!='e')  /*The while loop for player movement*/
        {

        
            printf("Enter a key:");     /*Ask for the key to move the player*/

            disableBuffer();  /*For the scanf command to work without the Enter button*/
            scanf("%c",&c);
            enableBuffer();


        
        
        

        

            intMatrix[P1][P2] = ' ';                /*Emptying the position where P was previously*/
            if(c == 's')                            /*If the user input is 's'*/
            {
                firstu2 = 1;
                nred = 1;
                rem = 0;
               d = goal(intMatrix,P1+1,P2,G1,G2,c); /*Checking if the player went to the goal*/
           

                if(intMatrix[P1+1][P2]=='X')        /*Checking whether the position where the player will be at is having the 'X'*/
                {
                    P1 = P1;                        /*the player stays in the same position*/
                }
                
                                            /*Borderless endif*/
                else if(intMatrix[P1+1][P2]=='*')   /*If the player to be position has the * character*/
                {
                    P1 = P1;                        /*Player will be in the same place*/
                }
                else 
                {
                    P1 = P1+1;                      /*else player moves down*/
                   
                }
                printx(intMatrix, ROWS, COLUMNS,x1,x2);    /*The random X that will print in the border*/
                
                res.X1=X1;
                res.X2=X2;
                res.P1=P1;
                res.P2=P2;
                if(firstu==1){
                    insertLast(list,tres1);
                    insertLast(list,res);
                    firstu = 2;
                }
                else
                {
                    insertLast(list,res);   /*Inserting the locations of Player and random number to list*/
                }
            }

            else if(c=='w')                          /*If the user input is 'w'*/
            {
                firstu2 = 1;
                nred = 1;
                rem = 0;
                d = goal(intMatrix,P1-1,P2,G1,G2,c); /*Checking if the player went to the goal*/
                
                if(intMatrix[P1-1][P2]=='X')         /*Checking whether the position where the player will be at is having the 'X'*/
                {
                    P1 = P1;                         /*the player stays in the same position*/
                
                }
                
                                            /*Borderless endif*/
                else if(intMatrix[P1-1][P2]=='*')   /*If the player to be position has the * character*/
                {
                    P1 = P1;                        /*the player stays in the same position*/
                }
                else
                {
                    P1 = P1-1;                      /*else player moves up*/
                    
                }
                printx(intMatrix, ROWS, COLUMNS,x1,x2);   /*The random X that will print in the border*/
                
                res.X1=X1;
                res.X2=X2;
                res.P1=P1;
                res.P2=P2;
                if(firstu==1){
                    insertLast(list,tres1);             /*Inserting to the list*/
                    insertLast(list,res);
                    firstu = 2;
                }
                else
                {
                    insertLast(list,res);
                }
            }
            else if(c=='a')                         /*If the user input is 'a'*/
            {
                firstu2 = 1;
                nred = 1;
                rem = 0;
               d = goal(intMatrix,P1,P2-1,G1,G2,c); /*Checking if the player went to the goal*/
                if(intMatrix[P1][P2-1]=='X')        /*Checking whether the position where the player will be at is having the 'X'*/
                {
                    P2 = P2;                        /*Then the P stays where it was before*/
                }
                
                                             /*Borderless endif*/   
                else if(intMatrix[P1][P2-1]=='*')   /*If the player to be position has the * character*/
                {
                    P2 = P2;                        /*the player stays in the same position*/
                }
                else
                {
                    P2 = P2-1;                      /*else player moves left*/
                }
                printx(intMatrix, ROWS, COLUMNS,x1,x2);    /*The random X that will print in the border*/ 
                
                res.X1=X1;
                res.X2=X2;
                res.P1=P1;
                res.P2=P2;
                if(firstu==1){
                    insertLast(list,tres1);
                    insertLast(list,res);
                    firstu = 2;
                }
                else                            /*Inserting to the list*/
                {
                    insertLast(list,res);
                }
            }

            else if(c=='d')                         /*If the user input is 'a'*/
            {
                firstu2 = 1;
                nred = 1;
                rem = 0;
               d = goal(intMatrix,P1,P2+1,G1,G2,c); /*Checking if the player went to the goal*/
                if(intMatrix[P1][P2+1]=='X')         /*Checking whether the position where the player will be at is having the 'X'*/
                {
                    P2 = P2;                         /*Then the P stays where it was before*/
                }
                
                                            /*Borderless endif*/   
                else if(intMatrix[P1][P2+1]=='*')    /*If the player to be position has the * character*/   
                {
                    P2 = P2;                        /*the player stays in the same position*/
                }
                else
                {
                    P2 = P2+1;                      /*else player moves right*/
                    
                }
                printx(intMatrix, ROWS, COLUMNS,x1,x2);   /*The random X that will print in the border*/
                
                res.X1=X1;
                res.X2=X2;
                res.P1=P1;
                res.P2=P2;
                if(firstu==1){
                    insertLast(list,tres1);
                    insertLast(list,res);
                    firstu = 2;
                }                                       /*Inserting to the list*/
                else
                {
                    insertLast(list,res);
                }
            }
            else if(c=='u')       /*Undo method*/
            {
                
                firstu = 1;
                if(list->count == 0 )       /*Handling exceptions when the list count is zero*/
                {
                    if(firstu2==0)             /*If the initial character the player pressed is u*/
                    {
                        
                        nred = 0;               
                        firstu = 0;             
                        P1 = constP1;           
                        P2 = constP2;
                    }
                    else
                    {
                        intMatrix[X1][X2] = ' ';
                        nred = 0;
                        firstu = 0;             /*If the count is zero assigning nred to 0 to stop the background red from printing*/
                        P1 = constP1;           /*Assigning the location of P to the Initial location*/
                        P2 = constP2;
                    }
                    
                }
                else if(list->count == 1 )      /*Handling exceptions when the list count is one*/
                {
                    if((P1==constP1+1&&P2 == constP2)||(P1==constP1-1&&P2==constP2)||(P1==constP1&&P2==constP2+1)||(P1==constP1&&P2==constP2-1))
                    {
                        nred = 0;               /*If the Player is only one position away from the initial position assigning nred to 0 to stop the background red from printing*/
                    }
                    
                    
                    intMatrix[X1][X2] = ' ';        /*Deleting the X that was printed before*/
                    tres = removeLast(list);        /*Removing last element from list and grabbing it*/
                    P1 = constP1;
                    P2 = constP2;                   /*Assigning the location of P to the Initial location*/
                    X1 = tres.X1;                   /*Assigning the location of X to the previous location*/
                    X2 = tres.X2; 
                    firstu = 0;
                }
                else
                {

                    if(rem==0 && list->count != 1 )         /*If its the first time undoing after moving the player and count is not 1*/
                    {
                        removeLast(list);                   /*Removing the last element from list*/
                    }
                    rem = 1;

                    intMatrix[X1][X2] = ' ';                /*Deleting the previous X*/
                    
                    tres = removeLast(list);                /*Removing the new last element from list and grabbing the loc struct to tres*/
                    X1 = tres.X1;                           /*Assigning the location of X to the previous location*/
                    X2 = tres.X2;
                    P1 = tres.P1;                           /*Assigning the location of P to the previous location*/
                    P2 = tres.P2;
                    tres1 = tres;

                    
                }

                
            }
            else 
            {
                printf("enter valid key\n");           /*If the user enter any other key*/
            }

        

        

            intMatrix[P1][P2] = 'P';                /*assign the P in the new location*/
            intMatrix[G1][G2] = 'G';                /*assign the G in the location*/
            k = blocks(intMatrix, P1, P2,ROWS,COLUMNS,k);  /*checks if the player gets blocked*/
            h = blocks(intMatrix, G1, G2,ROWS,COLUMNS,h);   /*checks if the goal gets blocked*/


            printArr(intMatrix,i,j,ROWS,COLUMNS,X1,X2,nred);       /*print the array with new location*/


            
            

       


        
        }
        
        
        if(k == 'e')  /*printing the array and ending the game if player is blocked*/
        {
            
            printArr(intMatrix,i,j,ROWS,COLUMNS,X1,X2,nred);
            printf("\n");
            printf("You are BLOCKED\n");
        }
        else if( h == 'e')     /*printing the array and ending the game if goal is blocked*/
        {
            
            printArr(intMatrix,i,j,ROWS,COLUMNS,X1,X2,nred);
            printf("\n");
            printf("Goal is BLOCKED\n");
        }
        else                 /*printing the array and ending the game if player wins*/
        {
            printf("\n");
            printArr(intMatrix,i,j,ROWS,COLUMNS,X1,X2,nred);
            printf("\n");
            printf("You have won!!!\n");
        }
        
    
    }

    else         /*if command line arguments are not in range*/
    {
        printf("Coordinates are not correct");
    }

     /*freeing the malloced pointers */
    
    free(intMatrix);

    

    free( list ); 
    
    }
    



    return 0 ;



}







