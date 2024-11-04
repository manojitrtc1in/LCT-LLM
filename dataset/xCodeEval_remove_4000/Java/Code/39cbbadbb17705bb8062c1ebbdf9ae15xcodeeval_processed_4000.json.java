
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;

public class E99 {


    static int n,x,root=0,bcnt=0,rcnt=0;
    static boolean[] id15;

    static int[] id9,id7;
    static int[][] t,w;
    
    
    static void visit(int v) {
        if(v!=root&&id7[v]==1) {
            id7[v]--;
            for (int i=0; i<t[v].length; i++) {
                int pv=t[v][i];
                if(id7[pv]>0) {
                    id9[v]=pv;
                    id7[pv]--;
                    visit(pv);
                    break;
                }
            }
        }
    }
    
    static void id4(int[] e1, int[] e2) {
        int n=e1.length+1;
        id7=new int[n];
        for (int i=0; i<n-1; i++) {
            id7[e1[i]]++;
            id7[e2[i]]++;
        }
        
        t=new int[n][];
        for (int i=0; i<n; i++) {
            t[i]=new int[id7[i]];
        }
        for (int i=0; i<n-1; i++) {
            int v1=e1[i], v2=e2[i];
            t[v1][--id7[v1]]=v2;
            t[v2][--id7[v2]]=v1;
        }
        for (int i=0; i<n-1; i++) {
            id7[e1[i]]++;
            id7[e2[i]]++;
        }
        
        id9=new int[n]; 

        Arrays.fill(id9, -1);

        for (int i=1; i<n; i++) {
            if(id7[i]==1) {
                visit(i);
            }
        }
    }

    
    static class e {
        int minb,maxr,bcnt,rcnt, h;
        
        e(int minb, int maxr, int bcnt, int rcnt) {
            this.minb=minb;
            this.maxr=maxr;
            this.bcnt=bcnt;
            this.rcnt=rcnt;
            
            rehash();
        }
        
        void rehash() {
            h=minb;
            h=31*h+maxr;
            h=31*h+bcnt;
            h=31*h+rcnt;
        }
        
        public int hashCode() {
            return h;
        }
        
        public boolean equals(Object o) {
            e ee=(e)o;
            return minb==ee.minb&&maxr==ee.maxr&&bcnt==ee.bcnt&&rcnt==ee.rcnt;
        }
        
        public String toString() {
            return "["+minb+"/"+maxr+","+bcnt+"+"+rcnt+"]";
        }
    }
    
    static int epcnt=0;
    static e[] epool=new e[Short.MAX_VALUE];
    static e elease(long minb, int maxr, int bcnt, int rcnt) {
        if(minb>x) {
            minb=x+1;
        }
        if(epcnt==0) {
            epool[epcnt++]=new e((int)minb,maxr,bcnt,rcnt);
        }
        e k=epool[--epcnt];
        k.minb=(int)minb;
        k.maxr=maxr;
        k.bcnt=bcnt;
        k.rcnt=rcnt;
        k.rehash();
        return k;
    }
    
    static void release(e k) {
        if(epcnt==epool.length) {
            e[] tmp=new e[epool.length<<1];
            System.arraycopy(epool, 0, tmp, 0, epool.length);
            epool=tmp;
        }
        epool[epcnt++]=k;
    }

    static int mpcnt=0;
    static map<e, Integer>[] mpool=new map[Short.MAX_VALUE];
    static map<e, Integer> mlease() {
        if(mpcnt==0) {
            mpool[mpcnt++]=new map<e, Integer>();
        }
        map<e, Integer> ret=mpool[--mpcnt];
        return ret;
    }
    
    static void release(map<e, Integer> m) {
        if(mpcnt==mpool.length) {
            map<e, Integer>[] tmp=new map[mpool.length<<1];
            System.arraycopy(mpool, 0, tmp, 0, mpool.length);
            mpool=tmp;
        }
        

        mpool[mpcnt++]=m;
    }

