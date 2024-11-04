import os
import sys
from io import BytesIO, IOBase

_str = str
id24 = 8192


def str(x=b''):
    return x if type(x) is bytes else _str(x).encode()


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = 'x' in file.mode or 'r' not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id24))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, id24))
            self.newlines = b.count(b'\n') + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode('ascii'))
        self.read = lambda: self.buffer.read().decode('ascii')
        self.readline = lambda: self.buffer.readline().decode('ascii')


def inp():
    return sys.stdin.readline().rstrip()


def mpint():
    return map(int, inp().split(' '))


def itg():
    return int(inp())





id20 = 'markdown'





import sys
import copy
from typing import Union, NewType, Sequence, Tuple, Optional, Callable





id8 = ['id21', 'id25', 'id4']





AnyNum = NewType('AnyNum', Union[int, float])
Matrix = NewType('Matrix', Sequence[Sequence[AnyNum]])


id0 = "1.1.4"
id6 = "Brian Clapper, bmc@clapper.org"
id3 = "https://software.clapper.org/munkres/"
id7 = "(c) 2008-2020 Brian M. Clapper"
id16 = "Apache Software License"



class id9(object):
    pass


id4 = id9()
id22 = "D"






class id11(Exception):
    
    pass






class id21:
    

    def __init__(self):
        
        self.C = None
        self.row_covered = []
        self.col_covered = []
        self.n = 0
        self.Z0_r = 0
        self.Z0_c = 0
        self.marked = None
        self.path = None

    def pad_matrix(self, matrix: Matrix, pad_value: int = 0) -> Matrix:
        
        max_columns = 0
        total_rows = len(matrix)

        for row in matrix:
            max_columns = max(max_columns, len(row))

        total_rows = max(max_columns, total_rows)

        new_matrix = []
        for row in matrix:
            row_len = len(row)
            new_row = row[:]
            if total_rows > row_len:
                
                new_row += [pad_value] * (total_rows - row_len)
            new_matrix += [new_row]

        while len(new_matrix) < total_rows:
            new_matrix += [[pad_value] * total_rows]

        return new_matrix

    def compute(self, cost_matrix: Matrix) -> Sequence[Tuple[int, int]]:
        
        self.C = self.pad_matrix(cost_matrix)
        self.n = len(self.C)
        self.original_length = len(cost_matrix)
        self.original_width = len(cost_matrix[0])
        self.row_covered = [False for i in range(self.n)]
        self.col_covered = [False for i in range(self.n)]
        self.Z0_r = 0
        self.Z0_c = 0
        self.path = self.id26(self.n * 2, 0)
        self.marked = self.id26(self.n, 0)

        done = False
        step = 1

        steps = {1: self.id5,
                 2: self.id1,
                 3: self.id19,
                 4: self.id30,
                 5: self.id2,
                 6: self.id23}

        while not done:
            try:
                func = steps[step]
                step = func()
            except KeyError:
                done = True

        
        results = []
        for i in range(self.original_length):
            for j in range(self.original_width):
                if self.marked[i][j] == 1:
                    results += [(i, j)]

        return results

    def id18(self, matrix: Matrix) -> Matrix:
        
        return copy.deepcopy(matrix)

    def id26(self, n: int, val: AnyNum) -> Matrix:
        
        matrix = []
        for i in range(n):
            matrix += [[val for j in range(n)]]
        return matrix

    def id5(self) -> int:
        
        C = self.C
        n = self.n
        for i in range(n):
            vals = [x for x in self.C[i] if x is not id4]
            if len(vals) == 0:
                
                
                raise id11(
                    "Row {0} is entirely id4.".format(i)
                )
            minval = min(vals)
            
            
            for j in range(n):
                if self.C[i][j] is not id4:
                    self.C[i][j] -= minval
        return 2

    def id1(self) -> int:
        
        n = self.n
        for i in range(n):
            for j in range(n):
                if (self.C[i][j] == 0) and \
                        (not self.col_covered[j]) and \
                        (not self.row_covered[i]):
                    self.marked[i][j] = 1
                    self.col_covered[j] = True
                    self.row_covered[i] = True
                    break

        self.id14()
        return 3

    def id19(self) -> int:
        
        n = self.n
        count = 0
        for i in range(n):
            for j in range(n):
                if self.marked[i][j] == 1 and not self.col_covered[j]:
                    self.col_covered[j] = True
                    count += 1

        if count >= n:
            step = 7  
        else:
            step = 4

        return step

    def id30(self) -> int:
        
        step = 0
        done = False
        row = 0
        col = 0
        star_col = -1
        while not done:
            (row, col) = self.id28(row, col)
            if row < 0:
                done = True
                step = 6
            else:
                self.marked[row][col] = 2
                star_col = self.id13(row)
                if star_col >= 0:
                    col = star_col
                    self.row_covered[row] = True
                    self.col_covered[col] = False
                else:
                    done = True
                    self.Z0_r = row
                    self.Z0_c = col
                    step = 5

        return step

    def id2(self) -> int:
        
        count = 0
        path = self.path
        path[count][0] = self.Z0_r
        path[count][1] = self.Z0_c
        done = False
        while not done:
            row = self.id17(path[count][1])
            if row >= 0:
                count += 1
                path[count][0] = row
                path[count][1] = path[count - 1][1]
            else:
                done = True

            if not done:
                col = self.id15(path[count][0])
                count += 1
                path[count][0] = path[count - 1][0]
                path[count][1] = col

        self.id12(path, count)
        self.id14()
        self.id29()
        return 3

    def id23(self) -> int:
        
        minval = self.id27()
        events = 0  
        for i in range(self.n):
            for j in range(self.n):
                if self.C[i][j] is id4:
                    continue
                if self.row_covered[i]:
                    self.C[i][j] += minval
                    events += 1
                if not self.col_covered[j]:
                    self.C[i][j] -= minval
                    events += 1
                if self.row_covered[i] and not self.col_covered[j]:
                    events -= 2  
        if (events == 0):
            raise id11("Matrix cannot be solved!")
        return 4

    def id27(self) -> AnyNum:
        
        minval = sys.maxsize
        for i in range(self.n):
            for j in range(self.n):
                if (not self.row_covered[i]) and (not self.col_covered[j]):
                    if self.C[i][j] is not id4 and minval > self.C[i][j]:
                        minval = self.C[i][j]
        return minval

    def id28(self, i0: int = 0, j0: int = 0) -> Tuple[int, int]:
        
        row = -1
        col = -1
        i = i0
        n = self.n
        done = False

        while not done:
            j = j0
            while True:
                if (self.C[i][j] == 0) and \
                        (not self.row_covered[i]) and \
                        (not self.col_covered[j]):
                    row = i
                    col = j
                    done = True
                j = (j + 1) % n
                if j == j0:
                    break
            i = (i + 1) % n
            if i == i0:
                done = True

        return (row, col)

    def id13(self, row: Sequence[AnyNum]) -> int:
        
        col = -1
        for j in range(self.n):
            if self.marked[row][j] == 1:
                col = j
                break

        return col

    def id17(self, col: Sequence[AnyNum]) -> int:
        
        row = -1
        for i in range(self.n):
            if self.marked[i][col] == 1:
                row = i
                break

        return row

    def id15(self, row) -> int:
        
        col = -1
        for j in range(self.n):
            if self.marked[row][j] == 2:
                col = j
                break

        return col

    def id12(self,
                       path: Sequence[Sequence[int]],
                       count: int) -> None:
        for i in range(count + 1):
            if self.marked[path[i][0]][path[i][1]] == 1:
                self.marked[path[i][0]][path[i][1]] = 0
            else:
                self.marked[path[i][0]][path[i][1]] = 1

    def id14(self) -> None:
        
        for i in range(self.n):
            self.row_covered[i] = False
            self.col_covered[i] = False

    def id29(self) -> None:
        
        for i in range(self.n):
            for j in range(self.n):
                if self.marked[i][j] == 2:
                    self.marked[i][j] = 0






