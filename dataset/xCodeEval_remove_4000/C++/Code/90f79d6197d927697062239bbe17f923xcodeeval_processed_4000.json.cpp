





struct Linear {
    long long int a = 0;
    long long int b = 0;

    Linear& operator+=(const Linear& other) {
        a += other.a;
        b += other.b;
        return *this;
    }
    Linear& operator-=(const Linear& other) {
        a -= other.a;
        b -= other.b;
        return *this;
    }

    Linear operator-(const Linear& other) const {
        Linear new_object(*this);
        new_object -= other;
        return new_object;
    }

    Linear operator+(const Linear& other) const {
        Linear new_object(*this);
        new_object += other;
        return new_object;
    }
};

template <typename TX, typename TY, typename TValue>
struct Point {
    TX x;
    TY y;
    TValue value;
};

template <typename TX, typename TY, typename TValue>
class SquareNode {
public:
    using TPoint = Point<TX, TY, TValue>;

    SquareNode()
    {}

    void StoreMinMaxValues(const std::vector<TPoint>& points) {
        min_x = std::numeric_limits<TX>::max();
        max_x = std::numeric_limits<TX>::min();
        min_y = std::numeric_limits<TY>::max();
        max_y = std::numeric_limits<TY>::min();
        full_sum = TValue();
        any_points = false;
        for (auto& point: points) {
            if (min_x > point.x) {
                min_x = point.x;
            }
            if (max_x < point.x) {
                max_x = point.x;
            }
            if (min_y > point.y) {
                min_y = point.y;
            }
            if (max_y < point.y) {
                max_y = point.y;
            }
            full_sum += point.value;
            any_points = true;
        }
        ++max_x;
        ++max_y;
        mid_x = (min_x + max_x) / 2;
        mid_y = (min_y + max_y) / 2;
    }

    void LoadPoints(const std::vector<TPoint>& id9,
                    const std::vector<TPoint>& id1) {
        StoreMinMaxValues(id9);
        if (id7) {
            TValue prefix_sum;
            size_t prev_index{0};
            prefix_cols_sums.resize(static_cast<size_t>(max_x - min_x), {});
            for (auto& point: id9) {
                while (prev_index < static_cast<size_t>(point.x - min_x)) {
                    prefix_cols_sums[prev_index++] = prefix_sum;
                }
                prefix_sum += point.value;
            }
            while (prev_index < static_cast<size_t>(max_x - min_x)) {
                prefix_cols_sums[prev_index++] = prefix_sum;
            }
        }

        if (id14) {
            TValue prefix_sum;
            size_t prev_index{0};
            prefix_rows_sums.resize(static_cast<size_t>(max_y - min_y), {});
            for (auto& point: id1) {
                while (prev_index < static_cast<size_t>(point.y - min_y)) {
                    prefix_rows_sums[prev_index++] = prefix_sum;
                }
                prefix_sum += point.value;
            }
            while (prev_index < static_cast<size_t>(max_y - min_y)) {
                prefix_rows_sums[prev_index++] = prefix_sum;
            }
        }
    }


    bool IsEmpty() const noexcept {
        return max_x == min_x || max_y == min_y || !any_points;
    }

    bool IsDivisable() const noexcept {
        return max_x > min_x + 1 && max_y > min_y + 1;
    }

    template <typename TCoord>
    TValue id12(const TCoord& coord, const std::map<TCoord, TValue>& mapping) {
        if (IsEmpty()) {
            return {};
        } else {
            auto it = mapping.lower_bound(coord);
            if (it == mapping.begin()) {
                return {};
            } else {
                --it;
                return it->second;
            }
        }
    }

    template <typename TCoord>
    TValue id8(const TCoord& coord, const std::vector<TValue>& id3, const TCoord& min_coord) const {
        if (id3.size() == 0) {
            return {};
        }
        if (coord < min_coord + 1) {
            return {};
        }
        size_t index = static_cast<size_t>(coord - min_coord - 1);
        if (index >= id3.size()) {
            auto it = id3.end();
            --it;
            return *it;
        }
        return id3[index];
    }

    TValue GetPrefixColSum(TX x) const {
        return id8(x, prefix_cols_sums, min_x);
    }

    TValue GetPrefixRowSum(TY y) const {
        return id8(y, prefix_rows_sums, min_y);
    }

