#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#pragma comment(linker, "/STACK:36777216")

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "zinger_color2"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;



template<typename T, typename V, typename Compare, typename Operation>
class CartesianTree {
  static int GenRandom() {
    return rand() + (rand() << 16);
  }

  struct Node {
    T key;
    V value;
    V agg_value;
    int priority;
    Node* left, * right;

    Node(T key_, V value_) : key(key_), value(value_), agg_value(value_), priority(GenRandom()), left(NULL), right(NULL) {}

    Node() : key(0), value(0), agg_value(0), priority(0), left(NULL), right(NULL) {}
  };

  Node* root;

  Node* NewNode(T key, V value) {
    return new Node(key, value);
  }

  V GetAggValue(Node* node) {
    if (!node) {
      return Operation::Identity;
    }
    return node->agg_value;
  }

  void Update(Node* node) {
    node->agg_value = Operation()(node->value, GetAggValue(node->left), GetAggValue(node->right));
  }

  V GetAggLeft(Node* root, T key) {
    if (!root) {
      return GetAggValue(root);
    }
    if (Compare()(root->key, key)) {
      return Operation()(root->value, GetAggValue(root->left), GetAggLeft(root->right, key));
    }
    return GetAggLeft(root->left, key);
  }

  V GetAggRight(Node* root, T key) {
    if (!root) {
      return GetAggValue(root);
    }
    if (Compare()(root->key, key)) {
      return GetAggRight(root->right, key);
    }
    return Operation()(root->value, GetAggRight(root->left, key), GetAggValue(root->right));
  }

  void GetKeysRec(Node* root, vector<T>& res) {
    if (root == NULL) {
      return;
    }
    getKeysRec(root->left, res);
    res.push_back(root->key);
    getKeysRec(root->right, res);
  }

  bool HasKey(Node* root, T key) {
    if (root == NULL) {
      return false;
    }
    if (root->key == key) {
      return true;
    }
    if (Compare()(root->key, key)) {
      return HasKey(root->right, key);
    }
    else {
      return HasKey(root->left, key);
    }
  }

  pair<Node*, Node*> SplitLeft(Node* root, T key) {
    if (root == NULL) {
      return MP((Node*)NULL, (Node*)NULL);
    }
    if (!Compare()(key, root->key)) {
      pair<Node*, Node*> res = SplitLeft(root->right, key);
      root->right = res.first;
      Update(root);
      res.first = root;
      Update(res.first);
      return res;
    }
    else {
      pair<Node*, Node*> res = SplitLeft(root->left, key);
      root->left = res.second;
      Update(root);
      res.second = root;
      Update(res.second);
      return res;
    }
  }

public:
  CartesianTree() : root(NULL) {}

  CartesianTree(const CartesianTree& other) {
    root = other.root;
  }

  CartesianTree(Node* root_) : root(root_) {}

  Node* Merge(Node* left, Node* right) {
    if (left == NULL) {
      return right;
    }
    if (right == NULL) {
      return left;
    }
    if (left->priority > right->priority) {
      left->right = Merge(left->right, right);
      Update(left);
      return left;
    }
    else {
      right->left = Merge(left, right->left);
      Update(right);
      return right;
    }
  }

  void MergeWith(const CartesianTree& other) {
    root = Merge(root, other.root);
  }

  pair<Node*, Node*> Split(Node* root, T key) {
    if (root == NULL) {
      return MP((Node*)NULL, (Node*)NULL);
    }
    if (Compare()(root->key, key)) {
      pair<Node*, Node*> res = Split(root->right, key);
      root->right = res.first;
      Update(root);
      res.first = root;
      Update(res.first);
      return res;
    }
    else {
      pair<Node*, Node*> res = Split(root->left, key);
      root->left = res.second;
      Update(root);
      res.second = root;
      Update(res.second);
      return res;
    }
  }

  pair<CartesianTree, CartesianTree> Split(T key) {
    pair<Node*, Node*> res = Split(root, key);
    return MP(CartesianTree(res.first), CartesianTree(res.second));
  }

