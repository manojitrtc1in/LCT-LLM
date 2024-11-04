package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Input struct {
	scanner *bufio.Scanner
}

func NewInput() *Input {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	return &Input{scanner}
}

func (in *Input) ReadInt() int {
	in.scanner.Scan()
	val, _ := strconv.Atoi(in.scanner.Text())
	return val
}

func (in *Input) ReadIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = in.ReadInt()
	}
	return arr
}

type Output struct {
	writer *bufio.Writer
}

func NewOutput() *Output {
	return &Output{bufio.NewWriter(os.Stdout)}
}

func (out *Output) Print(args ...interface{}) {
	fmt.Fprint(out.writer, args...)
}

func (out *Output) Println(args ...interface{}) {
	out.Print(args...)
	out.Print("\n")
}

func (out *Output) Flush() {
	out.writer.Flush()
}

func primalityTable(n int) []bool {
	res := make([]bool, n)
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

func divisorTable(n int) []int {
	res := make([]int, n)
	if n > 1 {
		res[1] = 1
	}
	for i := 2; i < n; i++ {
		if res[i] == 0 {
			res[i] = i
			if int64(i)*int64(i) < int64(n) {
				for j := i * i; j < n; j += i {
					res[j] = i
				}
			}
		}
	}
	return res
}

func primes(n int) []int {
	isPrime := primalityTable(n)
	var res []int
	for i := 0; i < n; i++ {
		if isPrime[i] {
			res = append(res, i)
		}
	}
	return res
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

func unique(v []int) {
	seen := make(map[int]bool)
	j := 0
	for i := 0; i < len(v); i++ {
		if !seen[v[i]] {
			seen[v[i]] = true
			v[j] = v[i]
			j++
		}
	}
	v = v[:j]
}

func createOrder(n int) []int {
	order := make([]int, n)
	for i := 0; i < n; i++ {
		order[i] = i
	}
	return order
}

func inverse(p []int) []int {
	res := make([]int, len(p))
	for i := 0; i < len(p); i++ {
		res[p[i]] = i
	}
	return res
}

func addAll(v []int, begin, end []int) []int {
	v = append(v, begin...)
	return append(v, end...)
}

func getQty(begin, end []int, length int) []int {
	res := make([]int, length)
	for _, val := range begin {
		res[val]++
	}
	return res
}

func collect(all []int, a []int, vs ...[]int) {
	all = addAll(all, a, vs...)
}

func replace(all []int) {}

func replace(all []int, a []int, vs ...[]int) {
	for i := 0; i < len(a); i++ {
		pos := sort.SearchInts(all, a[i])
		a[i] = pos
	}
	replace(all, vs...)
}

func compress(vs ...[]int) []int {
	var vals []int
	collect(vals, vs...)
	sort.Ints(vals)
	replace(vals, vs...)
	return vals
}

func DKhaotichnayaV() {
	in := NewInput()
	out := NewOutput()

	n := in.ReadInt()
	k := in.ReadIntArray(n)

	p := primes(5000)
	d := divisorTable(5001)
	divisors := make([][]int, 5001)
	divisors[0] = []int{}
	divisors[1] = []int{}
	for i := 2; i < 5001; i++ {
		divisors[i] = divisors[i-1]
		if d[i] == i {
			divisors[i] = append(divisors[i], 1)
		} else {
			for q := i; q > 1; q /= d[q] {
				divisors[i] = append(divisors[i], sort.SearchInts(p, d[q]))
			}
		}
	}
	answer := int64(0)
	q := getQty(k, 5001)
	lost := 0
	still := make([]bool, 5001)
	for i := 0; i < 5001; i++ {
		still[i] = true
	}
	cur := make([]int, len(p))
	for {
		for i := 0; i < len(cur); i++ {
			cur[i] = 0
		}
		for i := 0; i < 5001; i++ {
			if still[i] && len(divisors[i]) > 0 {
				cur[len(divisors[i])-1] += q[i]
			}
		}
		pos := 0
		maxVal := cur[0]
		for i := 1; i < len(cur); i++ {
			if cur[i] > maxVal {
				maxVal = cur[i]
				pos = i
			}
		}
		if maxVal <= n/2 {
			pos = -2
		}
		step := int(^uint(0) >> 1)
		for i := 0; i < 5001; i++ {
			if still[i] && len(divisors[i]) > 0 && len(divisors[i])-1 != pos {
				answer += int64(q[i]) * int64(len(divisors[i]))
				lost += q[i]
				still[i] = false
			} else if still[i] {
				if divisors[i][len(divisors[i])-1] < step {
					step = divisors[i][len(divisors[i])-1]
				}
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
	out.Println(answer)
	out.Flush()
}

func main() {
	DKhaotichnayaV()
}
