
import sys


class IceGame(object):
    delta = zip([1, 0, -1, 0], [0, 1, 0, -1])

    def __init__(self, n, m, source, target, cracked):
        self.result = None
        self.n, self.m = n, m

        if not cracked[target[0]][target[1]] and len([v for v in self.get_neighbours(target)
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

    def get_neighbours(self, vertex):
        return [
            (vertex[0] + dr, vertex[1] + dc)
            for dr, dc in self.delta
            if 0 <= vertex[0] + dr < self.n and 0 <= vertex[1] + dc < self.m
        ]

    def compute(self, source, target, cracked):
        queue = [v for v in self.get_neighbours(source) if not cracked[v[0]][v[1]]]
        while queue:
            vertex = queue.pop()
            if vertex == target:
                return True
            for v in self.get_neighbours(vertex):
                if not cracked[v[0]][v[1]]:
                    cracked[v[0]][v[1]] = True
                    queue.append(v)
        return False


t = """100 100
..X...X...X.......X..XX.............X...X.......X..XX...XX.X....XX..XX.X..X..X.XX...XX.X..XX.XXXXXX.
.....X...X..X..........X.....X.XX.....X..X.XX.....XX.X.......X....X...........X..X.....X...X.....XXX
X.........X......XXXX...X..XXXX......XX...X...XX.X....XXX..XX.X.X.....X.....X.X.X...X........X.XXX..
.........X...X.....X........X.X.X.............X..X...X.XX....XXX.XXX..X....X.......X......XXX......X
X.......X..XX.....X....XX........X.....X....XX......XX...X....XX...XX.X.......X...X...X......XX.XX..
...XX.......XXX......X.....XXX....X...X.X......X.....XX..X..X..X....X..........X.X.....X.X.X...XXX..
.X..........XXX....X.X.X..X.XX...X.X..........X...X..XX..X...X....X...X.................X...X.X.X...
.X...X...XXX...X...X............X.......XXX.X......X..XXXX..X.....XX...XX..X.X..XX......X.....X....X
......X.X.........X.X.....X.........X...X.....X...X...X...X....X..X..X...XX.....XX......X..X.X..X...
........X...XX....X......X..........X...X.X....XX.X...X......X..X...........X..X.......XX..X...XX.XX
XX....X...X.....XX.X.......X.........X...X.X...X......X..XXX...X.....X.XXX.........X....X.X..X.....X
.........X.......X...XX...X....X.X.X...................X........XX.....XX...X...........X........X..
..X..X.X..X.....XX.......XX....X..XX.................X..X.....X.X...XX........X..X..X.X....X...X....
.X..X.......XX.XXX..XX.X.....XX..XX..............X.....X...X.XXX.......X...X........X..X..X.X.......
..............X..............X...X...........X.......XXX..XX......XX........XX.X.X.X...XX.X.X..X..X.
........X..X.....X.XX.X........XX.................X.X..X....X...X......X..X...............X..X...X..
..X..........X......XX.X..XX..X.X........X.X..X..X...X......X...X..XX....X........X.XX.......X....X.
..X.XX......XX..XX......X.X..X.X.X.X...X......XXX.X..XX.X....X......X.XX...XX.X.......X...X.........
X......X.X......X.....XXX.......XX.X....X........XXX....XX...XX..X...X...X.X...X....XXXX..XXX...X.X.
....X...X....X.X...X....X..X.....X.....X.........X..X..........X....X.X......XX........X.X.X....X...
...X......X..........XX.X......X...X........XX........X.....XX....X............X...X.......XX.X..X.X
.X.X........X....X.X.X.XXXXXXX...X...X....X..........X.X.......X.......X......X...XX....X.....X..XX.
..X......X.X........XX..X.......X...XXX..X.XX.X...XX.......X........X.....XXX.....X..X......XX......
.....X....XXX...XX..X.........X.......XX....XX.X.X..............X....X......XX..X..X....X...........
X.X........X..........XX......XX.XXX....X.X...X.......X.XX..X......XXXXX......XX...X.....X..X.......
..XXX.XX.XX.........X.X...............XX.....X.......X.XX....X.X..X......X.X.....X......X.X.........
........X...X.....X.X.XX..X.....XX......X....X.X..X.....XX..XXXXX..X..XX...X.........XX......XX..X..
..........X.XX.....X....XX.....X.XX.....XX.X....X........X.X.X.X..X.X..X......XX..X...X.......X.XXX.
........X...X........X.X.X........XX.........X.X.X.X........X..X.X...XX........X..XX...X..XX......X.
....X.X....X..X....XX..X..X.X.X..X.....XX..X..X...X.....X..X..XXXX.........X.....X.....X.....XX.X...
.......X.X.X.XX....XX..X.X....X.X...............X.X....X........XX..X.X.XXX........X.XXX.XX.....XX.X
.X...X..X...X.X...XX..X.X......XX...X.........XX.........X......X..........X......X.X....X..X..X..X.
.X.XX.......XXX.X.........XXX.X.....XX.XXXX.....X......X.....X....X.......X..X...X.X..X..X..X.X..X..
XX....X.X..........XXX.X.X.....X.........X.......X...X....X....X........X....X.......XX.XX.XX.X.....
.XX.........X.......XX.X.....X.X...XX.......XXXX.X......X.......X...X....X..........X.X.X.XX.X......
X.X..........................X..X.X...XX.............XX....X.......X......X.....XXX.X.X........XXX.X
..X.......X...X.X............X.X.X.......X..XX.........X.....X......XXX........X.X.X..X....X...XX.X.
X....XX..X.XX.....X...X.....XX.XXXX...X.XX.....XX.........XXX.....X......XX....XX....X.X.X.......XX.
.X........X....X.X....XX..X....XX..X........X..X..X..XXX..X.XX....XX...X.....X...X.X...X..X...XXXX.X
.....X....X.............X..X.X..X......XXX........X...X.X....X...XX....XX...X.X...X.X.........XX....
...X.........XX....XXXX....XX.X....X....XXXX......X..X.XXXX....X.....X......XX..XX..XX.........X....
XX..X.......XX....X....X.XX.XX.X..X......X....X...X.X.X.....X....X.XX....X....X..XXX.X...X....X.X.X.
...X...X.X..X..X...........X.X..........XX.XX..X...XX...X.XX..X........X....XXX...XXX..XX......XXX..
......X.XX....X.XXX....X..X.XX...X.XX........X.X.......XXX...X.X......X.XXX..XX.X.....X...XX..X.....
.X...X..X..X...X....X..X.XX....X.X..X......XX.....XXXX....X...X.XX..XX...X..X.....X.......X.X...X...
.X...X....XXX......X......X.....X..XXX............X......XX...X...X...X.X.X...........X.X......XXX..
X...X.X.X.X....XXX.....X.....X................XXX....X.X......X.....X.X.....XX.X.XX....XXX..X.....XX
...XX......X.X......X......X..X......X.....X....X....XX.X.X......XX........XX......XXX.XX..X.XX.XX..
X..XXX.XXX........X........X..X.....XX.........X.X...X.....X.X..XX......X..XXX....X......X.....X....
XX..XX.....X.X...XX..X......X.....X..X...X............X.....X.X.X.X....XX...X...X.XX...X.X..........
.XX.XX........XX....X....X...X..X..........XXXXXXX.X.X..XXX......X....XX.................XX.X.X..X..
XX..X..X.......XX.........X....XXXX.........X....X............X..XX.X...X..X....X.......XX...X...X.X
.X......X............X.....X.X..X...X...X....................X........X.X.X..XX.....XX...X..X.X.X...
....................X.....XX.....XX.....XX...X........X.X...........X..X......XX....X............XXX
..X.......X.X...........X.......XX..X......X...........X......XX.X.X.X..X.X..X....X.......X.....XX..
X..XX..X..X....X...X.........X.X.....XX...X.XX.X.X.X..XXX.....X....X.X.....X.X...X....X....X.......X
.X.X.X...X..X.......X..X.....XXX...X.......X...XX..XXXX.......X...X.........X..X....X........XX....X
XX.....XX..X....X.X........X.X.....X...X.X..XX...XXX.X...X.X......X.X.X...........X.......X.......XX
....X........X....X....X.........X.....X.X....X........X..X.X.....X.X.....X.....XXX...............X.
.XX.....XXX........X..X.X.X.XX.....XX....X...X.......X.....XX.......XX...XXXXX.....XX.....X..X..XXX.
X..X...............XXXX.X.....X...X.X...X..X...X.XX.X....X..XX...X......XX.......XX.X...........X...
X..X.......X..X.......X..X..X.XX...X..X..XXXX.....X...X....X..........X....X.......X.......XX....X.X
...X.XX.X..X..X...X.XXX...X..XX.........X.....XXX.X..X..............X.....X....X.........X.....X..X.
...X...X..XX......XX.XX.X..X......XXX...X.X..XX..X...X..X....X........X.XX.X.X.X......X....X..X..X..
.X.....X....X.......XXX.....X.X...........X...XX....XXXXXX.X...X..........X.....X..XX...XX..XX.X....
..X......X...X.......X..X........X.XX.X..XXXX..X...X.......X....X....X.X.XX.....XXX................X
.....X...X........X.XX.X......XX.XX......X.X.......X..........X..XX...X......X...XX.X...XX.X........
X......X..X............X...X..........X..XXXX.X.......X........X.....X....X.........X.X..X....X.X...
.X.......X......XXX..........X.....X....X....X.X...X........XXX.....X......XX......X.X...X..X.XX.X..
....X...XXX....X...XX.....X.X..X..X.....X......X.XX...X...................X.....X..XXXXXX...X.XX..X.
..X..........X...X.X...X.X.XX.......X.XX.....X.....X..XX..X.....X..XX....X.X...XXX.XXX....X...X...X.
..X.......X..X.X.X.....X..X.X..X....X.X...X........................X..XX....XXX.X..XXX.XX.XX...X..X.
.X.......X....XXX...X.....X.XX.XX...........X..X.........X.........X.X..XXXXX.X.X..X.X........X..X..
X..X..X...X..X.X..X...................X.......X.......X..XXXX............XX.....X..X....X.X..X.....X
.X.........XX....X........XX...X...X......X..X..X....X......X........X.X.X.......XX....X..XX........
..X...........X...X.X.X....XXXX....X..X.....XXX.X......X.X....X.X.XX.X.X..X.............X.X......XXX
..............X.X.............X...........XX..XX....X...................X.X....X..X..XX....X........
........X..XX.....X.XX....XX..X..X.....X.....X.........................XX....X.......X...........X..
.X............XXX.....X..X..X.X.X......XX..XX..X.............X..X.X.....XXX..XXXX......XXX.........X
..X....X..X....X..X..X.X..X.......X....X...XX....X.X...XX.X.X...X.....XXX...X.......................
.....X............XX....X..........X...X.....X..........X.X.X............X.....X.....XXX.X.XX.....XX
.X...X...XX..X.X.X.XX.......X...X..X......X.X..X.......X.X......XX...X....X..X.........XX...X.....X.
X...X...X.XX...X......X.X....X.XXX.......X...X......XX.....X..X....X....X.X......XX........XX.X.X.XX
.............X.....X..X.............X..X.....X.X..X.X...X......X......X......XX......X......X.......
X.............X..XXX....X..XXX..XX...X.....X.......X........X..X.X............X.X.......X...X...X...
X.X....X.X.X.....X.......X.........X....XXX.....X.....X.........X..X.X......XX....X.X...X...X..X....
.X.X....X.X.X...........X..X..X...X....XX.........X..X..XXX...........X.X......X..X.X.....X.....X...
.X....X.X..XX..X..........X.........XX.XX.....XXX..X......XX...X...X.X........XXX...XX.X.XX........X
.X..X.XX..................X....X..XX..X........X...X...X......X....X......XX.X...........X..X....X..
....XX..............X.....XXX....X..X...............X.XX.....X..X...X..X...................X..X.XX..
.XX...X.....X.XX...X...........X.........XX.....XX...XX..X.X...X......X.....XX.X...XXX.....XX.......
.X.X...X..X...X..........X.X....XX.....X.......X.X..........X..XX....X.........XX.X.X..X...X..X.....
...........X.X.X.X..X.XX....XXXX.X.XXXX...X........X.......X..................XX.X.X.X.....X...XX...
...X...X..X..X.....X.X....X...X..X.....X.X...............X.........X..X....X...X..X.....XX.X.X..X...
X..X.X..XXX....X.X.X..X.X..X..X..XX..X...X.X....X...XX.X..XX.X............X..X......X.X...X..X.X....
.X....X.XX...X.X..X.....XXX.....X.XXX...............X......X.X...X..........X.XXX.......XX..X......X
.X.XX.X.X..X..X..X.....X.XX...XXX..XXX........X.........X......X..XX.XX.X.X.X..X......X............X
...X.......X.XX....XX..XX.........X.X...X.....X.......X...........X..................X....X...XX.X..
X.X...X...X.....XX.X.XX.X..XXX..X....XX.X.....X....X...X.X.........X..X...X.....XX...XX.X.X..X.....X
..XX........X....X....X....X.XX...X....X.X...X...X...XX............XX.X.X.X.....X..............X.X..
1 3
100 90"""










game = IceGame.from_input(sys.stdin)
sys.stdout.write({True: 'YES', False: 'NO'}[game.result])