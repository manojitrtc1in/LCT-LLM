package main

import (
	"fmt"
)

const (
	MAX_MOD = 1000000007
	MOD     = 998244353
)

type modint struct {
	value int
}

func (a modint) add(b modint) modint {
	return modint{(a.value + b.value) % MAX_MOD}
}

func (a modint) sub(b modint) modint {
	return modint{(a.value - b.value + MAX_MOD) % MAX_MOD}
}

func (a modint) mul(b modint) modint {
	return modint{(a.value * b.value) % MAX_MOD}
}

func (a modint) pow(b int) modint {
	res := modint{1}
	for b > 0 {
		if b&1 == 1 {
			res = res.mul(a)
		}
		a = a.mul(a)
		b >>= 1
	}
	return res
}

func (a modint) div(b modint) modint {
	return a.mul(b.pow(MAX_MOD - 2))
}

type pair struct {
	first  modint
	second modint
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
	hoge := make([]pair, 300000)
	rev := make([]pair, 300000)
	nexts := pair{modint{1}, modint{1}}
	for i := 0; i < len(cnter); i++ {
		hoge[i+1] = hoge[i]
		hoge[i+1].first = hoge[i+1].first.add(nexts.first.mul(modint{cnter[i] % 2}))
		hoge[i+1].second = hoge[i+1].second.add(nexts.second.mul(modint{cnter[i] % 2}))
		rev[i+1] = rev[i]
		rev[i+1].first = rev[i+1].first.add(nexts.first.mul(modint{(cnter[i] + 1) % 2}))
		rev[i+1].second = rev[i+1].second.add(nexts.second.mul(modint{(cnter[i] + 1) % 2}))
		nexts.first = nexts.first.mul(modint{2})
		nexts.second = nexts.second.mul(modint{2})
	}
	var query int
	fmt.Scan(&query)
	for i := 0; i < query; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		a--
		b--
		Left := [2]int{lowerBound(cnter, a*2), lowerBound(cnter, (a+c)*2)}
		Right := [2]int{lowerBound(cnter, b*2), lowerBound(cnter, (b+c)*2)}
		if Left[1]-Left[0] != Right[1]-Right[0] {
			fmt.Println("No")
			continue
		}
		ok := 1
		aa := pair{hoge[Left[1]].first.sub(hoge[Left[0]].first), hoge[Left[1]].second.sub(hoge[Left[0]].second)}
		if a%2 == b%2 {
			bb := pair{hoge[Right[1]].first.sub(hoge[Right[0]].first), hoge[Right[1]].second.sub(hoge[Right[0]].second)}
			if Left[0] != 0 {
				aa.first = aa.first.div(nexts.first.pow(Left[0]))
				aa.second = aa.second.div(nexts.second.pow(Left[0]))
			}
			if Right[0] != 0 {
				bb.first = bb.first.div(nexts.first.pow(Right[0]))
				bb.second = bb.second.div(nexts.second.pow(Right[0]))
			}
			if aa.first.value != bb.first.value || aa.second.value != bb.second.value {
				ok = 0
			}
		} else {
			bb := pair{rev[Right[1]].first.sub(rev[Right[0]].first), rev[Right[1]].second.sub(rev[Right[0]].second)}
			if Left[0] != 0 {
				aa.first = aa.first.div(nexts.first.pow(Left[0]))
				aa.second = aa.second.div(nexts.second.pow(Left[0]))
			}
			if Right[0] != 0 {
				bb.first = bb.first.div(nexts.first.pow(Right[0]))
				bb.second = bb.second.div(nexts.second.pow(Right[0]))
			}
			if aa.first.value != bb.first.value || aa.second.value != bb.second.value {
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
		if arr[mid] >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func main() {
	solve()
}
