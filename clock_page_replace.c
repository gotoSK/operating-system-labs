// CLock Page Replacement Algorithm

/*
The Clock Page Replacement Algorithm
Although second chance is a reasonable algorithm, it is unnecessarily
inefficient because it is constantly moving pages around on its list. A better
approach is to keep all the page frames on a circular list in the form of a
clock, as shown in Fig. below. • A hand points to the oldest page. When a page
fault occurs, the page being pointed to by the hand is inspected.

fig
When a page fault occurs.
the page the hand is
pointing to is inspected.
The action taken depends
the R hit:
R = 0 : Evict the page
R = 1: Clear R and advance hand

If its R bit is 0, the page is evicted, the new page is inserted into the clock
in its place, and the hand is advanced one position. If R is 1, it is cleared
and the hand is advanced to the next page. This process is repeated until a page
is found with R = 0. Not surprisingly, this algorithm is called clock. It
differs from second chance only in the implementation.
*/
#include <stdio.h>
int main() {
  int n, p[100], f[10], ava, hit = 0, usebit[10], i, j;
  printf("Enter the length of the Reference string: ");
  scanf("%d", &n);
  printf("Enter the reference string: \n");

  for (i = 0; i < n; i++) scanf("%d", &p[i]);
  for (i = 0; i < n; i++) {
    ava = 0;
    // found
    for (j = 0; j < 3; j++) {
      if (p[i] == f[j]) {
        ava = 1;
        hit++;
        usebit[j] = 1;
        break;
      }
    }
    // search for usebit 0
    if (ava == 0) {
      for (j = 0; j < 3; j++) {
        if (usebit[j] == 0) {
          f[j] = p[i];
          usebit[j] = 1;
          ava = 1;
          break;
        }
      }
    }
    // fifo
    if (ava == 0) {
      for (j = 0; j < 3; j++) usebit[j] = 0;
    }
    f[0] = p[i];
    usebit[0] = 1;
  }
  printf("The number of Page hits: %d\n", hit);
  return 0;
}