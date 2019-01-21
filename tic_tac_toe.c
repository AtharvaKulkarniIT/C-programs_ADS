#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>
#include<string.h>
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin();
void board();
struct player
{
    char name[50];
};
struct player details[2];
int main()
{
    srand(time(0));
    int conti;
    do
    {
    int ch;
    printf("do you want to play single player or 2 player? (1/2)\n");
    scanf("%d",& ch);
    //2 player game
    if (ch==2)
    {
        char toss[10];
        char name1[50];
        char name2[50];
        printf("please enter your name\n");
        scanf("%s", name1);
        printf("please enter your name\n");
        scanf("%s", name2);
        printf("%s do you want heads or tails?(heads/tails)\n",name1);
        scanf("%s",toss);
        int f=1;
        while(f==1)//toss
        {
            int d=rand();
            if(d>=1&&d<=2)
            {
                if(d==1)
                {
                    if(strcmp("heads",toss)==0)
                    {
                        printf("%s is player 1",name1);
                        strcpy(details[0].name,name1);
                        strcpy(details[1].name,name2);
                    }
                    else
                    {
                        printf("%s is player 1",name2);
                        strcpy(details[0].name,name2);
                        strcpy(details[1].name,name1);
                    }
                }
                else
                {
                    if(strcmp("tails",toss)==0)
                    {
                        printf("%s is player 1",name1);
                        strcpy(details[0].name,name1);
                        strcpy(details[1].name,name2);
                    }
                    else
                    {
                        printf("%s is player 1",name2);
                        strcpy(details[0].name,name2);
                        strcpy(details[1].name,name1);
                    }
                }
                break;
            }
        }
    int player = 1, i, choice;

    char mark;
    do//game between 2 players
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getchar();
        }
        i = checkwin();

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
        printf("==>\a %s wins \n", details[(--player)-1].name);
    else
        printf("==>\aGame draw");

    getchar();
    }
    else//game against computer
    {
        int player = 1, i, choice;

        char mark;
        do
        {
            board();
            player = (player % 2) ? 1 : 2;
            if(player==1)//player will play first
            {

            printf("Player %d, enter a number:  ", player);
            scanf("%d", &choice);

            mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[1] == '1')
                square[1] = mark;

            else if (choice == 2 && square[2] == '2')
                square[2] = mark;

            else if (choice == 3 && square[3] == '3')
                square[3] = mark;

            else if (choice == 4 && square[4] == '4')
                square[4] = mark;

            else if (choice == 5 && square[5] == '5')
                square[5] = mark;

            else if (choice == 6 && square[6] == '6')
                square[6] = mark;

            else if (choice == 7 && square[7] == '7')
                square[7] = mark;

            else if (choice == 8 && square[8] == '8')
                square[8] = mark;

            else if (choice == 9 && square[9] == '9')
                square[9] = mark;

            else
            {
                printf("Invalid move ");

                player--;
                getchar();
            }
            i = checkwin();

            player++;
            }
            else//computer will play
            {
                int choice;
                int f=1;
                printf("computer will play the next move\n");
                while(f==1)
                {
                    choice=rand();
                    if(choice>=1&&choice<=9)
                    {
                        break;
                    }
                }
                mark = (player == 1) ? 'X' : 'O';

                if (choice == 1 && square[1] == '1')
                    square[1] = mark;

                else if (choice == 2 && square[2] == '2')
                    square[2] = mark;

                else if (choice == 3 && square[3] == '3')
                    square[3] = mark;

                else if (choice == 4 && square[4] == '4')
                    square[4] = mark;

                else if (choice == 5 && square[5] == '5')
                    square[5] = mark;

                else if (choice == 6 && square[6] == '6')
                    square[6] = mark;

                else if (choice == 7 && square[7] == '7')
                    square[7] = mark;

                else if (choice == 8 && square[8] == '8')
                    square[8] = mark;

                else if (choice == 9 && square[9] == '9')
                    square[9] = mark;

                else
                {
                    player--;
                    getchar();
                }
                i = checkwin();

                player++;

            }
        }while (i ==  - 1);

        board();

        if (i == 1)
        {
            if(--player==1)
            {
            printf("==>\aPlayer 1 wins ");
            }
            else
            {
                printf("==>\acomputer wins");
            }
        }
        else
        {
            printf("==>\aGame draw");
        }
        getchar();

    }
    int i=0;
        printf("do you wish to play again?(1/2)\n");
        scanf("%d",& conti);
        if(conti==1)//play again
        {
            for( i=0;i<=9;i++)
            {
                square[i]=i+'0';
            }
        }
        else
        {
            break;
        }
    }while(conti==1);
    return 0;
}

/*********************************************

 FUNCTION TO RETURN GAME STATUS
 1 FOR GAME IS OVER WITH RESULT
 -1 FOR GAME IS IN PROGRESS
 O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
 FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    system("clear");
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
