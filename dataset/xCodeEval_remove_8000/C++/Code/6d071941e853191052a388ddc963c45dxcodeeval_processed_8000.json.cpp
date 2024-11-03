

using namespace std;


class PQNode {
    

    friend class PQTree;
    friend class id12;

public:
    

    enum PQNode_types  {leaf, pnode, qnode};
    enum PQNode_marks  {unmarked, queued, blocked, unblocked};
    enum PQNode_labels {empty, full, partial};

    

    PQNode_types Type();

    

    int LeafValue();

    

    

    void Children(vector<PQNode*> *children);

private:
    

    

    

    list<PQNode*> circular_link_;

    

    int ChildCount();

    

    PQNode* CircularChildWithLabel(PQNode_labels label);

    

    void MoveFullChildren(PQNode* new_node);

    

    void ReplaceCircularLink(PQNode* old_child, PQNode* new_child);

    

    

    PQNode *endmost_children_[2];
    PQNode *pseudo_neighbors_[2];

    

    bool id1, id9;

    

    PQNode* EndmostChildWithLabel(PQNode_labels label);

    

    PQNode* ImmediateSiblingWithLabel(PQNode_labels label);

    

    PQNode* ImmediateSiblingWithoutLabel(PQNode_labels label);

    

    void AddImmediateSibling(PQNode* sibling);

    

    void RemoveImmediateSibling(PQNode* sibling);

    

    void ClearImmediateSiblings();

    

    int ImmediateSiblingCount() const;

    

    void ReplaceEndmostChild(PQNode* old_child, PQNode* new_child);

    

    void ReplaceImmediateSibling(PQNode* old_child, PQNode* new_child);

    

    void ReplacePartialChild(PQNode* old_child, PQNode* new_child);

    

    

    void ForgetChildren();

    

    

    bool ConsecutiveFullPartialChildren();

    

    

    set<PQNode*> full_children_;

    

    set<PQNode*> partial_children_;

    

    

    

    PQNode *immediate_siblings_[2];

    

    enum PQNode_labels label_;

    

    

    

    

    

    enum PQNode_marks mark_;

    

    enum PQNode_types type_;

    

    

    PQNode* parent_;

    

    int id2;

    

    int id14;

    

    int id3;

    

    PQNode* CopyAsChild(const PQNode& to_copy);

    

    void Copy(const PQNode& copy);

    

    PQNode& operator=(const PQNode& to_copy);

    

    

    

    PQNode* QNextChild(PQNode *last) const;

    void ReplaceChild(PQNode* old_child, PQNode* new_child);

    

    void SwapQ(PQNode *toInsert);

    

    

    PQNode* Parent() const;

    

    PQNode(const PQNode& to_copy);

    

    PQNode(int value);

    

    PQNode();

    

    ~PQNode();

    

    void LabelAsFull();

    

    void FindLeaves(map<int, PQNode*> &leafAddress);

    

    void FindFrontier(list<int> &ordering);

    

    void Reset();

    

    

    

    void Print(string *out) const;

    void Identify() const;
};



























class id12 {
public:
    

    

    id12(PQNode* parent, PQNode* begin_side=NULL);

    

    PQNode* Current();

    

    

    void Next();

    

    

    void Reset(PQNode* begin_side=NULL);

    

    

    

    bool IsDone();

private:
    

    void NextPseudoNodeSibling();
    PQNode* parent_;
    PQNode* current_;
    PQNode* next_;
    PQNode* prev_;
};

PQNode::PQNode_types PQNode::Type() {
    return type_;
}

int PQNode::LeafValue() {
    assert(type_ == leaf);
    return id3;
}

void PQNode::Children(vector<PQNode*> *children) {
    assert(children->empty());
    if (type_ == pnode) {
        for (list<PQNode*>::const_iterator i = circular_link_.begin();
             i != circular_link_.end(); ++i)
            children->push_back(*i);
    } else if (type_ == qnode) {
        for(id12 qit(this); !qit.IsDone(); qit.Next())
            children->push_back(qit.Current());
    }
}

int PQNode::ChildCount() {
    return circular_link_.size();
}

PQNode* PQNode::CopyAsChild(const PQNode& to_copy) {
    PQNode* temp = new PQNode(to_copy);
    temp->parent_ = this;
    return temp;
}

PQNode::PQNode(const PQNode& to_copy) {
    Copy(to_copy);
}

