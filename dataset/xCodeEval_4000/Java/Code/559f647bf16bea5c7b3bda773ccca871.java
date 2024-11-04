import java.util.*;

public class DijkstraTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		long[][] w = new long[26][26];
		char[] str1 = in.next().trim().toCharArray();
		char[] str2 = in.next().trim().toCharArray();
		int n = in.nextInt();
		Dijkstra d = new Dijkstra(26);
		for(int i=0; i<n; i++) {
			int a = in.next().trim().charAt(0)-'a';
			int b = in.next().trim().charAt(0)-'a';
			int c = in.nextInt();
			d.addEdge(a,b,c);
		}
		for(int i=0; i<26; i++) {
			long[] x = d.run(i,28);
			for(int j=0; j<26; j++)
				w[i][j] = x[j];
		}
		
		if(str1.length != str2.length) {
			System.out.println("-1");
			return;
		}
		char[] res = new char[str1.length];
		long t = 0;
		for(int i=0; i<res.length; i++) {
			int a = str1[i]-'a';
			int b = str2[i]-'a';
			int best = 0;
			for(int j=1; j<26; j++)
				if(w[a][best] + w[b][best] > w[a][j] + w[b][j])
					best = j;
			res[i] = (char)(best+'a');
			t += w[a][best] + w[b][best];
		}
		if(t > (long)1e9) {
			System.out.println("-1");
			return;
		}
		System.out.println(t);
		System.out.println(new String(res));
	}

	static class Dijkstra {
		int n;
		long oo=(long)1e12;	

		long[] dist;
		int[] prev;	

		ArrayList<E>[] e;	

		PriorityQueue<E> q;	

		
		Dijkstra(int a) {
			n=a;
			dist = new long[n];
			prev = new int[n];
			q = new PriorityQueue<E>();
			e = new ArrayList[n];
			for(int i=0; i<n; i++)
				e[i] = new ArrayList<E>();
		}
		void addEdge(int u, int v, int w) {
			e[u].add(new E(v,w));
		}
		long[] run(int s, int t) {
			Arrays.fill(dist,oo);
			Arrays.fill(prev,-1);
			dist[s] = 0;
			
			FibonacciHeap<Integer> fh = new FibonacciHeap<Integer>();
			FibonacciHeapNode<Integer>[] nodes = new FibonacciHeapNode[n];
			for(int i=0; i<n; i++) {
				nodes[i] = new FibonacciHeapNode<Integer>(i,dist[i]);
				fh.insert(nodes[i],nodes[i].key);
			}
			while(!fh.isEmpty()) {
				int crnt = fh.removeMin().getData();
				if(crnt == t) break;
				for(E x : e[crnt]) {
					long k = dist[crnt]+x.w;
					if(k < dist[x.v]) {
						dist[x.v] = k;
						fh.decreaseKey(nodes[x.v], dist[x.v]);
					}
				}
			}
			
			
			return dist;
		}
		class Node implements Comparable<Node> {
			long dist;
			int i;
			ArrayList<E> adj;
			Node(ArrayList<E> a, long d, int c) {
				adj = a;
				dist = d;
				i=c;
			}
			public int compareTo(Node n) {
				if(dist < n.dist) return -1;
				if(dist > n.dist) return 1;
				return i-n.i;
			}
		}
		class E implements Comparable<E>{
			int v;
			long w;
			E(int y,long z) {
				v=y;
				w=z;
			}
			public int compareTo(E e) {
				if(w-e.w < 0) return -1;
				if(w-e.w > 0) return 1;
				return 0;
			}
		}
	}
	
	


	
	static class FibonacciHeap<T>
	{
	    


	    private static final double oneOverLogPhi =
	        1.0 / Math.log((1.0 + Math.sqrt(5.0)) / 2.0);

	    


	    
	    private FibonacciHeapNode<T> minNode;

	    
	    private int nNodes;

	    


	    
	    public FibonacciHeap()
	    {
	    } 


	    


	    
	    public boolean isEmpty()
	    {
	        return minNode == null;
	    }

	    


	    
	    public void clear()
	    {
	        minNode = null;
	        nNodes = 0;
	    }

	    


	    
	    public void decreaseKey(FibonacciHeapNode<T> x, double k)
	    {
	        if (k > x.key) {
	            throw new IllegalArgumentException(
	                "decreaseKey() got larger key value");
	        }

	        x.key = k;

	        FibonacciHeapNode<T> y = x.parent;

	        if ((y != null) && (x.key < y.key)) {
	            cut(x, y);
	            cascadingCut(y);
	        }

	        if (x.key < minNode.key) {
	            minNode = x;
	        }
	    }

	    


	    
	    public void delete(FibonacciHeapNode<T> x)
	    {
	        

	        decreaseKey(x, Double.NEGATIVE_INFINITY);

	        

	        removeMin();
	    }

	    


	    
	    public void insert(FibonacciHeapNode<T> node, double key)
	    {
	        node.key = key;

	        

	        if (minNode != null) {
	            node.left = minNode;
	            node.right = minNode.right;
	            minNode.right = node;
	            node.right.left = node;

	            if (key < minNode.key) {
	                minNode = node;
	            }
	        } else {
	            minNode = node;
	        }

	        nNodes++;
	    }

	    


	    
	    public FibonacciHeapNode<T> min()
	    {
	        return minNode;
	    }

	    


	    
	    public FibonacciHeapNode<T> removeMin()
	    {
	        FibonacciHeapNode<T> z = minNode;

	        if (z != null) {
	            int numKids = z.degree;
	            FibonacciHeapNode<T> x = z.child;
	            FibonacciHeapNode<T> tempRight;

	            

	            while (numKids > 0) {
	                tempRight = x.right;

	                

	                x.left.right = x.right;
	                x.right.left = x.left;

	                

	                x.left = minNode;
	                x.right = minNode.right;
	                minNode.right = x;
	                x.right.left = x;

	                

	                x.parent = null;
	                x = tempRight;
	                numKids--;
	            }

	            

	            z.left.right = z.right;
	            z.right.left = z.left;

	            if (z == z.right) {
	                minNode = null;
	            } else {
	                minNode = z.right;
	                consolidate();
	            }

	            

	            nNodes--;
	        }

	        return z;
	    }

	    


	    
	    public int size()
	    {
	        return nNodes;
	    }

	    


	    
	    public static <T> FibonacciHeap<T> union(
	        FibonacciHeap<T> h1,
	        FibonacciHeap<T> h2)
	    {
	        FibonacciHeap<T> h = new FibonacciHeap<T>();

	        if ((h1 != null) && (h2 != null)) {
	            h.minNode = h1.minNode;

	            if (h.minNode != null) {
	                if (h2.minNode != null) {
	                    h.minNode.right.left = h2.minNode.left;
	                    h2.minNode.left.right = h.minNode.right;
	                    h.minNode.right = h2.minNode;
	                    h2.minNode.left = h.minNode;

	                    if (h2.minNode.key < h1.minNode.key) {
	                        h.minNode = h2.minNode;
	                    }
	                }
	            } else {
	                h.minNode = h2.minNode;
	            }

	            h.nNodes = h1.nNodes + h2.nNodes;
	        }

	        return h;
	    }

	    


	    
	    public String toString()
	    {
	        if (minNode == null) {
	            return "FibonacciHeap=[]";
	        }

	        

	        Stack<FibonacciHeapNode<T>> stack = new Stack<FibonacciHeapNode<T>>();
	        stack.push(minNode);

	        StringBuffer buf = new StringBuffer(512);
	        buf.append("FibonacciHeap=[");

	        

	        while (!stack.empty()) {
	            FibonacciHeapNode<T> curr = stack.pop();
	            buf.append(curr);
	            buf.append(", ");

	            if (curr.child != null) {
	                stack.push(curr.child);
	            }

	            FibonacciHeapNode<T> start = curr;
	            curr = curr.right;

	            while (curr != start) {
	                buf.append(curr);
	                buf.append(", ");

	                if (curr.child != null) {
	                    stack.push(curr.child);
	                }

	                curr = curr.right;
	            }
	        }

	        buf.append(']');

	        return buf.toString();
	    }

	    


	    
	    protected void cascadingCut(FibonacciHeapNode<T> y)
	    {
	        FibonacciHeapNode<T> z = y.parent;

	        

	        if (z != null) {
	            

	            if (!y.mark) {
	                y.mark = true;
	            } else {
	                

	                cut(y, z);

	                

	                cascadingCut(z);
	            }
	        }
	    }

	    


	    protected void consolidate()
	    {
	        int arraySize =
	            ((int) Math.floor(Math.log(nNodes) * oneOverLogPhi)) + 1;

	        List<FibonacciHeapNode<T>> array =
	            new ArrayList<FibonacciHeapNode<T>>(arraySize);

	        

	        for (int i = 0; i < arraySize; i++) {
	            array.add(null);
	        }

	        

	        int numRoots = 0;
	        FibonacciHeapNode<T> x = minNode;

	        if (x != null) {
	            numRoots++;
	            x = x.right;

	            while (x != minNode) {
	                numRoots++;
	                x = x.right;
	            }
	        }

	        

	        while (numRoots > 0) {
	            

	            int d = x.degree;
	            FibonacciHeapNode<T> next = x.right;

	            

	            for (;;) {
	                FibonacciHeapNode<T> y = array.get(d);
	                if (y == null) {
	                    

	                    break;
	                }

	                

	                

	                if (x.key > y.key) {
	                    FibonacciHeapNode<T> temp = y;
	                    y = x;
	                    x = temp;
	                }

	                

	                link(y, x);

	                

	                array.set(d, null);
	                d++;
	            }

	            

	            

	            array.set(d, x);

	            

	            x = next;
	            numRoots--;
	        }

	        

	        

	        minNode = null;

	        for (int i = 0; i < arraySize; i++) {
	            FibonacciHeapNode<T> y = array.get(i);
	            if (y == null) {
	                continue;
	            }

	            

	            if (minNode != null) {
	                

	                y.left.right = y.right;
	                y.right.left = y.left;

	                

	                y.left = minNode;
	                y.right = minNode.right;
	                minNode.right = y;
	                y.right.left = y;

	                

	                if (y.key < minNode.key) {
	                    minNode = y;
	                }
	            } else {
	                minNode = y;
	            }
	        }
	    }

	    


	    
	    protected void cut(FibonacciHeapNode<T> x, FibonacciHeapNode<T> y)
	    {
	        

	        x.left.right = x.right;
	        x.right.left = x.left;
	        y.degree--;

	        

	        if (y.child == x) {
	            y.child = x.right;
	        }

	        if (y.degree == 0) {
	            y.child = null;
	        }

	        

	        x.left = minNode;
	        x.right = minNode.right;
	        minNode.right = x;
	        x.right.left = x;

	        

	        x.parent = null;

	        

	        x.mark = false;
	    }

	    


	    
	    protected void link(FibonacciHeapNode<T> y, FibonacciHeapNode<T> x)
	    {
	        

	        y.left.right = y.right;
	        y.right.left = y.left;

	        

	        y.parent = x;

	        if (x.child == null) {
	            x.child = y;
	            y.right = y;
	            y.left = y;
	        } else {
	            y.left = x.child;
	            y.right = x.child.right;
	            x.child.right = y;
	            y.right.left = y;
	        }

	        

	        x.degree++;

	        

	        y.mark = false;
	    }

	    

	}

	

	
	

	
	static class FibonacciHeapNode<T>
	{
	    


	    
	    T data;

	    
	    FibonacciHeapNode<T> child;

	    
	    FibonacciHeapNode<T> left;

	    
	    FibonacciHeapNode<T> parent;

	    
	    FibonacciHeapNode<T> right;

	    
	    boolean mark;

	    
	    double key;

	    
	    int degree;

	    


	    
	    public FibonacciHeapNode(T data, double key)
	    {
	        right = this;
	        left = this;
	        this.data = data;
	        this.key = key;
	    }

	    


	    
	    public final double getKey()
	    {
	        return key;
	    }

	    
	    public final T getData()
	    {
	        return data;
	    }

	    
	    public String toString()
	    {
	        if (true) {
	            return Double.toString(key);
	        } else {
	            StringBuffer buf = new StringBuffer();
	            buf.append("Node=[parent = ");

	            if (parent != null) {
	                buf.append(Double.toString(parent.key));
	            } else {
	                buf.append("---");
	            }

	            buf.append(", key = ");
	            buf.append(Double.toString(key));
	            buf.append(", degree = ");
	            buf.append(Integer.toString(degree));
	            buf.append(", right = ");

	            if (right != null) {
	                buf.append(Double.toString(right.key));
	            } else {
	                buf.append("---");
	            }

	            buf.append(", left = ");

	            if (left != null) {
	                buf.append(Double.toString(left.key));
	            } else {
	                buf.append("---");
	            }

	            buf.append(", child = ");

	            if (child != null) {
	                buf.append(Double.toString(child.key));
	            } else {
	                buf.append("---");
	            }

	            buf.append(']');

	            return buf.toString();
	        }
	    }

	    

	}

	

}
