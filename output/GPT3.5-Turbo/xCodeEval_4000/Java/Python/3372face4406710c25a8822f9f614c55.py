import sys
from typing import List
from random import randint

class TaskB:
    def __init__(self):
        self.x = 0

    def solve(self, test_number: int, count: int, ones: int, x: int) -> List[int]:
        self.x = x
        a = [i + 1 for i in range(count)]
        self.shuffle(count, a)
        b = [1] * ones + [0] * (count - ones)
        self.shuffle(count, b)
        answer = [0] * count
        size = (count + 31) >> 5
        ready = [0] * size
        mask = [0] * size
        for i in range(size):
            for j in range(i * 32, min((i + 1) * 32, count)):
                if b[j] == 1:
                    mask[i] += 1 << (j - i * 32)
        up_masks = [[0] * size for _ in range(32)]
        down_masks = [[0] * size for _ in range(32)]
        for i in range(32):
            if i == 0:
                filter_val = -1
            else:
                filter_val = (1 << (32 - i)) - 1
            other_shift = 32 - i
            for j in range(size):
                up_masks[i][j] = mask[j] & filter_val
                down_masks[i][j] = mask[j] >> other_shift
        order = sorted(range(count), key=lambda i: a[i], reverse=True)
        for i in order:
            value = a[i]
            shift = i & 31
            other_shift = 32 - shift
            if shift == 0:
                filter_val = -1
            else:
                filter_val = (1 << (32 - shift)) - 1
            start = i >> 5
            up_to = size - start - 1
            other_filter = (1 << shift) - 1
            if other_filter == -1:
                other_filter = 0
            for j in range(up_to):
                if (ready[j + start] >> shift & up_masks[shift][j]) != up_masks[shift][j]:
                    for k in range((j + start) * 32 + shift, min((j + start + 1) * 32, count)):
                        if b[k - i] == 1 and answer[k] == 0:
                            answer[k] = value
                            ready[k >> 5] += 1 << (k & 31)
                if (ready[j + start + 1] & down_masks[shift][j]) != down_masks[shift][j]:
                    for k in range((j + start + 1) * 32, min((j + start + 1) * 32 + shift, count)):
                        if b[k - i] == 1 and answer[k] == 0:
                            answer[k] = value
                            ready[k >> 5] += 1 << (k & 31)
            if (ready[up_to + start] >> shift & up_masks[shift][up_to]) != up_masks[shift][up_to]:
                for k in range((up_to + start) * 32 + shift, min((up_to + start + 1) * 32, count)):
                    if b[k - i] == 1 and answer[k] == 0:
                        answer[k] = value
                        ready[k >> 5] += 1 << (k & 31)
        return answer

    def shuffle(self, count: int, a: List[int]) -> None:
        for i in range(count):
            index = self.next() % (i + 1)
            a[i], a[index] = a[index], a[i]

    def next(self) -> int:
        self.x = (self.x * 37 + 10007) % 1000000007
        return self.x

def main() -> None:
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_ = InputReader(input_stream)
    out = OutputWriter(output_stream)
    solver = TaskB()
    solver.solve(1, in_, out)
    out.close()

class InputReader:
    def __init__(self, stream):
        self.stream = stream

    def read(self):
        return self.stream.read().strip()

    def read_int(self):
        return int(self.read())

    def read_long(self):
        return int(self.read())

    def read_list(self):
        return list(map(int, self.read().split()))

class OutputWriter:
    def __init__(self, stream):
        self.stream = stream

    def print_line(self, line):
        self.stream.write(str(line) + '\n')

    def close(self):
        self.stream.close()

if __name__ == '__main__':
    main()
