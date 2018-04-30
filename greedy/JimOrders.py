#!/bin/python

import sys

class PriorityQueue:

    def __init__(self):
        self.queue = []


    def push(self, value):
        self.queue.append(value)
        index = len(self.queue) - 1
        parent = int((index - 1) / 2)

        while index != 0 and self.queue[index][1] < self.queue[parent][1]:
            swap = self.queue[index]
            self.queue[index] = self.queue[parent]
            self.queue[parent] = swap
            index = parent
            parent = int((index - 1) / 2)


    def pop(self):

        if len(self.queue) == 0:
            return

        self.queue[0] = self.queue[len(self.queue) - 1]
        del self.queue[-1]
        self.reorder(0)


    def reorder(self, index):
        left, right = [ 2 * index + 1, 2 * index + 2 ]
        parent = index
        count = len(self.queue)

        if left < count and self.queue[left][1] <= self.queue[parent][1]:
            parent = left

        if right < count and self.queue[right][1] <= self.queue[parent][1]:
            parent = right

        if parent != index:
            swap = self.queue[parent]
            self.queue[parent] = self.queue[index]
            self.queue[index] = swap
            self.reorder(parent)


def jimOrders(orders):
    queue = PriorityQueue()

    for i in range(len(orders)):
        queue.push((i + 1, orders[i][0] + orders[i][1]))

    result = []

    for i in range(len(queue.queue)):
        result.append(queue.queue[0][0])
        queue.pop()

    return result

if __name__ == "__main__":
    n = int(raw_input().strip())
    orders = []
    for orders_i in xrange(n):
        orders_temp = map(int,raw_input().strip().split(' '))
        orders.append(orders_temp)
    result = jimOrders(orders)
    print " ".join(map(str, result))
