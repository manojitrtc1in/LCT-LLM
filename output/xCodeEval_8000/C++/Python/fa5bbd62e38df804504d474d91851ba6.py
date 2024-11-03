import sys
from math import atan2, pi

class CPaintTree:
    class Solver:
        def __init__(self, in_stream, out_stream):
            self.in_stream = in_stream
            self.out_stream = out_stream

        def solve(self):
            n = int(self.in_stream.readline())
            e = [[] for _ in range(n)]
            for _ in range(n - 1):
                u, v = map(int, self.in_stream.readline().split())
                e[u - 1].append(v - 1)
                e[v - 1].append(u - 1)
            
            xy = []
            for _ in range(n):
                x, y = map(int, self.in_stream.readline().split())
                xy.append((x, y))
            
            subtree_sz = [0] * n
            xy_mapping = [0] * n
            xys_idx = [(0, i) for i in range(n)]
            xys_idx.sort(key=lambda x: (xy[x[1]][0], xy[x[1]][1]), reverse=True)
            
            def x_dist(i, j):
                return xy[j][0] - xy[i][0]
            
            def y_dist(i, j):
                return xy[j][1] - xy[i][1]
            
            def get_angle(i, j):
                return atan2(y_dist(i, j), x_dist(i, j))
            
            def sort_by_angel(l, r, cur_xy):
                if r < l:
                    return
                max_angle = get_angle(cur_xy, xys_idx[l][1])
                for i in range(l, r + 1):
                    xys_idx[i] = (get_angle(cur_xy, xys_idx[i][1]), xys_idx[i][1])
                    max_angle = max(max_angle, xys_idx[i][0])
                if max_angle + pi < xys_idx[l][0]:
                    for i in range(l, r + 1):
                        xys_idx[i] = (xys_idx[i][0] + 2 * pi, xys_idx[i][1])
                xys_idx[l:r + 1] = sorted(xys_idx[l:r + 1])
            
            def solve_rec(l, r, root, parent):
                curr_xy = xys_idx[r][1]
                xy_mapping[curr_xy] = root
                sort_by_angel(l, r, curr_xy)
                cur_l = l
                for i in e[root]:
                    if i == parent:
                        continue
                    cur_r = cur_l + subtree_sz[i] - 1
                    nxt_l = cur_r + 1
                    solve_rec(cur_l, cur_r, i, root)
                    cur_l = nxt_l
            
            def calculate_subtree_sizes(i, p):
                subtree_sz[i] = 1
                for j in e[i]:
                    if j == p:
                        continue
                    calculate_subtree_sizes(j, i)
                    subtree_sz[i] += subtree_sz[j]
            
            calculate_subtree_sizes(0, -1)
            solve_rec(0, n - 1, 0, -1)
            xy_mapping = [x + 1 for x in xy_mapping]
            self.out_stream.write(' '.join(map(str, xy_mapping)) + '\n')

    @staticmethod
    def solve(in_stream, out_stream):
        CPaintTree.Solver(in_stream, out_stream).solve()

if __name__ == '__main__':
    CPaintTree.solve(sys.stdin, sys.stdout)
