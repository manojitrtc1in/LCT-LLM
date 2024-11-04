



using namespace std;

int n, m, x;
int s[100000];

namespace Solution1 {





int count[100000][20];

void init() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (s[i] & (1 << j)) {
        count[i][j] = 1;
      } else {
        count[i][j] = 0;
      }
    }
  }
}

void setValue(int pos, int value) {
  s[pos] = value;
  for (int i = 0; i < 20; ++i) {
    if (value & (1 << i)) {
      count[pos][i] = 1;
    } else {
      count[pos][i] = 0;
    }
  }
}

uint64_t getPairs(int left, int right) {
  uint64_t res = 0;
  int state = 0;
  int end = left - 1;
  int sum[20] = {};
  for (int start = left; start <= right; ++start) {
    while (end + 1 <= right && (state < x || end < start)) {
      end++;
      for (int i = 0; i < 20; ++i) {
        sum[i] += count[end][i];
        if (sum[i] == 1 && count[end][i] == 1) {
          state |= (1 << i);
        }
      }
    }
    if (state < x) {
      break;
    }
    res += right - end + 1;
    for (int i = 0; i < 20; ++i) {
      sum[i] -= count[start][i];
      if (sum[i] == 0 && count[start][i] == 1) {
        state &= ~(1 << i);
      }
    }
  }
  return res;
}

}  


namespace Solution2 {




int id10;
int count[100000][20];
int segmentTree[100000 * 4][20];
int segmentTreeOr[100000 * 4];

void id15(int root, int left, int right) {
  if (left == right) {
    if (left >= n) {
      return;
    }
    for (int i = 0; i < 20; ++i) {
      segmentTree[root][i] = count[left][i];
    }
  } else {
    int mid = left + (right - left) / 2;
    int subLeft = root * 2 + 1;
    int subRight = root * 2 + 2;
    if (left < n) {
      id15(subLeft, left, mid);
    } else {
      subLeft = -1;
    }
    if (mid + 1 < n) {
      id15(subRight, mid + 1, right);
    } else {
      subRight = -1;
    }
    for (int i = 0; i < 20; ++i) {
      int value = 0;
      if (subLeft >= 0) value += segmentTree[subLeft][i];
      if (subRight >= 0) value += segmentTree[subRight][i];
      segmentTree[root][i] = value;
    }
  }
  int orValue = 0;
  for (int i = 0; i < 20; ++i) {
    if (segmentTree[root][i]) {
      orValue |= 1 << i;
    }
  }
  segmentTreeOr[root] = orValue;
  if (left == right) {
    assert(segmentTreeOr[root] == s[left]);
    

  }
}

void init() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (s[i] & (1 << j)) {
        count[i][j] = 1;
      } else {
        count[i][j] = 0;
      }
    }
  }
  id10 = 1;
  while (id10 < n) {
    id10 <<= 1;
  }
  id15(0, 0, id10 - 1);
}

void id16(int root, int left, int right, int pos, int add[20]) {
  if (pos < left || pos > right) {
    return;
  }
  int orValue = 0;
  for (int i = 0; i < 20; ++i) {
    segmentTree[root][i] += add[i];
    if (segmentTree[root][i]) {
      orValue |= 1 << i;
    }
  }
  segmentTreeOr[root] = orValue;
  if (left == right) {
    assert(segmentTreeOr[root] ==  s[pos]);
  }
  if (left != right) {
    int mid = left + (right - left) / 2;
    id16(root * 2 + 1, left, mid, pos, add);
    id16(root * 2 + 2, mid + 1, right, pos, add);
  }
}

void setValue(int pos, int value) {
  s[pos] = value;
  int add[20];
  for (int i = 0; i < 20; ++i) {
    int newBit;
    if (value & (1 << i)) {
       newBit = 1;
    } else {
      newBit = 0;
    }
    add[i] = newBit - count[pos][i];
    count[pos][i] = newBit;
  }
  id16(0, 0, id10 - 1, pos, add);
}

int id4(int root, int left, int right, int begin, int end) {
  if (begin <= left && right <= end) {




    return segmentTreeOr[root];
  }
  if (end < left || begin > right) {
    return 0;
  }
  int mid = left + (right - left) / 2;
  return id4(root * 2 + 1, left, mid, begin, end) |
    id4(root * 2 + 2, mid + 1, right, begin, end);
}

int id12(int begin, int end) {
  return id4(0, 0, id10 - 1, begin, end);
}

struct ChangeInfo {
  int pos;
  int orValue;
  ChangeInfo(int pos = 0, int orValue = 0) : pos(pos), orValue(orValue) {}
};

vector<ChangeInfo> leftChanges;
vector<ChangeInfo> rightChanges;

