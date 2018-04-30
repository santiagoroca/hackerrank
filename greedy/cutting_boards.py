#!/bin/python

import sys

def boardCutting(cost_y, cost_x):
    cost_y.sort()
    cost_x.sort()

    total_cost = 0
    horizontal_segments = 1
    vertical_segments = 1

    while cost_y or cost_x:

        if not cost_x:
            total_cost +=  cost_y.pop() *  vertical_segments
            horizontal_segments += 1
        elif not cost_y:
            total_cost +=  cost_x.pop() *  horizontal_segments
            vertical_segments += 1
        elif cost_y[len(cost_y) - 1] > cost_x[len(cost_x) - 1]:
            total_cost +=  cost_y.pop() *  vertical_segments
            horizontal_segments += 1
        else:
            total_cost +=  cost_x.pop() *  horizontal_segments
            vertical_segments += 1


    return total_cost



if __name__ == "__main__":
    q = int(raw_input().strip())
    for a0 in xrange(q):
        m, n = raw_input().strip().split(' ')
        m, n = [int(m), int(n)]
        cost_y = map(int, raw_input().strip().split(' '))
        cost_x = map(int, raw_input().strip().split(' '))
        result = boardCutting(cost_y, cost_x)
        print result
