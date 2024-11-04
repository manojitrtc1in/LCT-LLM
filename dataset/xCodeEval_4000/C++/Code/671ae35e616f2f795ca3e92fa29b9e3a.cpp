#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <cassert>
#include <functional>
#include <utility>
#include <stdexcept>

typedef std::vector<size_t> Permutation;

Permutation inverse(const Permutation& permutation) {
	Permutation result(permutation.size());
	for (size_t i = 0; i < permutation.size(); ++i) {
		result[permutation[i]] = i;
	}
	return result;
}


class ImmutableSummator {
public:
	typedef long long value_type;
	
	template<class Iterator>
	ImmutableSummator(Iterator begin, Iterator end)
		: partialSums_(1, 0)
	{
        

        

        partialSums_.insert(partialSums_.end(), begin, end);
		std::partial_sum(partialSums_.begin(), partialSums_.end(), partialSums_.begin());
	}

	value_type operator() (size_t begin, size_t end) const {
        return partialSums_.at(end) - partialSums_.at(begin);
	}

private:
	std::vector<value_type> partialSums_;
};

struct Range {
    

    Range() :
        begin(0),
        end(0)
    {}

    Range(size_t begin, size_t end) :
        begin(begin),
        end(end)
    {}

    size_t begin;
    size_t end;
};

bool operator == (const Range& first, const Range& second) {
    return first.begin == second.begin && first.end == second.end;
}

struct Decomposition {
    Range prefix;
    Range blocks;
    Range suffix;
};



class BlockIndexer {
public:
	explicit BlockIndexer(size_t size) :
		size_(size),
		blockSize_(static_cast<size_t>(std::sqrt(size)))
	{}

	size_t begin(size_t index) const {
		return index * blockSize_;
	}

	size_t end(size_t index) const {
		return std::min(size_, (index + 1) * blockSize_);
	}

	size_t index(size_t position) const {
		return position / blockSize_;
	}

	size_t totalNumber() const {
		return (size_ - 1) / blockSize_ + 1;
	}

    Decomposition decompose(size_t beginIndex, size_t endIndex) const {
        Decomposition decomposition;
        if (beginIndex >= endIndex) {
            return decomposition;
        }

        const size_t firstBlockIndex = index(beginIndex);
        const size_t lastBlockIndex = index(endIndex - 1);

        if (firstBlockIndex == lastBlockIndex) {
            decomposition.prefix = Range(beginIndex, endIndex);
        } else {
            decomposition.prefix = Range(beginIndex, end(firstBlockIndex));
            decomposition.blocks = Range(firstBlockIndex + 1, lastBlockIndex);
            decomposition.suffix = Range(begin(lastBlockIndex), endIndex);
        }
        return decomposition;
    }


private:
	size_t size_;
	size_t blockSize_;
};

class Matrix {
public:
	typedef int value_type;
	typedef std::vector<value_type>::const_iterator const_iterator;

	Matrix(size_t width, size_t height)
		: data_(width, std::vector<value_type>(height))
	{}

	value_type operator() (size_t column, size_t row) const {
		return data_[column][row];
	}

	value_type& operator() (size_t column, size_t row) {
		return data_[column][row];
	}

	const_iterator columnBegin(size_t column) const {
		return data_[column].begin();
	}

	const_iterator columnEnd(size_t column) const {
		return data_[column].end();
	}

	size_t width() const {
		return data_.size();
	}

	size_t height() const {
		return data_.empty() ? 0 : data_.front().size();
	}

private:
	std::vector<std::vector<value_type>> data_;
};

class ImmutableColumnSummator {
public:
	typedef ImmutableSummator::value_type value_type;

	explicit ImmutableColumnSummator(const Matrix& matrix) {
		columnSummators_.reserve(matrix.width());
		for (size_t column = 0; column < matrix.width(); ++column) {
			columnSummators_.push_back(ImmutableSummator(
				matrix.columnBegin(column), matrix.columnEnd(column)
				));
		}
	}

