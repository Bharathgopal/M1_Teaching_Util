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

/**
 * @struct complex_t 
 * @brief Structure definition of complex data type
 */
typedef struct complex_t
{
    float real;      /**< Real part of the  complex number */
    float imaginary; /**< Imaginary part of the complex number */
} complex_t;

int main()
{
    char char_var = '*';
    char *ptr_char_var = NULL;

    ptr_char_var = &char_var;

    int int_var = 10;
    int *ptr_int_var = &int_var;

    complex_t *ptr_complex_var = malloc(sizeof(complex_t)); // calloc(1, sizeof(complex_t));

    if (NULL == ptr_complex_var)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return -1;
    }

    ptr_complex_var->real = 1.1;
    ptr_complex_var->imaginary = 2.2;

    DEBUG_PRINT("size of char* = %lu, size of int* = %lu, size of complext_t* = %lu\n", sizeof(ptr_char_var), sizeof(ptr_int_var), sizeof(ptr_complex_var));

    free(ptr_complex_var);
    ptr_complex_var = NULL;

    return 0;
}