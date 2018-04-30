#!/bin/python

from __future__ import print_function

import os
import sys

#
# Complete the connectingTowns function below.
#
def connectingTowns(n, routes):
    return reduce(lambda x, y: x * y, routes, 1) % 1234567

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        routes = map(int, raw_input().rstrip().split())

        result = connectingTowns(n, routes)

        fptr.write(str(result) + '\n')

    fptr.close()
