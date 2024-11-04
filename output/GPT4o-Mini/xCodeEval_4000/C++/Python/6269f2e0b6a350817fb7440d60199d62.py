class ModInt:
    def __init__(self, value, mod=1000000007):
        self.value = value % mod
        self.mod = mod

    def __add__(self, other):
        return ModInt(self.value + other.value, self.mod)

    def __sub__(self, other):
        return ModInt(self.value - other.value, self.mod)

    def __mul__(self, other):
        return ModInt(self.value * other.value, self.mod)

    def __pow__(self, exp):
