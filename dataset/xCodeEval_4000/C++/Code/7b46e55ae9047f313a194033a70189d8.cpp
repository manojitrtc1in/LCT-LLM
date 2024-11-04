#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

struct Node {
  explicit Node(ll v, shared_ptr<Node> p) : value(v), parent(p) {}
  int count = 1;
  

  

  int balance = 0;
  ll value;
  shared_ptr<Node> left;
  shared_ptr<Node> right;
  shared_ptr<Node> parent;
};





class ThresholdMultiset {
 public:
  ThresholdMultiset() {}

  

  void Insert(ll k) {
    if (root == nullptr) {
      root = make_shared<Node>(k, nullptr);
      return;
    }

    shared_ptr<Node> cur = root;
    

    while (cur->value != k &&
           (k < cur->value ? cur->left != nullptr : cur->right != nullptr)) {
      cur = k < cur->value ? cur->left : cur->right;
    }
    if (cur->value == k) {
      while (cur != nullptr) {
        cur->count++;
        cur = cur->parent;
      }
      return;
    }

    

    const bool increased_height = cur->balance == 0;
    if (k < cur->value) {
      cur->left = make_shared<Node>(k, cur);
      cur->balance--;
    } else {
      cur->right = make_shared<Node>(k, cur);
      cur->balance++;
    }
    cur->count++;

    if (!increased_height) {
      while (cur->parent != nullptr) {
        cur = cur->parent;
        cur->count++;
      }
      return;
    };

    shared_ptr<Node> parent;
    while (cur != nullptr) {
      if (cur->balance == 0) break;
      parent = cur->parent;
      if (parent == nullptr) break;
      parent->count++;
      if (parent->left == cur) {
        parent->balance--;
        if (parent->balance == -2) {
          if (cur->balance == -1) {
            RotateRight(parent);
            break;
          } else {  

            RotateLeft(cur);
            RotateRight(parent);
            cur = cur->parent;
            break;
          }
        }
      } else {
        parent->balance++;
        if (parent->balance == 2) {
          if (cur->balance == 1) {
            RotateLeft(parent);
            break;
          } else {  

            RotateRight(cur);
            RotateLeft(parent);
            cur = cur->parent;
            break;
          }
        }
      }
      cur = parent;
    }

    do {
      cur = cur->parent;
      if (cur == nullptr) break;
      cur->count++;
    } while (cur != nullptr);
  }

  ll CountNumAtLeast(ll t, shared_ptr<Node> n) {
    const int n_left_count = n->left == nullptr ? 0 : n->left->count;
    if (n->value == t) return n->count - n_left_count;
    if (n->value > t) {
      if (n->left == nullptr)
        return n->count;
      else
        return n->count - n_left_count + CountNumAtLeast(t, n->left);
    }
    if (n->right == nullptr) return 0;
    return CountNumAtLeast(t, n->right);
  }

  

  ll CountNumAtLeast(ll t) { return CountNumAtLeast(t, root); }

  

  

  

  


  

  

  shared_ptr<Node> RotateLeft(shared_ptr<Node> x) {
    const int x_left_count = x->left == nullptr ? 0 : x->left->count;
    const int num_at_x = x->count - x_left_count - x->right->count;

    shared_ptr<Node> z = x->right;
    shared_ptr<Node> t = z->left;
    if (root == x) root = z;
    x->right = t;
    if (t != nullptr) {
      t->parent = x;
    }
    z->parent = x->parent;

    if (x->parent != nullptr) {
      if (x == x->parent->left) {
        x->parent->left = z;
      } else {
        x->parent->right = z;
      }
    }
    z->left = x;
    x->parent = z;

    const int old_x_balance = x->balance;
    if (x->balance == z->balance) {
      x->balance = -1;
    } else {
      x->balance = 0;
    }
    if (old_x_balance == 2) {
      z->balance = 0;
    } else if (z->balance >= 0) {
      z->balance = -1;
    } else {
      z->balance = -2;
    }

    z->count = x->count;
    const int x_right_count = x->right == nullptr ? 0 : x->right->count;
    x->count = x_left_count + x_right_count + num_at_x;
    return z;
  }

  

  

