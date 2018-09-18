/**********************************************************************
 * This is the header file needed to define the functions used by
 * the file_util.c file and the reverse.c file.
 *
 * @author Trungvuong Pham
 * @version 1.0
 * *******************************************************************/
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

/**********************************************************************
 * Reads the file and takes a filename with a double pointer character.
 * Places read file into a buffer.
 *
 * @param filename The name of the file
 * @param buffer Holds the file contents
 *
 * @return the size of the file
 *********************************************************************/
int read_file(char* filename, char** buffer);

/**********************************************************************
 * Writes a file. Takes the filename and the writes in the read file 
 * into a new file.
 *
 * @param filename The name of the file 
 * @param buffer The pointer that holds the contents of the file
 * @param size The size of input
 *
 * @return The size of the file  
 *********************************************************************/
int write_file(char* filename, char* buffer, int size);

#endif //FILE_UTILS_H
