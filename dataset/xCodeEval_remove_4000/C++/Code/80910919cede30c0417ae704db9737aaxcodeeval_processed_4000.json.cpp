

using namespace std;



using ll = long long;

constexpr double kPI = 3.14159265358979323846264338327950288;















class Multiset {
 public:
  

  Multiset() {}

  

  void InsertNTimes(ll val, ll n) {
    if (root == nullptr) {
      root = make_shared<Node>(val, n, nullptr);
      return;
    }

    shared_ptr<Node> cur = root;
    

    while (cur->value != val &&
           (val < cur->value ? cur->left != nullptr : cur->right != nullptr)) {
      cur = val < cur->value ? cur->left : cur->right;
    }
    

    if (cur->value == val) {
      while (cur != nullptr) {
        AddToSubtreeNTimes(cur, val, n);
        cur = cur->parent;
      }
      return;
    }

    

    const bool id5 = cur->balance == 0;
    if (val < cur->value) {
      cur->left = make_shared<Node>(val, n, cur);
      cur->balance--;
    } else {
      cur->right = make_shared<Node>(val, n, cur);
      cur->balance++;
    }
    AddToSubtreeNTimes(cur, val, n);

    

    

    if (!id5) {
      while (cur->parent != nullptr) {
        cur = cur->parent;
        AddToSubtreeNTimes(cur, val, n);
      }
      return;
    };

    shared_ptr<Node> parent;
    

    

    

    

    while (cur != nullptr) {
      if (cur->balance == 0) break;
      parent = cur->parent;
      if (parent == nullptr) break;
      AddToSubtreeNTimes(parent, val, n);
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
      AddToSubtreeNTimes(cur, val, n);
    } while (cur != nullptr);
  }

  void Insert(ll k) { InsertNTimes(k, 1); }

  

  

  void DeleteNTimes(ll val, ll n) {
    if (root == nullptr) return;
    shared_ptr<Node> cur = root;
    

    while (cur->value != val &&
           (val < cur->value ? cur->left != nullptr : cur->right != nullptr)) {
      cur = val < cur->value ? cur->left : cur->right;
    }
    if (cur->value != val) return;  

    if (Count(cur) > n) {
      

      while (cur != nullptr) {
        AddToSubtreeNTimes(cur, val, -n);
        cur = cur->parent;
      }
      return;
    }
    n = min(Count(cur), n);

    

    

    

    

    shared_ptr<Node> id7;
    bool id6;
    

    

    if (cur->left == nullptr && cur->right == nullptr) {
      

      if (cur->parent != nullptr) {
        id7 = cur->parent;
        id6 = cur->parent->left == cur;
      }
      DeleteChildlessNode(cur);
    } else if (cur->left == nullptr || cur->right == nullptr) {
      

      if (cur->parent != nullptr) {
        id7 = cur->parent;
        id6 = cur->parent->left == cur;
      }
      MoveChildInto(cur);
    } else {
      

      id6 = cur->right->left != nullptr;
      id7 = MoveInorderSuccessorInto(cur);
    }

    

    

    

    

    

    while (id7 != nullptr) {
      AddToSubtreeNTimes(id7, val, -n);
      

      shared_ptr<Node> parent = id7->parent;
      bool id11;
      if (parent != nullptr)
        id11 = parent->left == id7;
      if (id6) {
        id7->balance++;  

        if (id7->balance == 2) {
          shared_ptr<Node> child = id7->right;
          if (child->balance < 0) {
            RotateRight(child);
            RotateLeft(id7);
          } else if (child->balance == 0) {
            RotateLeft(id7);
            while (parent != nullptr) {
              id7 = parent;
              AddToSubtreeNTimes(id7, val, -n);
              parent = id7->parent;
            }
            break;
          } else if (child->balance == 1) {
            RotateLeft(id7);
          }
        } else if (id7->balance == 1) {
          id7->balance = 1;
          while (parent != nullptr) {
            id7 = parent;
            AddToSubtreeNTimes(id7, val, -n);
            parent = id7->parent;
          }
          break;
        } else {  

          id7->balance = 0;
        }
      } else {                      

        id7->balance--;  

        if (id7->balance == -2) {
          shared_ptr<Node> child = id7->left;
          if (child->balance > 0) {
            RotateLeft(child);
            RotateRight(id7);
          } else if (child->balance == 0) {
            RotateRight(id7);
            while (parent != nullptr) {
              id7 = parent;
              AddToSubtreeNTimes(id7, val, -n);
              parent = id7->parent;
            }
            break;
          } else if (child->balance == -1) {
            RotateRight(id7);
          }
        } else if (id7->balance == -1) {
          id7->balance = -1;
          while (parent != nullptr) {
            id7 = parent;
            AddToSubtreeNTimes(id7, val, -n);
            parent = id7->parent;
          }
          break;
        } else {  

          id7->balance = 0;
        }
      }
      id7 = parent;
      id6 = id11;
    }
  }

