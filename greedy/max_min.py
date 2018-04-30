#!/bin/python

import sys

def angryChildren(k, arr):

    arr.sort()

    min = arr[k - 1] - arr[0]

    for i in range(1, len(arr) - k + 1):
        if arr[i + k - 1] - arr[i] < min:
            min = arr[i + k - 1] - arr[i]

    return min


if __name__ == "__main__":
    n = int(raw_input().strip())
    k = int(raw_input().strip())
    arr = []
    arr_i = 0
    for arr_i in xrange(n):
        arr_t = int(raw_input().strip())
        arr.append(arr_t)
    result = angryChildren(k, arr)
    print result
