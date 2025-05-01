// Second Chance
/*
The Second Chance Page Replacement Algorithm
A simple modification to FIFO that avoids the problem of throwing out a heavily
used page is to inspect the R bit of the oldest page. If it is 0, the page is
both old and unused, so it is replaced immediately. If the R bit is 1, the bit
is cleared, the page is put onto the end of the list of pages, and its load time
is updated as though it had just arrived in memory. Then the search continues.
The operation of this algorithm is called second chance.
What second chance is doing is looking for an old page that has not been
referenced in the previous clock interval. If all the pages have been
referenced, second chance degenerates into pure FIFO.
*/
#include <stdio.h>
#define FN 4  // frame number
#define RB 0  // reference bit
#define PN 1  // page number
int main(void) {
  // hp = hand pointer, in = input, pt = page table
  int rgPT[FN][2] = {0}, nHP = 3, nIn, iPT;

  printf("Enter: ");
  while (scanf("%d", &nIn)) {
    getchar();

    // search page table
    for (iPT = 0; rgPT[iPT][PN] != nIn && iPT < FN; iPT++)
      ;

    // failed to retrieve
    if (rgPT[iPT][PN] != nIn) {
      // search for a victim
      do {
        nHP = (nHP + 1) % FN;
      } while (!(rgPT[nHP][RB] == 1 ? rgPT[nHP][RB] = 0 : 1));
      // update the page table
      rgPT[nHP][RB] = 1;
      rgPT[nHP][PN] = nIn;
    }

    // retrieved
    else
      rgPT[iPT][RB] = 1;

    // show page table state
    puts("Page table:");
    for (iPT = 0; iPT < FN; iPT++)
      printf("%s %d, %d.\n", iPT == (nHP + 1) % 4 ? ">" : " ", rgPT[iPT][RB],
             rgPT[iPT][PN]);
    putchar('\n');

    printf("Enter: ");
  }
  puts("May the Roses bloom upon your Cross. ");

  return 0;
}