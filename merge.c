#include "header.h"
#include "mergeSorting.h"

#define MERGE_SORTING 0
#define OTHER_STRAT 1

int testLen(Node *ll1, Node *ll2) {
  /* 1 -> l1 > l2
   * 2 -> l2 > l1 */
  if (ll1->len > ll2->len) return 1;
  else return 2;
}

int testGreater(Node *ll1, Node *ll2) {
  /* 1 -> l2 + l1
   * 2 -> l1 + l2 */
  int extremes1[] = {ll1->val, getLastElementVal(ll1)},
      extremes2[] = {ll2->val, getLastElement(ll2)};
  if (extremes1[0] > extremes2[1]) return 1;
  if (extremes2[0] > extremes1[1]) return 2;
  return 0;
}

Node *merge(Node *ll1, Node *ll2, int strat) {
  Node *trieL1 = triFusion(ll1),
       *trieL2 = triFusion(ll2);
  size_t lenTot = ll1->len + ll2->len - 1;
  switch (testGreater(trieL1, trieL2)) {
    case 0:
      switch (strat) {
        case MERGE_SORTING:
          getLastElement(trieL1)->next = trieL2;
          trieL2->prev = getLastElement(trieL1);
          updateLen(trieL1, lenTot);
          return triFusion(trieL1);
      }
    case 1:
      getLastElement(trieL2)->next = trieL1;
      trieL1->prev = getLastElement(trieL2);
      updateLen(trieL2, lenTot);
      return trieL2;
    case 2:
      getLastElement(trieL1)->next = trieL2;
      trieL2->prev = getLastElement(trieL1);
      updateLen(trieL1, lenTot);
      return trieL1;
  }
}

int main() {
  int l1[] = {1, 38, 22, 29089, 2, 1, 222};
  int l2[] = {1, 38, 2232, 2, 19, 1000, 2909, 20000};
  size_t lenl1 = sizeof(l1) / sizeof(int),
         lenl2 = sizeof(l2) / sizeof(int);
  Node *ll1 = liste(l1, lenl1),
       *ll2 = liste(l2, lenl2);
  Node *ret1 = merge(ll1, ll2, MERGE_SORTING);
  display(ret1);
}
