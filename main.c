#include <stdio.h>
#include <stdlib.h>
#define NUM_PRODUCTS 10
// Program:	Project 4
// Author:		Justin Nunley
// Course:		COP2220

//Prototypes
void displayWelcome (void);
int selectOption (void);
int findHighest (double array[], int elements);
int findLowest (double* costs, int elements);
double computeAverage (double array[], int elements);
void displayCredits (void);

//main function
int main (void)
{
    //Array declarations
    char types[NUM_PRODUCTS] = {'R', 'R', 'R', 'F', 'F', 'F', 'D', 'W', 'W', 'A'};
    double lengths[NUM_PRODUCTS] = {1.5, 1.25, 1, 1.625, 1, 2, 1.625, 0.5, 0.625, 1.25};
    double costs[NUM_PRODUCTS] = {47.45, 15.98, 4.98, 3.98, 3.98, 5.98, 7.98, 5.97, 1.38, 18.67};
    //Integer declarations
    int option, index, productChoice, highest, lowest;
    int goAgain = 0;
    //Double declarations
    double average, compareLength;
    //Pointer declarations
    double *lengthsPTR = lengths;
    double *costsPTR = costs;
    char *typesPTR = types;


    displayWelcome ();
    //Start of a do while loop to run the option selection for user input and switch statement repeatedly
    do
    {

        option = selectOption();

        switch(option)
        {
        //Case 1 addresses user option 1 and displays all information via a for loop
        case 1:
            for (index = 0; index < NUM_PRODUCTS; index = index + 1)
                printf("Product Type:%c Product Length:%lf Product Cost:%lf\n----------------------------\n", types[index], lengths[index], costs[index]);
            break;
        //Case 2 takes a product number, validates it, and prints the corresponding array element in the console
        case 2:
            do
            {
                printf("Enter the product number which you would like to see the information for 1-10:");
                scanf("%d", &productChoice);
            }
            while (productChoice > 10  || productChoice == 0 || productChoice < 0);
            printf("Product Type:%c Product Length:%lf Product Cost:%lf|\n", types[productChoice-1], lengths[productChoice-1], costs[productChoice-1]);
            break;
        //Case 3 calls the findHighest function, assigns it to highest, and uses that to print the info of the highest length product
        case 3:
            highest = findHighest(lengths, NUM_PRODUCTS);
            printf(" The information for the product with the longest length is \nProduct Type:%c Product Length:%lf Product Cost:%lf|\n", types[highest], lengths[highest], costs[highest]);
            break;
        //Case 4 calls the findHighest function, assigns it to lowest, and uses that to print the info of the lowest cost product
        case 4:
            lowest = findLowest(costs, NUM_PRODUCTS);
            printf(" The information for the product with the lowest cost is \nProduct Type:%c Product Length:%lf Product Cost:%lf|\n", types[lowest], lengths[lowest], costs[lowest]);
            break;
        //Case 5 assigns the average variable to the computeAverage functions call then prints the average
        case 5:
            average = computeAverage (costsPTR, NUM_PRODUCTS);
            printf("The average cost of all products available are %lf\n", average);
            break;
        //Case 6 takes a length from the user and compares it to the products in the array, displaying ones equal or smaller
        case 6:
            do
            {
                printf("Enter a length to see which products are the same length or smaller.\n");
                scanf("%lf", &compareLength);
            }
            while (compareLength <= 0);
            for (index = 0; index < NUM_PRODUCTS-1; index = index + 1)
                if (lengths[index]  >= compareLength)
                    printf("\nProduct Type:%c Product Length:%lf Product Cost:%lf|\n", types[index], lengths[index], costs[index]);
            break;
        //Default displays the credits and exits
        default:
            displayCredits();
            exit(0);

        }
    }
    while (goAgain == 0);
return 0;
}

    /*Function Name: displayWelcome
Purpose: To display a welcome message to the application
Parameters: void (none)
Return: void (none)
 */
void displayWelcome (void)
{
    printf("Welcome to the Hardware Information tool!");
}

    /*Function Name: selectOption
Purpose: To prompt the user and take input to return to main
Parameters: dvoid
Return: int option
 */
int selectOption (void)
{
    int option;
    do
    {
        printf("Please enter the number of the option you wish to select from below for displaying information about the available products:\n");
        printf("1) Display All Products Data.\n 2) Specific product number  \n 3) Highest Length Product \n 4) Lowest Cost Product \n5 Average cost of products \n 6) Product Length under amount \n 0)Exit \n");
        scanf("%d", &option);
    }
    while (option >= 7 || option <0);
    return option;
}

    /*Function Name: findHighest
Purpose: To find the lowest value in a given array give an array and a number of elements
Parameters: double values[](an array) and int elements
Return: int returnIndex
 */
