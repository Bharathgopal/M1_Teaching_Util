/**
 * @file calculator.c
 * @author Bharath G ()
 * @brief Example to learn Complex numbers: Add, Subtract, Divide and Multply
 * @version 0.1
 * @date 2022-02-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>  // existing library 
//#include "stdio.h" // Only for user header files

struct complex_number{
    int real;
    int imaginary;
};

/**
 * @brief Adds two complex numbers
 * 
 * @param in_operand1 Operand1 for addition
 * @param in_operand2 Operand2 for addition
 * @return struct complex_number Result of addition
 */
struct complex_number complex_add(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    temp.real = in_operand1.real + in_operand2.real;
    temp.imaginary = in_operand1.imaginary + in_operand2.imaginary;

    return temp;
}
/**
 * @brief Subtract two complex numbers
 * 
 * @param in_operand1 Operand1 for Subtract
 * @param in_operand2 Operand2 for Subtract
 * @return struct complex_number Result of Subtraction
 */
struct complex_number complex_subtract(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    //What if real1 = INT_MIN & real2 = INT_MIN
    temp.real = in_operand1.real - in_operand2.real;
    temp.imaginary = in_operand1.imaginary - in_operand2.imaginary;

    return temp;
}

/**
 * @brief Multiply two complex numbers
 * 
 * @param in_operand1 Operand1 for Multiplication
 * @param in_operand2 Operand2 for Multiplication
 * @return struct complex_number Result of Multiplication
 */
struct complex_number complex_multiply(struct complex_number in_operand1, struct complex_number in_operand2)
{
    struct complex_number temp;
    //TODO Correct logic for multiplication of complext numbers
    return temp;
}

enum status{
    error_divide_by_zero,
    success
};
/**
 * @brief Divides two complex numbers
 * 
 * @param in_operand1 Operand1 for Division
 * @param in_operand2 Operand2 for Division
 * @return struct complex_number Result of Division
 */
enum status complex_divide(struct complex_number in_operand1, struct complex_number in_operand2, struct complex_number* out_result_divide)
{
     /*
        A = 10;
        B = 0;
        A/B --> Crash of the program
    */
    if(0 == in_operand1.imaginary || 0 == in_operand2.imaginary)
        return error_divide_by_zero;

    //TODO Correct logic for multiplication of complext numbers
    out_result_divide->real = 1;
    out_result_divide->imaginary = 2;

    return success;
}

int main()
{
    int number11 , number12;
    printf("Enter two numbers\n");
    scanf("%d %d", &number11, &number12);

    struct complex_number cn1 = {number11, number12};

    int number21 , number22;
    printf("Enter two numbers \n");
    scanf("%d %d", &number21, &number22);

    struct complex_number cn2 = {number21, number22};
    struct complex_number result = complex_add(cn1, cn2);

    // What if number11 = INT_MAX
    printf("Sum of 2 complex number is = %d + i %d\n",result.real, result.imaginary);

    enum status operation_divide_status = complex_divide(cn1, cn2, &result);

    printf("Division of two complex number, Ststu = %d\n", operation_divide_status);
    printf("Division of 2 complex number is = %d + i %d\n",result.real, result.imaginary);
  return 0;  
}

/*
Interface Layer Programming

Compilation/ Build process:
    1) Preprocessing
        * Tool : cpp
        * Input is .c file
        * Removes comments
        * Substitute the content of header file
        * Preprocessors will be substituted in its place
            * #define
            * #include
            * #if
            * #else
            * #endif
        * Generates a Pure C Code 
        * gcc -E <filename> or cpp <filename>
        * Output is .i
    2) Compilation
        * Tool : gcc
        * Checks
            * Sytax check
            * Varibale mapping
            * Semantics
                * 10 = A + 20;
            * Parenthesis matching
        * If all checks pass
            * Then it generates assembly code - opcodes
        * gcc -S <c source filename> or * gcc -S <i source filename>
    3) Assembling
        * Tool : as
        * Convert assembly code to Machine code - Object code
        * gcc -c <c source file> or as <assembly source file>
    4) Linking
        * Tool : ld
        * Address of external function (library, or other object files) is linked
            * Run time
            * Compile time
* Commands
    * Check libraries - ldd a.out
    * compilation: gcc <filename> -o <own name>.out
        * .exe - Windows
        * .out - Linux
    * Symbol Table - nm <.o>  or nm a.out
    * Size of Segmnets(Text, data, bss) - size a.out
    * File size - ls -l a.out

* Memory Map
    * Content of a.out ?
    * Text or Code
    * Data - Global Varibales
        * Initiazed - Data
        * Uninitiazed - BSS (Block Started by symbol)
    * Heap - Dynamic Variables
    * Stack - Local Varibales
        * Function calls
* Functions
    * Passing
        * By Value
        * By Address
    * Returning
        * By Value
        * By Address
* Math on Lines of Code
    * 5 Member team
    * Each write 100 lines a day
    * 1 year - 182500 - 100 files
* Multifile
    * More than 1 source code files
    * Feature files, Application files,, Library files, Utilty files, Header files
*/