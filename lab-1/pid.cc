#include <sys/types.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int main() {
  // pid_t data type stands for process identification and it is used to
  // represent process ids. Whenever, we want to declare a variable that is
  // going to be deal with the process ids we can use pid_t data type.

  pid_t pid = fork();  // creates a child process

  if (pid == 0) {
    // Child process
    cout << "This is the child process, PID = " << getpid() << endl;
    // getpid() – this function returns the process id of the calling process,
    // its syntax is, pid_t getpid()

  } else if (pid > 0) {
    // Parent process
    cout << "This is the parent process, PID = " << getpid() << endl;
  } else {
    // Error
    cout << "Error: fork() failed" << endl;
    return 1;
  }

  return 0;
}

/*
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid;

  pid = fork();

  if (pid < 0) {
    printf("Error!");
  } else if (pid == 0) {
    printf("Child Process = %d\n", pid);
  } else {
    printf("Parent's Process = %d\n", pid);
  }
}*/
