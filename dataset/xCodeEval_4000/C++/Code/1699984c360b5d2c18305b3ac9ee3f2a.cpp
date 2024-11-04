#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <tuple>
#include <utility>
#include <map>

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <limits>

#define RELEASE
#ifdef RELEASE
#  define fprintf(...) void(0)
#endif  

template <class Tp>
class RedBlackTree {
  

  static constexpr Tp MAX{0, 0};

public:
  struct Node {
    Node *children[2]={nullptr, nullptr}, *parent=nullptr;
    Tp value;
    size_t lnum=0;
    enum Color { RED, BLACK } color=RED;
    Node(const Tp &x): value(x) {}

    const Node *successor() const {
      const Node *cur=this;
      if (children[1]) {
        cur = cur->children[1];
        while (cur->children[0]) cur = cur->children[0];
        return cur;
      }
      while (true) {
        if (!cur->parent) return nullptr;
        if (cur == cur->parent->children[0]) return cur->parent;
        cur = cur->parent;
      }
    }

    Node *successor() {
      Node *cur=this;
      if (children[1]) {
        cur = cur->children[1];
        while (cur->children[0]) cur = cur->children[0];
        return cur;
      }
      while (true) {
        if (!cur->parent) return nullptr;
        if (cur == cur->parent->children[0]) return cur->parent;
        cur = cur->parent;
      }
    }

    const Node *predecessor() const {
      const Node *cur=this;
      if (children[0]) {
        cur = cur->children[0];
        while (cur->children[1]) cur = cur->children[1];
        return cur;
      }
      while (true) {
        if (!cur->parent) return nullptr;
        if (cur == cur->parent->children[1]) return cur->parent;
        cur = cur->parent;
      }
    }

    Node *predecessor() {
      Node *cur=this;
      if (children[0]) {
        cur = cur->children[0];
        while (cur->children[1]) cur = cur->children[1];
        return cur;
      }
      while (true) {
        if (!cur->parent) return nullptr;
        if (cur == cur->parent->children[1]) return cur->parent;
        cur = cur->parent;
      }
    }

    const Node *root() const {
      const Node *cur=this;
      while (cur->parent) cur = cur->parent;
      return cur;
    }

    const Node *first() const {
      const Node *cur=root();
      while (cur->children[0]) cur = cur->children[0];
      return cur;
    }

    const Node *last() const {
      const Node *cur=root();
      while (cur->children[1]) cur = cur->children[1];
      return cur;
    }
  };

private:
  Node *root=nullptr;
  size_t size_=0;

  RedBlackTree(Node *root): root(root) {
    if (!root) {
      size_ = 0;
      return;
    }
    root->parent = nullptr;
    root->color = Node::BLACK;
    reset_size();
  }

  bool is_red(Node *node) const {
    return node && node->color == Node::RED;
  }

  size_t black_height() const {
    size_t res=0;
    for (Node *cur=root; cur; cur=cur->children[0])
      if (cur->color == Node::BLACK) ++res;

    return res;
  }

  void swap(RedBlackTree &oth) {
    std::swap(size_, oth.size_);
    std::swap(root, oth.root);
  }

  void rotate(Node *cur, int dir) {
    


    Node *child=cur->children[!dir];
    assert(child);
    cur->children[!dir] = child->children[dir];
    if (child->children[dir])
      child->children[dir]->parent = cur;

    child->parent = cur->parent;
    if (!cur->parent) {
      root = child;
    } else if (cur == cur->parent->children[dir]) {
      cur->parent->children[dir] = child;
    } else {
      cur->parent->children[!dir] = child;
    }
    child->children[dir] = cur;
    cur->parent = child;

    if (dir == 0) {
      cur->parent->lnum += cur->lnum+1;
    } else if (dir == 1) {
      cur->lnum -= cur->parent->lnum+1;
    } else {
      assert(false);
    }
  }

  void insert_fixup(Node *cur) {
    


    while (is_red(cur->parent)) {
      Node *gparent=cur->parent->parent;
      assert(gparent);

      int uncle_dir=(cur->parent != gparent->children[1]);
      Node *uncle=gparent->children[uncle_dir];

      if (is_red(uncle)) {
        cur->parent->color = uncle->color = Node::BLACK;
        gparent->color = Node::RED;
        cur = gparent;
        continue;
      }
      if (cur == cur->parent->children[uncle_dir]) {
        cur = cur->parent;
        rotate(cur, !uncle_dir);
      }
      cur->parent->color = Node::BLACK;
      cur->parent->parent->color = Node::RED;
      rotate(gparent, uncle_dir);
    }
    root->color = Node::BLACK;
  }

