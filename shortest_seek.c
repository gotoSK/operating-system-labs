// Shortest Seek Time Disk Scheduling Algorithm

/*
SSTF is a secondary storage scheduling algorithm that determines the motion of
the disk’s head and arm in servicing the read and write requests. SSTF acts as a
disk scheduling algorithm, and it is an improvement upon the FCFS algorithm. It
selects the requests with the least seek time starting from the current head
position. Scheduling priority goes to the processes with the shortest seek- even
if the requests aren’t the first ones in the queue.

SSTF implements this by calculating the seek time of every request in the queue
in advance. It then schedules the requests according to their seek time.
However, this process doesn’t ensure fairness and can lead to unspecified
postponement. The seek pattern is highly localized in SSTF, and it is like SJF
(Shortest Job First) because it can prevent distant requests from being serviced
under heavy load. This phenomenon is known as Starvation.
*/
#include <stdio.h>

struct head {
  int num;
  int flag;
};

int main() {
  struct head h[33];
  int array_1[33], array_2[33];
  int count = 0, j, x, limit, minimum, location, disk_head, sum = 0;
  printf("\nEnter total number of locations:\t");
  scanf("%d", &limit);
  printf("\nEnter position of disk head:\t");
  scanf("%d", &disk_head);
  printf("\nEnter elements of disk head queue\n");
  while (count < limit) {
    scanf("%d", &h[count].num);
    h[count].flag = 0;
    count++;
  }
  for (count = 0; count < limit; count++) {
    x = 0;
    minimum = 0;
    location = 0;
    for (j = 0; j < limit; j++) {
      if (h[j].flag == 0) {
        if (x == 0) {
          array_1[j] = disk_head - h[j].num;
          if (array_1[j] < 0) {
            array_1[j] = h[j].num - disk_head;
          }
          minimum = array_1[j];
          location = j;
          x++;
        } else {
          array_1[j] = disk_head - h[j].num;
          if (array_1[j] < 0) {
            array_1[j] = h[j].num - disk_head;
          }
        }
        if (minimum > array_1[j]) {
          minimum = array_1[j];
          location = j;
        }
      }
    }
    h[location].flag = 1;
    array_2[count] = h[location].num - disk_head;
    if (array_2[count] < 0) {
      array_2[count] = disk_head - h[location].num;
    }
    disk_head = h[location].num;
  }
  count = 0;
  while (count < limit) {
    sum = sum + array_2[count];
    count++;
  }
  printf("\nTotal movements of the cylinders:\t%d\n", sum);
  return 0;
}