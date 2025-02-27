#include <stdio.h>
/*
File Name: hw6_Erik_Dunlap.c
Author: Erik Dunlap
Course: CS125
Assignment: Recursive Matrix
Date: 02-12-25
Resources: Slides and https://stackoverflow.com/questions/
3911400/how-to-pass-2d-array-matrix-in-a-function-in-c
*/
void printMatrix(int size, int matrix[size][size]) //prints the matrix
{
    int columns; //column making var
    int rows; //row making var
    for (columns= 0;columns<size;columns++)
    {
        printf("[ ");
        for (rows= 0;rows<size;rows++)
        {
            if (matrix[columns][rows] != 0)
            {
                printf("%d " , matrix[columns][rows]);
            }
        }
        printf("]\n");
    }
}

int fillMatrix(int rowCounter, int size, int matrix[size][size])
{
    if (rowCounter == size)
    {
        return matrix[size][size]; //end of the recursion
    }
    int forVar;
    for(forVar= 0;forVar < rowCounter+1;forVar++)
    {
        matrix[rowCounter][forVar]= forVar+1;
    }
    return fillMatrix(rowCounter+1, size, matrix);
}

int main()
{
    int rowCounter= 0; //keeps track of which row the function is on
    int columnMaker; //makes the inital 0 columns
    int rowMaker; //makes the inital 0 rows
    int numberOfRows= 0;
    printf("Enter a number from 2 to 99\n");
    while (99 < numberOfRows || numberOfRows <= 1 ) //range bounding
    {
        while (scanf("%d", &numberOfRows) == 0)
        {
            printf("Invalid Input\n");
            while (getchar() != '\n');
        }
        if (99 < numberOfRows || numberOfRows <= 1 )
        {
            printf("Invalid Input\n");
        }
    }
    int matrix[numberOfRows][numberOfRows];
    for(columnMaker= 0; columnMaker<numberOfRows; columnMaker++)
    {
        for(rowMaker= 0; rowMaker<numberOfRows; rowMaker++)
        {
            matrix[columnMaker][rowMaker]= 0;
        }
    }
    fillMatrix(rowCounter, numberOfRows, matrix);
    printMatrix(numberOfRows, matrix);
    return 0;
}