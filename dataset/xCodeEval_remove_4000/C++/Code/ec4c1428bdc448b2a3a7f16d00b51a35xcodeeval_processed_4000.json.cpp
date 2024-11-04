







using namespace std;
FILE *in; FILE *out;

const int MAX = 1024;











class Long {
    public:
        

        Long();
        Long(const int&);
        Long(const long long&);
        Long(const char*);
        Long(const std::string&);
        Long(const Long&);

        

        ~Long();

        

        Long& operator = (const Long&);

        

        friend bool operator < (const Long& lvalue, const Long& rvalue);
        friend bool operator > (const Long& lvalue, const Long& rvalue);
        friend bool operator <= (const Long& lvalue, const Long& rvalue);
        friend bool operator >= (const Long& lvalue, const Long& rvalue);
        friend bool operator == (const Long& lvalue, const Long& rvalue);
        friend bool operator != (const Long& lvalue, const Long& rvalue);

        

        Long operator + (const Long&) const;
        Long operator - (const Long&) const;
        Long operator * (const Long&) const;
        Long operator / (const Long&) const;
        Long operator % (const Long&) const;

        Long& operator += (const Long&);
        Long& operator -= (const Long&);
        Long& operator *= (const Long&);
        Long& operator /= (const Long&);
        Long& operator %= (const Long&);

        

        Long operator + (void) const;
        Long operator - (void) const;

        

        Long& operator ++ ();
        Long& operator -- ();

        

        Long operator ++ (int);
        Long operator -- (int);

        

        

        explicit operator bool() const;

        

        bool isZero() const;

        

        int toInt() const;
        long long toLong() const;
        std::string toString() const;

    private:
        

        static const int BASE = 1000000;
        static const int id0 = 6;
        static const int DEFAULT_SIZE = 4;
        

        


        

        bool negative_;
        int* digits_, length_, size_;

        

        void init_();
        void clean_();
        void reserve_(int size);
        void append_(int digit);
        void copy_(const Long&);
        void fix_();

        

        void createFromInteger_(long long);
        void createFromString_(const char*);

        

        int toInt_() const;
        long long toLong_() const;
        std::string toString_() const;

        

        int absoluteCompare_(const Long&, const Long&) const;
        void absoluteAdd_(Long&, const Long&) const;
        void absoluteSubtract_(Long&, const Long&) const;
        void absoluteMultiplyByInt_(Long&, const int&) const;
        void absoluteMultiplyByLong_(Long&, const Long&) const;
        void absoluteDivideByInt_(Long&, const int&, bool) const;
        void absoluteDivideByLong_(Long&, const Long&, bool) const;

        

        int compare_(const Long&) const;
        void add_(const Long&);
        void multiply_(const Long&);
        void divide_(const Long&);
        void modulus_(const Long&);

        

        bool isZero_() const;

};





void Long::init_() {
    this->digits_ = NULL;
    this->negative_ = false;
    this->length_ = this->size_ = 0;
}

void Long::clean_() {
    if (this->digits_ != NULL)
        delete [] this->digits_;
    this->digits_ = NULL;
    this->negative_ = false;
    this->length_ = this->size_ = 0;
}

void Long::reserve_(int size) {
    int* digits = new int[size];
    memset(digits, 0, size * sizeof(int));
    if (this->length_ > 0 && this->length_ <= size) {
        memcpy(digits, this->digits_, this->length_ * sizeof(int));
    }
    delete [] this->digits_;
    this->size_ = size;
    this->digits_ = digits;
}

void Long::append_(int digit) {
    if (this->length_ == this->size_)
        this->reserve_(this->size_ * 2);
    this->digits_[this->length_++] = digit;
}

void Long::copy_(const Long& value) {
    this->clean_();
    this->reserve_(value.length_);

    this->negative_ = value.negative_;
    this->length_ = value.length_;
    memcpy(this->digits_, value.digits_, this->size_ * sizeof(int));
}

