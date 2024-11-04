package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type ProblemC_76 struct {
	ONLINE_JUDGE bool
	in           *bufio.Reader
	out          *bufio.Writer
	tok          []string
}

func (p *ProblemC_76) init() {
	if p.ONLINE_JUDGE {
		p.in = bufio.NewReader(os.Stdin)
		p.out = bufio.NewWriter(os.Stdout)
	} else {
		p.in = bufio.NewReader(strings.NewReader(``)) // Replace with the input file path
		p.out = bufio.NewWriter(strings.NewReader(``)) // Replace with the output file path
	}
}

func (p *ProblemC_76) readString() string {
	for len(p.tok) == 0 {
		line, _ := p.in.ReadString('\n')
		p.tok = strings.Split(line, " ")
	}
	str := p.tok[0]
	p.tok = p.tok[1:]
	return str
}

func (p *ProblemC_76) readInt() int {
	num, _ := strconv.Atoi(p.readString())
	return num
}

func (p *ProblemC_76) readLong() int64 {
	num, _ := strconv.ParseInt(p.readString(), 10, 64)
	return num
}

func (p *ProblemC_76) readDouble() float64 {
	num, _ := strconv.ParseFloat(p.readString(), 64)
	return num
}

func main() {
	p := ProblemC_76{}
	p.run()
}

func (p *ProblemC_76) run() {
	p.init()
	p.solve()
	p.out.Flush()
}

func (p *ProblemC_76) solve() {
	n := p.readInt() - 1
	m := p.readInt()
	a := p.readInt() - 1
	b := p.readInt() - 1
	i := a / m
	j := b / m
	l := a % m
	r := b % m
	if r == n {
		r = m - 1
	}
	if l == 0 && r == m-1 {
		fmt.Fprint(p.out, 1)
		return
	}
	if j-i < 2 {
		fmt.Fprint(p.out, j-i+1)
		return
	}
	if (l != 0 && r == m-1) || (l == 0 && r != m-1) {
		fmt.Fprint(p.out, 2)
		return
	}
	if l-r == 1 {
		fmt.Fprint(p.out, 2)
		return
	}
	fmt.Fprint(p.out, 3)
}

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func binpow(a int64, n int) int64 {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		b := binpow(a, n/2)
		return b * b
	} else {
		return binpow(a, n-1) * a
	}
}

func phi(n int64) int64 {
	p := sieve(int64(math.Ceil(math.Sqrt(float64(n)))) + 2)
	phi := int64(1)
	for i := 0; i < len(p); i++ {
		x := int64(1)
		for n%p[i] == 0 {
			n /= p[i]
			x *= p[i]
		}
		phi *= x - x/p[i]
	}
	if n != 1 {
		phi *= n - 1
	}
	return phi
}

func sieve(n int64) []int64 {
	b := make([]bool, n+1)
	for i := int64(0); i <= n; i++ {
		b[i] = true
	}
	b[0] = false
	b[1] = false
	nLong := n
	j := 0
	for i := int64(1); i <= n; i++ {
		if b[i] {
			j++
			if i*i <= nLong {
				for k := i * i; k <= n; k += i {
					b[k] = false
				}
			}
		}
	}
	p := make([]int64, j)
	for i := int64(2); i <= n; i++ {
		if b[i] {
			p[j] = i
			j++
		}
	}
	return p
}
