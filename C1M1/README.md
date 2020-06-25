Course 1 Module 1 assessment
Author:William Liu
Date:June 10 2020

Description:
You will create a simple application that performs statistical analytics on a dataset.
This assignment will help you get re-oriented with c-programming syntax and host machine compilation.
We begin by setting up a version control repository on your local machine.
You will then develop and test your code there.
When complete, you will upload a zip of your repository to Coursera.

After completing this assignment, you will be able to:
Write a simple programming assignment that prints statistics to the command line using a variety of c-programming operators and features.
Perform Compilation with GCC and execute output files from the command line.
Use git Version control to create a repository to version control code.

Implementation File Guidelines - stats.c
You are to write a couple of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set.
In addition, you will need to reorder this data set from large to small.
All statistics should be rounded down to the nearest integer.
After analysis and sorting is done, you will need to print that data to the screen in nicely formatted presentation.

You will have to make at least 3 commit with git.

Files and functions:
stats.c
  main()
    The main entry point of the program
  print_statistics()
    prints the statistics of an array including minimum, maximum, mean, and median.
  print_array()
    Given an array of data and a length, prints the array to the screen
  find_median()
    Given an array of data and a length, returns the median value
  find_mean()
    Given an array of data and a length, returns the mean
  find_maximum()
    Given an array of data and a length, returns the maximum
  find_minimum()
    Given an array of data and a length, returns the minimum
  sort_array()
    Given an array of data and a length
    sorts the array from largest to smallest.
    (The zeroth Element should be the largest value, and the last element (n-1) should be the      
    smallest value. )
stats.h
  Header file of my C-programming code
README.md
  This file.

