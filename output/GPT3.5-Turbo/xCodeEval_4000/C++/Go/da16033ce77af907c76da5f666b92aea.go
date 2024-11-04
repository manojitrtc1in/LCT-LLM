package main

import (
	"fmt"
	"sort"
)

var (
	mainArray [][]int
	dpTable   [][]int
)

func functionName() {
	var arrayNumber, operationNumber int
	fmt.Scanf("%d %d", &arrayNumber, &operationNumber)

	reversedArray := make([][]int, operationNumber)
	for i := 0; i < operationNumber; i++ {
		reversedArray[i] = make([]int, arrayNumber)
	}

	mainArray = make([][]int, arrayNumber)
	for i := 0; i < arrayNumber; i++ {
		mainArray[i] = make([]int, operationNumber)
	}

	maximum := 0
	dpTable = make([][]int, arrayNumber)
	for i := 0; i < arrayNumber; i++ {
		dpTable[i] = make([]int, operationNumber+1)
		for j := 0; j <= operationNumber; j++ {
			dpTable[i][j] = maximum
		}
	}

	for i := 0; i < arrayNumber; i++ {
		var elementNumber int
		fmt.Scanf("%d", &elementNumber)
		for j := 0; j < elementNumber; j++ {
			var element int
			fmt.Scanf("%d", &element)
			if j < operationNumber {
				mainArray[i][j] = element + mainArray[i][j-1]
				reversedArray[j][i] = mainArray[i][j]
			}
		}
	}

	for i := 0; i < operationNumber; i++ {
		sort.Sort(sort.Reverse(sort.IntSlice(reversedArray[i])))
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
	fmt.Printf("%d\n", answer)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	functionName()
}
