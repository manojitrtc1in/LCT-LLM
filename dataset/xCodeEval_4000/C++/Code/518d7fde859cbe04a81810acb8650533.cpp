#include <assert.h>
#include <stdio.h>
#include <cinttypes>
#include <vector>
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




int powerOfTwoN;
int count[100000][20];
int segmentTree[100000 * 4][20];
int segmentTreeOr[100000 * 4];

void initSegmentTree(int root, int left, int right) {
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
      initSegmentTree(subLeft, left, mid);
    } else {
      subLeft = -1;
    }
    if (mid + 1 < n) {
      initSegmentTree(subRight, mid + 1, right);
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
  powerOfTwoN = 1;
  while (powerOfTwoN < n) {
    powerOfTwoN <<= 1;
  }
  initSegmentTree(0, 0, powerOfTwoN - 1);
}

void setValueSegmentTree(int root, int left, int right, int pos, int add[20]) {
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
    setValueSegmentTree(root * 2 + 1, left, mid, pos, add);
    setValueSegmentTree(root * 2 + 2, mid + 1, right, pos, add);
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
  setValueSegmentTree(0, 0, powerOfTwoN - 1, pos, add);
}

int getOrInSegmentTreeRange(int root, int left, int right, int begin, int end) {
  if (begin <= left && right <= end) {




    return segmentTreeOr[root];
  }
  if (end < left || begin > right) {
    return 0;
  }
  int mid = left + (right - left) / 2;
  return getOrInSegmentTreeRange(root * 2 + 1, left, mid, begin, end) |
    getOrInSegmentTreeRange(root * 2 + 2, mid + 1, right, begin, end);
}

int getOrInRange(int begin, int end) {
  return getOrInSegmentTreeRange(0, 0, powerOfTwoN - 1, begin, end);
}

struct ChangeInfo {
  int pos;
  int orValue;
  ChangeInfo(int pos = 0, int orValue = 0) : pos(pos), orValue(orValue) {}
};

vector<ChangeInfo> leftChanges;
vector<ChangeInfo> rightChanges;

void getLeftChangeInfo_r(int left, int leftOrValue, int right, int rightOrValue, int end) {
  assert(left <= right);
  if (left == right) {
    assert(leftOrValue == rightOrValue);
  }
  if (leftOrValue == rightOrValue) {
    return;
  }
  int mid = left + (right - left) / 2;
  int midOrValue = getOrInRange(mid, end);
  if (midOrValue != rightOrValue) {
    int a = mid + 1;
    int aOrValue = getOrInRange(a, end);
    getLeftChangeInfo_r(a, aOrValue, right, rightOrValue, end);
    if (aOrValue != midOrValue) {
      leftChanges.emplace_back(mid, midOrValue);
    }
  }
  getLeftChangeInfo_r(left, leftOrValue, mid, midOrValue, end);
}

void getLeftChangeInfo(int begin, int end) {
  leftChanges.clear();
  leftChanges.emplace_back(end, s[end]);
  assert(s[end] == getOrInRange(end, end));
  getLeftChangeInfo_r(begin, getOrInRange(begin, end), end, s[end], end);
}

void getRightChangeInfo_r(int left, int leftOrValue, int right, int rightOrValue, int begin) {
  assert(left <= right);
  if (left == right) {
    assert(leftOrValue == rightOrValue);
  }
  if (leftOrValue == rightOrValue) {
    return;
  }
  int mid = left + (right - left) / 2 + 1;
  int midOrValue = getOrInRange(begin, mid);
  if (midOrValue != leftOrValue) {
    int a = mid - 1;
    int aOrValue = getOrInRange(begin, a);
    getRightChangeInfo_r(left, leftOrValue, a, aOrValue, begin);
    if (aOrValue != midOrValue) {
      rightChanges.emplace_back(mid, midOrValue);
    }
  }
  getRightChangeInfo_r(mid, midOrValue, right, rightOrValue, begin);
}

void getRightChangeInfo(int begin, int end) {
  rightChanges.clear();
  rightChanges.emplace_back(begin, s[begin]);
  getRightChangeInfo_r(begin, s[begin], end, getOrInRange(begin, end), begin);
}

