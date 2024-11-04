import java.util.*; 
import java.io.BufferedReader; 
import java.io.InputStreamReader; 
import java.util.StringTokenizer; 
import java.io.IOException; 
import java.lang.Math.*;


public class cp{

    public static long pow(long x, long y, long p){ 
        

        long res = 1;      
         
        

        

        x = x % p;  
      
        while (y > 0) 
        { 
            

            

            if((y & 1)==1) 
                res = (res * x) % p; 
      
            

            

            y = y >> 1;  
            x = (x * x) % p;  
        } 
        return res; 
    }
  
  	public static void printArray(int[] arr){
  		if(arr == null){
  			System.out.println("null");
  			return;
  		}
  		for(int i = 0; i < arr.length; i++){
  			System.out.print(arr[i] + " ");
  		}System.out.println("");
  	}

  	public static void printArray(ArrayList arr){
  		if(arr == null){
  			System.out.println("null");
  			return;
  		}
  		for(int i = 0; i < arr.size(); i++){
  			System.out.print(arr.get(i) + " ");
  		}System.out.println("");
   	}

   	public static void printArray(boolean[] arr){
   		for(int i = 0; i < arr.length; i ++){
   			System.out.print(arr[i] ? "1 ": "0 ");
   		}System.out.println("");
   	}

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer s = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(s.nextToken());
		int m = Integer.parseInt(s.nextToken());

		int[][] edges = new int[m][2];
		
		for(int i = 0; i < m; i ++){
			s = new StringTokenizer(br.readLine());
			edges[i][0] = Integer.parseInt(s.nextToken()) - 1;
			edges[i][1] = Integer.parseInt(s.nextToken()) - 1;
		}

		Graph graph = new Graph(n, edges, false);

		graph.solve();
		


	}
}


class Node{
	public int data;
	public Node next;

	public Node(int data){
		this.data = data;
		this.next = null;
	}

	public int getData(){
		return data;
	}

	public Node getNextNode(){
		return next;
	}

	public void setData(int data){
		this.data = data;
	}

	public void setNextNode(Node next){
		this.next = next;
	}
}

class Linklist{
	public Node front;

	public Node getFront(){
		return front;
	}

	public void print(){
		Node ptr = front;

		while(ptr!=null){
			System.out.print(ptr.getData()+" ");
			ptr = ptr.getNextNode();
		}
		System.out.println("");
	}

	public int length(){
		int count = 0;
		Node curr = front;
		while(curr!= null){
			count++;
			curr = curr.getNextNode();
		}
		return count;
	}

	public void addNode(int data, int position){
		Node nptr = new Node(data);
		if(front == null){
			front = nptr;
		}
		if(position == 1){
			nptr.setNextNode(front.getNextNode());
			front = nptr;
		}else{
			Node prev = front;
			Node curr = front.getNextNode();
			while(position -- > 2){
				curr = curr.getNextNode();
				prev = prev.getNextNode();
			}
			nptr.setNextNode(curr);
			prev.setNextNode(nptr);
		}
	}

	public void addNode(int data){
		addNode(data,length()+1);
	}

	public void deleteNode(int position){
		if(position == 1){
			front = front.getNextNode();
		}else{
			Node prev = front;
			Node curr = front.getNextNode();

			while(position -- > 2){
				curr = curr.getNextNode();
				prev = prev.getNextNode();
			}

			prev.setNextNode(curr.getNextNode());
		}
	}

	public void recDelete(int position, Node ptr){
		if(position == 1){
			front = front.getNextNode();
		}else if(position == 2){
			ptr.setNextNode(ptr.getNextNode().getNextNode());
		}else{
			ptr = ptr.getNextNode();
			recDelete(position - 1, ptr);
		}
	}

	public void reverse(){
		Node prev = front;
		Node curr = prev.getNextNode();
		Node next = curr;
		while(curr!=null){
			next = next.getNextNode();
			curr.setNextNode(prev);
			prev = curr;
			curr = next;
		}
		front.setNextNode(null);
		front = prev;
	}

	public int makeAlt(Node curr, boolean state, Node mid){
		if(curr == null){
			return mid.getData();
		}
		if(state){
			mid = mid.getNextNode();
		}

		return makeAlt(curr.getNextNode(),!state, mid);
	}
}

class Stack{
	private Node top;
	private int size;

	public Stack(){
		size = 0;
	}

