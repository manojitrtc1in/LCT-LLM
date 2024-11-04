package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const EPS = 1e-7

type Point2D struct {
	x, y float64
}

func (p *Point2D) set(x, y float64) *Point2D {
	p.x = x
	p.y = y
	return p
}

func (p Point2D) add(v Point2D) Point2D {
	return Point2D{p.x + v.x, p.y + v.y}
}

func (p Point2D) sub(v Point2D) Point2D {
	return Point2D{p.x - v.x, p.y - v.y}
}

func (p Point2D) len() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point2D) normalize(newLen float64) Point2D {
	return p.mul(newLen / p.len())
}

func (p Point2D) mul(k float64) Point2D {
	return Point2D{k * p.x, k * p.y}
}

func (p Point2D) rotate(angle float64) Point2D {
	cos := math.Cos(angle)
	sin := math.Sin(angle)
	return Point2D{p.x*cos - p.y*sin, p.x*sin + p.y*cos}
}

type Circle2D struct {
	c Point2D
	r float64
}

func (c Circle2D) contains(p Point2D) bool {
	return c.c.sub(p).len() < c.r+EPS
}

func dist(p1, p2 Point2D) float64 {
	return p1.sub(p2).len()
}

func can(t float64, pp, ps Point2D, vP, vs float64, star Circle2D) bool {
	return dist(ps, pp.rotate(t*vP/pp.len())) < t*vs
}

func solve() {
	var xp, yp, vP, vs float64
	fmt.Scan(&xp, &yp, &vP, &vs)

	pp := Point2D{}.set(xp, yp)
	rP := pp.len()

	tvP := 1.0
	vP /= tvP
	vs /= tvP

	omegaP := vP / rP
	var star Circle2D
	var radius float64
	fmt.Scan(&radius)
	star = Circle2D{Point2D{0.0, 0.0}, radius}

	ans := 3e6
	left, right := 0.0, ans

	for it := 0; it < 10000; it++ {
		mid := 0.5 * (left + right)
		if can(mid, pp, ps, vP, vs, star) {
			right = mid
			ans = math.Min(ans, mid)
		} else {
			left = mid
		}
	}

	fmt.Println(ans / tvP)
}

func main() {
	if _, err := os.Stat("input.txt"); err == nil {
		file, _ := os.Open("input.txt")
		defer file.Close()
		reader := strings.NewReader("")
		scanner := bufio.NewScanner(file)
		for scanner.Scan() {
			reader.WriteString(scanner.Text() + "\n")
		}
	}

	solve()
}
