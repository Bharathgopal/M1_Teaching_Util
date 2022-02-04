#include "calculator.h"

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
    struct complex_number result = {0, 0};

    // What if number11 = INT_MAX
    printf("Sum of 2 complex number is = %d + i %d\n",result.real, result.imaginary);

    enum status operation_divide_status = complex_divide(cn1, cn2, &result);

    printf("Division of two complex number, Status = %d\n", operation_divide_status);
    printf("Division of 2 complex number is = %d + i %d\n",result.real, result.imaginary);
  return 0;  
}
/*
* Erros
    * Undefined reference - function name is not visible for the linker
    * solution - Add the file which has function definition into the compilation command

*/