  shared_ptr<Node> RotateRight(shared_ptr<Node> x) {
    const int x_right_count = x->right == nullptr ? 0 : x->right->count;
    const int num_at_x = x->count - x_right_count - x->left->count;

    shared_ptr<Node> z = x->left;
    shared_ptr<Node> t = z->right;
    if (root == x) root = z;
    x->left = t;
    if (t != nullptr) {
      t->parent = x;
    }
    z->parent = x->parent;
    if (x->parent != nullptr) {
      if (x == x->parent->right) {
        x->parent->right = z;
      } else {
        x->parent->left = z;
      }
    }
    z->right = x;
    x->parent = z;

    const int old_x_balance = x->balance;
    if (x->balance == z->balance) {
      x->balance = 1;
    } else {
      x->balance = 0;
    }
    if (old_x_balance == -2) {
      z->balance = 0;
    } else if (z->balance <= 0) {
      z->balance = 1;
    } else {
      z->balance = 2;
    }

    z->count = x->count;
    const int x_left_count = x->left == nullptr ? 0 : x->left->count;
    x->count = x_right_count + x_left_count + num_at_x;
    return z;
  }

  shared_ptr<Node> root;
};

int n;
ll t;
vector<ll> a;

void Load() {
  scanf("%d%lld", &n, &t);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
}

void Solve() {
  vector<ll> pref(n, 0);
  pref[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }

  ThresholdMultiset multiset;
  multiset.Insert(0);
  ll ans = 0, segment_max = t - 1;
  for (int i = 0; i < n; ++i) {
    ll min_pref_sum = pref[i] - segment_max;
    ans += multiset.CountNumAtLeast(min_pref_sum);
    multiset.Insert(pref[i]);
  }
  printf("%lld\n", ans);
}

bool CheckNode(shared_ptr<Node> n, int val, int cnt, int bal) {
  bool res = n->count == cnt && n->balance == bal && n->value == val;
  if (!res) {
    printf(
        "Failed! (Expected, Actual) Values %d %d Counts %d %d Balances %d %d\n",
        val, n->value, cnt, n->count, bal, n->balance);
  }
  return res;
}



bool IsLeaf(shared_ptr<Node> n) {
  return n->left == nullptr && n->right == nullptr;
}

bool Test5() {
  ThresholdMultiset m;
  m.Insert(5);
  shared_ptr<Node>& r = m.root;
  if (!CheckNode(r, 5, 1, 0)) return false;
  if (!IsLeaf(r) || r->parent != nullptr) {
    return false;
  }
  return true;
}

bool Test53() {
  ThresholdMultiset m;
  m.Insert(5);
  m.Insert(3);
  auto& r = m.root;
  auto& l = r->left;
  if (!CheckNode(r, 5, 2, -1)) return false;
  if (!CheckNode(r->left, 3, 1, 0)) return false;
  if (r->right != nullptr || r->parent != nullptr || !IsLeaf(l)) {
    return false;
  }
  if (l->parent != r) {
    return false;
  }
  return true;
}

bool Test35() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(5);
  auto& r = m.root;
  auto& rht = r->right;
  if (!CheckNode(r, 3, 2, 1)) return false;
  if (!CheckNode(r->right, 5, 1, 0)) return false;
  if (r->left != nullptr || r->parent != nullptr || !IsLeaf(rht)) {
    return false;
  }
  if (rht->parent != r) {
    return false;
  }
  return true;
}

bool Test55() {
  ThresholdMultiset m;
  m.Insert(5);
  m.Insert(5);
  auto& r = m.root;
  if (!CheckNode(r, 5, 2, 0)) return false;
  if (r->parent != nullptr || !IsLeaf(r)) {
    return false;
  }
  return true;
}

