## Micro optimization of string conversion

Working for an algorithmic trading company is not easy. Time is precious and everything has to be done super-fast. Trading transactions occur nearly instantaneously, and every microsecond counts.

In an attempt to get an edge over the competition, you'll try to optimize the first part of the trading algorithm's pipeline: converting the stock price quotes from strings to numbers. Assume you have a constant source of online stock quotes that provides you with a stream of strings. Each  string represents one stock quote, in cents (no decimal point). Your job is to convert them to integers (`uint32_t`, specifically) as fast as possible. You may assume there are no overflowing or negative values. For the purpose of this optimization, I created a micro-benchmark for you that already sets up the input data. All you have to do is optimize one function, `convert_all()`, that converts an array of strings into an array of integers. The benchmark is written in C for wide compatibility, but feel free to port it to C++ if you prefer or use C++ features (with the g++/clang++ compilers).

I've included four files to get you started:

 1. A trivial implementation (`converter.c`) of the code you need to write and optimize, just to ensure you understand the requirements. You can rewrite it from scratch, but you must adhere to the same interface, as described in `converter.h`.
2. A data file (`quotes.txt.bz2`) with inputs of historical S&P 500 quotes, edited to include only opening quotes, in cents. To use it, you'll have to first uncompress it using `bunzip2 quotes.txt.bz2`.
3. A driver benchmark (`driver.c`) that reads in the quote file (first argument) and calls the converter function multiple times (second argument), while measuring the minimum CPU time. To help you catch bugs, it verifies that your converted numbers have the same checksum as mine.

To build, simply compile: `gcc -O3 -std=c99 -march=native -o driver -Werror -Wall -Wextra -pedantic *.c` (you can use a different compiler if you like, but make sure to turn on optimizations).

To test, run: `./driver quotes.txt 1000`.
(Fewer than  about a 1000 iterations can be noisy.) On gyoza (which is an old computer with an old compiler, gcc-4.8), this default implementation yields a best run time of about 0.05s. On my desktop with AMD 1950X and gcc-9.3 the run time improves a bit to 0.03s.

Your job is to make it faster --- much faster!

For this problem, multithreading is inappropriate, since we're micro-optimizing single-threaded performance. However, any other optimization trick you can think of is valid, as long as the converter.h interface isn't broken and the checksum stays the same. If you didn't have to change driver.c, you're probably OK.

### Part 1: Naive implementation (20 pts)

The current implementation of `convert_all()` simply uses the standard C library `atoi()` function, which is always a good starting point, because standard library functions are well-debugged and documented. Your first task it to replace this call with your own implementation of the string conversion, as simple and readable as possible. Your naive implementation should iterate over all characters in the string and convert each one to decimal.

Measure the performance of your implementation, describe it in the README, and explain the performance difference you got from the `atoi()` version. You will get up to 10 point for a correct implementation and 10 point for a correct and complete performance explanation.

For comparison, my version of the naive algorithm runs in about 0.01s on gyoza/gcc-4.8, and much faster using a more modern compiler and architecture. If your version isn't significantly faster than `atoi`, you're doing something wrong.

**Writeup for Part1**

Running in WSL, with the given converter in (`standard_converter.c`) which uses the standard library `atoi()` function, the best performance is 0.031s. Use my own version implemented in (`naive_converter.c`), the best performance is 0.01s. 

The performance difference is obvious since standard (`atoi`) function checks a lot of extra stuff where the naive version doesn't do. For example, (`atoi`) function checks the whitespace of given array, the sign of the char array, and if all characters are digits, while the navie version doesn't have such overhead. 

### Part 2: Optimized implementation (80 pts)

Your assignment is to apply any optimization you can think of to the `convert_all()` function and get the best run time possible for this benchmark. A solution that shaves 30% of the naive run time (for example, going from 0.06s to 0.042s) will get the full 80 points. Anything beyond that is extra credit.
As extra incentive, the fastest solution in the class will receive a prize!

I will compile and compare all of your implementations on my Linux host with gcc v. 9.3 (note that performance differences on a Mac will not necessarily translate to Linux).

This is an individual assignment --- no pairs this time. Also, please do **not** look up solutions online, just answers to compiler or optimization questions.
Post a link to your github repo with your code and a README.md describing your changes (I'd like to also read about what you tried and didn't work).

*Good luck!*
