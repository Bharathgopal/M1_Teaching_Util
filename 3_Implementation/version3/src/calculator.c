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
   if(0 == in_operand1.imaginary || 0 == in_operand2.imaginary)
        return error_divide_by_zero;

    /* 
    a + ib
    c + id

        ((a+ib) / (c+id)) * ((c-id)/(c-id))
    */
    
    out_result_divide->real = ((in_operand1.real * in_operand2.real) + (in_operand1.imaginary * in_operand2.imaginary)) / (pow(in_operand2.real,2) + pow(in_operand1.imaginary,2));
    out_result_divide->imaginary = ((in_operand1.imaginary * in_operand2.real) - (in_operand1.real * in_operand2.imaginary)) / (pow(in_operand2.real,2) + pow(in_operand2.imaginary,2));

    return success;
}
