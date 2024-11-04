import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.TreeSet;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;


public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int i,j;
        Graph g = new Graph(n);
        for(i=0;i<n;++i){
            j = in.nextInt()-1;
            if(j>=0) g.id0(new Edge(i,j));
        }

        Graph.id1 lt = new Graph.id1(g);
        Graph.id3 d = new Graph.id3(g);
        TreeMap<Integer, DataStruct.id4> t[] = new TreeMap[d.ways];
        int lx[] = new int[d.ways];
        int x[] = new int[n];
        
        for(i=0;i<d.ways;++i){
            t[i] = new TreeMap<Integer, DataStruct.id4>();
            DataStruct.id4 z = DataStruct.id4.build(0,d.w[i].length-1);
            t[i].put(0, z);
        }
        
        
        int q = in.nextInt();
        for(int qi = 1;qi<=q;++qi){
            int type = in.nextInt();
            
            if(type==1){
                i = in.nextInt()-1;
                j = d.wi[i];
                t[j].put(qi, t[j].get(lx[j]).P_add(d.wj[i], 1));
                x[i] = qi;
                lx[j] = qi;
            }else{
                int a = in.nextInt()-1, b = in.nextInt()-1, k = in.nextInt(), y = in.nextInt();
                int l = lt.lca(a,b);
                int c[], count = 0, res = -1;

                DataStruct.id4 yl, yr;
                
                
                if(l==a){
                    if(a==b || lt.nthParent(b, 1)==a) res = -1; else{
                        

                        b = lt.nthParent(b,1);
                        a = lt.id5(a,b);
                        c = d.query(b,a);
                        int ny = -1; long st;
                        

                        for(i=c.length-3;i>=0;i-=3){
                            ny = t[c[i]].floorKey(y);
                            st = (c[i+2]-c[i+1]+1) - (t[c[i]].get(lx[c[i]]).getSum(c[i+1],c[i+2]) - t[c[i]].get(ny).getSum(c[i+1],c[i+2]));
                            

                            if(st<k) k-=st; else break;
                        }
                        

                        if(i<0) res = -1; else{
                            yl = t[c[i]].get(ny);
                            yr = t[c[i]].get(lx[c[i]]);
                            long nz = c[i+1] - (yr.getSum(0,c[i+1]-1)-yl.getSum(0,c[i+1]-1));
                            

                            nz += (c[i+2]-c[i+1]+1)-yr.getSum(c[i+1],c[i+2])+yl.getSum(c[i+1],c[i+2])-k+1;
                            res = index(yl, yr, (int) nz);
                            

                            res = d.w[c[i]][res] + 1;
                        }
                    }
                }else
                if(l==b){
                    if(a==b || lt.nthParent(a, 1)==b) res = -1; else{
                        

                        a = lt.nthParent(a,1);
                        b = lt.id5(b,a);
                        c = d.query(a,b);
                        int ny = -1; long st;
                        

                        for(i=0;i<c.length;i+=3){
                            ny = t[c[i]].floorKey(y);
                            st = (c[i+2]-c[i+1]+1) - (t[c[i]].get(lx[c[i]]).getSum(c[i+1],c[i+2]) - t[c[i]].get(ny).getSum(c[i+1],c[i+2]));
                            

                            if(st<k) k-=st; else break;
                        }
                        

                        if(i>=c.length) res = -1; else{
                            yl = t[c[i]].get(ny);
                            yr = t[c[i]].get(lx[c[i]]);
                            long nz = c[i+1] - (yr.getSum(0,c[i+1]-1)-yl.getSum(0,c[i+1]-1));
                            

                            nz += k;
                            res = index(yl, yr, (int) nz);
                            

                            res = d.w[c[i]][res] + 1;
                        }
                    }
                }else{
                    boolean id6 = false;
                    a = lt.nthParent(a,1);
                    c = d.query(a,l);
                    int ny = -1; long st;
                    

                    for(i=0;i<c.length;i+=3){
                        ny = t[c[i]].floorKey(y);
                        st = (c[i+2]-c[i+1]+1) - (t[c[i]].get(lx[c[i]]).getSum(c[i+1],c[i+2]) - t[c[i]].get(ny).getSum(c[i+1],c[i+2]));
                        

                        if(st<k) k-=st; else break;
                    }
                    

                    if(i>=c.length) res = -1; else{
                        yl = t[c[i]].get(ny);
                        yr = t[c[i]].get(lx[c[i]]);
                        long nz = c[i+1] - (yr.getSum(0,c[i+1]-1)-yl.getSum(0,c[i+1]-1));
                        

                        nz += k;
                        res = index(yl, yr, (int) nz);
                        

                        res = d.w[c[i]][res] + 1;
                    }
                    if(res==-1 && lt.nthParent(b,1)!=l){
                        l = lt.id5(l,b);
                        b = lt.nthParent(b,1);
                        c = d.query(b,l);
                        ny = -1;
                        

                        for(i=c.length-3;i>=0;i-=3){
                            ny = t[c[i]].floorKey(y);
                            st = (c[i+2]-c[i+1]+1) - (t[c[i]].get(lx[c[i]]).getSum(c[i+1],c[i+2]) - t[c[i]].get(ny).getSum(c[i+1],c[i+2]));
                            

                            if(st<k) k-=st; else break;
                        }
                        

                        if(i<0) res = -1; else{
                            yl = t[c[i]].get(ny);
                            yr = t[c[i]].get(lx[c[i]]);
                            long nz = c[i+1] - (yr.getSum(0,c[i+1]-1)-yl.getSum(0,c[i+1]-1));
                            

                            nz += (c[i+2]-c[i+1]+1)-yr.getSum(c[i+1],c[i+2])+yl.getSum(c[i+1],c[i+2])-k+1;
                            res = index(yl, yr, (int) nz);
                            

                            res = d.w[c[i]][res] + 1;
                        }
                    }
                }
                
                out.writeln(res);
            }
        }
	}
    
    int index(DataStruct.id4 a, DataStruct.id4 b, int kz){
        int i = 0;
        while(a.size>1){
            int s = (int) (b.left.size - b.left.getSum() + a.left.getSum());
            if(s>=kz){
                a = a.left;
                b = b.left;
            }else{
                kz-=s;
                i+=a.left.size;
                a = a.right;
                b = b.right;
            }
        }
        return i;
    }
}

