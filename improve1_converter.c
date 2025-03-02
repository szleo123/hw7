/*
 * The first attempt to improve the performance
 * Getting rid of the overhead of finding the size of quote
 */
#include "converter.h"

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    char* cur = lines[i];
    uint16_t result = 0; 

    while(*cur != '\0'){
    	result = result * 10 + *cur - '0'; 
        ++cur; 
    }
    nums[i] = result;
  }
}