	value_type operator() (size_t column, size_t beginRow, size_t endRow) const {
		return columnSummators_.at(column)(beginRow, endRow);
	}

private:
	std::vector<ImmutableSummator> columnSummators_;
};

Matrix calculateNumbersForBlocks(const Permutation& permutation, const BlockIndexer& indexer) {
	Matrix matrix(indexer.totalNumber(), indexer.totalNumber());
	for (size_t i = 0; i < permutation.size(); ++i) {
		matrix(indexer.index(i), indexer.index(permutation[i])) += 1;
	}
	return matrix;
}

size_t countNumbersTrivially(const Permutation& permutation,
		size_t rangeBegin, size_t rangeEnd, size_t imageBegin, size_t imageEnd)
{
    if (imageBegin >= imageEnd) {
        return 0;
    }

	size_t count = 0;
	for (size_t index = rangeBegin; index < rangeEnd; ++index) {
		const size_t image = permutation[index];
		if (imageBegin <= image && image < imageEnd) {
			++count;
		}
	}
	return count;
}


class PermutationImageAnalyzer {
public:
	typedef size_t value_type;

	explicit PermutationImageAnalyzer(const Permutation& permutation) :
		permutation_(permutation),
		inversePermutation_(inverse(permutation)),
		blockIndexer_(permutation.size()),
		blocksSummator_(calculateNumbersForBlocks(permutation, blockIndexer_))
		{}


	size_t countNumbers(size_t rangeBegin, size_t rangeEnd, size_t imageBegin, size_t imageEnd) const {
        const Decomposition rangeDecomposition = blockIndexer_.decompose(rangeBegin, rangeEnd);
        const Decomposition imageDecomposition = blockIndexer_.decompose(imageBegin, imageEnd);

		value_type count = 0;
        

        Range ranges[2] = {rangeDecomposition.prefix, rangeDecomposition.suffix};
        for (const Range& range: ranges) {
            count += countNumbersTrivially(permutation_, range.begin, range.end, imageBegin, imageEnd);
        }

		for (size_t blockIndex = rangeDecomposition.blocks.begin; blockIndex < rangeDecomposition.blocks.end; ++blockIndex) {
			count += static_cast<size_t>(
                blocksSummator_(blockIndex, imageDecomposition.blocks.begin, imageDecomposition.blocks.end)
                );
		}

        if (rangeDecomposition.blocks.end > 0) {
            ranges[0] = imageDecomposition.prefix; ranges[1] = imageDecomposition.suffix;
            for (const Range& range: ranges) {
                count += countNumbersTrivially(permutation_,
                    blockIndexer_.begin(rangeDecomposition.blocks.begin),
                    blockIndexer_.end(rangeDecomposition.blocks.end - 1),
                    range.begin, range.end
                    );
            }
        }

        return count;
	}

private:
	Permutation permutation_;
	Permutation inversePermutation_;
	BlockIndexer blockIndexer_;
	ImmutableColumnSummator blocksSummator_;
};

size_t readSize(std::istream& inputStream = std::cin) {
	size_t size;
	inputStream >> size;
	return size;
}

Permutation readPermutation(size_t size, std::istream& inputStream = std::cin) {
	Permutation permutation(size);
	for (size_t& element: permutation) {
		inputStream >> element;
        

        

		--element;
	}
	return permutation;
}

Permutation composition(const Permutation& external, const Permutation& internal) {
	assert(external.size() == internal.size());
	const size_t size = external.size();
	Permutation result(size);
	for (size_t i = 0; i < size; ++i) {
		result[i] = external[internal[i]];
	}
	return result;
}


struct IntPoint {
    IntPoint()
    {}

    IntPoint(int x, int y)
        : x(x), y(y)
    {}

    int x;
    int y;
};

