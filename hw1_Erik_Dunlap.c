/*
 * File: hw1_Erik_Dunlap.c
 * Author: Erik Dunlap
 * Assignment: Homework 1
 * Date: 01/08/2025
 * References: Slides, Python Knowledge, and a stackoverflow forum
*/

#include <stdio.h>
int main() //I'm not sure if you wanted comments yet but adding them just in case
{//Default Values
   float Denominator= 1.00;
   float Numerator= 1.00;
   float Answer= 1.00;

   printf("This is a simple division calculator!\n");
   printf("Enter a numerator: ");
   scanf("%f", &Numerator); //Getting Numerator

   printf("Enter a denominator: ");
   scanf("%f", &Denominator); //Denominator

   if (Denominator == 0)
   {
       printf("ERROR DIVIDE BY 0 DETECTED! SELF-DESTRUCTION INITIATED!"); //In case of division by 0
   }
   else
   {
       Answer = Numerator/Denominator;
       printf("Numerator: %.2f; Denominator: %.2f; Answer: %.2f", Numerator, Denominator, Answer); //main hard part was finding out about the existence of %.2f
   }
}
