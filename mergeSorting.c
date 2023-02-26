#include "header.h"

/* fusion = merge
 * tri fusion = merge sorting */

Node *fusion(Node *liste1, Node *liste2) {
  if (liste1 == NULL) 
    return liste2;
  if (liste2 == NULL) 
    return liste1;
  if (liste1->val <= liste2->val)
    return (addFirst(fusion(removeElement(liste1, 0), liste2), liste1->val));
  else
    return (addFirst(fusion(removeElement(liste2, 0), liste1), liste2->val));
}

Node *triFusion(Node *liste) {
  if (liste->len <= 1) 
    return liste;
  else
    return fusion(triFusion(cutHalf(liste)[0]), triFusion(cutHalf(liste)[1]));
}

// int main() {
//   clock_t start, end;
//   double cpuTimeUsed;
// 
//   int list[] = {38, 27, 43, 3, 9, 82, 10};
//   size_t len = sizeof(list) / sizeof(int);
//   Node *lList = liste(list, len);
// 
//   start = clock();
//   Node *ret = triFusion(lList);
//   end = clock();
//   cpuTimeUsed = (end - start);
// 
//   printf("ORIGINAL\n");
//   display(lList);
//   bar();
//   printf("SORTED\n");
//   display(ret);
//   bar();
//   printf("time %lf seconds \n", cpuTimeUsed/CLOCKS_PER_SEC);
//   bar();
//   bar();
//   bar();
// }
