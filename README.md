#A C++ program to calculate time complexity of First, Best and Worst Fit algorithms


The main() function

The main function is the driver function, it performs the following functions:
 
1)	taking no_of_processes followed by, the free space requirements of the processes from the process file 
2)	taking input files one at a time (input0.txt, input1.txt, input2.txt, input3.txt, input4.txt) 
	  and analysing them using all three algorithms (First, Best & Worst fit)
3)	it calls the algorithms through the 'call_algo' function
4)	the output is formatted by using I/O manipulation functions (setw)

Note: 
All file are accessed using the function 'freopen' which redirects the file data to the 'stdin' console (creates a portal between
the user input file and the file opened by freopen) and enables reading of file data from the 'stdin' console as usual.
This portal is closed after use by using 'fclose' function.
