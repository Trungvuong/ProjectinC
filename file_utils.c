/**********************************************************************
 * This file utilizes the defined functions from file_utils.h and 
 * actually declares them for use in this file. The read_file is going
 * to read a given file, while the write_file will write a file.
 *
 * @author Trungvuong Pham
 * @version 1.0
 * @date September 17, 2018
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/**********************************************************************
 * This function reads in the file given within the command line 
 * argument.
 *
 * @param filename The file being read in
 * @param buffer A pointer to a pointer of the file contents
 *
 * @return the size of the file 
 *********************************************************************/
int read_file(char* filename, char** buffer){
	FILE* read = fopen(filename, "r");   //opens file
	if(read == NULL){ //prints error if no file is read
		fprintf(stderr, "File does not exist...");
		exit(0);
	}
	//these 3 lines find the size of a file
	//provided by Professor Ira Woodring
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//memory allocation for buffer
	*buffer  = (char*)malloc(size * sizeof(char));   
	char p= 0; //position of file 
	int i = 0; //index of pointer array
	p = fgetc(read); // reads file one character at a time
	while(p != EOF){
		*(*buffer + i) = p; //stores the contents of buffer to char
		p = fgetc(read); // get the next character
		i++;
	}
	fclose(read);	//closes the read file
	return size;
}

/**********************************************************************
 * This function writes the reverse file to the file read in.
 *
 * @param filename The file being written
 * @param buffer The contents of the file
 * @param size The size of read file 
 *
 * @return The size of new file
 *********************************************************************/
int write_file(char* filename, char* buffer, int size){
	FILE* write = fopen(filename, "w"); //writes the file
	if(write == NULL){   //error check for if file is there
		fprintf(stderr, "FILE COULD NOT BE WRITTEN!");
		exit(0);
	}
	//writes the file contents using loop
	for(int i = 0; i < size; i++)
		fprintf(write, "%c", buffer[i]); //prints each char
	fclose(write);

	// finds the size of the file
	// provided by Professor Woodring
	struct stat st;
	stat(filename, &st);
	int wSize = st.st_size;

	return wSize;
}
