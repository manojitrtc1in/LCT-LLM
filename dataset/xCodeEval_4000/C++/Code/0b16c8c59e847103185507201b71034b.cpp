#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

class HugeInt {
public:
    int sign;
    int size;
    int *V;

private:
    static const int BASE;
    static const int SCAN_POWER;
    static const char* PRINT_FORMAT;

    HugeInt unsignedAddition(const HugeInt& arg, int newSign) const {
        HugeInt answer;
        answer.alloc(max(this->size, arg.size) + 2);
        int i;
        int min = this->size < arg.size ? this->size : arg.size;
        for (i = 0; i <= min; ++i) {
            answer.V[i] = this->V[i] + arg.V[i];
        }
        for (; i <= this->size; ++i) {
            answer.V[i] = this->V[i];
        }
        for (; i <= arg.size; ++i) {
            answer.V[i] = arg.V[i];
        }
        answer.V[i] = 0;
        answer.size = i - 1;
        for (i = 0; i <= answer.size; ++i) {
            if (answer.V[i] >= BASE) {
                answer.V[i] -= BASE;
                ++answer.V[i + 1];
            }
        }
        if (answer.V[i] > 0) {
            ++answer.size;
        }
        answer.sign = newSign;
        return answer;
    }

    HugeInt unsignedSubtraction(const HugeInt& arg, int newSign) const {
        HugeInt answer;
        answer.alloc(max(this->size, arg.size) + 2);
        int i;
        int min = this->size < arg.size ? this->size : arg.size;
        for (i = 0; i <= min; ++i) {
            answer.V[i] = this->V[i] - arg.V[i];
        }
        for (; i <= this->size; ++i) {
            answer.V[i] = this->V[i];
        }
        for (; i <= arg.size; ++i) {
            answer.V[i] = -arg.V[i];
        }
        answer.size = i - 1;
        for (i = 0; i <= answer.size; ++i) {
            if (answer.V[i] < 0) {
                answer.V[i] += BASE;
                --answer.V[i + 1];
            }
        }
        for (; answer.V[answer.size] == 0 && answer.size > 0; --answer.size);
        answer.sign = newSign;
        return answer;
    }

    HugeInt digitMultiplication(const int& arg) const {
        HugeInt answer;
        answer.alloc(this->size + 3);
        int myArg = arg;
        if (myArg < 0) {
            myArg = -myArg;
            if (this->sign == -1) answer.sign = 1;
            else answer.sign = -1;
        } else {
            answer.sign = this->sign;
        }
        int i;
        long long tmp;
        for (i = 0; i <= this->size + 1; ++i) {
            answer.V[i] = 0;
        }
        for (i = 0; i <= this->size; ++i) {
            tmp = (long long)this->V[i] * myArg + answer.V[i];
            answer.V[i] = (int)(tmp % BASE);
            

            answer.V[i + 1] = (int)(tmp / BASE);
        }
        if (answer.V[this->size + 1]) {
            answer.size = this->size + 1;
        } else {
            answer.size = this->size;
        }
        return answer;
    }

public:
    HugeInt baseMultiplication(const int& arg) const {
        if (this->size == 0 && this->V[0] == 0) {
            return *this;
        }
        int i, j;
        HugeInt answer;
        if (this->size + arg >= 0) {
            answer.alloc(this->size + arg + 2);
            answer.sign = this->sign;
            answer.size = this->size + arg;
            for (i = answer.size, j = this->size; j >= 0 && i >= 0; --i, --j) {
                answer.V[i] = this->V[j];
            }
            for (; i >= 0; --i) {
                answer.V[i] = 0;
            }
        } else {
            answer = 0;
        }
        return answer;
    }

private:
    HugeInt digitDivision(const int& arg) const {
        HugeInt answer;
        answer.alloc(this->size + 2);
        int myArg = arg;
        if (myArg < 0) {
            myArg = -myArg;
            if (this->sign == -1) answer.sign = 1;
            else answer.sign = -1;
        } else {
            answer.sign = this->sign;
        }
        int i;
        long long tmp1, tmp2;
        tmp1 = this->V[this->size];
        for (i = this->size; i >= 0; --i) {
            tmp2 = tmp1 % myArg;
            tmp1 -= tmp2;
            answer.V[i] = (int)(tmp1 / myArg);
            if (i) tmp1 = tmp2 * BASE + this->V[i - 1];
        }
        if (answer.V[this->size] > 0) {
            answer.size = this->size;
        } else {
            if (this->size > 0) {
                answer.size = this->size - 1;
            } else {
                answer.size = this->size;
            }
        }
        return answer;
    }

