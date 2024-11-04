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
	n := readInt()
	m := readInt()

	canBeLeader := make([]bool, n)
	for i := 0; i < n; i++ {
		canBeLeader[i] = true
	}

	type Event struct {
		enter bool
		index int
	}

	inputEvents := make([]Event, m)
	for i := 0; i < m; i++ {
		eventType := readString()
		index := readInt() - 1
		if eventType == "+" {
			inputEvents[i] = Event{enter: true, index: index}
		} else {
			inputEvents[i] = Event{enter: false, index: index}
		}
	}

	startMeetingSize := 0

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
				canBeLeader[event.index] = false
			} else {
				zeros[event.index] = true
			}

			meetingSize++
		} else {
			meetingSize--

			if meetingSize != 0 {
				canBeLeader[event.index] = false
			} else {
				zeros[event.index] = true
			}
		}
	}

	if len(zeros) > 1 {
		for index := range zeros {
			canBeLeader[index] = false
		}
	} else if len(zeros) == 1 {
		for zeroEnter := range zeros {
			if len(wasBefore) > 0 && !wasBefore[zeroEnter] {
				canBeLeader[zeroEnter] = false
			}
		}
	}

	possibleLeaders := []int{}
	for i := 0; i < n; i++ {
		if canBeLeader[i] {
			possibleLeaders = append(possibleLeaders, i)
		}
	}

	fmt.Fprintln(writer, len(possibleLeaders))
	for _, leader := range possibleLeaders {
		fmt.Fprintf(writer, "%d ", leader+1)
	}
	fmt.Fprintln(writer)
}

func readString() string {
	scanner.Scan()
	return scanner.Text()
}

func readInt() int {
	num, _ := strconv.Atoi(readString())
	return num
}
