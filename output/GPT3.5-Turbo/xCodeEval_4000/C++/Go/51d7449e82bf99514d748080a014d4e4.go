package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 3000 + 10

var n, k int
var m [N]int
var a [N][N]int
var ans, sum [N]int64

func insert(dp []int64, a int, b int64) {
	for i := k; i >= a; i-- {
		dp[i] = max(dp[i], dp[i-a]+b)
	}
}

func DFS(l, r int, f []int64) {
	if l == r {
		ans = max(ans, f[k])
		var s int64
		for i := 1; i <= m[l] && i <= k; i++ {
			s += int64(a[l][i])
			ans = max(ans, s+f[k-i])
		}
		return
	}
	var g []int64
	mid := (l + r) >> 1
	g = make([]int64, k+1)
	copy(g, f)
	for i := mid + 1; i <= r; i++ {
		insert(g, m[i], sum[i])
	}
	DFS(l, mid, g)
	g = make([]int64, k+1)
	copy(g, f)
	for i := l; i <= mid; i++ {
		insert(g, m[i], sum[i])
	}
	DFS(mid+1, r, g)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	for i := 1; i <= n; i++ {
		scanner.Scan()
		m[i], _ = strconv.Atoi(scanner.Text())
		for j := 1; j <= m[i]; j++ {
			scanner.Scan()
			a[i][j], _ = strconv.Atoi(scanner.Text())
			sum[i] += int64(a[i][j])
		}
	}

	DFS(1, n, make([]int64, k+1))
	fmt.Println(ans)
}