#!/usr/bin/env python3

import math

def merge(L, R):
    ret = []
    lenRet, i, j = len(L)+len(R), 0, 0
    endL, endR = False, False
    for _ in range(lenRet):
        if endL == True:
            ret.append(R[j])
            j += 1
        elif endR == True:
            ret.append(L[i])
            i += 1
        elif L[i] <= R[j]:
            ret.append(L[i])
            i += 1
            if i >= len(L):
                endL = True
        elif R[j] <= L[i]:
            ret.append(R[j])
            j += 1
            if j >= len(R):
                endR = True
    return ret

def mergeSort(array):
    n = len(array)
    halfLen = math.floor(n/2)
    if n <= 1:
        return array
    L = mergeSort(array[:halfLen])
    R = mergeSort(array[halfLen:])
    return merge(L, R)

if __name__ == "__main__":
    myList = [2, 4, 32, 244, 4, 10]
    print(mergeSort(myList))
