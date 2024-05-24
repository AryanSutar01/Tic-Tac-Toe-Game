#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void printBoard();
int winner();

char array[10] = " 123456789";


int main()
{   
    system("cls");
    printf("---- TIC-TAC-TOE ----\n\n");
    printBoard();

    for (int i = 1; i <= 9; i++)
    {
        int playerswap = (i % 2 == 0) ? 2 : 1;
        int input;

        if (playerswap == 1)
        {
            printf("\nPlayer to play: ");
            scanf("%d", &input);

            if (array[input] == 'X' || array[input] == 'O')
            {
                printf("Place Already Taken\n");
                sleep(1);
                i--;
            }
            else
            {
                array[input] = 'X';
            }
        }
        else
        {
            do
            {
                input = rand() % 9 + 1;
            } while (array[input] == 'X' || array[input] == 'O');

            sleep(1);

            array[input] = 'O';
        }

        system("cls");
        printf("---- TIC-TAC-TOE ----\n\n");
        printBoard();

        int flag = winner();

        if (flag == 1)
        {
            printf("\nPlayer Won");
            break;
        }
        else if (flag == 2)
        {
            printf("\nComputer Won");
            break;
        }
    }

    if (winner() == 0)
    {
        printf("\nGame was a TIE");
    }

    return 0;
}

void printBoard()
{
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", array[1], array[2], array[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", array[4], array[5], array[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", array[7], array[8], array[9]);
    printf("     |     |     \n");
}

int winner()
{
    for (int i = 1; i <= 9; i += 3)
    {
        if (array[i] == array[i + 1] && array[i + 1] == array[i + 2])
        {
            if (array[i] == 'X')
                return 1;
            else if (array[i] == 'O')
                return 2;
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        if (array[i] == array[i + 3] && array[i + 3] == array[i + 6])
        {
            if (array[i] == 'X')
                return 1;
            else if (array[i] == 'O')
                return 2;
        }
    }

    if ((array[1] == array[5] && array[5] == array[9]) ||
        (array[3] == array[5] && array[5] == array[7]))
    {
        if (array[5] == 'X')
            return 1;
        else if (array[5] == 'O')
            return 2;
    }

    return 0;
}
