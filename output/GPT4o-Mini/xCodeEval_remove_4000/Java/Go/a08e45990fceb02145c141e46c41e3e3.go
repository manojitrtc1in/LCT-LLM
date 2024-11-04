package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

type Event struct {
	enter bool
	index int
}

func main() {
	r := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n, m := readInt(r), readInt(r)

	id33 := make([]bool, n)
	for i := range id33 {
		id33[i] = true
	}

	inputEvents := make([]Event, m)
	for i := 0; i < m; i++ {
		eventType := readString(r)
		index := readInt(r) - 1
		inputEvents[i] = Event{enter: eventType == "+", index: index}
	}

	wasBefore := make(map[int]struct{})
	used := make([]bool, n)

	for _, inputEvent := range inputEvents {
		if !inputEvent.enter && !used[inputEvent.index] {
			wasBefore[inputEvent.index] = struct{}{}
		}
		used[inputEvent.index] = true
	}

	zeros := make([]int, 0)
	meetingSize := len(wasBefore)

	for _, event := range inputEvents {
		if event.enter {
			if meetingSize != 0 {
				id33[event.index] = false
			} else {
				zeros = append(zeros, event.index)
			}
			meetingSize++
		} else {
			meetingSize--
			if meetingSize != 0 {
				id33[event.index] = false
			} else {
				zeros = append(zeros, event.index)
			}
		}
	}

	if len(zeros) > 1 {
		for _, index := range zeros {
			id33[index] = false
		}
	} else if len(zeros) == 1 {
		zeroEnter := zeros[0]
		if len(wasBefore) > 0 {
			if _, exists := wasBefore[zeroEnter]; !exists {
				id33[zeroEnter] = false
			}
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
		fmt.Fprint(writer, leader+1, " ")
	}
	fmt.Fprintln(writer)
}

func readInt(r *bufio.Reader) int {
	var x int
	fmt.Fscan(r, &x)
	return x
}

func readString(r *bufio.Reader) string {
	s, _ := r.ReadString('\n')
	return strings.TrimSpace(s)
}
