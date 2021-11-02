Sorting a File
	
	in the terminal: 
	1) cd to the "BinarySsearchNathanRickett" directory
	2) make all (compiles all programs except for file generator)
	3) ./binary_search input_file.txt output_file.txt


Rickett_Nathan_Binary_Search.cpp
	
	This program accepts to parameters, input and output files, stores the data from the first parameter (input) in an array,
	then uses the median of three method to select a pivot and runs quick sort on the array until it is sorted.
	Once sorted, it is appended to the second parameter (output).


ExecutionTime file
	
	In the execution time file the categories are seperated by space.
	Underneath "inputSize" are the values for input size
	Underneath "executionTime" is the amount of microseconds it took to finish sorting the file ONLY. 
	Execution time does not include any other code except for quick sort.


AverageExecutionTime file
	
	I imported the data set from the execution time file into "R gui" and received the mean value for execution time,
	then recorded it in the table in AverageExecutionTime file.


File Generator.cpp
	
	This program creates a directory called "numbers" inside of the current directory.
	Inside of the "numbers" directory it creates 500 files. 100 files of each type of input.
	Using a different for-loop and the rand function, it generates the specified amount of floating
	point inputs into the file. Each one are space deliminated.


dataCreator.cpp
	
	This is a program that i wrote that generates the data from the files created with File Generator.cpp
	it Records the execution time, in milliseconds, and then records it in ExecutionTime file. 
	The data is space seperated.


