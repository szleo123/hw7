/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i++) {
    char* cur = lines[i];
    // find the size of the quote
    char* cursize = cur;
    size_t size = 0;
    while(*cursize++) ++size;

    uint32_t result = 0; 
    int timer = 1;
    for (int i = size-1; i >=0; --i){
    	int dec = cur[i] - '0';
    	result += (timer * dec);
    	timer *= 10; 
    }
    nums[i] = result;
  }
}
