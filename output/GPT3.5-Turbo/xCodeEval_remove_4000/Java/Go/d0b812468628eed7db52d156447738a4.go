package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type id7 struct {
	r *bufio.Reader
}

func newId7() *id7 {
	return &id7{bufio.NewReader(os.Stdin)}
}

func (in *id7) nextLine() string {
	str, _ := in.r.ReadString('\n')
	return strings.TrimSuffix(str, "\n")
}

func (in *id7) next() string {
	str := in.nextLine()
	return strings.Fields(str)[0]
}

func (in *id7) nextInt() int {
	num, _ := strconv.Atoi(in.next())
	return num
}

func (in *id7) nextLong() int64 {
	num, _ := strconv.ParseInt(in.next(), 10, 64)
	return num
}

func bfs(w int64, n int) int {
	q := []int64{w}
	h := make(map[int64]int)
	h[w] = 0
	min := int(^uint(0) >> 1)
	for len(q) > 0 {
		s := q[0]
		q = q[1:]
		if n == len(strconv.FormatInt(s, 10)) {
			return h[s]
		}
		t := make(map[int]bool)
		e := strconv.FormatInt(s, 10)
		for i := 0; i < len(e); i++ {
			digit, _ := strconv.Atoi(string(e[i]))
			t[digit] = true
		}
		for x := range t {
			v := int64(x) * s
			if len(strconv.FormatInt(v, 10)) > n {
				continue
			}
			if _, ok := h[v]; !ok {
				h[v] = h[s] + 1
				q = append(q, v)
			}
		}
	}
	if min == int(^uint(0)>>1) {
		return -1
	}
	return min
}

func main() {
	input := newId7()
	n := input.nextInt()
	w := input.nextLong()
	fmt.Println(bfs(w, n))
}
