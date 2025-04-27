// First Come Forst Service (FCFS)

/*The process scheduling is the activity of the process manager that handles the
removal of the running process from the CPU and the selection of another process
on the basis of a particular strategy.

Process scheduling is an essential part of a Multiprogramming operating systems.
Such operating systems allow more than one process to be loaded into the
executable memory at a time and the loaded process shares the CPU using time
multiplexing.

Categories of Scheduling
There are two categories of scheduling:

Non-preemptive: Here the resource can’t be taken from a process until the
process completes execution. The switching of resources occurs when the running
process terminates and moves to a waiting state.

Preemptive: Here the OS allocates the resources to a process for a fixed amount
of time. During resource allocation, the process switches from running state to
ready state or from waiting state to ready state. This switching occurs as the
CPU may give priority to other processes and replace the process with higher
priority with the running process.

First Come First Serve CPU Scheduling Algorithm shortly known as FCFS is the
first algorithm of CPU Process Scheduling Algorithm. In First Come First Serve
Algorithm what we do is to allow the process to execute in linear manner.

This means that whichever process enters process enters the ready queue first is
executed first. This shows that First Come First Serve Algorithm follows First
In First Out (FIFO) principle.

The First Come First Serve Algorithm can be executed in Pre Emptive and Non Pre
Emptive manner. Before, going into examples, let us understand what is Pre
Emptive and Non Pre Emptive Approach in CPU Process Scheduling.
*/

// Program
#include <iostream>

using namespace std;
int main() {
  int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
  cout << "Enter total process (Max20): ";
  cin >> n;

  cout << endl << "Enter process brust time " << endl;
  for (i = 0; i < n; i++) {
    cout << "P[" << i + 1 << "]: ";
    cin >> bt[i];
  }
  wt[0] = 0;  // Wating time for first process 0
  for (i = 1; i < n; i++) {
    wt[i] = 0;
    for (j = 0; j < i; j++) {
      wt[i] += bt[j];
    }
  }
  cout << endl << "Process \t Burst Time \t Waiting Time \t Turnaround Time";
  for (i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    avwt += wt[i];
    avtat += tat[i];
    cout << endl
         << "P[" << i + 1 << "]\t \t " << bt[i] << " \t\t " << wt[i] << " \t\t "
         << tat[i];
  }
  avwt /= i;
  avtat /= i;
  cout << endl << endl << "Average waiting time: " << avwt << endl;
  cout << "Average turnaround time: " << avtat << endl << endl;

  return 0;
}