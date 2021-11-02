Sorting a File
	
	in the terminal: 
	1) cd to the "CSCE350Project_Rickett_Nathan" directory
	2) make all
	3) ./Rickett_Nathan_Binary_Search input_file.txt output_file.txt (input and output files are not included)


Rickett_Nathan_Binary_Search.cpp
	
	This program accepts two parameters, input and output files, stores the data from the first parameter (input file) in an array,
	then uses the median of three method to select a pivot and runs quick sort on the array until it is sorted.
	Once sorted, it is appended to the second parameter (output file).


Rickett_Nathan_executionTime.txt
	
	In the execution time file the categories are seperated by space.
	Underneath "inputSize" are the values for input size
	Underneath "executionTime" is the amount of microseconds it took to finish sorting the file ONLY. 
	Execution time only starts when the quick sort algorithm ends
	Execution time only ends when quick sort algorithm ends


Rickett_Nathan_averageExecutionTime.txt
	
	I imported the data set from the execution time file into "R gui" and received the mean value for execution time,
	then recorded it in the table in AverageExecutionTime file.


InputFileGenerator.cpp
	
	This program creates a directory called "numbers" inside of the current directory.
	Inside of the "numbers" directory it creates 500 files. 100 files of each type of input.
	Using a different for-loop and the rand function, it generates the specified amount of floating
	point inputs into the file. Each one are space deliminated.


makefile

	make all: compiles the Rickett_Nathan_QuickSort.cpp file
	make clean: removes the Rickett_Nathan_QuickSort binary


