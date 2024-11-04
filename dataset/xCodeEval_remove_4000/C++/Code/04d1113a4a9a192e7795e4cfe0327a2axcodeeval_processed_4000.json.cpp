

























using namespace std;

const double PI = std::atan(1.0) * 4;
const long long id0 = 0x7fffffffffffffff; 

void updatePoint(int& x, int& y, char C, int val) {
	switch (C) {
		case 'U': y += val;
			break;
		case 'D': y -= val;
			break;
		case 'R': x += val;
			break;
		case 'L': x -= val;
			break;
	}
}

bool possible(int x, int y, const string& commands, int ans) {
	int xx = 0, yy = 0; 
	for (int i = ans; i < commands.size(); i++) {
		updatePoint(xx, yy, commands[i], 1); 
	}

	if ((abs(x - xx) + abs(y - yy)) <= ans) 
		return true;

	for (int i = 1; i <= (commands.size() - ans); i++) {
		updatePoint(xx, yy, commands[i - 1], 1); 
		updatePoint(xx, yy, commands[i + ans - 1], -1); 

		if (abs(x - xx) + abs(y - yy) <= ans) {
			return true; 
		}
	}
	return false; 
}

int main(int argc, char *argv[]) {
		int n; cin >> n;
		string commands; cin >> commands;
		long long x, y; cin >> x >> y;

		if (abs(x) + abs(y) > n || (abs(x) + abs(y)) % 2 != n % 2) {
			cout << -1 << endl;
		}
		else {
			int ans = n;
			int maxAns = n, minAns = 0, midAns = (maxAns + minAns) / 2;
			while (maxAns >= minAns) {
				midAns = (maxAns + minAns) / 2;
				if (possible(x, y, commands, midAns)) {
					ans = min(ans, midAns);
					maxAns = midAns - 1;
				}
				else {
					minAns = midAns + 1;
				}
			}

			cout << ans << endl;
		}
	return 0;
}







namespace bst {
	template<class T>
	struct BSTNode {
		BSTNode *pLeftChild, *pRightChild, *pParent;
		T value; 
		BSTNode(T t) : 
			value(t), 
			pLeftChild(NULL), 
			pRightChild(NULL), 
			pParent(NULL) 
		{}
	};
	
	template<class T>
	class BST {
	private:
		BSTNode<T> * pRoot;
	public:
		BST() : pRoot(NULL) {}

		BSTNode<T>* getRoot() {
			return pRoot; 
		}

		void inorderTreeWalk(BSTNode<T>* pNode) {
			if (pNode != NULL) {
				inorderTreeWalk(pNode->pLeftChild);
				cout << pNode->value << " "; 
				inorderTreeWalk(pNode->pRightChild);
			}
		}

		BSTNode<T>* iterativeTreeSearch(BSTNode<T> *pNode, T k) {
			while (pNode != NULL && pNode->value != k) {
				if (k < pNode->value) {
					pNode = pNode->pLeftChild;
				}
				else {
					pNode = pNode->pRightChild;
				}
			}
			return pNode; 
		}

		BSTNode<T>* treeMinimum(BSTNode<T> *pNode) {
			while (pNode->pLeftChild != NULL) {
				pNode = pNode->pLeftChild;
			}
			return pNode; 
		}

		BSTNode<T>* treeMaximum(BSTNode<T> *pNode) {
			while (pNode->pRightChild != NULL) {
				pNode = pNode->pRightChild;
			}
			return pNode; 
		}

		BSTNode<T>* treeSuccessor(BSTNode<T> *pNode) {
			if (pNode->pRightChild != NULL) {
				return treeMinimum(pNode->pRightChild); 
			}
			BSTNode<T> *py = pNode->pParent;
			while (py != NULL && py->pRightChild == pNode) {
				pNode = py; 
				py = pNode->pParent; 
			}
			return py; 
		}

		BSTNode<T>* treePredecessor(BSTNode<T> *pNode) {
			if (pNode->pLeftChild != NULL) {
				return treeMaximum(pNode->pLeftChild); 
			}
			BSTNode<T> *py = pNode->pParent;
			while (py != NULL && py->pLeftChild == pNode) {
				pNode = py; 
				py = pNode->pParent; 
			}
			return py; 
		}

