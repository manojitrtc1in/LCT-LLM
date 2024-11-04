import sys

def main():
    path = next_word()
    x, y = 0, 0
    visited = {0: True}
    
    for c in path:
        if c == 'U':
            y -= 1
        elif c == 'D':
            y += 1
        elif c == 'L':
            x -= 1
        elif c == 'R':
            x += 1
        
        if (x * 1000 + y) in visited:
            print("BUG")
            return
        
        count = 0
        if (x - 1) * 1000 + y in visited:
            count += 1
        if (x + 1) * 1000 + y in visited:
            count += 1
        if x * 1000 + (y - 1) in visited:
            count += 1
        if x * 1000 + (y + 1) in visited:
            count += 1
        
        if count > 1:
            print("BUG")
            return
        
        visited[x * 1000 + y] = True
    
    print("OK")

def next_line():
    return sys.stdin.readline().strip()

def next_word():
    return next_line()

if __name__ == "__main__":
    main()