    int digitRemainder(const int& arg) const {
        long long answer = 0;
        int i;
        for(i = this->size; i >= 0; --i) {
            answer *= BASE;
            answer += this->V[i];
            answer %= arg;
        }
        return (int)answer;
    }

    void alloc(int size) {
        if (this->V != NULL) {
            delete this->V;
        }
        this->V = new int[size];
    }

    void realloc(int oldSize, int newSize) {
        if (this->V == NULL) {
            this->V = new int[newSize];
        } else {
            int i;
            int* oldV = this->V;
            this->V = new int[newSize];
            for (i = 0; i < oldSize; ++i) {
                this->V[i] = oldV[i];
            }
            delete oldV;
        }
    }

public:
    HugeInt() {
        this->V = NULL;
        *this = 0;
    }

    HugeInt(const long long& arg) {
        this->V = NULL;
        *this = arg;
    }

    HugeInt(const HugeInt& arg) {
        this->V = NULL;
        this->alloc(arg.size + 1);
        this->size = arg.size;
        this->sign = arg.sign;
        memcpy(this->V, arg.V, sizeof(int) * (this->size + 1));
    }

    HugeInt& operator =(const long long& arg) {
        this->alloc(3);
        this->V[0] = this->size = 0;
        long long myArg = arg;
        if (myArg < 0) {
            myArg = -myArg;
            this->sign = -1;
        } else {
            this->sign = 1;
        }
        while (myArg > 0) {
            this->V[this->size++] = (int)(myArg % BASE);
            myArg /= BASE;
        }
        if (this->size > 0) {
            --this->size;
        }
        return *this;
    }

    HugeInt& operator =(const HugeInt& arg) {
        this->alloc(arg.size + 1);
        this->size = arg.size;
        this->sign = arg.sign;
        memcpy(this->V, arg.V, sizeof(int) * (this->size + 1));
        return *this;
    }

    
    static int compare(const HugeInt &arg1, const HugeInt &arg2) {
        if (arg1.sign != arg2.sign) {
            if (arg1.sign==1) return 1;
            else return -1;
        } else {
            if (arg1.size > arg2.size) {
                if (arg1.sign == 1) return 1;
                else return -1;
            } else if (arg1.size < arg2.size) {
                if (arg1.sign == 1) return -1;
                else return 1;
            } else {
                int i;
                for (i = arg1.size; arg1.V[i] == arg2.V[i] && i >= 0; --i);
                if (i >= 0) {
                    if (arg1.V[i] > arg2.V[i]) {
                        if (arg1.sign == 1) return 1;
                        else return -1;
                    } else {
                        if (arg1.sign == 1) return -1;
                        else return 1;
                    }
                } else {
                    return 0;
                }
            }
        }
    }

    bool operator <(const HugeInt& arg) const {
        return compare(*this, arg) < 0;
    }

    friend bool operator <(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 < arg2;
    }

    bool operator >(const HugeInt& arg) const {
        return compare(*this, arg) > 0;
    }

    friend bool operator >(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 > arg2;
    }

    bool operator <=(const HugeInt& arg) const {
        return compare(*this, arg) <= 0;
    }

    friend bool operator <=(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 <= arg2;
    }

    bool operator >=(const HugeInt& arg) const {
        return compare(*this, arg) >= 0;
    }

    friend bool operator >=(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 >= arg2;
    }

