





#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <utility>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>


#define debug(x) std::cout <<  #x  << ": " << x << std::endl






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

































template<typename T>
std::ostream& operator<<(std::ostream& str, const std::vector<T>& v) { str << "["; for(auto n : v) str << n << ", "; str << "]"; return str; }











enum class mark { UNMARKED, MARKED, PRIME };
typedef long cell;
matrix<mark> hungarian_minimum_match(matrix<cell> table);
matrix<mark> hungarian_maximum_match(matrix<cell> table);



void hungarian_add_and_subtract(matrix<cell>& t, const std::vector<bool>& rowCovered, const std::vector<bool>& colCovered);
std::pair<int,int> hungarian_find_prime(matrix<cell>& t, matrix<mark>& marks, std::vector<bool>& rowCovered, std::vector<bool>& colCovered);
void hungarian_alt_marks(matrix<mark>& marks, std::vector<size_t>& altRow, std::vector<size_t>& altCol, std::vector<ssize_t>& colMarks, std::vector<ssize_t>& rowPrimes, std::pair<size_t,size_t> prime);

size_t lb(int64_t x) __attribute__((const));

const char keys[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";


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
        if (assignment.at(i,j) == mark::MARKED) {
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
    for (auto& x : table)
        x = -x;

    return hungarian_minimum_match(std::move(table));
}

matrix<mark> hungarian_minimum_match(matrix<cell> table)
{
    size_t n = table.n;
    size_t m = table.m;

    

    matrix<mark> marks(n, m, mark::UNMARKED);

    

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
                marks.at(i,j) = mark::MARKED;
                rowCovered[i] = true;
                colCovered[j] = true;
            }
        }
    }
    
    std::vector<size_t> altRow(n*m);
    std::vector<size_t> altCol(n*m);

    std::vector<ssize_t> rowPrimes(n);
    std::vector<ssize_t> colMarks(m);
    
    for (;;) {
        

        std::vector<bool> covered(marks.m, false);
        for (size_t j=0; j<marks.m; ++j) for (size_t i=0; i<marks.n; ++i) {
            if (marks.at(i,j) == mark::MARKED) {
                covered.at(j) = true;
                break;
            }
        }

        

        size_t count = std::count(covered.begin(), covered.end(), true);
        if (count == n)
            break;

        std::vector<bool> rowCovered(n, false);
        for (;;)
        {
            auto prime = hungarian_find_prime(table, marks, rowCovered, covered);

            if (prime.first >= 0) {
                hungarian_alt_marks(marks, altRow, altCol, colMarks, rowPrimes, prime);
                break;
            }

            hungarian_add_and_subtract(table, rowCovered, covered);
        }
    }

    return marks;
}

std::pair<int, int> hungarian_find_prime(matrix<cell>& t, matrix<mark>& marks, std::vector<bool>& rowCovered, std::vector<bool>& colCovered)
{
    size_t n = t.n;
    size_t m = t.m;
    

    std::set<int> zeroes; 
    
    for (size_t i = 0; i < n; i++)
        if (!rowCovered[i])
            for (size_t j = 0; j < m; j++)
                if (!colCovered[j] && t.at(i,j) == 0)
                  

                  zeroes.insert(i * m + j);
    
    for (;;)
    {
        

        

        

        

        if (zeroes.empty()) {
            return std::pair<int,int>(-1,-1);
        }

        ssize_t p = *zeroes.begin();
        
        size_t row = (size_t)p / m;
        size_t col = (size_t)p % m;
        
        marks.at(row, col) = mark::PRIME;
        
        auto mk = std::find(marks.row(row), marks.row_end(row), mark::MARKED);
        
        if (mk != marks.row_end(row))
        {
            col = std::distance(marks.row(row), mk);

            rowCovered[row] = true;
            colCovered[col] = false;
            
            for (size_t i = 0; i < n; i++)
                if ((t.at(i,col) == 0) && (row != i))
                {
                    if (!rowCovered[i] && !colCovered[col])
                        

                        zeroes.insert(i * m + col);
                    else
                        

                        zeroes.erase(i * m + col);
                }
            
            for (size_t j = 0; j < m; j++)
                if ((t.at(row,j) == 0) && (col != j))
                {
                    if (!rowCovered[row] && !colCovered[j])
                        

                        zeroes.insert(row * m + j);
                    else
                        

                        zeroes.erase(row * m + j);
                }
            
            if (!rowCovered[row] && !colCovered[col])
                

                zeroes.insert(row * m + col);
            else
                

                zeroes.erase(row * m + col);
        }
        else
        {
            return std::pair<int,int>(row,col);
        }
    }
}



void hungarian_alt_marks(
    matrix<mark>& marks,
    std::vector<size_t>& altRow,
    std::vector<size_t>& altCol,
    std::vector<ssize_t>& colMarks,
    std::vector<ssize_t>& rowPrimes,
    std::pair<size_t,size_t> prime)
{
    size_t n = marks.n;
    size_t m = marks.m;
    altRow[0] = prime.first;
    altCol[0] = prime.second;
        
    rowPrimes.assign(n, -1);
    colMarks.assign(m, -1);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (marks.at(i,j) == mark::MARKED) {
                colMarks[j] = (ssize_t)i;
            } else if (marks.at(i, j) == mark::PRIME) {
                rowPrimes[i] = (ssize_t)j;
            }
        }
    }
    
    size_t index = 0;
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
        if (markx == mark::MARKED)
            markx = mark::UNMARKED;
        else
            markx = mark::MARKED;
    }
    
    std::replace(marks.begin(), marks.end(),
        mark::PRIME,
        mark::UNMARKED);
}



void hungarian_add_and_subtract(matrix<cell>& t, const std::vector<bool>& rowCovered, const std::vector<bool>& colCovered)
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

























    


    



























    


    































    















    












    