void Long::fix_() {
    while (this->length_ > 1 && this->digits_[this->length_ - 1] == 0)
        this->length_--;
    if (this->negative_ && this->length_ == 1 && this->digits_[0] == 0)
        this->negative_ = false;
}



void Long::createFromInteger_(long long value) {
    this->init_();
    this->reserve_(DEFAULT_SIZE);

    if (value < 0) {
        value = -value;
        this->negative_ = true;
    }
    do {
        this->append_(value % BASE);
        value /= BASE;
    } while (value > 0);
}

void Long::createFromString_(const char* value) {
    bool hasSign = false;
    int len = (int)strlen(value);
    if (len == 0) {
        this->createFromInteger_(0LL);
        return;
    }
    if (value[0] == '-' || value[0] == '+')
        hasSign = true;

    bool id2 = true;
    assert(len > (int)hasSign);
    for (int i = (int)hasSign; i < len; i++) {
        if (value[i] < '0' || value[i] > '9') {
            id2 = false;
            break;
        }
    }
    assert(id2);

    this->init_();
    this->reserve_((len - hasSign + id0 - 1) / id0);

    if (hasSign && value[0] == '-')
        this->negative_ = true;

    for (int i = len - 1; i >= (int)hasSign; i -= id0) {
        int add = 0;
        int pos = std::max((int)hasSign, i - id0 + 1);
        for (int c = 0; pos + c <= i; c++)
            add = add * 10 + value[pos + c] - '0';
        this->append_(add);
    }
    this->fix_();
}



int Long::toInt_() const {
    int ret = 0;
    if (this->length_ > 0)
        ret += this->digits_[0];
    if (this->length_ > 1)
        ret += (this->digits_[1] % 1000) * BASE;
    return ret * (this->negative_ ? -1 : +1);
}

long long Long::toLong_() const {
    long long ret = 0;
    if (this->length_ > 0)
        ret += (long long)this->digits_[0];
    if (this->length_ > 1)
        ret += (long long)this->digits_[1] * BASE;
    if (this->length_ > 2)
        ret += (long long)this->digits_[2] * BASE * BASE;
    return ret * (this->negative_ ? -1 : +1);
}

std::string Long::toString_() const {
    std::string ret;
    if (this->negative_)
        ret = "-";
    for (int i = this->length_ - 1; i >= 0; i--) {
        std::string add;
        for (int tmp = this->digits_[i]; tmp > 0; tmp /= 10)
            add.push_back(tmp % 10 + '0');
        if (i < this->length_ - 1)
            add.resize(id0, '0');
        std::reverse(add.begin(), add.end());
        ret += (add == "" ? "0" : add);
    }
    return ret;
}



int Long::absoluteCompare_(const Long& lvalue, const Long& rvalue) const {
    if (lvalue.length_ != rvalue.length_)
        return lvalue.length_ < rvalue.length_ ? -1 : +1;
    for (int i = lvalue.length_ - 1; i >= 0; i--)
        if (lvalue.digits_[i] != rvalue.digits_[i])
            return lvalue.digits_[i] < rvalue.digits_[i] ? -1 : +1;
    return 0;
}

void Long::absoluteAdd_(Long& lvalue, const Long& rvalue) const {
    while (lvalue.length_ < rvalue.length_)
        lvalue.append_(0);
    int carry = 0;
    for (int i = 0; i < rvalue.length_; i++) {
        lvalue.digits_[i] += rvalue.digits_[i] + carry;
        carry = 0;
        if (lvalue.digits_[i] >= BASE) {
            lvalue.digits_[i] -= BASE;
            carry = 1;
        }
    }
    for (int i = rvalue.length_; i < lvalue.length_ && carry; i++) {
        lvalue.digits_[i] += carry;
        carry = 0;
        if (lvalue.digits_[i] >= BASE) {
            lvalue.digits_[i] -= BASE;
            carry = 1;
        }
    }
    if (carry)
        lvalue.append_(carry);
}

