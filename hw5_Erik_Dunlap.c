#include <stdio.h>

/*
    Author: Erik Dunlap
    Course: CS125
    Assignment: Functional Binary Helper Tool
    Date: 02-08-25
*/ 

int AND(int firstInt, int secondInt) //performs AND
{
    printf("%d\n", firstInt&secondInt);
    return 0;
}

int OR(int firstInt, int secondInt) //performs the regular OR
{
    printf("%d\n", firstInt|secondInt);
    return 0;
}

int XOR(int firstInt, int secondInt) //performs the exclusive OR
{
    printf("%d\n", firstInt^secondInt);
    return 0;
}

int compliment(int firstInt, int secondInt) //gets the 2's compliment
{
    printf("%d\n%d\n", ~firstInt + 1,~secondInt + 1);
    return 0;
}

int validIntInput() //Gets a int input from the user
{
    int checkingInput;
    while(scanf("%d", &checkingInput)== 0)
    {
        printf("Invalid Input\n");
        while(getchar() != '\n');
    }
    return checkingInput;
}

int main() 
{
    int firstNumber; //first number the user inputs
    int secondNumber; //second number the user inputs
    int operationChoice; //user input for which operation to do
    int repeatChoice; //user input for each repeat
    int breakVar= 0;
    printf("Enter your first integer!\n");
    firstNumber= validIntInput();
    printf("Enter your second integer!\n");
    secondNumber= validIntInput();
    while(breakVar == 0)
    {
        printf("What operation would you like to do?\n");
        printf("(1 for AND)\n(2 for OR)\n(3 for XOR)\n(4 for 2's compliment)\n");
        operationChoice= validIntInput();
        while(1 > operationChoice || operationChoice > 4)
        {
            printf("Number outside of range!\n");
            operationChoice= validIntInput();
        }
        switch (operationChoice)
        {
        case 1:
            {
                AND(firstNumber, secondNumber);
                break;
            }
        case 2:
            {
                OR(firstNumber, secondNumber);
                break;
            }
        case 3:
            {
                XOR(firstNumber, secondNumber);
                break;
            }
        case 4:
            {
                compliment(firstNumber, secondNumber);
                break;
            }
        }
        printf("What would you like to do?\n");
        printf("(1 for another operation)\n(2 for new numbers)\n(3 to quit)\n");
        repeatChoice= validIntInput();
        while(1 > repeatChoice || repeatChoice > 3)
        {
            printf("Number outside of range!\n");
            repeatChoice= validIntInput();
        }
        switch (repeatChoice)
        {
        case 2:
            {
                printf("Enter your first integer!\n");
                firstNumber= validIntInput();
                printf("Enter your second integer!\n");
                secondNumber= validIntInput();
                break;
            }
        case 3:
            {
                breakVar= 1;
                break;
            }
        }
    }
    return 0;
}