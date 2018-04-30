#!/bin/python

import sys
from math import ceil

def lowestTriangle(base, area):
    return int(ceil((float(area) * 2) / float(base)))

base, area = raw_input().strip().split(' ')
base, area = [int(base), int(area)]
height = lowestTriangle(base, area)
print(height)
