package main

import (
	"fmt"
	"math"
	"strings"
)

type Scanner struct{}

func (s *Scanner) ScanString() string {
	var str string
	fmt.Scan(&str)
	return str
}

func (s *Scanner) ScanStrings() (string, string, string) {
	A := s.ScanString()
	B := s.ScanString()
	V := s.ScanString()
	return A, B, V
}

type Printer struct{}

func (p *Printer) Print(args ...interface{}) {
	fmt.Print(args...)
}

func (p *Printer) Println(args ...interface{}) {
	fmt.Println(args...)
}

var (
	nA, nB, nV, mx, cans int
	d                   [101][101][101]int
	prefix              [101][1001]int
	c                   [101][101][101]int
	A, B, V            string
	ans                []rune
)

func maxSet(lhs, rhs *int) bool {
	if *lhs < rhs {
		*lhs = rhs
		return true
	}
	return false
}

func solve() {
	scanner := &Scanner{}
	printer := &Printer{}

	A, B, V = scanner.ScanStrings()
	nA = len(A)
	nB = len(B)
	nV = len(V)
	A = "#" + A + "#"
	B = "#" + B + "#"
	V = "#" + V + "#"

	for iV := 0; iV < nV; iV++ {
		for C := 'A'; C <= 'Z'; C++ {
			prefix[iV][C] = iV + 1
			for prefix[iV][C] > 0 {
				if V[1:prefix[iV][C]] == V[iV+2-prefix[iV][C]:prefix[iV][C]-1]+string(C) {
					break
				}
				prefix[iV][C]--
			}
		}
	}

	for iA := 1; iA <= nA; iA++ {
		for iB := 1; iB <= nB; iB++ {
			for iV := 0; iV < nV; iV++ {
				d[iA][iB][iV] = -1
				if maxSet(&d[iA][iB][iV], &d[iA-1][iB][iV]) {
					c[iA][iB][iV] = -1
				}
				if maxSet(&d[iA][iB][iV], &d[iA][iB-1][iV]) {
					c[iA][iB][iV] = -2
				}
			}
			for iV := 0; iV < nV; iV++ {
				if A[iA] == B[iB] {
					maxSet(&d[iA][iB][prefix[iV][A[iA]]], d[iA-1][iB-1][iV]+1) {
						c[iA][iB][prefix[iV][A[iA]]] = iV
					}
				}
			}
		}
	}

	for iV := 0; iV < nV; iV++ {
		maxSet(&mx, d[nA][nB][iV]) {
			cans = iV
		}
	}

	if mx == 0 {
		printer.Println(0)
	} else {
		iA, iB, iV := nA, nB, cans
		for iA > 0 && iB > 0 {
			if c[iA][iB][iV] == -1 {
				iA--
			} else if c[iA][iB][iV] == -2 {
				iB--
			} else {
				ans = append(ans, A[iA])
				iV = c[iA][iB][iV]
				iA--
				iB--
			}
		}
		for i := len(ans) - 1; i >= 0; i-- {
			printer.Print(string(ans[i]))
		}
	}
}

func main() {
	solve()
}
