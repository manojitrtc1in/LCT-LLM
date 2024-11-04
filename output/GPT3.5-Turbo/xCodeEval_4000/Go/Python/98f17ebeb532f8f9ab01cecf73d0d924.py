import sys

def nextLine():
    return sys.stdin.readline().strip()

def nextWord():
    return nextLine()

def nextInt():
    return int(nextWord())

def nextInt64():
    return int(nextWord())

def nextFloat64():
    return float(nextWord())

def main():
    board = []
    for i in range(8):
        board.append(list(nextWord()))
    total = 0
    for i in range(8):
        count = 0
        for j in range(8):
            if board[i][j] == 'B':
                count += 1
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

if __name__ == "__main__":
    main()
