







#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <limits>

using namespace std;

const double PI = std::atan(1.0) * 4;
const long long FINITELL = 0x7fffffffffffffff;
const int FINITEINT = 0x7fffffff;


const int mod = 998244353; 
int numSize;  
map<int, pair<int, int>>  numRange;

struct Number {
	int value, minIndex, maxIndex; 
	Number(int v, int mini, int maxi) : value(v), minIndex(mini), maxIndex(maxi) {}
};

bool operator<(const Number& n1, const Number& n2) {
	if (n1.minIndex < n2.minIndex)
		return true;
	else
		return false;
}

int main(int argc, char *argv[]) {
	cin >> numSize;
	
	for (int i = 0; i < numSize; i++) {
		int num; cin >> num;
		if (numRange.find(num) != numRange.end()) {
			numRange[num].second = max(numRange[num].second, i);
		}
		else {
			numRange[num] = make_pair(i, i);
		}
	}

	vector<Number> numbers; 
	for (map<int, pair<int, int>>::iterator iter = numRange.begin(); iter != numRange.end(); iter++) {
		numbers.push_back(Number(iter->first, iter->second.first, iter->second.second));
	}

	sort(numbers.begin(), numbers.end());

	int diffBlock = 0; 
	int lowerBound = numbers[0].minIndex, upperBound = numbers[0].maxIndex; 
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i].minIndex < upperBound) {
			upperBound = max(numbers[i].maxIndex, upperBound);
		}
		else {
			diffBlock++;
			lowerBound = numbers[i].minIndex; 
			upperBound = numbers[i].maxIndex;
		}
	}

	long long ans = 1; 
	for (int i = 0; i < diffBlock; i++) {
		ans = ans * 2 % mod; 
	}

	cout << ans << endl; 

	return 0;
}


namespace Graph {
	class DirectedGraph {
	public:
		DirectedGraph(int aNodeNum) : nodeNum(aNodeNum), inDegree(aNodeNum) {
		}

		

		void addConnection(char a, char b) {
			connections[a].push_back(b);
			inDegree[b - 'A']++;
		}

		vector<char> LogisticOrder() {
			vector<char> logisticOrder;
			vector<int> inDegreeBackup = inDegree;

			while (logisticOrder.size() < nodeNum) {
				char nextNode = 'Z';
				for (int i = 0; i < nodeNum; i++) {
					if (inDegree[i] == 0) {
						inDegree[i] = -1;
						nextNode = 'A' + i;
						for (int j = 0; j < connections[nextNode].size(); j++) {
							inDegree[connections[nextNode][j] - 'A']--;
						}
						break;
					}
				}
				logisticOrder.push_back(nextNode);
			}
			return logisticOrder;
		}

	private:
		map<char, vector<char>> connections;
		vector<int> inDegree;
		int nodeNum;

	};
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

		void treeInsert(BSTNode<T> *pNewNode) {
			if (pRoot == NULL) {
				pRoot = pNewNode; 
				return; 
			}

			BSTNode<T> *pParent = NULL;
			BSTNode<T> *pNode = pRoot;
			while (pNode != NULL) {
				pParent = pNode; 
				if (pNewNode->value < pNode->value) {
					pNode = pNode->pLeftChild;
				}
				else {
					pNode = pNode->pRightChild; 
				}
			}
			pNewNode->pParent = pParent; 

			if (pNewNode->value < pParent->value) {
				pParent->pLeftChild = pNewNode; 
			}
			else {
				pParent->pRightChild = pNewNode; 
			}
		}

		void treeDelete(BSTNode<T> *pDeleteNode) {
			if (pDeleteNode == NULL)
				return; 

			

			if (pDeleteNode->pLeftChild == NULL && pDeleteNode->pRightChild == NULL) {
				BSTNode<T> *pParent = pDeleteNode->pParent; 
				if (pParent != NULL) {
					if (pParent->pLeftChild == pDeleteNode) {
						pParent->pLeftChild = NULL; 
					}
					else {
						pParent->pRightChild = NULL; 
					}
				}
				else {
					pRoot = NULL; 
				}
				delete(pDeleteNode);
			}
			

			else if (pDeleteNode->pLeftChild == NULL || pDeleteNode->pRightChild == NULL) {
				BSTNode<T> *pChildPoint = pDeleteNode->pLeftChild; 
				if (pChildPoint == NULL) {
					pChildPoint = pDeleteNode->pRightChild; 
				}
				BSTNode<T> *pParent = pDeleteNode->pParent; 
				if (pParent != NULL) {
					if (pParent->pLeftChild == pDeleteNode) {
						pParent->pLeftChild = pChildPoint; 
					}
					else {
						pParent->pRightChild = pChildPoint; 
					}
					pChildPoint->pParent = pParent; 
				}
				else {
					pRoot = pChildPoint;
					pChildPoint->pParent = NULL; 
				}
				delete(pDeleteNode); 
			}
			

			else {
				BSTNode<T> *pSuccessor = treeSuccessor(pDeleteNode); 
				if (pSuccessor != NULL) {
					T successorValue = pSuccessor->value;
					treeDelete(pSuccessor); 
					pDeleteNode->value = successorValue; 
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
	void computePrefixFunction(string p); 
	vector<int> pi; 

	
	

	vector<int> kmpMatcher(string t, string p) {
		pi.resize(p.size(), 0); 
		computePrefixFunction(p); 

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

	void computePrefixFunction(string p) {
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


























