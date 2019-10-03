This program prompts the user for the input and output file names, then copies the contents of the input file to the output file. You will be implementing this pseudocode. The standard tee command copies data from standard input to standard output (like an ordinary shell pipe), however it also writes a copy of standard input to a file named on the command line. See the man page for details. Your program’s user interface should appear exactly asfollows:

Welcome to the File Copy Program by <yourname>! Enter the name of the file to copy from:
<type in file name & hit return>
Enter the name of the file to copy to:
<type in the file name & hit return>
File Copy Successful, <number> bytes copied