void PQNode::Copy(const PQNode& to_copy) {
    

    id3            = to_copy.id3;
    id14  = to_copy.id14;
    id2 = to_copy.id2;
    type_                  = to_copy.type_;
    mark_                  = to_copy.mark_;
    label_                 = to_copy.label_;
    id1            = to_copy.id1;
    id9           = to_copy.id9;

    

    parent_ = NULL;
    partial_children_.clear();
    full_children_.clear();
    circular_link_.clear();
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();

    

    

    for (list<PQNode*>::const_iterator i = to_copy.circular_link_.begin();
         i != to_copy.circular_link_.end(); i++)
        circular_link_.push_back(CopyAsChild(**i));

    

    if (type_ == qnode) {
        PQNode *current, *last;
        

        PQNode *curCopy, *lastCopy, *nextCopy;
        endmost_children_[0] = CopyAsChild(*to_copy.endmost_children_[0]);
        curCopy = to_copy.endmost_children_[0];
        lastCopy = NULL;
        last = endmost_children_[0];

        

        nextCopy = curCopy->QNextChild(lastCopy);
        while (nextCopy != NULL) {
            lastCopy = curCopy;
            curCopy  = nextCopy;
            current  = CopyAsChild(*curCopy);
            current->AddImmediateSibling(last);
            last->AddImmediateSibling(current);
            last = current;
            nextCopy = curCopy->QNextChild(lastCopy);
        }

        

        endmost_children_[1] = current;
    }
}

PQNode& PQNode::operator=(const PQNode& to_copy) {
    

    if (&to_copy == this)
        return *this;
    Copy(to_copy);
    

    return *this;
}

void PQNode::LabelAsFull() {
    label_ = full;
    if (parent_)
        parent_->full_children_.insert(this);
}





PQNode* PQNode::QNextChild(PQNode *last) const {
    if (immediate_siblings_[0] == last) {
        return immediate_siblings_[1];
    } else {
        if (!last && 2 == ImmediateSiblingCount()) 

            return immediate_siblings_[1];
        return immediate_siblings_[0];
    }
}

void PQNode::ReplaceChild(PQNode* old_child, PQNode* new_child) {
    if (type_ == pnode) {
        ReplaceCircularLink(old_child, new_child);
    } else {  

        for (int i = 0; i < 2 && old_child->immediate_siblings_[i]; ++i) {
            PQNode *sibling = old_child->immediate_siblings_[i];
            sibling->ReplaceImmediateSibling(old_child, new_child);
        }
        ReplaceEndmostChild(old_child, new_child);
    }
    new_child->parent_ = old_child->parent_;
    if (new_child->label_ == partial)
        new_child->parent_->partial_children_.insert(new_child);
    if (new_child->label_ == full)
        new_child->parent_->full_children_.insert(new_child);
}



void PQNode::SwapQ(PQNode *toInsert) {
    toInsert->id9 = id9;
    toInsert->ClearImmediateSiblings();
    for (int i = 0; i < 2; ++i) {
        if (parent_->endmost_children_[i] == this)
            parent_->endmost_children_[i] = toInsert;
        if (immediate_siblings_[i])
            immediate_siblings_[i]->ReplaceImmediateSibling(this, toInsert);
    }
    ClearImmediateSiblings();
    parent_ = NULL;
}

PQNode* PQNode::Parent() const {
    

    

    if (immediate_siblings_[0] == NULL || immediate_siblings_[1] == NULL)
        return parent_;
    return NULL;
}

PQNode::PQNode(int value) {
    id3             = value;
    type_                  = leaf;
    parent_                = NULL;
    label_                 = empty;
    mark_                  = unmarked;
    id2  = 0;
    id14   = 0;
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();
}

PQNode::PQNode() {
    id1 = false;
    parent_ = NULL;
    label_ = empty;
    mark_ = unmarked;
    id2 = 0;
    id14 = 0;
    endmost_children_[0] = NULL;
    endmost_children_[1] = NULL;
    ClearImmediateSiblings();
    ForgetChildren();
}

PQNode::~PQNode() {
    if (type_ == qnode) {
        PQNode *last     = NULL;
        PQNode *current  = endmost_children_[0];
        while(current) {
            PQNode *next = current->QNextChild(last);
            delete last;
            last    = current;
            current = next;
        }
        delete last;
    } else if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end(); i++)
            delete *i;
        circular_link_.clear();
    }
}

PQNode* PQNode::CircularChildWithLabel(PQNode_labels label) {
    for (list<PQNode*>::iterator i = circular_link_.begin();
         i != circular_link_.end(); i++) {
        if ((*i)->label_ == label)
            return *i;
    }
    return NULL;
}


PQNode* PQNode::EndmostChildWithLabel(PQNode_labels label) {
    for (int i = 0; i < 2; ++i)
        if (endmost_children_[i] && endmost_children_[i]->label_ == label)
            return endmost_children_[i];
    return NULL;
}

PQNode* PQNode::ImmediateSiblingWithLabel(PQNode_labels label) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i]->label_ == label)
            return immediate_siblings_[i];
    return NULL;
}

PQNode* PQNode::ImmediateSiblingWithoutLabel(PQNode_labels label) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i]->label_ != label)
            return immediate_siblings_[i];
    return NULL;
}

void PQNode::AddImmediateSibling(PQNode *sibling) {
    int null_idx = ImmediateSiblingCount();
    assert(null_idx < 2);
    immediate_siblings_[null_idx] = sibling;
}

void PQNode::RemoveImmediateSibling(PQNode *sibling) {
    if (immediate_siblings_[0] == sibling) {
        immediate_siblings_[0] = immediate_siblings_[1];
        immediate_siblings_[1] = NULL;
    } else if (immediate_siblings_[1] == sibling) {
        immediate_siblings_[1] = NULL;
    } else {
        assert(false);
    }
}