  void erase_fixup(Node *cur, Node *parent) {
    

    while (cur != root && !is_red(cur)) {
      int sibling_dir=(cur == parent->children[0]);
      Node *sibling=parent->children[sibling_dir];

      if (is_red(sibling)) {
        sibling->color = Node::BLACK;
        parent->color = Node::RED;
        rotate(parent, !sibling_dir);
        sibling = parent->children[sibling_dir];
      }

      if (sibling) {
        if (!is_red(sibling->children[0]) && !is_red(sibling->children[1])) {
          sibling->color = Node::RED;
          cur = parent;
          parent = cur->parent;
          continue;
        }

        if (!is_red(sibling->children[sibling_dir])) {
          if (sibling->children[!sibling_dir])
            sibling->children[!sibling_dir]->color = Node::BLACK;

          sibling->color = Node::RED;
          rotate(sibling, sibling_dir);
          sibling = parent->children[sibling_dir];
          assert(sibling);
        }

        sibling->color = parent->color;
        sibling->children[sibling_dir]->color = Node::BLACK;
      }

      parent->color = Node::BLACK;
      rotate(parent, !sibling_dir);
      cur = root;
      parent = nullptr;
    }
    if (cur) cur->color = Node::BLACK;
  }

  void propagate_lnum(Node *cur, size_t diff) {
    

    assert(cur);
    while (cur->parent) {
      if (cur == cur->parent->children[0])
        cur->parent->lnum += diff;
      cur = cur->parent;
    }
  }

  void reset_size() {
    size_ = calc_size(root);
  }

  size_t calc_size(const Node *subroot) const {
    size_t res=0;
    while (subroot) {
      res += subroot->lnum+1;
      subroot = subroot->children[1];
    }
    return res;
  }

  size_t size(const Node *subroot) const {
    if (subroot == root) return size_;
    if (subroot == subroot->parent->children[0])
      return subroot->parent->lnum;
    return calc_size(subroot);
  }

  void release() {
    root = nullptr;
    size_ = 0;
  }

public:
  RedBlackTree() = default;

  template <class ForwardIt>
  RedBlackTree(ForwardIt first, ForwardIt last) {
    root = new Node(*first);
    root->color = Node::BLACK;
    Node *prev=root;
    for (ForwardIt it=first; ++it!=last;) {
      Node *node=new Node(*it);
      assert(node->color == Node::RED);
      prev->children[1] = node;
      node->parent = prev;
      insert_fixup(node);
      prev = node;
    }
    size_ = last-first;
  }

  RedBlackTree(size_t n, Tp value=Tp()) {
    root = new Node(value);
    root->color = Node::BLACK;
    Node *prev=root;
    for (size_t i=0; i<n; ++i) {
      Node *node=new Node(value);
      assert(node->color == Node::RED);
      prev->children[1] = node;
      node->parent = prev;
      insert_fixup(node);
      prev = node;
    }
    size_ = n;
  }

  struct Node;

  size_t size() const {
    return size_;
  }

  const Node *first() const {
    if (!root) return nullptr;
    const Node *cur=root;
    while (cur->children[0]) cur = cur->children[0];
    return cur;
  }

  Node *first() {
    if (!root) return nullptr;
    Node *cur=root;
    while (cur->children[0]) cur = cur->children[0];
    return cur;
  }

  const Node *last() const {
    if (!root) return nullptr;
    const Node *cur=root;
    while (cur->children[1]) cur = cur->children[1];
    return cur;
  }

  Node *last() {
    if (!root) return nullptr;
    Node *cur=root;
    while (cur->children[1]) cur = cur->children[1];
    return cur;
  }

  const Node *successor(const Node *cur) const {
    return cur->successor();
  }

  Node *successor(Node *cur) {
    return cur->successor();
  }

  Node *insert_front(Node *node) {
    ++size_;
    node->lnum = 0;
    if (!root) {
      node->color = Node::BLACK;
      root = node;
      return root;
    }
    Node *cur=root;
    ++root->lnum;
    while (cur->children[0]) {
      cur = cur->children[0];
      ++cur->lnum;
    }
    cur->children[0] = node;
    node->parent = cur;
    node->color = Node::RED;
    insert_fixup(node);
    return root;
  }

  Node *insert_front(const Tp &x) {
    return insert_front(new Node(x));
  }

  Node *insert_back(Node *node) {
    ++size_;
    node->lnum = 0;
    if (!root) {
      node->color = Node::BLACK;
      root = node;
      return root;
    }
    Node *cur=last();
    cur->children[1] = node;
    node->parent = cur;
    node->color = Node::RED;
    insert_fixup(node);
    return root;
  }

  Node *insert_back(const Tp &x) {
    return insert_back(new Node(x));
  }

