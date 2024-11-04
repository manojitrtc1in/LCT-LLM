package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

type Abra struct {
	br *bufio.Reader
	bw *bufio.Writer
}

func main() {
	abra := &Abra{}
	abra.run()
}

func (abra *Abra) init() {
	abra.br = bufio.NewReader(os.Stdin)
	abra.bw = bufio.NewWriter(os.Stdout)
}

func (abra *Abra) run() {
	abra.init()
	defer abra.bw.Flush()

	w := abra.nextInt()
	if w == 2 {
		fmt.Fprint(abra.bw, "NO")
		return
	}
	if w%2 == 0 {
		fmt.Fprint(abra.bw, "YES")
	} else {
		fmt.Fprint(abra.bw, "NO")
	}
}

func (abra *Abra) nextInt() int {
	line, _ := abra.br.ReadString('\n')
	num, _ := strconv.Atoi(line[:len(line)-1])
	return num
}
