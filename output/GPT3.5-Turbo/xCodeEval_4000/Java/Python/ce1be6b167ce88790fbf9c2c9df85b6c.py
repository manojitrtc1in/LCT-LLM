import sys
from typing import List

class FastScanner:
    def __init__(self):
        self.sin = sys.stdin.buffer
        self.buffer = bytearray()
        self.ptr = 0
        self.buflen = 0
    
    def hasNextByte(self) -> bool:
        if self.ptr < self.buflen:
            return True
        else:
            self.ptr = 0
            self.buflen = self.sin.readinto(self.buffer)
            if self.buflen <= 0:
                return False
        return True
    
    def readByte(self) -> int:
        if self.hasNextByte():
            result = self.buffer[self.ptr]
            self.ptr += 1
            return result
        else:
            return -1
    
    def isPrintableChar(self, c: int) -> bool:
        return 33 <= c <= 126
    
    def hasNext(self) -> bool:
        while self.hasNextByte() and not self.isPrintableChar(self.buffer[self.ptr]):
            self.ptr += 1
        return self.hasNextByte()
    
    def next(self) -> str:
        if not self.hasNext():
            raise ValueError("No more tokens are available.")
        sb = []
        b = self.readByte()
        while self.isPrintableChar(b):
            sb.append(chr(b))
            b = self.readByte()
        return "".join(sb)
    
    def longNext(self) -> int:
        if not self.hasNext():
            raise ValueError("No more tokens are available.")
        n = 0
        minus = False
        b = self.readByte()
        if b == ord("-"):
            minus = True
            b = self.readByte()
        if not ord("0") <= b <= ord("9"):
            raise ValueError("Invalid long format")
        while True:
            if ord("0") <= b <= ord("9"):
                n *= 10
                n += b - ord("0")
            elif b == -1 or not self.isPrintableChar(b) or b == ord(":"):
                return -n if minus else n
            else:
                raise ValueError("Invalid long format")
            b = self.readByte()
    
    def intNext(self) -> int:
        nl = self.longNext()
        if nl < -2147483648 or nl > 2147483647:
            raise ValueError("Value out of range")
        return nl
    
    def nextLongArray(self, n: int) -> List[int]:
        a = [0] * n
        for i in range(n):
            a[i] = self.longNext()
        return a
    
    def nextIntArray(self, n: int) -> List[int]:
        a = [0] * n
        for i in range(n):
            a[i] = self.intNext()
        return a

class FastWriter:
    def __init__(self):
        self.out = []
    
    def p(self, obj) -> 'FastWriter':
        self.out.append(str(obj))
        return self
    
    def pp(self, *args) -> 'FastWriter':
        for ob in args:
            self.out.append(str(ob))
            self.out.append(" ")
        self.out.append("\n")
        return self
    
    def println(self, arr: List[int]) -> None:
        for e in arr:
            self.out.append(str(e))
            self.out.append(" ")
        self.out.append("\n")
    
    def toFile(self, fileName: str) -> None:
        with open(fileName, "w") as f:
            f.write("".join(self.out))
    
    def close(self) -> None:
        print("".join(self.out), end='')

class E:
    def solver(self) -> None:
        n = in.intNext()
        ar = in.nextLongArray(3)
        br = in.nextLongArray(3)
        mxWins = 0
        mxLosesOrDraw = 0
        draws = 0
        for i in range(3):
            mxWins += min(ar[i], br[(i + 1) % 3])
            mxLose = min(br[i], ar[(i + 1) % 3])
            mxDraw = min(br[i], ar[i])
            mxLosesOrDraw += min(br[i], mxLose + mxDraw)
        out.pp(n - mxLosesOrDraw, mxWins)

out = FastWriter()
in = FastScanner()
E().solver()
out.close()
