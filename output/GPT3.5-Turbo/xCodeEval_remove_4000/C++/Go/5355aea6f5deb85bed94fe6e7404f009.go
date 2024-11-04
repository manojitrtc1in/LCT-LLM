package main

import (
	"fmt"
	"math"
	"sort"
)

func umax(a *int, b int) {
	if *a < b {
		*a = b
	}
}

func umin(a *int, b int) {
	if *a > b {
		*a = b
	}
}

func abs(a int) int {
	if a > 0 {
		return a
	} else {
		return -a
	}
}

func gcd(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a int, b int) int {
	return a / gcd(a, b) * b
}

func modpow(a int, n int, temp int) int {
	res := 1
	y := a
	for n > 0 {
		if n&1 == 1 {
			res = (res * y) % temp
		}
		y = (y * y) % temp
		n /= 2
	}
	return res % temp
}

func ison(mask int, pos int) int {
	return (mask & (1 << pos))
}

type vi []int
type vvi [][]int
type pii struct {
	first  int
	second int
}

func cbit(n int) int {
	k := 0
	for n != 0 {
		n &= (n - 1)
		k++
	}
	return k
}

func nbit(n int) int {
	k := 0
	for n != 0 {
		n /= 2
		k++
	}
	return k
}

const mod int = 1e9 + 7

func sgn(x int) int {
	if x < 0 {
		return -1
	} else {
		return 1
	}
}

const eps float64 = 1e-7
const pi float64 = math.Acos(-1.0)

func inc(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func dec(x *int, y int) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func chmax(x *int, y int) {
	if y > *x {
		*x = y
	}
}

func mulm(x *int, y int) {
	*x *= y
	if *x >= mod {
		*x -= mod
	}
}

func xo(i int) int {
	if (i & 3) == 0 {
		return i
	}
	if (i & 3) == 1 {
		return 1
	}
	if (i & 3) == 2 {
		return i + 1
	}
	return 0
}

type ver struct {
	first  int
	second pii
}

func main() {
	var data [][]int
	var n, i, j, k, l, m int
	fmt.Scan(&n)
	tot := 0
	for i = 1; i <= n; i++ {
		var k, a, x, y, m int
		fmt.Scan(&k, &a, &x, &y, &m)
		tot += k
		tmp := []int{a}
		for j = 2; j <= k; j++ {
			tmp = append(tmp, (tmp[len(tmp)-1]*x+y)%m)
		}
		data = append(data, tmp)
	}
	q := make([]ver, 0)
	for i = 0; i < n; i++ {
		q = append(q, ver{data[i][0], pii{i, 0}})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].first < q[j].first
	})
	ans := make([]int, 0)
	sol := make([]pii, 0)
	p := 0
	for len(ans) < tot {
		idx := -1
		for i := 0; i < len(q); i++ {
			if q[i].first == p {
				idx = i
				break
			}
		}
		if idx == -1 {
			idx = 0
		}
		v := q[idx].first
		p = v
		o := q[idx].second
		ans = append(ans, v)
		sol = append(sol, pii{v, o.first + 1})
		q = append(q[:idx], q[idx+1:]...)
		if o.second+1 < len(data[o.first]) {
			q = append(q, ver{data[o.first][o.second+1], pii{o.first, o.second + 1}})
		}
	}

	bad := 0
	for i = 1; i < len(ans); i++ {
		if ans[i-1] > ans[i] {
			bad++
		}
	}
	fmt.Println(bad)
	if tot <= 200000 {
		for i = 0; i < len(sol); i++ {
			fmt.Println(sol[i].first, sol[i].second)
		}
	}
}
