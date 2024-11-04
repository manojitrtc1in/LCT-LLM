package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Event struct {
	enter bool
	index int
}

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n, m int
	fmt.Fscan(r, &n, &m)

	canBeLeader := make([]bool, n)
	for i := range canBeLeader {
		canBeLeader[i] = true
	}

	inputEvents := make([]Event, m)
	for i := 0; i < m; i++ {
		var eventType string
		var index int
		fmt.Fscan(r, &eventType, &index)
		inputEvents[i] = Event{enter: eventType == "+", index: index - 1}
	}

	startMeetingSize := 0
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
				canBeLeader[event.index] = false
			} else {
				zeros = append(zeros, event.index)
			}
			meetingSize++
		} else {
			meetingSize--
			if meetingSize != 0 {
				canBeLeader[event.index] = false
			} else {
				zeros = append(zeros, event.index)
			}
		}
	}

	if len(zeros) > 1 {
		for _, index := range zeros {
			canBeLeader[index] = false
		}
	} else if len(zeros) == 1 {
		zeroEnter := zeros[0]
		if len(wasBefore) > 0 {
			if _, exists := wasBefore[zeroEnter]; !exists {
				canBeLeader[zeroEnter] = false
			}
		}
	}

	possibleLeaders := make([]int, 0)
	for i := 0; i < n; i++ {
		if canBeLeader[i] {
			possibleLeaders = append(possibleLeaders, i)
		}
	}

	fmt.Fprintln(w, len(possibleLeaders))
	for _, leader := range possibleLeaders {
		fmt.Fprint(w, leader+1, " ")
	}
	fmt.Fprintln(w)
}