	public void push( int data){
		Node node = new Node(data);
		node.setNextNode(top);
		top = node;

		size++;
	}

	public int pop(){
		int ret = top.getData();
		top = top.getNextNode();
		size--;
		return ret;
	}

	public int peek(){
		return top.getData();
	}

	public int size(){
		return size;
	}

	public boolean isEmpty(){
		return size == 0;
	}


	public void print(){
		Node ptr = top;

		while(ptr!=null){
			System.out.print(ptr.getData()+" ");
			ptr = ptr.getNextNode();
		}
		System.out.println("");
	}
}

class Queue{
	Node front;
	Node rear;
	int size;

	public Queue(){
		size = 0;
	}

	public void enqueue(int data){
		size += 1;
		if(front == null){
			front = new Node(data);
			rear = front;
			return;
		}
		Node nptr = new Node(data);
		nptr.setNextNode(front.getNextNode());
		front.setNextNode(nptr);
		front = nptr; 
	}

	public int dequeue(){
		if(rear == null){
			System.out.println("error: Queue empty");
			return -1;
		}
		size -= 1;
		int curr = rear.getData();
		rear = rear.getNextNode();
		if(rear == null){
			front = null;
		}
		return curr;
	}

	public void print(){
		Node ptr = rear;
		while(ptr!= null){
			System.out.print(ptr.getData()+" ");
			ptr = ptr.getNextNode();
		}
		System.out.println("");
	}

	public boolean isEmpty(){
		return size == 0;
	}
}

class BinarySearchTree{

	int data;
	BinarySearchTree left;
	BinarySearchTree right;

	public BinarySearchTree(){
	}

	public BinarySearchTree(int data){
		this.data = data;
	}

	public void insertInt( int data ){
		BinarySearchTree tree = new BinarySearchTree( data );

		insert( tree );
	}

	public void insert(BinarySearchTree tree){
		if(tree.data < this.data){
			if(this.left == null){
				this.left = tree;
			}else{
				this.left.insert( tree );
			}
		}else{
			if(this.right == null){
				this.right = tree;
			}else{
				this.right.insert( tree );
			}
		}
	}

	public void delete(int data){
		if(contains(data)){
			delete(data, null, true);
		}else{
			System.out.println("Not found!");
		}
	}

	public void delete(int data, BinarySearchTree parent, boolean isLeftChild){
		if(data == this.data){
			if(this.left == null && this.right == null){
				if(parent == null){
					System.out.println("Can't delete only node of tree!");
					return;
				}
				if(isLeftChild){
					parent.left = null;
				}else{
					parent.right = null;
				}
			}else if(this.left != null && this.right != null){
				int minValue = this.right.getMin();
				delete(minValue, null, true);
				this.data = minValue;
			}else if(this.right != null){
				this.left = this.right.left;
				this.data = this.right.data;
				this.right = this.right.right;
			}else{
				this.right = this.left.right;
				this.data = this.left.data;
				this.left = this.left.left;
			}
		}else if(data < this.data){
			this.left.delete(data, this, true);

		}else if(data > this.data){
			this.right.delete(data, this, false);
		}
	}

	public BinarySearchTree getParent(int data){
		if(this.data == data){
			return null;
		}else if(data < this.data){
			if(data == this.left.data){
				return this;
			}else{
				return this.left.getParent(data);
			}
		}else{
			if(data == this.right.data){
				return this;
			}else{
				return this.right.getParent(data);
			}
		}
	}

	public boolean contains( int data ){
		if( data == this.data){
			return true;
		}
		else if( data < this.data){
			if( this.left == null ){
				return false;
			}
			return this.left.contains( data );
		}
		else if( data > this.data){
			if( this.right == null ){
				return false;
			}
			return this.right.contains( data );
		}

		return false;
	}

	public int getMax(){
		if(this.right == null){
			return this.data;
		}
		return this.right.getMax();
	}

	public int getMin(){
		if(this.left == null){
			return this.data;
		}else{
			return this.left.getMin();
		}
	}

	public void display(){
		displayWithIndent(0);
	}

