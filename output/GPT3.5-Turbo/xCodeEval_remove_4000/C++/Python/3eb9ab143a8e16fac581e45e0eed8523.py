class TaskB:
    def solve(self, in_stream, out_stream):
        n, m = map(int, in_stream.readline().split())
        ways = [0] * (n + 1)
        extras = [0] * (n + 1)
        ways[1] = 1
        sum = 0
        extra = 0
        for i in range(1, n + 1):
            ways[i] += sum
            extra += extras[i]
            ways[i] += extra
            for j in range(2, n // i + 1):
                extras[i * j] += ways[i]
                if (i + 1) * j <= n:
                    extras[(i + 1) * j] -= ways[i]
            sum += ways[i]
        out_stream.write(str(ways[n]) + "\n")

solver = TaskB()
solver.solve(input, print)