bool Test435() {
  ThresholdMultiset m;
  m.Insert(4);
  m.Insert(3);
  m.Insert(5);
  auto& r = m.root;
  if (!CheckNode(r, 4, 3, 0)) return false;
  auto& rht = r->right;
  auto& lft = r->left;
  if (!CheckNode(rht, 5, 1, 0)) return false;
  if (!CheckNode(lft, 3, 1, 0)) return false;
  if (r->parent != nullptr || !IsLeaf(rht) || !IsLeaf(lft)) return false;
  return true;
}

bool Test3251() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(2);
  m.Insert(5);
  m.Insert(1);
  auto& r = m.root;
  auto& n2 = r->left;
  auto& n5 = r->right;
  auto& n1 = n2->left;
  if (!CheckNode(r, 3, 4, -1)) return false;
  if (!CheckNode(n2, 2, 2, -1)) return false;
  if (!CheckNode(n5, 5, 1, 0)) return false;
  if (!CheckNode(n1, 1, 1, 0)) return false;
  if (r->parent != nullptr || n2->right != nullptr || !IsLeaf(n1) ||
      !IsLeaf(n5))
    return false;
  return true;
}

bool Test325121() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(2);
  m.Insert(5);
  m.Insert(1);
  m.Insert(2);
  m.Insert(1);
  auto& r = m.root;
  if (!CheckNode(r, 3, 6, -1)) return false;
  auto& n2 = r->left;
  auto& n5 = r->right;
  auto& n1 = n2->left;
  if (!CheckNode(n2, 2, 4, -1)) return false;
  if (!CheckNode(n5, 5, 1, 0)) return false;
  if (!CheckNode(n1, 1, 2, 0)) return false;
  if (r->parent != nullptr || n2->right != nullptr || !IsLeaf(n1) ||
      !IsLeaf(n5))
    return false;
  return true;
}

bool Test4261357() {
  ThresholdMultiset m;
  m.Insert(4);
  m.Insert(2);
  m.Insert(6);
  m.Insert(1);
  m.Insert(3);
  m.Insert(5);
  m.Insert(7);
  auto& r = m.root;
  auto& n2 = r->left;
  auto& n6 = r->right;
  auto& n1 = n2->left;
  auto& n3 = n2->right;
  auto& n5 = n6->left;
  auto& n7 = n6->right;
  if (!CheckNode(r, 4, 7, 0)) return false;
  if (!CheckNode(n2, 2, 3, 0)) return false;
  if (!CheckNode(n6, 6, 3, 0)) return false;
  if (!CheckNode(n1, 1, 1, 0)) return false;
  if (!CheckNode(n3, 3, 1, 0)) return false;
  if (!CheckNode(n5, 5, 1, 0)) return false;
  if (!CheckNode(n7, 7, 1, 0)) return false;
  if (r->parent != nullptr || !IsLeaf(n1) || !IsLeaf(n3) || !IsLeaf(n5) ||
      !IsLeaf(n7))
    return false;
  return true;
}

bool Test543() {
  ThresholdMultiset m;
  m.Insert(5);
  m.Insert(4);
  m.Insert(3);
  auto& r = m.root;
  auto& lft = r->left;
  auto& rht = r->right;
  if (!CheckNode(r, 4, 3, 0)) return false;
  if (!CheckNode(lft, 3, 1, 0)) return false;
  if (!CheckNode(rht, 5, 1, 0)) return false;
  if (!IsLeaf(lft) || !IsLeaf(rht)) return false;
  return true;
}

bool Test345() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(4);
  m.Insert(5);
  auto& r = m.root;
  if (!CheckNode(r, 4, 3, 0)) return false;
  auto& lft = r->left;
  auto& rht = r->right;
  if (!CheckNode(lft, 3, 1, 0)) return false;
  if (!CheckNode(rht, 5, 1, 0)) return false;
  if (!IsLeaf(lft) || !IsLeaf(rht)) return false;
  return true;
}

