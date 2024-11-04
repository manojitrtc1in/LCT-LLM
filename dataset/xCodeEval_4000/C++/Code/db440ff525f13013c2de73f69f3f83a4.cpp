#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>
#include <cinttypes>
 
#define REPEAT(token, num) for (token = 0; token < num; token++)
static inline int64_t min(int64_t length1, int64_t length2) { return (length1 < length2) ? length1 : length2; }
static inline int64_t max(int64_t length1, int64_t length2) { return (length1 > length2) ? length1 : length2; }
 


#ifdef DEBUG
#define PRINTF printf
#else
#define PRINTF(...)
#endif
 
typedef int64_t num_items;
 
namespace treap {
    template <class item_key, class item_value> struct treap;
    
    template <class item_key, class item_value> struct node {
        item_key key;
        item_value value;
        num_items priority;
        num_items size;
        num_items need;
        num_items excess;
        treap<item_key, item_value> left;
        treap<item_key, item_value> right;
    };
    
    template <class item_key, class item_value> struct treap_pair {
        treap<item_key, item_value> left;
        treap<item_key, item_value> right;
        treap_pair() : left(nullptr), right(nullptr) {};
    };
 
    template <class item_key, class item_value> static treap<item_key, item_value> newTreapNode(item_key key, item_value value);
    