void id5(int left, int id14, int right, int id0, int end) {
  assert(left <= right);
  if (left == right) {
    assert(id14 == id0);
  }
  if (id14 == id0) {
    return;
  }
  int mid = left + (right - left) / 2;
  int id1 = id12(mid, end);
  if (id1 != id0) {
    int a = mid + 1;
    int id2 = id12(a, end);
    id5(a, id2, right, id0, end);
    if (id2 != id1) {
      leftChanges.emplace_back(mid, id1);
    }
  }
  id5(left, id14, mid, id1, end);
}

void id11(int begin, int end) {
  leftChanges.clear();
  leftChanges.emplace_back(end, s[end]);
  assert(s[end] == id12(end, end));
  id5(begin, id12(begin, end), end, s[end], end);
}

void id6(int left, int id14, int right, int id0, int begin) {
  assert(left <= right);
  if (left == right) {
    assert(id14 == id0);
  }
  if (id14 == id0) {
    return;
  }
  int mid = left + (right - left) / 2 + 1;
  int id1 = id12(begin, mid);
  if (id1 != id14) {
    int a = mid - 1;
    int id2 = id12(begin, a);
    id6(left, id14, a, id2, begin);
    if (id2 != id1) {
      rightChanges.emplace_back(mid, id1);
    }
  }
  id6(mid, id1, right, id0, begin);
}

void id17(int begin, int end) {
  rightChanges.clear();
  rightChanges.emplace_back(begin, s[begin]);
  id6(begin, s[begin], end, id12(begin, end), begin);
}

uint64_t id8(int left_begin, int left_end, int right_begin, int right_end) {
  id11(left_begin, left_end);
  id17(right_begin, right_end);
  int leftIndex = 0;
  int rightIndex = rightChanges.size() - 1;
  uint64_t res = 0;
  

  int id9 = right_end + 1;
  while (leftIndex < leftChanges.size() && rightIndex >= 0) {
    while (rightIndex >= 0 &&
      (leftChanges[leftIndex].orValue | rightChanges[rightIndex].orValue) >= x) {
        rightIndex--;
    }
    if (rightIndex + 1 < rightChanges.size()) {
      int leftPos = leftChanges[leftIndex].pos;
      int rightPos = rightChanges[rightIndex + 1].pos;
      res += (uint64_t)(leftPos - left_begin + 1) * (id9 - rightPos);
    

    

    

      id9 = rightPos;
    }
    leftIndex++;
  }
  return res;
}

uint64_t getPairs(int left, int right) {
  if (left > right) {
    return 0;
  }
  if (left == right) {
    return (s[left] >= x) ? 1 : 0;
  }
  if (left + 1 == right) {
    if (s[left] >= x && s[right] >= x) return 3;
    if (s[left] >= x || s[right] >= x) return 2;
    if ((s[left] | s[right]) >= x) return 1;
    return 0;
  }
  int mid = left + (right - left) / 2;
  uint64_t res = getPairs(left, mid);
  res += getPairs(mid + 1, right);
  res += id8(left, mid, mid + 1, right);
  return res;
}

}  


namespace Solution3 {






int id10;
int count[100000][20];

struct ChangeInfo {
  int pos;
  int orValue;
  ChangeInfo(int pos = 0, int orValue = 0) : pos(pos), orValue(orValue) {}
};

struct ChangePoint {
  int pos;
  int orValue;
  ChangePoint(int pos = 0, int orValue = 0) : pos(pos), orValue(orValue) {}
  void set(int pos, int orValue) {
    this->pos = pos;
    this->orValue = orValue;
  }
};

struct Node {
  int64_t pairs;  