void PQNode::ClearImmediateSiblings() {
    for (int i = 0; i < 2; ++i)
        immediate_siblings_[i] = NULL;
}

int PQNode::ImmediateSiblingCount() const {
    int count = 0;
    for (int i = 0; (i < 2) && immediate_siblings_[i]; ++i)
        ++count;
    return count;
}

void PQNode::ReplaceEndmostChild(PQNode* old_child, PQNode* new_child) {
    for (int i = 0; i < 2; ++i) {
        if (endmost_children_[i] == old_child) {
            endmost_children_[i] = new_child;
            return;
        }
    }
}

void PQNode::ReplaceImmediateSibling(PQNode* old_child, PQNode* new_child) {
    for (int i = 0; i < 2 && immediate_siblings_[i]; ++i)
        if (immediate_siblings_[i] == old_child)
            immediate_siblings_[i] = new_child;
    new_child->immediate_siblings_[new_child->ImmediateSiblingCount()] = this;
}

void PQNode::ReplacePartialChild(PQNode* old_child, PQNode* new_child) {
    new_child->parent_ = this;
    partial_children_.insert(new_child);
    partial_children_.erase(old_child);
    if (type_ == pnode) {
        circular_link_.remove(old_child);
        circular_link_.push_back(new_child);
    } else {
        old_child->SwapQ(new_child);
    }
}

void PQNode::ForgetChildren() {
    for (int i = 0; i < 2; ++i)
        endmost_children_[i] = NULL;
}

bool PQNode::ConsecutiveFullPartialChildren() {
    

    if (full_children_.size() + partial_children_.size() <= 1)
        return true;
    

    

    map<PQNode_labels, int> counts;
    for(set<PQNode*>::iterator it = full_children_.begin();
        it != full_children_.end(); ++it) {
        for (int i = 0; i < 2 && (*it)->immediate_siblings_[i]; ++i)
            counts[(*it)->immediate_siblings_[i]->label_]++;
    }
    for(set<PQNode*>::iterator it = partial_children_.begin();
        it != partial_children_.end(); ++it) {
        for (int i = 0; i < 2 && (*it)->immediate_siblings_[i]; ++i)
            counts[(*it)->immediate_siblings_[i]->label_]++;
    }
    if (counts[partial] != partial_children_.size())
        return false;
    

    

    if (counts[full] != (full_children_.size() * 2) - (2 - counts[partial]))
        return false;
    return true;
}

void PQNode::MoveFullChildren(PQNode* new_node) {
    for (set<PQNode*>::iterator i = full_children_.begin();
         i != full_children_.end(); ++i) {
        circular_link_.remove(*i);
        new_node->circular_link_.push_back(*i);
        (*i)->parent_ = new_node;
    }
}

void PQNode::ReplaceCircularLink(PQNode* old_child, PQNode* new_child) {
    circular_link_.remove(old_child);
    circular_link_.push_back(new_child);
}









void PQNode::FindLeaves(map<int, PQNode*> &leafAddress) {
    if (type_ == leaf) {
        leafAddress[id3] = this;
    } else if (type_ == pnode) {
        

        for (list<PQNode*>::iterator i = circular_link_.begin();
             i!=circular_link_.end(); i++)
            (*i)->FindLeaves(leafAddress);
    } else if (type_ == qnode) {
        

        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->FindLeaves(leafAddress);
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }
}

void PQNode::FindFrontier(list<int> &ordering) {
    if (type_ == leaf) {
        ordering.push_back(id3);
    } else if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end();i++)
            (*i)->FindFrontier(ordering);
    } else if (type_ == qnode) {
        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->FindFrontier(ordering);
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }
}



void PQNode::Reset() {
    if (type_ == pnode) {
        for (list<PQNode*>::iterator i = circular_link_.begin();
             i != circular_link_.end(); i++)
            (*i)->Reset();
    } else if (type_ == qnode) {
        PQNode *last    = NULL;
        PQNode *current = endmost_children_[0];
        while (current) {
            current->Reset();
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }
    }

    full_children_.clear();
    partial_children_.clear();
    label_                 = empty;
    mark_                  = unmarked;
    id2 = 0;
    id14  = 0;
    id9           = false;
    id1            = false;
}






int answer = 1;
const int mod = 998244353;
using ll = long long;
void PQNode::Print(string *out) const {
    if (type_ == leaf) {
        char value_str[10];
        sprintf(value_str, "%d", id3);
        *out += value_str;
    } else if (type_ == pnode) {
        *out += "(";
        int cnt = 0;
        for (list<PQNode*>::const_iterator i = circular_link_.begin();
             i != circular_link_.end(); i++) {
            (*i)->Print(out);
            cnt++;
            answer = (answer * (ll)cnt) % mod;
            

            if (++i != circular_link_.end())
                *out += " ";
            --i;
        }
        *out += ")";
    } else if (type_ == qnode) {
        *out += "[";
        PQNode *last     = NULL;
        PQNode *current  = endmost_children_[0];
        while (current) {
            current->Print(out);
            PQNode *next = current->QNextChild(last);
            last     = current;
            current  = next;
            if (current)
                *out += " ";
        }
        answer = (answer * (ll)2) % mod;
        *out += "]";
    }
}