void Long::absoluteSubtract_(Long& lvalue, const Long& rvalue) const {
    int carry = 0;
    assert(lvalue.length_ >= rvalue.length_);
    for (int i = 0; i < rvalue.length_; i++) {
        lvalue.digits_[i] -= rvalue.digits_[i] + carry;
        carry = 0;
        if (lvalue.digits_[i] < 0) {
            lvalue.digits_[i] += BASE;
            carry = 1;
        }
    }
    for (int i = rvalue.length_; i < lvalue.length_ && carry; i++) {
        lvalue.digits_[i] -= carry;
        carry = 0;
        if (lvalue.digits_[i] < 0) {
            lvalue.digits_[i] += BASE;
            carry = 1;
        }
    }
}

void Long::absoluteMultiplyByInt_(Long& lvalue, const int& rvalue) const {
    long long carry = 0;
    for (int i = 0; i < lvalue.length_; i++) {
        carry += (long long)rvalue * lvalue.digits_[i];
        lvalue.digits_[i] = carry % BASE;
        carry /= BASE;
    }
    while (carry) {
        lvalue.append_(carry % BASE);
        carry /= BASE;
    }
    lvalue.fix_();
}

void Long::absoluteMultiplyByLong_(Long& lvalue, const Long& rvalue) const {
    Long result;
    result.reserve_(lvalue.length_ + rvalue.length_);
    for (int i = 0; i < rvalue.length_; i++) {
        if (rvalue.digits_[i] == 0)
            continue;
        Long add(lvalue);
        absoluteMultiplyByInt_(add, rvalue.digits_[i]);
        if (i > 0) {
            add.reserve_(add.length_ + i);
            for (int c = add.length_ - 1; c >= 0; c--)
                add.digits_[i + c] = add.digits_[c], add.digits_[c] = 0;
            add.length_ += i;
        }
        absoluteAdd_(result, add);
    }
    lvalue.copy_(result);
}

void Long::absoluteDivideByInt_(Long& lvalue, const int& rvalue,
        bool id1 = false) const {
    long long carry = 0;
    Long result;
    for (int i = lvalue.length_ - 1; i >= 0; i--) {
        carry = carry * BASE + lvalue.digits_[i];
        result.append_(carry / rvalue);
        carry %= rvalue;
    }
    if (id1) {
        lvalue.createFromInteger_(carry);
    }
    else {
        std::reverse(result.digits_, result.digits_ + result.length_);
        result.fix_();
        lvalue.copy_(result);
    }
}

void Long::absoluteDivideByLong_(Long& lvalue, const Long& rvalue,
        bool id1 = false) const {
    assert(rvalue.length_ > 1);
    Long result;
    result.length_ = 0;
    for (int i = lvalue.length_ - 1; i >= rvalue.length_ - 1; i--) {
        long long carry = (i + 1 < lvalue.length_ ? lvalue.digits_[i + 1] : 0);
        

        long long digit = carry;
        digit = digit * BASE + lvalue.digits_[i];
        digit = digit * BASE + lvalue.digits_[i - 1];
        

        digit /= (long long)BASE * rvalue.digits_[rvalue.length_ - 1] +
                                   rvalue.digits_[rvalue.length_ - 2];

        

        for (int c = 1; c <= rvalue.length_; c++) {
            carry = carry * BASE + lvalue.digits_[i - c + 1];
            carry -= digit * rvalue.digits_[rvalue.length_ - c];
            if (carry < 0) {
                

                digit--;
                break;
            }
            if (carry >= BASE)
                break;
        }
        assert(digit >= 0);
        if (result.length_ == 0 && digit == 0)
            continue;
        result.append_(digit);
        
        carry = 0;
        for (int c = 0; c < rvalue.length_; c++) {
          carry += digit * rvalue.digits_[c];
          lvalue.digits_[i - rvalue.length_ + c + 1] -= carry % BASE;
          carry /= BASE;
          if (lvalue.digits_[i - rvalue.length_ + c + 1] < 0) {
            carry++;
            lvalue.digits_[i - rvalue.length_ + c + 1] += BASE;
          }
        }
        for (int c = i + 1; carry && c < lvalue.length_; c++) {
          lvalue.digits_[c] -= carry % BASE;
          carry /= BASE;
          if (lvalue.digits_[c] < 0) {
            carry++;
            lvalue.digits_[c] += BASE;
          }
        }
        assert(carry == 0);
    }
    if (id1) {
        lvalue.fix_();
    }
    else {
        std::reverse(result.digits_, result.digits_ + result.length_);
        result.fix_();
        lvalue.copy_(result);
    }
}



