package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve()
}

func solve() {
	n, m := readInt(), readInt()

	id33 := make([]bool, n)
	for i := 0; i < n; i++ {
		id33[i] = true
	}

	type Event struct {
		enter bool
		index int
	}

	inputEvents := make([]Event, m)
	for i := 0; i < m; i++ {
		eventType := readString()
		index := readInt() - 1
		inputEvents[i] = Event{enter: eventType == "+", index: index}
	}

	id16 := 0

	wasBefore := make(map[int]bool)

	used := make([]bool, n)
	for _, inputEvent := range inputEvents {
		if !inputEvent.enter && !used[inputEvent.index] {
			wasBefore[inputEvent.index] = true
		}

		used[inputEvent.index] = true
	}

	zeros := make(map[int]bool)

	meetingSize := len(wasBefore)
	for _, event := range inputEvents {
		if event.enter {
			if meetingSize != 0 {
				id33[event.index] = false
			} else {
				zeros[event.index] = true
			}

			meetingSize++
		} else {
			meetingSize--

			if meetingSize != 0 {
				id33[event.index] = false
			} else {
				zeros[event.index] = true
			}
		}
	}

	if len(zeros) > 1 {
		for index := range zeros {
			id33[index] = false
		}
	} else if len(zeros) == 1 {
		var zeroEnter int
		for index := range zeros {
			zeroEnter = index
		}

		if len(wasBefore) > 0 && !wasBefore[zeroEnter] {
			id33[zeroEnter] = false
		}
	}

	id14 := make([]int, 0)
	for i := 0; i < n; i++ {
		if id33[i] {
			id14 = append(id14, i)
		}
	}

	fmt.Fprintln(writer, len(id14))
	for _, leader := range id14 {
		fmt.Fprintf(writer, "%d ", leader+1)
	}
	fmt.Fprintln(writer)
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	val, _ := strconv.Atoi(readString())
	return val
}