    template <class item_key, class item_value> struct treap {
        node<item_key, item_value> *root;
        treap() { root = nullptr; }
        treap(node<item_key, item_value> *ptr) { root = ptr; }
        
        num_items getSize() { return (root == nullptr) ? 0 : root->size; }
        num_items getNeed() { return (root == nullptr) ? 0 : root->need; }
        num_items getExcess() { return (root == nullptr) ? 0 : root->excess; }
        void updateProperties() {
            if (root != nullptr) {
                root->size = 1+root->left.getSize()+root->right.getSize();        
                num_items needLeft = root->left.getNeed();
                num_items excessRight = root->right.getExcess();
                if (root->value > 0) excessRight++;
                else needLeft++;
 
                num_items nodesMatched = needLeft;
                if (excessRight < nodesMatched) nodesMatched = excessRight;
 
                root->need = needLeft+root->right.getNeed()-nodesMatched;
                root->excess = root->left.getExcess()+excessRight-nodesMatched;
            }
        }
        
        static treap<item_key, item_value> mergeTreaps(treap<item_key, item_value> left, treap<item_key, item_value> right) {
            if (left.root == nullptr) return right;
            if (right.root == nullptr) return left;
            if (left.root->priority > right.root->priority) {
                left.root->right = mergeTreaps(left.root->right, right);
                left.updateProperties();
                return left;
            } else {
                right.root->left = mergeTreaps(left, right.root->left);
                right.updateProperties();
                return right;
            }
        }
        
        

        

        treap_pair<item_key, item_value> splitByKey(item_key key, bool exclusive) {
            treap_pair<item_key, item_value> answer;
            if (root == nullptr) return answer;
 
            

            if (exclusive ? (key <= root->key) : (key < root->key)) {
                answer = root->left.splitByKey(key, exclusive);
                

                root->left = answer.right;
                

                answer.right = *this;
            }
            

            else {
                answer = root->right.splitByKey(key, exclusive);
                

                

                root->right = answer.left;
                

                answer.left = *this;
            }
            updateProperties();
            return answer;
        }
        
        item_value getKeyRangeSum(item_key startKey, item_key endKey) {
            

            treap_pair<item_key, item_value> parts = splitByKey(endKey, false);
            

            treap_pair<item_key, item_value> parts2 = parts.left.splitByKey(startKey, true);
            

            item_value result = parts2.right.getSum();
            

            root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
            return result;
        }
 
        bool addElementByKey(item_key newKey, item_value newValue, bool exclusive) {
            

            treap_pair<item_key, item_value> parts = splitByKey(newKey, false);
            

            if (exclusive) {
                treap_pair<item_key, item_value> parts2 = parts.left.splitByKey(newKey, true);
                if (parts2.right.root != nullptr) {
                    root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
                    return false;
                }
                parts.left = mergeTreaps(parts2.left, parts2.right);
            }
 
            

            treap<item_key, item_value> storeTreap = newTreapNode<item_key, item_value>(newKey, newValue);
            

            root = mergeTreaps(mergeTreaps(parts.left, storeTreap), parts.right).root;
 
            return true;
        }
 
        bool removeElementByKey(item_key oldKey) {
            

            treap_pair<item_key, item_value> parts = splitByKey(oldKey, false);
            

            treap_pair<item_key, item_value> parts2 = parts.left.splitByKey(oldKey, true);
            

            bool actuallyRemoved = parts2.right.root != nullptr;
            

            root = mergeTreaps(parts2.left, parts.right).root;
 
            return actuallyRemoved;
        }
 
        

        

        treap_pair<item_key, item_value> splitByPos(num_items pos) {
            treap_pair<item_key, item_value> answer;
            if (this->root == nullptr) return answer;
            if (pos > getSize()) {
                answer.left = *this;
                return answer;
            }
 
            num_items leftSize = root->left.getSize();
            

            if (pos <= leftSize) {
                answer = root->left.splitByPos(pos);
                

                root->left = answer.right;
                

                answer.right = *this;
            }
            

            else {
                

                answer = root->right.splitByPos(pos-leftSize-1);
                

                

                root->right = answer.left;
                

                answer.left = *this;
            }
            updateProperties();
            return answer;
        }
 
        item_value getIntervalSum(num_items startPos, num_items endPos) {
            

            treap_pair<item_key, item_value> parts = splitByPos(endPos+1);
            

            treap_pair<item_key, item_value> parts2 = parts.left.splitByPos(startPos);
            

            item_value result = parts2.right.getSum();
            

            root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
            return result;
        }
 
        void addElementByPos(num_items newPos, item_key newKey, item_value newValue) {
            

            treap_pair<item_key, item_value> parts = splitByPos(newPos);
            

            treap<item_key, item_value> storeTreap = newTreapNode<item_key, item_value>(newKey, newValue);
            

            root = mergeTreaps(mergeTreaps(parts.left, storeTreap), parts.right).root;
        }
 
        bool removeElementByPos(num_items oldPos) {
            

            if (oldPos+1 > getSize()) return false;
            if (oldPos < 0) return false;
 
            

            treap_pair<item_key, item_value> parts = splitByPos(oldPos+1);
            

            treap_pair<item_key, item_value> parts2 = parts.left.splitByPos(oldPos);
            

            root = mergeTreaps(parts2.left, parts.right).root;
 
            return true;
        }
        
        item_value *getValueAtPos(num_items pos) {
            

            if (pos < 0) return nullptr;
            if (pos > getSize()) return nullptr;
 
            treap<item_key, item_value> curTreap = *this;
            

            while (curTreap.root->left.size() != pos) {
                

                

                if (curTreap.root->left.size() < pos) {
                    pos -= curTreap.root->left.size()+1;
                    curTreap = curTreap.root->right;
                }
                

                else curTreap = curTreap.root->left;
                
                if (curTreap.root == nullptr) puts("Treap size values are corrupted"), exit(1);
            }
            

            return &(curTreap.root->value);
        }
 
        item_key getHighestNeed() {
            num_items index = getNeed()-1;
            treap<item_key, item_value> curTreap = *this;
            
            while (true) {
                num_items needLeft = curTreap.root->left.getNeed();
                num_items excessRight = curTreap.root->right.getExcess();
                if (curTreap.root->value > 0) excessRight++;
                else if (excessRight <= needLeft) needLeft++;
                if (excessRight < needLeft) needLeft -= excessRight;
                else needLeft = 0;
                
                if ((curTreap.root->value == 0) && (excessRight == 0) && (needLeft == index+1)) return curTreap.root->key;
                if (index >= needLeft) index -= needLeft, curTreap = curTreap.root->right;
                else curTreap = curTreap.root->left;
            }
        }
    };
        
