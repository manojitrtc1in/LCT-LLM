#include<bits/stdc++.h>
using namespace std;


template <class T> struct is_iterator {
	template < class U, typename enable_if < !is_convertible<U, const char*>::value, int >::type = 0 >
	constexpr static auto has_indirection(int) -> decltype(*declval<U>(), bool()) { return true; }
	template <class> constexpr static bool has_indirection(long) { return false; }
	constexpr static bool value = has_indirection<T>(0);
};

using uint = unsigned int;


const uint BUFFER_SIZE = 1 << 12;




const uint MAX_LENGTH = 1 << 7;

namespace Detail {
struct Width { uint value; };
struct Fill { char value; };
struct Base { uint value; };
struct Precision { uint value; };
struct Delimiter { const char* value; };
}  


Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return {value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return {value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return {value}; }


class InputDevice {
protected:
	const char* head;
	const char* tail;

	InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}

	virtual void fillInput() = 0;

	inline char nextChar() {
		if (__builtin_expect(head >= tail, false)) fillInput();
		return *head++;
	}

	template <class I> int readUnsignedIntGeneral(I& arg, char c) {
		I value = 0;
		int length = 0;
		for (;; ++length, c = nextChar()) {
			if (isDigit(c)) c -= '0';
			else if (isUpper(c)) c -= 'A' - 10;
			else if (isLower(c)) c -= 'a' - 10;
			else c = base;
			if (c >= base) break;
			value = base * value + c;
		}
		arg = value;
		return --head, length;
	}

	template <class I> inline int readUnsignedInt(I& arg, char c) {
		if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
		I value = 0;
		int length = 0;
		for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
			value = base * value + c - '0';
		arg = value;
		return --head, length;
	}

	template <class I> inline bool readSignedInt(I& arg, char c) {
		bool negative = c == '-';
		if (negative) c = nextChar();
		typename make_unsigned<I>::type unsignedArg;
		if (readUnsignedInt(unsignedArg, c) == 0) return false;
		arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
		return true;
	}

	template <class F> bool readFloatingPoint(F& arg, char c) {
		bool negative = c == '-';
		if (negative) c = nextChar();
		unsigned long long integerPart;
		if (readUnsignedInt(integerPart, c) == 0) return false;
		arg = static_cast<F>(integerPart);
		if (nextChar() == '.') {
			unsigned long long fractionalPart = 0;
			int fractionalLength = readUnsignedInt(fractionalPart, nextChar());
			if (fractionalLength > 0) {
				unsigned long long basePower = 1;
				for (; fractionalLength; --fractionalLength) basePower *= base;
				arg += static_cast<F>(fractionalPart) / basePower;
			}
		} else --head;
		if (negative) arg = -arg;
		return true;
	}

public:
	uint base;

	InputDevice(InputDevice const&) = delete;
	InputDevice& operator = (InputDevice const&) = delete;

	static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
	static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
	static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
	static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
	static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }

	void putBack() { --head; }  


	inline bool readChar(char& arg) {
		if (__builtin_expect(head >= tail, false)) {
			fillInput();
			if (__builtin_expect(head >= tail, false)) return arg = '\0', false;
		}
		return arg = *head++, true;
	}

	template <class UnaryPredicate>
	inline char skipCharacters(UnaryPredicate isSkipped) {
		char c;
		do { c = nextChar(); } while (isSkipped(c));
		return c;
	}
	inline char skipCharacters() { return skipCharacters(isSpace); }

	template <class UnaryPredicate>
	inline int readString(char* arg, int limit, UnaryPredicate isTerminator) {
		skipCharacters(isTerminator);
		

		int charsRead = 0;
		for (--head, --limit; head < tail; fillInput()) {
			ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), isTerminator) - head;
			arg = copy_n(head, chunkSize, arg);
			head += chunkSize;
			charsRead += chunkSize;
			if (chunkSize == 0 || head < tail) break;
		}
		return *arg = '\0', charsRead;
	}

	inline int readString(char* arg, int limit, const char* terminators) {
		if (!*terminators) return readString(arg, limit, InputDevice::isSpace);
		return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
	}

	

	inline bool read(Detail::Base newBase) { base = newBase.value; return true; }
	

	inline bool read() { return true; }
	inline bool read(char& arg) { return readChar(arg); }
	template <class I> inline typename enable_if < is_integral<I>::value && is_unsigned<I>::value,
	bool >::type read(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0; }
	template <class I> inline typename enable_if < is_integral<I>::value && is_signed<I>::value,
	bool >::type read(I& arg) { return readSignedInt(arg, skipCharacters()); }
	template <class F> inline typename enable_if<is_floating_point<F>::value,
	bool>::type read(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
	

	inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
	inline bool read(const char* arg) {
		if (*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
		else skipCharacters();
		return putBack(), true;
	}
	inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }
	

	template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
	bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args) {
		readString(arg, static_cast<int>(limit), terminator);
		return read(forward<Ts>(args)...);
	}
	template <class I> inline typename enable_if<is_integral<I>::value,
	bool>::type read(char* arg, I limit) { return read(arg, limit, ""); }
	template <class... Ts>
	inline bool read(char* first, char* last, Ts&&... args) {
		return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
	}
	template <int N, class... Ts>
	inline bool read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
	template <class Terminator, class... Ts>
	inline bool read(string& arg, Terminator terminator, Ts&&... args) {
		for (int length = 16, last = 0;; last += length, length <<= 1) {
			arg.resize(last + length);
			int charsRead = readString(&arg[last], length + 1, terminator);
			if (charsRead < length) {
				arg.resize(last + charsRead);
				return read(forward<Ts>(args)...);
			}
		}
	}
	inline bool read(string& arg) { return read(arg, ""); }
	

	template <class T1, class T2>
	inline bool read(pair<T1, T2>& arg) { return read(arg.first, arg.second); }
	template <class T>
	inline bool read(complex<T>& arg) {
		T real, imag;
		if (!read(real, imag)) return false;
		arg.real(real), arg.imag(imag);
		return true;
	}
	template <class T>
	inline bool read(vector<T>& arg) {
		uint n;
		if (!read(n)) return false;
		arg.resize(n);
		return read(arg.begin(), arg.end());
	}
	template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
	bool>::type read(Iterator first, Iterator last, Ts&&... args) {
		for (; first != last; ++first) if (!read(*first)) return false;
		return read(forward<Ts>(args)...);
	}
	template <class Iterator, class I, class... Ts>
	inline typename enable_if < is_iterator<Iterator>::value && is_integral<I>::value,
	bool >::type read(Iterator first, I count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
	

	template <class T>
	inline auto read(T& arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
	template <class T0, class T1, class... Ts>
	inline typename enable_if < !is_iterator<T0>::value & & !is_convertible<T0, char*>::value,
	bool >::type read(T0&& arg0, T1&& arg1, Ts&&... args) {
		return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
	}
};

class InputFile : public InputDevice {
	FILE* file;
	bool lineBuffered;
	bool owner;
	char buffer[BUFFER_SIZE];

	void fillInput() override {
		head = buffer;
		*buffer = '\0';
		if (__builtin_expect(!lineBuffered, true)) {
			tail = head + fread(buffer, 1, BUFFER_SIZE, file);
		} else {
			tail = head;
			if (fgets(buffer, BUFFER_SIZE, file)) while (*tail) ++tail;
		}
	}

public:
	InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
		: InputDevice(buffer, buffer) , file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
	InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
	~InputFile() { if (owner) fclose(file); }
};



class InputString : public InputDevice {
	void fillInput() override { while (*tail) ++tail; }

public:
	InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
	InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};


class OutputDevice {
protected:
	char buffer[BUFFER_SIZE + MAX_LENGTH];
	char* output;
	char* end;
	bool separate;

	OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false)
		, width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value)
		, delimiter(setDelimiter().value) { computeBasePower(); }

	virtual void writeToDevice(uint count) = 0;

	inline void flushMaybe() {
		if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
			writeToDevice(BUFFER_SIZE);
			output = copy(buffer + BUFFER_SIZE, output, buffer);
		}
	}

	void computeBasePower() {
		basePower = 1;
		for (uint i = 0; i < precision; ++i) basePower *= base;
	}

	template <class I> inline char* writeUnsignedInt(I arg, char* last) {
		if (__builtin_expect(arg == 0, false)) *--last = '0';
		if (__builtin_expect(base == 10, true)) {
			for (; arg; arg /= 10) * --last = '0' + arg % 10;
		} else for (; arg; arg /= base) {
				I digit = arg % base;
				*--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
			}
		return last;
	}

	template <class I> inline char* writeSignedInt(I arg, char* last) {
		auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
		if (arg < 0) {
			last = writeUnsignedInt(~unsignedArg + 1, last);
			*--last = '-';
			return last;
		}
		return writeUnsignedInt(unsignedArg, last);
	}

	template <class F> char* writeFloatingPoint(F arg, char* last) {
		bool negative = signbit(arg);
		if (negative) arg = -arg;
		if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
		else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
		else {
			auto integerPart = static_cast<unsigned long long>(arg);
			auto fractionalPart = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
			if (fractionalPart >= basePower) ++integerPart, fractionalPart = 0;
			char* point = last - precision;
			if (precision > 0) {
				::fill(point, writeUnsignedInt(fractionalPart, last), '0');
				*--point = '.';
			}
			last = writeUnsignedInt(integerPart, point);
		}
		if (negative) *--last = '-';
		return last;
	}

	inline int writeT(char* first) {
		int delimiterLenght = separate ? writeDelimiter() : 0;
		separate = true;
		uint charsWritten = static_cast<uint>(end - first);
		if (__builtin_expect(charsWritten < width, false))
			charsWritten += writeFill(width - charsWritten);
		output = copy(first, end, output);
		flushMaybe();
		return delimiterLenght + static_cast<int>(charsWritten);
	}

	inline int writeFill(uint count) {
		int charsWritten = static_cast<int>(count);
		if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
			if (count == 1) *output++ = fill;
			else output = fill_n(output, count, fill);
		} else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
				if (chunkSize > count) chunkSize = count;
				output = fill_n(output, chunkSize, fill);
				flushMaybe();
				if ((count -= chunkSize) == 0) break;
			}
		return charsWritten;
	}