struct LessByX {
    bool operator() (const IntPoint& first, const IntPoint& second) const {
        return first.x < second.x;
    }
};

size_t nextPowerOfTwo(size_t number) {
    size_t result = 1;
    while (result < number) {
        result <<= 1;
    }
    return result;
}

template<class T>
class LinePartition {
public:
    LinePartition()
    {}

    template<class Iterator>
    LinePartition(Iterator begin, Iterator end) {
        assign(begin, end);
    }

    template<class Iterator>
    void assign(Iterator begin, Iterator end) {
        points_.assign(begin, end);
        std::sort(points_.begin(), points_.end());
        points_.erase(std::unique(points_.begin(), points_.end()), points_.end());
    }
    
    std::ptrdiff_t partIndex(const T& point) const {
        return std::distance(
            points_.begin(),
            std::lower_bound(points_.begin(), points_.end(), point)
            );
    }

private:
    std::vector<T> points_;
};

class ImmutableSegmentTree2D {
public:
    ImmutableSegmentTree2D()
    {}

    template<class Iterator>
    ImmutableSegmentTree2D(Iterator begin, Iterator end) {
        assign(begin, end);
    }

    template<class Iterator>
    void assign(Iterator begin, Iterator end) {
        std::vector<IntPoint> points(begin, end);
        {
            std::vector<int> coords(points.size());
            std::transform(points.begin(), points.end(), coords.begin(),
                [] (const IntPoint& point) { return point.x; });
            xPartition_.assign(coords.begin(), coords.end());
        }

        size_ = nextPowerOfTwo(points.size());
        segments_.resize(2 * size_);
        for (const IntPoint& point: points) {
            segments_.at(size_ + xIndex(point.x)).push_back(point.y);
        }
        for (size_t i = size_ - 1; i > 0; --i) {
            recalculate(i);       
        }
    }

    size_t countPoints(int xBegin, int xEnd, int yBegin, int yEnd) const {
        const Range rootRange(0, size_);
        const Range queryRange(xIndex(xBegin), xIndex(xEnd));
        return countPoints(ROOT_INDEX, rootRange, queryRange, yEnd)
            - countPoints(ROOT_INDEX, rootRange, queryRange, yBegin);
    }

private:
    static const int ROOT_INDEX;

    typedef std::vector<int> SegmentData;

    static size_t leftChildIndex(size_t index) {
        return 2 * index;
    }

    static size_t rightChildIndex(size_t index) {
        return 2 * index + 1;
    }

    void recalculate(size_t index) {
        const SegmentData& leftChild = segments_.at(leftChildIndex(index));
        const SegmentData& rightChild = segments_.at(rightChildIndex(index));
        SegmentData& segment = segments_.at(index);
        segment.resize(leftChild.size() + rightChild.size());
        std::merge(
            leftChild.begin(), leftChild.end(),
            rightChild.begin(), rightChild.end(),
            segment.begin()
            );
    }

    size_t countPoints(size_t index, const Range& segmentRange, const Range& queryRange, int yEnd) const {
        if (queryRange.begin >= queryRange.end) {
            return 0;
        }
        if (segmentRange == queryRange) {
            const SegmentData& segmentData = segments_[index];
            return std::distance(
                segmentData.begin(),
                std::lower_bound(segmentData.begin(), segmentData.end(), yEnd)
                );
        }
        const size_t middle = (segmentRange.begin + segmentRange.end) / 2;
        return countPoints(leftChildIndex(index), Range(segmentRange.begin, middle),
                Range(queryRange.begin, std::min(queryRange.end, middle)), yEnd)
            + countPoints(rightChildIndex(index), Range(middle, segmentRange.end),
                Range(std::max(queryRange.begin, middle), queryRange.end), yEnd);

    }


    size_t xIndex(int x) const {
        return xPartition_.partIndex(x);
    }

    LinePartition<int> xPartition_;
    size_t size_;
    std::vector<SegmentData> segments_;
};

