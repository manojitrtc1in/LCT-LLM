
import java.io.*;
import java.util.*;
import java.math.*;

public class Main { 

    static HashSet<Integer>[] grp;
    static boolean[] vis;
    static HashSet<Integer>[] grp2;
    static boolean[] vis2;
    static HashSet<Integer> cont;

    public static void main(String[] args) throws java.lang.Exception { 
        

        Scanner pm = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        StringBuffer sb = new StringBuffer();
        int t = pm.nextInt();
        while(t-- > 0){
            int n = pm.nextInt();
            int m = pm.nextInt();
            grp = new HashSet[n*m +1];
            vis = new boolean[n*m +1];

            grp2 = new HashSet[n*m +1];
            vis2 = new boolean[n*m +1];
            int emp = '.';
            cont = new HashSet<>();
            for(int i=0;i<grp.length;i++)
                grp[i] = new HashSet<>();

            for(int i=0;i<grp.length;i++)
                grp2[i] = new HashSet<>();

            char[][] c = new char[n][m];
            int[][] d = new int[n][m];
            int g = 0;
            int b = 0;
            int cnt = 1;
            for(int i=0;i<n;i++){
                String s = pm.next();
                for(int j=0;j<m;j++){
                    c[i][j] = s.charAt(j);
                    d[i][j] = cnt++;
                    if(c[i][j] == 'G')
                        g++;
                    else if(c[i][j] == 'B')
                        b++;
                    
                }
            }
            if(g == 0){
                sb.append("Yes\n");
                continue;
            }
            

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(c[i][j] == 'B'){
                        if(i-1 >= 0 && c[i-1][j] != 'G' && c[i-1][j] != 'B')
                            c[i-1][j] = '#';
                        if(i+1 <= n-1 && c[i+1][j] != 'G' && c[i+1][j] != 'B')
                            c[i+1][j] = '#';
                        if(j-1 >= 0 && c[i][j-1] != 'G' && c[i][j-1] != 'B')
                            c[i][j-1] = '#';
                        if(j+1 <= m-1 && c[i][j+1] != 'G' && c[i][j+1] != 'B')
                            c[i][j+1] = '#';
                    }
                }
            }
            HashSet<Integer> good = new HashSet<>();
            HashSet<Integer> bad = new HashSet<>();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(c[i][j] == 'G'){
                        good.add(d[i][j]);
                    }else if(c[i][j] == 'B')
                        bad.add(d[i][j]);
                }
            }
            

            

            

            

            

            

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(c[i][j] == 'G'){
                        if(i-1 >= 0 && (c[i-1][j] == '.' || c[i-1][j] == 'G')){
                            grp[d[i][j]].add(d[i-1][j]);
                            grp[d[i-1][j]].add(d[i][j]);
                        }
                        if(i+1 <= n-1 && (c[i+1][j] == '.' || c[i+1][j] == 'G')){
                            grp[d[i][j]].add(d[i+1][j]);
                            grp[d[i+1][j]].add(d[i][j]);
                        }

                        if(j-1 >= 0 && (c[i][j-1] == '.' || c[i][j-1] == 'G')){
                            grp[d[i][j]].add(d[i][j-1]);
                            grp[d[i][j-1]].add(d[i][j-1]);
                        }
                        if(j+1 <= m-1 && (c[i][j+1] == '.' || c[i][j+1] == 'G')){
                            grp[d[i][j]].add(d[i][j+1]);
                            grp[d[i][j+1]].add(d[i][j]);
                        }
                           
                    } else if(c[i][j] == '.'){
                        if(i-1 >= 0 && (c[i-1][j] == '.' || c[i-1][j] == 'G' || c[i-1][j] == 'B')){
                            grp[d[i][j]].add(d[i-1][j]);
                            grp[d[i-1][j]].add(d[i][j]);
                        }
                        if(i+1 <= n-1 && (c[i+1][j] == '.' || c[i+1][j] == 'G' || c[i+1][j] == 'B')){
                            grp[d[i][j]].add(d[i+1][j]);
                            grp[d[i+1][j]].add(d[i][j]);
                        }

                        if(j-1 >= 0 && (c[i][j-1] == '.' || c[i][j-1] == 'G' || c[i][j-1] == 'B')){
                            grp[d[i][j]].add(d[i][j-1]);
                            grp[d[i][j-1]].add(d[i][j-1]);
                        }
                        if(j+1 <= m-1 && (c[i][j+1] == '.' || c[i][j+1] == 'G' || c[i][j+1] == 'B')){
                            grp[d[i][j]].add(d[i][j+1]);
                            grp[d[i][j+1]].add(d[i][j]);
                        }
                    } 
                }
            }

            

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(c[i][j] == 'B'){
                        if(i-1 >= 0 && (c[i-1][j] == '.' || c[i-1][j] == 'G' || c[i-1][j] == 'B')){
                            grp2[d[i][j]].add(d[i-1][j]);
                            grp2[d[i-1][j]].add(d[i][j]);
                        }
                        if(i+1 <= n-1 && (c[i+1][j] == '.' || c[i+1][j] == 'G'|| c[i+1][j] == 'B')){
                            grp2[d[i][j]].add(d[i+1][j]);
                            grp2[d[i+1][j]].add(d[i][j]);
                        }

                        if(j-1 >= 0 && (c[i][j-1] == '.' || c[i][j-1] == 'G'|| c[i][j-1] == 'B')){
                            grp2[d[i][j]].add(d[i][j-1]);
                            grp2[d[i][j-1]].add(d[i][j-1]);
                        }
                        if(j+1 <= m-1 && (c[i][j+1] == '.' || c[i][j+1] == 'G' || c[i][j+1] == 'B')){
                            grp2[d[i][j]].add(d[i][j+1]);
                            grp2[d[i][j+1]].add(d[i][j]);
                        }
                           
                    } 
                    else if(c[i][j] == '.'){
                        if(i-1 >= 0 && (c[i-1][j] == '.' || c[i-1][j] == 'G' || c[i-1][j] == 'B')){
                            grp2[d[i][j]].add(d[i-1][j]);
                            grp2[d[i-1][j]].add(d[i][j]);
                        }
                        if(i+1 <= n-1 && (c[i+1][j] == '.' || c[i+1][j] == 'G' || c[i+1][j] == 'B')){
                            grp2[d[i][j]].add(d[i+1][j]);
                            grp2[d[i+1][j]].add(d[i][j]);
                        }

                        if(j-1 >= 0 && (c[i][j-1] == '.' || c[i][j-1] == 'G' || c[i][j-1] == 'B')){
                            grp2[d[i][j]].add(d[i][j-1]);
                            grp2[d[i][j-1]].add(d[i][j-1]);
                        }
                        if(j+1 <= m-1 && (c[i][j+1] == '.' || c[i][j+1] == 'G' || c[i][j+1] == 'B')){
                            grp2[d[i][j]].add(d[i][j+1]);
                            grp2[d[i][j+1]].add(d[i][j]);
                        }
                    } 
                    else if(c[i][j] == 'G') {
                        if(i-1 >= 0 && (c[i-1][j] == '.' || c[i-1][j] == 'G' || c[i-1][j] == 'B')){
                            grp2[d[i][j]].add(d[i-1][j]);
                            grp2[d[i-1][j]].add(d[i][j]);
                        }
                        if(i+1 <= n-1 && (c[i+1][j] == '.' || c[i+1][j] == 'G' || c[i+1][j] == 'B')){
                            grp2[d[i][j]].add(d[i+1][j]);
                            grp2[d[i+1][j]].add(d[i][j]);
                        }

                        if(j-1 >= 0 && (c[i][j-1] == '.' || c[i][j-1] == 'G' || c[i][j-1] == 'B')){
                            grp2[d[i][j]].add(d[i][j-1]);
                            grp2[d[i][j-1]].add(d[i][j-1]);
                        }
                        if(j+1 <= m-1 && (c[i][j+1] == '.' || c[i][j+1] == 'G' || c[i][j+1] == 'B')){
                            grp2[d[i][j]].add(d[i][j+1]);
                            grp2[d[i][j+1]].add(d[i][j]);
                        }
                    } 
                }
            }
            bfs(n*m, n, m);

            

            

            

            

            int fl = 0;
            for(Integer i: good){
                if(!cont.contains(i)){
                    fl = 1;
                    break;
                }
            }
            if(fl == 0){
                cont = new HashSet<>();
                bfs2(n*m, n,m);
                for(Integer i: bad){
                    if(cont.contains(i)){
                        fl = 1;
                        break;
                    }
                }
            }
            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            

            if(fl == 1)
                sb.append("No\n");
            else 
                sb.append("Yes\n");

        }
        System.out.println(sb);
        

        
    }
    


    static void bfs(int v, int n,int m){
        Queue<Integer> q = new LinkedList<>();
        vis = new boolean[n*m+1];
        q.add(v);
        vis[v] = true;
        while(q.size() != 0){
            int top = q.poll();
            cont.add(top);
            for(int i:grp[top]){
                if(!vis[i]){
                    vis[i] = true;
                    q.add(i);
                }
            }
        }
    }

    static void bfs2(int v, int n,int m){
        Queue<Integer> q = new LinkedList<>();
        vis = new boolean[n*m+1];
        q.add(v);
        vis[v] = true;
        while(q.size() != 0){
            int top = q.poll();
            cont.add(top);
            for(int i:grp2[top]){
                if(!vis[i]){
                    vis[i] = true;
                    q.add(i);
                }
            }
        }
    }

    static void dfs(int v){
        vis[v] = true;
        cont.add(v);
        for(Integer i:grp[v]){
            if(!vis[i])
                dfs(i);
        }
    }

    static void dfs2(int v){
        vis2[v] = true;
        cont.add(v);
        for(Integer i:grp2[v]){
            if(!vis2[i])
                dfs2(i);
        }
    }

    static int countInRange(int arr[], int n, int x, int y) { 
        

        int count = 0; 
        count = upperIndex(arr, n, y) -  
                lowerIndex(arr, n, x) + 1; 
        return count; 
    } 
    
    
    static int lowerIndex(int arr[], int n, int x) { 
        int l = 0, h = n - 1; 
        while (l <= h)  
        { 
            int mid = (l + h) / 2; 
            if (arr[mid] >= x) 
                h = mid - 1; 
            else
                l = mid + 1; 
        } 
        return l; 
    } 
      
    

    static int upperIndex(int arr[], int n, int y) { 
        int l = 0, h = n - 1; 
        while (l <= h)  
        { 
            int mid = (l + h) / 2; 
            if (arr[mid] <= y) 
                l = mid + 1; 
            else
                h = mid - 1; 
        } 
        return h; 
    }
    
    public static StringBuilder dec_to_bin(long n) {
        

        if(n==0) {
            StringBuilder str=new StringBuilder("");
            for(int i=0;i<30;i++) {
                str.append("0");
            }
            return str;
        }
        StringBuilder str=new StringBuilder("");
        while(n!=0) {
            str.append(n%2L);
            n/=2L;
        }
        str=str.reverse();
        StringBuilder tmp_str=new StringBuilder("");
        int len=str.length();
        while(len!=30) {
            tmp_str.append("0");
            len++;
        }
        tmp_str.append(str);
        return tmp_str;
    }
    
    private static int binarySearchPM(int[] arr, int key){
        int n = arr.length;
        int mid = -1;
        int begin = 0,end=n;
        while(begin <= end){
            mid = (begin+end) / 2;
            if(mid == n){
                return n;
            }
            if(key < arr[mid]){
                end = mid-1;
            } else if(key > arr[mid]){
                begin = mid+1;
            } else {
                return mid;
            }
        }
        

        return -begin; 

    }
    
    static class Reader { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    }
}    