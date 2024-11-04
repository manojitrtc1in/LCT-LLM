package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = INF + 7
	EPS   = 1e-9
	PI    = acos(-1.0)

	N  = 1000*1000 + 13
	AL = 26
)

type pt struct {
	x, y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

type pair struct {
	first  interface{}
	second interface{}
}

func (a pair) String() string {
	return fmt.Sprintf("(%v, %v)", a.first, a.second)
}

type vector []interface{}

func (v vector) String() string {
	str := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			str += ", "
		}
		str += fmt.Sprintf("%v", v[i])
	}
	return str + "]"
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	s := readString()
	num, _ := strconv.Atoi(s)
	return num
}

func readInts() []int {
	s := readString()
	fields := strings.Fields(s)
	nums := make([]int, len(fields))
	for i, field := range fields {
		nums[i], _ = strconv.Atoi(field)
	}
	return nums
}

func read() (string, int, []int) {
	s := readString()
	n := len(s)
	m := readInt()
	t := make([]int, m)
	for i := 0; i < m; i++ {
		t[i] = readInt()
	}
	return s, m, t
}

func solve(s string, m int, t []int) {
	n := len(s)
	nxt := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		nxt[i] = make([]int, AL)
		for j := 0; j < AL; j++ {
			nxt[i][j] = n
		}
	}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < AL; j++ {
			nxt[i][j] = nxt[i+1][j]
		}
		nxt[i][int(s[i]-'a')] = i
	}

	masks := make(map[int]int)
	cnt := make([]int, N)
	mx := make([]int, N)

	for i := 0; i < m; i++ {
		if _, ok := masks[t[i]]; !ok {
			k := len(masks)
			masks[t[i]] = k
		}
	}

	for i := 0; i < n; i++ {
		lst := i
		cur := 1 << int(s[lst]-'a')
		for {
			mn := n
			for j := 0; j < AL; j++ {
				if cur>>j&1 == 0 {
					mn = min(mn, nxt[lst][j])
				}
			}
			if _, ok := masks[cur]; ok {
				x := masks[cur]
				if mx[x] != mn-1 {
					mx[x] = mn - 1
					cnt[x]++
				}
			}
			if mn == n {
				break
			}
			lst = mn
			cur |= 1 << int(s[lst]-'a')
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(cnt[masks[t[i]]])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	s := readString()
	m := readInt()
	t := make([]int, m)
	for i := 0; i < m; i++ {
		t[i] = readInt()
	}
	solve(s, m, t)
}