class InputReader{
    private InputStream in;
    private byte buffer[] = new byte[1<<11];
    private int cur;
    private int end;
    
    
    public InputReader(InputStream stream){
        in = stream;
    }
    
    public int read(){
        if(end<0) throw new InputMismatchException();
        if(cur>=end){
            cur = 0;
            try{
                end = in.read(buffer);
            }catch(IOException e){
                throw new InputMismatchException();
            }
            if(end<=0) return -1;
        }
        return buffer[cur++];
    }
    
    public boolean isSpace(int c){
        return c==' ' || c=='\n' || c=='\r' || c=='\t' || c==-1;
    }
    
    public int nextInt(){
        int c = read(), res = 0, sign = 1;
        while(isSpace(c)) c = read();
        if(c=='-'){ sign = -1; c = read(); }
        do{
            if(c>'9' || c<'0') throw new InputMismatchException();
            res = res*10 + (c-'0');
            c = read();
        }while(!isSpace(c));
        return res*sign;
    }

    }

class OutputWriter{
    private PrintWriter out;
    
    public OutputWriter(Writer out){
        this.out = new PrintWriter(out);
    }

    public OutputWriter(OutputStream out){
        this.out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(out)));
    }
    
    public void close(){
        out.close();
    }

    public void write(Object ... o){
        for(Object x : o) out.print(x);
    }
    
    public void writeln(Object ... o){
        write(o);
        out.println();
    }
}

class Graph{
    public int N;
    public ArrayList<Edge> edges[];
    
    public Graph(int n){
        N = n;
        edges = new ArrayList[n];
        for(int i=0;i<n;++i) edges[i] = new ArrayList<Edge>();
    }
    
    public void id0(Edge ... ex){
        for(Edge e : ex){
            edges[e.from].add(e);
            edges[e.to].add(e.inv());
        }
    }


    public static class id1{
        private int p[][];
        private int log;
        private Graph g;
        private int ti[], to[], tm;

        public id1(Graph tree){
            int n = tree.N;
            for(log=0; 1<<log<n; ++log);
            ++log;
            p = new int[log][n];
            this.g = tree;
            ti = new int[n];
            to = new int[n];
            tm = 0;
            for(int i=0;i<n;++i) if(ti[i]==0) dfs_p(i, -1);
        }

        private void dfs_p(int v, int par){
            ti[v] = ++tm;
            p[0][v] = par;
            for(int i=1;i<log;++i) p[i][v] = p[i-1][v]==-1 ? -1: p[i-1][p[i-1][v]];
            for(Edge e : g.edges[v]) if(ti[e.to]==0) dfs_p(e.to, v);
            to[v] = ++tm;
        }

        private boolean upper(int v, int u){
            return v==-1 || u!=-1 && ti[v]<ti[u] && to[v]>to[u];
        }