void PQNode::Identify() const {
    cout << "Node: " << this;
    cout << " Parent: " << parent_ << endl;
    if (type_ == leaf) {
        cout << "Type: leaf  Value: " << id3 << endl;
    } else {
        string value;
        Print(&value);
        if (type_ == pnode)
            cout << "Type: pnode Value: " << value << endl;
        if (type_ == qnode)
            cout << "Type: qnode Value: " << value << endl;
    }
}





id12::id12(
        PQNode* parent, PQNode* begin_side) {
    parent_ = parent;
    Reset(begin_side);
}

void id12::Reset(PQNode* begin_side) {
    current_ = parent_->endmost_children_[0];
    if (begin_side)
        current_ = begin_side;
    prev_ = NULL;
    next_ = current_->immediate_siblings_[0];
}

PQNode* id12::Current() {
    return current_;
}

void id12::NextPseudoNodeSibling() {
    

    

    

    prev_ = current_;
    current_ = current_->ImmediateSiblingWithLabel(PQNode::full);
    if (!current_)
        current_ = current_->ImmediateSiblingWithLabel(PQNode::partial);
}

void id12::Next() {
    

    

    if (IsDone())
        return;
    if (prev_ == NULL && current_->ImmediateSiblingCount() == 2) {
        NextPseudoNodeSibling();
    } else {
        prev_ = current_;
        current_ = next_;
    }

    if (current_) {
        next_ = current_->immediate_siblings_[0];
        if (next_ == prev_)
            next_ = current_->immediate_siblings_[1];
    }
}

bool id12::IsDone() {
    return current_ == NULL;
}

class PQTree {
private:

    

    PQNode *root_;

    

    int id18;

    

    int id0;

    

    

    int id13;

    

    list<set<int> > id20;

    

    

    

    

    map<int, PQNode*> leaf_address_;

    

    

    

    

    PQNode* id1;

    

    bool invalid_;

    

    

    

    

    

    

    int UnblockSiblings(PQNode* sibling);

    

    

    

    

    

    bool TemplateL1(PQNode* candidate_node);
    bool TemplateQ1(PQNode* candidate_node);
    bool TemplateQ2(PQNode* candidate_node);
    bool TemplateQ3(PQNode* candidate_node);
    bool TemplateP1(PQNode* candidate_node, bool id16);
    bool TemplateP2(PQNode* candidate_node);
    bool TemplateP3(PQNode* candidate_node);
    bool TemplateP4(PQNode* candidate_node);
    bool TemplateP5(PQNode* candidate_node);
    bool TemplateP6(PQNode* candidate_node);

    

    

    

    

    

    bool Bubble(set<int> S);

    bool ReduceStep(set<int> S);

public:
    

    

    PQTree(set<int> S);
    PQTree(const PQTree& to_copy);
    ~PQTree();

    

    PQNode* Root();

    

    string Print() const;

    

    void CleanPseudo();

    

    

    bool SafeReduce(set<int>);
    bool SafeReduceAll(list<set<int> >);

    

    

    bool Reduce(set<int> S);
    bool ReduceAll(list<set<int> > L);

    

    list<int> Frontier();

    

    PQTree& operator=(const PQTree& to_copy);

    

    void CopyFrom(const PQTree& to_copy);


    

    

    list<int> ReducedFrontier();

    

    list<set<int> > GetReductions();

    

    set<int> GetContained();
};

PQTree::PQTree(const PQTree& to_copy) {
    CopyFrom(to_copy);
}

PQTree& PQTree::operator=(const PQTree& to_copy) {
    if (&to_copy != this)
        CopyFrom(to_copy);
    return *this;
}

void PQTree::CopyFrom(const PQTree& to_copy) {
    root_                 = new PQNode(*to_copy.root_);
    id18   = to_copy.id18;
    id0 = to_copy.id0;
    invalid_         = to_copy.invalid_;
    id13   = to_copy.id13;
    id1         = NULL;
    id20         = to_copy.id20;

    leaf_address_.clear();
    root_->FindLeaves(leaf_address_);
}

int PQTree::UnblockSiblings(PQNode* candidate_node) {
    assert (candidate_node->mark_ == PQNode::unblocked);
    int id15 = 0;
    for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
        PQNode* sibling = candidate_node->immediate_siblings_[i];
        if (sibling->mark_ == PQNode::blocked) {
            sibling->parent_ = candidate_node->parent_;
            sibling->mark_ = PQNode::unblocked;
            id15++;
            id15 += UnblockSiblings(sibling);
        }
    }
    return id15;
}


























bool PQTree::TemplateL1(PQNode* candidate_node) {
    

    if (candidate_node->type_ != PQNode::leaf)
        return false;

    candidate_node->LabelAsFull();
    return true;
}

