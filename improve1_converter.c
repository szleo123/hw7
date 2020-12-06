/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    char* cur = lines[i];
    uint16_t result = 0; // make size of result smaller and g

    while(*cur != '\0'){
    	result = result * 10 + *cur - '0'; 
        ++cur; 
    }
    nums[i] = result;
  }
}
