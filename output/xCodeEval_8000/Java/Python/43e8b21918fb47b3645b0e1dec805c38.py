import sys
from typing import List, Tuple, Dict, Any


class FastReader:
    def __init__(self):
        self.buffer = []
        self.buffer_size = 0
        self.pointer = 0

    def read(self) -> str:
        if self.pointer >= self.buffer_size:
            self.buffer = sys.stdin.readline().split()
            self.buffer_size = len(self.buffer)
            self.pointer = 0
        self.pointer += 1
        return self.buffer[self.pointer - 1]

    def next_int(self) -> int:
        return int(self.read())

    def next_long(self) -> int:
        return int(self.read())

    def next_double(self) -> float:
        return float(self.read())

    def next_char(self) -> str:
        return self.read()[0]

    def next_string(self) -> str:
        return self.read()

    def next_int_array(self, n: int) -> List[int]:
        return [self.next_int() for _ in range(n)]

    def next_double_array(self, n: int) -> List[float]:
        return [self.next_double() for _ in range(n)]

    def next_long_array(self, n: int) -> List[int]:
        return [self.next_long() for _ in range(n)]


def main() -> None:
    fr = FastReader()
    out = sys.stdout

    # Constants
    gigamod = 1000000007
    t = 1
    epsilon = 0.00000001

    # Helper functions
    def gcd(a: int, b: int) -> int:
        if b == 0:
            return a
        else:
            return gcd(b, a % b)

    def lcm(a: int, b: int) -> int:
        return (a * b) // gcd(a, b)

    def power(x: int, y: int, p: int) -> int:
        res = 1
        x = x % p
        while y > 0:
            if y & 1:
                res = (res * x) % p
            y = y >> 1
            x = (x * x) % p
        return res

    def mod_inverse(n: int, p: int) -> int:
        return power(n, p - 2, p)

    def mod_div(a: int, b: int) -> int:
        return mod(a * mod_inverse(b, gigamod))

    def mod(a: int, m: int = gigamod) -> int:
        return (a % m + m) % m

    def is_prime(n: int) -> bool:
        if n <= 1:
            return False
        if n <= 3:
            return True
        if n % 2 == 0 or n % 3 == 0:
            return False
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True

    def prime_factorization(num: int) -> Dict[int, int]:
        factors = {}
        while num % 2 == 0:
            num //= 2
            factors[2] = factors.get(2, 0) + 1
        i = 3
        while i * i <= num:
            while num % i == 0:
                num //= i
                factors[i] = factors.get(i, 0) + 1
            i += 2
        if num != 1:
            factors[num] = 1
        return factors

    def divisors(num: int) -> List[int]:
        divs = {1, num}
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                divs.add(i)
                divs.add(num // i)
        return sorted(list(divs))

    def bsearch(arr: List[int], val: int, lo: int, hi: int, s_mode: bool = False) -> int:
        idx = -1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if arr[mid] > val:
                hi = mid - 1
            else:
                idx = mid
                lo = mid + 1
        return idx

    def dfs_mark(current: int, marked: List[bool], g: List[List[int]]) -> None:
        if marked[current]:
            return
        marked[current] = True
        for adj in g[current]:
            dfs_mark(adj, marked, g)

    def dfs_mark_dist(current: int, from_: int, dist_to: List[int], marked: List[bool], g: List[List[int]], end_points: List[int]) -> None:
        if marked[current]:
            return
        marked[current] = True
        if from_ != -1:
            dist_to[current] = dist_to[from_] + 1
        already_marked_ctr = 0
        for adj in g[current]:
            if marked[adj]:
                already_marked_ctr += 1
            dfs_mark_dist(adj, current, dist_to, marked, g, end_points)
        if already_marked_ctr == len(g[current]):
            end_points.append(current)

    def bfs_order(current: int, g: List[List[int]]) -> None:
        pass

    def dfs_mark_color(current: int, color_ids: List[int], color: int, g: List[List[int]]) -> None:
        if color_ids[current] != -1:
            return
        color_ids[current] = color
        for adj in g[current]:
            dfs_mark_color(adj, color_ids, color, g)

    def connected_components(g: List[List[int]]) -> List[int]:
        n = len(g)
        component_id = [-1] * n
        color_ctr = 0
        for i in range(n):
            if component_id[i] != -1:
                continue
            dfs_mark_color(i, component_id, color_ctr, g)
            color_ctr += 1
        return component_id

    def topological_sort(g: List[List[int]]) -> List[int]:
        def run_dfs(v: int) -> None:
            marked[v] = True
            for adj in g[v]:
                if not marked[adj]:
                    run_dfs(adj)
            topological_stack.append(v)

        n = len(g)
        marked = [False] * n
        topological_stack = []
        for i in range(n):
            if not marked[i]:
                run_dfs(i)
        return topological_stack[::-1]

    def kosaraju_sharir_scc(g: List[List[int]]) -> List[int]:
        def scc_dfs(v: int, id_ctr: int) -> None:
            marked[v] = True
            component_id[v] = id_ctr
            for adj in g[v]:
                if not marked[adj]:
                    scc_dfs(adj, id_ctr)

        n = len(g)
        reversed_g = [[] for _ in range(n)]
        for i in range(n):
            for adj in g[i]:
                reversed_g[adj].append(i)

        marked = [False] * n
        component_id = [-1] * n
        id_ctr = -1

        topological_stack = topological_sort(reversed_g)
        while topological_stack:
            v = topological_stack.pop()
            if not marked[v]:
                id_ctr += 1
                scc_dfs(v, id_ctr)
        return component_id

    def bridge_finder(g: List[List[int]]) -> bool:
        def dp_dfs(current: int, from_: int, level_of: List[int], dp: List[int], marked: List[bool], g: List[List[int]]) -> int:
            level_of[current] = level_of[from_] + 1
            dp[current] = level_of[current]
            for back in back_ug[current]:
                dp[current] = min(dp[current], level_of[back])
            for adj in g[current]:
                if adj != from_:
                    dp[current] = min(dp[current], dp_dfs(adj, current, level_of, dp, marked, g))
            return dp[current]

        n = len(g)
        tree = [[] for _ in range(n)]
        back_ug = [[] for _ in range(n)]
        has_bridge = -1

        def tree_calc(current: int, from_: int, marked: List[bool], g: List[List[int]]) -> None:
            if marked[current]:
                back_ug[from_].append(current)
                return
            if from_ != -1:
                tree[from_].append(current)
            marked[current] = True
            for adj in g[current]:
                if adj != from_:
                    tree_calc(adj, current, marked, g)

        marked = [False] * n
        for i in range(n):
            if marked[i]:
                continue
            tree_calc(i, -1, marked, g)

        level_of = [0] * n
        dp = [float('inf')] * n
        marked = [False] * n
        while has_bridge == -1:
            dp_dfs(0, -1, level_of, dp, marked, tree)
            for i in range(n):
                for adj in tree[i]:
                    if dp[adj] > level_of[i]:
                        has_bridge = 1
                        break
        if has_bridge != 1:
            has_bridge = 0
        return has_bridge == 1

    def main_logic() -> None:
        for _ in range(t):
            n = fr.next_int()
            mod = fr.next_long()

            dp = [0] * (n + 1)
            dp[n] = 1

            for i in range(n - 1, 0, -1):
                dp[i] += dp[i + 1]
                dp[i] %= mod

                for div in range(1, (n // i) + 1):
                    lb = div * i
                    ub = min((div * (i + 1)) - 1, n)
                    seg_sum = dp[lb]
                    if ub + 1 <= n:
                        seg_sum -= dp[ub + 1]
                    dp[i] += seg_sum
                    dp[i] %= mod

                dp[i] += dp[i + 1]
                dp[i] %= mod

            out.write(str((dp[1] - dp[2] + mod) % mod) + '\n')

    main_logic()


if __name__ == "__main__":
    main()