bool PQTree::TemplateQ1(PQNode* candidate_node) {
    

    if (candidate_node->type_ != PQNode::qnode)
        return false;
    for (id12 it(candidate_node); !it.IsDone(); it.Next()) {
        if (it.Current()->label_ != PQNode::full)
            return false;
    }

    candidate_node->LabelAsFull();
    return true;
}

bool PQTree::TemplateQ2(PQNode* candidate_node) {
    

    

    

    

    

    

    

    if (candidate_node->type_ != PQNode::qnode ||
        candidate_node->id1 ||
        candidate_node->partial_children_.size() > 1 ||
        !candidate_node->ConsecutiveFullPartialChildren())
        return false;

    bool has_partial = candidate_node->partial_children_.size() > 0;
    bool has_full = candidate_node->full_children_.size() > 0;

    if (has_full && !candidate_node->EndmostChildWithLabel(PQNode::full))
        return false;
    if (!has_full && !candidate_node->EndmostChildWithLabel(PQNode::partial))
        return false;

    

    if (has_partial) {
        PQNode* to_merge = *candidate_node->partial_children_.begin();
        for (int i = 0; i < 2; ++i) {
            PQNode* child = to_merge->endmost_children_[i];
            PQNode* sibling = to_merge->ImmediateSiblingWithLabel(child->label_);
            if (sibling) {
                sibling->ReplaceImmediateSibling(to_merge, child);
            } else {
                candidate_node->ReplaceEndmostChild(to_merge, child);
                child->parent_ = candidate_node;
            }
        }
        to_merge->ForgetChildren();
        delete to_merge;
    }

    candidate_node->label_ = PQNode::partial;
    if (candidate_node->parent_)
        candidate_node->parent_->partial_children_.insert(candidate_node);
    return true;
}

bool PQTree::TemplateQ3(PQNode* candidate_node) {
    

    

    

    

    if (candidate_node->type_ != PQNode::qnode ||
        candidate_node->partial_children_.size() > 2 ||
        !candidate_node->ConsecutiveFullPartialChildren())
        return false;

    

    for (set<PQNode*>::iterator j = candidate_node->partial_children_.begin();
         j != candidate_node->partial_children_.end(); j++) {
        PQNode* to_merge = *j;
        for (int i = 0; i < 2; ++i) {
            PQNode* sibling = to_merge->immediate_siblings_[i];
            if (sibling) {
                PQNode* child = to_merge->EndmostChildWithLabel(sibling->label_);
                if (!child)
                    child = to_merge->EndmostChildWithLabel(PQNode::full);
                sibling->ReplaceImmediateSibling(to_merge, child);
            } else {
                PQNode* empty_child = to_merge->EndmostChildWithLabel(PQNode::empty);
                empty_child->parent_ = candidate_node;
                candidate_node->ReplaceEndmostChild(to_merge, empty_child);
            }
        }

        to_merge->ForgetChildren();
        delete to_merge;
    }
    return true;
}











bool PQTree::TemplateP1(PQNode* candidate_node, bool id16) {
    

    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->full_children_.size() != candidate_node->ChildCount())
        return false;

    candidate_node->label_ = PQNode::full;
    if (!id16)
        candidate_node->parent_->full_children_.insert(candidate_node);
    return true;
}

bool PQTree::TemplateP2(PQNode* candidate_node) {
    

    

    if (candidate_node->type_ != PQNode::pnode ||
        !candidate_node->partial_children_.empty())
        return false;

    

    if (candidate_node->full_children_.size() >= 2) {
        PQNode* new_pnode = new PQNode;
        new_pnode->type_ = PQNode::pnode;
        new_pnode->parent_ = candidate_node;
        candidate_node->MoveFullChildren(new_pnode);
        candidate_node->circular_link_.push_back(new_pnode);
    }
    

    candidate_node->label_ = PQNode::partial;

    return true;
}
bool PQTree::TemplateP3(PQNode* candidate_node) {
    

    

    if (candidate_node->type_ != PQNode::pnode ||
        !candidate_node->partial_children_.empty())
        return false;

    

    

    

    

    

    PQNode* id10 = new PQNode;
    id10->type_ = PQNode::qnode;
    id10->label_ = PQNode::partial;
    candidate_node->parent_->ReplacePartialChild(candidate_node, id10);

    

    

    PQNode* full_child;
    if (candidate_node->full_children_.size() == 1) {
        full_child = *candidate_node->full_children_.begin();
        candidate_node->circular_link_.remove(full_child);
    } else {
        full_child = new PQNode;
        full_child->type_ = PQNode::pnode;
        full_child->label_ = PQNode::full;
        candidate_node->MoveFullChildren(full_child);
    }
    full_child->parent_ = id10;
    full_child->label_ = PQNode::full;
    id10->endmost_children_[0] = full_child;
    id10->full_children_.insert(full_child);

    

    

    PQNode* empty_child;
    if (candidate_node->circular_link_.size() == 1) {
        empty_child = *candidate_node->circular_link_.begin();
        candidate_node->circular_link_.clear();
        delete candidate_node;
    } else {
        empty_child = candidate_node;
    }
    empty_child->parent_ = id10;
    empty_child->label_ = PQNode::empty;
    id10->endmost_children_[1] = empty_child;

    

    empty_child->immediate_siblings_[0] = full_child;
    full_child->immediate_siblings_[0] = empty_child;

    return true;
}

