package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

const (
	eps  = 1e-9
	INFD = 1e18
	PI   = 3.14159265358979323846
	MOD  = 1e9 + 7
)

type SegTree[T any] struct {
	n, N, base int
	nodes      []T
}

func NewSegTree[T any](n int, init T) *SegTree[T] {
	N := int(math.Pow(2, math.Ceil(math.Log2(float64(n)))))
	base := N - 1
	nodes := make([]T, base+N)
	for i := range nodes {
		nodes[i] = init
	}
	return &SegTree[T]{n, N, base, nodes}
}

func (st *SegTree[T]) leftOf(index int) int {
	if index >= st.base {
		return -1
	}
	return index*2 + 1
}

func (st *SegTree[T]) rightOf(index int) int {
	if index >= st.base {
		return -1
	}
	return index*2 + 2
}

func (st *SegTree[T]) parentOf(index int) int {
	if index == 0 {
		return -1
	}
	return (index - 1) >> 1
}

func (st *SegTree[T]) updateRec(s, t, l, r, index int, v T) {
	if s == l && t == r {
		st.nodes[index] = v
	} else {
		mid := (l + r) / 2
		indexL := st.leftOf(index)
		indexR := st.rightOf(index)
		if s < mid && mid < t {
			st.updateRec(s, mid, l, mid, indexL, v)
			st.updateRec(mid, t, mid, r, indexR, v)
		} else if s < mid {
			st.updateRec(s, t, l, mid, indexL, v)
		} else if mid < t {
			st.updateRec(s, t, mid, r, indexR, v)
		}
		st.nodes[index] = st.nodes[indexL] + st.nodes[indexR]
	}
}

func (st *SegTree[T]) addRec(s, t, l, r, index int) T {
	if s == l && t == r {
		return st.nodes[index]
	} else {
		mid := (l + r) / 2
		indexL := st.leftOf(index)
		indexR := st.rightOf(index)
		var v0, v1 T
		if s < mid && mid < t {
			v0 = st.addRec(s, mid, l, mid, indexL)
			v1 = st.addRec(mid, t, mid, r, indexR)
		} else if s < mid {
			v0 = st.addRec(s, t, l, mid, indexL)
		} else if mid < t {
			v1 = st.addRec(s, t, mid, r, indexR)
		}
		return v0 + v1
	}
}

func (st *SegTree[T]) Update(k int, v T) {
	st.updateRec(k, k+1, 0, st.N, 0, v)
}

func (st *SegTree[T]) Sum(s, t int) T {
	return st.addRec(s, t, 0, st.N, 0)
}

type modll struct {
	val int64
}

func (x *modll) modify(v int64) int64 {
	ret := v % int64(MOD)
	if ret < 0 {
		ret += int64(MOD)
	}
	return ret
}

func (x *modll) inv(v int64) int64 {
	if v == 0 {
		return 1 / v
	} else if v == 1 {
		return 1
	}
	return x.modify(x.inv(int64(MOD)%v) * x.modify(-int64(MOD)/v))
}

func (x *modll) Add(y modll) modll {
	return modll{x.modify(x.val + y.val)}
}

func (x *modll) Sub(y modll) modll {
	return modll{x.modify(x.val - y.val)}
}

func (x *modll) Mul(y modll) modll {
	return modll{x.modify(x.val * y.val)}
}

func (x *modll) Div(y modll) modll {
	return modll{x.modify(x.val * x.inv(y.val))}
}

func (x *modll) GetVal() int64 {
	return x.val
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	st := NewSegTree[int64](n, 0)
	ast := NewSegTree[modll](n, modll{0})
	lst := NewSegTree[modll](n, modll{0})
	rst := NewSegTree[modll](n, modll{0})

	for i := 0; i < n; i++ {
		var w int64
		fmt.Scan(&w)
		st.Update(i, w)
		ast.Update(i, modll{w} * modll{a[i]})
		lst.Update(i, modll{w} * modll{int64(n - 1 - i)})
		rst.Update(i, modll{w} * modll{int64(i)})
	}

	ans := make([]modll, 0)
	for i := 0; i < q; i++ {
		var x int
		fmt.Scan(&x)
		if x < 0 {
			x++
			var y int64
			fmt.Scan(&y)
			st.Update(-x, y)
			ast.Update(-x, modll{y} * modll{a[-x]})
			lst.Update(-x, modll{y} * modll{int64(n - 1 - (-x))})
			rst.Update(-x, modll{y} * modll{int64(-x)})
		} else {
			var y int
			fmt.Scan(&y)
			x--
			y--
			if x == y {
				ans = append(ans, modll{0})
			} else {
				var halfid int
				if y-x == 1 {
					halfid = x
				} else {
					// Implement id4 function here
				}
				cand0 := st.Sum(x, halfid+1)
				cand1 := st.Sum(halfid+1, y+1)
				var dst int64
				var dstid int
				if cand0 <= cand1 {
					dst = a[halfid+1]
					dstid = halfid + 1
				} else {
					dst = a[halfid]
					dstid = halfid
				}
				buf := modll{0}
				buf = buf.Add(modll{dst}.Mul(st.Sum(x, dstid))).Sub(ast.Sum(x, dstid)).Sub(lst.Sum(x, dstid).Sub(modll{st.Sum(x, dstid}.Mul(modll{int64(n - 1 - dstid})})))
				buf = buf.Add(ast.Sum(dstid, y+1)).Sub(modll{dst}.Mul(st.Sum(dstid, y+1))).Sub(rst.Sum(dstid, y+1).Sub(modll{st.Sum(dstid, y+1}.Mul(modll{int64(dstid)})))
				ans = append(ans, buf)
			}
		}
	}
	for _, res := range ans {
		fmt.Println(res.GetVal())
	}
}
