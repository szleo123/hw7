/*
 * The second attempt to improve the performance
 */
#include "converter.h"
#include <stdio.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    char* cur = lines[i];
    uint16_t result = 100 * (*cur) + 10 * (*(cur+1)) + *(cur+2) - 111 * '0';
    cur += 3; 

    while(*cur != '\0'){
    	result = result * 10 + *cur - '0'; 
        ++cur; 
    }
    nums[i] = result;
  }
}
