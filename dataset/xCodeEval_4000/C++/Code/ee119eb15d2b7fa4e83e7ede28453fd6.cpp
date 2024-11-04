#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <vector>



typedef std::vector<size_t> Permutation;

Permutation inverse(const Permutation& permutation) {
    Permutation result(permutation.size());
    for (size_t i = 0; i < permutation.size(); ++i) {
        result.at(permutation[i]) = i;
    }
    return result;
}



Permutation composition(const Permutation& external, const Permutation& internal) {
    if (external.size() != internal.size()) {
        throw std::runtime_error("Cannot compose permutations of different sizes");
    }
    const size_t size = external.size();
    Permutation result(size);
    for (size_t i = 0; i < size; ++i) {
        result[i] = external[internal[i]];
    }
    return result;
}



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

bool isEmpty(const Range& range) {
    return range.begin >= range.end;
}

bool operator == (const Range& first, const Range& second) {
    return (isEmpty(first) && isEmpty(second)) ||
        (first.begin == second.begin && first.end == second.end);
}



 template<class T>
struct Point {
    typedef T Coordinate;

    Point(T x, T y)
        : x(x), y(y)
    {}

    T x;
    T y;
};





size_t nextPowerOfTwo(size_t number) {
    if (number >= std::numeric_limits<size_t>::max() / 2) {
        throw std::runtime_error("Next power of two exceeds type limit");
    }
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

    static LinePartition unite(const LinePartition& first, const LinePartition& second) {
        LinePartition result;
        auto& points = result.points_;
        points.resize(first.nPoints() + second.nPoints());
        std::merge(
            first.points_.begin(), first.points_.end(),
            second.points_.begin(), second.points_.end(),
            points.begin()
            );
        points.erase(std::unique(points.begin(), points.end()), points.end());
        return result;
    }

    template<class Iterator>
    void assign(Iterator begin, Iterator end) {
        points_.assign(begin, end);
        std::sort(points_.begin(), points_.end());
        points_.erase(std::unique(points_.begin(), points_.end()), points_.end());
    }

    size_t nPoints() const {
        return points_.size();
    }

    size_t partIndex(const T& point) const {
        return std::distance(
            points_.begin(),
            std::lower_bound(points_.begin(), points_.end(), point)
            );
    }

private:
    std::vector<T> points_;
};

 template<class Coordinate>
class ImmutableSegmentTree2DBuilder;





 template<class Coordinate_>
class ImmutableSegmentTree2D {
public:
    typedef Coordinate_ Coordinate;
    typedef ::Point<Coordinate> Point;

    size_t countPoints(
            Coordinate xBegin, Coordinate xEnd,
            Coordinate yBegin, Coordinate yEnd) const {
        if (size_ == 0) {
            return 0;
        }

        const Range rootRange(0, size_);
        const Range queryRange(
                xPartition_.partIndex(xBegin),
                xPartition_.partIndex(xEnd)
                );
        return countPoints(ROOT_INDEX, rootRange, queryRange, yEnd)
            - countPoints(ROOT_INDEX, rootRange, queryRange, yBegin);
    }

private:
    ImmutableSegmentTree2D() :
        size_(0)
    {}

    ImmutableSegmentTree2D(
            size_t size,
            const LinePartition<Coordinate>& xPartition,
            const std::vector<LinePartition<Coordinate>>& segments) :
        size_(size),
        xPartition_(xPartition),
        segments_(segments)
    {}

    friend class ImmutableSegmentTree2DBuilder<Coordinate>;

    static const size_t ROOT_INDEX = 1;

    static size_t leftChildIndex(size_t index) {
        return 2 * index;
    }

    static size_t rightChildIndex(size_t index) {
        return 2 * index + 1;
    }

    size_t countPoints(
                size_t index,
                const Range& segmentRange,
                const Range& queryRange,
                Coordinate yEnd) const {
        if (queryRange.begin >= queryRange.end) {
            return 0;
        }
        if (segmentRange == queryRange) {
            return segments_.at(index).partIndex(yEnd);
        }

        const size_t middle = (segmentRange.begin + segmentRange.end) / 2;
        return countPoints(leftChildIndex(index), Range(segmentRange.begin, middle),
                Range(queryRange.begin, std::min(queryRange.end, middle)), yEnd)
            + countPoints(rightChildIndex(index), Range(middle, segmentRange.end),
                Range(std::max(queryRange.begin, middle), queryRange.end), yEnd);

    }

    

    

    size_t size_;
    LinePartition<Coordinate> xPartition_;
    std::vector<LinePartition<Coordinate>> segments_;
};

 template<class Coordinate>
class ImmutableSegmentTree2DBuilder {
public:
    typedef ImmutableSegmentTree2D<Coordinate> SegmentTree;
    typedef ::Point<Coordinate> Point;

    template<class PointIterator>
    SegmentTree build(PointIterator begin, PointIterator end) {
        LinePartition<Coordinate> xPartition;
        std::vector<Point> points(begin, end);
        {
            

            std::vector<Coordinate> xs(points.size());
            std::transform(points.begin(), points.end(), xs.begin(),
                [] (const Point& point) { return point.x; });
            xPartition.assign(xs.begin(), xs.end());
        }

        const size_t size = nextPowerOfTwo(xPartition.nPoints() + 1);
        std::vector<LinePartition<Coordinate>> segments(2 * size);
        {
            

            std::vector<std::vector<Coordinate>> ys(size);
            for (const Point& point: points) {
                ys.at(xPartition.partIndex(point.x)).push_back(point.y);
            }
            for (size_t i = 0; i < size; ++i) {
                segments.at(size + i).assign(ys[i].begin(), ys[i].end());
            }
        }
        for (size_t i = size - 1; i > 0; --i) {
            segments.at(i) = LinePartition<Coordinate>::unite(
                segments.at(SegmentTree::leftChildIndex(i)),
                segments.at(SegmentTree::rightChildIndex(i))
                );
        }
        return SegmentTree(size, xPartition, segments);
    }
};

