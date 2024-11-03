

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;

public class Main {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;

        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }





    




















































































































































































































































































































    static boolean ff = false;

    
























































































































































































    












































    












































































































































































































    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }







































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































static class point{
        int val;
        String name;

}
static class comp implements Comparator<point>{
        public int compare(point a,point b){
            return a.val-b.val;
        }
}






















































































































































static class compp implements Comparator<int[]>{
    public int compare(int[] a,int[] b){
        return a[2]-b[2];
    }
}

static int maxx(int j){
    if(j>1){
        j=maxx(j/10)+maxx(j%10);

    }else{
        j=0;
    }
    return j;
}
















































































static HashSet<String> hashSet;
    static HashSet<String> hashset;
    static int maxx(String str,String st,int n,int ind,int k){
        if(ind>=str.length()){
            int i=0,j=st.length()-1;
            int flag=0;
            while(i<j){
                if(st.charAt(i)!=st.charAt(j)){
                    flag=1;break;
                }
                i++;j--;
            }
            if(flag==0 && str.compareTo(st)>0 ){
                hashSet.add(st);
            }
            return 0;
        }
        if(hashset.contains(st)){
            return 0;
        }
        for(int j=0;j<k;j++){
            char ch=(char)('a'+j);
            maxx(str,st+String.valueOf(ch),n,ind+1,k);
        }
        hashset.add(st);
        return 0;
    }
    static class TreeNode{
        char ch;
        TreeNode left,right;
        TreeNode(char ch){
            this.ch=ch;
        }
    }
    static void Java(){
        try{
            System.out.println("Inside Java");
            throw new RuntimeException("demo");
        }
        finally {
            System.out.println("Java's finally");
        }
    }
    static void Python(){
        try{
            System.out.println("Inside Python");
            return;
        }
        finally {
            System.out.println("Python's finally");
        }
    }





    static void postorder(TreeNode root){
        if(root==null){
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.println(root.ch);
    }
    static boolean fff=false;
    static void maxx(String st,int tot,long n){
        if(tot<=1){
            return;
        }
        if(n%Long.parseLong(st)==0){
            fff=true;
            return;
        }


        if(n<0){
            return;
        }
        maxx(st.substring(0,st.length()-1),tot-1,n);
        if(fff){
            return;
        }
        long tt=Long.parseLong(st);
        while(true){
            n=n-tt;
            maxx(st.substring(0,st.length()-1),tot-1,n);
            if(fff){
                return;
            }
            if(n<0){
                return;
            }
        }

    }

    public static void main(String[] args) throws IOException {
         Reader s=new Reader();
         

        

             int n=s.nextInt();
             PriorityQueue<Long> priorityQueue=new PriorityQueue<>();
             long tot=0;
             int tt=0;
             for(int i=0;i<n;i++){
                 long el=s.nextLong();
                 if(el>=0){
                     tot=(long)((long)tot+(long)el);
                     tt++;
                 }else{
                     if(tot >= Math.abs(el)){
                         tot=(long)((long)tot+(long)el);
                         priorityQueue.add(el);
                         tt++;
                     }else{
                         if(!priorityQueue.isEmpty()) {
                             long tv =(long)((long)Math.abs(priorityQueue.peek())+(long)tot);

                             if( tv > Math.abs(el) && Math.abs(priorityQueue.peek())>Math.abs(el) ){
                                 long ttt=priorityQueue.poll();
                                 tot=(long)((long)tot+(long)Math.abs(ttt)+(long)el);
                                 priorityQueue.add(el);
                             }
                         }

                     }
                 }
             }
             System.out.println(tt);















       






































































































         }









    }








