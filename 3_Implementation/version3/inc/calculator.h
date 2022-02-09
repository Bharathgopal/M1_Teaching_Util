/**
 * @file calculator.h
 * @author Bharath G (Bharath.g@ltts.com)
 * @brief Example to learn Complex numbers: Add, Subtract, Divide and Multply
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// Header gaurd, Madatory
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

// Macros declarations
//Include files
#include <stdio.h>  // existing library 
#include <math.h>
// Structure declarations
struct complex_number{
    int real;
    int imaginary;
};

enum status{
    error_divide_by_zero,
    success
};

// Function prototypes
/**
 * @brief Adds two complex numbers
 * 
 * @param in_operand1 Operand1 for addition
 * @param in_operand2 Operand2 for addition
 * @return struct complex_number Result of addition
 */
enum status complex_add(struct complex_number in_operand1, struct complex_number in_operand2);

/**
 * @brief Subtract two complex numbers
 * 
 * @param in_operand1 Operand1 for Subtract
 * @param in_operand2 Operand2 for Subtract
 * @return struct complex_number Result of Subtraction
 */
enum status complex_subtract(struct complex_number in_operand1, struct complex_number in_operand2);


/**
 * @brief Multiply two complex numbers
 * 
 * @param in_operand1 Operand1 for Multiplication
 * @param in_operand2 Operand2 for Multiplication
 * @return struct complex_number Result of Multiplication
 */
enum status complex_multiply(struct complex_number in_operand1, struct complex_number in_operand2);

/**
 * @brief Divides two complex numbers
 * 
 * @param in_operand1 Operand1 for Division
 * @param in_operand2 Operand2 for Division
 * @return struct complex_number Result of Division
 */
enum status complex_divide(struct complex_number in_operand1, struct complex_number in_operand2, struct complex_number* out_result_divide);

#endif