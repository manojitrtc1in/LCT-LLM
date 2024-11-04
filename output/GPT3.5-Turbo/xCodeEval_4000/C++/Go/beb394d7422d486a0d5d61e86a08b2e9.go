package main

import (
	"fmt"
	"math"
	"sort"
)

type statistic struct {
	p   [2][2]inte
	l   int
	r   int
}

type col struct {
	i   int
	tp  int
	t1  int
	t2  int
}

type inte struct {
	v   int
}

func (a inte) wrapAround() {
	if a.v < 0 {
		a.v = (a.v % p + p) % p
	} else if a.v >= p {
		a.v %= p
	}
}

func (a inte) add(b inte) inte {
	c := inte{a.v + b.v}
	if c.v >= a.p {
		c.v -= a.p
	}
	return c
}

func (a inte) sub(b inte) inte {
	c := inte{a.v - b.v}
	if c.v < 0 {
		c.v += a.p
	}
	return c
}

func (a inte) mul(b inte) inte {
	c := inte{}
	if a.t == "int64" {
		c.v = (a.v * b.v - int64(float64(a.v*b.v)/float64(a.p))*a.p + a.p) % a.p
	} else if a.t == "int" {
		c.v = int(int64(a.v) * int64(b.v) % a.p)
	} else {
		c.v = a.v * b.v % a.p
	}
	return c
}

func (a inte) pow(b int) inte {
	r := inte{1}
	for b > 0 {
		if b&1 == 1 {
			r = r.mul(a)
		}
		a = a.mul(a)
		b >>= 1
	}
	return r
}

func (a inte) inverse() inte {
	assert(a.v != 0)
	if a.v < len(a.inverseCache) {
		return a.inverseCache[a.v]
	}
	return a.pow(a.p - 2)
}

func (a inte) inverseCached() inte {
	assert(a.v != 0)
	t := a.inverseCache
	for len(t) <= a.v {
		t = append(t, inte{-a.p / len(t)} * t[a.p % len(t)])
	}
	return t[a.v]
}

func (a inte) factorial() inte {
	assert(a.v >= 0)
	t := a.factorialCache
	for len(t) <= a.v {
		t = append(t, t[len(t)-1].mul(inte{len(t)}))
	}
	return t[a.v]
}

func (a inte) binaryCoefficient(b inte) inte {
	assert(a.v >= 0 && b.v >= 0)
	if a.v < b.v {
		return inte{}
	}
	return a.factorial().div(b.factorial()).div(a.sub(b).factorial())
}

func (a inte) div(b inte) inte {
	return a.mul(b.inverse())
}

func (a inte) addInt(b int) inte {
	return a.add(inte{b})
}

func (a inte) subInt(b int) inte {
	return a.sub(inte{b})
}

func (a inte) mulInt(b int) inte {
	return a.mul(inte{b})
}

func (a inte) divInt(b int) inte {
	return a.div(inte{b})
}

func (a inte) powInt(b int) inte {
	return a.pow(b)
}

func (a inte) wrapAroundInt() int {
	if a.v < 0 {
		return (a.v % p + p) % p
	} else if a.v >= p {
		return a.v % p
	}
	return a.v
}

func (a inte) String() string {
	return fmt.Sprintf("%d", a.v)
}

func (a *inte) Scanf(format string, args ...interface{}) (int, error) {
	return fmt.Scanf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Println(args ...interface{}) (int, error) {
	return fmt.Println(args...)
}

func (a *inte) Print(args ...interface{}) (int, error) {
	return fmt.Print(args...)
}

func (a *inte) Printlnf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format+"\n", args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Fprintf(w io.Writer, format string, args ...interface{}) (int, error) {
	return fmt.Fprintf(w, format, args...)
}

func (a *inte) Fscanf(r io.Reader, format string, args ...interface{}) (int, error) {
	return fmt.Fscanf(r, format, args...)
}

func (a *inte) Fprintf(w io.Writer, format string, args ...interface{}) (int, error) {
	return fmt.Fprintf(w, format, args...)
}

func (a *inte) Fscanf(r io.Reader, format string, args ...interface{}) (int, error) {
	return fmt.Fscanf(r, format, args...)
}

func (a *inte) Scanln(args ...interface{}) (int, error) {
	return fmt.Scanln(args...)
}

func (a *inte) Scanf(format string, args ...interface{}) (int, error) {
	return fmt.Scanf(format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Scanf(format string, args ...interface{}) (int, error) {
	return fmt.Scanf(format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanln(str string, args ...interface{}) (int, error) {
	return fmt.Sscanln(str, args...)
}

func (a *inte) Sscanln(str string, args ...interface{}) (int, error) {
	return fmt.Sscanln(str, args...)
}

func (a *inte) Sscanln(str string, args ...interface{}) (int, error) {
	return fmt.Sscanln(str, args...)
}

func (a *inte) Sscanln(str string, args ...interface{}) (int, error) {
	return fmt.Sscanln(str, args...)
}

func (a *inte) Sscan(str string, args ...interface{}) (int, error) {
	return fmt.Sscan(str, args...)
}

func (a *inte) Sscan(str string, args ...interface{}) (int, error) {
	return fmt.Sscan(str, args...)
}

func (a *inte) Sscan(str string, args ...interface{}) (int, error) {
	return fmt.Sscan(str, args...)
}

func (a *inte) Sscan(str string, args ...interface{}) (int, error) {
	return fmt.Sscan(str, args...)
}

func (a *inte) Sscanln(args ...interface{}) (int, error) {
	return fmt.Sscanln(args...)
}

func (a *inte) Sscanln(args ...interface{}) (int, error) {
	return fmt.Sscanln(args...)
}

func (a *inte) Sscanln(args ...interface{}) (int, error) {
	return fmt.Sscanln(args...)
}

func (a *inte) Sscanln(args ...interface{}) (int, error) {
	return fmt.Sscanln(args...)
}

func (a *inte) Sscan(args ...interface{}) (int, error) {
	return fmt.Sscan(args...)
}

func (a *inte) Sscan(args ...interface{}) (int, error) {
	return fmt.Sscan(args...)
}

func (a *inte) Sscan(args ...interface{}) (int, error) {
	return fmt.Sscan(args...)
}

func (a *inte) Sscan(args ...interface{}) (int, error) {
	return fmt.Sscan(args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Sscanf(str string, format string, args ...interface{}) (int, error) {
	return fmt.Sscanf(str, format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
	return fmt.Printf(format, args...)
}

func (a *inte) Printf(format string, args ...interface{}) (int, error) {