public:
	uint width;
	char fill;
	uint base;
	uint precision;
	unsigned long long basePower;
	string delimiter;

	OutputDevice(OutputDevice const&) = delete;
	OutputDevice& operator = (OutputDevice const&) = delete;
	virtual ~OutputDevice() {};

	inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }

	inline int writeString(const char* arg, size_t length, bool checkWidth = true) {
		separate = false;
		uint count = static_cast<uint>(length);
		int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
		if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
			if (count == 1) *output++ = *arg;
			else output = copy_n(arg, count, output);
		} else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
				if (chunkSize > count) chunkSize = count;
				output = copy_n(arg, chunkSize, output);
				flushMaybe();
				if ((count -= chunkSize) == 0) break;
				arg += chunkSize;
			}
		return charsWritten;
	}

	inline int writeDelimiter() { return writeString(delimiter.c_str(), delimiter.size(), false); }

	inline void flush() {
		writeToDevice(static_cast<uint>(output - buffer));
		output = buffer;
	}

	

	inline int write(Detail::Width newWidth) { width = newWidth.value; return 0; }
	inline int write(Detail::Fill newFill) { fill = newFill.value; return 0; }
	inline int write(Detail::Base newBase) { base = newBase.value; computeBasePower(); return 0; }
	inline int write(Detail::Precision newPrecision) {
		precision = newPrecision.value; computeBasePower(); return 0;
	}
	inline int write(Detail::Delimiter newDelimiter) { delimiter = newDelimiter.value; return 0; }
	

	inline int write() { return 0; }
	inline int write(char arg) { return writeChar(arg); }
	template <class I> inline typename enable_if < is_integral<I>::value && is_unsigned<I>::value,
	int >::type write(I arg) { return writeT(writeUnsignedInt(arg, end)); }
	template <class I> inline typename enable_if < is_integral<I>::value && is_signed<I>::value,
	int >::type write(I arg) { return writeT(writeSignedInt(arg, end)); }
	template <class F> inline typename enable_if<is_floating_point<F>::value,
	int>::type write(F arg) { return writeT(writeFloatingPoint(arg, end)); }
	

	inline int write(const char* arg) { return writeString(arg, strlen(arg)); }
	template <int N>
	inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
	inline int write(const string& arg) { return writeString(arg.c_str(), arg.size()); }
	template <class T1, class T2>
	inline int write(const pair<T1, T2>& arg) {
		int charsWritten = write(arg.first);
		charsWritten += writeDelimiter();
		return charsWritten + write(arg.second);
	}
	template <class T>
	inline int write(const complex<T>& arg) { return write(real(arg), imag(arg)); }
	

	template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
	int>::type write(Iterator first, Iterator last, Ts&&... args) {
		int charsWritten = 0;
		for (; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
		return charsWritten + write(forward<Ts>(args)...);
	}
	template <class Iterator, class I, class... Ts>
	inline typename enable_if < is_iterator<Iterator>::value && is_integral<I>::value,
	int >::type write(Iterator first, I count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
	

	template <class T>
	inline auto write(const T& arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
	template <class T0, class T1, class... Ts> inline typename enable_if < !is_iterator<T0>::value,
	int >::type write(T0&& arg0, T1&& arg1, Ts&&... args) {
		int charsWritten = write(forward<T0>(arg0));
		return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
	}
};

class OutputFile : public OutputDevice {
	FILE* file;
	bool owner;

	void writeToDevice(uint count) override {
		fwrite(buffer, 1, count, file);
		fflush(file);
	}

public:
	OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
	OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
	~OutputFile() override { flush(); if (owner) fclose(file); }
};

class OutputString : public OutputDevice {
	string& str;

	void writeToDevice(uint count) override { str.append(buffer, count); }

public:
	OutputString(string& str) : OutputDevice(), str(str) {}
	~OutputString() override { flush(); }
};

unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;

template <class... Ts> inline bool read(Ts&&... args) { return input->read(forward<Ts>(args)...); }
template <class... Ts> inline int write(Ts&&... args) { return output->write(forward<Ts>(args)...); }
template <class... Ts> inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
void flush() { output->flush(); }



#define endl '\n'

const int M = 2e5 + 5;
const int S = 448;
const int K = 86;
const int N = 1e5 + 5;




template<const int &MOD>
struct _m_int  

{
	int val;   


	_m_int(int64_t v = 0)  

	{
		if (v < 0) v = v % MOD + MOD;
		if (v >= MOD) v %= MOD;
		val = v;
	}

	static int mod_inv(int a, int m = MOD)
	{
		

		int g = m, r = a, x = 0, y = 1;

		while (r != 0)
		{
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}

		return x < 0 ? x + m : x;
	}

	explicit operator int() const
	{
		return val;
	}

	explicit operator int64_t() const
	{
		return val;
	}

	_m_int& operator += (const _m_int &other)  

	{
		val -= MOD - other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	_m_int& operator -= (const _m_int &other)  

	{
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}

	static unsigned fast_mod(uint64_t x, unsigned m = MOD) 

	{
#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
#endif
		

		

		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}

	_m_int& operator*=(const _m_int &other)  

	{
		val = fast_mod((uint64_t) val * other.val);
		return *this;
	}

	_m_int& operator/=(const _m_int &other)  

	{
		return *this *= other.inv();
	}

	friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
	friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
	friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
	friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }

	_m_int& operator++()  

	{
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}

	_m_int& operator--()  

	{
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}

	_m_int operator++(int) { _m_int before = *this; ++*this; return before; }  

	_m_int operator--(int) { _m_int before = *this; --*this; return before; }  


	_m_int operator-() const  

	{
		return val == 0 ? 0 : MOD - val;
	}

	

	bool operator==(const _m_int &other) const { return val == other.val; }
	bool operator!=(const _m_int &other) const { return val != other.val; }
	bool operator< (const _m_int &other) const { return val <  other.val; }
	bool operator<=(const _m_int &other) const { return val <= other.val; }
	bool operator> (const _m_int &other) const { return val >  other.val; }
	bool operator>=(const _m_int &other) const { return val >= other.val; }

	_m_int inv() const  

	{
		return mod_inv(val);
	}

	_m_int pow(int64_t p) const  

	{
		if (p < 0)
			return inv().pow(-p);

		_m_int a = *this, result = 1;

		while (p > 0)
		{
			if (p & 1)
			{
				result *= a;
			}
			a *= a;
			p >>= 1;
		}

		return result;
	}

	friend ostream& operator<<(ostream &os, const _m_int &m)  

	{
		return os << m.val;
	}

};

extern const int MOD = 1e9 + 7;
using mod_int = _m_int<MOD>;


struct node
{
	int prv;
	mod_int pm, pref;

	node(int _prv, mod_int _pm, mod_int _pref)
	{
		prv = _prv;
		pm = _pm;
		pref = _pref;
	}

	bool operator < (node &other) const
	{
		return prv < other.prv;
	}
};

template<typename T>
class merge_sort	

{
public:
	vector<T> st;
	int n;

	merge_sort() {}

	merge_sort(int _n)
	{
		n = _n;
		st.resize(2 * n);
	}

	mod_int get(T &a, int x)
	{
		int low = 0;
		int high = (int)a.size() - 1;
		int id = -1;
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			if (a[mid].prv < x)
			{
				id = mid;
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		if (id >= 0)
		{
			return a[id].pref;
		}
		return 1;
	}

	void merge_nodes(T &vl, T &vr, T &v)
	{
		T res;
		merge(vl.begin(), vl.end(), vr.begin(), vr.end(), back_inserter(res));
		mod_int curr = 1;
		for (int i = 0; i < res.size(); i++)
		{
			mod_int p_val = 1;
			int j = i;
			while (j < res.size() && res[i].prv == res[j].prv)
			{
				curr = (curr * res[j].pm);
				p_val = (p_val * res[j].pm);
				j++;
			}
			i = j - 1;
			v.push_back(node(res[i].prv, p_val, curr));
		}
	}

	void create()
	{
		for (int i = n - 1; i > 0; i--) 

		{
			merge_nodes(st[i << 1], st[(i << 1) | 1], st[i]);
		}
	}

	mod_int query(int l, int r, int x)
	{
		mod_int ans = 1;
		mod_int ansl = 1;
		mod_int ansr = 1;
		for (l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
			{
				mod_int id = get(st[l], x); 

				l++;
				ansl *= id;
			}
			if (r & 1)
			{
				--r;
				mod_int id = get(st[r], x);
				ansr *= id;
			}
		}
		ans = (ansl * ansr);
		return ans;
	}
};


template<typename T>
class segment	

{
public:

	vector<T> st;
	int n;

	segment() {}

	segment(int _n)
	{
		n = _n;
		st.resize(2 * n, (T)0);
	}

	T merge(T &a, T &b)
	{
		return max(a, b);
	}

	void create()
	{
		for (int i = n - 1; i > 0; i--)
		{
			st[i] = merge(st[i << 1], st[(i << 1) | 1]);
		}
	}

	void update(int idx, T val)
	{
		for (st[idx += n - 1] = val; idx > 1; idx >>= 1)
		{
			st[idx >> 1] = merge(st[min(idx, idx ^ 1)], st[max(idx, idx ^ 1)]);
		}
	}

	T query(int l, int r)
	{
		T ans{};
		T ansl{};
		T ansr{};
		for (l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
			{
				ansl = merge(ansl, st[l++]);
			}
			if (r & 1)
			{
				ansr = merge(st[--r], ansr);
			}
		}
		ans = merge(ansl, ansr);
		return ans;
	}
};


vector<segment<int>> obj(K);
merge_sort<vector<node>> obj_mg;
int p[N], val[N], a[N], spf[M], pv[M];
mod_int prime[K];
int n, q;

void pre()
{
	for (int i = 1; i < M; i++)
	{
		spf[i] = i;
	}
	for (int i = 2; i < M; i++)
	{
		if (spf[i] == i)
		{
			for (int j = 2 * i; j < M; j += i)
			{
				spf[j] = min(spf[j], i);
			}
		}
	}
	int id = 0;
	for (int i = 2; i < S; i++)
	{
		if (spf[i] == i)
		{
			prime[id++] = i;
		}
	}
	for (int i = 0; i < K; i++)
	{
		obj[i] = segment<int> (n);
		obj[i].create();
	}
	for (int i = 1; i < M; i++)
	{
		pv[i] = -1;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i];
		for (int j = 0; j < K; j++)
		{
			int pw = 0;
			while (x % (int)prime[j] == 0)
			{
				x /= (int)prime[j];
				pw++;
			}
			if (pw)
			{
				obj[j].update(i, pw);
			}
		}
		p[i] = x;
		val[i] = pv[p[i]];
		pv[p[i]] = i;
	}

	obj_mg = merge_sort<vector<node>> (n);
	for (int i = 1; i <= n; i++)
	{
		obj_mg.st[i + n - 1].push_back(node(val[i], p[i], p[i]));
	}
	obj_mg.create();
}

mod_int lcm(int l, int r)
{
	mod_int ans = 1;
	for (int i = 0; i < K; i++) 

	{
		ans = (ans * prime[i].pow(obj[i].query(l, r + 1)));
	}
	ans = (ans * obj_mg.query(l, r + 1, l));
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	input.reset(new InputFile(stdin, false));
	output.reset(new OutputFile());

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
	}
	pre();

	read(q);
	mod_int last = 0;
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		read(x);
		read(y);
		int l = (x + (int)last) % n + 1;
		int r = (y + (int)last) % n + 1;
		if (l > r)
		{
			swap(l, r);
		}
		last = lcm(l, r);
		writeln((int)last);
	}

}