  void Delete(ll k) { DeleteNTimes(k, 1); }

  

  ll CountNumAtLeast(ll t) { return CountNumAtLeast(t, root); }
  

  ll CountWithin(ll lb, ll ub) {
    return CountNumAtLeast(lb) - CountNumAtLeast(ub + 1);
  }
  

  

  ll AtRank(ll k) {
    if (k > Size()) return -1;
    return AtRank(k, root);
  }
  ll Size() { return SubtreeSize(root); }
  ll Count(ll t) { return Count(t, root); }
  

  ll SumOfGreatest(ll k) {
    if (k <= 0 || root == nullptr) return 0;
    return SumOfGreatest(min(k, Size()), root);
  }
  ll SumOfLeast(ll k) { return SubtreeSum(root) - SumOfGreatest(Size() - k); }

 private:
  struct Node {
    Node(ll v, ll cardinality, shared_ptr<Node> p)
        : value(v),
          subtree_size(cardinality),
          subtree_sum(v * cardinality),
          parent(p) {}
    ll subtree_size;
    ll subtree_sum;
    

    

    int balance = 0;
    ll value;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    shared_ptr<Node> parent;
  };

  

  ll SubtreeSize(shared_ptr<Node> n) {
    if (n == nullptr) return 0;
    return n->subtree_size;
  }
  ll Count(shared_ptr<Node> n) {
    if (n == nullptr) return 0;
    return SubtreeSize(n) - SubtreeSize(n->left) - SubtreeSize(n->right);
  }
  ll SubtreeSum(shared_ptr<Node> n) {
    if (n == nullptr) return 0;
    return n->subtree_sum;
  }

  

  

  void AddToSubtreeNTimes(shared_ptr<Node> node, ll value, ll num_times) {
    node->subtree_size += num_times;
    node->subtree_sum += num_times * value;
  }

  

  

  ll CountNumAtLeast(ll t, shared_ptr<Node> n) {
    if (n == nullptr) return 0;
    const int id1 = SubtreeSize(n->left);
    if (n->value == t) return n->subtree_size - id1;
    if (n->value > t) {
      if (n->left == nullptr)
        return n->subtree_size;
      else
        return n->subtree_size - id1 +
               CountNumAtLeast(t, n->left);
    }
    return CountNumAtLeast(t, n->right);
  }

  

  ll AtRank(ll k, shared_ptr<Node> n) {
    if (SubtreeSize(n->right) >= k) return AtRank(k, n->right);
    if (SubtreeSize(n->right) + Count(n) >= k) return n->value;
    return AtRank(k - SubtreeSize(n->right) - Count(n), n->left);
  }

  

  ll SumOfGreatest(ll k, shared_ptr<Node> n) {
    if (SubtreeSize(n->right) >= k) return SumOfGreatest(k, n->right);
    if (SubtreeSize(n->right) + Count(n) >= k) {
      return SubtreeSum(n->right) + (k - SubtreeSize(n->right)) * n->value;
    }
    return SubtreeSum(n->right) + Count(n) * n->value +
           SumOfGreatest(k - SubtreeSize(n->right) - Count(n), n->left);
  }

  

  ll Count(ll t, shared_ptr<Node> n) {
    if (n == nullptr) return 0;
    if (n->value == t)
      return SubtreeSize(n) - SubtreeSize(n->left) - SubtreeSize(n->right);
    if (n->value > t)
      return Count(t, n->left);
    else
      return Count(t, n->right);
  }

  

  

  void DeleteChildlessNode(shared_ptr<Node> x) {
    if (x == root) {
      root = nullptr;
      return;
    }
    shared_ptr<Node> parent = x->parent;  

    if (parent->left == x)
      parent->left = nullptr;
    else
      parent->right = nullptr;
  }

  

  

  

  void MoveChildInto(shared_ptr<Node> x) {
    if (x == root) {
      if (x->left != nullptr) {
        x->left->parent = nullptr;
        root = x->left;
      } else {
        x->right->parent = nullptr;
        root = x->right;
      }
      return;
    }
    shared_ptr<Node> child = x->left == nullptr ? x->right : x->left;
    shared_ptr<Node> parent = x->parent;
    child->parent = parent;
    if (parent->left == x)
      parent->left = child;
    else
      parent->right = child;
  }

  

  

  

  

  

  

  

  

