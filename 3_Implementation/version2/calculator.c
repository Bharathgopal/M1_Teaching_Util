#include "calculator.h"

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