    static void clear(map<e, Integer> m) {
        for (int i=0; i<m.size; i++) {
            e k=(e)m.id22[i];
            release(k);
        }
        m.clear();
    }
    
    static void compute(map<e, Integer> f, int v, boolean reduce) {
        if(t[v].length==1&&t[v][0]==id9[v]) {

            if(bcnt>0) {
                f.put(elease(0,-1,1,0), id15[v]? 0: 1);

            }
            if(rcnt>0) {
                f.put(elease(x+1,0,0,1), id15[v]? 1: 0);

            }
            return;
        }
        
        map<e, Integer> f1=mlease(), f2=mlease();
        
        if(bcnt>0) {
            f1.put(elease(0,-1,1,0), id15[v]? 0: 1);

        }
        if(rcnt>0) {
            f1.put(elease(x+1,0,0,1), id15[v]? 1: 0);

        }
        for (int i=0; i<t[v].length; i++) {
            int cv=t[v][i];
            if(cv!=id9[v]) {
                map<e, Integer> cf=mlease();
                compute(cf, cv, reduce);
                for (int j1=0; j1<f1.size; j1++) {
                    e k1=(e)f1.id22[j1];
                    long id0=k1.minb, id1=k1.maxr;
                    int id18=k1.bcnt, id8=k1.rcnt;
                    
                    for (int j2=0; j2<cf.size; j2++) {
                        e k2=(e)cf.id22[j2];
                        long id19=k2.minb, id2=k2.maxr;
                        int id13=k2.bcnt, id20=k2.rcnt;

                        if(id18+id13<=bcnt&&id8+id20<=rcnt) {
                            int min=f1.get(k1)+cf.get(k2);
                            if(id0==0) {
                                if(id2<0||id2+(long)w[v][cv]<=x) {
                                    e k=elease(0,-1,id18+id13,id8+id20);
                                    if(!f2.contains(k)||f2.get(k)>min) {
                                        f2.put(k, min);
                                    } else {
                                        release(k);
                                    }
                                }
                            } else {
                                long id5=(id1<0||id1+id19+(long)w[v][cv]<=x)? -1: id1;
                                long id6=(id2<0||id2+id0+(long)w[v][cv]<=x)? -1: id2+(long)w[v][cv];
                                long maxr=Math.max(id5, id6);
                                if(maxr<x) {
                                    e k=elease(
                                            Math.min(id0, id19+(long)w[v][cv]), 
                                            (int)maxr, 
                                            id18+id13,id8+id20);
                                    if(!f2.contains(k)||f2.get(k)>min) {
                                        f2.put(k, min);
                                    } else {
                                        release(k);
                                    }
                                }
                            }
                        }
                    }
                }
                clear(cf);
                release(cf);
                map<e, Integer> tmp=f1; f1=f2; f2=tmp; clear(f2);
            }
        }
        
        if(reduce) {
        for (int i=0; i<f1.size; i++) {
            int v1=(Integer)f1.id23[i];
            e k1=(e)f1.id22[i];
            boolean skip=false;

            for (int j=0; j<f1.size; j++) {
                if (i!=j) {
                    int v2=(Integer)f1.id23[j];
                    e k2=(e)f1.id22[j];
                    if (v1>=v2&&k1.bcnt>=k2.bcnt&&k1.maxr>=k2.maxr&&k1.minb>=k2.minb) {
                        if(i>j) {
                            skip=true;
                            break;
                        }
                    }
                }
            }
            if (!skip) {
                f.put(k1, v1);
            } else {
                release(k1);
            }
        }
        } else {
            f.putAll(f1);
        }
        
        f1.clear();
        release(f1);
        
        clear(f2);
        release(f2);
    }
    
