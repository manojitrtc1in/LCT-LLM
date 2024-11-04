import sys
import io

def main():
    board = []
    for i in range(8):
        board.append(list(next_word()))
    
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

def next_line():
    line = sys.stdin.readline().rstrip('\n')
    if not line:
        raise EOFError("next_line: EOF reached")
    return line

def next_word():
    while True:
        if not word_scanner:
            line = next_line()
            word_scanner = io.StringIO(line)
        word = word_scanner.read().split()[0]
        if word:
            return word

def next_int():
    return int(next_word())

def id3():
    return int(next_word())

def id6():
    return float(next_word())

if __name__ == "__main__":
    main()
