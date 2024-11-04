package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var vec [1010101][]int
var vid [1010101]int
var pr [1010101]int
var primes []int
var used map[int64]int
var maxh int64
var w [][]int
var g [5001][]int
var dc [5001]int
var dist [301][10002]int
var vis [10002]bool
var ans [303][303]int

func calc(v []int) int64 {
	sort.Ints(v)
	var res int64 = 0
	for _, x := range v {
		res = res*30 + int64(x)
	}
	return res
}

func calcd(v []int) int {
	res := 1
	for _, x := range v {
		res *= x + 1
	}
	return res
}

func addUsed(v *[]int, t []int) {
	x := calc(t)
	if _, ok := used[x]; !ok {
		sz := len(used)
		used[x] = sz
		w = append(w, t)
		dc[sz] = calcd(t)
	}
	*v = append(*v, used[x])
}

func solve() int {
	w = append(w, []int{})
	used = make(map[int64]int)
	used[0] = 0
	const N = 1000010
	for i := 2; i < N; i++ {
		if pr[i] == 0 {
			pr[i] = i
			primes = append(primes, i)
		}
		for _, p := range primes {
			if p*i >= N || p > pr[i] {
				break
			}
			pr[p*i] = p
		}
		cnt := 1
		x := i
		for pr[x] == pr[x/pr[x]] {
			cnt++
			x /= pr[x]
		}
		x /= pr[x]
		vec[i] = append(vec[i], vec[x]...)
		vec[i] = append(vec[i], cnt)
		h := calc(vec[i])
		maxh = max(maxh, h)
		id, ok := used[h]
		if !ok {
			id = len(w)
			w = append(w, vec[i])
			used[h] = id
		}
		vid[i] = id
	}
	ws := len(w)
	for i := 0; i < min(len(w), 5001); i++ {
		cur := w[i]
		for j := 0; j < len(cur); j++ {
			t := make([]int, len(cur))
			copy(t, cur)
			t[j]--
			addUsed(&g[i], t)
			t[j] += 2
			addUsed(&g[i], t)
		}
		cur = append(cur, 1)
		addUsed(&g[i], cur)
		sort.Ints(g[i])
		g[i] = removeDuplicates(g[i])
		dc[i] = calcd(w[i])
	}
	for i := 0; i < ws; i++ {
		for j := 0; j < 5001; j++ {
			dist[i][j] = 1011111111
		}
	}
	for i := 0; i < ws; i++ {
		vis = make([]bool, 10002)
		q := []int{i}
		dp := make([]int, len(used))
		for j := 0; j < len(used); j++ {
			dp[j] = 1011111111
		}
		dp[i] = 0
		for j := 0; j < len(q); j++ {
			cur := q[j]
			dcur := dp[cur]
			for _, to := range g[cur] {
				if dp[to] == 1011111111 {
					dp[to] = dcur + 1
					q = append(q, to)
				}
			}
		}
		for j := 0; j < len(used); j++ {
			if dc[j] < 5001 {
				dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
			}
		}
	}
	for i := 0; i < ws; i++ {
		dist[i][0] = 1011111111
		for j := 0; j < i+1; j++ {
			res := 1011111111
			for k := 0; k < 5001; k++ {
				res = min(res, dist[i][k]+dist[j][k])
			}
			ans[i][j] = res
		}
	}
	n := readInt()
	for ; n > 0; n-- {
		a := readInt()
		b := readInt()
		a = vid[a]
		b = vid[b]
		if a < b {
			a, b = b, a
		}
		writeInt(ans[a][b])
	}
	return 0
}

func removeDuplicates(nums []int) []int {
	if len(nums) == 0 {
		return nums
	}
	i := 0
	for j := 1; j < len(nums); j++ {
		if nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}
	return nums[:i+1]
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func writeInt(num int) {
	fmt.Println(num)
}

var scanner *bufio.Scanner

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	solve()
}