    static int compute(int[] e1, int[] e2, boolean reduce) {
        root=0;
        id4(e1, e2);
        bcnt=0; rcnt=0;
        for (int i=0; i<n; i++) {
            if(id15[i]) {
                bcnt++;
            } else {
                rcnt++;
            }
        }
        
        map<e, Integer> f=mlease();
        compute(f, root, reduce);
        int ret=Integer.MAX_VALUE;
        for (int i=0; i<f.size; i++) {
            e k=(e)f.id22[i];
            if(k.maxr<0&&f.get(k)<ret) {
                ret=f.get(k);
            }
        }
        
        return ret<Integer.MAX_VALUE? ret>>1: -1;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    static StringBuilder sb=new StringBuilder();
    static void parse(String l, boolean[] here) {
        sb.setLength(0);
        int len=l.length(), j=0;
        for (int i=0; i<len; i++) {
            char c=l.charAt(i);
            if(c==' ') {
                here[j++]=sb.toString().equals("1");
                sb.setLength(0);
            } else {
                sb.append(c);
            }
        }
        if(sb.length()>0) {
            here[j++]=sb.toString().equals("1");
        }
    }
    
    static void run_stream(InputStream ins) throws IOException {
        BufferedReader r=new BufferedReader(new InputStreamReader(System.in));
        String[] s=r.readLine().split(" ");
        n=Integer.parseInt(s[0]);
        x=Integer.parseInt(s[1]);
        
        id15=new boolean[n];
        parse(r.readLine(), id15);
        
        int[] e1=new int[n-1], e2=new int[n-1];
        w=new int[n][n];
        for (int i=0; i<n-1; i++) {
            String l=r.readLine();
            int space=l.indexOf(' ');
            e1[i]=Integer.parseInt(l.substring(0, space))-1;
            
            l=l.substring(space+1, l.length());
            
            space=l.indexOf(' ');
            e2[i]=Integer.parseInt(l.substring(0, space))-1;
            
            w[e1[i]][e2[i]]=Integer.parseInt(l.substring(space+1, l.length()));
            w[e2[i]][e1[i]]=w[e1[i]][e2[i]];
        }
        
        System.out.print(compute(e1,e2,true));
    }

    public static void main(String[] args) throws IOException {
        run_stream(System.in);
        

    }
    

    
    
    
    
    
    
    static Random r=new Random();
    static int[][] random_tree(int n) {
        int[][] ret=new int[n][];
        for (int i=0, j=1; i<n; i++) {
            int cnt=Math.min(n-j+1, 10);
            int k=r.nextInt(cnt);
            if(k==0&&i==0) {
                k++;
            }
            ret[i]=new int[k];
            for (int l=0; l<k; l++) {
                ret[i][l]=j++;
            }
        }
        
        return ret;
    }
    
    static void id16(int[][] t, int[] e1, int[] e2) {
        int k=0;
        for (int i=0; i<t.length; i++) {
            for (int j=0; j<t[i].length; j++) {
                if(r.nextBoolean()) {
                    e1[k]=i; e2[k]=t[i][j];
                } else {
                    e2[k]=i; e1[k]=t[i][j];
                }
                k++;
            }
        }
    }
    
    static void run_random(int nn, int xx) {
        int[][] t=random_tree(nn);
        int[] e1=new int[t.length-1], e2=new int[t.length-1];
        id16(t, e1, e2);
        
        n=t.length;
        x=xx;
        id15=new boolean[n];
        for (int i=0; i<n; i++) {
            id15[i]=r.nextBoolean();
        }
        w=new int[n][n];
        for (int i=0; i<e1.length; i++) {
            w[e1[i]][e2[i]]=w[e2[i]][e1[i]]=r.nextInt(50)+1;
        }

        long t0=System.currentTimeMillis();
        System.out.println(compute(e1, e2, true));
        System.out.println(System.currentTimeMillis()-t0);

        t0=System.currentTimeMillis();
        System.out.println(compute(e1, e2, false));
        System.out.println(System.currentTimeMillis()-t0);
    }

    
    
    
    
    
    
    
    
    
    static class map<K,V> {
        public int size=0;
        float load_factor;
        
        public int[] 
                id11,
                id21;
        
        public Object[] id22,id23;
        
        public map() {
            this(8, 0.75f);
        }
        
        public map(int capacity, float load_factor) {
            this.load_factor=load_factor;
            id11=new int[capacity];
            Arrays.fill(id11, -1);
            
            int data_size=(int)(capacity*load_factor)+1;
            id22=new Object[data_size];
            id23=new Object[data_size];
            id21=new int[data_size];
        }
        
        private int id3(int i) {
            i^=(i>>>20)^(i>>>12);
            return i^(i>>>7)^(i>>>4);
        }
        
        public boolean contains(K k) {
            int idx=id11[id12(k)];
            while(idx>=0) {
                if(id22[idx].equals(k)) {
                    return true;
                } else {
                    idx=id21[idx];
                }
            }
            return false;
        }
        
        public V get(K k) {
            int idx=id11[id12(k)];
            while(idx>=0) {
                if(id22[idx].equals(k)) {
                    return (V)id23[idx];
                } else {
                    idx=id21[idx];
                }
            }
            throw new IndexOutOfBoundsException();
        }
        
        public V put(K k, V v) {
            if(size>(int)(id11.length*load_factor)) {
                rehash(id11.length<<1);
            }
            
            int bucket_idx=id12(k);
            int idx=id11[bucket_idx];
            if(idx>=0) {
                while(true) {
                    if(id22[idx].equals(k)) {
                        V oldv=(V)id23[idx];
                        id23[idx]=v;
                        return oldv;
                    } else if(id21[idx]<0) {
                        int idx2=size++;
                        id22[idx2]=k;
                        id23[idx2]=v;
                        id21[idx]=idx2;
                        id21[idx2]=-1;
                        return v;
                    } else {
                        idx=id21[idx];
                    }
                }
            } else {
                idx=size++;
                id11[bucket_idx]=idx;
                id22[idx]=k;
                id23[idx]=v;
                id21[idx]=-1;
                return v;
            }
        }

        protected int id12(K k) {
            int bucket_idx=id3(k.hashCode())%id11.length;
            if(bucket_idx<0) {
                bucket_idx=id11.length+bucket_idx;
            }
            return bucket_idx;
        }

        void rehash(int new_capacity) {
            int[] id24=new int[new_capacity];
            Arrays.fill(id24, -1);
            
            int data_size=(int)(new_capacity*load_factor)+1;
            Object[] id17=new Object[data_size];
            Object[] id10=new Object[data_size];
            int[] id14=new int[data_size];
            
            int old_size=size;
            size=0;
            

            int[] aux=id24; id24=id11; id11=aux;
            aux=id14; id14=id21; id21=aux;

            Object[] oaux=id17; id17=id22; id22=oaux;
            oaux=id10; id10=id23; id23=oaux;
            

            for(int i=0; i<old_size; i++) {
                put((K)id17[i], (V)id10[i]);
            }
        }
        
        public void clear() {
            if(size>0) {
                size=0;
                Arrays.fill(id11, -1);
            }
        }
        
        public void putAll(map<K,V> m) {
            int new_size=size+m.size;
            if(new_size>(int)(id11.length*load_factor)) {
                rehash((int)(1+new_size/load_factor));
            }
            for(int idx=0; idx<m.size; idx++) {
                put((K)m.id22[idx], (V)m.id23[idx]);
            }
        }
        
        public String toString() {
            if(size==0)
                return "{}";

            StringBuilder sb=new StringBuilder();
            sb.append('{');
            for(int i=0; i<size; i++) {
                sb.append(id22[i]);
                sb.append('=');
                sb.append(id23[i]);
                if(i<size-1) {
                    sb.append(", ");
                }
            }
            return sb.append('}').toString();
        }
    }
}
