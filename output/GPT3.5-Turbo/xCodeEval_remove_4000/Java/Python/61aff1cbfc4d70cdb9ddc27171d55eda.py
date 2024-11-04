import random

MODULO = 1000 * 1000 * 1000 + 7

def solve1():
    for it in range(10):
        need = random.randint(1, 10000)
        maxTime = random.randint(1, 10000000)
        id45 = random.randint(1, 10)

        id43 = random.randint(1, 100)
        id16 = random.randint(1, 10)
        id77 = random.randint(1, 10)

        id7 = random.randint(1, 100)
        id90 = random.randint(1, 10)
        id51 = random.randint(1, 10)

        answer = getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

        id59 = id52(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

        if answer[0] != id59[0]:
            print("GOTCHA")
            print(answer)
            print(id59)
            print(need, maxTime, id16)
            print(id43, id16, id77)
            print(id7, id90, id51)

def solve():
    need = readInt()
    maxTime = readInt()
    id45 = readInt()

    id43 = readInt()
    id16 = readInt()
    id77 = readInt()

    id7 = readInt()
    id90 = readInt()
    id51 = readInt()

    answer = getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

    print(answer[0])

def getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51):
    answer = float('inf')
    firstOptimal = 0
    secondOptimal = 0

    for firstCount in range(100000):
        firstSize = 0
        firstTime = 0
        firstCost = 0

        while True:
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

                        id31 = ((id74 * id45 - id42))
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

    for secondCount in range(100000):
        secondSize = 0
        secondCost = 0
        secondTime = 0

        while True:
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

                        id31 = ((id74 * id45 - id42))
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

def id52(need, maxTime, id45, id43, id16, id77, id7, id90, id51):
    answer = float('inf')
    firstOptimal = 0
    secondOptimal = 0

    for firstCount in range(100000):
        firstSize = 0
        firstTime = 0
        firstCost = 0

        while True:
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

                        id31 = ((id74 * id45 - id42))
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

    for secondCount in range(100000):
        secondSize = 0
        secondCost = 0
        secondTime = 0

        while True:
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

                        id31 = ((id74 * id45 - id42))
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

def main():
    solve()

if __name__ == "__main__":
    main()