template<class PointIterator>
ImmutableSegmentTree2D<typename std::iterator_traits<PointIterator>::value_type::Coordinate>
buildImmutableSegmentTree2D(PointIterator begin, PointIterator end) {
    return ImmutableSegmentTree2DBuilder<
        typename std::iterator_traits<PointIterator>::value_type::Coordinate
        >().build(begin, end);
}









class PermutationImageAnalyzer {
public:
    size_t countNumbers(
            size_t rangeBegin, size_t rangeEnd,
            size_t imageBegin, size_t imageEnd) const {
        return segmentTree_.countPoints(
                rangeBegin, rangeEnd, imageBegin, imageEnd);
    }

private:
    typedef ImmutableSegmentTree2D<int> SegmentTree;

    explicit PermutationImageAnalyzer(const SegmentTree& segmentTree) :
        segmentTree_(segmentTree)
    {}

    friend class PermutationImageAnalyzerBuilder;

    SegmentTree segmentTree_;
};

class PermutationImageAnalyzerBuilder {
public:
    PermutationImageAnalyzer build(const Permutation& permutation) {
        std::vector<Point<int>> points;
        points.reserve(permutation.size());
        for (size_t i = 0; i < permutation.size(); ++i) {
            points.emplace_back(i, permutation[i]);
        }
        auto segmentTree = buildImmutableSegmentTree2D(points.begin(), points.end());
        return PermutationImageAnalyzer(segmentTree);

    }
};

PermutationImageAnalyzer buildPermutationImageAnalyzer(
        const Permutation& permutation) {
    return PermutationImageAnalyzerBuilder().build(permutation);
}

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


template<class Analyzer>
void processQueries(const Analyzer& analyzer, size_t size) {
    const size_t nQueries = readSize();
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
#ifdef TEST_MODE
    return testAll();
#endif

    std::ios::sync_with_stdio(false);

    size_t size = readSize();
    Permutation firstPermutation = readPermutation(size);
    Permutation secondPermutation = readPermutation(size);
    Permutation singlePermutation = composition(
            inverse(secondPermutation), firstPermutation
            );

    PermutationImageAnalyzer analyzer = buildPermutationImageAnalyzer(singlePermutation);
    processQueries(analyzer, size);

    return 0;
}





#include <cstdlib>
#include <sstream>
#include <string>



class TrivialAnalyzer {
public:
    explicit TrivialAnalyzer(const Permutation& permutation) :
        permutation_(permutation)
    {}

        size_t countNumbers(
            size_t rangeBegin, size_t rangeEnd,
            size_t imageBegin, size_t imageEnd) const {
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

    explicit TestNotPassedException(const std::string& what) :
        std::runtime_error(what.c_str())
    {}
};

std::ostream& operator << (std::ostream& os, const Permutation& permutation) {
    std::copy(
        permutation.begin(),
        permutation.end(),
        std::ostream_iterator<size_t>(os, " ")
        );
    return os;
}

class Tester {
public:
    explicit Tester(const Permutation& permutation) :
        analyzer_(buildPermutationImageAnalyzer(permutation)),
        trivialAnalyzer_(permutation),
        permutation_(permutation)
    {}

    

    void operator() (
            size_t rangeBegin, size_t rangeEnd,
            size_t imageBegin, size_t imageEnd) const {
        const size_t count = analyzer_.countNumbers(
                rangeBegin, rangeEnd,
                imageBegin, imageEnd
                );
        const size_t correctCount = trivialAnalyzer_.countNumbers(
                rangeBegin, rangeEnd,
                imageBegin, imageEnd
                );
        if (count != correctCount) {
            std::ostringstream oss;
            oss << "Test not passed: got answer " << count
                << " while the correct one is " << correctCount
                << " for the mapping"
                << " of [" << rangeBegin << ", " << rangeEnd << ")"
                << " to [" << imageBegin << ", " << imageEnd << ");"
                << "\n\tthe permutation is " << permutation_ << "\n";
            throw TestNotPassedException(oss.str());
        }
    }

    size_t size() const {
        return permutation_.size();
    }

private:
    PermutationImageAnalyzer analyzer_;
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
        oss << "Require equal failed: " << # first << " != " << # second \
            << " (" << firstValue << " != " << secondValue << ")\n"; \
        throw TestNotPassedException(oss.str()); \
    } \
    } while (false)

void testTrivialAnalyzer(size_t nTests) {
    const size_t PERMUTATION[] = {0, 4, 3, 2, 1};
    const TrivialAnalyzer analyzer(
            Permutation(std::begin(PERMUTATION), std::end(PERMUTATION)));
    const size_t size = std::distance(std::begin(PERMUTATION), std::end(PERMUTATION));
    for (size_t iTest = 0; iTest < nTests; ++iTest) {
        const Range range = randomRange(size);
        for (size_t begin = 0; begin < size; ++begin) {
            

            REQUIRE_EQUAL(
                analyzer.countNumbers(begin, begin, range.begin, range.end),
                0
                );
            

            REQUIRE_EQUAL(
                analyzer.countNumbers(range.begin, range.end, begin, begin),
                0
                );
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
        testTrivialAnalyzer(100);
        testIdentityPermutations(10, 100);
        testRandomPermutations(6, 100, 30);
        testRandomPermutations(10, 100, 20);
        testRandomPermutations(30, 100, 10);
        testRandomPermutations(100, 10, 20);
        testRandomPermutations(1000, 10, 5);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << "\n";
        return 1;
    }
    return 0;
}