    TValue GetPrefixSquareSum(TX x, TY y) {
        if (IsEmpty()) {
            return {};
        }
        if (x >= max_x) {
            x = max_x;
        }
        if (y >= max_y) {
            y = max_y;
        }
        if (x <= min_x || y <= min_y) {
            return {};
        }
        if (x == max_x && y == max_y) {
            return full_sum;
        } else if (x == max_x && id14) {
            return GetPrefixRowSum(y);
        } else if (y == max_y && id7) {
            return GetPrefixColSum(x);
        }

        std::cout << "GetPrefixSquareSum is called\n";
        TValue result;
        for (SquareNode* pointer: {left_lower, left_upper, right_lower, right_upper}) {
            if (pointer) {
                result += pointer->GetPrefixSquareSum(x, y);
            }
        }
        return result;
    }
public:
    TX min_x = 0;
    TX max_x = 0;
    TY min_y = 0;
    TY max_y = 0;
    TX mid_x = 0;
    TY mid_y = 0;

    TValue full_sum = {};

    SquareNode* left_lower = nullptr;
    SquareNode* right_lower = nullptr;
    SquareNode* left_upper = nullptr;
    SquareNode* right_upper = nullptr;

    bool id14 = true;
    bool id7 = true;

    bool any_points;
private:
    std::vector<TValue> prefix_rows_sums;
    std::vector<TValue> prefix_cols_sums;
};

using TPoint = Point<int, long long int, Linear>;
using TSquareNode = SquareNode<int, long long int, Linear>;

TSquareNode* BuildTree(const bool id14, const bool id7,
                       std::vector<TSquareNode>& pool, int& pool_index, std::vector<TPoint>& id9,
                       std::vector<TPoint>& id1) {
    TSquareNode& node = pool[pool_index++];
    if (id9.size() > 0) {
        node.id14 = id14;
        node.id7 = id7;
        node.LoadPoints(id9, id1);
        if (node.max_x > node.min_x + 1 && node.max_y > node.min_y + 1) {
            std::vector<TPoint> id13;
            std::vector<TPoint> id6;
            std::vector<TPoint> id5;
            std::vector<TPoint> id10;
            std::vector<TPoint> id15;
            std::vector<TPoint> id16;
            std::vector<TPoint> id11;
            std::vector<TPoint> id4;

            id13.reserve(id9.size());
            id10.reserve(id9.size());
            id5.reserve(id9.size());
            id6.reserve(id9.size());
            id15.reserve(id9.size());
            id4.reserve(id9.size());
            id11.reserve(id9.size());
            id16.reserve(id9.size());
            for (auto& point: id9) {
                if (point.x < node.mid_x && point.y < node.mid_y) {
                    id13.push_back(point);
                } else if (point.x < node.mid_x && point.y >= node.mid_y) {
                    id5.push_back(point);
                } else if (point.x >= node.mid_x && point.y < node.mid_y) {
                    id10.push_back(point);
                } else {
                    id6.push_back(point);
                }
            }
            for (auto& point: id1) {
                if (point.x < node.mid_x && point.y < node.mid_y) {
                    id15.push_back(point);
                } else if (point.x < node.mid_x && point.y >= node.mid_y) {
                    id11.push_back(point);
                } else if (point.x >= node.mid_x && point.y < node.mid_y) {
                    id4.push_back(point);
                } else {
                    id16.push_back(point);
                }
            }

            node.left_lower = BuildTree(true, true, pool, pool_index, id13, id15);
            node.left_upper = BuildTree(true, false, pool, pool_index, id5, id11);
            node.right_lower = BuildTree(false, true, pool, pool_index, id10, id4);
            node.right_upper = BuildTree(false, false, pool, pool_index, id6, id16);
        } else if (node.max_x > node.min_x + 1) {
            std::vector<TPoint> id13;
            std::vector<TPoint> id10;
            std::vector<TPoint> id15;
            std::vector<TPoint> id4;

            id13.reserve(id9.size());
            id10.reserve(id9.size());
            id15.reserve(id9.size());
            id4.reserve(id9.size());
            for (auto& point: id9) {
                if (point.x < node.mid_x) {
                    id13.push_back(point);
                } else if (point.x >= node.mid_x) {
                    id10.push_back(point);
                }
            }
            for (auto& point: id1) {
                if (point.x < node.mid_x) {
                    id15.push_back(point);
                } else if (point.x >= node.mid_x) {
                    id4.push_back(point);
                }
            }
            node.left_lower = BuildTree(true, false, pool, pool_index, id13, id15);
            node.right_lower = BuildTree(false, false, pool, pool_index, id10, id4);
        } else if (node.max_y > node.min_y + 1) {
            std::vector<TPoint> id13;
            std::vector<TPoint> id5;
            std::vector<TPoint> id15;
            std::vector<TPoint> id11;

            id13.reserve(id9.size());
            id5.reserve(id9.size());
            id15.reserve(id9.size());
            id11.reserve(id9.size());

            for (auto& point: id9) {
                if (point.y < node.mid_y) {
                    id13.push_back(point);
                } else if (point.y >= node.mid_y) {
                    id5.push_back(point);
                }
            }
            for (auto& point: id1) {
                if (point.y < node.mid_y) {
                    id15.push_back(point);
                } else if (point.y >= node.mid_y) {
                    id11.push_back(point);
                }
            }
            node.left_lower = BuildTree(false, true, pool, pool_index, id13, id15);
            node.left_upper = BuildTree(false, false, pool, pool_index, id5, id11);
        }
    }
    return &node;
}

