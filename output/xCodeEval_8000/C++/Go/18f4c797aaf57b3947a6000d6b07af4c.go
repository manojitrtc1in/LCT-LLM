package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	N = 1000009
	M = 10009
	Z = 26
)

var (
	A    [N]int
	buf  [Z]byte
	Q    [M]int
	have = make(map[int]bool)
	ans  = make(map[int]int)
	n, m int
)

func push(x int) {
	if !have[x] {
		have[x] = true
	} else {
		j := 0
		for ; stk[j] != x; j++ {
		}
		for ; j < nn-1; j++ {
			stk[j] = stk[j+1]
		}
		stk[nn-1] = x
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n = 0
	for {
		buf[0], _ = reader.ReadByte()
		if buf[0] == '\n' {
			break
		}
		A[n] = int(buf[0] - 'a')
		n++
	}
	A[n] = Z

	m = 0
	for {
		buf[0], _ = reader.ReadByte()
		if buf[0] == '\n' {
			break
		}
		if buf[0] == ' ' {
			continue
		}
		Q[m] = 0
		for {
			Q[m] |= 1 << (buf[0] - 'a')
			buf[0], _ = reader.ReadByte()
			if buf[0] == '\n' {
				break
			}
			if buf[0] == ' ' {
				break
			}
		}
		have[Q[m]] = true
		m++
	}

	nn = 0
	for i := 0; i < n; i++ {
		push(A[i])
		s := 0
		for j := nn; j >= 0; j-- {
			s |= 1 << stk[j]
			if s&(1<<A[i+1]) != 0 {
				break
			}
			if have[s] {
				ans[s]++
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(ans[Q[i]])
	}
}
