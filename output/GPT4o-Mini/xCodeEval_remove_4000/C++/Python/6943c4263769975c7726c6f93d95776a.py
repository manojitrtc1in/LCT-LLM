from bitarray import bitarray
import sys

input = sys.stdin.read
B = 100 * 1000
MN = int(3e8 + 10)

is_ = bitarray(MN)
is_.setall(0)

