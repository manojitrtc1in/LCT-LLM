

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
import java.util.Scanner;

public class c
{
    public static void computePaths(Vertex[] vertices)
    {
        vertices[0].minDistance = 0.;
        FibonacciHeap<Vertex> vertexQueue = new FibonacciHeap<Vertex>();
        for (int i = 0; i < vertices.length; i++) {
        	vertices[i].entry = vertexQueue.enqueue(vertices[i], vertices[i].minDistance);
        	
		}

	while (!vertexQueue.isEmpty()) {
	    Vertex u = vertexQueue.dequeueMin().getValue();

            

            for (Edge e : u.adjacencies)
            {
                Vertex v = e.target;
                double weight = e.weight;
                double distanceThroughU = u.minDistance + weight;
		if (distanceThroughU < v.minDistance) {

		    v.minDistance = distanceThroughU ;
		    v.previous = u;
		    vertexQueue.decreaseKey(v.entry, v.minDistance);
		}
            }
        }
    }

    public static List<Vertex> getShortestPathTo(Vertex target)
    {
        List<Vertex> path = new ArrayList<Vertex>();
        for (Vertex vertex = target; vertex != null; vertex = vertex.previous)
            path.add(vertex);

        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args)
    {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		
		Vertex[] vertices = new Vertex[n];
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		for (int i = 0; i < vertices.length; i++) {
			vertices[i] = new Vertex(i);
		}
		vertices[0].minDistance = 0;
		
		for (int i = 0; i < m; i++) {
			int a = in.nextInt()-1,b=in.nextInt()-1,w=in.nextInt();
			vertices[a].adj.add(new Edge(vertices[b], w));
			vertices[b].adj.add(new Edge(vertices[a], w));
		}
		for (int i = 0; i < vertices.length; i++) {
			vertices[i].adjacencies = new Edge[vertices[i].adj.size()];
			vertices[i].adjacencies = (Edge[]) vertices[i].adj.toArray(vertices[i].adjacencies);
		}
	
        computePaths(vertices);
        Vertex v = vertices[n-1];
	    if(v.minDistance == Double.POSITIVE_INFINITY)
	    	System.out.println(-1);
	    else
	    {
		    List<Vertex> path = getShortestPathTo(v);
		    for (int i = 0; i < path.size(); i++) {
				System.out.print(path.get(i)+" ");
			}
	    }
    }
}

class Vertex implements Comparable<Vertex>
{
	public int index;
	public ArrayList<Edge> adj  = new ArrayList<Edge>();
    public Edge[] adjacencies;
    public double minDistance = Double.POSITIVE_INFINITY;
    public Vertex previous;
    public Entry<Vertex> entry;
    public Vertex(int index) { this.index = index; }
    public String toString() { return (index+1) + ""; }
    public int compareTo(Vertex other)
    {
        return Double.compare(minDistance, other.minDistance);
    }

}


class Edge
{
    public final Vertex target;
    public final double weight;
    public Edge(Vertex argTarget, double argWeight)
    { target = argTarget; weight = argWeight; }
}

