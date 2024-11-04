





#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <utility>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

typedef long cell;

#define debug(x) std::cout <<  #x  << ": " << x << std::endl




enum mark { UNMARKED, MARKED, PRIME };




template<typename cell>
struct matrix {
        matrix(size_t n, size_t m): n(n), m(m), data_(new cell[n*m]) {}
        matrix(size_t n, size_t m, cell init): n(n), m(m), data_(new cell[n*m]) {
            for (size_t i=0; i<n*m;++i) data_[i] = init;
        }
        ~matrix() { delete[] data_; }
        matrix(matrix&& other): n(0), m(0), data_(nullptr) { *this = std::move(other); }
        matrix& operator=(matrix&& other) { std::swap(n, other.n); std::swap(m, other.m); std::swap(data_, other.data_); }
        

        matrix(const matrix& other): n(other.n), m(other.m), data_(new cell[n*m]) {
            for (size_t i=0; i<n*m;++i) data_[i] = other.data_[i];
        };
        matrix& operator=(const matrix& other) = delete;

        cell& at(size_t row, size_t col) {
                assert(row < n && col < m);
                return data_[row*m + col];
        }

        const cell& at(size_t row, size_t col) const {
                assert(row < n && col < m);
                return data_[row*m + col];
        }

        cell* row(size_t row) {
            assert(row < n);
            return data_ + row*m;
        }

        cell* row_end(size_t row) {
            assert(row < n);
            return data_ + (row+1)*m;
        }

        cell* data() { return data_; }
        size_t size() { return n*m; }

        cell* begin() { return data_; }
        cell* end() { return data_ + n*m; }

        size_t n,m;
        cell *data_; 

};


struct BitSet
{
    BitSet(size_t size);
    void set(size_t i);
    void unset(size_t i);
    

    ssize_t any() const;



    size_t c;
    size_t first;
    std::vector<uint64_t> limbs;
    std::vector<size_t> prev;
    std::vector<size_t> next;
};


template<typename T>
std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }





void kuhn_reduceRows(matrix<cell>& t);
void kuhn_addAndSubtract(matrix<cell>& t, std::vector<bool>& rowCovered, std::vector<bool>& colCovered);
matrix<mark> kuhn_mark(matrix<cell>& t);
std::pair<size_t,size_t>* kuhn_findPrime(matrix<cell>& t, matrix<mark>& marks, std::vector<bool>& rowCovered, std::vector<bool>& colCovered);
void kuhn_altMarks(matrix<mark>& marks, std::vector<size_t>& altRow, std::vector<size_t>& altCol, std::vector<ssize_t>& colMarks, std::vector<ssize_t>& rowPrimes, std::pair<size_t,size_t> prime);
std::vector<bool> kuhn_check_columns(const matrix<mark>& marks);

size_t lb(int64_t x) __attribute__((const));

