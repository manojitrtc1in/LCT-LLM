package main

import (
	"fmt"
	"math"
	"sort"
)

type Vector []int

func NewVector(size int) Vector {
	return make(Vector, size)
}

func (v Vector) Get(index int) int {
	if index < 0 || index >= len(v) {
		panic("Out of bounds")
	}
	return v[index]
}

func (v Vector) Set(index, value int) {
	if index < 0 || index >= len(v) {
		panic("Out of bounds")
	}
	v[index] = value
}

func (v Vector) Size() int {
	return len(v)
}

func PrimalityTable(n int) []bool {
	res := make([]bool, n)
	for i := range res {
		res[i] = true
	}
	if n > 0 {
		res[0] = false
	}
	if n > 1 {
		res[1] = false
	}
	for i := 2; i*i < n; i++ {
		if res[i] {
			for j := i * i; j < n; j += i {
				res[j] = false
			}
		}
	}
	return res
}

func DivisorTable(n int) Vector {
	res := NewVector(n)
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

func Primes(n int) Vector {
	isPrime := PrimalityTable(n)
	var res Vector
	for i := 0; i < n; i++ {
		if isPrime[i] {
			res = append(res, i)
		}
	}
	return res
}

func IsPrime(n int64) bool {
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

func NextPrime(n int64) int64 {
	if n <= 2 {
		return 2
	}
	n += 1 - (n & 1)
	for !IsPrime(n) {
		n += 2
	}
	return n
}

func Unique(v Vector) {
	sort.Ints(v)
	j := 0
	for i := 1; i < len(v); i++ {
		if v[i] != v[j] {
			j++
			v[j] = v[i]
		}
	}
	v = v[:j+1]
}

func CreateOrder(n int) Vector {
	order := NewVector(n)
	for i := 0; i < n; i++ {
		order.Set(i, i)
	}
	return order
}

func Inverse(p Vector) Vector {
	res := NewVector(len(p))
	for i := range p {
		res.Set(p[i], i)
	}
	return res
}

func GetQty(begin, end []int, length int) Vector {
	res := NewVector(length)
	for _, it := range begin {
		res.Set(it, res.Get(it)+1)
	}
	return res
}

func Compress(vs ...Vector) Vector {
	vals := Vector{}
	for _, v := range vs {
		vals = append(vals, v...)
	}
	sort.Ints(vals)
	Unique(vals)
	for _, v := range vs {
		for i := range v {
			v[i] = sort.SearchInts(vals, v[i])
		}
	}
	return vals
}

type DKhaotichnayaV struct{}

func (d *DKhaotichnayaV) Solve(n int, k Vector) int64 {
	p := Primes(5000)
	dTable := DivisorTable(5001)
	divisors := make([]Vector, 5001)
	for i := range divisors {
		divisors[i] = Vector{}
	}
	for i := 2; i < 5001; i++ {
		divisors[i] = append(divisors[i], divisors[i-1]...)
		if dTable.Get(i) == i {
			divisors[i] = append(divisors[i], 1)
		} else {
			for q := i; q > 1; q /= dTable.Get(q) {
				divisors[i][sort.SearchInts(p, dTable.Get(q))]++
			}
		}
	}
	answer := int64(0)
	q := GetQty(k, k, 5001)
	lost := 0
	still := make([]bool, 5001)
	for i := range still {
		still[i] = true
	}
	cur := NewVector(len(p))
	for {
		for i := range cur {
			cur[i] = 0
		}
		for i := 0; i < 5001; i++ {
			if still[i] && len(divisors[i]) > 0 {
				cur[len(divisors[i])-1] += q.Get(i)
			}
		}
		pos := sort.SearchInts(cur, int(math.MaxInt32))
		if cur[pos] <= n/2 {
			pos = -2
		}
		step := math.MaxInt32
		for i := 0; i < 5001; i++ {
			if still[i] && len(divisors[i])-1 != pos {
				answer += int64(q.Get(i)) * int64(sum(divisors[i]))
				lost += q.Get(i)
				still[i] = false
			} else if still[i] {
				step = int(math.Min(float64(step), float64(divisors[i][len(divisors[i])-1])))
			}
		}
		if pos == -2 {
			break
		}
		answer += int64(step) * int64(lost)
		for i := 0; i < 5001; i++ {
			if still[i] {
				divisors[i][len(divisors[i])-1] -= step
				if divisors[i][len(divisors[i])-1] == 0 {
					divisors[i] = divisors[i][:len(divisors[i])-1]
				}
			}
		}
	}
	return answer
}

func sum(v Vector) int {
	total := 0
	for _, val := range v {
		total += val
	}
	return total
}

func main() {
	var n int
	fmt.Scan(&n)
	k := NewVector(n)
	for i := 0; i < n; i++ {
		fmt.Scan(&k[i])
	}
	solver := DKhaotichnayaV{}
	answer := solver.Solve(n, k)
	fmt.Println(answer)
}
