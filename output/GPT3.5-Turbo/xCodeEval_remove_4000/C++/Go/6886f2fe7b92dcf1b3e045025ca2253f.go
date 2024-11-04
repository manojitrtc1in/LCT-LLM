package main

import (
	"fmt"
	"math/big"
)

const (
	MAX_MOD = 1000000007
	MOD     = 998244353
)

type modint struct {
	value *big.Int
	mod   *big.Int
}

func newModint(a int64, mod int64) *modint {
	return &modint{
		value: big.NewInt(a),
		mod:   big.NewInt(mod),
	}
}

func (m *modint) add(rhs *modint) *modint {
	ans := new(big.Int).Add(m.value, rhs.value)
	ans.Mod(ans, m.mod)
	return &modint{
		value: ans,
		mod:   m.mod,
	}
}

func (m *modint) sub(rhs *modint) *modint {
	ans := new(big.Int).Sub(m.value, rhs.value)
	ans.Mod(ans, m.mod)
	return &modint{
		value: ans,
		mod:   m.mod,
	}
}

func (m *modint) mul(rhs *modint) *modint {
	ans := new(big.Int).Mul(m.value, rhs.value)
	ans.Mod(ans, m.mod)
	return &modint{
		value: ans,
		mod:   m.mod,
	}
}

func (m *modint) div(rhs *modint) *modint {
	inv := new(big.Int).ModInverse(rhs.value, m.mod)
	ans := new(big.Int).Mul(m.value, inv)
	ans.Mod(ans, m.mod)
	return &modint{
		value: ans,
		mod:   m.mod,
	}
}

func (m *modint) pow(b int64) *modint {
	ans := new(big.Int).Exp(m.value, big.NewInt(b), m.mod)
	return &modint{
		value: ans,
		mod:   m.mod,
	}
}

func (m *modint) equal(rhs *modint) bool {
	return m.value.Cmp(rhs.value) == 0
}

func (m *modint) less(rhs *modint) bool {
	return m.value.Cmp(rhs.value) < 0
}

func (m *modint) String() string {
	return m.value.String()
}

type pair struct {
	first  *modint
	second *modint
}

func newPair(a, b *modint) *pair {
	return &pair{
		first:  a,
		second: b,
	}
}

func solve() {
	var n int
	fmt.Scan(&n)
	var t string
	fmt.Scan(&t)

	cnter := make([]int, 0)
	for i := 0; i < len(t); i++ {
		if t[i] == '0' {
			cnter = append(cnter, i*2+i%2)
		}
	}

	hoge := make([]*pair, 300000)
	rev := make([]*pair, 300000)
	nexts := newPair(newModint(1, MAX_MOD), newModint(1, MOD))
	for i := 0; i < len(cnter); i++ {
		hoge[i+1] = newPair(hoge[i].first.add(nexts.first.mul(newModint(int64(cnter[i]%2), MAX_MOD))), hoge[i].second.add(nexts.second.mul(newModint(int64(cnter[i]%2), MOD))))
		rev[i+1] = newPair(rev[i].first.add(nexts.first.mul(newModint(int64((cnter[i]+1)%2), MAX_MOD))), rev[i].second.add(nexts.second.mul(newModint(int64((cnter[i]+1)%2), MOD))))
		nexts.first = nexts.first.mul(newModint(2, MAX_MOD))
		nexts.second = nexts.second.mul(newModint(2, MOD))
	}

	var query int
	fmt.Scan(&query)
	for i := 0; i < query; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		a--
		b--
		left := []int{lowerBound(cnter, a*2), lowerBound(cnter, (a+c)*2)}
		right := []int{lowerBound(cnter, b*2), lowerBound(cnter, (b+c)*2)}
		if left[1]-left[0] != right[1]-right[0] {
			fmt.Println("No")
			continue
		}
		ok := 1
		aa := newPair(hoge[left[1]].first.sub(hoge[left[0]].first), hoge[left[1]].second.sub(hoge[left[0]].second))
		if a%2 == b%2 {
			bb := newPair(hoge[right[1]].first.sub(hoge[right[0]].first), hoge[right[1]].second.sub(hoge[right[0]].second))
			aa.first = aa.first.div(hoge[left[0]].first.pow(left[0]))
			aa.second = aa.second.div(hoge[left[0]].second.pow(left[0]))
			bb.first = bb.first.div(hoge[right[0]].first.pow(right[0]))
			bb.second = bb.second.div(hoge[right[0]].second.pow(right[0]))
			if !aa.first.equal(bb.first) || !aa.second.equal(bb.second) {
				ok = 0
			}
		} else {
			bb := newPair(rev[right[1]].first.sub(rev[right[0]].first), rev[right[1]].second.sub(rev[right[0]].second))
			aa.first = aa.first.div(hoge[left[0]].first.pow(left[0]))
			aa.second = aa.second.div(hoge[left[0]].second.pow(left[0]))
			bb.first = bb.first.div(rev[right[0]].first.pow(right[0]))
			bb.second = bb.second.div(rev[right[0]].second.pow(right[0]))
			if !aa.first.equal(bb.first) || !aa.second.equal(bb.second) {
				ok = 0
			}
		}
		if ok == 1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func lowerBound(arr []int, target int) int {
	left := 0
	right := len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func main() {
	solve()
}