const char keys[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

matrix<mark> hungarian_minimum_match(matrix<cell> table);
matrix<mark> hungarian_maximum_match(matrix<cell> table);

int main(int argc, char** argv)
{
    int n,k;
    std::cin >> n >> k;

    matrix<cell> mat(k, k, 0);

    std::string sasha, correct;
    std::cin >> sasha >> correct;

    for (int i=0; i<n; ++i) {
        char s = sasha[i];
        char c = correct[i];

        if (s <= 'Z') s = s - 'A' + 26;
        else s -= 'a';

        if (c <= 'Z') c = c- 'A' + 26;
        else c -= 'a';

        mat.at(s,c) += 1;
    }

    auto assignment = hungarian_maximum_match(mat);

    std::vector<char> mapping;
    size_t result = 0;
    for (int i=0; i<k; ++i) for (int j=0; j<k; ++j) {
        if (assignment.at(i,j) == MARKED) {
            result += mat.at(i,j);
            mapping.push_back(keys[j]);
            continue;
        }
    }

    std::cout << result << "\n";
    for (auto c : mapping)
        std::cout << c;
    std::cout << std::endl;

    return 0;
}

matrix<mark> hungarian_maximum_match(matrix<cell> table)
{
    auto mx = *std::max_element(table.begin(), table.end());
    for (auto& x : table)
        x = mx - x; 


    return hungarian_minimum_match(std::move(table));
}


matrix<mark> hungarian_minimum_match(matrix<cell> table)
{
    size_t n = table.n;
    size_t m = table.m;

    

    matrix<mark> marks(n, m, UNMARKED);

    

    for (size_t i = 0; i < n; i++) {
        cell rowmin = *std::min_element(table.row(i), table.row_end(i));
        
        for (size_t j = 0; j < m; j++)
            table.at(i, j) -= rowmin;
    }

    { 

        std::vector<bool> rowCovered(n, false);
        std::vector<bool> colCovered(m, false);
        
        for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
            if (!rowCovered[i] && !colCovered[j] && table.at(i,j) == 0) {
                marks.at(i,j) = MARKED;
                rowCovered[i] = true;
                colCovered[j] = true;
            }
        }
    }
    
    std::vector<size_t> altRow(n*m);
    std::vector<size_t> altCol(n*m);

    std::vector<ssize_t> rowPrimes(n);
    std::vector<ssize_t> colMarks(m);
    
    for (;;)
    {
        std::vector<bool> covered = kuhn_check_columns(marks);

        

        size_t count = std::count(covered.begin(), covered.end(), true);
        if (count == n)
            break;

        std::vector<bool> rowCovered(n, false);
        for (;;)
        {
            std::pair<size_t,size_t>* prime = kuhn_findPrime(table, marks, rowCovered, covered);
            if (prime != nullptr)
            {
                kuhn_altMarks(marks, altRow, altCol, colMarks, rowPrimes, *prime);
   
                free(prime);
                break;
            }
            kuhn_addAndSubtract(table, rowCovered, covered);
        }
    }

    return marks;
    
    

}


std::vector<bool> kuhn_check_columns(const matrix<mark>& marks)
{
    std::vector<bool> covered(marks.m, false);
    for (size_t j=0; j<marks.m; ++j) for (size_t i=0; i<marks.n; ++i) {
        if (marks.at(i,j) == MARKED) {
            covered.at(j) = true;
            break;
        }
    }

    return covered;
}



std::pair<size_t,size_t>* kuhn_findPrime(matrix<cell>& t, matrix<mark>& marks, std::vector<bool>& rowCovered, std::vector<bool>& colCovered)
{
    size_t n = t.n;
    size_t m = t.m;
    BitSet zeroes(n * m);
    
    for (size_t i = 0; i < n; i++)
        if (!rowCovered[i])
            for (size_t j = 0; j < m; j++)
                if (!colCovered[j] && t.at(i,j) == 0)
                  zeroes.set(i * m + j);
    
    ssize_t p;
    bool markInRow;
    
    for (;;)
    {
        p = zeroes.any();
        if (p < 0) {
            return nullptr;
        }
        
        size_t row = (size_t)p / m;
        size_t col = (size_t)p % m;
        
        marks.at(row, col) = PRIME;
        
        markInRow = false;
        for (size_t j = 0; j < m; j++)
            if (marks.at(row, j) == MARKED)
            {
                markInRow = true;
                col = j;
            }
        
        if (markInRow)
        {
            rowCovered[row] = true;
            colCovered[col] = false;
            
            for (size_t i = 0; i < n; i++)
                if ((t.at(i,col) == 0) && (row != i))
                {
                    if (!rowCovered[i] && !colCovered[col])
                        zeroes.set(i * m + col);
                    else
                        zeroes.unset(i * m + col);
                }
            
            for (size_t j = 0; j < m; j++)
                if ((t.at(row,j) == 0) && (col != j))
                {
                    if (!rowCovered[row] && !colCovered[j])
                        zeroes.set(row * m + j);
                    else
                        zeroes.unset(row * m + j);
                }
            
            if (!rowCovered[row] && !colCovered[col])
                zeroes.set(row * m + col);
            else
                zeroes.unset(row * m + col);
        }
        else
        {
            return new std::pair<size_t,size_t>(row,col);
        }
    }
}