    bool operator ==(const HugeInt& arg) const {
        return compare(*this, arg) == 0;
    }

    friend bool operator ==(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 == arg2;
    }

    bool operator !=(const HugeInt& arg) const {
        return compare(*this, arg) != 0;
    }

    friend bool operator !=(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 != arg2;
    }

    const HugeInt& operator +() const {
        return *this;
    }

    HugeInt operator -() const {
        HugeInt answer = *this;
        answer.sign = -answer.sign;
        return answer;
    }

    HugeInt operator +(const HugeInt& arg) const {
        if (this->sign == -1 && arg.sign == -1) {
            return this->unsignedAddition(arg, -1);
        } else if (this->sign == -1 && arg.sign == 1) {
            if (-*this > arg) {
                return this->unsignedSubtraction(arg, -1);
            } else {
                return arg.unsignedSubtraction(*this, 1);
            }
        } else if (this->sign == 1 && arg.sign == -1) {
            if (*this >= -arg) {
                return this->unsignedSubtraction(arg, 1);
            } else {
                return arg.unsignedSubtraction(*this, -1);
            }
        } else { 

            return this->unsignedAddition(arg, 1);
        }
    }

    friend HugeInt operator +(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 + arg2;
    }

    HugeInt operator -(const HugeInt& arg) const {
        if (this->sign == -1 && arg.sign == -1) {
            if (*this >= arg) { 

                return arg.unsignedSubtraction(*this, 1);
            } else {
                return this->unsignedSubtraction(arg, -1);
            }
        } else if (this->sign == -1 && arg.sign ==  1) {
            return this->unsignedAddition(arg, -1);
        } else if (this->sign ==  1 && arg.sign == -1) {
            return this->unsignedAddition(arg, 1);
        } else { 

            if (*this >= arg) {
                return this->unsignedSubtraction(arg, 1);
            } else {
                return arg.unsignedSubtraction(*this, -1);
            }
        }
    }

    friend HugeInt operator -(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 - arg2;
    }

    HugeInt& operator ++() { 

        int i;
        if (this->sign == 1) {
            ++this->V[0];
            for (i = 0; this->V[i] == BASE; ++i) {
                this->V[i] = 0;
                ++this->V[i + 1];
            }
            if (this->size < i) {
                this->size = i;
            }
        } else {
            --this->V[0];
            for (i = 0; this->V[i] == -1; ++i) {
                this->V[i] += BASE;
                --this->V[i + 1];
            }
            if (this->V[this->size] == 0) {
                --this->size;
            }
            if (this->size == -1) {
                this->sign = 1;
                this->size = 0;
            }
        }
        return *this;
    }

    HugeInt operator ++(int) { 

        HugeInt answer = *this;
        ++(*this);
        return answer;
    }

    HugeInt& operator --() { 

        int i;
        if (this->sign == -1) {
            ++this->V[0];
            for (i = 0; this->V[i] == BASE; ++i) {
                this->V[i] = 0;
                ++this->V[i + 1];
            }
            if (this->size < i) {
                this->size = i;
            }
        } else {
            if (this->size == 0 && this->V[0] == 0) {
                this->sign = -1;
                this->V[0] = 1;
            } else {
                --this->V[0];
                for (i = 0; this->V[i] == -1; ++i) {
                    this->V[i] += BASE;
                    --this->V[i + 1];
                }
                if (this->V[this->size] == 0) {
                    --this->size;
                }
                if (this->size == -1) {
                    this->size = 0;
                }
            }
        }
        return *this;
    }

    HugeInt operator --(int) { 

        HugeInt answer = *this;
        --(*this);
        return answer;
    }

