#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

//defining global constants
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Gareth Beavan"
#define YEAR 2022


int main (void)
{
    // Printing the information required by the instructions using the defined constants
    printf("*****************************\n"
           "%s\n"//Title
           "Written by: %s\n"//Author
           "Date: %d\n"//Year
           "*****************************\n", TITLE, AUTHOR, YEAR);
    int num;
    int radix;
    //Asking the external user to enter a positive decimal integer using printf
    printf("Enter a decimal number: ");
    //Reading a decimal integer in from the external user
    scanf("%d", &num);
    // while loop to keep the radix and decimal code used for entering values running while num is greater than 0
    while(num>0) {
        //Displaying the decimal number on the screen afterwards
        printf("The number you have entered is %d", num);

        /*Asking the user for an integer between 2 and 16, which will be the radix of the number system that the
          decimal number will convert to*/
        printf("\nEnter a radix for the converter between 2 and 16: ");
        //Reading a radix in from the external user
        scanf("%d", &radix);
        //Displaying the radix on the screen afterwards
        printf("The radix you have entered is %d", radix);
        printf("\n");
        //Finding the log2n of the entered decimal number and displaying it to the screen
        printf("The log2 of the number is %.2f\n", log2(num));
        //Finding the decimal number divided by the entered radix and displaying it to the screen
        printf("The integer result of the number divided by %d is %d\n", radix, num/radix);
        //Finding the remainder of the decimal number divided by radix and displaying it to the screen
        int remainder = num%radix;
        printf("The remainder is %d\n", remainder);
        //Printing out the fully converted decimal to radix i number
        printf("The radix-%d value is ", radix);
        //Calling Dec2RadixI function that prints the value of the decimal in radix-i
        Dec2RadixI(num, radix);
         //Asking the external user to enter a positive decimal integer
        printf("\nEnter a decimal number: ");
        //Reading a decimal integer in from the external user
        scanf("%d", &num);
    }
    //Prints exit when while loop is finished
    printf("EXIT");

    return 0;
}

void Dec2RadixI(int decValue, int radValue)
{
    //Create int variable to track index of the result
    int i = 0;
    //Create char to store the equivalent radix of the base
    char equivalentRadix [100];
    //Create int variable to keep a temporary number
    int tempNum;
    //Create char variable to keep a temporary char value
    char tempVal;
    /*While loop used to convert the decimal value to radix i by dividing them together while the decimal
      is greater than 0*/
    while (decValue > 0){
        //Getting the temporary remainder of the decimal divided by the radix
        tempNum=decValue%radValue;
        //Assigning the decimal a number or a letter depending on value using an if and an else
        if (tempNum >= 0 && tempNum <= 9)
        {
            //if the number is between -1 and 10 an ascii value is assigned to it to determine the char value
            tempVal=(char)(tempNum + '0');
        }
        else
        {
            //if the number is above 9 an ascii value is assigned to it to determine the char letter value
            tempVal=(char)(tempNum - 10 + 'A');
        }
        //Assigning the value of the char to the char array to create a string
        //i is increased twice to do this
        equivalentRadix[i++] = tempVal;
        //the decimal value is divided by the radix
        decValue /= radValue;
    }
    //The first space is assigned this to prevent errors during compilation as \0 is null and is used to siginify the
    //end of the string
    equivalentRadix[i] = '\0';

    //The length of the char array is stored in length using a function from the <string.h> library
    int length = strlen(equivalentRadix);
    //Reverses the array to give the correct order of the number with radix i
    for (int j = length-1; j > -1; j--)
    {
        //prints out arry with correct order
        printf("%c", equivalentRadix[j]);
    }

}

