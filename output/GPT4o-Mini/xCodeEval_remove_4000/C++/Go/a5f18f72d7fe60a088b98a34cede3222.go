package main

import (
	"fmt"
	"math"
	"sort"
)

type Vector[T any] struct {
	data []T
}

func NewVector[T any](n int) Vector[T] {
	return Vector[T]{data: make([]T, n)}
}

func (v *Vector[T]) Get(index int) T {
	if index < 0 || index >= len(v.data) {
		panic("Out of bounds")
	}
	return v.data[index]
}

func (v *Vector[T]) Set(index int, value T) {
	if index < 0 || index >= len(v.data) {
		panic("Out of bounds")
	}
	v.data[index] = value
}

func (v *Vector[T]) Size() int {
	return len(v.data)
}

func (v *Vector[T]) Push(value T) {
	v.data = append(v.data, value)
}

func (v *Vector[T]) View() []T {
	if len(v.data) > 50 {
		return v.data[:50]
	}
	return v.data
}

type Input struct {
	data []string
	index int
}

func NewInput() *Input {
	var n int
	fmt.Scan(&n)
	data := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}
	return &Input{data: data}
}

func (in *Input) ReadInt() int {
	var value int
	fmt.Scan(&value)
	return value
}

func (in *Input) ReadIntArray(size int) Vector[int] {
	arr := NewVector[int](size)
	for i := 0; i < size; i++ {
		arr.Set(i, in.ReadInt())
	}
	return arr
}

type Output struct{}

func (out *Output) PrintLine(value int64) {
	fmt.Println(value)
}

func isPrime(n int64) bool {
	if n < 2 {
		return false
	}
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func nextPrime(n int64) int64 {
	if n <= 2 {
		return 2
	}
	n += 1 - (n & 1)
	for !isPrime(n) {
		n += 2
	}
	return n
}

func primes(n int) []int {
	isPrime := make([]bool, n)
	for i := 2; i < n; i++ {
		isPrime[i] = true
	}
	for i := 2; i*i < n; i++ {
		if isPrime[i] {
			for j := i * i; j < n; j += i {
				isPrime[j] = false
			}
		}
	}
	var res []int
	for i := 2; i < n; i++ {
		if isPrime[i] {
			res = append(res, i)
		}
	}
	return res
}

func id7(n int) Vector[int] {
	res := NewVector[int](n)
	for i := 0; i < n; i++ {
		res.Set(i, 0)
	}
	if n > 1 {
		res.Set(1, 1)
	}
	for i := 2; i < n; i++ {
		if res.Get(i) == 0 {
			res.Set(i, i)
			if int64(i)*int64(i) < int64(n) {
				for j := i * i; j < n; j += i {
					res.Set(j, i)
				}
			}
		}
	}
	return res
}

func collect(all *[]int, vals ...Vector[int]) {
	for _, v := range vals {
		for i := 0; i < v.Size(); i++ {
			*all = append(*all, v.Get(i))
		}
	}
}

func compress(vals ...Vector[int]) Vector[int] {
	var uniqueVals []int
	collect(&uniqueVals, vals...)
	sort.Ints(uniqueVals)
	uniqueVals = unique(uniqueVals)
	for _, v := range vals {
		for i := 0; i < v.Size(); i++ {
			v.Set(i, sort.SearchInts(uniqueVals, v.Get(i)))
		}
	}
	return NewVector[int](len(uniqueVals))
}

func unique(arr []int) []int {
	seen := make(map[int]struct{})
	var result []int
	for _, v := range arr {
		if _, ok := seen[v]; !ok {
			seen[v] = struct{}{}
			result = append(result, v)
		}
	}
	return result
}

type DKhaotichnayaV struct{}

func (solver *DKhaotichnayaV) Solve(inp *Input, out *Output) {
	n := inp.ReadInt()
	k := inp.ReadIntArray(n)

	p := primes(5000)
	d := id7(5001)
	id0 := make([]Vector[int], 5001)
	id0[0] = NewVector[int](0)
	id0[1] = NewVector[int](0)
	for i := 2; i < 5001; i++ {
		id0[i] = id0[i-1]
		if d.Get(i) == i {
			id0[i].Push(1)
		} else {
			for q := i; q > 1; q /= d.Get(q) {
				id0[i].Set(sort.SearchInts(p, d.Get(q)), id0[i].Get(sort.SearchInts(p, d.Get(q)))+1)
			}
		}
	}
	var answer int64 = 0
	q := make([]int, 5001)
	for i := 0; i < k.Size(); i++ {
		q[k.Get(i)]++
	}
	lost := 0
	still := make([]bool, 5001)
	for i := 0; i < 5001; i++ {
		still[i] = true
	}
	cur := NewVector[int](len(p))
	for {
		for i := 0; i < len(cur.data); i++ {
			cur.Set(i, 0)
		}
		for i := 0; i < 5001; i++ {
			if still[i] && id0[i].Size() > 0 {
				cur.Set(id0[i].Size()-1, cur.Get(id0[i].Size()-1)+q[i])
			}
		}
		pos := sort.SearchInts(cur.data, int(math.MaxInt32))
		if cur.Get(pos) <= n/2 {
			pos = -2
		}
		step := math.MaxInt32
		for i := 0; i < 5001; i++ {
			if still[i] && id0[i].Size()-1 != pos {
				answer += int64(q[i]) * int64(sum(id0[i].data))
				lost += q[i]
				still[i] = false
			} else if still[i] {
				step = int(math.Min(float64(step), float64(id0[i].Get(id0[i].Size()-1))))
			}
		}
		if pos == -2 {
			break
		}
		answer += int64(step) * int64(lost)
		for i := 0; i < 5001; i++ {
			if still[i] {
				id0[i].Set(id0[i].Size()-1, id0[i].Get(id0[i].Size()-1)-step)
				if id0[i].Get(id0[i].Size()-1) == 0 {
					id0[i].data = id0[i].data[:id0[i].Size()-1]
				}
			}
		}
	}
	out.PrintLine(answer)
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

func main() {
	inp := NewInput()
	out := &Output{}
	solver := DKhaotichnayaV{}
	solver.Solve(inp, out)
}
