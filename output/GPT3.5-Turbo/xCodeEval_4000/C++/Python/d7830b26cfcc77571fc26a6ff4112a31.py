import math
import random

class Base:
    def f(self, label="bd"):
        print(label + ":base")

class Derived(Base):
    def f(self, label="dd"):
        print(label + ":derived")

def build_random_tree(tree, node):
    ancestor = [i for i in range(100)]
    random.seed()
    for i in range(1, node):
        node1 = random.randint(0, 99)
        node2 = random.randint(0, 99)
        par1 = node1
        par2 = node2
        while ancestor[par1] != par1:
            par1 = ancestor[par1]
        while ancestor[par2] != par2:
            par2 = ancestor[par2]
        ancestor[par1] = par2

def main():
    test_cases = 1

    pow2 = [1] * 18
    for i in range(1, 18):
        pow2[i] = pow2[i-1] * 2

    print("{:.10f}".format(math.pi))

    for T in range(test_cases):
        s = ""
        t = ""
        m1 = ""
        m2 = ""
        k = 0
        n = 0
        m = 0
        p = 0
        n, k = map(int, input().split())
        bamboo = list(map(int, input().split()))
        bamboo.sort()
        bamboo_sum = [0] * 111
        bamboo_sum[0] = bamboo[0]
        max_val = 0
        for i in range(1, n):
            bamboo_sum[i] = bamboo[i] + bamboo_sum[i-1]
            m = i * bamboo[i] - bamboo_sum[i-1]
            if m > k and max_val == 0:
                max_val = bamboo[i]
        if max_val == 0:
            remaining = k + bamboo_sum[n-1] - (n * bamboo[n-1])
            print(remaining // n + bamboo[n-1])
            return
        candidate_points = set()
        for i in range(n):
            bamboo_sum[i] += k
            lim = 1 + int(math.sqrt(bamboo[i] + 1))
            for j in range(1, lim):
                r1 = bamboo[i] // j
                r2 = j
                if r1 < max_val:
                    if r1 * j == bamboo[i]:
                        candidate_points.add(r1)
                    else:
                        candidate_points.add(r1 + 1)
        lim = int(math.sqrt(bamboo[n-1]))
        if lim > max_val:
            lim = max_val
        for i in range(1, lim):
            candidate_points.add(i)
        for cp in reversed(sorted(candidate_points)):
            total = 0
            d1 = 0
            flag = 1
            for i in range(n):
                d1 = (bamboo[i] + cp - 1) // cp
                total += (d1 * cp)
                if total > bamboo_sum[i]:
                    flag = 0
                    break
            if flag:
                dv = 0
                for i in range(n):
                    dv += (bamboo[i] + cp - 1) // cp
                print(cp + (bamboo_sum[n-1] - total) // dv)
                return
        print(1)

if __name__ == "__main__":
    main()
