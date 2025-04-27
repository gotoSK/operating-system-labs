// Round Robbing (RR)

// Program
#include <iostream>

using namespace std;
int main() {
  int count, j, n, time, remain, flag = 0, time_quantum;
  int bt[20], rt[10], at[10], wait_time = 0, turnaround_time = 0;
  cout << "Enter total process (Max10): ";
  cin >> n;

  remain = n;
  for (count = 0; count < n; count++) {
    cout << endl
         << "Enter arrival time and brust time for" << endl
         << "Process[" << count + 1 << "]: ";
    cin >> at[count] >> bt[count];
    rt[count] = bt[count];
  }
  cout << endl << "Enter time quantum: ";
  cin >> time_quantum;

  cout << endl << "Process \t Turnaround Time \t Waiting Time ";

  for (time = 0, count = 0; remain != 0;) {
    if (rt[count] <= time_quantum && rt[count] > 0) {
      time += rt[count];
      rt[count] = 0;
      flag = 1;
    } else if (rt[count] > 0) {
      rt[count] -= time_quantum;
      time += time_quantum;
    }
    if (rt[count] == 0 && flag == 1) {
      remain--;
      cout << endl
           << "P[" << count + 1 << "]\t \t " << time - at[count] << " \t\t\t "
           << time - at[count] - bt[count];
      wait_time += time - at[count] - bt[count];
      turnaround_time += time - at[count];
      flag = 0;
    }
    if (count == n - 1)
      count = 0;
    else if (at[count + 1] <= time) {
      count++;

    } else {
      count = 0;
    }
  }
  cout << endl
       << endl
       << "Average waiting time: " << wait_time * 1.0 / n << endl;
  cout << "Average turnaround time: " << turnaround_time * 1.0 / n << endl
       << endl;

  return 0;
}