uint64_t getCountInPartition(int left_begin, int left_end, int right_begin, int right_end) {
  getLeftChangeInfo(left_begin, left_end);
  getRightChangeInfo(right_begin, right_end);
  int leftIndex = 0;
  int rightIndex = rightChanges.size() - 1;
  uint64_t res = 0;
  

  int prev_right_limit = right_end + 1;
  while (leftIndex < leftChanges.size() && rightIndex >= 0) {
    while (rightIndex >= 0 &&
      (leftChanges[leftIndex].orValue | rightChanges[rightIndex].orValue) >= x) {
        rightIndex--;
    }
    if (rightIndex + 1 < rightChanges.size()) {
      int leftPos = leftChanges[leftIndex].pos;
      int rightPos = rightChanges[rightIndex + 1].pos;
      res += (uint64_t)(leftPos - left_begin + 1) * (prev_right_limit - rightPos);
    

    

    

      prev_right_limit = rightPos;
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
  res += getCountInPartition(left, mid, mid + 1, right);
  return res;
}

}  


namespace Solution3 {






int powerOfTwoN;
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

void initSegmentTree(int root, int left, int right) {
  if (left >= n) {
    return;
  }
  Node& node = segmentTree[root];
  if (left != right) {
    int mid = left + (right - left) / 2;
    initSegmentTree(root * 2 + 1, left, mid);
    initSegmentTree(root * 2 + 2, mid + 1, right);
  }
  node.pairs = -1;
  calculateChanges(root, left, right);
}

void init() {
  powerOfTwoN = 1;
  while (powerOfTwoN < n) {
    powerOfTwoN <<= 1;
  }
  initSegmentTree(0, 0, powerOfTwoN - 1);
}

int64_t calculatePairsInPartition(vector<ChangePoint>& leftChanges,
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

int64_t cachePairsInSegmentTree(int root, int left, int right) {
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
    int64_t res = cachePairsInSegmentTree(root * 2 + 1, left, mid) +
                    cachePairsInSegmentTree(root * 2 + 2, mid + 1, right);
    int upLimit = min(right, n - 1);
    if (upLimit > mid) {
      res += calculatePairsInPartition(segmentTree[root * 2 + 1].leftChanges,
                segmentTree[root * 2 + 2].rightChanges, left, upLimit);
    }
    node.pairs = res;
  }
  

  

  return node.pairs;
}

int64_t getPairsInSegmentTree(int root, int left, int right, int begin, int end) {
  if (begin > right || end < left) {
    return 0;
  }
  if (begin <= left && right <= end) {
    if (segmentTree[root].pairs == -1) {
      segmentTree[root].pairs = cachePairsInSegmentTree(root, left, right);
    }
    return segmentTree[root].pairs;
  }
  int mid = left + (right - left) / 2;
  int64_t res = getPairsInSegmentTree(root * 2 + 1, left, mid, begin, end) +
    getPairsInSegmentTree(root * 2 + 2, mid + 1, right, begin, end);
  if (begin <= mid && end >= mid + 1) {
    int lowLimit = max(begin, left);
    int hiLimit = min(end, right);
    int64_t a = calculatePairsInPartition(segmentTree[root * 2 + 1].leftChanges,
              segmentTree[root * 2 + 2].rightChanges, lowLimit, hiLimit);
    

    

    res += a;
  }
  return res;
}

uint64_t getPairs(int left, int right) {
  if (left > right) {
    return 0;
  }
  return getPairsInSegmentTree(0, 0, powerOfTwoN - 1, left, right);
}

void setValueSegmentTree(int root, int left, int right, int pos) {
  if (pos < left || pos > right) {
    return;
  }
  Node& node = segmentTree[root];
  if (left != right) {
    int mid = left + (right - left) / 2;
    setValueSegmentTree(root * 2 + 1, left, mid, pos);
    setValueSegmentTree(root * 2 + 2, mid + 1, right, pos);
  }
  calculateChanges(root, left, right);
  node.pairs = -1;
}

void setValue(int pos, int value) {
  s[pos] = value;
  setValueSegmentTree(0, 0, powerOfTwoN - 1, pos);
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
