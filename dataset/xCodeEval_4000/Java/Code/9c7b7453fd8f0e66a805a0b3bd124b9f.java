import java.io.*;
import java.util.*;

public class Solution{
    InputStream is;
    static PrintWriter out;
    String INPUT = "";
    static long mod = (long)1e9+7L;
    
    static class node{
        int first, last;
        boolean inc, dec, incDec;
        public node(){
            first = -1;
            last = -1;
            inc = false;
            dec = false;
            incDec = false;
        }
        public node(int f, int l, boolean i, boolean d, boolean id){
            first = f;
            last = l;
            inc = i;
            dec = d;
            incDec = id;
        }
        public String toString(){
            return "("+first+","+last+","+inc+","+dec+","+incDec+")";
        }
    }

    int n, q;
    node[] tree;
    int[] a;
    public void solve(){
        n = ni(); q = ni();
        a = na(n);
        tree = new node[4*n];
        build(1, 0, n-1);
        for(int i = 0; i<4*n; i++){
            

        }
        while(q-->0){
            node ans = query(1, 0, n-1, ni()-1, ni()-1);
            

            out.println((ans.inc || ans.dec || ans.incDec) ? "Yes" : "No");
        }
    }
    node query(int id, int start, int end, int l, int r){
        if(r < start || l > end){
            return null;
        }
        if(l <= start && r >= end){
            return tree[id];
        }

        int mid = (start + end) / 2;
        node n1 = query(2*id, start, mid, l, r);
        node n2 = query(2*id+1, mid+1, end, l, r);
        if(n1 == null){
            return n2;
        } 
        if(n2 == null){
            return n1;
        }
        return merge(n1, n2);
    }
    void build(int id, int start, int end){
        if(start == end){
            tree[id] = new node(a[start], a[start], true, true, false);
            

        }
        else{
            int mid = (start + end)/2;
            build(2 * id, start, mid);
            build(2 * id + 1, mid + 1, end);
            merge(id, 2 * id, 2 * id +1);
            

        }
    }
    void merge(int id, int lChild, int rChild){
        tree[id] = new node();
        

        if((!tree[lChild].inc && !tree[lChild].dec && !tree[lChild].incDec) || (!tree[rChild].inc && !tree[rChild].dec && !tree[rChild].incDec)){
            tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
            return;
        }

        

        if(tree[lChild].inc && tree[lChild].dec){
            

            if(tree[rChild].inc && tree[rChild].dec){
                if(tree[lChild].first == tree[rChild].last){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, true, true, false);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, true, false);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, true, false, false);
                }
            }
            

            else if(tree[rChild].inc){
                if(tree[lChild].last <= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, true, false, false);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }
            }
            

            else if(tree[rChild].dec){
                if(tree[lChild].last >= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, true, false);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }
            }
            

            else if(tree[rChild].incDec){
                if(tree[lChild].last <= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            return;
        }

        

        if(tree[lChild].inc){
            

            if(tree[rChild].inc && tree[rChild].dec){
                if(tree[lChild].last <= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, true, false, false);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }   
            }
            

            else if(tree[rChild].inc){
                if(tree[lChild].last <= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, true, false, false);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            

            else if(tree[rChild].dec){
                tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
            }
            

            else if(tree[rChild].incDec){
                if(tree[lChild].last <= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }
                else if(tree[lChild].last > tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            return;
        }

        

        if(tree[lChild].dec){
            

            if(tree[rChild].inc && tree[rChild].dec){
                if(tree[lChild].last >= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, true, false);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            

            else if(tree[rChild].inc){
                tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);   
            }
            

            else if(tree[rChild].dec){
                if(tree[lChild].last >= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, true, false);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            

            else if(tree[rChild].incDec){
                tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
            }
            return;
        }

        

        if(tree[lChild].incDec){
            

            if(tree[rChild].inc && tree[rChild].dec){
                if(tree[lChild].last >= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            

            else if(tree[rChild].inc){
                tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);   
            }
            

            else if(tree[rChild].dec){
                if(tree[lChild].last >= tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, true);
                }
                else if(tree[lChild].last < tree[rChild].first){
                    tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
                }   
            }
            

            else if(tree[rChild].incDec){
                tree[id] = new node(tree[lChild].first, tree[rChild].last, false, false, false);
            }
            return; 
        }

        

        return;   

    }

    node merge(node lChild, node rChild){
        node id = new node();

        

        if((!lChild.inc && !lChild.dec && !lChild.incDec) || (!rChild.inc && !rChild.dec && !rChild.incDec)){
            id = new node(lChild.first, rChild.last, false, false, false);
            return id;
        }

        

        if(lChild.inc && lChild.dec){
            

            if(rChild.inc && rChild.dec){
                if(lChild.first == rChild.last){
                    id = new node(lChild.first, rChild.last, true, true, false);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, true, false);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, true, false, false);
                }
            }
            

            else if(rChild.inc){
                if(lChild.last <= rChild.first){
                    id = new node(lChild.first, rChild.last, true, false, false);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }
            }
            

            else if(rChild.dec){
                if(lChild.last >= rChild.first){
                    id = new node(lChild.first, rChild.last, false, true, false);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }
            }
             

            else if(rChild.incDec){
                if(lChild.last <= rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            return id;
        }

        

        if(lChild.inc){
            

            if(rChild.inc && rChild.dec){
                if(lChild.last <= rChild.first){
                    id = new node(lChild.first, rChild.last, true, false, false);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }   
            }
            

            else if(rChild.inc){
                if(lChild.last <= rChild.first){
                    id = new node(lChild.first, rChild.last, true, false, false);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            

            else if(rChild.dec){
                id = new node(lChild.first, rChild.last, false, false, true);
            }
            

            else if(rChild.incDec){
                if(lChild.last <= rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }
                else if(lChild.last > rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            return id;
        }

        

        if(lChild.dec){
            

            if(rChild.inc && rChild.dec){
                if(lChild.last >= rChild.first){
                    id = new node(lChild.first, rChild.last, false, true, false);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            

            else if(rChild.inc){
                id = new node(lChild.first, rChild.last, false, false, false);   
            }
            

            else if(rChild.dec){
                if(lChild.last >= rChild.first){
                    id = new node(lChild.first, rChild.last, false, true, false);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            

            else if(rChild.incDec){
                id = new node(lChild.first, rChild.last, false, false, false);
            }
            return id;
        }

        

        if(lChild.incDec){
            

            if(rChild.inc && rChild.dec){
                if(lChild.last >= rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            

            else if(rChild.inc){
                id = new node(lChild.first, rChild.last, false, false, false);   
            }
            

            else if(rChild.dec){
                if(lChild.last >= rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, true);
                }
                else if(lChild.last < rChild.first){
                    id = new node(lChild.first, rChild.last, false, false, false);
                }   
            }
            

            else if(rChild.incDec){
                id = new node(lChild.first, rChild.last, false, false, false);
            }
            return id; 
        }

        

        return id;   

    }
    void run(){
        is = new DataInputStream(System.in);
        out = new PrintWriter(System.out);
        int t=1;while(t-->0)solve();
        out.flush();
    }
    public static void main(String[] args)throws Exception{new Solution().run();}
    long mod(long v, long m){if(v<0){long q=(Math.abs(v)+m-1L)/m;v=v+q*m;}return v%m;}
    long mod(long v){if(v<0){long q=(Math.abs(v)+mod-1L)/mod;v=v+q*mod;}return v%mod;}
    

    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;
    private int readByte(){
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    private String ns(){
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))){ 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    private char[] ns(int n){
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    private char[][] nm(int n, int m){
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    private int[] na(int n){
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    private int ni(){
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    private long nl(){
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    static  int i(long x){return (int)Math.round(x);}
    static class Pair implements Comparable<Pair>{
        long fs,sc;
        Pair(long a,long b){
            fs=a;sc=b;
        }
        public int compareTo(Pair p){
            if(this.fs>p.fs)return 1;
            else if(this.fs<p.fs)return -1;
            else{
                return i(this.sc-p.sc);
            }
            

        }
        public String toString(){
            return "("+fs+","+sc+")";
        }    
    }
    
}