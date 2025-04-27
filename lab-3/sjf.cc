// Shortest Job First (SJF)

/*
The shortest job first (SJF) or shortest job next, is a scheduling policy that
selects the waiting process with the smallest execution time to execute next.
SJN, also known as Shortest Job Next (SJN), can be preemptive or non-preemptive.

Characteristics of SJF Scheduling:

Shortest Job first has the advantage of having a minimum average waiting time
among all scheduling algorithms. It is a Greedy Algorithm. It may cause
starvation if shorter processes keep coming. This problem can be solved using
the concept of ageing. It is practically infeasible as Operating System may not
know burst times and therefore may not sort them. While it is not possible to
predict execution time, several methods can be used to estimate the execution
time for a job, such as a weighted average of previous execution times. SJF can
be used in specialized environments where accurate estimates of running time are
available.*/
// Program
#include <iostream>

// using namespace std;
int main() {
  int n, p[20], bt[20], wt[20], tat[20], i, j, total = 0, pos, temp;
  float avg_wt = 0.0, avg_tat = 0.0;
  std::cout << "Enter total process (Max20): ";
  std::cin >> n;

  std::cout << std::endl << "Enter process brust time " << std::endl;
  for (i = 0; i < n; i++) {
    std::cout << "P[" << i + 1 << "]: ";
    std::cin >> bt[i];
    p[i] = i + 1;
  }
  //   sorting burst time in ascending order using selection sort
  for (i = 0; i < n; i++) {
    pos = i;
    for (j = i + 1; j < n; j++) {
      if (bt[j] < bt[pos]) {
        pos = j;
      }
    }
    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] = temp;
    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;
  }
  wt[0] = 0;  // Wating time for first process 0
  for (i = 1; i < n; i++) {
    wt[i] = 0;
    for (j = 0; j < i; j++) {
      wt[i] += bt[j];
      total += wt[j];
    }
  }
  avg_wt = (float)total / n;
  total = 0;
  std::cout << std::endl
            << "Process \t Burst Time \t Waiting Time \t Turnaround Time";
  for (i = 0; i < n; i++) {
    tat[i] = bt[i] + wt[i];
    total += tat[i];
    std::cout << std::endl
              << "P[" << p[i] << "]\t \t " << bt[i] << " \t\t " << wt[i]
              << " \t\t " << tat[i];
  }
  avg_tat = (float)total / n;
  std::cout << std::endl
            << std::endl
            << "Average waiting time: " << avg_wt << std::endl;
  std::cout << "Average turnaround time: " << avg_tat << std::endl << std::endl;

  return 0;
}