package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Kattio struct {
	r *bufio.Reader
	w *bufio.Writer
}

func newKattio() *Kattio {
	return &Kattio{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}

func (io *Kattio) nextLine() string {
	str, _ := io.r.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func (io *Kattio) next() string {
	str, _ := io.r.ReadString(' ')
	return strings.TrimRight(str, " ")
}

func (io *Kattio) nextInt() int {
	str := io.next()
	num, _ := strconv.Atoi(str)
	return num
}

func (io *Kattio) nextLong() int64 {
	str := io.next()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func (io *Kattio) write(str string) {
	io.w.WriteString(str)
}

func (io *Kattio) flush() {
	io.w.Flush()
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
	io := newKattio()
	defer io.flush()

	n := io.nextInt()
	w := io.nextLong()
	io.write(strconv.Itoa(bfs(w, n)) + "\n")
}
