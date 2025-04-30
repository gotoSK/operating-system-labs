// Deadlock

/*
A deadlock is a situation where a set of processes are blocked because each
process is holding a resource and waiting for another resource acquired by some
other process.

Consider an example when two trains are coming toward each other on the same
track and there is only one track, none of the trains can move once they are in
front of each other. A similar situation occurs in operating systems when there
are two or more processes that hold some resources and wait for resources held
by other(s). For example, in the below diagram, Process 1 is holding Resource 1
and waiting for resource 2 which is acquired by process 2, and process 2 is
waiting for resource 1.

Deadlock can arise if the following four conditions hold simultaneously
(Necessary Conditions)

Mutual Exclusion: Two or more resources are non-shareable (Only one process can
use at a time) Hold and Wait: A process is holding at least one resource and
waiting for resources. No Preemption: A resource cannot be taken from a process
unless the process releases the resource. Circular Wait: A set of processes
waiting for each other in circular form.
*/
#include <iostream>

using namespace std;

int main() {
  static int mark[20];
  int i, j, np, nr;

  int alloc[10][10], request[10][10], avail[10], r[10], w[10];
  cout << "Enter the no. of process: ";
  cin >> np;
  cout << endl << "Enter the no. of resources: ";
  cin >> nr;

  for (i = 0; i < nr; i++) {
    cout << "\n Total Amount of the Resource R" << i + 1 << " :";
    cin >> r[i];
  }

  cout << "\n Enter the request matrix:";
  for (i = 0; i < np; i++) {
    for (j = 0; j < nr; j++) {
      cin >> request[i][j];
      cout << "\n Enter allocation matrix:";
      for (i = 0; i < np; i++) {
        cin >> alloc[i][j];
      }
      for (j = 0; j < nr; j++) {  // Available resourse calculation
        avail[j] = r[i];
        for (i = 0; i < np; i++) {
          avail[j] -= alloc[i][j];
        }
      }
      for (i = 0; i < nr; i++) {  // Marking process with zero allocation
        int count = 0;
        for (j = 0; j < nr; j++) {
          if (alloc[i][j] == 0) {
            count++;
          } else {
            break;
          }
          if (count == nr) {
            mark[i] = 1;
          }
        }
      }
    }
  }
  // Initialize W with avail
  for (j = 0; j < nr; j++) {
    w[j] = avail[j];
  }

  // Make processes with request less than or equal to w
  for (i = 0; i < np; i++) {
    int canbeprocessed = 0;
    if (mark[i] != 1) {
      for (j = 0; j < nr; j++) {
        if (request[i][j] <= w[j])
          canbeprocessed = 1;
        else {
          canbeprocessed = 0;
          break;
        }
      }
      if (canbeprocessed) {
        mark[i] = 1;
        for (j = 0; j < nr; j++) {
          w[j] += alloc[i][j];
        }
      }
    }
  }
  // checking for unmarked processes
  int deadlock = 0;
  for (i = 0; i < np; i++) {
    if (mark[i] != 1) {
      deadlock = 1;
    }
  }
  if (deadlock) {
    cout << endl << "Deadlock detection";
  } else {
    cout << endl << "No deadlock possible";
  }

  return 0;
}