class FibonacciHeap<T> {
    

    
    private Entry<T> mMin = null;

    
    private int mSize = 0;

    
    public Entry<T> enqueue(T value, double priority) {
        checkPriority(priority);

        
        Entry<T> result = new Entry<T>(value, priority);

        
        mMin = mergeLists(mMin, result);

        
        ++mSize;

        
        return result;
    }

    
    public Entry<T> min() {
        if (isEmpty())
            throw new NoSuchElementException("Heap is empty.");
        return mMin;
    }

    
    public boolean isEmpty() {
        return mMin == null;
    }

    
    public int size() {
        return mSize;
    }

    
    public static <T> FibonacciHeap<T> merge(FibonacciHeap<T> one, FibonacciHeap<T> two) {
        
        FibonacciHeap<T> result = new FibonacciHeap<T>();

        
        result.mMin = mergeLists(one.mMin, two.mMin);

        
        result.mSize = one.mSize + two.mSize;

        
        one.mSize = two.mSize = 0;
        one.mMin  = null;
        two.mMin  = null;

        
        return result;
    }

    
    public Entry<T> dequeueMin() {
        
        if (isEmpty())
            throw new NoSuchElementException("Heap is empty.");

        
        --mSize;

        
        Entry<T> minElem = mMin;

        
        if (mMin.mNext == mMin) { 

            mMin = null;
        }
        else { 

            mMin.mPrev.mNext = mMin.mNext;
            mMin.mNext.mPrev = mMin.mPrev;
            mMin = mMin.mNext; 

        }

        
        if (minElem.mChild != null) {
            
            Entry<?> curr = minElem.mChild;
            do {
                curr.mParent = null;

                
                curr = curr.mNext;
            } while (curr != minElem.mChild);
        }

        
        mMin = mergeLists(mMin, minElem.mChild);

        
        if (mMin == null) return minElem;

        
        List<Entry<T>> treeTable = new ArrayList<Entry<T>>();

        
        List<Entry<T>> toVisit = new ArrayList<Entry<T>>();

        
        for (Entry<T> curr = mMin; toVisit.isEmpty() || toVisit.get(0) != curr; curr = curr.mNext)
            toVisit.add(curr);

        
        for (Entry<T> curr: toVisit) {
            
            while (true) {
                
                while (curr.mDegree >= treeTable.size())
                    treeTable.add(null);

                
                if (treeTable.get(curr.mDegree) == null) {
                    treeTable.set(curr.mDegree, curr);
                    break;
                }

                
                Entry<T> other = treeTable.get(curr.mDegree);
                treeTable.set(curr.mDegree, null); 


                
                Entry<T> min = (other.mPriority < curr.mPriority)? other : curr;
                Entry<T> max = (other.mPriority < curr.mPriority)? curr  : other;

                
                max.mNext.mPrev = max.mPrev;
                max.mPrev.mNext = max.mNext;

                
                max.mNext = max.mPrev = max;
                min.mChild = mergeLists(min.mChild, max);
                
                
                max.mParent = min;

                
                max.mIsMarked = false;

                
                ++min.mDegree;

                
                curr = min;
            }

            
            if (curr.mPriority <= mMin.mPriority) mMin = curr;
        }
        return minElem;
    }

    
    public void decreaseKey(Entry<T> entry, double newPriority) {
        checkPriority(newPriority);
        if (newPriority > entry.mPriority)
            throw new IllegalArgumentException("New priority exceeds old.");

        
        decreaseKeyUnchecked(entry, newPriority);
    }
    
    
    public void delete(Entry<T> entry) {
        
        decreaseKeyUnchecked(entry, Double.NEGATIVE_INFINITY);

        
        dequeueMin();
    }

    
    private void checkPriority(double priority) {
        if (Double.isNaN(priority))
            throw new IllegalArgumentException(priority + " is invalid.");
    }

    
    private static <T> Entry<T> mergeLists(Entry<T> one, Entry<T> two) {
        
        if (one == null && two == null) { 

            return null;
        }
        else if (one != null && two == null) { 

            return one;
        }
        else if (one == null && two != null) { 

            return two;
        }
        else { 

            
            Entry<T> oneNext = one.mNext; 

            one.mNext = two.mNext;
            one.mNext.mPrev = one;
            two.mNext = oneNext;
            two.mNext.mPrev = two;

            
            return one.mPriority < two.mPriority? one : two;
        }
    }

    
    private void decreaseKeyUnchecked(Entry<T> entry, double priority) {
        
        entry.mPriority = priority;

        
        if (entry.mParent != null && entry.mPriority <= entry.mParent.mPriority)
            cutNode(entry);

        
        if (entry.mPriority <= mMin.mPriority)
            mMin = entry;
    }

    
    private void cutNode(Entry<T> entry) {
        
        entry.mIsMarked = false;

        
        if (entry.mParent == null) return;

        
        if (entry.mNext != entry) { 

            entry.mNext.mPrev = entry.mPrev;
            entry.mPrev.mNext = entry.mNext;
        }

        
        if (entry.mParent.mChild == entry) {
            
            if (entry.mNext != entry) {
                entry.mParent.mChild = entry.mNext;
            }
            
            else {
                entry.mParent.mChild = null;
            }
        }

        
        --entry.mParent.mDegree;

        
        entry.mPrev = entry.mNext = entry;
        mMin = mergeLists(mMin, entry);

        
        if (entry.mParent.mIsMarked)
            cutNode(entry.mParent);
        else
            entry.mParent.mIsMarked = true;

        
        entry.mParent = null;
    }
}

class Entry<T> {
    int     mDegree = 0;       

     boolean mIsMarked = false; 


     Entry<T> mNext;   

     Entry<T> mPrev;

     Entry<T> mParent; 


     Entry<T> mChild;  


     T      mElem;     

     double mPriority; 


    
    public T getValue() {
        return mElem;
    }
    
    public void setValue(T value) {
        mElem = value;
    }

    
    public double getPriority() {
        return mPriority;
    }

    
    public Entry(T elem, double priority) {
        mNext = mPrev = this;
        mElem = elem;
        mPriority = priority;
    }
}