Course 1 Module 1 assessment  
Author:William Liu  
Date:June 10 2020  

**Usage:**  
For Windows CCS + MSP432P401R LaunchPad  
Remember to DEFINE __MSP432P401R__ in CCS  
Because no printf function  
so you have to enter debug mode  
check result by setting watch point to variables that you want to observe.  
  
Under Linux  
1.Change to C1M1 directory  
2.$ gcc -o c1m1.out stats.c 
3.$ ./c1m1.out
4.you will see the result  
  
**Description:**  
You will create a simple application that performs statistical analytics on a dataset.  
This assignment will help you get re-oriented with c-programming syntax and host machine compilation.  
We begin by setting up a version control repository on your local machine.  
You will then develop and test your code there.  
When complete, you will upload a zip of your repository to Coursera.  

**After completing this assignment, you will be able to:**  
Write a simple programming assignment that prints statistics to the command line using a variety of c-programming operators and features.  
Perform Compilation with GCC and execute output files from the command line.  
Use git Version control to create a repository to version control code.  

**Implementation File Guidelines - stats.c**  
You are to write a couple of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set.  
In addition, you will need to reorder this data set from large to small.  
All statistics should be rounded down to the nearest integer.  
After analysis and sorting is done, you will need to print that data to the screen in nicely formatted presentation.  

You will have to make at least 3 commit with git.  

**Files and functions:**  
stats.c  
&nbsp;&nbsp;main()  
&nbsp;&nbsp;&nbsp;&nbsp;The main entry point of the program  
&nbsp;&nbsp;print_statistics()  
&nbsp;&nbsp;&nbsp;&nbsp;prints the statistics of an array including minimum, maximum, mean, and median.  
&nbsp;&nbsp;print_array()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length, prints the array to the screen  
&nbsp;&nbsp;find_median()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length, returns the median value  
&nbsp;&nbsp;find_mean()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length, returns the mean  
&nbsp;&nbsp;find_maximum()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length, returns the maximum  
&nbsp;&nbsp;find_minimum()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length, returns the minimum  
&nbsp;&nbsp;sort_array()  
&nbsp;&nbsp;&nbsp;&nbsp;Given an array of data and a length  
&nbsp;&nbsp;&nbsp;&nbsp;sorts the array from largest to smallest.  
&nbsp;&nbsp;&nbsp;&nbsp;(The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )  
stats.h  
&nbsp;&nbsp;Header file of my C-programming code  
README.md  
&nbsp;&nbsp;This file.  
