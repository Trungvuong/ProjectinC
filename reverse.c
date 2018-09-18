/**********************************************************************
 * This function is the main method to implementing the read and write
 * functions from the header file and the file_utils.c file. This will
 * in theory reverse a file within the argument of the method.
 *
 * @author Trungvuong Pham
 * @version 1.0
 * @date September 17, 2018
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char** argv){
	//there must be 3 arguments for this to work
	if(argc == 3){
		char *pBuffer;  //criate a pointer to buffer
		int rSize, wSize;  //the file sizes
		
		//reads input file and gets size from function
		rSize = read_file(argv[1], &pBuffer);
		if(rSize < 0){
			fprintf(stderr, "ERROR! CAN NOT LOAD FILE!");
			exit(0);
		}
		// create new char pointer to reverse the buffer
		char* reverseFile = (char*)malloc(rSize * sizeof(char));
		for(int i = 0; i < rSize; i++)
			reverseFile[rSize - 1 - i] = pBuffer[i];
		//writes the reversed file created above
		wSize = write_file(argv[2], reverseFile, rSize);
		//if both files are not equal, another error handling
		if(rSize != wSize){
			fprintf(stderr, "Error occured. Both files are not the same...");
			exit(0);
		}
		free(reverseFile); //frees space from pointer 
		free(pBuffer); 
		printf("The file %s was written in reverse successfully!", argv[2]);		
	}
	else{
		fprintf(stderr, "ARGUMENTS ARE INVALID. MUST HAVE 3 ARGUMENTS");
		exit(0);
	}
	return 0;
}
