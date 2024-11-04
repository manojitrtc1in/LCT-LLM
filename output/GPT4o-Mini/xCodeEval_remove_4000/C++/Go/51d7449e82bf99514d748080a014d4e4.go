package main

import (
	"fmt"
	"math"
	"os"
)

const N = 3000 + 10

var (
	n, k int
	m    [N]int
	a    [N][N]int
	ans  int64
	sum  [N]int64
)

func insert(dp []int64, a int, b int64) {
	for i := k; i >= a; i-- {
		dp[i] = int64(math.Max(float64(dp[i]), float64(dp[i-a]+b)))
	}
}

func DFS(l, r int, f []int64) {
	if l == r {
		ans = int64(math.Max(float64(ans), float64(f[k])))
		s := int64(0)
		for i := 1; i <= m[l] && i <= k; i++ {
			s += int64(a[l][i])
			ans = int64(math.Max(float64(ans), float64(s+f[k-i])))
		}
		return
	}
	g := make([]int64, k+1)
	mid := (l + r) >> 1
	copy(g, f)
	for i := mid + 1; i <= r; i++ {
		insert(g, m[i], sum[i])
	}
	DFS(l, mid, g)
	copy(g, f)
	for i := l; i <= mid; i++ {
		insert(g, m[i], sum[i])
	}
	DFS(mid+1, r, g)
}

func main() {
	file, err := os.Open("1.in")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	fmt.Fscanf(file, "%d %d\n", &n, &k)
	for i := 1; i <= n; i++ {
		fmt.Fscanf(file, "%d\n", &m[i])
		for j := 1; j <= m[i]; j++ {
			fmt.Fscanf(file, "%d\n", &a[i][j])
			sum[i] += int64(a[i][j])
		}
	}
	DFS(1, n, make([]int64, k+1))
	fmt.Println(ans)
}
