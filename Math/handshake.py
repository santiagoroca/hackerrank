#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the handshake function below.
#
def handshake(n):
    return (n - 1) * (n) / 2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        result = handshake(n)

        fptr.write(str(result) + '\n')

    fptr.close()
