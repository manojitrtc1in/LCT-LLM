package main

import (
	"bufio"
	"fmt"
	"os"
)

const Maxn = 100005

var l [Maxn]int
var r [Maxn]int
var n, m int
var sum [Maxn]int
var dp1 [Maxn]int
var dp2 [Maxn]int
var bit [Maxn]int

func read() int {
	x := 0
	f := 1
	reader := bufio.NewReader(os.Stdin)
	ch, _ := reader.ReadByte()
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		ch, _ = reader.ReadByte()
	}
	for ch >= '0' && ch <= '9' {
		x = x*10 + int(ch-'0')
		ch, _ = reader.ReadByte()
	}
	return x * f
}

func modify(pos, val int) {
	for pos < Maxn {
		bit[pos] = max(bit[pos], val)
		pos += pos & -pos
	}
}

func query(pos int) int {
	ans := 0
	for pos > 0 {
		ans = max(ans, bit[pos])
		pos -= pos & -pos
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, m = read(), read()
	for i := 0; i < n; i++ {
		l[i], r[i] = read(), read()
		sum[l[i]]++
		sum[r[i]+1]--
	}
	for i := 1; i <= m; i++ {
		sum[i] += sum[i-1]
	}
	dp1[0] = 0
	for i := 1; i <= m; i++ {
		dp1[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp1[i])
	}
	bit = [Maxn]int{}
	for i := m; i >= 1; i-- {
		dp2[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp2[i])
	}
	ans := 0
	for i := 1; i <= m; i++ {
		ans = max(ans, dp1[i]+dp2[i]-1)
	}
	fmt.Println(ans)
}