  vector<T> GetKeys() {
    vector<T> res;
    getKeysRec(root, res);
    return res;
  }

  V GetAggLeft(T key) {
    return GetAggLeft(root, key);
  }

  V GetAggRight(T key) {
    return GetAggRight(root, key);
  }

  void PrintTree(Node* root) {
    if (!root) {
      return;
    }
    PrintTree(root->left);
    cerr << root->key << ' ' << root->value << endl;
    PrintTree(root->right);
  }

  void PrintTree() {
    PrintTree(root);
  }

  void Insert(T key, V value) {
    pair<Node*, Node*> p = Split(root, key);
    Node* new_node = NewNode(key, value);
    p.first = Merge(p.first, new_node);
    root = Merge(p.first, p.second);
  }

  bool HasKey(T key) {
    return HasKey(root, key);
  }

  void Erase(T key) {
    pair<Node*, Node*> p = Split(root, key);
    pair<Node*, Node*> p2 = SplitLeft(p.second, key);
    root = Merge(p.first, p2.second);
  }

  void Change(T key, V value) {
    pair<Node*, Node*> p = Split(root, key);
    pair<Node*, Node*> q = SplitLeft(p.second, key);
    q.first->value = value;
    Update(q.first);
    root = Merge(p.first, Merge(q.first, q.second));
  }
};

class RightmostColor {
public:
  static char Identity;

  char operator()(char root, char left, char right) {
    if (right != Identity) {
      return right;
    }
    if (root != Identity) {
      return root;
    }
    return left;
  }
};

char RightmostColor::Identity = 'N';

typedef CartesianTree<int, char, std::less<int>, RightmostColor> ColorTree;

void Move(ColorTree& from, ColorTree& to, int start, int end) {
  pair<ColorTree, ColorTree> p1 = from.Split(start);
  pair<ColorTree, ColorTree> p2 = p1.second.Split(end + 1);
  from = p1.first;
  from.MergeWith(p2.second);
  pair<ColorTree, ColorTree> p3 = to.Split(start);
  to = p3.first;
  to.MergeWith(p2.first);
  to.MergeWith(p3.second);
}