bool PQTree::TemplateP4(PQNode* candidate_node) {
    

    

    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 1)
        return false;

    PQNode* id5 = *candidate_node->partial_children_.begin();
    PQNode* empty_child = id5->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child = id5->EndmostChildWithLabel(PQNode::full);

    if (!empty_child || !full_child)
        return false;

    

    

    if (!candidate_node->full_children_.empty()) {
        PQNode *id11;
        if (candidate_node->full_children_.size() == 1) {
            id11 = *(candidate_node->full_children_.begin());
            candidate_node->circular_link_.remove(id11);
        } else {
            id11 = new PQNode;
            id11->type_ = PQNode::pnode;
            id11->label_ = PQNode::full;
            candidate_node->MoveFullChildren(id11);
        }
        id11->parent_ = id5;
        id5->ReplaceEndmostChild(full_child, id11);
        id5->full_children_.insert(id11);
        full_child->AddImmediateSibling(id11);
        id11->AddImmediateSibling(full_child);
    }

    

    if (candidate_node->circular_link_.size() == 1) {
        if (candidate_node->Parent()) {
            candidate_node->parent_->ReplaceChild(candidate_node, id5);
        } else {
            id5->parent_ = NULL;
            if (root_ == candidate_node) {
                root_ = id5;
            } else {
                for (int i = 0; i < 2; ++i) {
                    PQNode *sibling = candidate_node->immediate_siblings_[i];
                    sibling->ReplaceImmediateSibling(candidate_node, id5);
                }
            }
        }
        candidate_node->circular_link_.clear();
        delete candidate_node;
    }
    return true;
}

bool PQTree::TemplateP5(PQNode* candidate_node) {
    

    

    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 1)
        return false;

    

    PQNode* id5 = *candidate_node->partial_children_.begin();
    assert(id5->type_ == PQNode::qnode);
    PQNode* empty_child = id5->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child = id5->EndmostChildWithLabel(PQNode::full);
    PQNode* id4 = candidate_node->CircularChildWithLabel(PQNode::empty);

    if (!empty_child || !full_child)
        return false;

    

    candidate_node->parent_->ReplaceChild(candidate_node, id5);
    id5->id14 = candidate_node->id14;
    candidate_node->circular_link_.remove(id5);

    

    if (!candidate_node->full_children_.empty()) {
        PQNode *id11;
        if (candidate_node->full_children_.size() == 1) {
            id11 = *candidate_node->full_children_.begin();
            candidate_node->circular_link_.remove(id11);
        } else {
            id11 = new PQNode;
            id11->type_ = PQNode::pnode;
            id11->label_ = PQNode::full;
            candidate_node->MoveFullChildren(id11);
        }

        id11->parent_ = id5;
        full_child->AddImmediateSibling(id11);
        id11->AddImmediateSibling(full_child);
        id5->ReplaceEndmostChild(full_child, id11);
    }

    

    if (candidate_node->ChildCount()) {
        PQNode *id19;
        if (candidate_node->ChildCount() == 1) {
            id19 = id4;
        } else {
            id19 = candidate_node;
            id19->label_ = PQNode::empty;
            id19->ClearImmediateSiblings();
        }

        id19->parent_ = id5;
        empty_child->AddImmediateSibling(id19);
        id19->AddImmediateSibling(empty_child);
        id5->ReplaceEndmostChild(empty_child, id19);
    }
    if (candidate_node->ChildCount() < 2) {
        

        candidate_node->circular_link_.clear();
        delete candidate_node;
    }

    return true;
}

bool PQTree::TemplateP6(PQNode* candidate_node) {
    if (candidate_node->type_ != PQNode::pnode ||
        candidate_node->partial_children_.size() != 2)
        return false;

    

    PQNode* id6 = *candidate_node->partial_children_.begin();
    PQNode* partial_qnode2 = *(++(candidate_node->partial_children_.begin()));

    PQNode* empty_child1 = id6->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child1 = id6->EndmostChildWithLabel(PQNode::full);
    if (!empty_child1 || !full_child1)
        return false;

    PQNode* empty_child2 = partial_qnode2->EndmostChildWithLabel(PQNode::empty);
    PQNode* full_child2 = partial_qnode2->EndmostChildWithLabel(PQNode::full);
    if (!empty_child2 || !full_child2)
        return false;

    

    if (!candidate_node->full_children_.empty()) {
        PQNode *id11 = NULL;
        if (candidate_node->full_children_.size() == 1) {
            id11 = *candidate_node->full_children_.begin();
            candidate_node->circular_link_.remove(id11);
        } else {
            

            id11 = new PQNode;
            id11->type_ = PQNode::pnode;
            id11->label_ = PQNode::full;
            candidate_node->MoveFullChildren(id11);
        }
        id11->parent_ = id6;
        full_child2->parent_ = id6;

        full_child1->AddImmediateSibling(id11);
        full_child2->AddImmediateSibling(id11);
        id11->AddImmediateSibling(full_child1);
        id11->AddImmediateSibling(full_child2);
    } else  {
        full_child1->AddImmediateSibling(full_child2);
        full_child2->AddImmediateSibling(full_child1);
    }
    id6->ReplaceEndmostChild(full_child1, empty_child2);
    empty_child2->parent_ = id6;

    

    candidate_node->circular_link_.remove(partial_qnode2);
    partial_qnode2->ForgetChildren();
    delete partial_qnode2;

    

    if (candidate_node->circular_link_.size() == 1) {
        id6->parent_ = candidate_node->parent_;
        id6->id14 = candidate_node->id14;
        id6->label_ = PQNode::partial;

        if (candidate_node->parent_) {
            candidate_node->parent_->partial_children_.insert(id6);
            if (candidate_node->parent_->type_ == PQNode::pnode) {
                candidate_node->parent_->ReplaceCircularLink(candidate_node,
                                                             id6);
            } else {
                for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
                    PQNode* sibling = candidate_node->immediate_siblings_[i];
                    sibling->ReplaceImmediateSibling(candidate_node, id6);
                }
                candidate_node->parent_->ReplaceEndmostChild(candidate_node,
                                                             id6);
            }
        } else {
            root_ = id6;
            id6->parent_ = NULL;

            

            candidate_node->circular_link_.clear();
            delete candidate_node;
        }
    }
    return true;
}







