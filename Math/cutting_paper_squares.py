#!/bin/python

import sys

def solve(n, m):
    return n * m - 1

n, m = raw_input().strip().split(' ')
n, m = [int(n), int(m)]
result = solve(n, m)
print(result)
