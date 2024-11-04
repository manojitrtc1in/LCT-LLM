










typedef std::vector<size_t> Permutation;

Permutation Inverse(const Permutation &permutation) {
  Permutation result(permutation.size());
  for (size_t i = 0; i < permutation.size(); ++i) {
    result.at(permutation[i]) = i;
  }
  return result;
}



Permutation Composition(const Permutation &external,
                        const Permutation &internal) {
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
  

  Range() : begin(0), end(0) {}

  Range(size_t begin, size_t end) : begin(begin), end(end) {}

  size_t begin;
  size_t end;
};

bool is_empty(const Range &range) { return range.begin >= range.end; }

bool operator==(const Range &first, const Range &second) {
  return (is_empty(first) && is_empty(second)) ||
         (first.begin == second.begin && first.end == second.end);
}



template <class T>
struct Point {
  typedef T Coordinate;

  Point(T x, T y) : x(x), y(y) {}

  T x;
  T y;
};







size_t id4(size_t number) {
  if (number >= std::numeric_limits<size_t>::max() / 2) {
    throw std::runtime_error("Next power of two exceeds type limit");
  }
  size_t result = 1;
  while (result < number) {
    result <<= 1;
  }
  return result;
}





















template <class T>
class LinePartition {
 public:
  LinePartition() = default;

  template <class Iterator>
  LinePartition(Iterator begin, Iterator end) {
    Assign(begin, end);
  }

  static LinePartition Unite(const LinePartition &first,
                             const LinePartition &second) {
    LinePartition result;
    auto &points = result.points_;
    points.resize(first.num_points() + second.num_points());
    std::merge(first.points_.begin(), first.points_.end(),
               second.points_.begin(), second.points_.end(), points.begin());
    points.erase(std::unique(points.begin(), points.end()), points.end());
    return result;
  }

  template <class Iterator>
  void Assign(Iterator begin, Iterator end) {
    points_.assign(begin, end);
    std::sort(points_.begin(), points_.end());
    points_.erase(std::unique(points_.begin(), points_.end()), points_.end());
  }

  size_t num_points() const { return points_.size(); }

  size_t part_index(const T &point) const {
    return std::distance(
        points_.begin(),
        std::lower_bound(points_.begin(), points_.end(), point));
  }

 private:
  std::vector<T> points_;
};

template <class Coordinate>
class ImmutableSegmentTree2DBuilder;





template <class Coordinate>
class id1 {
 public:
  typedef ::Point<Coordinate> Point;

  size_t CountPoints(Coordinate x_begin, Coordinate x_end, Coordinate y_begin,
                     Coordinate y_end) const {
    if (size_ == 0) {
      return 0;
    }

    const Range root_range(0, size_);
    const Range query_range(x_partition_.part_index(x_begin),
                            x_partition_.part_index(x_end));
    return CountPoints(kRootIndex, root_range, query_range, y_end) -
           CountPoints(kRootIndex, root_range, query_range, y_begin);
  }

 private:
  id1() : size_(0) {}

  id1(size_t size,
                         const LinePartition<Coordinate> &x_partition,
                         const std::vector<LinePartition<Coordinate>> &segments)
      : size_(size), x_partition_(x_partition), segments_(segments) {}

  friend class ImmutableSegmentTree2DBuilder<Coordinate>;

  static const size_t kRootIndex = 1;

  static size_t left_child_index(size_t index) { return 2 * index; }

  static size_t right_child_index(size_t index) { return 2 * index + 1; }

  size_t CountPoints(size_t index, const Range &segment_range,
                     const Range &query_range, Coordinate y_end) const {
    if (query_range.begin >= query_range.end) {
      return 0;
    }
    if (segment_range == query_range) {
      return segments_.at(index).part_index(y_end);
    }

    const size_t middle = (segment_range.begin + segment_range.end) / 2;
    return CountPoints(
               left_child_index(index), Range(segment_range.begin, middle),
               Range(query_range.begin, std::min(query_range.end, middle)),
               y_end) +
           CountPoints(
               right_child_index(index), Range(middle, segment_range.end),
               Range(std::max(query_range.begin, middle), query_range.end),
               y_end);
  }

  

  

  size_t size_;
  LinePartition<Coordinate> x_partition_;
  std::vector<LinePartition<Coordinate>> segments_;
};

template <class Coordinate>
class ImmutableSegmentTree2DBuilder {
 public:
  typedef id1<Coordinate> SegmentTree;
  typedef ::Point<Coordinate> Point;

