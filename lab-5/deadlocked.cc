#include <iostream>

using namespace std;

static int mark[20];
int i, j, np, nr;
int main() {
  int alloc[10][10], request[10][10], avail[10], r[10], w[10];
  cout << "Enter the no. of process: ";
  cin >> np;

  cout << endl << " Enter the no of resources: ";
  cin >> nr;

  for (i = 0; i < nr; i++) {
    cout << endl << " Total Amount of the Resource R" << i + 1 << ": ";
    cin >> r[i];
  }
  cout << endl << " Enter the request matrix: \n";
  for (i = 0; i < np; i++)
    for (j = 0; j < nr; j++) {
      cin >> request[i][j];
    }
  cout << endl << "Enter the allocation matrix: \n";
  for (i = 0; i < np; i++)
    for (j = 0; j < nr; j++) {
      cin >> alloc[i][j];
    }
  for (j = 0; j < nr; j++)  // Available resource calculation
  {
    avail[j] = r[j];
    for (i = 0; i < np; i++) {
      avail[j] -= alloc[i][j];
    }
  }
  for (i = 0; i < nr; i++)  // marking processes with zero allocation
  {
    int count = 0;
    for (j = 0; j < nr; j++) {
      if (alloc[i][j] == 0)
        count++;
      else
        break;
    }
    if (count == nr) mark[i] = 1;
  }
  // initialize W with avail

  for (j = 0; j < nr; j++) w[j] = avail[j];
  // make processes with request less than or equal to W

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
        for (j = 0; j < nr; j++) w[j] += alloc[i][j];
      }
    }
  }
  // checking for unmarked processes
  int deadlock = 0;
  for (i = 0; i < np; i++)
    if (mark[i] != 1) deadlock = 1;
  if (deadlock)
    cout << endl << " Deadlock detected \n";
  else
    cout << endl << "No deadlock possible" << endl;
  return 0;
}