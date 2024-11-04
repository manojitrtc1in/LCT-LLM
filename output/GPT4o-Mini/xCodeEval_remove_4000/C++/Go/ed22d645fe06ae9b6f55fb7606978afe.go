package main

import (
    "fmt"
    "os"
    "strings"
)

const N = int(1e2) + 9

var a, c [N]rune
var t [N]int
var tt [N][2]int
var b, d int

func main() {
    file, err := os.Open("in.txt")
    if err != nil {
        panic(err)
    }
    defer file.Close()

    fmt.Fscanf(file, "%d %d\n", &b, &d)
    fmt.Fscanf(file, "%s %s\n", &a, &c)

    an := len(a)
    cn := len(c)

    for i := 0; i < cn; i++ {
        k := &t[i]
        for j := 0; j < an; j++ {
            if a[j] == c[(i+*k)%cn] {
                (*k)++
            }
        }
    }

    for i := 0; i < N; i++ {
        tt[i][0] = -1
    }

    s := 0
    bj := false

    for i := 0; i < b; i++ {
        s += t[s%cn]

        if bj {
            continue
        }

        if tt[s%cn][0] == -1 {
            tt[s%cn][0] = i
            tt[s%cn][1] = s
        } else {
            r := i - tt[s%cn][0]
            s += (s - tt[s%cn][1]) * ((b - i) / r)
            i += ((b - i) / r) * r
            bj = true
        }
    }
    s /= cn * d
    fmt.Println(s)
}
