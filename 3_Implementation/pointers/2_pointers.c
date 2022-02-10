/**
 * @file 1_pointers.c
 * @author GEA
 * @brief Example program to understand application of pointers
 * @version 0.1
 * @date 2021-09-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdio.h"
#include "stdlib.h"

#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT
#endif

/** @enum error_t
 *  @brief Definition of return types from functions
 */
typedef enum error_t
{
    SUCCESS, /**< Return code for success */
    NULL_PTR, /**< Return code for NULL pointer arguments*/
    DIVIDE_BY_ZERO
} error_t;
/**
 * @struct complex_t 
 * @brief Structure definition of complex data type
 */
typedef struct complex_t
{
    float real;      /**< Real part of the  complex number */
    float imaginary; /**< Imaginary part of the complex number */
    
} complex_t;

/**
 * @brief Function to swap value of two arguments
 * 
 * @param var1 Variable1 for swap operation
 * @param var2 Variable2 for swap operation
 * @return error_t error_t value accordidng to the results
 */
error_t swap(int *var1, int *var2)
{
    if (NULL == var1 || NULL == var2)
        return NULL_PTR;

    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;

    return SUCCESS;
}

/**
 * @brief Function to add two complex numebrs
 * 
 * @param complex_var1 Complex variable 1
 * @param complex_var2 Complex variable 1
 * @param result_var Variabel to hold result of the add operation
 * @return error_t error_t value according to the result
 */
error_t complex_add(complex_t *complex_var1, complex_t *complex_var2, complex_t *result_var)
{
    if (NULL == complex_var1 || NULL == complex_var2 || NULL == result_var)
        return NULL_PTR;

    result_var->real = complex_var1->real + complex_var2->real;
    result_var->imaginary = complex_var1->imaginary + complex_var2->imaginary;

    return SUCCESS;
}
error_t complex_divide(complex_t *complex_var1, complex_t *complex_var2, complex_t *result_var)
{
    if (NULL == complex_var1 || NULL == complex_var2 || NULL == result_var)
        return NULL_PTR;
    
    if (0 == complex_var1->real || 0 == complex_var2->real )
        return DIVIDE_BY_ZERO;

    result_var->real = complex_var1->real + complex_var2->real;
    result_var->imaginary = complex_var1->imaginary + complex_var2->imaginary;

    return SUCCESS;
}

int main()
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));
    
    if(NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return -1;
    }

    complex_array[0].real      = 1.1;
    complex_array[0].imaginary = 1.1;

    complex_array[1].real      = 2.2;
    complex_array[1].imaginary = 2.2;
    
    if(SUCCESS == complex_add(&complex_array[0], &complex_array[1], &complex_array[2]))
    {
        DEBUG_PRINT("Sum of (%f + %fi)+ (%f + %fi) = (%f + %fi)\n",
        complex_array[0].real, complex_array[0].imaginary,
        complex_array[1].real, complex_array[1].imaginary,
        complex_array[2].real, complex_array[2].imaginary);
    }

    free(complex_array);
    complex_array = NULL;

    return 0;
}

void fun(int* a, int* b)
{
    *a = i + 10;
    *b = i + 20;
}

x = 1; y=2;
fun(&x, &y);
x = ?, y = ?; 