  template <class PointIterator>
  SegmentTree Build(PointIterator begin, PointIterator end) {
    LinePartition<Coordinate> x_partition;
    std::vector<Point> points(begin, end);
    {
      

      std::vector<Coordinate> xs(points.size());
      std::transform(points.begin(), points.end(), xs.begin(),
                     [](const Point &point) { return point.x; });
      x_partition.Assign(xs.begin(), xs.end());
    }

    const size_t size = id4(x_partition.num_points() + 1);
    std::vector<LinePartition<Coordinate>> segments(2 * size);
    {
      

      std::vector<std::vector<Coordinate>> ys(size);
      for (const Point &point : points) {
        ys.at(x_partition.part_index(point.x)).push_back(point.y);
      }
      for (size_t i = 0; i < size; ++i) {
        segments.at(size + i).Assign(ys[i].begin(), ys[i].end());
      }
    }
    for (size_t i = size - 1; i > 0; --i) {
      segments.at(i) = LinePartition<Coordinate>::Unite(
          segments.at(SegmentTree::left_child_index(i)),
          segments.at(SegmentTree::right_child_index(i)));
    }
    return SegmentTree(size, x_partition, segments);
  }
};

template <class PointIterator>
id1<
    typename std::iterator_traits<PointIterator>::value_type::Coordinate>
id6(PointIterator begin, PointIterator end) {
  return ImmutableSegmentTree2DBuilder<typename std::iterator_traits<
      PointIterator>::value_type::Coordinate>()
      .Build(begin, end);
}









class id3 {
 public:
  size_t CountNumbers(size_t range_begin, size_t range_end, size_t image_begin,
                      size_t image_end) const {
    return segment_tree_.CountPoints(range_begin, range_end, image_begin,
                                     image_end);
  }

 private:
  typedef id1<int> SegmentTree;

  explicit id3(const SegmentTree &segment_tree)
      : segment_tree_(segment_tree) {}

  friend class PermutationImageAnalyzerBuilder;

  SegmentTree segment_tree_;
};

class PermutationImageAnalyzerBuilder {
 public:
  id3 Build(const Permutation &permutation) {
    std::vector<Point<int>> points;
    points.reserve(permutation.size());
    for (size_t i = 0; i < permutation.size(); ++i) {
      points.emplace_back(i, permutation[i]);
    }
    auto segment_tree =
        id6(points.begin(), points.end());
    return id3(segment_tree);
  }
};

id3 id11(
    const Permutation &permutation) {
  return PermutationImageAnalyzerBuilder().Build(permutation);
}

size_t ReadSize() {
  size_t size;
  ::scanf("%lu", &size);
  

  return size;
}

Permutation ReadPermutation(size_t size) {
  Permutation permutation(size);
  for (size_t &element : permutation) {
      ::scanf("%lu", &element);
      

    

    

    --element;
  }
  return permutation;
}

template <class Analyzer>
void ProcessQueries(const Analyzer &analyzer, size_t size) {
  const size_t n_queries = ReadSize();
  size_t x = 0;
  auto f = [&x, size](size_t z) { return (z + x - 1) % size; };
  for (size_t i_query = 0; i_query < n_queries; ++i_query) {
    size_t a, b, c, d;
    ::scanf("%lu %lu %lu %lu", &a, &b, &c, &d);
    


    

    

    size_t count =
        analyzer.CountNumbers(std::min(f(a), f(b)), std::max(f(a), f(b)) + 1,
                              std::min(f(c), f(d)), std::max(f(c), f(d)) + 1);
    std::cout << count << "\n";
    x = count + 1;
  }
}

int TestAll();

int main() {

  return TestAll();


  


  size_t size = ReadSize();
  Permutation id8 = ReadPermutation(size);
  Permutation id13 = ReadPermutation(size);
  Permutation id9 =
      Composition(Inverse(id13), id8);

  id3 analyzer =
      id11(id9);
  ProcessQueries(analyzer, size);

  return 0;
}










class id15 {
 public:
  explicit id15(const Permutation &permutation)
      : permutation_(permutation) {}

  size_t CountNumbers(size_t range_begin, size_t range_end, size_t image_begin,
                      size_t image_end) const {
    size_t count = 0;
    for (size_t i = range_begin; i < range_end; ++i) {
      const size_t image = permutation_.at(i);
      count += static_cast<size_t>(image_begin <= image && image < image_end);
    }
    return count;
  }

 private:
  Permutation permutation_;
};

class id7 : public std::runtime_error {
 public:
  explicit id7(const char *what)
      : std::runtime_error(what) {}

  explicit id7(const std::string &what)
      : std::runtime_error(what.c_str()) {}
};

