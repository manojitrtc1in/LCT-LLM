package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v pt) add(u pt) pt {
	return pt{v.x + u.x, v.y + u.y}
}

type pair struct {
	x int
	y int
}

func (a pair) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (out *pair) operator(a pair) {
	out.x = a.x
	out.y = a.y
}

type vector struct {
	v []int
}

func (v vector) String() string {
	str := "["
	for i := 0; i < len(v.v); i++ {
		if i > 0 {
			str += ", "
		}
		str += fmt.Sprintf("%d", v.v[i])
	}
	str += "]"
	return str
}

func (out *vector) operator(v vector) {
	out.v = make([]int, len(v.v))
	copy(out.v, v.v)
}

func (out *vector) append(a int) {
	out.v = append(out.v, a)
}

func (out *vector) size() int {
	return len(out.v)
}

func (out *vector) reverse() {
	for i, j := 0, len(out.v)-1; i < j; i, j = i+1, j-1 {
		out.v[i], out.v[j] = out.v[j], out.v[i]
	}
}

func (out *vector) operator(i int) int {
	return out.v[i]
}

func (out *vector) operator(i int, a int) {
	out.v[i] = a
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int) *int {
	return &out.v[i]
}

func (out *vector) operator() {
	out.v = make([]int, 0)
}

func (out *vector) operator(i int, a int) {
	out.v = append(out.v[:i], append([]int{a}, out.v[i:]...)...)
}

const (
	INF    = int(1e9)
	INF64  = int64(1e18)
	MOD    = 998244353
	EPS    = 1e-9
	PI     = math.Acos(-1.0)
	N      = 300*1000 + 13
)

var (
	n  int
	g  [N]vector
	dp [N][3]int
)

func read() bool {
	if _, err := fmt.Scan(&n); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		g[i].operator()
	}
	for i := 0; i < n-1; i++ {
		var v, u int
		fmt.Scan(&v, &u)
		v--
		u--
		g[v].append(u)
		g[u].append(v)
	}
	return true
}

func add(a int, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	if a < 0 {
		a += MOD
	}
	return a
}

func mul(a int, b int) int {
	return a * b % MOD
}

func dfs(v int, p int) {
	dp[v][0] = 1
	dp[v][1] = 1
	vals := vector{}
	init := vector{}
	for _, u := range g[v].v {
		if u != p {
			dfs(u, v)
			vals.append(add(add(dp[u][1], dp[u][2]), dp[u][2]))
			init.append(add(dp[u][0], dp[u][1]))
			dp[v][0] = mul(dp[v][0], add(add(dp[u][1], dp[u][2]), dp[u][2]))
			dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]))
		}
	}
	dp[v][0] = add(dp[v][0], -dp[v][1])

	pr := vector{1}
	su := vector{1}
	for _, it := range vals.v {
		pr.append(mul(pr.v[len(pr.v)-1], it))
	}
	pr.reverse()
	for _, it := range vals.v {
		su.append(mul(su.v[len(su.v)-1], it))
	}
	su.reverse()
	dp[v][2] = 0
	for i := 0; i < vals.size(); i++ {
		dp[v][2] = add(dp[v][2], mul(init.v[i], mul(pr.v[i], su.v[i+1])))
	}
}

func solve() {
	dfs(0, -1)
	fmt.Println(add(dp[0][1], dp[0][2]))
}

func main() {
	rand.Seed(time.Now().UnixNano())

	tt := time.Now()

	for read() {
		solve()
	}

	fmt.Println("TIME =", time.Since(tt))
}