bool Test354() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(5);
  m.Insert(4);
  auto& r = m.root;
  auto& lft = r->left;
  auto& rht = r->right;
  if (!CheckNode(r, 4, 3, 0)) return false;
  if (!CheckNode(lft, 3, 1, 0)) return false;
  if (!CheckNode(rht, 5, 1, 0)) return false;
  if (!IsLeaf(lft) || !IsLeaf(rht)) return false;
  return true;
}

bool Test534() {
  ThresholdMultiset m;
  m.Insert(5);
  m.Insert(3);
  m.Insert(4);
  auto& r = m.root;
  auto& lft = r->left;
  auto& rht = r->right;
  if (!CheckNode(r, 4, 3, 0)) return false;
  if (!CheckNode(lft, 3, 1, 0)) return false;
  if (!CheckNode(rht, 5, 1, 0)) return false;
  if (!IsLeaf(lft) || !IsLeaf(rht)) return false;
  return true;
}

bool Test526413() {
  ThresholdMultiset m;
  m.Insert(5);
  m.Insert(2);
  m.Insert(6);
  m.Insert(4);
  m.Insert(1);
  m.Insert(3);
  auto& r = m.root;
  auto& n2 = r->left;
  auto& n5 = r->right;
  auto& n1 = n2->left;
  auto& n3 = n2->right;
  auto& n6 = n5->right;
  if (!CheckNode(r, 4, 6, 0)) return false;
  if (!CheckNode(n2, 2, 3, 0)) return false;
  if (!CheckNode(n5, 5, 2, 1)) return false;
  if (!CheckNode(n1, 1, 1, 0)) return false;
  if (!CheckNode(n3, 3, 1, 0)) return false;
  if (!CheckNode(n6, 6, 1, 0)) return false;
  if (r->parent != nullptr || n5->left != nullptr || !IsLeaf(n1) ||
      !IsLeaf(n3) || !IsLeaf(n6))
    return false;
  for (int i = 1; i < 8; ++i) {
    if (m.CountNumAtLeast(i) != 7 - i) return false;
  }
  if (m.CountNumAtLeast(-3) != 6) return false;
  return true;
}

bool Test344() {
  ThresholdMultiset m;
  m.Insert(3);
  m.Insert(4);
  m.Insert(4);
  auto& r = m.root;
  auto& rht = r->right;
  if (!CheckNode(r, 3, 3, 1)) return false;
  if (!CheckNode(rht, 4, 2, 0)) return false;
  if (r->parent != nullptr || !IsLeaf(rht)) return false;
  return true;
}

bool Test627145() {
  ThresholdMultiset m;
  m.Insert(6);
  m.Insert(2);
  m.Insert(7);
  m.Insert(1);
  m.Insert(4);
  m.Insert(5);
  auto& r = m.root;
  auto& n2 = r->left;
  auto& n6 = r->right;
  auto& n1 = n2->left;
  auto& n5 = n6->left;
  auto& n7 = n6->right;
  if (!CheckNode(r, 4, 6, 0)) return false;
  if (!CheckNode(n2, 2, 2, -1)) return false;
  if (!CheckNode(n6, 6, 3, 0)) return false;
  if (!CheckNode(n1, 1, 1, 0)) return false;
  if (!CheckNode(n5, 5, 1, 0)) return false;
  if (!CheckNode(n7, 7, 1, 0)) return false;
  if (r->parent != nullptr || n2->right != nullptr || !IsLeaf(n1) ||
      !IsLeaf(n5) || !IsLeaf(n7))
    return false;
  return true;
}

bool Test44665() {
  ThresholdMultiset m;
  m.Insert(4);
  m.Insert(4);
  m.Insert(6);
  m.Insert(6);
  m.Insert(5);
  auto& r = m.root;
  auto& lft = r->left;
  auto& rht = r->right;
  if (!CheckNode(r, 5, 5, 0)) return false;
  if (!CheckNode(lft, 4, 2, 0)) return false;
  if (!CheckNode(rht, 6, 2, 0)) return false;
  if (r->parent != nullptr || !IsLeaf(lft) || !IsLeaf(rht)) return false;
  return true;
}