const int ImmutableSegmentTree2D::ROOT_INDEX = 1;


class FastImageAnalyzer {
public:
    explicit FastImageAnalyzer(const Permutation& permutation)
    {
        std::vector<IntPoint> points(permutation.size());
        for (size_t i = 0; i < permutation.size(); ++i) {
            points[i] = IntPoint(i, permutation[i]);
        }
        segmentTree_.assign(points.begin(), points.end());
    }

	size_t countNumbers(size_t rangeBegin, size_t rangeEnd, size_t imageBegin, size_t imageEnd) const {
        return segmentTree_.countPoints(rangeBegin, rangeEnd, imageBegin, imageEnd);
    }

private:
    ImmutableSegmentTree2D segmentTree_;
    size_t size_;
};

template<class Analyzer>
void processQueries(const Analyzer& analyzer, size_t size) {
	size_t nQueries = readSize();
	size_t x = 0;
	auto f = [&x, size] (size_t z) { return (z + x - 1) % size; };
	for (size_t iQuery = 0; iQuery < nQueries; ++iQuery) {
		size_t a, b, c, d;
		std::cin >> a >> b >> c >> d;
		size_t count = analyzer.countNumbers(
			std::min(f(a), f(b)), std::max(f(a), f(b)) + 1,
			std::min(f(c), f(d)), std::max(f(c), f(d)) + 1
			);
		std::cout << count << "\n";
		x = count + 1;
	}
}

int testAll();

int main() {
#if 0
    return testAll();
#endif

	std::ios::sync_with_stdio(false);

#if 0
	std::ifstream fin("test01.in");
	if (!fin.is_open()) {
		throw std::runtime_error("Could not open test file");
	}
	std::cin.rdbuf(fin.rdbuf());
#endif
	size_t size = readSize();
	Permutation firstPermutation = readPermutation(size);
	Permutation secondPermutation = readPermutation(size);
	Permutation singlePermutation = composition(inverse(secondPermutation), firstPermutation);

	FastImageAnalyzer analyzer(singlePermutation);
	processQueries(analyzer, size);

	return 0;
}




class TrivialAnalyzer {
public:
    explicit TrivialAnalyzer(const Permutation& permutation) :
        permutation_(permutation)
    {}

	size_t countNumbers(size_t rangeBegin, size_t rangeEnd, size_t imageBegin, size_t imageEnd) const {
        size_t count = 0;
        for (size_t i = rangeBegin; i < rangeEnd; ++i) {
            const size_t image = permutation_.at(i);
            count += static_cast<size_t>(imageBegin <= image && image < imageEnd);
        }
        return count;
    }

private:
    Permutation permutation_;
};


class TestNotPassedException : public std::runtime_error {
public:
    explicit TestNotPassedException(const char* what) :
        std::runtime_error(what)
    {}
};

namespace std {
    ostream& operator << (ostream& os, const Permutation& permutation) {
        std::copy(permutation.begin(), permutation.end(), std::ostream_iterator<size_t>(os, " "));
        return os;
    }
} 


class Tester {
public:
    explicit Tester(const Permutation& permutation) :
        analyzer_(permutation),
        fastAnalyzer_(permutation),
        trivialAnalyzer_(permutation),
        permutation_(permutation)
    {}

    

    void operator() (size_t rangeBegin, size_t rangeEnd, size_t imageBegin, size_t imageEnd) const {
        const size_t count = fastAnalyzer_.countNumbers(rangeBegin, rangeEnd, imageBegin, imageEnd);
        const size_t correctCount = trivialAnalyzer_.countNumbers(rangeBegin, rangeEnd, imageBegin, imageEnd);
        if (count != correctCount) {
            std::ostringstream oss;          
            oss << "Test not passed: got answer " << count << " while the correct one is " << correctCount
                << " for the mapping of [" << rangeBegin << ", " << rangeEnd << ") to ["
                << imageBegin << ", " << imageEnd << "); \n\tthe permutation is " << permutation_ << "\n";
            throw TestNotPassedException(oss.str().c_str());
        }
    }

