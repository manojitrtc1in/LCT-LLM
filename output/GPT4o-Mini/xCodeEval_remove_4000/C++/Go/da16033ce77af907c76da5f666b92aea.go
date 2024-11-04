package main

import (
	"fmt"
	"math"
	"sort"
)

type ll int64

var pi = 2 * math.Acos(0.0)

var id1, testCase = 0, 1

var mainArray [][]ll
var dpTable [][]ll

func functionName() {
	var arrayNumber, operationNumber int
	fmt.Scanf("%d %d", &arrayNumber, &operationNumber)

	id3 := make([][]ll, operationNumber)
	for i := range id3 {
		id3[i] = make([]ll, arrayNumber)
	}

	mainArray = make([][]ll, arrayNumber)
	for i := range mainArray {
		mainArray[i] = make([]ll, operationNumber)
	}

	maximum := ll(0)
	dpTable = make([][]ll, arrayNumber)
	for i := range dpTable {
		dpTable[i] = make([]ll, operationNumber+1)
		for j := range dpTable[i] {
			dpTable[i][j] = maximum
		}
	}

	for i := 0; i < arrayNumber; i++ {
		var elementNumber int
		fmt.Scanf("%d", &elementNumber)
		for j := 0; j < elementNumber; j++ {
			var element ll
			fmt.Scanf("%d", &element)
			if j < operationNumber {
				if j > 0 {
					mainArray[i][j] = element + mainArray[i][j-1]
				} else {
					mainArray[i][j] = element
				}
				id3[j][i] = mainArray[i][j]
			}
		}
	}

	for i := 0; i < operationNumber; i++ {
		sort.Slice(id3[i], func(a, b int) bool {
			return id3[i][a] > id3[i][b]
		})
	}

	for i := 0; i < arrayNumber; i++ {
		for j := 0; j < operationNumber; j++ {
			if mainArray[i][j] < id3[j][min(operationNumber/(j+1), arrayNumber-1)] {
				mainArray[i][j] = 0
			}
		}
	}

	for id0 := 0; id0 < arrayNumber; id0++ {
		if id0 > 0 {
			dpTable[id0] = dpTable[id0-1]
		}

		for id2 := 0; id2 < operationNumber; id2++ {
			if mainArray[id0][id2] != 0 {
				for operationLeft, old := operationNumber, operationNumber-(id2+1); operationLeft > id2; operationLeft, old = operationLeft-1, old-1 {
					if id0 == 0 {
						dpTable[id0][operationLeft] = max(dpTable[id0][operationLeft], mainArray[id0][id2])
					} else {
						dpTable[id0][operationLeft] = max(dpTable[id0][operationLeft], mainArray[id0][id2]+dpTable[id0-1][old])
					}
				}
			}
		}
	}

	answer := dpTable[arrayNumber-1][operationNumber]
	fmt.Println(answer)
}

func functionNameWithParams(v1, v2, v3 int) {}

func functionNameWithString(line string) {}

type initialWorks struct{}

func (iw *initialWorks) withTestCaseNumber() {
	fmt.Scanf("%d", &id1)

	for testCase <= id1 {
		functionName()
		testCase++
	}
}

func (iw *initialWorks) singleIteration() {
	functionName()
}

func (iw *initialWorks) withoutTestCaseNumber() {
	var v1, v2, v3 int
	for fmt.Scanf("%d %d %d", &v1, &v2, &v3) == 3 && v1 != 0 {
		functionNameWithParams(v1, v2, v3)
		testCase++
	}
}

func (iw *initialWorks) eoof() {
	var id4 string
	for {
		if _, err := fmt.Scanf("%[^\n]", &id4); err != nil {
			break
		}
		fmt.Scanf("%*c") // consume newline

		functionNameWithString(id4)
		testCase++
	}
}

func main() {
	var a initialWorks
	a.singleIteration()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b ll) ll {
	if a > b {
		return a
	}
	return b
}