vector<string> ComputeColors(int n, const vector<string>& input_messages, int t, const vector<pair<int, string> >& edits) {
  map<char, string> colors;
  colors['r'] = "red";
  colors['o'] = "orange";
  colors['y'] = "yellow";
  colors['g'] = "green";
  colors['b'] = "blue";
  colors['i'] = "indigo";
  colors['v'] = "violet";
  vector<string> messages(n + 2);
  messages[0] = "unlock";
  for (int i = 0; i < n; ++i) {
    messages[i + 1] = input_messages[i];
  }
  messages[n + 1] = "lock";  
  set<int> lock_positions;
  set<int> unlock_positions;
  for (int i = 0; i < messages.size(); ++i) {
    if (messages[i] == "lock") {
      lock_positions.insert(i);
    }
    else if (messages[i] == "unlock") {
      unlock_positions.insert(i);
    }
  }
  int unlock_pos = -1;
  ColorTree active;
  ColorTree passive;
  set<int> left_borders;
  set<int> right_borders;
  while (unlock_pos < (int)messages.size()) {
    auto lock_it = lock_positions.lower_bound(unlock_pos);
    int lock_pos = *lock_it;
    left_borders.insert(unlock_pos);
    right_borders.insert(lock_pos);
    for (int i = unlock_pos; i <= lock_pos; ++i) {
      char value;
      if (i == unlock_pos) {
        value = RightmostColor::Identity;
      }
      else if (messages[i] == "lock" || messages[i] == "unlock") {
        value = RightmostColor::Identity;
      }
      else {
        value = messages[i][0];
      }
      active.Insert(i, value);
    }
    int next_unlock;
    auto unlock_it = unlock_positions.lower_bound(lock_pos);
    if (unlock_it == unlock_positions.end()) {
      next_unlock = messages.size();
    }
    else {
      next_unlock = *unlock_it;
    }
    for (int i = lock_pos + 1; i < next_unlock; ++i) {
      char value;
      if (messages[i] == "lock") {
        value = RightmostColor::Identity;
      }
      else if (messages[i] == "unlock") {
        cerr << "WTF: unlock earlier than next_unlock, lock_pos = " << lock_pos << ", next_unlock = " << next_unlock << ", i = " << i << endl;
        exit(1);
      }
      else {
        value = messages[i][0];
      }
      passive.Insert(i, value);
    }
    unlock_pos = next_unlock;
  }
  active.Change(0, 'b');
  vector<string> result;
  result.push_back(colors[active.GetAggRight(-2)]);
  string last_res = result.back();
  for (int edit = 0; edit < t; ++edit) {    
    int pos = edits[edit].first;
    string nvalue = edits[edit].second;
    if (nvalue == messages[pos]) {
      result.push_back(last_res);
      continue;
    }
    if (active.HasKey(pos)) {
      if (nvalue == "lock" || nvalue == "unlock") {
        active.Change(pos, RightmostColor::Identity);
      }
      else {
        active.Change(pos, nvalue[0]);
      }
    }
    else {
      if (nvalue == "lock" || nvalue == "unlock") {
        passive.Change(pos, RightmostColor::Identity);
      }
      else {
        passive.Change(pos, nvalue[0]);
      }
    }
    if (messages[pos] == "lock") {
      if (right_borders.count(pos)) {
        auto it = left_borders.lower_bound(pos);
        --it;
        int unlock_pos = *it;
        auto it2 = lock_positions.lower_bound(pos + 1);
        int lock_pos = *it2;
        if (right_borders.count(lock_pos)) {
          auto it3 = left_borders.lower_bound(lock_pos);
          --it3;
          int next_unlock = *it3;
          Move(passive, active, pos + 1, next_unlock - 1);
          left_borders.erase(next_unlock);
        }
        else {
          Move(passive, active, pos + 1, lock_pos);
          right_borders.insert(lock_pos);
        }
        right_borders.erase(pos);
        if (nvalue == "unlock") {
          unlock_positions.insert(pos);
        }
      }
      else {
        if (nvalue == "unlock") {
          auto it = lock_positions.lower_bound(pos + 1);
          int lock_pos = *it;
          if (right_borders.count(lock_pos)) {
            auto it2 = left_borders.lower_bound(lock_pos);
            --it2;
            int unlock_pos = *it2;
            Move(passive, active, pos, unlock_pos - 1);
            left_borders.erase(unlock_pos);
          }
          else {
            Move(passive, active, pos, lock_pos);
            right_borders.insert(lock_pos);
          }
          unlock_positions.insert(pos);
          left_borders.insert(pos);
        }
      }
      lock_positions.erase(pos);
    }
    else if (messages[pos] == "unlock") {
      if (left_borders.count(pos)) {
        auto it2 = right_borders.lower_bound(pos + 1);
        int lock_pos = *it2;
        auto it = unlock_positions.lower_bound(pos + 1);
        if (it == unlock_positions.end()) {
          Move(active, passive, pos, lock_pos);
          right_borders.erase(lock_pos);
        }
        else {
          int next_unlock = *it;
          if (next_unlock < lock_pos) {
            Move(active, passive, pos, next_unlock - 1);
            left_borders.insert(next_unlock);
          }
          else {
            Move(active, passive, pos, lock_pos);
            right_borders.erase(lock_pos);
          }
        }
        left_borders.erase(pos);
        if (nvalue == "lock") {
          lock_positions.insert(pos);
        }
      }
      else {
        if (nvalue == "lock") {
          auto it = right_borders.lower_bound(pos + 1);
          int lock_pos = *it;
          auto it3 = unlock_positions.lower_bound(pos + 1);
          if (it3 == unlock_positions.end()) {
            Move(active, passive, pos + 1, lock_pos);
            right_borders.erase(lock_pos);
            right_borders.insert(pos);
          }
          else {
            int next_unlock = *it3;
            if (next_unlock > lock_pos) {
              Move(active, passive, pos + 1, lock_pos);
              right_borders.erase(lock_pos);
              right_borders.insert(pos);
            }
            else {
              Move(active, passive, pos + 1, next_unlock - 1);
              right_borders.insert(pos);
              left_borders.insert(next_unlock);
            }
          }
          lock_positions.insert(pos);
        }
      }
      unlock_positions.erase(pos);
    }
    else {
      auto unlock_it = left_borders.lower_bound(pos);
      --unlock_it;
      int unlock_pos = *unlock_it;
      auto lock_it = right_borders.lower_bound(unlock_pos);
      int lock_pos = *lock_it;
      if (nvalue == "lock") {
        lock_positions.insert(pos);
        if (pos < lock_pos) {
          auto it2 = unlock_positions.lower_bound(pos);
          if (it2 != unlock_positions.end()) {
            int next_unlock = *it2;
            if (next_unlock < lock_pos) {
              Move(active, passive, pos + 1, next_unlock - 1);
              left_borders.insert(next_unlock);
            }
            else {
              right_borders.erase(lock_pos);
              Move(active, passive, pos + 1, lock_pos);
            }
          }
          else {
            right_borders.erase(lock_pos);
            Move(active, passive, pos + 1, lock_pos);
          }
          right_borders.insert(pos);
        }
      }
      else if (nvalue == "unlock") {
        unlock_positions.insert(pos);
        if (pos > lock_pos) {
          auto it = lock_positions.lower_bound(pos);
          int next_lock = *it;
          if (right_borders.count(next_lock)) {
            auto it2 = left_borders.lower_bound(next_lock);
            --it2;
            int prev_unlock = *it2;
            Move(passive, active, pos, prev_unlock - 1);
            left_borders.erase(prev_unlock);
          }
          else {
            Move(passive, active, pos, next_lock);
            right_borders.insert(next_lock);
          }
          left_borders.insert(pos);
        }
      }
      else {
        

      }
    }
    messages[pos] = nvalue;
    result.push_back(colors[active.GetAggRight(-2)]);
    last_res = result.back();
  }
  return result;
}

