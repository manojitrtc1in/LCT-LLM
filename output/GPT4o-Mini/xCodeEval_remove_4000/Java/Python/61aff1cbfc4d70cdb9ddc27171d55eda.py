import random
import sys
import time
from collections import deque
from typing import List, Tuple

MODULO = 1000 * 1000 * 1000 + 7

class C:
    def __init__(self):
        self.id69 = 10
        self.rnd = random.Random()
        self.fileName = ""
        self.id36 = not self.file_exists("input.txt")

    def file_exists(self, filename):
        try:
            with open(filename):
                return True
        except FileNotFoundError:
            return False

    def solve1(self):
        for it in range(10):
            need = self.rnd.randint(1, 10000)
            maxTime = self.rnd.randint(1, 10000000)
            id45 = self.rnd.randint(1, 10)

            id43 = self.rnd.randint(1, 100)
            id16 = self.rnd.randint(1, 10)
            id77 = self.rnd.randint(1, 10)

            id7 = self.rnd.randint(1, 100)
            id90 = self.rnd.randint(1, 10)
            id51 = self.rnd.randint(1, 10)

            answer = self.get_answer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)
            id59 = self.id52(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

            if answer[0] != id59[0]:
                print("GOTCHA", file=sys.stderr)
                print(answer, file=sys.stderr)
                print(id59, file=sys.stderr)
                print(need, maxTime, id16, file=sys.stderr)
                print(id43, id16, id77, file=sys.stderr)
                print(id7, id90, id51, file=sys.stderr)

    def solve(self):
        need = self.read_int()
        maxTime = self.read_int()
        id45 = self.read_int()

        id43 = self.read_int()
        id16 = self.read_int()
        id77 = self.read_int()

        id7 = self.read_int()
        id90 = self.read_int()
        id51 = self.read_int()

        answer = self.get_answer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)
        print(answer[0])

    def get_answer(self, need: int, maxTime: int, id45: int, id43: int, id16: int, id77: int, id7: int, id90: int, id51: int) -> List[int]:
        answer = float('inf')
        firstOptimal = 0
        secondOptimal = 0

        firstCount = 0
        firstSize = 0
        firstTime = 0
        firstCost = 0

        while True:
            firstCount += 1
            firstSize += id43
            firstCost += id77
            firstTime += id16 * id43

            if firstSize >= need:
                firstSize = need
                firstTime = id16 * firstSize

            id42 = maxTime - firstTime
            id74 = need - firstSize
            if id42 >= 0:
                if id45 <= id90:
                    freeTime = id45 * id74
                    if freeTime + firstTime <= maxTime:
                        if answer > firstCost:
                            answer = firstCost
                            firstOptimal = firstCount
                            secondOptimal = 0
                else:
                    id68 = id74 // id7
                    id63 = id7 * id68
                    id50 = id74 - id63

                    id81 = id63 * id90
                    id15 = id50 * id45

                    if id81 + id15 <= id42:
                        if answer > firstCost + id68 * id51:
                            answer = firstCost + id68 * id51
                            firstOptimal = firstCount
                            secondOptimal = id68

                    id41 = id74 // id7
                    if id74 % id7 != 0:
                        id41 += 1
                    id80 = min(id74, id7 * id41)
                    id21 = id74 - id80

                    id97 = id80 * id90
                    id98 = id21 * id45

                    if id97 + id98 <= id42:
                        if answer > firstCost + id41 * id51:
                            answer = firstCost + id41 * id51
                            firstOptimal = firstCount
                            secondOptimal = id41

                        id31 = (id74 * id45 - id42)
                        id96 = (id45 - id90) * id7

                        id14 = id31 // id96
                        if id31 < 0:
                            id14 = 0
                        elif id31 % id96 != 0:
                            id14 += 1
                        if id14 >= 0:
                            id29 = min(id74, id7 * id14)
                            id38 = id74 - id29

                            id48 = id29 * id90
                            id70 = id38 * id45

                            if id48 + id70 <= id42:
                                if answer > firstCost + id14 * id51:
                                    answer = firstCost + id14 * id51
                                    firstOptimal = firstCount
                                    secondOptimal = id14

            if firstSize >= need:
                break

        secondCount = 0
        secondSize = 0
        secondCost = 0
        secondTime = 0

        while True:
            secondCount += 1
            secondSize += id7
            secondCost += id51
            secondTime += id90 * id7

            if secondSize >= need:
                secondSize = need
                secondTime = id90 * secondSize

            id42 = maxTime - secondTime
            id74 = need - secondSize
            if id42 >= 0:
                if id45 <= id16:
                    freeTime = id45 * id74
                    if freeTime + secondTime <= maxTime:
                        if answer > secondCost:
                            answer = secondCost
                            secondOptimal = secondCount
                            firstOptimal = 0
                else:
                    id68 = id74 // id43
                    id79 = id43 * id68
                    id50 = id74 - id79

                    id23 = id79 * id16
                    id15 = id50 * id45

                    if id23 + id15 <= id42:
                        if answer > secondCost + id68 * id77:
                            answer = secondCost + id68 * id77
                            secondOptimal = secondCount
                            firstOptimal = id68

                    id41 = id74 // id43
                    if id74 % id43 != 0:
                        id41 += 1
                    id39 = min(id74, id43 * id41)
                    id21 = id74 - id39

                    id83 = id39 * id16
                    id98 = id21 * id45

                    if id83 + id98 <= id42:
                        if answer > secondCost + id41 * id77:
                            answer = secondCost + id41 * id77
                            secondOptimal = secondCount
                            firstOptimal = id41

                        id31 = (id74 * id45 - id42)
                        id96 = (id45 - id16) * id43

                        id14 = id31 // id96
                        if id31 < 0:
                            id14 = 0
                        elif id31 % id96 != 0:
                            id14 += 1
                        if id14 >= 0:
                            id86 = min(id74, id43 * id14)
                            id38 = id74 - id86

                            id92 = id86 * id16
                            id70 = id38 * id45

                            if id92 + id70 <= id42:
                                if answer > secondCost + id14 * id77:
                                    answer = secondCost + id14 * id77
                                    secondOptimal = secondCount
                                    firstOptimal = id14

            if secondSize >= need:
                break

        if answer == float('inf'):
            answer = -1

        return [answer, firstOptimal, secondOptimal]

    def id52(self, need: int, maxTime: int, id45: int, id43: int, id16: int, id77: int, id7: int, id90: int, id51: int) -> List[int]:
        answer = float('inf')
        firstOptimal = 0
        secondOptimal = 0

        firstCount = 0
        while True:
            firstSize = min(need, firstCount * id43)
            if firstSize >= need:
                firstSize = need

            firstTime = firstSize * id16
            firstCost = firstCount * id77

            id74 = need - firstSize
            secondCount = 0
            while True:
                secondSize = min(id74, secondCount * id7)
                if secondSize >= id74:
                    secondSize = id74

                secondTime = secondSize * id90
                secondCost = secondCount * id51

                freeSize = id74 - secondSize
                freeTime = freeSize * id45

                if firstTime + secondTime + freeTime <= maxTime:
                    if answer > firstCost + secondCost:
                        answer = firstCost + secondCost
                        firstOptimal = firstCount
                        secondOptimal = secondCount

                if secondSize >= id74:
                    break

            if firstSize >= need:
                break

            firstCount += 1

        if answer == float('inf'):
            answer = -1

        return [answer, firstOptimal, secondOptimal]

    def read_int(self) -> int:
        return int(sys.stdin.readline().strip())

    def run(self):
        try:
            self.time_init()
            if self.id36:
                self.solve()
            else:
                while True:
                    try:
                        self.time_init()
                        self.solve()
                        print()
                    except ValueError:
                        break
                    except Exception as e:
                        if not self.id53:
                            raise e

            self.time()
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

    def time_init(self):
        self.time_begin = time.time()

    def time(self):
        time_end = time.time()
        print(f"Time = {time_end - self.time_begin}", file=sys.stderr)

if __name__ == "__main__":
    C().run()
