




 

static inline int64_t min(int64_t length1, int64_t length2) { return (length1 < length2) ? length1 : length2; }
static inline int64_t max(int64_t length1, int64_t length2) { return (length1 > length2) ? length1 : length2; }
 








typedef int32_t num_items;

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
    
    template <class item_key, class item_value> struct id0 {
        treap<item_key, item_value> left;
        treap<item_key, item_value> right;
        id0() : left(nullptr), right(nullptr) {};
    };

    template <class item_key, class item_value> struct node_manager;
    
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
                num_items id1 = root->right.getExcess();
                if (root->value > 0) id1++;
                else needLeft++;

                num_items nodesMatched = needLeft;
                if (id1 < nodesMatched) nodesMatched = id1;

                root->need = needLeft+root->right.getNeed()-nodesMatched;
                root->excess = root->left.getExcess()+id1-nodesMatched;
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
        
        

        

        id0<item_key, item_value> splitByKey(item_key key, bool exclusive) {
            id0<item_key, item_value> answer;
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
            

            id0<item_key, item_value> parts = splitByKey(endKey, false);
            

            id0<item_key, item_value> parts2 = parts.left.splitByKey(startKey, true);
            

            item_value result = parts2.right.getSum();
            

            root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
            return result;
        }

        bool addElementByKey(item_key newKey, item_value newValue, bool exclusive) {
            

            id0<item_key, item_value> parts = splitByKey(newKey, false);
            

            if (exclusive) {
                id0<item_key, item_value> parts2 = parts.left.splitByKey(newKey, true);
                if (parts2.right.root != nullptr) {
                    root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
                    return false;
                }
                parts.left = mergeTreaps(parts2.left, parts2.right);
            }

            

            treap<item_key, item_value> id5 = node_manager<item_key, item_value>::newTreapNode(newKey, newValue);
            

            root = mergeTreaps(mergeTreaps(parts.left, id5), parts.right).root;

            return true;
        }

        bool removeElementByKey(item_key oldKey) {
            

            id0<item_key, item_value> parts = splitByKey(oldKey, false);
            

            id0<item_key, item_value> parts2 = parts.left.splitByKey(oldKey, true);
            

            bool actuallyRemoved = parts2.right.root != nullptr;
            

            root = mergeTreaps(parts2.left, parts.right).root;

            return actuallyRemoved;
        }

        

        

        id0<item_key, item_value> splitByPos(num_items pos) {
            id0<item_key, item_value> answer;
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
            

            id0<item_key, item_value> parts = splitByPos(endPos+1);
            

            id0<item_key, item_value> parts2 = parts.left.splitByPos(startPos);
            

            item_value result = parts2.right.getSum();
            

            root = mergeTreaps(mergeTreaps(parts2.left, parts2.right), parts.right).root;
            return result;
        }

        void addElementByPos(num_items newPos, item_key newKey, item_value newValue) {
            

            id0<item_key, item_value> parts = splitByPos(newPos);
            

            treap<item_key, item_value> id5 = node_manager<item_key, item_value>::newTreapNode(newKey, newValue);
            

            root = mergeTreaps(mergeTreaps(parts.left, id5), parts.right).root;
        }

        bool removeElementByPos(num_items oldPos) {
            

            if (oldPos+1 > getSize()) return false;
            if (oldPos < 0) return false;

            

            id0<item_key, item_value> parts = splitByPos(oldPos+1);
            

            id0<item_key, item_value> parts2 = parts.left.splitByPos(oldPos);
            

            root = mergeTreaps(parts2.left, parts.right).root;

            return true;
        }
        
        item_value *getValueAtPos(num_items pos) {
            

            if (pos < 0) return nullptr;
            if (pos > getSize()) return nullptr;

            treap<item_key, item_value> id4 = *this;
            

            while (id4.root->left.size() != pos) {
                

                

                if (id4.root->left.size() < pos) {
                    pos -= id4.root->left.size()+1;
                    id4 = id4.root->right;
                }
                

                else id4 = id4.root->left;
                
                if (id4.root == nullptr) puts("Treap size values are corrupted"), exit(1);
            }
            

            return &(id4.root->value);
        }

        item_key getHighestNeed() {
            num_items index = getNeed()-1;
            treap<item_key, item_value> id4 = *this;
            
            while (true) {
                num_items needLeft = id4.root->left.getNeed();
                num_items id1 = id4.root->right.getExcess();
                if (id4.root->value > 0) id1++;
                else if (id1 <= needLeft) needLeft++;
                if (id1 < needLeft) needLeft -= id1;
                else needLeft = 0;
                
                if ((id4.root->value == 0) && (id1 == 0) && (needLeft == index+1)) return id4.root->key;
                if (index >= needLeft) index -= needLeft, id4 = id4.root->right;
                else id4 = id4.root->left;
            }
        }
    };
        
    template <class item_key, class item_value> struct node_manager {
        static const num_items MAX_SPACE = 900010;
        static node<item_key, item_value> space[MAX_SPACE];
        static num_items numSpaceUsed;
        static treap<item_key, item_value> newTreapNode(item_key key, item_value value) {
            if (numSpaceUsed >= MAX_SPACE) puts("Ran out of treap node space"), exit(1);
    
            space[numSpaceUsed].priority = rand();
            space[numSpaceUsed].key = key;
            space[numSpaceUsed].value = value;
            space[numSpaceUsed].left = treap<item_key, item_value>();
            space[numSpaceUsed].right = treap<item_key, item_value>();
    
            treap<item_key, item_value> newNode(space+numSpaceUsed);
            newNode.updateProperties();
    
            numSpaceUsed++;
            return newNode;
        }
    };
}
template <class item_key, class item_value> treap::node<item_key, item_value> treap::node_manager<item_key, item_value>::space[MAX_SPACE];
template <class item_key, class item_value> num_items treap::node_manager<item_key, item_value>::numSpaceUsed;