int findHighest (double values[], int elements)
{
    int index, returnIndex;
    double highest;
    for (index = 0; index <= elements-1; index = index + 1)
    {
        if (values[index] > highest)
        {
            highest = values[index];
            returnIndex = index;
        }
    }
    return returnIndex;
}

    /*Function Name: findLowest
Purpose: To find the lowest value in a given array give an address and a number of elements
Parameters: double* costs(an address) and int elements
Return: int returnIndex
 */
int findLowest (double* costs, int elements)
{
    int index, returnIndex;
    double lowest;
    for (index = 0; index <= elements-1; index = index + 1)
    {
        if (costs[index] < costs[returnIndex])
        {
            returnIndex = index;
        }
    }
    return returnIndex;
}

    /*Function Name: computeAverage
Purpose: To take an array and creates a running total, divides that total by the number of elements
Parameters: double (an array)values[], int elements
Return: double
 */
double computeAverage (double values[], int elements)
{
    int index;
    double total, average;
    total = 0;
    for (index = 0; index <= elements-1; index = index + 1)
    {
        total = total + values[index];
    }
    average = total/NUM_PRODUCTS;
    return average;
}

    /*Function Name: displayCredits
Purpose: To display a credits message for the application with my first and last name
Parameters: void (none)
Return: void (none)
 */
void displayCredits (void)
{
    printf("This program was made by Justin Nunley!");
}



/*
Test Data 1
First Option: 1
Second Option: 2
Product Number: 10
Exit: 0

Expected Results
Print out of the data of all three arrays
Prompt for a product number
Print out the information of product 10 A 1.25 18.67
exit and display credits

Actual Results
Welcome to the Hardware Information tool!Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
1
Product Type:R Product Length:1.500000 Product Cost:47.450000
----------------------------
Product Type:R Product Length:1.250000 Product Cost:15.980000
----------------------------
Product Type:R Product Length:1.000000 Product Cost:4.980000
----------------------------
Product Type:F Product Length:1.625000 Product Cost:3.980000
----------------------------
Product Type:F Product Length:1.000000 Product Cost:3.980000
----------------------------
Product Type:F Product Length:2.000000 Product Cost:5.980000
----------------------------
Product Type:D Product Length:1.625000 Product Cost:7.980000
----------------------------
Product Type:W Product Length:0.500000 Product Cost:5.970000
----------------------------
Product Type:W Product Length:0.625000 Product Cost:1.380000
----------------------------
Product Type:A Product Length:1.250000 Product Cost:18.670000
----------------------------
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
2
Enter the product number which you would like to see the information for 1-10:10
Product Type:A Product Length:1.250000 Product Cost:18.670000|
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
0
This program was made by Justin Nunley!
Process returned 0 (0x0)   execution time : 10.246 s
Press any key to continue.


Test Data 2
First Option: 4
Second Option: 3
Exit: 0

Expected Results
Displays the information for the lowest cost product W .625 1.38
Displays the information for the highest length product F 2 5.98
Exit and display credits

Actual Results
Welcome to the Hardware Information tool!Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
4
 The information for the product with the lowest cost is
Product Type:W Product Length:0.625000 Product Cost:1.380000|
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
3
 The information for the product with the longest length is
Product Type:F Product Length:2.000000 Product Cost:5.980000|
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
0
This program was made by Justin Nunley!
Process returned 0 (0x0)   execution time : 6.263 s
Press any key to continue.




Test Data 3
First Option: 5
Second Option: 6
Length: 1
Exit: 0

Expected Results
Displays the average of all costs of the array
Takes input from the user and displays all products under or equal to that length 7 products
Exits and displays the credits

Actual Results
Welcome to the Hardware Information tool!Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
5
The average cost of all products available are 11.635000
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit
6
Enter a length to see which products are the same length or smaller.
1

Product Type:R Product Length:1.500000 Product Cost:47.450000|

Product Type:R Product Length:1.250000 Product Cost:15.980000|

Product Type:R Product Length:1.000000 Product Cost:4.980000|

Product Type:F Product Length:1.625000 Product Cost:3.980000|

Product Type:F Product Length:1.000000 Product Cost:3.980000|

Product Type:F Product Length:2.000000 Product Cost:5.980000|

Product Type:D Product Length:1.625000 Product Cost:7.980000|
Please enter the number of the option you wish to select from below for displaying information about the available products:
1) Display All Products Data.
 2) Specific product number
 3) Highest Length Product
 4) Lowest Cost Product
5 Average cost of products
 6) Product Length under amount
 0)Exit


*/
