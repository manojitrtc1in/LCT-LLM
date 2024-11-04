package main

import (
	"fmt"
	"math"
	"math/rand"
	"strconv"
	"strings"
	"time"
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v []int) String() string {
	str := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			str += ", "
		}
		str += strconv.Itoa(v[i])
	}
	return str + "]"
}

var rnd = rand.New(rand.NewSource(time.Now().Unix()))

const INF = int(1e9)
const INF64 = int64(1e18)
const MOD = int(1e9) + 7
const EPS = 1e-9
const PI = math.Acos(-1.0)

const N = 1000 + 7

var n int
var s string

func read() bool {
	var buf string
	_, err := fmt.Scan(&buf)
	if err != nil {
		return false
	}
	s = buf
	s = s[4:]
	n = len(s)
	return true
}

var lim = []int64{0, 9, 99, 99, 3099, 13099, 113099, 1113099, 11113099, 111113099}
var pr1 = []string{"", "198", "19", "2", "", "", "", "", "", ""}
var pr2 = []string{"", "199", "20", "3", "1", "1", "1", "1", "1", "1"}

func solve() string {
	x, _ := strconv.ParseInt(s, 10, 64)
	if x >= lim[n] {
		return pr1[n] + s
	} else {
		return pr2[n] + s
	}
}

func main() {
	rand.Seed(time.Now().Unix())

	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		read()

		for read() {
			fmt.Println(solve())
		}

		tc--
	}
}