bool PQTree::Bubble(set<int> id7) {
    queue<PQNode*> q;
    id18 = 0;
    id0 = 0;
    id13 = 0;

    

    set<PQNode*> blocked_list;

    

    for (set<int>::iterator i = id7.begin();
         i != id7.end(); ++i) {
        PQNode *temp = leaf_address_[*i];
        assert (temp);
        q.push(temp);
    }

    while (q.size() + id18 + id13 > 1) {
        if (q.empty())
            return false;

        PQNode* candidate_node = q.front();
        q.pop();
        candidate_node->mark_ = PQNode::blocked;

        

        set<PQNode*> id17;
        set<PQNode*> id8;
        for (int i = 0; i < 2 && candidate_node->immediate_siblings_[i]; ++i) {
            PQNode* sibling = candidate_node->immediate_siblings_[i];
            if (sibling->mark_ == PQNode::blocked) {
                id8.insert(sibling);
            } else if (sibling->mark_ == PQNode::unblocked) {
                id17.insert(sibling);
            }
        }

        

        

        

        

        if (!id17.empty()) {
            candidate_node->parent_ = (*id17.begin())->parent_;
            candidate_node->mark_ = PQNode::unblocked;
        } else if (candidate_node->ImmediateSiblingCount() < 2) {
            candidate_node->mark_ = PQNode::unblocked;
        }

        

        if (candidate_node->mark_ == PQNode::unblocked) {
            if (!id8.empty()) {
                int list_size = UnblockSiblings(candidate_node);
                candidate_node->parent_->id2 += list_size;
                id0 -= list_size;
            }

            if (!candidate_node->parent_) {
                id13 = 1;
            } else {
                candidate_node->parent_->id2++;
                if (candidate_node->parent_->mark_ == PQNode::unmarked) {
                    q.push(candidate_node->parent_);
                    candidate_node->parent_->mark_ = PQNode::queued;
                }
            }
            id18 -= id8.size();
        } else {
            id18 += 1 - id8.size();
            id0 += 1;
            blocked_list.insert(candidate_node);
        }
    }

    if (id18 > 1 || (id13 == 1 && id18 != 0))
        return false;

    

    

    if (id18 == 1 && id0 > 1) {
        id1 = new PQNode;
        id1->type_ = PQNode::qnode;
        id1->id1 = true;
        id1->id2 = 0;

        

        int side = 0;
        for (set<PQNode*>::iterator i = blocked_list.begin();
             i != blocked_list.end(); ++i) {
            PQNode* blocked = *i;
            if (blocked->mark_ == PQNode::blocked) {  

                id1->id2++;
                id1->id14 += blocked->id14;
                for (int j = 0; j < 2; ++j) {
                    PQNode* sibling = blocked->immediate_siblings_[j];
                    if (sibling->mark_ == PQNode::unmarked) {
                        blocked->RemoveImmediateSibling(sibling);
                        sibling->RemoveImmediateSibling(blocked);
                        id1->pseudo_neighbors_[side] = sibling;
                        id1->endmost_children_[side++] = blocked;
                        break;
                    }
                }
                blocked->parent_ = id1;
                blocked->id9 = true;
            }
        }
        q.push(id1);
    }
    return true;
}

