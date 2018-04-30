#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the primeCount function below.
#
def primeCount(n):

    primorials = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

    i = 0
    sum = 1
    while i < 16 and sum <= n:

        sum = sum * primorials[i]
        i += 1

    return i - 1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(raw_input())

    for q_itr in xrange(q):
        n = int(raw_input())

        result = primeCount(n)

        fptr.write(str(result) + '\n')

    fptr.close()
