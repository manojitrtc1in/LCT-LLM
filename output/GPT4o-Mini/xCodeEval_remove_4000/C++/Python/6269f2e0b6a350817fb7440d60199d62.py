class ModInt:
    def __init__(self, value, mod=1000000007):
        self.mod = mod
        self.value = value % mod

    def __add__(self, other):
        return ModInt(self.value + other.value, self.mod)

    def __mul__(self, other):
        return ModInt(self.value * other.value, self.mod)

    def val(self):
        return self.value


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    q = int(data[0])
    index = 1
    results = []
    
    for _ in range(q):
        n = int(data[index])
        index += 1
        M = n // 4 + 1
        m = ModInt(M)
        
        if n % 4 <= 1:
            results.append((m * m).val())
        else:
            results.append((m * (m + ModInt(1))).val())
    
    print("\n".join(map(str, results)))


if __name__ == "__main__":
    main()
