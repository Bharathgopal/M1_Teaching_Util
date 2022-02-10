/**
 * @file 4_pointers.c
 * @author GEA
 * @brief Example program to understand memory leaks and it's detection using Valgrind in linux
 * @version 0.1
 * @date 2021-09-06
 * @copyright Copyright (c) 2021
 * 
 * @note To find out the problems caused in this example, in linux use valgrind tool / Dr.Memroy.
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

void dynamic_memory_allocation_and_free(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }
    free(complex_array);
    complex_array = NULL;

}
void no_free_problem(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }
    return;
}

void access_after_free_problem(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }
    free(complex_array);
    
    complex_array[0].imaginary = -99.99;

    return;
}

void outof_bound_access_poroblem(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }
    complex_array[4].imaginary = -99.99;

    free(complex_array);
    return;
}

void double_free_problem(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }

    free(complex_array);
    free(complex_array);

    return;
}
void wrong_pointer_free_problem(void)
{
    complex_t *complex_array = malloc(3 * sizeof(complex_t)); // calloc(3, sizeof(complex_t));

    if (NULL == complex_array)
    {
        DEBUG_PRINT("Could not allocate dynamic memory, Exiting\n");
        return;
    }
    complex_array++;

    free(complex_array);

    return;
}

int main()
{
   // dynamic_memory_allocation_and_free();
    no_free_problem();
    access_after_free_problem();
    #if 0
    outof_bound_access_poroblem();
    double_free_problem();
    wrong_pointer_free_problem();
    #endif
    return 0;
}