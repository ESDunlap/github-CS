// Online C compiler to run C program online
#include <stdio.h>
/*
    Author: Erik Dunlap
    Course: CS125
    Assignment: Homework 3
    Date: 01-25-25
*/    
int main() //going to be using camelCase throughout
{
    float hoursWorked = -1; //hours worked per work week
    int employeeID = 1; //EmployeeID umber
    int overWorked= 0; //0 for working proper time, 1 for overworking
    float hourlyPay= -1; //pay per hour
    int salaryType= 0; //1 for hourly, 2 for salary
    int breakVar= 0; //Variable to break final loop
    int queryVar; //Variable for queries
    int moneyVar; //Variable for payment
    int inputVar; //Variable for wrong input
    int wholeMoney; //Variable for whole money paycheck
    float exactMoney; //Variable for exact money paycheck
    
    while (hoursWorked < 0) //hoursWorked validation check
    {
        printf("Please enter your hours worked: ");
        while (scanf("%f", &hoursWorked) == 0) //While check until they enter a valid input
        {
            printf("ERROR! Invalid input must be a float\n");
            printf("Please enter your hours worked: ");
            while (getchar() != '\n');
        }
        (hoursWorked >= 0) ? : printf("ERROR! you can't work negative hours\n");
    }
    //breaks added inbetween for added readability
    while (1000 >= employeeID || employeeID >= 1000000 ) //employeeID check
    {
        printf("Please enter your ID number: ");
        while (getchar() != '\n'); //Otherwise an error causes a double question
        while (scanf("%d", &employeeID) == 0) //non-int check
        {
            printf("ERROR! Invalid input must be a integer\n");
            printf("Please enter your ID number: ");
            while (getchar() != '\n');
        }
        (1000 < employeeID && employeeID < 1000000) ? //cut into two lines for length
        : printf("ERROR! ID must be in the 1001 to 999999 range!\n");
    }
    
    while (hourlyPay < 0 || hourlyPay > 100) //hourlyPay check
    {
        printf("Please enter hourly pay: ");
        while (getchar() != '\n'); //similar case for before
        while (scanf("%f", &hourlyPay) == 0) //While check until they enter a valid input
        {
            printf("ERROR! Invalid input must be a float\n");
            printf("Please enter your hourly pay worked: ");
            while (getchar() != '\n');
        }
        (hourlyPay >= 0) ? : printf("ERROR! you can't earn negative money\n");
        (hourlyPay <= 100) ? : printf("ERROR! Maximum hourly rate offered is $100\n");
    }
    
    while ((salaryType != 1) && (salaryType != 2)) //Salary check
    {
        printf("Please enter your salary type (1 for hourly, 2 for salary): ");
        while (getchar() != '\n');
        scanf("%d", &salaryType);
        ((salaryType == 1) || (salaryType == 2))? : printf("ERROR! Invalid Input\n");
    }
    
    if (hoursWorked > 60 && salaryType== 1) //Overworked check
    {
        printf("WARNING, Hours over approved amount. Reseting to 60. ");
        printf("Talk to your manager for approval\n");
        overWorked= 1;
        hoursWorked= 60;
    }
    
    printf("Employee %d\nCurrent Hours Per Week: %.2f\n", employeeID, hoursWorked);
    printf("Hourly Pay: $%.2f\nPayment Type: ", hourlyPay);
    (salaryType == 1) ? printf("Hourly\n") : printf("Salary\n");
    //since only 2 possiblities using ternary
    while (breakVar== 0)
    {
        (overWorked != 1)?
        : printf("You currently need to talk to your manager\n");
        printf("What would you like to do?\n(1 for current pay)\n");
        printf("(2 for incorrect input)\n(3 for manager status)\n");
        printf("(4 for summary)\n(5 for exiting)\n");
        while (getchar() != '\n');
        scanf("%d", &queryVar);
        switch (queryVar)
        {
        case 1:
            printf("You selected payment.\n(1 for whole dollars)\n");
            printf("(2 for exact)\n(Anything else to return)\n");
            scanf("%d", &moneyVar);
            switch (moneyVar)
            {
            case 1:
                wholeMoney= (int) hoursWorked * hourlyPay;
                printf("Your whole dollar payment is $%d\n", wholeMoney);
                break;
            case 2:
                exactMoney= hoursWorked * hourlyPay;
                printf("Your exact dollar payment is $%.2f\n", exactMoney);
                break;
            }
            break;
        case 2:
            printf("You selected incorrect input. Which input is wrong?\n");
            printf("(1 for hours worked)\n(2 for pay)\n(3 for payment type)\n");
            printf("(Anything else to return)\n");
            scanf("%d", &inputVar);
            switch(inputVar)
            {
            case 1: //just copy pasting the same code as before
                do //changed to do while so they get one loop
                {
                    printf("Please enter your hours worked: ");
                    while (scanf("%f", &hoursWorked) == 0)
                    {
                        printf("ERROR! Invalid input must be a float\n");
                        printf("Please enter your hours worked: ");
                        while (getchar() != '\n');
                    }
                    (hoursWorked >= 0) ? : printf("ERROR! you can't work negative hours\n");
                }
                while (hoursWorked < 0);
                if (hoursWorked > 60 && salaryType== 1)
                    {
                        printf("WARNING, Hours over approved amount. Reseting to 60. ");
                        printf("Talk to your manager for approval\n");
                        overWorked= 1;
                        hoursWorked= 60;
                    }
                break;
            case 2: //Pay
                do
                {
                    printf("Please enter hourly pay: ");
                    while (getchar() != '\n');
                    while (scanf("%f", &hourlyPay) == 0)
                    {
                        printf("ERROR! Invalid input must be a float\n");
                        printf("Please enter your hourly pay worked: ");
                        while (getchar() != '\n');
                    }
                    (hourlyPay >= 0) ? : printf("ERROR! you can't earn negative money\n");
                    (hourlyPay <= 100) ? : printf("ERROR! Maximum hourly rate offered is $100\n");
                }
                while (hourlyPay < 0 || hourlyPay > 100); 
                break;
            case 3:
                do //Salary
                {
                    printf("Please enter your salary type (1 for hourly, 2 for salary): ");
                    while (getchar() != '\n');
                    scanf("%d", &salaryType);
                    ((salaryType == 1) || (salaryType == 2))? : printf("ERROR! Invalid Input\n");
                }
                while ((salaryType != 1) && (salaryType != 2)); 
                
                if (hoursWorked > 60 && salaryType== 1) //Overworked check
                {
                    printf("WARNING, Hours now over approved amount. Reseting to 60. ");
                    printf("Talk to your manager for approval\n");
                    overWorked= 1;
                    hoursWorked= 60;
                }
                break;
            }
            break;
        case 3:
            (overWorked== 1)? printf("You currently need to talk to your manager\n")
            :printf("No outstanding meetings needed\n");
            break;
        case 4:
            printf("Employee %d\nCurrent Hours Per Week: %.2f\n", employeeID, hoursWorked);
            printf("Hourly Pay: $%.2f\nPayment Type: ", hourlyPay);
            (salaryType == 1) ? printf("Hourly\n")
            :printf("Salary\n");
            break;
        case 5:
            breakVar= 1;
            break;
        }
    }
}