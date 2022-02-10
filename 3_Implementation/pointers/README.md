# Pointer in C/C++

## Value of and address of operator
```
int A = 10;
int* ptr = &A;

printf("Value of Variable = %d, Address variable = %p\n", A, &A);

printf("Address of Pointer = %p, Address pointed by Pointer = %p, Value pointed by pointer = %d\n", &ptr, ptr, *ptr);
```

## Passing and returning address
* Always perform NULL check before working on any pointer argument.
* Do not return pointers to local variabels.

## Applying pointers

### Pointer to basic data types
* Pass the arguments and work on these variabels in other functions and have the results stored in the original varaiables

### Pointer to structure
* To pack multiple variabels into single entity
* To optimise speed and memory usage

### Pointer to function
* Callback functions
* Interrutp servic routines
* Thread functions

### Operations on Pointers
* Dereference
* Arithmetic operations
    * Subtracting two pointers


### Writing Test cases for void functions
* move_left
* Void return type

X = 1, Y = 1

move_left(X, Y)

//X = 0, Y = 0

TEST_ASSERT_EQ(0 , X);
TEST_ASSERT_EQ(0 , Y);