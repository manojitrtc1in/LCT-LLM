import sys
from io import IOBase, BytesIO
import os
import math
import bisect
from collections import deque, defaultdict
from heapq import heapify, heappop, heappush

class TaskB:
    def __init__(self):
        self.x = 0

    def solve(self, testNumber, in_stream, out_stream):
        count = int(in_stream.readline())
        ones = int(in_stream.readline())
        self.x = int(in_stream.readline())
        a = [i + 1 for i in range(count)]
        self.shuffle(count, a)
        b = [1] * ones + [0] * (count - ones)
        self.shuffle(count, b)
        answer = [0] * count
        size = (count + 31) // 32
        ready = [0] * size
        mask = [0] * size
        for i in range(size):
            for j in range(i * 32, min((i + 1) * 32, count)):
                if b[j] == 1:
                    mask[i] += 1 << (j - i * 32)
        upMasks = [[0] * size for _ in range(32)]
        downMasks = [[0] * size for _ in range(32)]
        for i in range(32):
            if i == 0:
                filter = -1
            else:
                filter = (1 << (32 - i)) - 1
            otherShift = 32 - i
            for j in range(size):
                upMasks[i][j] = mask[j] & filter
                downMasks[i][j] = mask[j] >> otherShift
        order = sorted(range(count), key=lambda x: a[x], reverse=True)
        for i in order:
            value = a[i]
            shift = i & 31
            otherShift = 32 - shift
            if shift == 0:
                filter = -1
            else:
                filter = (1 << (32 - shift)) - 1
            start = i >> 5
            upTo = size - start - 1
            otherFilter = (1 << shift) - 1
            if otherFilter == -1:
                otherFilter = 0
            for j in range(upTo):
                if (ready[j + start] >> shift & upMasks[shift][j]) != upMasks[shift][j]:
                    for k in range((j + start) * 32 + shift, min((j + start + 1) * 32, count)):
                        if b[k - i] == 1 and answer[k] == 0:
                            answer[k] = value
                            ready[k >> 5] += 1 << (k & 31)
                if (ready[j + start + 1] & downMasks[shift][j]) != downMasks[shift][j]:
                    for k in range((j + start + 1) * 32, min((j + start + 1) * 32 + shift, count)):
                        if b[k - i] == 1 and answer[k] == 0:
                            answer[k] = value
                            ready[k >> 5] += 1 << (k & 31)
            if (ready[upTo + start] >> shift & upMasks[shift][upTo]) != upMasks[shift][upTo]:
                for k in range((upTo + start) * 32 + shift, min((upTo + start + 1) * 32, count)):
                    if b[k - i] == 1 and answer[k] == 0:
                        answer[k] = value
                        ready[k >> 5] += 1 << (k & 31)
        out_stream.write(' '.join(map(str, answer)) + '\n')

    def shuffle(self, count, a):
        for i in range(count):
            index = self.next() % (i + 1)
            temp = a[i]
            a[i] = a[index]
            a[index] = temp

    def next(self):
        self.x = (self.x * 37 + 10007) % 1000000007
        return self.x

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        while True:
            c = self.stream.read(1)
            if c == '\n' or c == ' ':
                continue
            return c

    def read_int(self):
        c = self.read()
        while c == ' ':
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while c != ' ' and c != '\n':
            res *= 10
            res += int(c)
            c = self.read()
        return res * sgn

    def read_long(self):
        c = self.read()
        while c == ' ':
            c = self.read()
        sgn = 1
        if c == '-':
            sgn = -1
            c = self.read()
        res = 0
        while c != ' ' and c != '\n':
            res *= 10
            res += int(c)
            c = self.read()
        return res * sgn

class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def print(self, array):
        for i in range(len(array)):
            if i != 0:
                self.stream.write(' ')
            self.stream.write(str(array[i]))

    def print_line(self, array):
        self.print(array)
        self.stream.write('\n')

    def close(self):
        self.stream.close()

def main():
    input_stream = InputReader(sys.stdin)
    output_stream = OutputWriter(sys.stdout)
    solver = TaskB()
    solver.solve(1, input_stream, output_stream)
    output_stream.close()

if __name__ == "__main__":
    main()
