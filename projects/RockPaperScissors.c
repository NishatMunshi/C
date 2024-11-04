#include <stdio.h>
#include <stdlib.h> //needed for srand function
#include <time.h>
#include <string.h>3
const char Rock[] = "Rock";
const char Paper[] = "Paper";
const char Scissors[] = "Scissors";
char name[20];
char PlayerChoice[10];
char ComputerChoice[10];
int rounds;
int GenerateRandomNumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
void WelcomeMessage()
{
    printf("\nWelcome to the worst rock, paper, scissors game you can ever imagine!!!!\n\n");
    printf("Please enter your name here: ");
    scanf("%s", &name);

    printf("\nRules of the game:\n\tPress 'r' for rock, 'p' for paper, and 's' for scissors.\nThree rounds will be held between you and the computer. Whoever has the most points in the end wins. Negative points are considered.\n\n");
}
void PlayerChoiceStringDecoder(char choice)
{
    switch (choice)
    {
    case 'r':
        strcpy(PlayerChoice, Rock);
        break;
    case 'p':
        strcpy(PlayerChoice, Paper);
        break;
    case 's':
        strcpy(PlayerChoice, Scissors);
        break;
    default:
        break;
    }
}
void ComputerChoiceStringDecoder()
{
    int ran = GenerateRandomNumber(3);
    switch (ran)
    {
    case 0:
        strcpy(ComputerChoice, Rock);
        break;
    case 1:
        strcpy(ComputerChoice, Paper);
        break;
    case 2:
        strcpy(ComputerChoice, Scissors);
        break;
    }
}
int GameLogic(char PlayerChoice[], char ComputerChoice[]) // returns player score increase.
{
    if (strcmp(PlayerChoice, ComputerChoice) == 0)
    {
        return 0;
    }
    else if (strcmp(PlayerChoice, Rock) == 0 && strcmp(ComputerChoice, Scissors) == 0)
    {
        return 1;
    }
    else if (strcmp(PlayerChoice, Paper) == 0 && strcmp(ComputerChoice, Rock) == 0)
    {
        return 1;
    }
    else if (strcmp(PlayerChoice, Scissors) == 0 && strcmp(ComputerChoice, Paper) == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void main()
{
    WelcomeMessage();
repeat:
    printf("\nEnter an odd number as the number of rounds you wanna play: ");
    scanf("%d", &rounds);
    if (rounds % 2 != 0 && rounds > 0)
    {
        int PlayerScore = 0;
        int ComputerScore = 0;
        for (int i = 0; i < rounds; i++)
        {
            char choice = '\0';
            printf("Round %d:\n\n%s's turn:\n\tEnter your choice: ", i + 1, name);
            scanf(" %c", &choice);
            if (choice == 'r' || choice == 'p' || choice == 's')
            {
                PlayerChoiceStringDecoder(choice);
                ComputerChoiceStringDecoder();
                PlayerScore = PlayerScore + GameLogic(PlayerChoice, ComputerChoice);
                ComputerScore = ComputerScore - GameLogic(PlayerChoice, ComputerChoice);
            }
            else
            {
                printf("Sorry, wrong input.\n\n");
                goto repeat;
            }
            printf("Result of round %d:\n\t%s chose: %s\n\tComputer chose: %s\n\n", i + 1, name, PlayerChoice, ComputerChoice);
            printf("you get %d point\n\n", GameLogic(PlayerChoice, ComputerChoice));
        }
        printf("***Result***\n\t%s's score is %d\n\tComputer's score is %d\n\n", name, PlayerScore, ComputerScore);
        if (PlayerScore == ComputerScore)
        {
            printf("It's a Tie!!");
        }
        else if (PlayerScore > ComputerScore)
        {
            printf("You win!! Congratulations!!");
        }
        else
        {
            printf("Computer wins. Better luck next time!!");
        }
        printf("\n\nWould you like to play again? (y/n): ");
        char again;
        scanf(" %c", &again);
        if (again == 'y')
        {
            goto repeat;
        }
        else
        {
            goto end;
        }
    }
    else
    {
        printf("Odd number of rounds only!!!");
        goto repeat;
    }

end:
    printf("\nQuitting Game.....");
}