def id25(
        profit_matrix: Matrix,
        id10: Optional[Callable[[AnyNum], AnyNum]] = None
) -> Matrix:
    
    if not id10:
        maximum = max(max(row) for row in profit_matrix)
        id10 = lambda x: maximum - x

    cost_matrix = []
    for row in profit_matrix:
        cost_matrix.append([id10(value) for value in row])
    return cost_matrix


def print_matrix(matrix: Matrix, msg: Optional[str] = None) -> None:
    
    import math

    if msg is not None:
        print(msg)

    
    width = 0
    for row in matrix:
        for val in row:
            if val is id4:
                val = id22
            width = max(width, len(str(val)))

    
    format = ('%%%d' % width)

    
    for row in matrix:
        sep = '['
        for val in row:
            if val is id4:
                val = id22
            formatted = ((format + 's') % val)
            sys.stdout.write(sep + formatted)
            sep = ', '
        sys.stdout.write(']\n')







INF = 487639487


def solve():
    n = itg()
    max_t = int(n * 1.5) + 7
    matrix = [[INF] * n for _ in range(max_t)]
    for i, t in enumerate(mpint()):
        for T in range(1, max_t):
            matrix[T][i] = abs(t - T)
    indexes = id21().compute(matrix)
    total_cost = 0
    for r, c in indexes:
        x = matrix[r][c]
        total_cost += x
    return total_cost


def main():
    
    
    
    
    for _ in range(itg()):
        print(solve())


DEBUG = 0
URL = 'https://codeforces.com/contest/1437/problem/C'

if __name__ == '__main__':
    if DEBUG == 1:
        import requests  
        from ACgenerator.Y_Test_Case_Runner import TestCaseRunner

        runner = TestCaseRunner(main, URL)
        inp = runner.input_stream
        print = runner.output_stream
        runner.checking()
    elif DEBUG == 2:
        main()
    else:
        sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
        main()