int Long::compare_(const Long& rvalue) const {
    if (this->negative_ != rvalue.negative_)
        return this->negative_ ? -1 : +1;
    int ret = absoluteCompare_(*this, rvalue);
    return this->negative_ ? -ret : +ret;
}

void Long::add_(const Long& rvalue) {
    if (this->negative_ == rvalue.negative_)
        absoluteAdd_(*this, rvalue);
    else {
        if (absoluteCompare_(*this, rvalue) >= 0) {
            absoluteSubtract_(*this, rvalue);
        }
        else {
            Long temp(rvalue);
            absoluteSubtract_(temp, *this);
            this->copy_(temp);
            this->negative_ = rvalue.negative_;
        }
    }
    this->fix_();
}

void Long::multiply_(const Long& rvalue) {
    bool negative = (this->negative_ != rvalue.negative_);
    if (rvalue.length_ == 1)
        absoluteMultiplyByInt_(*this, rvalue.digits_[0]);
    else if (this->length_ == 1) {
        int val = this->digits_[0];
        this->copy_(rvalue);
        absoluteMultiplyByInt_(*this, val);
    }
    else
        absoluteMultiplyByLong_(*this, rvalue);
    this->negative_ = negative;
    this->fix_();
}

void Long::divide_(const Long& rvalue) {
    assert(!rvalue.isZero_());
    if (absoluteCompare_(*this, rvalue) < 0) {
        this->length_ = 1;
        this->digits_[0] = 0;
        this->negative_ = false;
        return;
    }

    bool negative = (this->negative_ != rvalue.negative_);
    if (rvalue.length_ == 1)
        absoluteDivideByInt_(*this, rvalue.digits_[0]);
    else
        absoluteDivideByLong_(*this, rvalue);
    this->negative_ = negative;
    this->fix_();
}

void Long::modulus_(const Long& rvalue) {
    assert(!rvalue.isZero_());
    if (absoluteCompare_(*this, rvalue) < 0)
        return;
    if (rvalue.length_ == 1)
        absoluteDivideByInt_(*this, rvalue.digits_[0], true);
    else
        absoluteDivideByLong_(*this, rvalue, true);
    this->fix_();
}

bool Long::isZero_() const {
    return this->length_ == 1 && this->digits_[0] == 0;
}






Long::Long() {
    this->createFromInteger_(0LL);
}

Long::Long(const int& value) {
    this->createFromInteger_((long long)value);
}

Long::Long(const long long& value) {
    this->createFromInteger_(value);
}

Long::Long(const char* value) {
    this->createFromString_(value);
}

Long::Long(const std::string& value) {
    this->createFromString_(value.c_str());
}



Long::Long(const Long& value) {
    this->init_();
    this->copy_(value);
}



Long::~Long() {
    this->clean_();
}



Long& Long::operator = (const Long& rvalue) {
    if (this != &rvalue) {
        this->copy_(rvalue);
    }
    return *this;
}



bool operator < (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) < 0;
}

bool operator > (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) > 0;
}

bool operator <= (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) <= 0;
}

bool operator >= (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) >= 0;
}

bool operator == (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) == 0;
}

