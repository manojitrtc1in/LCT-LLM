package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = INF + 7
	EPS     = 1e-9
	PI      = 3.141592653589793
	N       = 1000*1000 + 13
	AL      = 26
)

var (
	n   int
	s   string
	m   int
	t   [N]int
	nxt [N][AL]int
	cnt [N]int
	mx  [N]int
	masks = make(map[int]int)
)

func read() bool {
	var buf [N]byte
	if _, err := fmt.Scanf("%s", &buf); err != nil {
		return false
	}
	s = string(buf[:])
	n = len(s)
	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		if _, err := fmt.Scanf("%s", &buf); err != nil {
			return false
		}
		tmp := string(buf[:])
		x := 0
		for j := 0; j < len(tmp); j++ {
			x |= (1 << (tmp[j] - 'a'))
		}
		t[i] = x
	}
	return true
}

func solve() {
	for i := 0; i < AL; i++ {
		nxt[n][i] = n
	}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < AL; j++ {
			nxt[i][j] = nxt[i+1][j]
		}
		nxt[i][s[i]-'a'] = i
	}

	masks = make(map[int]int)
	for i := 0; i < m; i++ {
		if _, exists := masks[t[i]]; !exists {
			k := len(masks)
			masks[t[i]] = k
		}
	}

	for i := range cnt {
		cnt[i] = 0
	}
	for i := range mx {
		mx[i] = -1
	}

	for i := 0; i < n; i++ {
		lst := i
		cur := (1 << (s[lst] - 'a'))
		for {
			mn := n
			for j := 0; j < AL; j++ {
				if (cur>>j)&1 == 0 {
					mn = min(mn, nxt[lst][j])
				}
			}
			if x, exists := masks[cur]; exists {
				if mx[x] != mn-1 {
					mx[x] = mn - 1
					cnt[x]++
				}
			}
			if mn == n {
				break
			}
			lst = mn
			cur |= (1 << (s[lst] - 'a'))
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
	rand.Seed(time.Now().UnixNano())

	for read() {
		solve()
	}
}
