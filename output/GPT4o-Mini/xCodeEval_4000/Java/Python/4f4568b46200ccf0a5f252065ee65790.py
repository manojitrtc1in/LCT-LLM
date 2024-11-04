import sys
from math import isqrt
from sympy import isprime

class MyScanner:
    def __init__(self, file=None):
        if file:
            self.br = open(file, 'r')
        else:
            self.br = sys.stdin

    def next_token(self):
        return self.br.readline().strip()

    def next_int(self):
        return int(self.next_token())

class C:
    shift = 100000
    maxn = 300000000

    prec = [0, 4784, 8978, 12981, 16901, 20732, 24523, 28249,
            31916, 35585, 39176, 42818, 46430, 49962, 53516, 57023, 60523,
            64040, 67489, 70985, 74417, 77879, 81285, 84679, 88055, 91433,
            94878, 98240, 101608, 104979, 108284, 111653, 115039, 118375,
