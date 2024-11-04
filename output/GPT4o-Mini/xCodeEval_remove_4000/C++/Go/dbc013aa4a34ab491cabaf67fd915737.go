package main

import (
    "fmt"
    "math"
    "strings"
)

type Pair struct {
    first  string
    second string
}

func idiff(a, b string, k int) int {
    n := int(math.Min(float64(len(a)), float64(len(b)))) + 1
    for i := 0; i+1 < int(math.Min(float64(n), float64(k))); i++ {
        if a[i] != b[i] {
            return i
        }
    }
    return -1
}

func bigger(a, b *string, first string, length int) {
    if len(*a) < len(*b)+1 {
        k := idiff(first, *b, length)
        if len(*a) < len(*b) && k != -1 {
            *a, *b = *b, *a
        } else if len(*a) == len(*b) && k < idiff(first, *a, length) {
            *a, *b = *b, *a
        }
    }
}

func startswith(a, b string) bool {
    if len(a) < len(b) {
        return false
    }
    for i, j := 0, 0; i < len(a) && j < len(b); i, j = i+1, j+1 {
        if a[i] != b[j] {
            return false
        }
    }
    return true
}

func id28(i, j int, str []string, vir string, cache [][]map[int]Pair) Pair {
    if i == len(str[0]) || j == len(str[1]) {
        return Pair{"", ""}
    }

    if val, ok := cache[i][j]; ok {
        return val
    }

    if str[0][i] != str[1][j] {
        a := id28(i+1, j, str, vir, cache)
        b := id28(i, j+1, str, vir, cache)

        if len(a.first) < len(b.first) {
            a, b = b, a
        }

        bigger(&a.second, &b.first, a.first, len(vir))
        bigger(&a.second, &b.second, a.first, len(vir))

        return cache[i][j] = a
    } else {
        rest := id28(i+1, j+1, str, vir, cache)
        a := string(str[0][i]) + rest.first
        b := string(str[0][i]) + rest.second

        for _, iter := range rest.first {
            if startswith(a, vir) {
                a = string(str[0][i]) + string(iter)
            }
        }

        for _, iter := range rest.second {
            if startswith(b, vir) {
                b = string(str[0][i]) + string(iter)
            }
        }

        if startswith(a, vir) {
            a = ""
        }
        if startswith(b, vir) {
            b = ""
        }

        if len(rest.first) < len(a) {
            rest.first, a = a, rest.first
        }

        bigger(&rest.second, &a, rest.first, len(vir))

        if len(rest.first) < len(b) {
            rest.first, b = b, rest.first
        }

        bigger(&rest.second, &b, rest.first, len(vir))

        return cache[i][j] = rest
    }
}

func main() {
    var str [2]string
    var vir string
    fmt.Scan(&str[0], &str[1], &vir)

    cache := make([][]map[int]Pair, len(str[0]))
    for i := range cache {
        cache[i] = make([]map[int]Pair, len(str[1]))
        for j := range cache[i] {
            cache[i][j] = make(map[int]Pair)
        }
    }

    val := id28(0, 0, str[:], vir, cache)
    if val.first == "" {
        fmt.Println("0")
    } else {
        fmt.Println(val.first)
    }
}
