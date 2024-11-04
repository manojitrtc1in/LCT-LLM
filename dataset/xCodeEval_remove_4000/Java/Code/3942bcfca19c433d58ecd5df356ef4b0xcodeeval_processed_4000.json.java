

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class k{
	static class Reader 
    { 
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
	static final int MAXN = 1000001; 
    
   
    static int f[] = new int[MAXN]; 
       
   
    static void sieve() 
    { 
        f[1] = 1; 
        for (int i=2; i<MAXN; i++) 
            f[i] = i; 
       
       
        for (int i=4; i<MAXN; i+=2) 
            f[i] = 2; 
       
        for (int i=3; i*i<MAXN; i++) 
        { 
            
            if (f[i] == i) 
            { 
               
                for (int j=i*i; j<MAXN; j+=i) 
       
                   
                    if (f[j]==j) 
                        f[j] = i; 
            } 
        } 
    } 
       
    
    static ArrayList<Integer> get(int x) 
    { 
        ArrayList<Integer> ret = new ArrayList<>(); 
        while (x != 1) 
        { 
            ret.add(f[x]); 
            x = x / f[x]; 
        } 
        return ret; 
    } 
       
	
	public static void main(String[] args) throws Exception 
	{ 
	Reader s=new Reader();
	StringBuilder sb=new StringBuilder();
		sieve();
		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {

			int n=s.nextInt();
			int[] arr=new int[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			HashMap<Integer,Integer> map=new HashMap<>();
			for(int i=0;i<n;i++) {
				ArrayList<Integer> ans=get(arr[i]);
				HashMap<Integer,Integer> count=new HashMap<>();
				int val=1;
				for(int j=0;j<ans.size();j++) {
					count.put(ans.get(j), count.getOrDefault(ans.get(j), 0)+1);
				}
				
				for(Map.Entry<Integer, Integer> entry:count.entrySet()) {
					if(entry.getValue()%2!=0) {
						val=val*entry.getKey();
					}
				}
				
				map.put(val, map.getOrDefault(val, 0)+1);
				
				
			}
			long ans1=1;
			
			for(Map.Entry<Integer, Integer> entry:map.entrySet()) {
				
				ans1=Math.max(ans1, entry.getValue());
			
		}
			
			int b=0;
			
			long ans2=1;
			ArrayList<Integer> ss=new ArrayList<>();
			
			for(Map.Entry<Integer, Integer> entry:map.entrySet()) {
				if(entry.getValue()%2==0) {
					 b=b+entry.getValue();
				ss.add(entry.getKey());
					
				}
			}
			for(int i=0;i<ss.size();i++) {
				map.remove(ss.get(i));
			}
			map.put(1, map.getOrDefault(1,0 )+b);
			
			for(Map.Entry<Integer, Integer> entry:map.entrySet()) {
				ans2=Math.max(ans2, entry.getValue());
			}
			
			
		int q=s.nextInt();
		
		for(int j=0;j<q;j++) {
			long g=s.nextLong();
			
			if(g==0) {
				sb.append(ans1).append("\n");
			}else {
				sb.append(ans2).append("\n");
				
				
				
				
			}
			
			
			

		}
			
			
			
			
			
		}
		System.out.println(sb);
	}
}