string ComputeColor(const vector<string>& messages) {
  string result = "blue";
  bool locked = false;
  for (int i = 0; i < messages.size(); ++i) {
    if (messages[i] == "lock") {
      locked = true;
    }
    else if (messages[i] == "unlock") {
      locked = false;
    }
    else {
      if (!locked) {
        result = messages[i];
      }
    }
  }
  return result;
}

vector<string> ComputeColorsStupid(int n, vector<string> messages, int t, const vector<pair<int, string> >& edits) {
  vector<string> result;
  result.push_back(ComputeColor(messages));
  for (int i = 0; i < edits.size(); ++i) {
    messages[edits[i].first - 1] = edits[i].second;
    result.push_back(ComputeColor(messages));
  }
  return result;
}

int main() {
  
#ifdef LOCAL
  freopen(PROBLEM_ID".in", "r", stdin);
#endif
  
  int n;
  scanf("%d", &n);
  vector<string> messages(n);
  for (int i = 0; i < n; ++i) {
    char buf[100];
    scanf("%s", buf);
    messages[i] = buf;
  }
  int t;
  scanf("%d", &t);
  vector<pair<int, string> > edits;
  for (int edit = 0; edit < t; ++edit) {
    int pos;
    string nvalue;
    char buf[100];
    scanf("%d %s", &pos, buf);
    nvalue = buf;
    edits.push_back(MP(pos, nvalue));
  }
  vector<string> result = ComputeColors(n, messages, t, edits);
#ifdef LOCAL
  freopen(PROBLEM_ID".out", "w", stdout);
#endif
  for (int i = 0; i < result.size(); ++i) {
    printf("%s\n", result[i].c_str());
  }
  return 0;
}