        public int lca(int v, int u){
            if(v==u || upper(v,u)) return v;
            if(upper(u,v)) return u;
            for(int i=log-1;i>=0;--i) if(!upper(p[i][v], u)) v = p[i][v];
            return p[0][v];
        }
        
        public int id5(int from, int id2){
            int i = log-1;
            while(i>=0){
                if(upper(from, p[i][id2])) id2 = p[i][id2];
                else --i;
            }
            return id2;
        }
        
        public int nthParent(int v, int n){
            if(n >= 1<<log) return -1;
            int t = 0;
            while(n <= 1<<t){
                if((1<<t&n)!=0) v = p[t][v];
                ++t;
            }
            return v;
        }
    }
    
    
    
    public static class id3{
        private Graph g;
        private int p[], s[];
        int w[][], ways, wi[], wj[];
        private int q[];
        
        public id3(Graph tree){
            int n = tree.N, i;
            this.g = tree;
            p = new int[n];
            Arrays.fill(p,-1);
            s = new int[n];
            for(i=0;i<n;++i) if(s[i]==0) dfs_ps(i, -1);
            wi = new int[n];
            wj = new int[n];
            ways = 0;
            for(i=0;i<n;++i) if(p[i]==-1) dfs_w(i, 0, -1);
            w = new int[ways][];
            ways = 0;
            for(i=0;i<n;++i){
                boolean h = false;
                for(Edge e : g.edges[i]) if(e.to!=p[i] && s[e.to]>0){ h=true; break; }
                if(!h){
                    w[ways] = new int[s[i]+1];
                    for(int j=i, k=0; k<w[ways].length; j=p[j], ++k){
                        w[ways][k] = j;
                        wi[j] = ways;
                        wj[j] = k;
                    }
                    ++ways;
                }
            }
            q = new int[50*3];
        }
        
        private void dfs_ps(int v, int par){
            p[v] = par;
            s[v] = 1;
            for(Edge e : g.edges[v]) if(e.to!=par){
                dfs_ps(e.to, v);
                s[v] += s[e.to];
            }
        }
        
        private void dfs_w(int v, int hc, int par){
            boolean h = false;
            for(Edge e : g.edges[v]) if(e.to!=par){
                if(s[e.to]*2>=s[v]){
                    h = true;
                    dfs_w(e.to, hc+1, v);
                }else dfs_w(e.to, 0, v);
            }
            s[v] = hc;
            if(!h) ++ways; 
        }
        
        public int[] query(int from, int to){
            int m = 0;
            for(;;){
                int fi = wi[from];
                int end = w[fi][w[fi].length-1];
                if(fi==wi[to]) end = to;
                q[m++] = fi;
                q[m++] = wj[from];
                q[m++] = wj[end];
                if(end==to) break;
                from = p[end];
            }
            return Arrays.copyOf(q, m);
        }
    }
    
}

class Edge{
    public int from, to;
    
    public Edge(int _form, int _to){
        from =  _form;
        to = _to;
    }

    public Edge(){}
    
    public Edge inv(){
        return new Edge(to, from);
    }

    }

class DataStruct {

    public static class id4{
        public id4 left, right;
        int size;

        private long sum;

        private void calc(){
            sum = (left==null ? 0 : left.sum + right.sum);
        }

        public static id4 build(int left, int right){
            if(left==right) return new id4(null, null);
            int middle = (left + right)>>1;
            return new id4(build(left,middle), build(middle+1,right));
        }

        private id4(id4 _left, id4 _right){
            left = _left;
            right = _right;
            sum = 0;
            size = (left==null? 1 : left.size+right.size);
            calc();
        }

        public long getSum(int i, int j){
            if(i>j || 0>i || j>=size) return 0;
            if(i==0 && j==size-1){
                return sum;
            }else{
                int m = left.size-1;
                long sl = 0, sr = 0;
                if(i<=m) sl = left.getSum(i, Math.min(m, j));
                if(j>m) sr = right.getSum(Math.max(0, i - m - 1), j-m-1);
                return sl+sr;
            }
        }
        
        public long getSum(){
            return sum;
        }
        
        public id4 P_add(int index, int value){
            if(index<0 || index>=size) throw new RuntimeException();
            if(size==1){
                id4 t = new id4(left, right);
                t.sum = sum + value;
                return t;
            }else{
                id4 t = new id4(left, right);
                int m = left.size-1;
                if(index<left.size) t.left = left.P_add(index, value);
                else t.right = right.P_add(index-left.size, value);
                t.calc();
                return t;
            }
        }
    }
    
    
    
    }

