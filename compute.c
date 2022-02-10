/*
    Add required header files and function defintiions here
    upload this file to submitty
*/
#include "compute.h"
complex_t complex_sum(complex_t c1, complex_t c2)
{
    complex_t ans;
  ans.real = c1.real + c2.real;
    ans.img = c1.img + c2.img;
    return ans;

}
complex_t complex_difference(complex_t c1, complex_t c2)
{
    complex_t ans;
    
    ans.real = c1.real - c2.real;
    ans.img = c1.img - c2.img;
    return ans;

}
complex_t complex_multiply(complex_t c1, complex_t c2)
{
    complex_t ans;
    ans.real = c1.real * c2.real - c1.img * c2.img;
    ans.img = c1.img * c2.real + c1.real * c2.img;
    return ans;
}
complex_t complex_divide(complex_t c1, complex_t c2)
{
    complex_t ans;
 if(c2.real == 0 && c2.img == 0)
 {
  return c2;}
  else
{
    ans.real = ((c1.real * c2.real) + (c1.img * c2.img)) / ((c2.real * c2.real) + (c2.img * c2.img));
    ans.img = ((c1.img * c2.real) - (c1.real * c2.img)) / ((c2.real * c2.real) + (c2.img * c2.img));
    return ans;
}
}
