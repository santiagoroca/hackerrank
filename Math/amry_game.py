#!/bin/python

from __future__ import print_function

import os
import sys
from math import ceil

#
# Complete the gameWithCells function below.
#
def gameWithCells(n, m):
    return (int(n / 2) + n % 2) * (int(m / 2) + m % 2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = raw_input().split()

    n = int(nm[0])

    m = int(nm[1])

    result = gameWithCells(n, m)

    fptr.write(str(result) + '\n')

    fptr.close()
