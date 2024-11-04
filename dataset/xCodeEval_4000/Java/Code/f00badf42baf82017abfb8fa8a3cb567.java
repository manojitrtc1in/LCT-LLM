

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

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


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    public static void main(String[] args) throws IOException {
        Reader s=new Reader();
        int t=s.nextInt();
        for(int j=0;j<t;j++){
            int n=s.nextInt();
            int l=s.nextInt();
            int r=s.nextInt();
            HashMap<Integer, List<Integer>> left=new HashMap<>();
            HashMap<Integer,List<Integer>> right=new HashMap<>();
            int[] col=new int[l];
            int[] cor=new int[n];
            for(int i=0;i<l;i++){
                int co=s.nextInt();
                col[i]=co;
                left.putIfAbsent(co,new ArrayList<>());
                left.get(co).add(i);
            }
            for(int i=l;i<r+l;i++){
                int co=s.nextInt();
                cor[i]=co;
                right.putIfAbsent(co,new ArrayList<>());
                right.get(co).add(i);
            }
            boolean[] vis=new boolean[n];
            int ll=0;
            int rr=0;
            int cost=0;
            for(int i=l;i<l+r;i++){
                if(vis[i]){continue;}
                if( left.get(cor[i])!=null  ){
                    vis[i]=true;
                    vis[left.get(cor[i]).get( left.get(cor[i]).size()-1 )]=true;
                    left.get(cor[i]).remove( left.get(cor[i]).size()-1 );
                    right.get(cor[i]).remove(new Integer(i));
                    if(left.get(cor[i]).size()==0){
                        left.remove(cor[i]);
                    }
                    if(right.get(cor[i]).size()==0){
                        right.remove(cor[i]);
                    }
                }






























































            }
            for(int i=0;i<l;i++){
                if(vis[i]){continue;}
                if( right.get(col[i])!=null  ){
                    vis[i]=true;
                    vis[right.get(col[i]).get( right.get(col[i]).size()-1 )]=true;
                    right.get(col[i]).remove( right.get(col[i]).size()-1 );
                    left.get(col[i]).remove( new Integer(i) );
                    if(right.get(col[i]).size()==0){
                        right.remove(col[i]);
                    }
                    if(left.get(col[i]).size()==0){
                        left.remove(col[i]);
                    }
                }























































            }
            for(int i=0;i<l;i++){
                if(!vis[i]){
                    ll++;
                }
            }
            for(int i=l;i<r+l;i++){
                if(!vis[i]){
                    rr++;
                }
            }
            int tt=Math.max(rr,ll)-Math.min(ll,rr);
            cost=cost+Math.min(rr,ll);
             if(rr>ll){
                 List<Integer> list=new ArrayList<>();
                 for(Integer i:right.keySet()){
                    list.add(right.get(i).size());
                 }
                 Collections.sort(list,Collections.reverseOrder());
                 for(int i=0;i<list.size();i++){
                     if(tt<=1){
                         break;
                     }
                     if(list.get(i)>=2){
                         if(list.get(i)>tt){
                             cost=cost+tt/2;
                             tt=0;break;
                         }
                         cost=cost+list.get(i)/2;
                         tt=tt-list.get(i)+list.get(i)%2;
                     }
                 }
                 cost=cost+tt;


             }else if(ll>rr){
                 List<Integer> list=new ArrayList<>();
                 for(Integer i:left.keySet()){
                     list.add(left.get(i).size());
                 }
                 Collections.sort(list,Collections.reverseOrder());
                 for(int i=0;i<list.size();i++){
                     if(tt<=1){
                         break;
                     }
                     if(list.get(i)>=2){
                         if(list.get(i)>tt){
                             cost=cost+tt/2;
                             tt=0;break;
                         }
                         cost=cost+list.get(i)/2;
                         tt=tt-list.get(i)+list.get(i)%2;
                     }
                 }
                 cost=cost+tt;
             }


            System.out.println(cost);

        }


    }

    }








