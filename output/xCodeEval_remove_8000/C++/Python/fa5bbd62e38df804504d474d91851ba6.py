import sys
from math import atan2, pi

class CPaintTree:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self.in_stream = in_stream
            self.out_stream = out_stream

        def read_tree(self):
            self.e = []
            self.n = int(self.in_stream.readline())
            for _ in range(self.n - 1):
                u, v = map(int, self.in_stream.readline().split())
                self.e.append((u - 1, v - 1))

        def read_points(self):
            self.xy = []
            for _ in range(self.n):
                x, y = map(int, self.in_stream.readline().split())
                self.xy.append((x, y))

        def get_angle(self, i, j):
            return atan2(self.xy[j][1] - self.xy[i][1], self.xy[j][0] - self.xy[i][0])

        def sort_by_angle(self, l, r, cur_xy):
            if r < l:
                return
            max_angle = self.get_angle(cur_xy, self.xys_idx[l][1])
            for i in range(l, r + 1):
                angle = self.get_angle(cur_xy, self.xys_idx[i][1])
                if angle + pi < max_angle:
                    angle += 2 * pi
                self.xys_idx[i] = (angle, self.xys_idx[i][1])
            self.xys_idx[l:r + 1] = sorted(self.xys_idx[l:r + 1])

        def solve_rec(self, l, r, root, parent):
            curr_xy = self.xys_idx[r][1]
            self.xy_mapping[curr_xy] = root
            self.sort_by_angle(l, r, curr_xy)
            cur_l = l
            for i in range(len(self.e[root])):
                j = self.e[root][i]
                if j == parent:
                    continue
                cur_r = cur_l + self.subtree_sz[j] - 1
                self.solve_rec(cur_l, cur_r, j, root)
                cur_l = cur_r + 1

        def calculate_subtree_sizes(self, i, p):
            self.subtree_sz[i] = 1
            for j in self.e[i]:
                if j == p:
                    continue
                self.calculate_subtree_sizes(j, i)
                self.subtree_sz[i] += self.subtree_sz[j]

        def solve(self):
            self.read_tree()
            self.read_points()
            self.xy_mapping = [0] * self.n
            self.subtree_sz = [0] * self.n
            self.calculate_subtree_sizes(0, -1)
            self.xys_idx = [(0, i) for i in range(self.n)]
            self.xys_idx.sort(key=lambda x: (self.xy[x[1]][0], self.xy[x[1]][1]), reverse=True)
            self.solve_rec(0, self.n - 1, 0, -1)
            self.xy_mapping = [x + 1 for x in self.xy_mapping]
            self.out_stream.write(' '.join(map(str, self.xy_mapping)) + '\n')

    @staticmethod
    def solve(in_stream, out_stream):
        CPaintTree.Solver(in_stream, out_stream).solve()

if __name__ == '__main__':
    CPaintTree.solve(sys.stdin, sys.stdout)
