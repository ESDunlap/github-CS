/*
*Name: hw2_Erik_Dunlap.c
*Author: Erik Dunlap
*Assignment: Homework 2 Jet Engine Warm Up Sim
*Date: 1/13/2025
*References: Slides and : https://www.geeksforgeeks.org/sleep-function-in-c/ for the unistd.h
*/
#include <stdio.h>
#include <unistd.h>
int main()
{//default values
    float burnRate= 2.0; //gasoline burn rate (gallons per second)
    float startingTemp= 3.0; //Extra engine temperature (Fahrenheit)
    float heatRate= 1.25; //rate the engine heats up (Fahrenheit per second)
    float engineTemp; //Engine Temp Initialization
    float fuel; //Fuel of plane Initialization Note:Specifically asked if using this float here was okay and got back approval
    float fuelUsed= 0; //Total Fuel Used 
    float requiredTemp; //Required Temp Initialization
    float secondsTaken= 0; //Measurement of Time for Initialization
    float finishingSeconds= 1; //Used to keep track of ending seconds

    printf("Enter the outside temperature in Fahrenheit: ");
    scanf("%f", &engineTemp);
    engineTemp += startingTemp; //Adding the extra engine heat to proper heat
    do
    {
    printf("Enter Gallons of Fuel: ");
    scanf("%f", &fuel);
    if (fuel <= 0) //Negative Check
    {
        printf("That's not enough to start heating! Please re-enter\n");
    }
    }
    while(fuel <= 0);
    do
    {
    printf("Enter required temperature in Fahrenheit: ");
    scanf("%f", &requiredTemp);
    if (requiredTemp < 0) //Negative Check
    {
        printf("The engine doesn't work at that temperature! Please re-enter\n");
    }
    }
    while (requiredTemp < 0);
    if (requiredTemp >= engineTemp)
    {
      while (1) //indefinite loop but break statements inside
      {
          sleep(1);
          engineTemp += heatRate;
          if (engineTemp >= requiredTemp)
          {
              finishingSeconds= (1- (engineTemp- requiredTemp)/heatRate); //So the rest of the loop can continue
          }
          secondsTaken += finishingSeconds; //++ is not used because of the last loop
          fuel -= (burnRate*finishingSeconds); //Everything from this point on uses finishing seconds so no code is copied basically one-to-one for the end
          fuelUsed += (burnRate*finishingSeconds);
          if (fuel < 0) //Run out of fuel check
          {
              printf("FUEL RAN OUT, PROPER TEMPERATURE NOT REACHED!\n");
              break;
          }
          if (engineTemp > requiredTemp) //proper temp reached
          {
              printf("Warm-up completed after %.1f seconds. Warm-up used %.1f gallons. Remaining fuel left on-board is %.1f gallons.\n", secondsTaken, fuelUsed, fuel);
              break;
          }
      }
    }
    else
    {
      printf("You are already at that temperature!\n");
    }
}
