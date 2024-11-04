package main

import (
	"fmt"
	"math"
	"sort"
)

type pii struct {
	first, second int64
}

type ver struct {
	first  int64
	second pii
}

func umax(a *int64, b int64) {
	if *a < b {
		*a = b
	}
}

func umin(a *int64, b int64) {
	if *a > b {
		*a = b
	}
}

func abs(a int64) int64 {
	if a > 0 {
		return a
	}
	return -a
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func modpow(a, n, temp int64) int64 {
	res := int64(1)
	y := a
	for n > 0 {
		if n&1 != 0 {
			res = (res * y) % temp
		}
		y = (y * y) % temp
		n /= 2
	}
	return res % temp
}

func ison(mask, pos int64) int64 {
	return (mask & (1 << pos))
}

func cbit(n int64) int64 {
	k := int64(0)
	for n != 0 {
		n &= (n - 1)
		k++
	}
	return k
}

func nbit(n int64) int64 {
	k := int64(0)
	for n != 0 {
		n /= 2
		k++
	}
	return k
}

var mod int64 = 1e9 + 7

func sgn(x int64) int64 {
	if x < 0 {
		return -1
	}
	if x > 0 {
		return 1
	}
	return 0
}

const eps = 1e-7
const pi = math.Pi

func inc(x *int64, y int64) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func dec(x *int64, y int64) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func chmax(x *int64, y int64) {
	if y > *x {
		*x = y
	}
}

func mulm(x *int64, y int64) {
	*x *= y
	if *x >= mod {
		*x -= mod
	}
}

func xo(i int64) int64 {
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

func main() {
	var n int64
	fmt.Scan(&n)
	tot := int64(0)
	data := make([][]int64, n)

	for i := int64(0); i < n; i++ {
		var k, a, x, y, m int64
		fmt.Scan(&k, &a, &x, &y, &m)
		tot += k
		tmp := make([]int64, 0)
		tmp = append(tmp, a)
		for j := int64(2); j <= k; j++ {
			tmp = append(tmp, (tmp[len(tmp)-1]*x+y)%m)
		}
		data[i] = tmp
	}

	q := make([]ver, 0)
	for i := int64(0); i < n; i++ {
		q = append(q, ver{data[i][0], pii{i, 0}})
	}
	sort.Slice(q, func(i, j int) bool {
		return q[i].first < q[j].first
	})

	ans := make([]int64, 0)
	sol := make([]pii, 0)
	p := int64(0)

	for int64(len(ans)) < tot {
		it := sort.Search(len(q), func(i int) bool {
			return q[i].first >= p
		})
		if it == len(q) {
			it = 0
		}
		v := q[it].first
		p = v
		o := q[it].second
		ans = append(ans, v)
		sol = append(sol, pii{v, o.first + 1})
		q = append(q[:it], q[it+1:]...) // remove element

		if o.second+1 < int64(len(data[o.first])) {
			q = append(q, ver{data[o.first][o.second+1], pii{o.first, o.second + 1}})
			sort.Slice(q, func(i, j int) bool {
				return q[i].first < q[j].first
			})
		}
	}

	bad := int64(0)
	for i := int64(1); i < int64(len(ans)); i++ {
		if ans[i-1] > ans[i] {
			bad++
		}
	}
	fmt.Println(bad)
	if tot <= 200000 {
		for i := int64(0); i < int64(len(sol)); i++ {
			fmt.Println(sol[i].first, sol[i].second)
		}
	}
}