	private void displayWithIndent(int indent){
		for(int i = 0;i < indent; i++){
			System.out.print(" ");
		}System.out.println(this.data);
		
		if(this.left != null){
			for(int i = 0;i < indent; i++){
				System.out.print(" ");
			}System.out.println("left: ");
			this.left.displayWithIndent(indent + 2);			
		}

		if(this.right != null){
			for(int i = 0;i < indent + 2; i++){
				System.out.print(" ");
			}System.out.println("right: ");
			this.right.displayWithIndent(indent + 2);			
		}
	}
	public void printSorted(){
		if(this.left != null){
			left.printSorted();
		}
		System.out.println(this.data);
		if(this.right != null){
			right.printSorted();
		}
	}
}

class AVLTree{

    int data;
    int height;
    AVLTree left;
    AVLTree right;

    private static int ALLOWED_IMBALANCE = 1;

    AVLTree(){
        this.data = -1;
        height = 0;
    }

    AVLTree(int data){
        this.data = data;
        height = 0;
    }

    public void insert(int data){
        if(this.data == -1){
            this.data = data;
            return;
        }
        if(data < this.data){
            if(this.left == null){
                this.left = new AVLTree(data);
            }else{
                this.left.insert(data);
            }
        }else{
            if(this.right == null){
                this.right = new AVLTree(data);
            }else{
                this.right.insert(data);
            }
        }

        balance();
    }

    public void delete(int data){
        if(data == this.data){
            if(this.left == null && this.right == null){
                System.out.println("Can't delete only node of tree");
                return;
            }else if(this.left != null && this.right != null){
                int leftmostOfRightChild = this.right.findMin();
                delete(leftmostOfRightChild);
                this.data = leftmostOfRightChild;
            }else if(this.left != null && this.right == null){
                this.data = this.left.data;
                this.right = this.left.right;
                this.left = this.left.left;
            }else if(this.left == null && this.right != null){
                this.data = this.right.data;
                this.left = this.right.left;
                this.right = this.right.right;
            }
        }else if(data < this.data){
            if(this.left == null){
                System.out.println( data + " not Found" );
                return;
            }else{
                if(data == this.left.data && this.left.left == null && this.left.right == null){
                    this.left = null;
                }else{
                    this.left.delete(data);
                }
            }
        }else{
            if(this.right == null){
                System.out.println( data + " not Found" );
                return;
            }else{
                if(data == this.right.data && this.right.right == null && this.right.left == null){
                    this.right = null;
                }else{
                    this.right.delete(data);
                }
            }            
        }
        balance();
    }

    public int findMin(){
        if(this.left == null){
            return this.data;
        }else{
            return this.left.findMin();
        }
    }

    private void balance(){
        if(this.left != null){
            this.left.balance();
        }
        if(this.right != null){
            this.right.balance();
        }
        int leftHeight = this.left == null ? 0 : this.left.height;
        int rightHeight = this.right == null ? 0 : this.right.height;
        System.out.println(this.data + " leftHeight: " + leftHeight + " rightHeight: " + rightHeight);
        if(leftHeight - rightHeight > ALLOWED_IMBALANCE){
            if(this.left.left != null && this.left.left.height - (rightHeight - 1) > 1){
                singleRotationRight();
            }else if(this.left.right != null && this.left.right.height - (rightHeight - 1) > 1){
                doubleRotationRight();
            }
        }else if(leftHeight - rightHeight < -1*ALLOWED_IMBALANCE){
            if(this.right.right != null && this.right.right.height - (leftHeight - 1) > 1){
                singleRotationLeft();
            }else if(this.right.left != null && this.right.left.height - (leftHeight - 1) > 1){
                doubleRotationLeft();
            }
        }

        if(this.left == null && this.right == null){
            this.height = 1;
        }else if(this.left == null && this.right != null){
            this.height = 1 + this.right.height;
        }else if(this.left != null && this.right == null){
            this.height = 1 + this.left.height;
        }else{
            this.height = 1 + this.left.height > this.right.height ? this.left.height : this.right.height;
        }
    }

    private void singleRotationLeft(){
        int k1 = this.data;
        int k2 = this.right.data;

        AVLTree x = this.right.right;
        AVLTree y = this.right.left;
        AVLTree z = this.left;

        this.data = k2;
        this.left = this.right;
        this.right.right = y;
        this.right.right = z;
        this.right = x;
        this.left.data = k1; 
    }

    private void singleRotationRight(){
        int k1 = this.data;
        int k2 = this.left.data;

        AVLTree x = this.left.left;
        AVLTree y = this.left.right;
        AVLTree z = this.right;

        this.data = k2;
        this.right = this.left;
        this.right.left = y;
        this.right.right = z;
        this.left = x;
        this.right.data = k1;

    }

