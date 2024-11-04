
import sys


class IceGame(object):
    delta = zip([1, 0, -1, 0], [0, 1, 0, -1])

    def __init__(self, n, m, source, target, cracked):
        self.result = None
        self.n, self.m = n, m

        if not cracked[target[0]][target[1]] and len([v for v in self.id0(target)
                                                      if not cracked[v[0]][v[1]] or v == source]) < 2:
            self.result = False
        else:
            cracked[target[0]][target[1]] = False
            self.result = self.compute(source, target, cracked)

    @classmethod
    def from_input(cls, stdin):
        n, m = map(int, stdin.readline().split())

        cracked = [[False] * m for _ in xrange(n)]
        for row in xrange(n):
            for idx, item in enumerate(stdin.readline()):
                if item == 'X':
                    cracked[row][idx] = True

        source = tuple(map(lambda x: int(x) - 1, stdin.readline().split()))
        target = tuple(map(lambda x: int(x) - 1, stdin.readline().split()))
        return cls(n, m, source, target, cracked)

    def id0(self, vertex):
        return [
            (vertex[0] + dr, vertex[1] + dc)
            for dr, dc in self.delta
            if 0 <= vertex[0] + dr < self.n and 0 <= vertex[1] + dc < self.m
        ]

    def compute(self, source, target, cracked):
        queue = [v for v in self.id0(source) if not cracked[v[0]][v[1]]]
        while queue:
            vertex = queue.pop()
            if vertex == target:
                return True
            for v in self.id0(vertex):
                if not cracked[v[0]][v[1]]:
                    cracked[v[0]][v[1]] = True
                    queue.append(v)
        return False


t = 










game = IceGame.from_input(sys.stdin)
sys.stdout.write({True: 'YES', False: 'NO'}[game.result])