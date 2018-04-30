#!/bin/python

from __future__ import print_function

import os
import sys
from math import sqrt

#
# Complete the movingTiles function below.
#
def movingTiles(l, s1, s2, queries):

    length = sqrt(l**2 * 2)
    results = []

    for i in range(len(queries)):
        if queries[i] == sqrt(2) * l:
            results.append(0.0)
        else:
            results.append(format(sqrt(2) * (l - sqrt(queries[i])) / abs(s2 - s1), '.20f'))

    return results

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    lS1S2 = raw_input().split()

    l = int(lS1S2[0])

    s1 = int(lS1S2[1])

    s2 = int(lS1S2[2])

    queries_count = int(raw_input())

    queries = []

    for _ in xrange(queries_count):
        queries_item = int(raw_input())
        queries.append(queries_item)

    result = movingTiles(l, s1, s2, queries)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