bool operator != (const Long& lvalue, const Long& rvalue) {
    return lvalue.compare_(rvalue) != 0;
}



Long Long::operator + () const {
    return *this;
}

Long Long::operator - () const {
    Long ret(*this);
    if (!ret.isZero_())
        ret.negative_ = !ret.negative_;
    return ret;
}



Long& Long::operator ++ () {
    this->add_(1);
    return *this;
}

Long& Long::operator -- () {
    this->add_(-1);
    return *this;
}



Long Long::operator ++ (int placeholder) {
    Long ret(*this);
    this->add_(1);
    return ret;
}

Long Long::operator -- (int placeholder) {
    Long ret(*this);
    this->add_(-1);
    return ret;
}



Long::operator bool() const {
    return !this->isZero_();
}



Long Long::operator + (const Long& rvalue) const {
    Long ret(*this);
    ret.add_(rvalue);
    return ret;
}

Long Long::operator - (const Long& rvalue) const {
    Long ret(*this);
    ret.add_(-rvalue);
    return ret;
}

Long Long::operator * (const Long& rvalue) const {
    Long ret(*this);
    ret.multiply_(rvalue);
    return ret;
}

Long Long::operator / (const Long& rvalue) const {
    Long ret(*this);
    ret.divide_(rvalue);
    return ret;
}

Long Long::operator % (const Long& rvalue) const {
    Long ret(*this);
    ret.modulus_(rvalue);
    return ret;
}

Long& Long::operator += (const Long& rvalue) {
    this->add_(rvalue);
    return *this;
}

Long& Long::operator -= (const Long& rvalue) {
    this->add_(-rvalue);
    return *this;
}

Long& Long::operator *= (const Long& rvalue) {
    this->multiply_(rvalue);
    return *this;
}

Long& Long::operator /= (const Long& rvalue) {
    this->divide_(rvalue);
    return *this;
}

Long& Long::operator %= (const Long& rvalue) {
    this->modulus_(rvalue);
    return *this;
}

bool Long::isZero() const {
    return this->isZero_();
}

int Long::toInt() const {
    return this->toInt_();
}

long long Long::toLong() const {
    return this->toLong_();
}

std::string Long::toString() const {
    return this->toString_();
}




void dummy(long long x, long long y, long long p, long long q) {
    long long k = 0, w = 0;
    while ((x + w) * q != (y + k) * p) {
        if (k > 1000000000) break;
        if ((x + w) * q < (y + k) * p) {
            k++, w++;
        } else {
            k++;
        }
    }
    if ((x + w) * q == (y + k) * p) {
        fprintf(out, "%lld\n", k);
        fprintf(stderr, "Found answer with k = %lld, w = %lld\n", k, w);
    } else {
        fprintf(out, "-1\n");
    }
}

int main(void) {
	in = stdin; out = stdout;
	

	
	int numTests;
	fscanf(in, "%d", &numTests);
	
	for (int test = 0; test < numTests; test++) {
	    long long x, y, p, q;
	    fscanf(in, "%lld %lld %lld %lld", &x, &y, &p, &q);
	    

	    
	    if (p == q) {
	        fprintf(out, "%d\n", x == y ? 0 : -1);
        } else if (p == 0) {
            fprintf(out, "%d\n", x == 0 ? 0 : -1);
        } else {
            Long w = (x % p == 0) ? 0 : ((x / p + 1) * p - x);
            Long left = 0, right = 1;
            while ((w + x) * q / p + right * q - y < w + right * p)
                left = right, right *= 2;
            while (left <= right) {
                Long mid = (left + right) / 2;
                if ((w + x) * q / p + mid * q - y >= w + mid * p)
                    right = mid - 1;
                else left = mid + 1;
            }
            w += (right + 1) * p;
            Long k = (w + x) * q / p - y;
            

            fprintf(out, "%s\n", k.toString().c_str());
        }
    }
	
	return 0;
}