    HugeInt operator *(const HugeInt& arg) const {
        if (arg == 0 || *this == 0) {
            return 0;
        }
        HugeInt answer;
        answer.alloc(this->size + arg.size + 4);
        answer.sign = this->sign * arg.sign;
        HugeInt Tmp;
        int i, j;
        for (i = 0; i <= this->size + arg.size + 1; ++i) {
            answer.V[i] = 0;
        }
        for (i = 0; i <= arg.size; ++i) {
            Tmp = this->digitMultiplication(arg.V[i]);
            for(j = 0; j <= Tmp.size; ++j) {
                answer.V[i + j] += Tmp.V[j];
                answer.size = i + j;
                if (answer.V[i + j] >= BASE) {
                    answer.V[i + j] -= BASE;
                    ++answer.V[i + j + 1];
                    answer.size = i + j + 1;
                }
            }
        }
        return answer;
    }

    HugeInt operator *(const int& arg) const {
        if (0 <= arg && arg < BASE) {
            return this->digitMultiplication(arg);
        } else {
            return this->operator *((HugeInt)arg);
        }
    }

    friend HugeInt operator *(const long long& arg1, const HugeInt& arg2) {
        return arg2 * (HugeInt)arg1;
    }

    HugeInt operator /(const HugeInt& arg) const {
        if (arg.size == 0 && this->sign == 1 && arg.sign == 1) {
            return this->digitDivision(arg.V[0]);
        }
        int nrCifre = (this->size + 1) - (arg.size + 1);
        if (nrCifre <= 0) {
            nrCifre = 1;
        }

        int i;
        HugeInt answer;
        answer.alloc(nrCifre + 2);
        HugeInt tmp;
        HugeInt thisAbs = this->abs();
        HugeInt argAbs = arg.abs();
        int start, med, stop;

        for (i = nrCifre; i >= 0; --i) {
            start = 0;
            stop = BASE - 1;
            while (start < stop) {
                med = (start + stop) / 2 + 1;
                tmp = (med * argAbs).baseMultiplication(i);
                if (tmp <= thisAbs) {
                    start = med;
                } else {
                    stop = med - 1;
                }
            }
            answer.V[i] = start;
            thisAbs -= (start * argAbs).baseMultiplication(i);
        }
        for (answer.size = nrCifre; answer.size > 0 && answer.V[answer.size] == 0; --answer.size);

        answer.sign = this->sign * arg.sign;
        if (answer.size == 0 && answer.V[0] == 0) {
            answer.sign = 1;
        }
        return answer;
    }

    friend HugeInt operator /(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 / arg2;
    }

    HugeInt operator %(const HugeInt& arg) const {
        if (arg.size == 0 && this->sign == 1 && arg.sign == 1) {
            return this->digitRemainder(arg.V[0]);
        }
        return *this - (*this / arg) * arg;
    }

    friend HugeInt operator %(const long long& arg1, const HugeInt& arg2) {
        return (const HugeInt)arg1 % arg2;
    }

    HugeInt& operator +=(const HugeInt& arg) {
        *this = *this + arg;
        return *this;
    }

    HugeInt& operator -=(const HugeInt& arg) {
        *this = *this - arg;
        return *this;
    }

    HugeInt& operator *=(const HugeInt& arg) {
        *this = *this * arg;
        return *this;
    }

    HugeInt& operator /=(const HugeInt& arg) {
        *this = *this / arg;
        return *this;
    }

    HugeInt& operator %=(const HugeInt& arg) {
        *this = *this % arg;
        return *this;
    }

    HugeInt abs() const {
        HugeInt answer = *this;
        answer.sign = 1;
        return answer;
    }

    HugeInt pow(unsigned int exp) const {
        HugeInt answer = 1;
        HugeInt power = *this;
        for(; exp > 0; exp >>= 1) {
            if ((exp & 1) > 0) {
                answer *= power;
            }
            if (exp > 1) {
                power *= power;
            }
        }
        return answer;
    }

