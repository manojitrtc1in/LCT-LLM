import sys

def main():
    board = [list(next_word()) for _ in range(8)]
    total = 0

    for i in range(8):
        count = sum(1 for j in range(8) if board[i][j] == 'B')
        if count == 8:
            for j in range(8):
                board[i][j] = 'A'
            total += 1

    for i in range(8):
        for j in range(8):
            if board[j][i] == 'B':
                total += 1
                break

    print(total)

def next_line():
    return sys.stdin.readline().strip()

def next_word():
    return next_line()

if __name__ == "__main__":
    main()