std::ostream &operator<<(std::ostream &os, const Permutation &permutation) {
  std::copy(permutation.begin(), permutation.end(),
            std::ostream_iterator<size_t>(os, " "));
  return os;
}

class Tester {
 public:
  explicit Tester(const Permutation &permutation)
      : analyzer_(id11(permutation)),
        trivial_analyzer_(permutation),
        permutation_(permutation) {}

  

  void operator()(size_t range_begin, size_t range_end, size_t image_begin,
                  size_t image_end) const {
    const size_t count =
        analyzer_.CountNumbers(range_begin, range_end, image_begin, image_end);
    const size_t correct_count = trivial_analyzer_.CountNumbers(
        range_begin, range_end, image_begin, image_end);
    if (count != correct_count) {
      std::ostringstream oss;
      oss << "Test not passed: got answer " << count
          << " while the correct one is " << correct_count << " for the mapping"
          << " of [" << range_begin << ", " << range_end << ")"
          << " to [" << image_begin << ", " << image_end << ");"
          << "\n\tthe permutation is " << permutation_ << "\n";
      throw id7(oss.str());
    }
  }

  size_t size() const { return permutation_.size(); }

 private:
  id3 analyzer_;
  id15 trivial_analyzer_;
  Permutation permutation_;
};

int RandomInt(int begin, int end) { return rand() % (end - begin) + begin; }

Range RandomRange(size_t size) {
  size_t begin = RandomInt(0, size);
  size_t end = RandomInt(begin, size);
  return Range(begin, end);
}

void id2(const Tester &tester) {
  int size = tester.size();
  Range range = RandomRange(size);
  Range image = RandomRange(size);
  tester(range.begin, range.end, image.begin, image.end);
}

void id5(size_t max_size, size_t n_tests) {
  for (size_t size = 1; size <= max_size; ++size) {
    Permutation permutation(size);
    std::iota(permutation.begin(), permutation.end(), 0);
    Tester tester(permutation);
    for (size_t i_test = 0; i_test < n_tests; ++i_test) {
      id2(tester);
    }
  }
}

void id16(size_t max_size, size_t id12,
                            size_t id14) {
  for (size_t id10 = 0; id10 < id12;
       ++id10) {
    const size_t size = RandomInt(2, max_size);
    Permutation permutation(size);
    std::iota(permutation.begin(), permutation.end(), 0);
    std::random_shuffle(permutation.begin(), permutation.end());
    Tester tester(permutation);
    for (size_t i_test = 0; i_test < id14; ++i_test) {
      id2(tester);
    }
  }
}


  do {                                                                       \
    auto firstValue = (first);                                               \
    auto secondValue = (second);                                             \
    if (firstValue != secondValue) {                                         \
      std::ostringstream oss;                                                \
      oss << "Require equal failed: " << 
          << firstValue << " != " << secondValue << ")\n";                   \
      throw id7(oss.str());                               \
    }                                                                        \
  } while (false)

void id0(size_t n_tests) {
  const size_t permutation[] = {0, 4, 3, 2, 1};
  const id15 analyzer(
      Permutation(std::begin(permutation), std::end(permutation)));
  const size_t size =
      std::distance(std::begin(permutation), std::end(permutation));
  for (size_t i_test = 0; i_test < n_tests; ++i_test) {
    const Range range = RandomRange(size);
    for (size_t begin = 0; begin < size; ++begin) {
      

      REQUIRE_EQUAL(analyzer.CountNumbers(begin, begin, range.begin, range.end),
                    0);
      

      REQUIRE_EQUAL(analyzer.CountNumbers(range.begin, range.end, begin, begin),
                    0);
    }
  }
  REQUIRE_EQUAL(analyzer.CountNumbers(0, 1, 0, 3), 1);
  REQUIRE_EQUAL(analyzer.CountNumbers(0, 1, 0, 1), 1);
  REQUIRE_EQUAL(analyzer.CountNumbers(0, 5, 0, 3), 3);
  REQUIRE_EQUAL(analyzer.CountNumbers(1, 3, 0, 5), 2);
  REQUIRE_EQUAL(analyzer.CountNumbers(1, 4, 1, 4), 2);
  REQUIRE_EQUAL(analyzer.CountNumbers(2, 5, 1, 4), 3);
}



int TestAll() {
  std::srand(1543);

  try {
    id0(100);
    id5(10, 100);
    id16(6, 100, 30);
    id16(10, 100, 20);
    id16(30, 100, 10);
    id16(100, 10, 20);
    id16(1000, 10, 5);
  } catch (std::exception &ex) {
    std::cerr << ex.what() << "\n";
    return 1;
  }
  return 0;
}
