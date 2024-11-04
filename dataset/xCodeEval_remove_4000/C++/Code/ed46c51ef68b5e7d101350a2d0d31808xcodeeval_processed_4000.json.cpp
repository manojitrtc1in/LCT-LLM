



































using namespace std;



inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);



static const int buf_size = 4096*4;

inline int getChar()
{
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if(pos == len)
		pos = 0, len = (int)_fread_nolock(buf, 1, buf_size, stdin);
	if(pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar()
{
	int c = getChar();
	while(c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt()
{
	int s = 1, c = readChar();
	T x = 0;
	if(c == '-')
		s = -1, c = getChar();
	while('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}



static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x)
{
	if(write_pos == buf_size)
		_fwrite_nolock(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end)
{
	if(x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while(x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while(n--)
		writeChar(s[n]);
	if(end)
		writeChar(end);
}

inline void writeWord(const char *s)
{
	while(*s)
		writeChar(*s++);
}

struct Flusher
{
	~Flusher()
	{
		if(write_pos)
			_fwrite_nolock(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;




class TimeTracker
{
	clock_t start, end;
public:
	TimeTracker ()
	{
		start = clock ();
	}
	~TimeTracker ()
	{
		end = clock ();
		fprintf (stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
};



template <typename InputIt>
struct key_it : public InputIt
{
	key_it(InputIt it) : InputIt(it) {}
	auto operator*() { return (*this)->first; }
};


template <typename InputIt>
key_it<InputIt> id6(InputIt it)
{
	return{it};
}





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n{}, t{}, ans{2}, x{}, a{};
	vector<pair<int, int>>v{};
	v.reserve(n);
	n = readInt();
	t = readInt();
	t <<= 1;
	for(int i = 0; i < n; i++)
	{
		x = readInt();
		a = readInt();
		v.push_back({2*x - a, 2*x + a});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < (int)v.size(); i++)
	{
		if(v[i].first - v[i-1].second == t)
			++ans;
		else if(v[i].first - v[i-1].second > t)
			ans += 2;
	}
	writeInt(ans, '\n');
	return 0;
}




using namespace std;

template <class T> struct is_iterator
{
	template <class U, typename enable_if<!is_convertible<U, const char*>::value, int>::type = 0>
	constexpr static auto id3(int) -> decltype(*declval<U>(), bool()) { return true; }
	template <class> constexpr static bool id3(long) { return false; }
	constexpr static bool value = id3<T>(0);
};

using uint = unsigned int;


const uint BUFFER_SIZE = 1 << 12;




const uint MAX_LENGTH = 1 << 7;

namespace Detail
{
	struct Width { uint value; };
	struct Fill { char value; };
	struct Base { uint value; };
	struct Precision { uint value; };
	struct Delimiter { const char* value; };
}  


Detail::Width setWidth(uint value = 0) { return{value}; }
Detail::Fill setFill(char value = ' ') { return{value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return{value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return{value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return{value}; }


class InputDevice
{
protected:
	const char* head;
	const char* tail;

	InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}

	virtual void fillInput() = 0;

	inline char nextChar()
	{
		if(__builtin_expect(head >= tail, false)) fillInput();
		return *head++;
	}

	template <class I> int id1(I& arg, char c)
	{
		I value = 0;
		int length = 0;
		for(;; ++length, c = nextChar())
		{
			if(isDigit(c)) c -= '0';
			else if(isUpper(c)) c -= 'A' - 10;
			else if(isLower(c)) c -= 'a' - 10;
			else c = base;
			if(c >= base) break;
			value = base * value + c;
		}
		arg = value;
		return --head, length;
	}

	template <class I> inline int id5(I& arg, char c)
	{
		if(__builtin_expect(base > 10, false)) return id1(arg, c);
		I value = 0;
		int length = 0;
		for(; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
			value = base * value + c - '0';
		arg = value;
		return --head, length;
	}

	template <class I> inline bool id12(I& arg, char c)
	{
		bool negative = c == '-';
		if(negative) c = nextChar();
		typename make_unsigned<I>::type unsignedArg;
		if(id5(unsignedArg, c) == 0) return false;
		arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
		return true;
	}

	template <class F> bool id4(F& arg, char c)
	{
		bool negative = c == '-';
		if(negative) c = nextChar();
		unsigned long long integerPart;
		if(id5(integerPart, c) == 0) return false;
		arg = static_cast<F>(integerPart);
		if(nextChar() == '.')
		{
			unsigned long long id11 = 0;
			int id10 = id5(id11, nextChar());
			if(id10 > 0)
			{
				unsigned long long basePower = 1;
				for(; id10; --id10) basePower *= base;
				arg += static_cast<F>(id11) / basePower;
			}
		}
		else --head;
		if(negative) arg = -arg;
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


	inline bool readChar(char& arg)
	{
		if(__builtin_expect(head >= tail, false))
		{
			fillInput();
			if(__builtin_expect(head >= tail, false)) return arg = '\0', false;
		}
		return arg = *head++, true;
	}

	template <class UnaryPredicate>
	inline char skipCharacters(UnaryPredicate isSkipped)
	{
		char c;
		do { c = nextChar(); } while(isSkipped(c));
		return c;
	}
	inline char skipCharacters() { return skipCharacters(isSpace); }

	template <class UnaryPredicate>
	inline int readString(char* arg, int limit, UnaryPredicate id9)
	{
		skipCharacters(id9);
		

		int charsRead = 0;
		for(--head, --limit; head < tail; fillInput())
		{
			ptrdiff_t chunkSize = find_if(head, min(tail, head + limit - charsRead), id9) - head;
			arg = copy_n(head, chunkSize, arg);
			head += chunkSize;
			charsRead += chunkSize;
			if(chunkSize == 0 || head < tail) break;
		}
		return *arg = '\0', charsRead;
	}

	inline int readString(char* arg, int limit, const char* terminators)
	{
		if(!*terminators) return readString(arg, limit, InputDevice::isSpace);
		return readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
	}

	

	inline bool read(Detail::Base newBase) { base = newBase.value; return true; }
	

	inline bool read() { return true; }
	inline bool read(char& arg) { return readChar(arg); }
	template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
		bool>::type read(I& arg) { return id5(arg, skipCharacters()) > 0; }
	template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
		bool>::type read(I& arg) { return id12(arg, skipCharacters()); }
	template <class F> inline typename enable_if<is_floating_point<F>::value,
		bool>::type read(F& arg) { return id4(arg, skipCharacters()); }
	

	inline bool read(const char& arg) { skipCharacters([arg](char c) { return arg != c; }); return true; }
	inline bool read(const char* arg)
	{
		if(*arg) skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
		else skipCharacters();
		return putBack(), true;
	}
	inline bool read(bool (*isSkipped)(char)) { skipCharacters(isSkipped); putBack(); return true; }
	

	template <class I, class Terminator, class... Ts> inline typename enable_if<is_integral<I>::value,
		bool>::type read(char* arg, I limit, Terminator terminator, Ts&&... args)
	{
		readString(arg, static_cast<int>(limit), terminator);
		return read(forward<Ts>(args)...);
	}
	template <class I> inline typename enable_if<is_integral<I>::value,
		bool>::type read(char* arg, I limit) { return read(arg, limit, ""); }
	template <class... Ts>
	inline bool read(char* first, char* last, Ts&&... args)
	{
		return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
	}
	template <int N, class... Ts>
	inline bool read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
	template <class Terminator, class... Ts>
	inline bool read(string& arg, Terminator terminator, Ts&&... args)
	{
		for(int length = 16, last = 0;; last += length, length <<= 1)
		{
			arg.resize(last + length);
			int charsRead = readString(&arg[last], length + 1, terminator);
			if(charsRead < length)
			{
				arg.resize(last + charsRead);
				return read(forward<Ts>(args)...);
			}
		}
	}
	inline bool read(string& arg) { return read(arg, ""); }
	

	template <class T1, class T2>
	inline bool read(pair<T1, T2>& arg) { return read(arg.first, arg.second); }
	template <class T>
	inline bool read(complex<T>& arg)
	{
		T real, imag;
		if(!read(real, imag)) return false;
		arg.real(real), arg.imag(imag);
		return true;
	}
	template <class T>
	inline bool read(vector<T>& arg)
	{
		uint n;
		if(!read(n)) return false;
		arg.resize(n);
		return read(arg.begin(), arg.end());
	}
	template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
		bool>::type read(Iterator first, Iterator last, Ts&&... args)
	{
		for(; first != last; ++first) if(!read(*first)) return false;
		return read(forward<Ts>(args)...);
	}
	template <class Iterator, class I, class... Ts>
	inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
		bool>::type read(Iterator first, I count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
	

	template <class T>
	inline auto read(T& arg) -> decltype(arg.read(*this)) { return arg.read(*this); }
	template <class T0, class T1, class... Ts>
	inline typename enable_if<!is_iterator<T0>::value && !is_convertible<T0, char*>::value,
		bool>::type read(T0&& arg0, T1&& arg1, Ts&&... args)
	{
		return read(forward<T0>(arg0)) && read(forward<T1>(arg1), forward<Ts>(args)...);
	}
};

class InputFile : public InputDevice
{
	FILE* file;
	bool lineBuffered;
	bool owner;
	char buffer[BUFFER_SIZE];

	void fillInput() override
	{
		head = buffer;
		*buffer = '\0';
		if(__builtin_expect(!lineBuffered, true))
		{
			tail = head + fread(buffer, 1, BUFFER_SIZE, file);
		}
		else
		{
			tail = head;
			if(fgets(buffer, BUFFER_SIZE, file)) while(*tail) ++tail;
		}
	}

public:
	InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
		: InputDevice(buffer, buffer), file(file), lineBuffered(lineBuffered), owner(takeOwnership)
	{}
	InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
	~InputFile() { if(owner) fclose(file); }
};



class InputString : public InputDevice
{
	void fillInput() override { while(*tail) ++tail; }

public:
	InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
	InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};


class OutputDevice
{
protected:
	char buffer[BUFFER_SIZE + MAX_LENGTH];
	char* output;
	char* end;
	bool separate;

	OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false)
		, width(setWidth().value), fill(setFill().value), base(setBase().value), precision(setPrecision().value)
		, delimiter(setDelimiter().value)
	{
		computeBasePower();
	}

	virtual void writeToDevice(uint count) = 0;

	inline void flushMaybe()
	{
		if(__builtin_expect(output >= buffer + BUFFER_SIZE, false))
		{
			writeToDevice(BUFFER_SIZE);
			output = copy(buffer + BUFFER_SIZE, output, buffer);
		}
	}

	void computeBasePower()
	{
		basePower = 1;
		for(uint i = 0; i < precision; ++i) basePower *= base;
	}

	template <class I> inline char* id8(I arg, char* last)
	{
		if(__builtin_expect(arg == 0, false)) *--last = '0';
		if(__builtin_expect(base == 10, true))
		{
			for(; arg; arg /= 10) *--last = '0' + arg % 10;
		}
		else for(; arg; arg /= base)
		{
			I digit = arg % base;
			*--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
		}
		return last;
	}

	template <class I> inline char* id0(I arg, char* last)
	{
		auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
		if(arg < 0)
		{
			last = id8(~unsignedArg + 1, last);
			*--last = '-';
			return last;
		}
		return id8(unsignedArg, last);
	}

	template <class F> char* id7(F arg, char* last)
	{
		bool negative = signbit(arg);
		if(negative) arg = -arg;
		if(isnan(arg)) for(int i = 0; i < 3; ++i) *--last = i["NaN"];
		else if(isinf(arg)) for(int i = 0; i < 3; ++i) *--last = i["fnI"];
		else
		{
			auto integerPart = static_cast<unsigned long long>(arg);
			auto id11 = static_cast<unsigned long long>((arg - integerPart) * basePower + F(0.5));
			if(id11 >= basePower) ++integerPart, id11 = 0;
			char* point = last - precision;
			if(precision > 0)
			{
				::fill(point, id8(id11, last), '0');
				*--point = '.';
			}
			last = id8(integerPart, point);
		}
		if(negative) *--last = '-';
		return last;
	}

	inline int writeT(char* first)
	{
		int id2 = separate ? writeDelimiter() : 0;
		separate = true;
		uint charsWritten = static_cast<uint>(end - first);
		if(__builtin_expect(charsWritten < width, false))
			charsWritten += writeFill(width - charsWritten);
		output = copy(first, end, output);
		flushMaybe();
		return id2 + static_cast<int>(charsWritten);
	}

	inline int writeFill(uint count)
	{
		int charsWritten = static_cast<int>(count);
		if(__builtin_expect(output + count + MAX_LENGTH < end, true))
		{
			if(count == 1) *output++ = fill;
			else output = fill_n(output, count, fill);
		}
		else for(uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE)
		{
			if(chunkSize > count) chunkSize = count;
			output = fill_n(output, chunkSize, fill);
			flushMaybe();
			if((count -= chunkSize) == 0) break;
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

	inline int writeString(const char* arg, size_t length, bool checkWidth = true)
	{
		separate = false;
		uint count = static_cast<uint>(length);
		int charsWritten = static_cast<int>(count) + (checkWidth && count < width ? writeFill(width - count) : 0);
		if(__builtin_expect(output + count + MAX_LENGTH < end, true))
		{
			if(count == 1) *output++ = *arg;
			else output = copy_n(arg, count, output);
		}
		else for(uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE)
		{
			if(chunkSize > count) chunkSize = count;
			output = copy_n(arg, chunkSize, output);
			flushMaybe();
			if((count -= chunkSize) == 0) break;
			arg += chunkSize;
		}
		return charsWritten;
	}

	inline int writeDelimiter() { return writeString(delimiter.c_str(), delimiter.size(), false); }

	inline void flush()
	{
		writeToDevice(static_cast<uint>(output - buffer));
		output = buffer;
	}

	

	inline int write(Detail::Width newWidth) { width = newWidth.value; return 0; }
	inline int write(Detail::Fill newFill) { fill = newFill.value; return 0; }
	inline int write(Detail::Base newBase) { base = newBase.value; computeBasePower(); return 0; }
	inline int write(Detail::Precision newPrecision)
	{
		precision = newPrecision.value; computeBasePower(); return 0;
	}
	inline int write(Detail::Delimiter newDelimiter) { delimiter = newDelimiter.value; return 0; }
	

	inline int write() { return 0; }
	inline int write(char arg) { return writeChar(arg); }
	template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
		int>::type write(I arg) { return writeT(id8(arg, end)); }
	template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
		int>::type write(I arg) { return writeT(id0(arg, end)); }
	template <class F> inline typename enable_if<is_floating_point<F>::value,
		int>::type write(F arg) { return writeT(id7(arg, end)); }
	

	inline int write(const char* arg) { return writeString(arg, strlen(arg)); }
	template <int N>
	inline int write(char (&arg)[N]) { return writeString(arg, strlen(arg)); }
	inline int write(const string& arg) { return writeString(arg.c_str(), arg.size()); }
	template <class T1, class T2>
	inline int write(const pair<T1, T2>& arg)
	{
		int charsWritten = write(arg.first);
		charsWritten += writeDelimiter();
		return charsWritten + write(arg.second);
	}
	template <class T>
	inline int write(const complex<T>& arg) { return write(real(arg), imag(arg)); }
	

	template <class Iterator, class... Ts> inline typename enable_if<is_iterator<Iterator>::value,
		int>::type write(Iterator first, Iterator last, Ts&&... args)
	{
		int charsWritten = 0;
		for(; first != last; charsWritten += ++first == last ? 0 : writeDelimiter()) charsWritten += write(*first);
		return charsWritten + write(forward<Ts>(args)...);
	}
	template <class Iterator, class I, class... Ts>
	inline typename enable_if<is_iterator<Iterator>::value && is_integral<I>::value,
		int>::type write(Iterator first, I count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
	

	template <class T>
	inline auto write(const T& arg) -> decltype(arg.write(*this)) { return arg.write(*this); }
	template <class T0, class T1, class... Ts> inline typename enable_if<!is_iterator<T0>::value,
		int>::type write(T0&& arg0, T1&& arg1, Ts&&... args)
	{
		int charsWritten = write(forward<T0>(arg0));
		return charsWritten + write(forward<T1>(arg1), forward<Ts>(args)...);
	}
};

class OutputFile : public OutputDevice
{
	FILE* file;
	bool owner;

	void writeToDevice(uint count) override
	{
		fwrite(buffer, 1, count, file);
		fflush(file);
	}

public:
	OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
	OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
	~OutputFile() override { flush(); if(owner) fclose(file); }
};

class OutputString : public OutputDevice
{
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






class TimeTracker
{
	clock_t start, end;
public:
	TimeTracker ()
	{
		start = clock ();
	}
	~TimeTracker ()
	{
		end = clock ();
		fprintf (stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
};



template <typename InputIt>
struct key_it : public InputIt
{
	key_it(InputIt it) : InputIt(it) {}
	auto operator*() { return (*this)->first; }
};


template <typename InputIt>
key_it<InputIt> id6(InputIt it)
{
	return{it};
}






	

const int N = 1001;
int n, m;
char s[N][N];
int a[N], b[N];

int main()
{

	

	input.reset(new InputFile());					

	output.reset(new OutputFile());					

	


	input.reset(new InputFile(stdin, false));		

	

	output.reset(new OutputFile());


	int n{}, t{}, ans{2}, x{}, a{};
	vector<pair<int, int>>v{};
	v.reserve(n);
	read(n, t);
	t <<= 1;
	for(int i = 0; i < n; i++)
	{
		read(x, a);
		v.push_back({2*x - a, 2*x + a});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < (int)v.size(); i++)
	{
		if(v[i].first - v[i-1].second == t)
			++ans;
		else if(v[i].first - v[i-1].second > t)
			ans += 2;
	}
	writeln(ans);


	flush();
	cerr << endl << endl << static_cast<double>(clock()) / CLOCKS_PER_SEC << endl;


	return 0;
}


