// Process creation

/*THEORY
A process is a running state of program which is loaded into memory and
executive i.e. active in nature. It is created by either user or system or any
other program. Process creation is acheived through the fork() system call.
There are four principle events that cause process creation.

1. System initialization
2. Execution of a process creation system call by a running program
3. A user request to create a new process
4. Initialization if a batch job


| new |                            | terminate |
   \                                    ^
    \ admitted                         / exit
     v            interrupt           /
    | ready | ------------------> | running |
      |    \                        /    |
       \    \__schedular_dispatch__/    /
        \                              / I/O or event wait
         \                            /
          \------>| waiting |<-------/
I/O or event completion
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  fork();

  printf("Hello world!\n");
  return 0;
}