  shared_ptr<Node> MoveInorderSuccessorInto(shared_ptr<Node> x) {
    ll id13 = Count(x);
    ll id2 = x->value;
    shared_ptr<Node> successor = x->right;
    while (successor->left != nullptr) successor = successor->left;
    shared_ptr<Node> id8 = successor->parent;

    

    x->value = successor->value;
    

    

    shared_ptr<Node> id9 = successor->parent;
    while (id9 != x) {
      id9->subtree_size +=
          id13 - Count(successor);
      id9->subtree_sum +=
          id2 * id13 -
          Count(successor) * successor->value;
      id9 = id9->parent;
    }

    

    if (successor->right == nullptr)
      DeleteChildlessNode(successor);  

    else
      MoveChildInto(successor);

    return id8;
  }

  

  

  

  

  

  

  

  void RotateLeft(shared_ptr<Node> x) {
    const int id4 =
        x->subtree_size - SubtreeSize(x->left) - x->right->subtree_size;

    

    shared_ptr<Node> z = x->right;
    shared_ptr<Node> t = z->left;
    if (root == x) root = z;
    x->right = t;
    if (t != nullptr) t->parent = x;
    z->parent = x->parent;

    if (x->parent != nullptr) {
      if (x == x->parent->left)
        x->parent->left = z;
      else
        x->parent->right = z;
    }
    z->left = x;
    x->parent = z;

    

    const int id0 = x->balance;
    if ((x->balance == 1 && z->balance == 1) ||
        (x->balance == 2 && z->balance == 2))
      x->balance = -1;
    else if (z->balance == 0 && x->balance == 2)  

      x->balance = 1;
    else if (z->balance == 0 && x->balance == 1)  

      x->balance = 0;
    else
      x->balance = 0;
    if (id0 == 2 && z->balance == 0)
      z->balance = -1;
    else if (id0 == 2)
      z->balance = 0;
    else if (z->balance >= 0)
      z->balance = -1;
    else
      z->balance = -2;

    z->subtree_size = x->subtree_size;
    z->subtree_sum = x->subtree_sum;
    x->subtree_size = SubtreeSize(x->left) + SubtreeSize(x->right) + id4;
    x->subtree_sum -= SubtreeSum(z->right) + Count(z) * z->value;
  }

  

  

  void RotateRight(shared_ptr<Node> x) {
    const int id4 =
        x->subtree_size - SubtreeSize(x->right) - x->left->subtree_size;

    

    shared_ptr<Node> z = x->left;
    shared_ptr<Node> t = z->right;
    if (root == x) root = z;
    x->left = t;
    if (t != nullptr) t->parent = x;
    z->parent = x->parent;
    if (x->parent != nullptr) {
      if (x == x->parent->right)
        x->parent->right = z;
      else
        x->parent->left = z;
    }
    z->right = x;
    x->parent = z;

    

    const int id0 = x->balance;
    if ((x->balance == -1 && z->balance == -1) ||
        (x->balance == -2 && z->balance == -2))
      x->balance = 1;
    else if (z->balance == 0 && x->balance == -2)  

      x->balance = -1;
    else if (z->balance == 0 && x->balance == -1)  

      x->balance = 0;
    else
      x->balance = 0;
    if (id0 == -2 && z->balance == 0)
      z->balance = 1;
    else if (id0 == -2)
      z->balance = 0;
    else if (z->balance <= 0)
      z->balance = 1;
    else
      z->balance = 2;

    z->subtree_size = x->subtree_size;
    z->subtree_sum = x->subtree_sum;
    x->subtree_size = SubtreeSize(x->left) + SubtreeSize(x->right) + id4;
    x->subtree_sum -= SubtreeSum(z->left) + Count(z) * z->value;
  }

  shared_ptr<Node> root;
};



ll Power(ll a, ll pow) {
  if (pow == 0) return 1;
  if (pow == 1) return a;

  

  ll x = Power(a, pow / 2);
  ll y = x * x;
  if (pow % 2 == 0) return y;
  return y * a;
}


ll n, k, A, B;
Multiset mset;

void Load() {
  scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
  for (int i = 0; i < k; ++i) {
    ll avg_pos;
    scanf("%lld", &avg_pos);
    mset.Insert(avg_pos - 1);
  }
}

ll MinPow(ll left_index, ll right_index, ll id10) {
  if (id10 == 0) {
    return A;
  }
  if (left_index == right_index) {
    return B * id10;
  }
  ll id3 = B * id10 * (right_index - left_index + 1);
  ll half = (right_index + left_index) / 2;
  if (id10 == 1) {
    return min(id3, MinPow(left_index, half, 1) + A);
  }
  ll id12 = mset.CountWithin(left_index, half);
  ll id14 =
      MinPow(left_index, half, id12) +
      MinPow(half + 1, right_index, id10 - id12);
  return min(id3, id14);
}

void Solve() {
  ll left_index = 0;
  ll right_index = Power(2, n) - 1;
  printf("%lld\n", MinPow(left_index, right_index, k));
}


int main() {
  Load();
  Solve();
}