    private void doubleRotationLeft(){
        this.right.singleRotationRight();
        singleRotationLeft();
    }

    private void doubleRotationRight(){
        this.left.singleRotationLeft();
        singleRotationRight();
    }

    public void display(){
        displayWithIndent(0);
    }

    private void displayWithIndent(int indent){
        for(int i = 0; i < indent; i ++){
            System.out.print(" ");
        }System.out.println(this.data);

        for(int i = 0; i < indent + 2; i ++){
            System.out.print(" ");
        }System.out.println("left: ");
        if(this.left != null){
            this.left.displayWithIndent(indent + 2);
        }
        for(int i = 0; i < indent + 2; i ++){
            System.out.print(" ");
        }System.out.println("right: ");
        if(this.right != null){
            this.right.displayWithIndent(indent + 2);
        }
    }
}

class Heap{
    int[] heap;
    int size;
    boolean parentShouldHaveLowerValue;

    Heap(int size){
        heap = new int[size];
        this.size = 0;
        this.parentShouldHaveLowerValue = true;
    }

    Heap(){}

    public void heapify(int [] arr, boolean parentShouldHaveLowerValue){
        this.heap = arr;
        this.parentShouldHaveLowerValue = parentShouldHaveLowerValue;
        this.size = arr.length;
        for(int i = size - 1; i >= 0; i --){
            percolateDown(i);
        }
    }

    public void insert(int data){
        heap[size++] = data;
        percolateUp(size - 1);
    }

    public int popHighestPriority(){
        int highestPriority = heap[0];

        heap[0] = heap[size - 1];
        size --;
        percolateDown(0);

        return highestPriority;
    }

    public void percolateUp(int curr){
        int parent = curr%2 == 0 ? curr/2 - 1 : curr/2;
        if(parent < 0){
            return;
        }
        if(isHigherPriority(curr, parent)){
            int temp = heap[parent];
            heap[parent] = heap[curr];
            heap[curr] = temp;
            percolateUp(parent);
        } 
    }

    public void percolateDown(int curr){
        int leftChild = 2*curr + 1;
        int rightChild = 2*curr + 2;
        
        int switchWith = -1;
        if(leftChild < size){
            if(!isHigherPriority(curr, leftChild)){
                switchWith = leftChild;
            }
        }
        if(rightChild < size){
            if(!isHigherPriority(curr, rightChild)){
                if(switchWith == -1 || isHigherPriority(rightChild, leftChild)){
                    switchWith = rightChild;
                }
            }
        }

        if(switchWith != -1){
            int temp = heap[switchWith];
            heap[switchWith] = heap[curr];
            heap[curr] = temp;
            percolateDown(switchWith);
        }
    }

    public static int[] heapSort(int arr[], boolean ascending){
        Heap heap = new Heap();
        int n = arr.length;
        heap.heapify(arr, !ascending);
        for(int i = 0; i < n; i++){
            heap.heap[n - i - 1] = heap.popHighestPriority();
        }
        return heap.heap;
    }

    public boolean isHeap(){
        for(int curr = 0; curr < size; curr ++){
            int leftChild = 2*curr + 1;
            int rightChild = 2*curr + 2;

            if(leftChild < size && !isHigherPriority(curr, leftChild)){
                return false;
            }
            if(rightChild < size && !isHigherPriority(curr, rightChild)){
                return false;
            }
        }
        return true;
    }

    public void displaySimple(){
        System.out.println("Heap: ");
        int j = 2;
        for(int i = 0; i < size; i ++){
            System.out.print(heap[i] + " ");

            if(i == j - 2){
                System.out.println("");
                j *= 2;
            }
        }System.out.println("");
        System.out.println("Is this a heap? " + (isHeap() ? "yes" : "no"));
    }

    public boolean isHigherPriority(int parent, int child){
        if(this.parentShouldHaveLowerValue){
            if(heap[parent] > heap[child]){
                return false;
            }else{
                return true;
            }
        }else{
            if(heap[parent] < heap[child]){
                return false;
            }else{
                return true;
            }
        }
    }
}









class Graph{

	public int n;
	public int[][] edges;
	public ArrayList[] adjacencyList;
	public boolean[][] adjacencyMatrix;
	public boolean isDirected;

