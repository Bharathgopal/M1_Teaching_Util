/**
 * @file 3_pointers.c
 * @author GEA
 * @brief Example program to understand application of pointers to functions
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
    NULL_PTR /**< Return code for NULL pointer arguments*/
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
 * @typedef funtion_swap_t 
 * @brief Pointer for the swap function
 * 
 */
typedef error_t (*funtion_swap_t)(int *var1, int *var2);

/**
 * @typedef function_complex_add_t 
 * @brief Pointer for the complex add function
 * 
 */
typedef error_t (*function_complex_add_t)(complex_t *complex_var1, complex_t *complex_var2, complex_t *result_var);

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

/**
 * @brief Function for complex calculator
 * 
 * @param add_funtion 
 * @return error_t error_t value according to the result
 */
error_t complex_calculator(function_complex_add_t add_funtion)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return NULL_PTR;
    }

    complex_array[0].real = 1.1;
    complex_array[0].imaginary = 1.1;

    complex_array[1].real = 2.2;
    complex_array[1].imaginary = 2.2;

    if (SUCCESS == add_funtion(&complex_array[0], &complex_array[1], &complex_array[2]))
    {
        DEBUG_PRINT("Sum of (%f + %fi)+ (%f + %fi) = (%f + %fi)\n",
                    complex_array[0].real, complex_array[0].imaginary,
                    complex_array[1].real, complex_array[1].imaginary,
                    complex_array[2].real, complex_array[2].imaginary);
    }

    free(complex_array);
    complex_array = NULL;
    return SUCCESS;
}
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

int main()
{
    int val1 = 100, val2 = 200;

    error_t (*function_swap_ptr)(int *, int *) = NULL;

    function_swap_ptr = swap;
    
    DEBUG_PRINT("Before swap: \n\tVal1 = %d\n\tVal2 = %d\n",val1, val2);
    if(SUCCESS == function_swap_ptr(&val1, &val2))
    {
        DEBUG_PRINT("After swap: \n\tVal1 = %d\n\tVal2 = %d\n",val1, val2);
    }

    if (SUCCESS == complex_calculator(complex_add))
    {
        return 0;
    }
    return -1;
}