struct item_key {
    int32_t cost;
    int32_t index;

    bool operator<(item_key other) {
        if (cost != other.cost) return cost < other.cost;
        return index < other.index;
    }
    bool operator<=(item_key other) {
        if (cost != other.cost) return cost <= other.cost;
        return index <= other.index;
    }
};
typedef int32_t item_value;
typedef int32_t num_items;
 
typedef int32_t num_dishes;
typedef int32_t num_pupils;
typedef int32_t cost;
typedef int32_t num_queries;
 
num_dishes id3;
num_pupils id6;
num_queries numQueries;
cost dishes[300010], pupils[300010];
treap::treap<item_key, item_value> id2;
 
num_dishes i;
num_pupils j, queryIndex;
item_key storeKey;
cost queryCost;
num_queries queryType;
 
int main() {
    scanf("%" PRId32 " %" PRId32, &id3, &id6);
    REPEAT(i, id3) {
        scanf("%" PRId32, dishes+i);
        
        storeKey.cost = dishes[i];
        storeKey.index = i;
        

        id2.addElementByKey(storeKey, 0, false);
    }
    REPEAT(i, id6) {
        scanf("%" PRId32, pupils+i);
        
        storeKey.cost = pupils[i];
        storeKey.index = i+id3;
        

        id2.addElementByKey(storeKey, 1, false);
    }
    
    scanf("%" PRId32, &numQueries);
    while (numQueries--) {
        scanf("%" PRId32 " %" PRId32 " %" PRId32, &queryType, &queryIndex, &queryCost);
        queryIndex--;
        storeKey.cost = (queryType == 1) ? dishes[queryIndex] : pupils[queryIndex];
        storeKey.index = (queryType == 1) ? queryIndex : (queryIndex+id3);
        bool success = id2.removeElementByKey(storeKey);
        if (!success) puts("NOES"), exit(1);
        
        storeKey.cost = queryCost;
        if (queryType == 1) dishes[queryIndex] = queryCost;
        else pupils[queryIndex] = queryCost;
        id2.addElementByKey(storeKey, (queryType == 2), false);
        

        
        if (id2.getNeed() > 0) printf("%" PRId32 "\n", id2.getHighestNeed().cost);
        else puts("-1");
    }
    
    exit(0);
}