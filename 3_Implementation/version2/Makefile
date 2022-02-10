#TargetName : Dependencies
#<TAB>commands

Build : project_main.c calculator.c
	gcc project_main.c calculator.c -o Calculator.out -lm

Run : Build
	./Calculator.out

Clean:
	rm -rf *.o *.out *.i *.s