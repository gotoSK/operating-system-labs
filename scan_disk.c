// Scan disk scheduling
// SSTF

/*
In SCAN disk scheduling algorithm, head starts from one end of the disk and
moves towards the other end, servicing requests in between one by one and reach
the other end. Then the direction of the head is reversed and the process
continues as head continuously scan back and forth to access the disk. So, this
algorithm works as an elevator and hence also known as the elevator algorithm.
As a result, the requests at the midrange are serviced more and those arriving
behind the disk arm will have to wait.

Advantages of SCAN (Elevator) algorithm

This algorithm is simple and easy to understand.
SCAN algorithm have no starvation.
This algorithm is better than FCFS Scheduling algorithm .
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
  int i, j, sum = 0, n;
  int d[20];
  int disk;  // loc of head
  int temp, max;
  int dloc;  // loc of disk in array
  printf("Enter number of location:\t");
  scanf("%d", &n);
  printf("Enter position of head:\t");
  scanf("%d", &disk);
  printf("Enter elements of disk queue:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }
  d[n] = disk;
  n = n + 1;
  for (i = 0; i < n; i++)  // sorting disk locations
  {
    for (j = i; j < n; j++) {
      if (d[i] > d[j]) {
        temp = d[i];
        d[i] = d[j];
        d[j] = temp;
      }
    }
  }
  max = d[n];
  for (i = 0; i < n; i++)  // to find loc of disc in array
  {
    if (disk == d[i]) {
      dloc = i;
      break;
    }
  }
  for (i = dloc; i >= 0; i--) {
    printf("%d -->", d[i]);
  }
  printf("0 -->");
  for (i = dloc + 1; i < n; i++) {
    printf("%d-->", d[i]);
  }
  sum = disk + max;
  printf("\nmovement of total cylinders %d", sum);
  return 0;
}
