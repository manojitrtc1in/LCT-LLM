import sys

def main():
    path = list(next_word())
    x, y = 0, 0
    visited = set()
    visited.add((0, 0))
    for c in path:
        if c == 'U':
            y -= 1
        elif c == 'D':
            y += 1
        elif c == 'L':
            x -= 1
        elif c == 'R':
            x += 1
        if (x, y) in visited:
            print("BUG")
            return
        count = 0
        if (x - 1, y) in visited:
            count += 1
        if (x + 1, y) in visited:
            count += 1
        if (x, y - 1) in visited:
            count += 1
        if (x, y + 1) in visited:
            count += 1
        if count > 1:
            print("BUG")
            return
        visited.add((x, y))
    print("OK")

def next_line():
    return sys.stdin.readline().strip()

def next_word():
    return next_line().split()

if __name__ == "__main__":
    main()
