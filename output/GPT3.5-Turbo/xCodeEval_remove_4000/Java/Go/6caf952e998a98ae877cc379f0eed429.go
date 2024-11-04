package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Line struct {
	a, b, c float64
}

type Segment struct {
	a, b Point
}

type Circle struct {
	center Point
	radius float64
}

type Vector struct {
	x, y float64
}

type Polygon struct {
	vertices []Point
}

type BooleanMatrix struct {
	data        [][]bool
	rowCount    int
	columnCount int
}

type Heap struct {
	comparator func(int, int) int
	size       int
	elements   []int
	at         []int
}

type Pair struct {
	first  int
	second int
}

type InputReader struct {
}

type OutputWriter struct {
}

type Task interface {
	solve(testNumber int, in *InputReader, out *OutputWriter)
}

type A struct {
}

func (task *A) solve(testNumber int, in *InputReader, out *OutputWriter) {
	str := in.next()
	ret := 0
	n := len(str)
	c := 0
	for i := 1; i < n; i++ {
		if str[i] != str[i-1] {
			ret += c % 2
			c = 0
		} else {
			c++
		}
	}
	ret += c % 2
	out.printLine(ret)
}

type B struct {
}

func (task *B) solve(testNumber int, in *InputReader, out *OutputWriter) {
	str := in.next()
	ret := ""
	for i := 0; i < len(str); i++ {
		c := str[i]
		if c == '>' {
			ret += "1000"
		} else if c == '<' {
			ret += "1001"
		} else if c == '+' {
			ret += "1010"
		} else if c == '-' {
			ret += "1011"
		} else if c == '.' {
			ret += "1100"
		} else if c == ',' {
			ret += "1101"
		} else if c == '[' {
			ret += "1110"
		} else {
			ret += "1111"
		}
	}
	n := 0
	for i := 0; i < len(ret); i++ {
		n = (2*n + int(ret[i]) - '0') % 1000003
	}
	out.printLine(n)
}

type C struct {
}

func (task *C) solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type D struct {
}

func (task *D) solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type E struct {
}

func (task *E) solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type F struct {
}

func (task *F) solve(testNumber int, in *InputReader, out *OutputWriter) {

}

func main() {
	inputReader := &InputReader{}
	outputWriter := &OutputWriter{}
	inputStream := inputReader
	outputStream := outputWriter
	in := inputReader
	out := outputWriter
	task := &A{}
	task.solve(1, in, out)
	out.close()
}

func (in *InputReader) read() int {
	return 0
}

func (in *InputReader) peek() int {
	return 0
}

func (in *InputReader) readInt() int {
	return 0
}

func (in *InputReader) readLong() int64 {
	return 0
}

func (in *InputReader) readString() string {
	return ""
}

func (in *InputReader) readCharacter() byte {
	return 0
}

func (in *InputReader) readDouble() float64 {
	return 0
}

func (in *InputReader) id10() bool {
	return false
}

func (in *InputReader) next() string {
	return ""
}

func (out *OutputWriter) print(args ...interface{}) {
	fmt.Print(args...)
}

func (out *OutputWriter) println(args ...interface{}) {
	fmt.Println(args...)
}

func (out *OutputWriter) printf(format string, args ...interface{}) {
	fmt.Printf(format, args...)
}

func (out *OutputWriter) close() {

}

func (out *OutputWriter) flush() {

}

func (out *OutputWriter) printLine(args ...interface{}) {
	fmt.Println(args...)
}

func (out *OutputWriter) printFormat(format string, args ...interface{}) {
	fmt.Printf(format, args...)
}

func (out *OutputWriter) printLinef(format string, args ...interface{}) {
	fmt.Printf(format, args...)
}

func (out *OutputWriter) printLineInts(args []int) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineLongs(args []int64) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineDoubles(args []float64) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineStrings(args []string) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineChars(args []byte) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineBytes(args []byte) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineBools(args []bool) {
	for i := 0; i < len(args); i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(args[i])
	}
	fmt.Println()
}

func (out *OutputWriter) printLineInts2D(args [][]int) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineLongs2D(args [][]int64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineDoubles2D(args [][]float64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineStrings2D(args [][]string) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineChars2D(args [][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineBytes2D(args [][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineBools2D(args [][]bool) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			if j != 0 {
				fmt.Print(" ")
			}
			fmt.Print(args[i][j])
		}
		fmt.Println()
	}
}

func (out *OutputWriter) printLineInts3D(args [][][]int) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineLongs3D(args [][][]int64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineDoubles3D(args [][][]float64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineStrings3D(args [][][]string) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineChars3D(args [][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineBytes3D(args [][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineBools3D(args [][][]bool) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				if k != 0 {
					fmt.Print(" ")
				}
				fmt.Print(args[i][j][k])
			}
			fmt.Println()
		}
	}
}

func (out *OutputWriter) printLineInts4D(args [][][][]int) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineLongs4D(args [][][][]int64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineDoubles4D(args [][][][]float64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineStrings4D(args [][][][]string) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineChars4D(args [][][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineBytes4D(args [][][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineBools4D(args [][][][]bool) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					if l != 0 {
						fmt.Print(" ")
					}
					fmt.Print(args[i][j][k][l])
				}
				fmt.Println()
			}
		}
	}
}

func (out *OutputWriter) printLineInts5D(args [][][][][]int) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineLongs5D(args [][][][][]int64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineDoubles5D(args [][][][][]float64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineStrings5D(args [][][][][]string) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineChars5D(args [][][][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineBytes5D(args [][][][][]byte) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineBools5D(args [][][][][]bool) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						if m != 0 {
							fmt.Print(" ")
						}
						fmt.Print(args[i][j][k][l][m])
					}
					fmt.Println()
				}
			}
		}
	}
}

func (out *OutputWriter) printLineInts6D(args [][][][][][]int) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						for n := 0; n < len(args[i][j][k][l][m]); n++ {
							if n != 0 {
								fmt.Print(" ")
							}
							fmt.Print(args[i][j][k][l][m][n])
						}
						fmt.Println()
					}
				}
			}
		}
	}
}

func (out *OutputWriter) printLineLongs6D(args [][][][][][]int64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
			for k := 0; k < len(args[i][j]); k++ {
				for l := 0; l < len(args[i][j][k]); l++ {
					for m := 0; m < len(args[i][j][k][l]); m++ {
						for n := 0; n < len(args[i][j][k][l][m]); n++ {
							if n != 0 {
								fmt.Print(" ")
							}
							fmt.Print(args[i][j][k][l][m][n])
						}
						fmt.Println()
					}
				}
			}
		}
	}
}

func (out *OutputWriter) printLineDoubles6D(args [][][][][][]float64) {
	for i := 0; i < len(args); i++ {
		for j := 0; j < len(args[i]); j++ {
