package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type ProblemC76 struct {
	onlineJudge bool
	in          *bufio.Reader
	out         *bufio.Writer
	tok         *strings.Reader
}

func (p *ProblemC76) init() {
	p.onlineJudge = os.Getenv("ONLINE_JUDGE") != ""
	if p.onlineJudge {
		p.in = bufio.NewReader(os.Stdin)
		p.out = bufio.NewWriter(os.Stdout)
	} else {
		file, _ := os.Open("input.txt")
		p.in = bufio.NewReader(file)
		fileOut, _ := os.Create("output.txt")
		p.out = bufio.NewWriter(fileOut)
	}
}

func (p *ProblemC76) readString() string {
	if p.tok == nil {
		line, _ := p.in.ReadString('\n')
		p.tok = strings.NewReader(line)
	}
	s, _ := p.tok.ReadString(' ')
	return strings.TrimSpace(s)
}

func (p *ProblemC76) readInt() int {
	i, _ := strconv.Atoi(p.readString())
	return i
}

func (p *ProblemC76) readLong() int64 {
	i, _ := strconv.ParseInt(p.readString(), 10, 64)
	return i
}

func (p *ProblemC76) readDouble() float64 {
	f, _ := strconv.ParseFloat(p.readString(), 64)
	return f
}

func (p *ProblemC76) run() {
	defer p.out.Flush()
	p.init()
	p.solve()
}

func (p *ProblemC76) solve() {
	n := p.readInt() - 1
	m := p.readInt()
	a := p.readInt() - 1
	b := p.readInt() - 1
	i := a / m
	j := b / m
	l := a % m
	r := b
	if b == n {
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

func main() {
	problem := &ProblemC76{}
	problem.run()
}