  vector<ChangePoint> leftChanges;
  vector<ChangePoint> rightChanges;
};
Node segmentTree[100000 * 4];

void calculateChanges(int root, int left, int right) {
  Node& node = segmentTree[root];
  if (left == right) {
    node.leftChanges.resize(1);
    node.leftChanges[0].set(left, s[left]);
    node.rightChanges.resize(1);
    node.rightChanges[0].set(left, s[left]);
  } else {
    Node& leftNode = segmentTree[root * 2 + 1];
    Node& rightNode = segmentTree[root * 2 + 2];
    int prev = 0;
    int i = 0;
    auto putChanges = [&](vector<ChangePoint>& from, vector<ChangePoint>& to) {
      for (ChangePoint& p : from) {
        if (i == 0 || (p.orValue & ~prev)) {
          to.resize(i + 1);
          prev |= p.orValue;
          to[i++].set(p.pos, prev);
        }
      }
    };
    putChanges(rightNode.leftChanges, node.leftChanges);
    putChanges(leftNode.leftChanges, node.leftChanges);
    i = 0;
    prev = 0;
    putChanges(leftNode.rightChanges, node.rightChanges);
    putChanges(rightNode.rightChanges, node.rightChanges);
  }
}

void id15(int root, int left, int right) {
  if (left >= n) {
    return;
  }
  Node& node = segmentTree[root];
  if (left != right) {
    int mid = left + (right - left) / 2;
    id15(root * 2 + 1, left, mid);
    id15(root * 2 + 2, mid + 1, right);
  }
  node.pairs = -1;
  calculateChanges(root, left, right);
}

void init() {
  id10 = 1;
  while (id10 < n) {
    id10 <<= 1;
  }
  id15(0, 0, id10 - 1);
}

int64_t id13(vector<ChangePoint>& leftChanges,
    vector<ChangePoint>& rightChanges, int lowLimit, int highLimit) {
  if (rightChanges.empty()) {
    return 0;
  }
  int rightIndex = rightChanges.size() - 1;
  while (rightChanges[rightIndex].pos > highLimit) {
    rightIndex--;
  }
  assert(rightIndex >= 0);
  int64_t res = 0;
  for (int leftIndex = 0; leftIndex < leftChanges.size() &&
        leftChanges[leftIndex].pos >= lowLimit; ++leftIndex) {
    int orValue = leftChanges[leftIndex].orValue;
    while (rightIndex >= 0 &&
        (orValue | rightChanges[rightIndex].orValue) >= x) {
      rightIndex--;
    }
    if (rightIndex + 1 < rightChanges.size() &&
        (orValue | rightChanges[rightIndex + 1].orValue) >= x &&
        highLimit >= rightChanges[rightIndex + 1].pos) {
      

      

      

      res += (int64_t)(leftChanges[leftIndex].pos - lowLimit + 1) *
              (highLimit - rightChanges[rightIndex + 1].pos + 1);
      highLimit = rightChanges[rightIndex + 1].pos - 1;
    }
  }
  return res;
}

int64_t id3(int root, int left, int right) {
  if (left >= n) {
    return 0;
  }
  Node& node = segmentTree[root];
  if (node.pairs >= 0) {
    return node.pairs;
  }
  if (left == right) {
    node.pairs = (s[left] >= x) ? 1 : 0;
  } else {
    int mid = left + (right - left) / 2;
    int64_t res = id3(root * 2 + 1, left, mid) +
                    id3(root * 2 + 2, mid + 1, right);
    int upLimit = min(right, n - 1);
    if (upLimit > mid) {
      res += id13(segmentTree[root * 2 + 1].leftChanges,
                segmentTree[root * 2 + 2].rightChanges, left, upLimit);
    }
    node.pairs = res;
  }
  

  

  return node.pairs;
}

int64_t id7(int root, int left, int right, int begin, int end) {
  if (begin > right || end < left) {
    return 0;
  }
  if (begin <= left && right <= end) {
    if (segmentTree[root].pairs == -1) {
      segmentTree[root].pairs = id3(root, left, right);
    }
    return segmentTree[root].pairs;
  }
  int mid = left + (right - left) / 2;
  int64_t res = id7(root * 2 + 1, left, mid, begin, end) +
    id7(root * 2 + 2, mid + 1, right, begin, end);
  if (begin <= mid && end >= mid + 1) {
    int lowLimit = max(begin, left);
    int hiLimit = min(end, right);
    int64_t a = id13(segmentTree[root * 2 + 1].leftChanges,
              segmentTree[root * 2 + 2].rightChanges, lowLimit, hiLimit);
    

    

    res += a;
  }
  return res;
}

uint64_t getPairs(int left, int right) {
  if (left > right) {
    return 0;
  }
  return id7(0, 0, id10 - 1, left, right);
}

void id16(int root, int left, int right, int pos) {
  if (pos < left || pos > right) {
    return;
  }
  Node& node = segmentTree[root];
  if (left != right) {
    int mid = left + (right - left) / 2;
    id16(root * 2 + 1, left, mid, pos);
    id16(root * 2 + 2, mid + 1, right, pos);
  }
  calculateChanges(root, left, right);
  node.pairs = -1;
}

void setValue(int pos, int value) {
  s[pos] = value;
  id16(0, 0, id10 - 1, pos);
}

}  


using namespace Solution3;


int main() {
  while (true) {
    if (scanf("%d%d%d", &n, &m, &x) != 3 || n <= 0) {
      break;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &s[i]);
    }
    init();
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a == 1) {
        setValue(b - 1, c);
      } else if (a == 2) {
        uint64_t res = getPairs(b - 1, c - 1);
        printf("%" PRIu64 "\n", res);
      }
    }
  }
  return 0;
}
