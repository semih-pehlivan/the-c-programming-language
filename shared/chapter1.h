#ifndef CHAPTER_ONE_UTILS
#define CHAPTER_ONE_UTILS 1

/**
 * Copy a null terminated char array.
 * This function is not safe and will overflow if the from string is malformed.
 */
void copy(char to[], const char from[]);

/**
 * Find the string length of s. 
 * Will return an invalid value, and could even cause a segfault if the string 
 * is malformed.
 */
int bstrlen(const char * s);

/**
 * Gets a line from stdin, with length up to lim.
 * returns the length of the line returned.
 * If the line is longer than lim, returns a null terminated fragment of 
 * length lim
 */
int bgetline(char s[], int lim);

/**
 * Reverse a string in place.
 */
void reverse_in_place(char * s);

#endif