	Graph(int n, boolean isDirected){
		this.n = n;
		this.isDirected = isDirected;
		adjacencyList = new ArrayList[n];
		for(int i = 0; i < n; i ++){
			adjacencyList[i] = new ArrayList();
		}
	}

	Graph(int n, int[][] edges, boolean isDirected){
		this.n = n;
		this.edges = edges;
		this.isDirected = isDirected;
		if(edges != null){
			createAdjacencyList(edges);
		}
	}

	public void addEdge(int x, int y){
		adjacencyList[x].add(y);
	}

	public void createAdjacencyList(int[][] edges){
		adjacencyList = new ArrayList[n];
		for(int i = 0; i < n; i++){
			adjacencyList[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < edges.length; i++){
			adjacencyList[edges[i][0]].add(edges[i][1]);
			if(!isDirected){
				adjacencyList[edges[i][1]].add(edges[i][0]);
			}
		}
	}

	public void createAdjacencyMatrix(int[][] edges){
		adjacencyMatrix = new boolean[n][n];
		for(int i = 0; i < edges.length; i++){
			adjacencyMatrix[edges[i][0]][edges[i][1]] = true;
			if(!isDirected){
				adjacencyMatrix[edges[i][1]][edges[i][0]] = true;
			}
		}
	}

	public void displayAdjacencyList(){
		for(int i = 0; i < n; i ++){
			System.out.print(i + ": ");

			for(int j = 0; j < adjacencyList[i].size(); j++ ){
				System.out.print(adjacencyList[i].get(j) + " ");
			}System.out.println("");
		}
	}

	public void displayAdjacencyMatrix(){
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				System.out.print(adjacencyMatrix[i][j] ? "o " : "x ");
			}System.out.println("");
		}
	}

	public Graph getTranspose(){
		Graph g = new Graph(n, null, isDirected);
		g.adjacencyList = new ArrayList[n];

		for(int i = 0; i < n; i ++){
			g.adjacencyList[i] = new ArrayList<Integer>();
		}

		for(int i = 0; i < n; i ++){
			for(int j = 0 ; j < adjacencyList[i].size(); j++){
				int x = (int) adjacencyList[i].get(j);

				g.adjacencyList[x].add(i);
			}
		}
		g.displayAdjacencyList();
		return g;
	}

	public boolean areConnected(int x, int y){
		Stack stack = new Stack();
		boolean[] visited = new boolean[n];

		stack.push(x);
		visited[x] = true;
		while(!stack.isEmpty()){
			int curr = (int) stack.pop();
			if(curr == y){
				return true;
			}

			for(int i = 0; i < adjacencyList[curr].size(); i ++){
				if(visited[(int)adjacencyList[curr].get(i)]){
					continue;
				}
				stack.push((int)adjacencyList[curr].get(i));
				visited[(int)adjacencyList[curr].get(i)] = true;
			}
		}

		return false;
	}

	public void displayConnectedComponents(){
		boolean[] visited = new boolean[n];
		for(int i = 0; i < n; i ++){
			if(visited[i]){
				continue;
			}

			Stack stack = new Stack();

			stack.push(i);
			visited[i] = true;

			while(!stack.isEmpty()){
				int curr = (int) stack.pop();
				System.out.print(curr + " ");

				for(int j = 0; j < adjacencyList[curr].size(); j ++){
					if(visited[(int)(int)adjacencyList[curr].get(j)]){
						continue;
					}

					stack.push((int)adjacencyList[curr].get(j));
					visited[(int)adjacencyList[curr].get(j)] = true;
				}
			}

			System.out.println("");
		}
	}

	public void fillOrder(int i, boolean[] visited, Stack order){
		if(visited[i]){
			return;
		}

		visited[i] = true;
		for(int j = 0; j < adjacencyList[i].size(); j++){
			int x = (int)adjacencyList[i].get(j);

			fillOrder(x, visited, order);
		}

		order.push(i);
	}

	public void displayStronglyConnectedComponents(){
		Stack dfsOrder = new Stack();
		boolean[] visited = new boolean[n];

		for(int i = 0; i < n; i ++){
			if(visited[i]){
				continue;
			}
			
			fillOrder(i, visited, dfsOrder);
		}

		dfsOrder.print();

		for(int i = 0; i < n; i ++){
			visited[i] = false;
		}

		Graph g = getTranspose();

		while(!dfsOrder.isEmpty()){
			int i = dfsOrder.pop();
			if(visited[i]){
				continue;
			}

			Stack stack = new Stack();
			stack.push(i);
			visited[i] = true;
			while(!stack.isEmpty()){
				int curr = (int)stack.pop();
				System.out.print(curr + " ");
				for(int j = 0; j < g.adjacencyList[curr].size(); j ++){
					int x = (int) g.adjacencyList[curr].get(j);
					

					if(visited[x]){
						continue;
					}

					stack.push(x);
					visited[x] = true;
				}
			}
			System.out.println("");
		}
	}

	public int[] distanceToAllPoints(int x){
		int[] distance = new int[n];

		for(int i = 0; i < n; i ++){
			distance[i] = Integer.MAX_VALUE;
		}

		boolean[] visited = new boolean[n];
		Queue queue = new Queue();

		queue.enqueue(x);
		visited[x] = true;
		distance[x] = 0;
		while(!queue.isEmpty()){
			int curr = queue.dequeue();

			for(int i = 0; i < adjacencyList[curr].size(); i ++){
				if(visited[(int)adjacencyList[curr].get(i)]){
					continue;
				}
				queue.enqueue((int)adjacencyList[curr].get(i));
				visited[(int)adjacencyList[curr].get(i)] = true;
				distance[(int)adjacencyList[curr].get(i)] = distance[curr] + 1;
			}
		}
		return distance;
	}

	public int[] getShortestPath(int x, int y){
		int[] distance = new int[n];
		int[] parent = new int[n];
		for(int i = 0; i < n; i ++){
			distance[i] = Integer.MAX_VALUE;
		}

		boolean[] visited = new boolean[n];
		Queue queue = new Queue();

		queue.enqueue(x);
		visited[x] = true;
		distance[x] = 0;
		while(!queue.isEmpty()){
			int curr = queue.dequeue();

			for(int i = 0; i < adjacencyList[curr].size(); i ++){
				if(visited[(int)adjacencyList[curr].get(i)]){
					continue;
				}
				queue.enqueue((int)adjacencyList[curr].get(i));
				visited[(int)adjacencyList[curr].get(i)] = true;
				distance[(int)adjacencyList[curr].get(i)] = distance[curr] + 1;
				parent[(int)adjacencyList[curr].get(i)] = curr;
				if(curr == y){
					break;
				}
			}
		}

		int[] path = new int[distance[y] + 1];
		path[distance[y]] = y;
		for(int i = distance[y] - 1; i >= 0; i --){
			path[i] = parent[path[i + 1]];
		}

		return path;
	}

	public int getSink(){
		createAdjacencyMatrix(edges);
		displayAdjacencyMatrix();

		if(n == 1){
			return -1;
		}
		
		int i = 0;
		int j = 0;

		while(j < n){
			if(adjacencyMatrix[i][j] == true){
				i = j;
				j ++;
			}else{
				j++;
			}
		}

		int potenitalSink = i;

		if(potenitalSink == n){
			return -1;
		}

		for(i = 0; i < n; i ++){
			if(i == potenitalSink){
				continue;
			}

			if(adjacencyMatrix[potenitalSink][i] == true || adjacencyMatrix[i][potenitalSink] == false){
				return -1;
			}
		}

		return potenitalSink;
	}

	public boolean isBipartite(){
		int[] distance = distanceToAllPoints(0);

		boolean[] group = new boolean[n];

		for(int i = 0; i < n; i ++){
			group[i] = distance[i]%2 == 0;
		}

		for(int i = 0; i < edges.length; i ++){
			if(group[edges[i][0]] ^ group[edges[i][1]] == false){
				return false;
			}
		}

		return true;
	}

	public boolean cyclePresent(){
		if(isDirected){
			return cyclePresentDirected();
		}else{
			return cyclePresentUndirected();
		}
	}

	public boolean cyclePresentUndirected(){
		boolean[] visited = new boolean[n];
		int[] parent = new int[n];
		for(int i = 0; i < n; i ++){
			parent[i] = -1;
		}
		for(int i = 0; i < n; i ++){
			if(visited[i]){
				continue;
			}

			Stack stack = new Stack();

			stack.push(i);
			visited[i] = true;

			while(!stack.isEmpty()){
				int curr = (int) stack.pop();

				for(int j = 0; j < adjacencyList[curr].size(); j ++){
					


					if(visited[(int)adjacencyList[curr].get(j)] && parent[curr] != (int)adjacencyList[curr].get(j)){
						return true;
					}
					if(visited[(int)adjacencyList[curr].get(j)]){
						continue;
					}

					stack.push((int)adjacencyList[curr].get(j));
					visited[(int)adjacencyList[curr].get(j)] = true;
					parent[(int)adjacencyList[curr].get(j)] = curr;
				}
			}
		}

		return false;
	}

	public boolean cyclePresentDirected(){
		return topologicalSort() == null;
	}

	public ArrayList topologicalSort(){
		int[] inDegree = new int[n];

		ArrayList sort = new ArrayList<Integer>();

		for(int i = 0; i < n; i ++){
			for(int j = 0; j < adjacencyList[i].size(); j ++){
				inDegree[(int)adjacencyList[i].get(j)] ++;
			}
		}

		Queue queue = new Queue();
		boolean[] visited = new boolean[n];
		for(int i = 0; i < n; i ++){
			if(inDegree[i] == 0){
				queue.enqueue(i);
				visited[i] = true;
			}
		}


		while(!queue.isEmpty()){
			int curr = (int) queue.dequeue();
			sort.add(curr);

			for(int i = 0; i < adjacencyList[curr].size(); i ++){
				if(visited[(int)adjacencyList[curr].get(i)]){
					continue;
				}

				inDegree[(int)adjacencyList[curr].get(i)] --;
				if(inDegree[(int)adjacencyList[curr].get(i)] == 0){
					queue.enqueue((int)adjacencyList[curr].get(i));
				}
			}
		}

		if(sort.size() != n){
			return null;
		}

		return sort;
	}

	public boolean[] directEdges(int[][] edges){
		ArrayList topologicalOrder = topologicalSort();

		int[] position = new int[n];

		for(int i = 0; i < topologicalOrder.size(); i++){
			int x = (int) topologicalOrder.get(i);

			position[x] = i;  
		}

		boolean[] direction = new boolean[edges.length];

		for(int i = 0; i < edges.length; i++){
			direction[i] = position[edges[i][0]] < position[edges[i][1]];
		}

		return direction;
	}

	public void dfs(){
		boolean visited[] = new boolean[n];
		for(int i = 0; i < n; i ++){
			if(visited[i]){
				continue;
			}

			Stack stack = new Stack();

			stack.push(i);
			visited[i] = true;

			while(!stack.isEmpty()){
				int curr = (int) stack.pop();
				


				for(int j = 0; j < adjacencyList[curr].size(); j ++){
					if(visited[(int)adjacencyList[curr].get(j)]){
						continue;
					}
					stack.push((int)adjacencyList[curr].get(j));
					visited[(int)adjacencyList[curr].get(j)] = true;
				}
			}
		}
	}

	public void bfs(){
		boolean[] visited = new boolean[n];
		for(int i = 0; i < n; i ++){
			if(visited[i]){
				continue;
			}

			Queue queue = new Queue();

			queue.enqueue(i);
			visited[i] = true;

			while(!queue.isEmpty()){
				int curr = (int) queue.dequeue();
				


				for(int j = 0; j < adjacencyList[curr].size(); j ++){
					if(visited[(int)adjacencyList[curr].get(j)]){
						continue;
					}

					queue.enqueue((int)adjacencyList[curr].get(j));
					visited[(int)adjacencyList[curr].get(j)] = true;
				}
			}
		}
	}

	public void solve(){
		int[] degree = new int[n];
		for(int i = 0; i < n; i ++){
			degree[i] = adjacencyList[i].size();
		}

		int count1 = 0;
		int count2 = 0; 
		int count3 = 0;

		for(int i = 0; i < n; i ++){
			if(degree[i] == 1){
				count1 ++;
			}else if(degree[i] == 2){
				count2 ++;
			}else{
				count3 ++;
			}
		}

		if(count1 == 0 && count2 == n && count3 == 0){
			System.out.println("ring topology");
		}else if(count1 == 2 && count2 == n - 2 && count3 == 0){
			System.out.println("bus topology");
		}else if(count1 == n - 1 && count2 == 0 && count3 == 1){
			System.out.println("star topology");
		}else{
			System.out.println("unknown topology");
		}
	}
}










