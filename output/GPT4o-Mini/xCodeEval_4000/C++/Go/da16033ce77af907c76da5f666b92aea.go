package main

import (
	"fmt"
	"sort"
)

type InitialWorks struct{}

var (
	mainArray   [][]int64
	dpTable     [][]int64
	testCaseNum int
	testCase    = 1
)

func functionName() {
	var arrayNumber, operationNumber int
	fmt.Scan(&arrayNumber, &operationNumber)

	reversedArray := make([][]int64, operationNumber)
	for i := range reversedArray {
		reversedArray[i] = make([]int64, arrayNumber)
	}

	mainArray = make([][]int64, arrayNumber)
	for i := range mainArray {
		mainArray[i] = make([]int64, operationNumber)
	}

	maximum := int64(0)
	dpTable = make([][]int64, arrayNumber)
	for i := range dpTable {
		dpTable[i] = make([]int64, operationNumber+1)
		for j := range dpTable[i] {
			dpTable[i][j] = maximum
		}
	}

	for i := 0; i < arrayNumber; i++ {
		var elementNumber int
		fmt.Scan(&elementNumber)
		for j := 0; j < elementNumber; j++ {
			var element int64
			fmt.Scan(&element)
			if j < operationNumber {
				if j > 0 {
					mainArray[i][j] = element + mainArray[i][j-1]
				} else {
					mainArray[i][j] = element
				}
				reversedArray[j][i] = mainArray[i][j]
			}
		}
	}

	for i := 0; i < operationNumber; i++ {
		sort.Slice(reversedArray[i], func(a, b int) bool {
			return reversedArray[i][a] > reversedArray[i][b]
		})
	}

	for i := 0; i < arrayNumber; i++ {
		for j := 0; j < operationNumber; j++ {
			if mainArray[i][j] < reversedArray[j][min(operationNumber/(j+1), arrayNumber-1)] {
				mainArray[i][j] = 0
			}
		}
	}

	for currentArrayNo := 0; currentArrayNo < arrayNumber; currentArrayNo++ {
		if currentArrayNo > 0 {
			dpTable[currentArrayNo] = dpTable[currentArrayNo-1]
		}

		for currentColumnNo := 0; currentColumnNo < operationNumber; currentColumnNo++ {
			if mainArray[currentArrayNo][currentColumnNo] != 0 {
				for operationLeft, old := operationNumber, operationNumber-(currentColumnNo+1); operationLeft > currentColumnNo; operationLeft, old = operationLeft-1, old-1 {
					if currentArrayNo == 0 {
						dpTable[currentArrayNo][operationLeft] = max(dpTable[currentArrayNo][operationLeft], mainArray[currentArrayNo][currentColumnNo])
					} else {
						dpTable[currentArrayNo][operationLeft] = max(dpTable[currentArrayNo][operationLeft], mainArray[currentArrayNo][currentColumnNo]+dpTable[currentArrayNo-1][old])
					}
				}
			}
		}
	}

	answer := dpTable[arrayNumber-1][operationNumber]
	fmt.Println(answer)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func (iw *InitialWorks) SingleIteration() {
	functionName()
}

func main() {
	var iw InitialWorks
	iw.SingleIteration()
}