  Node *insert_next(Node *node, Node *dst) {
    if (!node) return root;

    node->children[0] = node->children[1] = nullptr;
    node->lnum = 0;

    if (!dst) {
      

      

      

      

      

      return insert_back(node);
    }

    node->color = Node::RED;
    if (dst->children[1]) {
      dst = dst->successor();
      assert(!dst->children[0]);
      dst->children[0] = node;
    } else {
      dst->children[1] = node;
    }
    node->parent = dst;

    ++size_;
    propagate_lnum(node, 1);
    insert_fixup(node);
    return root;
  }

  Node *erase(Node *cur) {
    if (!cur) return nullptr;

    --size_;
    Node *y=cur;
    if (cur->children[0] && cur->children[1]) y = successor(y);
    assert(y);

    Node *x=y->children[0];
    if (!x) x = y->children[1];
    if (x) x->parent = y->parent;
    if (!y->parent) {
      root = x;
    } else {
      propagate_lnum(y, -1);
      int ydir=(y == y->parent->children[1]);
      y->parent->children[ydir] = x;
    }
    Node *xparent=y->parent;  

    bool fix_needed=(y->color == Node::BLACK);
    if (y != cur) {
      

      assert(!y->children[0]);

      y->parent = cur->parent;
      y->children[0] = cur->children[0];
      y->children[1] = cur->children[1];
      y->color = cur->color;
      y->lnum = cur->lnum;

      if (y->children[0]) y->children[0]->parent = y;
      if (y->children[1]) y->children[1]->parent = y;
      if (y->parent) {
        y->parent->children[cur == cur->parent->children[1]] = y;
      } else {
        root = y;
      }
      if (xparent == cur) {
        xparent = y;
        if (x) x->parent = y;
      }
    }

    if (fix_needed) {
      erase_fixup(x, xparent);
    }

    cur->color = Node::RED;
    cur->children[0] = cur->children[1] = cur->parent = nullptr;
    cur->lnum = 0;
    return root;
  }

  Node *merge(RedBlackTree &oth) {
    if (!oth.root) return root;
    if (!root) {
      swap(oth);
      return root;
    }

    size_t bh1=black_height(), bh2=oth.black_height();
    if (bh1 >= bh2) {
      Node *med=oth.first();
      oth.erase(med);
      merge(oth, med);
    } else {
      Node *med=last();
      erase(med);
      merge(oth, med);
    }
    return root;
  }

  Node *merge(RedBlackTree &oth, Node *med) {
    if (!med) {
      merge(oth);
      return root;
    }

    if (!root && !oth.root) {
      size_ = 1;
      root = med;
      root->color = Node::BLACK;
      root->lnum = 0;
      return root;
    }

    med->color = Node::RED;
    if (!root) {
      oth.insert_front(med);
      swap(oth);
      return root;
    }
    if (!oth.root) {
      med->lnum = 0;
      insert_back(med);
      return root;
    }

    size_t bh1=black_height(), bh2=oth.black_height();
    Node *cur;
    if (bh1 >= bh2) {
      cur = root;
      while (bh1 >= bh2) {
        if (cur->color == Node::BLACK && bh1-- == bh2) break;
        cur = cur->children[1];
      }
      med->children[0] = cur;
      med->children[1] = oth.root;
      med->parent = cur->parent;

      if (!med->parent) {
        root = med;
        med->color = Node::BLACK;
      } else {
        med->parent->children[1] = med;
      }
      cur->parent = oth.root->parent = med;
    } else {
      cur = oth.root;
      while (bh1 <= bh2) {
        if (cur->color == Node::BLACK && bh1 == bh2--) break;
        cur = cur->children[0];
      }
      med->children[0] = root;
      med->children[1] = cur;
      med->parent = cur->parent;

      med->parent->children[0] = med;
      cur->parent = root->parent = med;

      root = oth.root;
      propagate_lnum(med, size_+1);
    }

    med->lnum = calc_size(med->children[0]);
    size_ += oth.size_+1;
    oth.release();
    insert_fixup(med);
    return root;
  }

  std::pair<RedBlackTree, RedBlackTree> split(Node *crit) {
    if (!crit) {
      RedBlackTree left(*this);
      release();
      return {left, nullptr};
    }

    Node *crit_orig=crit;
    RedBlackTree left(crit->children[0]), right(crit->children[1]);
    crit->children[0] = crit->children[1] = nullptr;

    if (crit == root) {
      release();
      return {left, right};
    }

    int crit_dir=(crit == crit->parent->children[1]);
    crit = crit->parent;

    while (crit) {
      RedBlackTree subtree(crit->children[!crit_dir]);
      crit->children[!crit_dir] = nullptr;
      Node *med=crit;
      bool merge_left=crit_dir;
      if (crit != root)
        crit_dir = (crit == crit->parent->children[1]);
      crit = crit->parent;

      med->parent = nullptr;
      med->children[0] = med->children[1] = nullptr;
      if (merge_left) {
        subtree.merge(left, med);
        left.swap(subtree);
      } else {
        right.merge(subtree, med);
      }
    }

    release();
    left.reset_size();
    right.reset_size();

    crit_orig->lnum = 0;
    crit_orig->parent = nullptr;
    return {left, right};
  }

