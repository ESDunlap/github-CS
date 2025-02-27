#include <stdio.h> //default library
#include <stdlib.h> //rand functions
#include <time.h> //helps randomize seed
#include <unistd.h> //to get sleep()
/*
    Author: Erik Dunlap
    Course: CS125
    Assignment: Autopilot Sim Game 
    Date: 01-31-25
*/ 

int main()
{
    srand(time(0)); //Randomizing rand
    int distancePath; //Current distance from path
    int errorMargin= 5; //Distance where autopilot activates within
    int elevation= 38000; //Flavor Variable
    int elevationRand; //Rand for elevation height
    int secToEnd; //Turn limit within the game
    int randMove; //Amount the plane moves
    int autoPilot; //Win variable
    int endGame= 0; //End game variable
    int gameChoice; //game choice
    
    printf("You are a pilot flying towards a narrow canyon!\n");
    printf("In order to get to your autopilot to bring you to safety,\n");
    printf("You need to get within %d meters of the entrance!\n", errorMargin);
    while (endGame == 0) //main ending the game loop
    {
        autoPilot= 0;
        distancePath= rand()%19 + 51; //range (50, 70)/[51,69]
        for (secToEnd= 10; secToEnd> 0; secToEnd--)
        {
            sleep(1);
            randMove= rand()%23 + 2; //range (1,25)/[2,24]
            elevationRand= rand()%1001; //range [0,1000]
            printf("Current Height: %d meters\n", elevation - elevationRand);
            printf("Time until destination: %d seconds\n", secToEnd);
            printf("You are currently %d meters off course\n", distancePath);
            printf("(Enter a number to stay course, ");
            printf("a character to correct course)\n");
            randMove= (scanf("%d", &gameChoice) == 1)? randMove :-randMove;
            while (getchar() != '\n'); //clearing info
            distancePath+= (distancePath > 0)? randMove : -randMove;
            if (-5 < distancePath && distancePath < 5) //win check
            {
               sleep(1);
               autoPilot= 1;
               printf("WITHIN ACCEPTABLE DISTANCE, AUTOPILOT ENGAGED\n");
               printf("You Won!\n");
               break;
            }
        }
        (autoPilot== 1)? :printf("You have ran out of time. You have lost.\n");
        printf("Would you like to play again?\n");
        printf("(Enter a number to play again, a character to quit)\n");
        endGame= (scanf("%d", &gameChoice) == 1)? 0 : 1;
        while (getchar() != '\n');
    }
}