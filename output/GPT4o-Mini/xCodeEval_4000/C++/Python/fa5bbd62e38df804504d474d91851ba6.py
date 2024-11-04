import sys
import math
from collections import defaultdict

MOD = 998244353

class CPaintTree:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self.in_stream = in_stream
            self.out_stream = out_stream
            self.n = 0
            self.e = []
            self.subtree_sz = []
            self.xy_mapping = []
            self.xys_idx = []
            self.xy = []

        def read_tree(self):
            self.e.clear()
            self.e = [[] for _ in range(self.n)]
            for _ in range(self.n - 1):
                u, v = map(int, self.in_stream.readline().split())
                u -= 1
                v -= 1
                self.e[u].append(v)
                self.e[v].append(u)

        def read_points(self):
            self.xy = [list(map(int, self.in_stream.readline().split())) for _ in range(self.n)]

        def x_dist(self, i, j):
            return self.xy[j][0] - self.xy[i][0]

        def y_dist(self, i, j):
            return self.xy[j][1] - self.xy[i][1]

        def get_angle(self, i, j):
            return math.atan2(self.y_dist(i, j), self.x_dist(i, j))

        def sort_by_angle(self, l, r, cur_xy):
            if r < l:
                return
            for i in range(l, r + 1):
                self.xys_idx[i][0] = self.get_angle(cur_xy, self.xys_idx[i][1])
            max_angle = self.xys_idx[l][0]
            for i in range(l, r + 1):
                max_angle = max(max_angle, self.xys_idx[i][0])
            for i in range(l, r + 1):
                if self.xys_idx[i][0] + math.pi < max_angle:
                    self.xys_idx[i][0] += 2 * math.pi
            self.xys_idx[l:r + 1] = sorted(self.xys_idx[l:r + 1])

        def solve_rec(self, l, r, root, parent):
            curr_xy = self.xys_idx[r][1]
            self.xy_mapping[curr_xy] = root
            self.sort_by_angle(l, r, curr_xy)
            cur_l = l
            for i in self.e[root]:
                if i == parent:
                    continue
                cur_r = cur_l + self.subtree_sz[i] - 1
                nxt_l = cur_r + 1
                self.solve_rec(cur_l, cur_r, i, root)
                cur_l = nxt_l

        def calculate_subtree_sizes(self, i, p):
            self.subtree_sz[i] = 1
            for j in self.e[i]:
                if j == p:
                    continue
                self.calculate_subtree_sizes(j, i)
                self.subtree_sz[i] += self.subtree_sz[j]

        def solve(self):
            self.n = int(self.in_stream.readline().strip())
            self.subtree_sz = [0] * self.n
            self.read_tree()
            self.read_points()
            self.xy_mapping = [0] * self.n
            self.calculate_subtree_sizes(0, -1)
            self.xys_idx = [[0, i] for i in range(self.n)]
            for i in range(self.n):
                self.xys_idx[i][1] = i
            api = lambda i: (self.xy[i][0], self.xy[i][1])
            self.xys_idx.sort(key=lambda i: api(i[1]), reverse=True)
            self.solve_rec(0, self.n - 1, 0, -1)
            self.xy_mapping = [x + 1 for x in self.xy_mapping]
            self.out_stream.write(' '.join(map(str, self.xy_mapping)) + '\n')

    @staticmethod
    def solve(in_stream, out_stream):
        CPaintTree.Solver(in_stream, out_stream).solve()

if __name__ == "__main__":
    CPaintTree.solve(sys.stdin, sys.stdout)
