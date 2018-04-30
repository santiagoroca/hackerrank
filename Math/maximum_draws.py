#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the maximumDraws function below.
#
def maximumDraws(n):
    return n + 1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        result = maximumDraws(n)

        fptr.write(str(result) + '\n')

    fptr.close()
