
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Random;
import java.util.TreeSet;

public class E {

    
    static ArrayList<Double> solve(final int[] h, long[][] q) {
        int N=h.length, M=q.length;
        
        CountingTree<Integer> t1=new CountingTree<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int ret=h[o1]-h[o2];
                if(ret==0) {
                    ret=o1-o2;
                }
                return ret;
            }
        });
        CountingTree<Integer> t2=new CountingTree<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int ret=h[o1]-h[o2];
                if(ret==0) {
                    ret=o1-o2;
                }
                return ret;
            }
        });
        
        for (int i=0; i<N; i++) {
            t1.add(i);
            t2.add(i, h[i]);
        }
        
        ArrayList<Double> out=new ArrayList<Double>();
        for (int i=0; i<M; i++) {
            if(q[i][0]==1) {
                int j=(int)(q[i][1]-1);
                t1.remove(j);
                t2.remove(j, h[j]);
                h[j]=(int)q[i][2];
                t1.add(j);
                t2.add(j, h[j]);
            } else {
                int lo=0, hi=N-1;
                boolean done=false;
                while(lo<=hi) {
                    int mid=(lo+hi)>>1;
                    int j=t1.floor(mid);
                    long vol=t2.size(j, true);
                    int k=t1.floor(mid+1);
                    long free_vol=(long)mid*h[k]-vol;
                    if(free_vol==q[i][1]) {
                        out.add((double)h[k]); done=true; break;
                    } else if(free_vol>q[i][1]) {
                        hi=mid-1;
                    } else {
                        lo=mid+1;
                    }
                }
                if(!done) {
                    int j=t1.floor(lo);
                    long vol=t2.size(j, true);
                    double v=(double)(q[i][1]+vol)/(lo);
                    out.add(v);
                }
            }
        }
        
        return out;
    }
    
    
    static ArrayList<Double> baseline(final int[] h, long[][] q) {
        int N=h.length, M=q.length;
        
        TreeSet<Integer> t=new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int ret=h[o1]-h[o2];
                if(ret==0) {
                    ret=o1-o2;
                }
                return ret;
            }
        });
        
        for (int i=0; i<N; i++) {
            t.add(i);
        }
        
        ArrayList<Double> out=new ArrayList<Double>();
        for (int i=0; i<M; i++) {
            if(q[i][0]==1) {
                int j=(int)(q[i][1]-1);
                t.remove(j);
                h[j]=(int)q[i][2];
                t.add(j);
            } else {
                int k=0; double min=Double.MAX_VALUE;
                long v=q[i][1], vol=0;
                for (int j : t) {
                    vol+=h[j];
                    k++;
                    
                    double val=(double)(vol+v)/k;
                    if(min>val) {
                        min=val;
                    }
                }
                out.add(min);
            }
        }
        
        return out;
    }
    
    
    static StringBuilder sb=new StringBuilder();
    static void parse(String l, int[] here) {
        sb.setLength(0);
        int len=l.length(), j=0;
        for (int i=0; i<len; i++) {
            char c=l.charAt(i);
            if(c==' ') {
                here[j++]=Integer.parseInt(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }
        if(sb.length()>0) {
            here[j++]=Integer.parseInt(sb.toString());
        }
    }

    static void parse(String l, long[] here) {
        sb.setLength(0);
        int len=l.length(), j=0;
        for (int i=0; i<len; i++) {
            char c=l.charAt(i);
            if(c==' ') {
                here[j++]=Long.parseLong(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }
        if(sb.length()>0) {
            here[j++]=Long.parseLong(sb.toString());
        }
    }
    
    static void run_stream(InputStream ins) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] nq=br.readLine().split(" ");
        int n=Integer.parseInt(nq[0]);
        int m=Integer.parseInt(nq[1]);

        int[] h=new int[n];
        parse(br.readLine(), h);
        
        long[][] q=new long[m][3];
        
        for (int i=0; i<m; i++) {
            parse(br.readLine(), q[i]);
        }
        
        ArrayList<Double> ret=solve(h, q);
        sb.setLength(0);
        for(double d: ret) {
            sb.append(d+"\n");
        }
        
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        run_stream(System.in);
        
        

        

    }
    
    static void random_test() {
        Random r=new Random();
        int n=1000, m=1000;
        int[] h=new int[n];
        for (int i=0; i<n; i++) {
            h[i]=r.nextInt(n);
        }
        
        long[][] q=new long[m][3];
        for (int i=0; i<m; i++) {
            q[i][0]=r.nextInt(2)+1;
            if(q[i][0]==1) {
                q[i][1]=r.nextInt(n)+1;
                q[i][2]=r.nextInt(n);
            } else {
                q[i][1]=r.nextInt(10*n);
            }
        }
        
        test(h, q);
    }


    static void test(int[] h, long[][] q) {
        int n=h.length, m=q.length;
        
        ArrayList<Double> ret1=solve(h.clone(), q);
        ArrayList<Double> ret2=baseline(h.clone(), q);
        
        int err_cnt=0;
        for (int i=0; i<ret1.size(); i++) {
            if(ret1.get(i).doubleValue()!=ret2.get(i).doubleValue()) {
                System.out.println("at "+i+" expected "+ret2.get(i)+" got "+ret1.get(i));
                err_cnt++;
            }
        }
        if(err_cnt>0) {
            System.out.println(n+" "+m);
            for (int i=0; i<n; i++) {
                System.out.print(h[i]+" ");
            }
            System.out.println();
            for (int i=0; i<m; i++) {
                System.out.println(q[i][0]+" "+q[i][1]+(q[i][0]==1? " "+q[i][2]: ""));
            }
        } else {
            System.out.println("all good");
        }
    }
    
    static void test() throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String[] nq=br.readLine().split(" ");
        int n=Integer.parseInt(nq[0]);
        int m=Integer.parseInt(nq[1]);

        int[] h=new int[n];
        parse(br.readLine(), h);
        
        long[][] q=new long[m][3];
        
        for (int i=0; i<m; i++) {
            parse(br.readLine(), q[i]);
        }

        test(h, q);
    }
    
    
    
    
    
    
    
    
    
    
    
    static class CountingTree<E> {
        
        public static class Node<E> {
            public E value;
            public Node<E> left = null, right=null, parent=null;
            boolean color = BLACK;
            public int cnt=1;
            public long childCnt=0;
            

            
            public Node(E value, Node<E> parent) {
                this.value = value;
                this.parent = parent;
            }

            
            public E getValue() {
                return value;
            }

            public boolean equals(Object o) {
                if (!(o instanceof Node))
                    return false;
                Node<E> e = (Node<E>)o;

                return value.equals(e.value);
            }

            public int hashCode() {
                return value.hashCode();
            }

            public String toString() {
                return value.toString();
            }
            
            public boolean isDescendantOf(Node<E> e) {
                Node<E> _parent=parent;
                while(_parent!=null) {
                    if(_parent==e) {
                        return true;
                    }
                    _parent=_parent.parent;
                }
                return false;
            }
            
            public int getDepth() {
                int ret=0;
                Node<E> _parent=parent;
                while(_parent!=null) {
                    ret++;
                    _parent=_parent.parent;
                }
                return ret;
            }
        }
        
        protected Comparator<E> cmp=null;
        public Node<E> root;
        
        public CountingTree() {
            this(null);
        }
        
        public CountingTree(Comparator<E> cmp) {
            this.cmp=cmp;
        }

        protected static<E> Node<E> createNode(E value, Node<E> parent, int cnt) {
            Node<E> ret=new Node<E>(value, parent);
            ret.cnt=cnt;
            return ret;
        }
        
        protected int compare(E v1, E v2) {
            if(cmp==null) {
                Comparable<E> c1=(Comparable<E>)v1;
                return c1.compareTo(v2);
            } else {
                return cmp.compare(v1, v2);
            }
        }
        
        public int add(E value) {
            return add(value, 1);
        }
        
        public void set(E value, int cnt) {
            Node<E> n=getNode(value);
            if(n==null) {
                _add(value, cnt);
            } else {
                int delta=cnt-n.cnt;
                n.cnt=cnt;
                while(n.parent!=null) {
                    n=n.parent;
                    n.childCnt+=delta;
                }
            }
        }

        public int add(E value, int cnt) {
            return _add(value, cnt).cnt;
        }
        
        public static interface E2Cnt<E> {
            int size();
            E e(int i);
            int cnt(int i);
        }
        
        public static<E> CountingTree<E> buildFromSorted(E2Cnt<E> ee) {
            CountingTree<E> ret=new CountingTree<E>();
            ret.root=buildFromSorted(ee, 0, ee.size()-1);
            if(ret.root!=null) {
                setCounts(ret.root);
            }
            return ret;
        }
        
        private static<E> void setCounts(Node<E> n) {
            if(n.left!=null) {
                setCounts(n.left);
                n.childCnt+=n.left.childCnt+n.left.cnt;
            }
            if(n.right!=null) {
                setCounts(n.right);
                n.childCnt+=n.right.childCnt+n.right.cnt;
            }
        }

        protected static<E> Node<E> buildFromSorted(E2Cnt<E> ee, int from, int to) {
            Node<E> ret=null;
            if(to>=from) {
                int mid=(to+from)>>1;
                ret=createNode(ee.e(mid), null, ee.cnt(mid));
                if(mid>from) {
                    ret.left=buildFromSorted(ee, from, mid-1);
                }
                if(mid<to) {
                    ret.right=buildFromSorted(ee, mid+1, to);
                }
            }
            return ret;
        }
        
        protected Node<E> _add(E value, int cnt) {
            if(VALIDATE) {
                count(root);
            }

            Node<E> t = root;
            if (t == null) {
                root=createNode(value, null, cnt);
                return root;
            }
            int cmp;
            Node<E> parent;
            do {
                parent = t;
                cmp=compare(value, t.value);
                if (cmp < 0) {
                    t.childCnt+=cnt;
                    t = t.left;
                } else if (cmp > 0) {
                    t.childCnt+=cnt;
                    t = t.right;
                } else {
                    t.cnt+=cnt;
                    if(VALIDATE) {
                        count(root);
                    }
                    return t;
                }
            } while (t != null);

            Node<E> e=createNode(value, parent, cnt);
            if (cmp < 0)
                parent.left = e;
            else
                parent.right = e;

            if(VALIDATE) {
                count(root);
            }

            fixAfterInsertion(e);
            
            if(VALIDATE) {
                count(root);
            }
            
            return e;
        }

        public boolean remove(E value) {
            return remove(value, 1);
        }
        
        public boolean remove(E value, long cnt) {
            Node<E> p = root;
            while (p != null) {
                int cmp=compare(value, p.value);
                if (cmp < 0)
                    p = p.left;
                else if (cmp > 0)
                    p = p.right;
                else {
                    if(p.cnt>cnt) {
                        p.cnt-=cnt;
                        Node<E> parent=p.parent;
                        while (parent!=null) {
                            parent.childCnt-=cnt;
                            parent=parent.parent;
                        }
                        return true;
                    } else if(p.cnt<cnt) {
                        throw new IllegalStateException("Can not remove "+cnt+" of "+p+" - only "+p.cnt+" left");
                    }
                    break;
                }
            }
            
            if(p!=null) {
                deleteEntry(p);
                return true;
            } else {
                return false;
            }
        }
        
        public long removeAll(E value) {
            long cnt=size(value, value);
            if(cnt>0) {
                remove(value, cnt);
            }
            return cnt;
        }
        
        
        private void deleteEntry(Node<E> p) {
            if(VALIDATE) {
                count(root);
            }

            

            

            if (p.left != null && p.right != null) {
                Node<E> s = successor (p);
                p.value = s.value;
                if(s.cnt!=p.cnt) {
                    Node<E> parent = p.parent;
                    while (parent != null) {
                        parent.childCnt+=(s.cnt-p.cnt);
                        parent = parent.parent;
                    }
                }
                p.cnt=s.cnt;
                p = s;
            } 


            

            Node<E> replacement = (p.left != null ? p.left : p.right);

            if (replacement != null) {
                Node<E> parent = p.parent;
                while (parent != null) {
                    parent.childCnt-=p.cnt;
                    parent = parent.parent;
                }

                

                replacement.parent = p.parent;
                if (p.parent == null)
                    root = replacement;
                else if (p == p.parent.left)
                    p.parent.left  = replacement;
                else
                    p.parent.right = replacement;

                

                p.left = p.right = p.parent = null;

                if(VALIDATE) {
                    count(root);
                }
                

                if (p.color == BLACK) {
                    fixAfterDeletion(replacement);
                    if(VALIDATE) {
                        count(root);
                    }
                }
            } else if (p.parent == null) { 

                root = null;
            } else { 

                if (p.color == BLACK) {
                    fixAfterDeletion(p);
                }

                if (p.parent != null) {
                    Node<E> parent = p.parent;
                    while (parent != null) {
                        parent.childCnt-=p.cnt;
                        parent = parent.parent;
                    }

                    if (p == p.parent.left)
                        p.parent.left = null;
                    else if (p == p.parent.right)
                        p.parent.right = null;
                    p.parent = null;
                }
                if(VALIDATE) {
                    count(root);
                }
            }
        }
        
        public Node<E> getNode(E value) {
            Node<E> p=root;
            while (p!=null) {
                int cmp=compare(value, p.value);
                if (cmp < 0)
                    p = p.left;
                else if (cmp > 0)
                    p = p.right;
                else
                    return p;
            }
            return null;
        }

        public long size() {
            return root!=null? (root.cnt+root.childCnt): 0;
        }
        
        public long size(E from, E to) {
            return size(from, true, to, true);
        }
        
        public long iters=0;
        public long size(E to, boolean incTo) {
            if(root==null) {
                return 0;
            }
            Node<E> t = root;
            int cmp;
            long cnt=0;
            do {
                iters++;
                cmp=compare(to, t.value);
                if (cmp<0) {
                    t = t.left;
                } else if (cmp>0) {
                    cnt+=t.cnt;
                    if(t.left!=null) {
                        cnt+=(t.left.cnt+t.left.childCnt);
                    }
                    t = t.right;
                } else {
                    if(incTo) {
                        cnt+=t.cnt;
                    }
                    if(t.left!=null) {
                        cnt+=(t.left.cnt+t.left.childCnt);
                    }
                    break;
                }
            } while (t != null);
            return cnt;
        }
        
        public E floor(int cnt) {
            if(root==null) {
                return null;
            }
            Node<E> t=root;
            if(cnt>t.cnt+t.childCnt) {
                return null;
            }

            while(true) {
                if(t.left==null) {
                    if(cnt<=t.cnt) {
                        return t.value;
                    } else {
                        if(t.right==null) {
                            return t.value;
                        } else {
                            t=t.right;
                        }
                    }
                } else {
                    if(cnt<=t.left.childCnt+t.left.cnt) {
                        t=t.left;
                    } else {
                        if(cnt<=t.left.childCnt+t.left.cnt+t.cnt) {
                            return t.value;
                        }
                        if(t.right==null) {
                            throw new IllegalStateException(); 
                        } else {
                            cnt-=t.left.childCnt+t.left.cnt+t.cnt;
                            t=t.right;
                        }
                    }
                }
            }
        }
        
        public long size(E from, boolean incFrom, E to, boolean incTo) {
            return size(to, incTo)-size(from, !incFrom);
        }
        
        private static boolean VALIDATE=false;
        
        private int count(Node<E> n) {
            if(n==null) {
                return 0;
            }
            int cnt=count(n.left)+count(n.right);
            if(cnt!=n.childCnt) {
                throw new IllegalStateException();
            }
            return n.cnt+cnt;
        }
        
        private static final boolean RED   = false;
        private static final boolean BLACK = true;


        
        public Node<E> getFirstEntry() {
            Node<E> p = root;
            if (p != null)
                while (p.left != null)
                    p = p.left;
            return p;
        }

        
        public Node<E> getLastEntry() {
            Node<E> p = root;
            if (p != null)
                while (p.right != null)
                    p = p.right;
            return p;
        }
        
        public Node<E> successor(E value) {
            Node<E> p=root;
            while (p!=null) {
                int cmp=compare(value, p.value);
                if (cmp < 0) {
                    if(p.left!=null) {
                        p = p.left;
                    } else {
                        return p;
                    }
                } else if (cmp > 0) {
                    if(p.right!=null) {
                        p = p.right;
                    } else {
                        return successor(p);
                    }
                } else {
                    return successor(p);
                }
            }
            return null;
        }

        
        public Node<E> successor(Node<E> t) {
            if (t == null)
                return null;
            else if (t.right != null) {
                Node<E> p = t.right;
                while (p.left != null)
                    p = p.left;
                return p;
            } else {
                Node<E> p = t.parent;
                Node<E> ch = t;
                while (p != null && ch == p.right) {
                    ch = p;
                    p = p.parent;
                }
                return p;
            }
        }
        
        public Node<E> predecessor(E value) {
            Node<E> p=root;
            while (p!=null) {
                int cmp=compare(value, p.value);
                if (cmp < 0) {
                    if(p.left!=null) {
                        p = p.left;
                    } else {
                        return predecessor(p);
                    }
                } else if (cmp > 0) {
                    if(p.right!=null) {
                        p = p.right;
                    } else {
                        return p;
                    }
                } else {
                    return predecessor(p);
                }
            }
            return null;
        }

        
        public Node<E> predecessor(Node<E> t) {
            if (t == null)
                return null;
            else if (t.left != null) {
                Node<E> p = t.left;
                while (p.right != null)
                    p = p.right;
                return p;
            } else {
                Node<E> p = t.parent;
                Node<E> ch = t;
                while (p != null && ch == p.left) {
                    ch = p;
                    p = p.parent;
                }
                return p;
            }
        }
        
        public Node<E> getCeilingNode(E value) {
            Node<E> p = root;
            while (p != null) {
                int cmp = compare(value, p.value);
                if (cmp < 0) {
                    if (p.left != null)
                        p = p.left;
                    else
                        return p;
                } else if (cmp > 0) {
                    if (p.right != null) {
                        p = p.right;
                    } else {
                        Node<E> parent = p.parent;
                        Node<E> ch = p;
                        while (parent != null && ch == parent.right) {
                            ch = parent;
                            parent = parent.parent;
                        }
                        return parent;
                    }
                } else
                    return p;
            }
            return null;
        }

        public Node<E> getFloorNode(E value) {
            Node<E> p = root;
            while (p != null) {
                int cmp = compare(value, p.value);
                if (cmp > 0) {
                    if (p.right != null)
                        p = p.right;
                    else
                        return p;
                } else if (cmp < 0) {
                    if (p.left != null) {
                        p = p.left;
                    } else {
                        Node<E> parent = p.parent;
                        Node<E> ch = p;
                        while (parent != null && ch == parent.left) {
                            ch = parent;
                            parent = parent.parent;
                        }
                        return parent;
                    }
                } else
                    return p;

            }
            return null;
        }


        

        private static <E> boolean colorOf(Node<E> p) {
            return (p == null ? BLACK : p.color);
        }

        private static <E> Node<E> parentOf(Node<E> p) {
            return (p == null ? null: p.parent);
        }

        private static <E> void setColor(Node<E> p, boolean c) {
            if (p != null)
            p.color = c;
        }

        private static <E> Node<E> leftOf(Node<E> p) {
            return (p == null) ? null: p.left;
        }

        private static <E> Node<E> rightOf(Node<E> p) {
            return (p == null) ? null: p.right;
        }

        
        private void rotateLeft(Node<E> p) {
            if (p != null) {
                Node<E> r = p.right;
                p.childCnt-=(r.cnt+(r.right!=null? r.right.cnt+r.right.childCnt: 0));
                r.childCnt+=(p.cnt+(p.left!=null? p.left.cnt+p.left.childCnt: 0));

                p.right = r.left;
                if (r.left != null)
                    r.left.parent = p;
                r.parent = p.parent;
                if (p.parent == null)
                    root = r;
                else if (p.parent.left == p)
                    p.parent.left = r;
                else
                    p.parent.right = r;
                r.left = p;
                p.parent = r;
            }
        }

        
        private void rotateRight(Node<E> p) {
            if (p != null) {
                Node<E> l = p.left;
                p.childCnt-=(l.cnt+(l.left!=null? l.left.cnt+l.left.childCnt: 0));
                l.childCnt+=(p.cnt+(p.right!=null? p.right.cnt+p.right.childCnt: 0));

                p.left = l.right;
                if (l.right != null) l.right.parent = p;
                l.parent = p.parent;
                if (p.parent == null)
                    root = l;
                else if (p.parent.right == p)
                    p.parent.right = l;
                else p.parent.left = l;
                l.right = p;
                p.parent = l;
            }
        }

        
        private void fixAfterInsertion(Node<E> x) {
            x.color = RED;

            while (x != null && x != root && x.parent.color == RED) {
                if (parentOf(x) == leftOf(parentOf(parentOf(x)))) {
                    Node<E> y = rightOf(parentOf(parentOf(x)));
                    if (colorOf(y) == RED) {
                        setColor(parentOf(x), BLACK);
                        setColor(y, BLACK);
                        setColor(parentOf(parentOf(x)), RED);
                        x = parentOf(parentOf(x));
                    } else {
                        if (x == rightOf(parentOf(x))) {
                            x = parentOf(x);
                            rotateLeft(x);
                        }
                        setColor(parentOf(x), BLACK);
                        setColor(parentOf(parentOf(x)), RED);
                        rotateRight(parentOf(parentOf(x)));
                    }
                } else {
                    Node<E> y = leftOf(parentOf(parentOf(x)));
                    if (colorOf(y) == RED) {
                        setColor(parentOf(x), BLACK);
                        setColor(y, BLACK);
                        setColor(parentOf(parentOf(x)), RED);
                        x = parentOf(parentOf(x));
                    } else {
                        if (x == leftOf(parentOf(x))) {
                            x = parentOf(x);
                            rotateRight(x);
                        }
                        setColor(parentOf(x), BLACK);
                        setColor(parentOf(parentOf(x)), RED);
                        rotateLeft(parentOf(parentOf(x)));
                    }
                }
            }
            root.color = BLACK;
        }

        
        private void fixAfterDeletion(Node<E> x) {
            while (x != root && colorOf(x) == BLACK) {
                if (x == leftOf(parentOf(x))) {
                    Node<E> sib = rightOf(parentOf(x));

                    if (colorOf(sib) == RED) {
                        setColor(sib, BLACK);
                        setColor(parentOf(x), RED);
                        rotateLeft(parentOf(x));
                        sib = rightOf(parentOf(x));
                    }

                    if (colorOf(leftOf(sib))  == BLACK &&
                        colorOf(rightOf(sib)) == BLACK) {
                        setColor(sib, RED);
                        x = parentOf(x);
                    } else {
                        if (colorOf(rightOf(sib)) == BLACK) {
                            setColor(leftOf(sib), BLACK);
                            setColor(sib, RED);
                            rotateRight(sib);
                            sib = rightOf(parentOf(x));
                        }
                        setColor(sib, colorOf(parentOf(x)));
                        setColor(parentOf(x), BLACK);
                        setColor(rightOf(sib), BLACK);
                        rotateLeft(parentOf(x));
                        x = root;
                    }
                } else { 

                    Node<E> sib = leftOf(parentOf(x));

                    if (colorOf(sib) == RED) {
                        setColor(sib, BLACK);
                        setColor(parentOf(x), RED);
                        rotateRight(parentOf(x));
                        sib = leftOf(parentOf(x));
                    }

                    if (colorOf(rightOf(sib)) == BLACK &&
                        colorOf(leftOf(sib)) == BLACK) {
                        setColor(sib, RED);
                        x = parentOf(x);
                    } else {
                        if (colorOf(leftOf(sib)) == BLACK) {
                            setColor(rightOf(sib), BLACK);
                            setColor(sib, RED);
                            rotateLeft(sib);
                            sib = leftOf(parentOf(x));
                        }
                        setColor(sib, colorOf(parentOf(x)));
                        setColor(parentOf(x), BLACK);
                        setColor(leftOf(sib), BLACK);
                        rotateRight(parentOf(x));
                        x = root;
                    }
                }
            }

            setColor(x, BLACK);
        }
        
        public void print(PrintStream out) {
            Node<E> last=getLastEntry();
            Node<E> curr=getFirstEntry();
            Node<E> succ=successor(curr);
            
            if(curr!=null) {
                out.print(curr.value+"("+(curr.cnt)+") ");
                while(succ!=null && succ!=last) {
                    curr=succ;
                    succ=successor(succ);
                    out.print(curr.value+"("+(curr.cnt)+") ");
                }
                if(getFirstEntry()!=last) {
                    out.print(last.value+"("+(last.cnt)+") ");
                }
            } else {
                out.print("\ttree is empty");
            }
            out.println();
        }

        public interface NodeVisitor<E> {
            boolean visit(Node<E> n);
        }

        public void visitInOrder(NodeVisitor<E> nv) {
            visitInOrder(nv, null, false, null, false);
        }
        
        public void visitInOrder(NodeVisitor<E> nv, E from, boolean incFrom, E to, boolean incTo) {
            visitInOrder(root, nv, from, incFrom, to, incTo);
        }

        private boolean visitInOrder(Node<E> n, NodeVisitor<E> nv, E from, boolean incFrom, E to, boolean incTo) {
            if(n!=null) {
                int cmp1=from!=null? compare(n.value, from): 1;
                int cmp2=to!=null? compare(n.value, to): -1;
                if(n.left!=null&&(from==null||cmp1>0)) {
                    if(!visitInOrder(n.left, nv, from, incFrom, to, incTo)) {
                        return false;
                    }
                }
                if((cmp1>0||incFrom&&cmp1==0)&&(cmp2<0||incTo&&cmp2==0)) {
                    if(!nv.visit(n)) {
                        return false;
                    }
                }
                if(n.right!=null&&(to==null||cmp2<0)) {
                    if(!visitInOrder(n.right, nv, from, incFrom, to, incTo)) {
                        return false;
                    }
                }
            }
            return true;
        }
        
        public interface Node2String<E> {
            String toSring(Node<E> n);
        }
        
        public String toString() {
            return toString(null);
        }
        
        public String toString(final Node2String<E> n2s) {
            if(root==null) {
                return "[]";
            }
            final StringBuilder sb=new StringBuilder();
            sb.append('[');
            visitInOrder(new NodeVisitor<E>() {
                public boolean visit(Node<E> n) {
                    if(sb.length()>1){
                        sb.append(",");
                    }
                    sb.append(n2s!=null? n2s.toSring(n): n.value);
                    return true;
                }
            });
            sb.append(']');
            return sb.toString();
        }
    }
}
