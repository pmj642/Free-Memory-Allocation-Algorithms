# A C++ program to calculate and study time complexity of First, Best and Worst Fit algorithms

## Libraries Included
1)	iostream(standard i/o)
2)	ctime	(timer)
3)	cstring	(strcpy() function)
4)	iomanip (formatted output)

## Functions Used

* int main(void);
	
	driver function

* void *__call_algo__*(int freeblocks[], int n_blocks, int process[], int n_process);
	
	Function to call three memory allocation functions

* int *__firstFit__*(int blockSize[], int m, int processSize[], int n);

	Function to allocate memory to blocks as per First fit algorithm

* int *__bestFit__*(int blockSize[], int m, int processSize[], int n);
	
	Function to allocate memory to blocks as per Best fit algorithm

* int *__worstFit__*(int blockSize[], int m, int processSize[], int n);

	Function to allocate memory to blocks as per Worst fit algorithm

## The main() function

The main function is the driver function, it performs the following functions:
 
1)	taking *__no_of_processes__* followed by, the free space requirements of the processes from the process file 
2)	taking input files one at a time *__(input0.txt, input1.txt, input2.txt, input3.txt, input4.txt)__* 
	  and analysing them using all three algorithms *__(First, Best & Worst fit)__*
3)	it calls the algorithms through the *__'call_algo'__* function
4)	the output is formatted by using I/O manipulation functions *__(setw)__*

#### Note: 
All file are accessed using the function *__'freopen'__* which redirects the file data to the *__'stdin'__* console (creates a portal between the user input file and the file opened by freopen) and enables reading of file data from the 'stdin' console as usual.
This portal is closed after use by using *__'fclose'__* function.