  Node *node_at(size_t i) {
    Node *res=root;
    while (res->lnum != i) {
      if (res->lnum < i) {
        i -= res->lnum+1;
        res = res->children[1];
      } else {
        res = res->children[0];
      }
    }
    return res;
  }

  Node *node_at(size_t pos, const Tp &val) {
    Node *node=node_at(pos);
    node->value = val;
    reset_min(node);
    return node;
  }

  Node *upper_bound(Tp value) {
    if (root == nullptr) return nullptr;
    Node *res=root;
    while (true) {
      int dir=(!(value < res->value));
      Node *tmp=res->children[dir];
      if (tmp == nullptr) {
        break;
      }
      res = tmp;
    }
    if (!(value < res->value))
      return res->successor();
    return res;
  }

  
  bool verify() const {
#ifdef RELEASE
    return true;
#endif

    auto report=[](const char *s) {
      fprintf(stderr, "%sviolated:%s %s%s%s\n",
              "\x1b[31;1m", "\x1b[0m", "\x1b[37;1m", s, "\x1b[0m");
    };

    bool violated=false;
    if (root->color == Node::RED) {
      violated = true;
      report("root node is red");
    }

    if (!root) {
      fprintf(stderr, "================================================\n");
      assert(size_ == 0);
      fprintf(stderr, "size: 0\n");
    }

    bool reached=false;
    size_t bheight=-1;
    size_t i=0;
    std::function<void (Node *, int, size_t)> dfs=[&](
        Node *subroot, int depth, size_t bh) {

      if (!subroot) return;

      if (subroot->color == Node::RED) {
        

        

        if (subroot->parent && subroot->parent->color == Node::RED) {
          violated = true;
          report("two consecutive nodes are red");
        }
      } else {
        ++bh;
      }

      Node *left=subroot->children[0], *right=subroot->children[1];

      if (!(left && right)) {
        if (!reached) {
          bheight = bh;
          reached = true;
        } else if (bheight != bh) {
          violated = true;
          report("different number of black nodes in two root-leaf paths");
        }
      }

      if (right) dfs(right, depth+1, bh);

      

      fprintf(stderr, "%zu\t%s%*s(%d)%s (%zu) [%zu]%s\n",
              size_-1-i,
              is_red(subroot)? "\x1b[31;1m":"\x1b[37;1m",
              depth*2+2, "  ",
              subroot->value,
              "\x1b[0m", bh, subroot->lnum, 
              (left && right)? "":" *");

      ++i;
      if (left) dfs(left, depth+1, bh);
    };

    fprintf(stderr, "================================================\n");
    fprintf(stderr, "size: %zu\n", size_);
    dfs(root, 0, 0);
    fprintf(stderr, "================================================\n");
    return !violated;
  }
  
};

int main() {
  size_t n;
  scanf("%zu", &n);

  using interval = std::pair<intmax_t, intmax_t>;
  std::vector<interval> rl(n);
  std::map<interval, size_t> dec;
  for (size_t i = 0; i < n; ++i) {
    scanf("%jd %jd", &rl[i].second, &rl[i].first);
    dec[rl[i]] = i;
  }

  std::sort(rl.begin(), rl.end());

  std::vector<int> res(n);
  RedBlackTree<int> rbt;

  using node = RedBlackTree<int>::Node;
  std::map<int, node*> tsurai;

  size_t nya = 0;
  for (const auto& p: rl) {
    int l, r;
    std::tie(r, l) = p;
    node* newnode = new node(l);
    tsurai[l] = newnode;
    

    if (nya == 0) {
      rbt.insert_front(newnode);
      ++nya;
      

      continue;
    }

    if (rbt.node_at(0)->value > l) {
      res[dec[p]] = nya;
    } else {
      size_t lb = 0;
      size_t ub = nya;
      

      while (ub-lb > 1) {
        size_t mid = (lb+ub) >> 1;
        ((rbt.node_at(mid)->value < l)? lb:ub) = mid;
      }
      res[dec[p]] = nya-ub;
    }
    


    

    


    if (rbt.node_at(0)->value > l) {
      rbt.insert_front(newnode);
    } else if (rbt.node_at(nya-1)->value < l) {
      rbt.insert_back(newnode);
    } else {
      node* ub = rbt.upper_bound(l)->predecessor();
      rbt.insert_next(newnode, ub);
    }
    ++nya;
    

  }

  for (int r: res) printf("%d\n", r);
}