    HugeInt root(const unsigned int& deg) const {
        HugeInt start, stop;
        int nrCifre = ((this->size + 1) - 1) / deg + 1;
        start.alloc(nrCifre + 2);
        stop.alloc(nrCifre + 2);
        start.size = nrCifre - 1;
        stop.size = nrCifre - 1;
        int i;
        for (i = 0; i < nrCifre; ++i) {
            start.V[i] = 0;
            stop.V[i] = BASE - 1;
        }
        start.V[start.size] = 1;

        HugeInt med;
        while (start < stop) {
            med = (start + stop) / 2 + 1;
            if (med.pow(deg) <= *this) {
                start = med;
            } else {
                stop = med - 1;
            }
        }

        start.sign = this->sign;
        return start;
    }

    unsigned long long getllu() const {
        unsigned long long answer = 0;
        int i;
        for (i = this->size; i >= 0; --i) {
            answer *= BASE;
            answer += this->V[i];
        }
        return answer;
    }

    long long getlld() const {
        long long answer = 0;
        int i;
        for (i = this->size; i >= 0; --i) {
            answer *= BASE;
            answer += this->V[i];
        }
        if (this->sign == -1) {
            answer = -answer;
        }
        return answer;
    }

    unsigned int getu() const {
        return this->getllu();
    }

    int getd() const {
        return this->getlld();
    }

    void afisare(FILE* output) const {
        int i;
        if (this->sign == -1) fprintf(output, "-");
        fprintf(output, "%d", this->V[this->size]);
        for(i = this->size - 1; i >= 0; --i) {
            fprintf(output, PRINT_FORMAT, this->V[i]);
        }
    }

    void afisare() const {
        afisare(stdout);
    }

    void citire(FILE *input) {
        int allocated = 4;
        this->alloc(allocated + 2);
        int Nr0;
        char Nr[1000];
        int stop;
        int i, j;
        int tmp, tmpc;
        fscanf(input, "%s", Nr);
        Nr0 = strlen(Nr);
        if (Nr[0] == '-') {
            stop = 1;
            this->sign = -1;
        } else {
            stop = 0;
            this->sign = 1;
        }
        this->V[this->size = 0] = 0;
        for(i = Nr0 - 1; i >= stop; ) {
            tmp = 0;
            tmpc = 0;
            for(j = 1; j <= SCAN_POWER && i >= stop; ++j) {
                tmp *= 10;
                tmp += Nr[i] - '0';
                --i;
                ++tmpc;
            }
            for(j = 1; j <= tmpc; ++j) {
                this->V[this->size] *= 10;
                this->V[this->size] += tmp % 10;
                tmp /= 10;
            }
            this->V[++this->size] = 0;
            if (this->size == allocated) {
                allocated *= 2;
                this->realloc(allocated / 2 + 2, allocated + 2);
            }
        }
        if (this->V[this->size] == 0) {
            --this->size;
        }
        if (this->size == 0 && this->V[0] == 0 && this->sign == -1) this->sign = 0;
    }

    void citire() {
        citire(stdin);
    }

    ~HugeInt() {
        if (this->V != NULL) {
            delete this->V;
        }
    }
};

const int HugeInt::BASE = 1000000000;
const int HugeInt::SCAN_POWER = 9;
const char* HugeInt::PRINT_FORMAT = "%.9d";


int gcd(int a, int b) {
  while (b > 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

bool eOk(HugeInt x, HugeInt q, HugeInt y, HugeInt answer, HugeInt pas, HugeInt p) {
  return (x * q <= (y + answer + pas) * p
      && p * (y + answer + pas) <= q * (x + answer + pas));
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t > 0) {
    long long x, y, p, q;
    scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
    long long answer;
    if (x < y && p == q) { 

      answer = -1;
    } else if (0 < x && p == 0) { 

      answer = -1;
    } else {
      int cmmdc = gcd(p, q);
      p /= cmmdc;
      q /= cmmdc;

      
      answer = 0;
      for (long long pas = 1LL << 62; pas > 0; pas >>= 1)
        if (!eOk(x, q, y, answer, pas, p))
          answer += pas;
      if ((y + answer) % q > 0)
        answer += q - (y + answer) % q;
    }
    printf("%lld\n", answer);
    t--;
  }
  return 0;
}