    static const num_items MAX_SPACE = 4000000;
    template <class item_key, class item_value> static node<item_key, item_value> space[MAX_SPACE];
    template <class item_key, class item_value> static num_items numSpaceUsed;
    template <class item_key, class item_value> static treap<item_key, item_value> newTreapNode(item_key key, item_value value) {
        if (numSpaceUsed<item_key, item_value> >= MAX_SPACE) puts("Ran out of treap node space"), exit(1);
 
        space<item_key, item_value>[numSpaceUsed<item_key, item_value>].priority = rand();
        space<item_key, item_value>[numSpaceUsed<item_key, item_value>].key = key;
        space<item_key, item_value>[numSpaceUsed<item_key, item_value>].value = value;
        space<item_key, item_value>[numSpaceUsed<item_key, item_value>].left = treap<item_key, item_value>();
        space<item_key, item_value>[numSpaceUsed<item_key, item_value>].right = treap<item_key, item_value>();
 
        treap<item_key, item_value> newNode(space<item_key, item_value>+numSpaceUsed<item_key, item_value>);
        newNode.updateProperties();
 
        numSpaceUsed<item_key, item_value>++;
        return newNode;
    }
}
 
struct item_key {
    int64_t cost;
    int64_t index;
 
    bool operator<(item_key other) {
        if (cost != other.cost) return cost < other.cost;
        return index < other.index;
    }
    bool operator<=(item_key other) {
        if (cost != other.cost) return cost <= other.cost;
        return index <= other.index;
    }
};
typedef int64_t item_value;
typedef int64_t num_items;
 
typedef int64_t num_dishes;
typedef int64_t num_pupils;
typedef int64_t cost;
typedef int64_t num_queries;
 
num_dishes numDishes;
num_pupils numPupils;
num_queries numQueries;
cost dishes[300010], pupils[300010];
treap::treap<item_key, item_value> dishesAndPupils;
 
num_dishes i;
num_pupils j, queryIndex;
item_key storeKey;
cost queryCost;
num_queries queryType;
 
int main() {
    scanf("%" PRId64 " %" PRId64, &numDishes, &numPupils);
    REPEAT(i, numDishes) {
        scanf("%" PRId64, dishes+i);
        
        storeKey.cost = dishes[i];
        storeKey.index = i;
        

        dishesAndPupils.addElementByKey(storeKey, 0, false);
    }
    REPEAT(i, numPupils) {
        scanf("%" PRId64, pupils+i);
        
        storeKey.cost = pupils[i];
        storeKey.index = i+numDishes;
        

        dishesAndPupils.addElementByKey(storeKey, 1, false);
    }
    
    scanf("%" PRId64, &numQueries);
    while (numQueries--) {
        scanf("%" PRId64 " %" PRId64 " %" PRId64, &queryType, &queryIndex, &queryCost);
        queryIndex--;
        storeKey.cost = (queryType == 1) ? dishes[queryIndex] : pupils[queryIndex];
        storeKey.index = (queryType == 1) ? queryIndex : (queryIndex+numDishes);
        bool success = dishesAndPupils.removeElementByKey(storeKey);
        if (!success) puts("NOES"), exit(1);
        
        storeKey.cost = queryCost;
        if (queryType == 1) dishes[queryIndex] = queryCost;
        else pupils[queryIndex] = queryCost;
        dishesAndPupils.addElementByKey(storeKey, (queryType == 2), false);
        

        
        if (dishesAndPupils.getNeed() > 0) printf("%" PRId64 "\n", dishesAndPupils.getHighestNeed().cost);
        else puts("-1");
    }
    
    exit(0);
}