		void treeInsert(BSTNode<T> *id3) {
			if (pRoot == NULL) {
				pRoot = id3; 
				return; 
			}

			BSTNode<T> *pParent = NULL;
			BSTNode<T> *pNode = pRoot;
			while (pNode != NULL) {
				pParent = pNode; 
				if (id3->value < pNode->value) {
					pNode = pNode->pLeftChild;
				}
				else {
					pNode = pNode->pRightChild; 
				}
			}
			id3->pParent = pParent; 

			if (id3->value < pParent->value) {
				pParent->pLeftChild = id3; 
			}
			else {
				pParent->pRightChild = id3; 
			}
		}

		void treeDelete(BSTNode<T> *id2) {
			if (id2 == NULL)
				return; 

			

			if (id2->pLeftChild == NULL && id2->pRightChild == NULL) {
				BSTNode<T> *pParent = id2->pParent; 
				if (pParent != NULL) {
					if (pParent->pLeftChild == id2) {
						pParent->pLeftChild = NULL; 
					}
					else {
						pParent->pRightChild = NULL; 
					}
				}
				else {
					pRoot = NULL; 
				}
				delete(id2);
			}
			

			else if (id2->pLeftChild == NULL || id2->pRightChild == NULL) {
				BSTNode<T> *id5 = id2->pLeftChild; 
				if (id5 == NULL) {
					id5 = id2->pRightChild; 
				}
				BSTNode<T> *pParent = id2->pParent; 
				if (pParent != NULL) {
					if (pParent->pLeftChild == id2) {
						pParent->pLeftChild = id5; 
					}
					else {
						pParent->pRightChild = id5; 
					}
					id5->pParent = pParent; 
				}
				else {
					pRoot = id5;
					id5->pParent = NULL; 
				}
				delete(id2); 
			}
			

			else {
				BSTNode<T> *pSuccessor = treeSuccessor(id2); 
				if (pSuccessor != NULL) {
					T id1 = pSuccessor->value;
					treeDelete(pSuccessor); 
					id2->value = id1; 
				}
			}
			
		}
	};
}

namespace trie {
	

	const int CHAR_SIZE = 128; 
	struct TrieNode {
		bool isLeaf; 
		TrieNode* character[CHAR_SIZE]; 
		TrieNode() : isLeaf(false) {
			for (TrieNode *p : character) {
				p = NULL; 
			}
		}
	};

	class Trie {
	private:
		TrieNode * pRoot; 
	public:
		Trie() : pRoot(new TrieNode()) {}
		void insert(string key) {
			TrieNode *pCurr = pRoot; 
			for (char c : key) {
				if (pCurr->character[c] == NULL) {
					pCurr->character[c] = new TrieNode(); 
				}
				pCurr = pCurr->character[c];
			}
			pCurr->isLeaf = true; 
		}

		

		

		int search(string key) {

		}
	};
}

namespace kmp {
	void id6(string p); 
	vector<int> pi; 

	
	

	vector<int> id4(string t, string p) {
		pi.resize(p.size(), 0); 
		id6(p); 

		int n = t.size(); 
		int m = p.size(); 
		int q = 0;  

		vector<int> matchPoints; 
		for (int i = 0; i < n; i++) {
			while (q > 0 && p[q] != t[i]) {
				q = pi[q]; 
			}

			if (p[q] == t[i]) {
				q++; 
			}

			if (q == m) {
				matchPoints.push_back(i - m + 1); 
				q = pi[q - 1]; 
			}
		}
		return matchPoints; 
	}

	void id6(string p) {
		int m = p.size(); 
		int k = 0; 


		pi[0] = 0;
		for (int q = 1; q < m; q++) {
			while (k > 0 && p[k] != p[q]) {
				k = pi[k]; 
			}
			if (p[k] == p[q]) {
				k++;
			}
			pi[q] = k; 
		}
	}
}


























