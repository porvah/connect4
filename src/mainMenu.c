#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/config.h"

int validMode() {
    char input [256];
    printf("\nPlease Select a path : \n");
    fgets(input, 255, stdin);
    int output = atoi(input);
    if (output == 0 || output > 3) {
        printf("invalid input!!\n");
        return validMode();
    }
    else return output;
    

}

void mainMenu(struct config config)
{
    char game_colors[] = { 'R','O','Y','G' }; //all colors possible for players' disks
    
    double md = 0;
    printf("                                                CONNECT 4 \n");
    printf("                                    ************************************\n");
    printf("1 : New Game\n");
    printf("2 : Load Game\n");
    printf("3 : Highscores");
    
    //printf("\nPlease Select a path : \n");
    //scanf_s("%lf", &pth); //path selection
    int p = validMode(); //correction for switch function
    switch (p)
    {
    case (1):
        printf("\n***************\n");
        printf("\nPlease Select GAME MODE :");
        printf("\n1 : Player 1 V.S PC");
        printf("\n2 : Player 2 V.S Player 2");
        while (1)
        {
              printf("\nSelect The MODE's Number : \n"); //mode selection
              scanf_s("%lf", &md);
              if (md == 1 || md == 2)
                   break;
              printf("Please Select a Valid Mode !");
        }
        int C1, C2; // player 1 , 2 disks colors
        time_t t;
        srand((unsigned)time(&t)); // generating random numbers using time
        C1 = rand() % 4;
        printf("Player 1 has %c color", game_colors[C1]);
        if (md == 2) // check for mode 2
        {
              while (1)
              {
                   C2 = rand() % 4; //generating random in range 0 >> 4
                   if (C1 != C2) // check that every player has his independent color
                        break;
              }
              printf("\nPlayer 2 has %c color", game_colors[C2]);
        }
        break;
    case (2):
          printf("check2"); // <<<<<<<<<< we need save file here to load a previous game
          break;
     case (3):
          printf("check3"); // <<<<<<<<<< we need save file here to view highscores
          break;
    }
}