void kuhn_altMarks(
    matrix<mark>& marks,
    std::vector<size_t>& altRow,
    std::vector<size_t>& altCol,
    std::vector<ssize_t>& colMarks,
    std::vector<ssize_t>& rowPrimes,
    std::pair<size_t,size_t> prime)
{
    size_t index = 0;
    size_t n = marks.n;
    size_t m = marks.m;
    altRow[0] = prime.first;
    altCol[0] = prime.second;
        
    rowPrimes.assign(n, -1);
    colMarks.assign(m, -1);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (marks.at(i,j) == MARKED) {
                colMarks[j] = (ssize_t)i;
            } else if (marks.at(i, j) == PRIME) {
                rowPrimes[i] = (ssize_t)j;
            }
        }
    }
    
    for (;;)
    {
        ssize_t row = colMarks.at( altCol[index] );
        if (row < 0)
            break;
        
        index++;
        altRow.at(index) = (size_t)row;
        altCol.at(index) = altCol.at(index - 1);
        
        ssize_t col = rowPrimes.at( altRow[index] );
        
        index++;
        altRow.at(index) = altRow.at(index - 1);
        altCol.at(index) = (size_t)col;
    }
    
    for (size_t i = 0; i <= index; i++)
    {
        mark& markx = marks.at(altRow.at(i), altCol.at(i));
        if (markx == MARKED)
            markx = UNMARKED;
        else
            markx = MARKED;
    }
    
    mark* marksi;
    for (size_t i = 0; i < n; i++)
    {
        marksi = marks.row(i);
        for (size_t j = 0; j < m; j++)
            if (*(marksi + j) == PRIME)
                *(marksi + j) = UNMARKED;
    }
}



void kuhn_addAndSubtract(matrix<cell>& t, std::vector<bool>& rowCovered, std::vector<bool>& colCovered)
{
    size_t i, j;
    size_t n = t.n;
    size_t m = t.m;
    cell min = 0x7FFFffffL;
    for (i = 0; i < n; i++)
        if (!rowCovered[i])
            for (j = 0; j < m; j++)
                if (!colCovered[j] && (min > t.at(i,j)))
                    min = t.at(i,j);
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (rowCovered[i])
                t.at(i,j) += min;
            if (!colCovered[j])
                t.at(i,j) -= min;
        }
}


BitSet::BitSet(size_t size):
    c(size/64 + bool(size&63L)),
    limbs(c, 0),
    first(0),
    prev(c+1, 0),
    next(c+1, 0)
{}

void BitSet::set(size_t i)
{
    size_t j = i >> 6L;
    uint64_t old = limbs.at(j);
    
    limbs.at(j) |= 1ULL << (i & 63L);
    
    if ((!limbs.at(j)) ^ (!old))
    {
        j++;
        prev.at(first) = j;
        prev.at(j) = 0;
        next.at(j) = first;
        first = j;
    }
}

void BitSet::unset(size_t i)
{
    size_t j = i >> 6L;
    uint64_t old = limbs.at(j);
    
    limbs.at(j) &= ~(1ULL << (i & 63L));
    
    if ((!limbs.at(j)) ^ (!old))
    {
        j++;
        size_t p = prev.at(j);
        size_t n = next.at(j);
        prev.at(n) = p;
        next.at(p) = n;
        if (first == j)
            first = n;
    }
}

ssize_t BitSet::any() const
{
    if (first == 0L)
        return -1;
    
    size_t i = first - 1;
    return (ssize_t)(lb(limbs.at(i) & -limbs.at(i)) + (i << 6L));
}



size_t lb(int64_t value)
{
    size_t rc = 0;
    int64_t v = value;
    
    if (v & (int_fast64_t)0xFFFFFFFF00000000LL)  {  rc |= 32L;  v >>= 32LL;  }
    if (v & (int_fast64_t)0x00000000FFFF0000LL)  {  rc |= 16L;  v >>= 16LL;  }
    if (v & (int_fast64_t)0x000000000000FF00LL)  {  rc |=  8L;  v >>=  8LL;  }
    if (v & (int_fast64_t)0x00000000000000F0LL)  {  rc |=  4L;  v >>=  4LL;  }
    if (v & (int_fast64_t)0x000000000000000CLL)  {  rc |=  2L;  v >>=  2LL;  }
    if (v & (int_fast64_t)0x0000000000000002LL)     rc |=  1L;
    
    return rc;
}