bool Test123456() {
  ThresholdMultiset m;
  for (int i = 1; i < 7; ++i) m.Insert(i);
  auto& r = m.root;
  auto& n2 = r->left;
  auto& n5 = r->right;
  auto& n1 = n2->left;
  auto& n3 = n2->right;
  auto& n6 = n5->right;
  if (!CheckNode(r, 4, 6, 0)) return false;
  if (!CheckNode(n2, 2, 3, 0)) return false;
  if (!CheckNode(n5, 5, 2, 1)) return false;
  if (!CheckNode(n1, 1, 1, 0)) return false;
  if (!CheckNode(n3, 3, 1, 0)) return false;
  if (!CheckNode(n6, 6, 1, 0)) return false;
  if (r->parent != nullptr || n5->left != nullptr || !IsLeaf(n1) ||
      !IsLeaf(n3) || !IsLeaf(n6))
    return false;
  return true;
}

bool TestMega1() {
  ThresholdMultiset m;
  auto& r = m.root;
  m.Insert(4);
  m.Insert(2);
  m.Insert(7);
  m.Insert(1);
  m.Insert(5);
  m.Insert(3);
  m.Insert(10);
  m.Insert(6);
  m.Insert(8);
  m.Insert(12);
  if (r->right->value != 7) return false;
  if (!CheckNode(r, 4, 10, 1)) return false;

  m.Insert(7);
  if (!CheckNode(r, 4, 11, 1)) return false;
  m.Insert(7);
  m.Insert(5);
  m.Insert(4);
  m.Insert(9);

  if (!CheckNode(r, 7, 15, 0)) return false;
  auto& n5 = r->left->right;
  if (!CheckNode(n5, 5, 3, 1)) return false;
  auto& n4 = r->left;
  if (!CheckNode(n4, 4, 8, 0)) return false;
  auto& n9 = r->right->left->right;
  if (!CheckNode(n9, 9, 1, 0)) return false;
  auto& n10 = r->right;
  if (!CheckNode(n10, 10, 4, -1)) return false;
  if (m.CountNumAtLeast(3) != 13) return false;
  if (m.CountNumAtLeast(7) != 7) return false;
  if (m.CountNumAtLeast(13) != 0) return false;
  if (n10->left->left != nullptr || !IsLeaf(n9) || !IsLeaf(n10->right) ||
      n5->left != nullptr)
    return false;
  return true;
}

void Test() {
  puts(Test5() ? "1 PASS" : "FAIL");
  puts(Test53() ? "2 PASS" : "FAIL");
  puts(Test35() ? "3 PASS" : "FAIL");
  puts(Test55() ? "4 PASS" : "FAIL");
  puts(Test435() ? "5 PASS" : "FAIL");
  puts(Test3251() ? "6 PASS" : "FAIL");
  puts(Test325121() ? "7 PASS" : "FAIL");
  puts(Test4261357() ? "8 PASS" : " FAIL");
  puts(Test543() ? "9 PASS" : "FAIL");
  puts(Test345() ? "10 PASS" : "FAIL");
  puts(Test354() ? "11 PASS" : "FAIL");
  puts(Test534() ? "12 PASS" : "FAIL");
  puts(Test526413() ? "13 PASS" : "FAIL");
  puts(Test344() ? "14 PASS" : "FAIL");
  puts(Test627145() ? "15 PASS" : "FAIL");
  puts(Test44665() ? "16 PASS" : "FAIL");
  puts(Test123456() ? "17 PASS" : "FAIL");
  puts(TestMega1() ? "18 PASS" : " FAIL");
}

int main() {
  

  Load();
  Solve();
  return 0;
}