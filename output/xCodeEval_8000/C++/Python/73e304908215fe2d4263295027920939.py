import sys
import math
import time

m, h1, a1, x1, y1 = map(int, input().split())
h2, a2, x2, y2 = map(int, input().split())
vis1 = [-1] * m
vis2 = [-1] * m

vis1[h1] = 0
cycleStart1 = -1
cycleLen1 = -1
while True:
    z = (h1 * x1 + y1) % m
    if vis1[z] != -1:
        cycleStart1 = vis1[z]
        cycleLen1 = vis1[h1] + 1 - vis1[z]
        break
    else:
        vis1[z] = vis1[h1] + 1
    h1 = z

vis2[h2] = 0
cycleStart2 = -1
cycleLen2 = -1
while True:
    z = (h2 * x2 + y2) % m
    if vis2[z] != -1:
        cycleStart2 = vis2[z]
        cycleLen2 = vis2[h2] + 1 - vis2[z]
        break
    else:
        vis2[z] = vis2[h2] + 1
    h2 = z

if vis1[a1] == -1 or vis2[a2] == -1:
    print("-1")
    sys.exit()

if vis1[a1] < cycleStart1 and vis2[a2] < cycleStart2:
    if vis1[a1] == vis2[a2]:
        print(vis1[a1])
    else:
        print("-1")
    sys.exit()

if vis1[a1] >= cycleStart1 and vis2[a2] >= cycleStart2:
    ans = -1
    for i in range(1000001):
        expected = vis1[a1] + cycleLen1 * i
        if (expected - vis2[a2]) % cycleLen2 == 0 and (expected - vis2[a2]) // cycleLen2 >= 0:
            ans = expected
            break
    print(ans)
    sys.exit()

if vis1[a1] < cycleStart1 and vis2[a2] >= cycleStart2:
    if (vis1[a1] - vis2[a2]) % cycleLen2 == 0 and (vis1[a1] - vis2[a2]) // cycleLen2 >= 0:
        print(vis1[a1])
    else:
        print("-1")
    sys.exit()

if vis1[a1] >= cycleStart1 and vis2[a2] < cycleStart2:
    if (vis2[a2] - vis1[a1]) % cycleLen1 == 0 and (vis2[a2] - vis1[a1]) // cycleLen1 >= 0:
        print(vis2[a2])
    else:
        print("-1")
    sys.exit()