Linear id2(
    TSquareNode* root,
    int x,
    long long int y
) {
    Linear result;
    TSquareNode* node = root;
    while (true) {
        if (node == nullptr || x <= node->min_x || y <= node->min_y) {
            break;
        }
        if (x >= node->max_x) {
            x = node->max_x;
        }
        if (y >= node->max_y) {
            y = node->max_y;
        }
        if (node->max_x > node->min_x + 1 && node->max_y > node->min_y + 1) {
            if (x <= node->mid_x && y <= node->mid_y) {
                node = node->left_lower;
            } else if (x > node->mid_x && y <= node->mid_y) {
                result += node->left_lower->GetPrefixRowSum(y);
                node = node->right_lower;
            } else if (x <= node->mid_x && y > node->mid_y) {
                result += node->left_lower->GetPrefixColSum(x);
                node = node->left_upper;
            } else {
                result += node->left_lower->full_sum;
                result += node->left_upper->GetPrefixRowSum(y);
                result += node->right_lower->GetPrefixColSum(x);
                node = node->right_upper;
            }
        } else if (node->max_x > node->min_x + 1) {
            if (x <= node->mid_x) {
                node = node->left_lower;
            } else {
                result += node->left_lower->GetPrefixRowSum(y);
                node = node->right_lower;
            }
        } else if (node->max_y > node->min_y + 1) {
            if (y <= node->mid_y) {
                node = node->left_lower;
            } else {
                result += node->left_lower->GetPrefixColSum(x);
                node = node->left_upper;
            }
        } else {
            if (node->max_x == x && node->max_y == y) {
                result += node->full_sum;
            }
            node = nullptr;
        }
    }
    return result;
}
int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<TPoint> id9(2 * n);
    std::vector<TPoint> id1(2 * n);


    std::vector<long long int> id0(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long int x1, x2, y1, y2, a, b;
        std::cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        id9[2 * i] = {i, x1, {a, b - y1}};
        id9[2 * i + 1] = {i, x2, {-a, y2 - b}};
        id1[2 * i] = {i, x1, {a, b - y1}};
        id1[2 * i + 1] = {i, x2, {-a, y2 - b}};
        id0[i + 1] = y1;
        id0[i + 1] += id0[i];
    }
    std::sort(id9.begin(), id9.end(), [] (const TPoint& first, const TPoint& second) -> bool {
        return first.x < second.x;
    });
    std::sort(id1.begin(), id1.end(), [] (const TPoint& first, const TPoint& second) -> bool {
        return first.y < second.y;
    });




    std::vector<TSquareNode> pool(2000000);




    int pool_index = 0;
    TSquareNode& root = *BuildTree(false, false, pool, pool_index, id9, id1);




    int m;
    std::cin >> m;
    long long int last = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        long long int x;
        std::cin >> l >> r >> x;
        --l;
        --r;
        x += last;
        x %= 1000000000;
        long long int initial_constant = id0[r + 1] - id0[l];




        Linear first_linear = id2(&root, r + 1, x);
        Linear second_linear = id2(&root, l, x);
        Linear linear = first_linear - second_linear;
        linear.b += initial_constant;
        last = linear.a * x + linear.b;
        std::cout << last << std::endl;
    }





    return 0;
}
