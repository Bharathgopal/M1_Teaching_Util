#TargetName : Dependencies
#<TAB>commands
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif
Build : project_main.c calculator.c
	gcc project_main.c calculator.c -o Calculator.out -lm

Run : Build
	./Calculator.out

Clean:
	rm -rf *.o *.out *.i *.s