bool PQTree::ReduceStep(set<int> id7) {
    

    queue<PQNode*> q;
    for (set<int>::iterator i = id7.begin();
         i != id7.end(); i++) {
        PQNode* candidate_node = leaf_address_[*i];
        if (candidate_node == NULL)
            return false;
        candidate_node->id14 = 1;
        q.push(candidate_node);
    }

    while (!q.empty()) {
        

        PQNode* candidate_node = q.front();
        q.pop();

        

        

        if (candidate_node->id14 < id7.size()) {
            PQNode* candidate_parent = candidate_node->parent_;
            candidate_parent->id14 +=
                    candidate_node->id14;
            candidate_parent->id2--;
            

            

            if (candidate_parent->id2 == 0)
                q.push(candidate_parent);

            

            if      (TemplateL1(candidate_node)) {}
            else if (TemplateP1(candidate_node,  false)) {}
            else if (TemplateP3(candidate_node)) {}
            else if (TemplateP5(candidate_node)) {}
            else if (TemplateQ1(candidate_node)) {}
            else if (TemplateQ2(candidate_node)) {}
            else {
                CleanPseudo();
                return false;
            }
        } else {  

            

            if      (TemplateL1(candidate_node)) {}
            else if (TemplateP1(candidate_node,  true)) {}
            else if (TemplateP2(candidate_node)) {}
            else if (TemplateP4(candidate_node)) {}
            else if (TemplateP6(candidate_node)) {}
            else if (TemplateQ1(candidate_node)) {}
            else if (TemplateQ2(candidate_node)) {}
            else if (TemplateQ3(candidate_node)) {}
            else {
                CleanPseudo();
                return false;
            }
        }
    }
    CleanPseudo();
    return true;
}

void PQTree::CleanPseudo() {
    if (id1) {
        

        

        

        PQNode *last    = NULL;
        PQNode *current = id1->endmost_children_[0];
        while (current) {
            current->parent_ = NULL;
            PQNode *next = current->QNextChild(last);
            last    = current;
            current = next;
        }

        for (int i = 0; i < 2; i++) {
            id1->endmost_children_[i]->AddImmediateSibling(
                    id1->pseudo_neighbors_[i]);
            id1->pseudo_neighbors_[i]->AddImmediateSibling(
                    id1->endmost_children_[i]);
        }

        id1->ForgetChildren();
        delete id1;
        id1 = NULL;
    }
}



PQTree::PQTree(set<int> id7) {
    

    root_ = new PQNode;
    root_->type_ = PQNode::pnode;
    invalid_ = false;
    id1 = NULL;
    id18 = 0;
    id0 = 0;
    id13 = 0;
    for (set<int>::iterator i = id7.begin();
         i != id7.end(); i++) {
        PQNode *new_node;
        new_node = new PQNode(*i);
        leaf_address_[*i] = new_node;
        new_node->parent_ = root_;
        new_node->type_ = PQNode::leaf;
        root_->circular_link_.push_back(new_node);
    }
}

PQNode* PQTree::Root() {
    return root_;
}

string PQTree::Print() const {
    string out;
    root_->Print(&out);
    return out;
}





bool PQTree::SafeReduce(set<int> S) {
    

    PQTree toCopy(*this);

    if (!Reduce(S)) {
        

        root_ = new PQNode(*toCopy.root_);
        id18 = toCopy.id18;
        id0 = toCopy.id0;
        id13 = toCopy.id13;
        invalid_ = toCopy.invalid_;
        leaf_address_.clear();
        root_->FindLeaves(leaf_address_);
        return false;
    }
    return true;
}

bool PQTree::SafeReduceAll(list<set<int> > L) {
    

    PQTree toCopy(*this);
    if (!ReduceAll(L)) {
        

        root_ = new PQNode(*toCopy.root_);
        id18 = toCopy.id18;
        id0 = toCopy.id0;
        id13 = toCopy.id13;
        invalid_ = toCopy.invalid_;
        leaf_address_.clear();
        root_->FindLeaves(leaf_address_);
        return false;
    }
    return true;
}


bool PQTree::Reduce(set<int> id7) {
    if (id7.size() < 2) {
        id20.push_back(id7);
        return true;
    }
    if (invalid_)
        return false;
    if (!Bubble(id7)) {
        invalid_ = true;
        return false;
    }
    if (!ReduceStep(id7)) {
        invalid_ = true;
        return false;
    }

    

    root_->Reset();

    

    id20.push_back(id7);
    return true;
}

bool PQTree::ReduceAll(list<set<int> > L) {
    for (list<set<int> >::iterator S = L.begin(); S != L.end(); S++) {
        if (!Reduce(*S))
            return false;
    }
    return true;
}

list<int> PQTree::Frontier() {
    list<int> out;
    root_->FindFrontier(out);
    return out;
}

list<set<int> > PQTree::GetReductions() {
    return id20;
}



PQTree::~PQTree() {
    delete root_;
}
using namespace std;

int main() {

    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ddd;
    for(size_t i=0; i<m; ++i) {
        vector<int> g;
        int k;
        cin >> k;
        g.resize(k);
        for (int &j : g)
            cin >> j;
        ddd.push_back(g);
    }

    vector<int> o(n);
    iota(o.begin(), o.end(), 1);
    set<int> ST{o.begin(), o.end()};
    PQTree tree(ST);

    

    for (auto g : ddd) {
        if (!tree.Reduce({g.begin(), g.end()})) {
            cout << 0;
            return 0;
        }
        

    }
    answer = 1;
    tree.Print();
    cout << answer;
}