    size_t size() const {
        return permutation_.size();
    }

private:
    PermutationImageAnalyzer analyzer_;
    FastImageAnalyzer fastAnalyzer_;
    TrivialAnalyzer trivialAnalyzer_;
    Permutation permutation_;
};

int randomInt(int begin, int end) {
    return rand() % (end - begin) + begin;
}

Range randomRange(size_t size) {
    size_t begin = randomInt(0, size);
    size_t end = randomInt(begin, size);
    return Range(begin, end);
}

void performRandomTest(const Tester& tester) {
    int size = tester.size();
    Range range = randomRange(size);
    Range image = randomRange(size);
    tester(range.begin, range.end, image.begin, image.end);
}

void testIdentityPermutations(size_t maxSize, size_t nTests) {
    for (size_t size = 1; size <= maxSize; ++size) {
        Permutation permutation(size);
        std::iota(permutation.begin(), permutation.end(), 0);
        Tester tester(permutation);
        for (size_t iTest = 0; iTest < nTests; ++iTest) {
            performRandomTest(tester);
        }
    }
}

void testRandomPermutations(size_t maxSize, size_t nPermutations, size_t nTestsEach) {
    for (size_t iPermutation = 0; iPermutation < nPermutations; ++iPermutation) {
        const size_t size = randomInt(2, maxSize);
        Permutation permutation(size);
        std::iota(permutation.begin(), permutation.end(), 0);
        std::random_shuffle(permutation.begin(), permutation.end());
        Tester tester(permutation);
        for (size_t iTest = 0; iTest < nTestsEach; ++iTest) {
            performRandomTest(tester);
        }
    }
}

#define REQUIRE_EQUAL(first, second) do { \
    auto firstValue = (first); \
    auto secondValue = (second); \
    if (firstValue != secondValue) { \
        std::ostringstream oss; \
        oss << "Require equal failed: " << firstValue << " != " << secondValue << "\n"; \
        throw std::runtime_error(oss.str().c_str()); \
    } \
    } \
    while (false)

void testTrivialAnalyzer() {
    const size_t PERMUTATION[] = {0, 4, 3, 2, 1};
    const TrivialAnalyzer analyzer(Permutation(std::begin(PERMUTATION), std::end(PERMUTATION)));
    const size_t size = std::distance(std::begin(PERMUTATION), std::end(PERMUTATION));
    for (size_t iTest = 0; iTest < 100; ++iTest) {
        const Range range = randomRange(size);
        for (size_t begin = 0; begin < size; ++begin) {
            REQUIRE_EQUAL(analyzer.countNumbers(begin, begin, range.begin, range.end), 0);
            REQUIRE_EQUAL(analyzer.countNumbers(range.begin, range.end, begin, begin), 0);
        }
    }
    REQUIRE_EQUAL(analyzer.countNumbers(0, 1, 0, 3), 1);
    REQUIRE_EQUAL(analyzer.countNumbers(0, 1, 0, 1), 1);
    REQUIRE_EQUAL(analyzer.countNumbers(0, 5, 0, 3), 3);
    REQUIRE_EQUAL(analyzer.countNumbers(1, 3, 0, 5), 2);
    REQUIRE_EQUAL(analyzer.countNumbers(1, 4, 1, 4), 2);
    REQUIRE_EQUAL(analyzer.countNumbers(2, 5, 1, 4), 3);
}



int testAll() {
    std::srand(1543);

    try {
        testTrivialAnalyzer();
        testIdentityPermutations(10, 100);
        testRandomPermutations(6, 100, 30);
        testRandomPermutations(10, 100, 20);
        testRandomPermutations(30, 100, 10);
        testRandomPermutations(100, 10, 20);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << "\n";
        return 1;
    }
    return 0;

}