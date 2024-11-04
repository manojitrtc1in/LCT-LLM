import sys
import random

class InputReader:
    def __init__(self, stream):
        self.stream = stream
        self.buffer = []
    
    def read(self):
        if not self.buffer:
            self.buffer = list(map(int, self.stream.readline().split()))
        return self.buffer.pop(0)

    def read_int(self):
        return self.read()

    def read_long(self):
        return self.read()

class OutputWriter:
    def __init__(self, stream):
        self.writer = stream

    def print(self, array):
        self.writer.write(' '.join(map(str, array)))

    def print_line(self, array):
        self.print(array)
        self.writer.write('\n')

    def close(self):
        self.writer.close()

class TaskB:
    def __init__(self):
        self.x = 0

    def solve(self, test_number, in_reader, out_writer):
        count = in_reader.read_int()
        ones = in_reader.read_int()
        self.x = in_reader.read_long()
        a = list(range(1, count + 1))
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

        up_masks = [[0] * size for _ in range(32)]
        down_masks = [[0] * size for _ in range(32)]
        for i in range(32):
            filter_mask = (1 << (32 - i)) - 1 if i != 0 else -1
            other_shift = 32 - i
            for j in range(size):
                up_masks[i][j] = mask[j] & filter_mask
                down_masks[i][j] = mask[j] >> other_shift

        order = sorted(range(len(a)), key=lambda i: a[i], reverse=True)
        for i in order:
            value = a[i]
            shift = i & 31
            other_shift = 32 - shift
            filter_mask = (1 << (32 - shift)) - 1 if shift != 0 else -1
            start = i >> 5
            up_to = size - start - 1
            other_filter = (1 << shift) - 1 if (1 << shift) - 1 != -1 else 0

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

        out_writer.print_line(answer)

    def shuffle(self, count, a):
        for i in range(count):
            index = self.next() % (i + 1)
            a[i], a[index] = a[index], a[i]

    def next(self):
        self.x = (self.x * 37 + 10007) % 1000000007
        return self.x

def main():
    input_reader = InputReader(sys.stdin)
    output_writer = OutputWriter(sys.stdout)
    solver = TaskB()
    solver.solve(1, input_reader, output_writer)
    output_writer.close()

if __name__ == "__main__":
    main()
