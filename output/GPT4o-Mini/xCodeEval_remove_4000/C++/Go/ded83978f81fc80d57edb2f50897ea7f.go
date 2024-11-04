package main

import (
	"fmt"
	"math"
	"strings"
)

type Scanner struct{}

func (s *Scanner) ScanBool() bool {
	var var bool
	fmt.Scanf("%d", &var)
	return var
}

func (s *Scanner) ScanInt() int {
	var var int
	fmt.Scanf("%d", &var)
	return var
}

func (s *Scanner) ScanUint() uint {
	var var uint
	fmt.Scanf("%u", &var)
	return var
}

func (s *Scanner) ScanInt64() int64 {
	var var int64
	fmt.Scanf("%d", &var)
	return var
}

func (s *Scanner) ScanUint64() uint64 {
	var var uint64
	fmt.Scanf("%d", &var)
	return var
}

func (s *Scanner) ScanFloat64() float64 {
	var var float64
	fmt.Scanf("%lf", &var)
	return var
}

func (s *Scanner) ScanString() string {
	var var string
	fmt.Scanf("%s", &var)
	return var
}

type Printer struct{}

func (p *Printer) PrintBool(var bool) {
	fmt.Printf("%d", var)
}

func (p *Printer) PrintInt(var int) {
	fmt.Printf("%d", var)
}

func (p *Printer) PrintUint(var uint) {
	fmt.Printf("%u", var)
}

func (p *Printer) PrintInt64(var int64) {
	fmt.Printf("%d", var)
}

func (p *Printer) PrintUint64(var uint64) {
	fmt.Printf("%d", var)
}

func (p *Printer) PrintFloat64(var float64) {
	fmt.Printf("%f", var)
}

func (p *Printer) PrintString(var string) {
	fmt.Printf("%s", var)
}

func sum_(vars ...int) int {
	total := 0
	for _, v := range vars {
		total += v
	}
	return total
}

func max_(vars ...int) int {
	maxVal := vars[0]
	for _, v := range vars {
		if v > maxVal {
			maxVal = v
		}
	}
	return maxVal
}

func min_(vars ...int) int {
	minVal := vars[0]
	for _, v := range vars {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

func eq(a, b float64) bool {
	return math.Abs(a-b) <= 0.00000001
}

func solve() {
	scanner := Scanner{}
	printer := Printer{}

	A := scanner.ScanString()
	B := scanner.ScanString()
	V := scanner.ScanString()
	nA := len(A)
	nB := len(B)
	nV := len(V)

	prefix := make([][]int, nV)
	for i := range prefix {
		prefix[i] = make([]int, 256)
	}

	for iV := 0; iV < nV; iV++ {
		for C := 'A'; C <= 'Z'; C++ {
			prefix[iV][C] = iV + 1
			for prefix[iV][C] > 0 {
				if V[:prefix[iV][C]] == V[iV+2-prefix[iV][C]:iV+1] + string(C) {
					break
				}
				prefix[iV][C]--
			}
		}
	}

	d := make([][][]int, nA+1)
	c := make([][][]int, nA+1)
	for i := range d {
		d[i] = make([][]int, nB+1)
		c[i] = make([][]int, nB+1)
		for j := range d[i] {
			d[i][j] = make([]int, nV)
			c[i][j] = make([]int, nV)
		}
	}

	mx := 0
	cans := 0

	for iA := 1; iA <= nA; iA++ {
		for iB := 1; iB <= nB; iB++ {
			for iV := 0; iV < nV; iV++ {
				d[iA][iB][iV] = -1
				if d[iA][iB][iV] < d[iA-1][iB][iV] {
					c[iA][iB][iV] = -1
				}
				if d[iA][iB][iV] < d[iA][iB-1][iV] {
					c[iA][iB][iV] = -2
				}
			}
			for iV := 0; iV < nV; iV++ {
				if A[iA-1] == B[iB-1] {
					if d[iA][iB][prefix[iV][A[iA-1]]] < d[iA-1][iB-1][iV]+1 {
						c[iA][iB][prefix[iV][A[iA-1]]] = iV
					}
				}
			}
		}
	}

	for iV := 0; iV < nV; iV++ {
		if mx < d[nA][nB][iV] {
			mx = d[nA][nB][iV]
			cans = iV
		}
	}

	if mx == 0 {
		printer.PrintInt(0)
	} else {
		iA, iB, iV := nA, nB, cans
		ans := []rune{}

		for iA > 0 && iB > 0 {
			if c[iA][iB][iV] == -1 {
				iA--
			} else if c[iA][iB][iV] == -2 {
				iB--
			} else {
				ans = append(ans, rune(A[iA-1]))
				iV = c[iA][iB][iV]
				iA--
				iB--
			}
		}

		for i := len(ans) - 1; i >= 0; i-- {
			printer.PrintString(string(ans[i]))
		}
	}
}

func main() {
	// Assuming USEFILE, TESTCASE, SPLITCASE, PRINTCASE are defined elsewhere
	prep()
	if TESTCASE {
		testNum := scanner.ScanInt()
		for testCount := 1; testCount <= testNum; testCount++ {
			if SPLITCASE {
				fmt.Printf("\n>>>>> Test %d <<<<<\n", testCount)
			}
			if PRINTCASE {
				fmt.Printf("Case ")
			}
			solve()
		}
	} else {
		solve()
	}
}

func prep() {
	// Preparation logic here
}
