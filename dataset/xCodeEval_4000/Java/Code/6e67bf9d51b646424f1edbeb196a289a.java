import java.util.Iterator;
import java.util.NoSuchElementException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;
 public class Main {


    final static double INFINITY = Double.POSITIVE_INFINITY;
    static double[] dist;
    static int[] parent;
    private static IndexMinPQ<Double> pq;    


    static Object[] adj;

    static double Dijkstra(int s, int t) {
        dist[s] = 0;
        parent[s]=s;
        for (int i = 0; i < dist.length; i++) 

            if (i != s) {
                dist[i] = INFINITY;
                parent[i]=i;
            
                pq.insert(i,dist[i]);

            }
        

        pq.insert(s,dist[s]);

        
        while (!pq.isEmpty()) {


        double d=   pq. minKey();
             int v = pq.delMin();

            for (int p = 0; adj[v] != null
                    && p < ((ArrayList<neighbor>) adj[v]).size(); p++)

                                                                        

                                                                        

            {
                if (d+ ((ArrayList<neighbor>) adj[v]).get(p).weight < dist[((ArrayList<neighbor>) adj[v])
                        .get(p).to]) {
                    dist[((ArrayList<neighbor>) adj[v]).get(p).to] = d
                            + ((ArrayList<neighbor>) adj[v]).get(p).weight;
                    parent[((ArrayList<neighbor>) adj[v]).get(p).to]=v;
                    


                    pq.decreaseKey(((ArrayList<neighbor>) adj[v]).get(p).to, dist[((ArrayList<neighbor>) adj[v]).get(p).to]) ;

                }
            }

        }
        return dist[t];

    }

    public static void main(String[] args) throws IOException {
        Scanner exp1 = new Scanner(System.in);

    

        String x = exp1.nextLine();
        String[] arr = x.split(" ");
        int v = Integer.parseInt(arr[0]);
        int e = Integer.parseInt(arr[1]);
        dist = new double[v+1];
        parent = new int[v+1];
        adj = new Object[v+1];
        int i = 0;
        while (i < e) {
            x = exp1.nextLine();
            arr = x.split(" ");
            int from = Integer.parseInt(arr[0]);
            int to = Integer.parseInt(arr[1]);
            double weight = Double.parseDouble(arr[2]);
            if (adj[from] == null) {
                ArrayList<neighbor> temp = new ArrayList<neighbor>();
                neighbor b = new neighbor(to, weight);
                temp.add(b);
                adj[from] = temp;
            }

            else {
                neighbor b = new neighbor(to, weight);
                ((ArrayList<neighbor>) adj[from]).add(b);
            }
            if (adj[to] == null) {
                ArrayList<neighbor> temp = new ArrayList<neighbor>();
                neighbor b = new neighbor(from, weight);
                temp.add(b);
                adj[to] = temp;
            }

            else {
                neighbor b = new neighbor(from, weight);
                ((ArrayList<neighbor>) adj[to]).add(b);
            }

            i++;

        }
        pq=new  IndexMinPQ<Double>(v+1);   





    

        int s = 1;


    

        int t = v;


        long start1 = System.currentTimeMillis();
        double dis = Dijkstra(s, t);

        long end1 = System.currentTimeMillis();
        long duration1 = (end1 - start1);
    


        if (dis != INFINITY)

        {
        

            Stack<Integer> k = new Stack<Integer>();
            int p = t;
            while (parent[p] != p) {
                k.push(p);
                p = parent[p];
            }
            k.push(s);
            while (!k.isEmpty()) {
                System.out.print(k.pop() );
                if (!k.isEmpty())
                    System.out.print(" ");
            }
            System.out.println();
        } else
            System.out.println("-1");



































































    }
}





 class IndexMinPQ<Key extends Comparable<Key>> implements Iterable<Integer> {
    private int NMAX;        

    private int N;           

    private int[] pq;        

    private int[] qp;        

    private Key[] keys;      


    
    public IndexMinPQ(int NMAX) {
        if (NMAX < 0) throw new IllegalArgumentException();
        this.NMAX = NMAX;
        keys = (Key[]) new Comparable[NMAX + 1];    

        pq   = new int[NMAX + 1];
        qp   = new int[NMAX + 1];                   

        for (int i = 0; i <= NMAX; i++) qp[i] = -1;
    }

    
    public boolean isEmpty() {
        return N == 0;
    }

    
    public boolean contains(int i) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        return qp[i] != -1;
    }

    
    public int size() {
        return N;
    }

    
    public void insert(int i, Key key) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (contains(i)) throw new IllegalArgumentException("index is already in the priority queue");
        N++;
        qp[i] = N;
        pq[N] = i;
        keys[i] = key;
        swim(N);
    }

    
    public int minIndex() { 
        if (N == 0) throw new NoSuchElementException("Priority queue underflow");
        return pq[1];        
    }

    
    public Key minKey() { 
        if (N == 0) throw new NoSuchElementException("Priority queue underflow");
        return keys[pq[1]];        
    }

    
    public int delMin() { 
        if (N == 0) throw new NoSuchElementException("Priority queue underflow");
        int min = pq[1];        
        exch(1, N--); 
        sink(1);
        qp[min] = -1;            

        keys[pq[N+1]] = null;    

        pq[N+1] = -1;            

        return min; 
    }

    
    public Key keyOf(int i) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        else return keys[i];
    }

    
    @Deprecated public void change(int i, Key key) {
        changeKey(i, key);
    }

    
    public void changeKey(int i, Key key) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        keys[i] = key;
        swim(qp[i]);
        sink(qp[i]);
    }

    
    public void decreaseKey(int i, Key key) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        if (keys[i].compareTo(key) <= 0) throw new IllegalArgumentException("Calling decreaseKey() with given argument would not strictly decrease the key");
        keys[i] = key;
        swim(qp[i]);
    }

    
    public void increaseKey(int i, Key key) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        if (keys[i].compareTo(key) >= 0) throw new IllegalArgumentException("Calling increaseKey() with given argument would not strictly increase the key");
        keys[i] = key;
        sink(qp[i]);
    }

    
    public void delete(int i) {
        if (i < 0 || i >= NMAX) throw new IndexOutOfBoundsException();
        if (!contains(i)) throw new NoSuchElementException("index is not in the priority queue");
        int index = qp[i];
        exch(index, N--);
        swim(index);
        sink(index);
        keys[i] = null;
        qp[i] = -1;
    }


   
    private boolean greater(int i, int j) {
        return keys[pq[i]].compareTo(keys[pq[j]]) > 0;
    }

    private void exch(int i, int j) {
        int swap = pq[i]; pq[i] = pq[j]; pq[j] = swap;
        qp[pq[i]] = i; qp[pq[j]] = j;
    }


   
    private void swim(int k)  {
        while (k > 1 && greater(k/2, k)) {
            exch(k, k/2);
            k = k/2;
        }
    }

    private void sink(int k) {
        while (2*k <= N) {
            int j = 2*k;
            if (j < N && greater(j, j+1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }


   

    
    public Iterator<Integer> iterator() { return new HeapIterator(); }

    private class HeapIterator implements Iterator<Integer> {
        

        private IndexMinPQ<Key> copy;

        

        

        public HeapIterator() {
            copy = new IndexMinPQ<Key>(pq.length - 1);
            for (int i = 1; i <= N; i++)
                copy.insert(pq[i], keys[pq[i]]);
        }

        public boolean hasNext()  { return !copy.isEmpty();                     }
        public void remove()      { throw new UnsupportedOperationException();  }

        public Integer next() {
            if (!hasNext()) throw new NoSuchElementException();
            return copy.delMin();
        }
    }


    




























































}


  class neighbor {
     int to;
     double weight;
     neighbor( int t,double w){
        to=t;
        weight=w;
     }
     }