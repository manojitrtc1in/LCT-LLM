

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
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
	public static void main(String[] args) throws Exception
	{
         Reader s=new Reader();
 
        int n=s.nextInt();
        int[] arr=new int[n];
        
        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }
        
        HashMap<Integer,ArrayList<Integer>> map=new HashMap<>();
        
        for(int i=0;i<n;i++) {
        	if(map.containsKey(arr[i])) {
        		ArrayList<Integer> d=map.get(arr[i]);
        		d.add(i);
        		map.put(arr[i], d);
        	}else {
        		ArrayList<Integer> p=new ArrayList<>();
        		p.add(i);
        		map.put(arr[i], p);
        	}
        }
        int[] g=new int[6];
        g[0]=4;
        g[1]=8;
        g[2]=15;
        g[3]=16;
        g[4]=23;
        g[5]=42;
        
        int st=1;
        
        int how=0;
        if(map.containsKey(4)) {
        	ArrayList<Integer> list=map.get(4);
        	for(int i=0;i<list.size();i++) {
        		int flag=0;
        		int in=list.get(i);
        		st=1;
        		while(st<6) {
        			if(map.containsKey(g[st])) {
        			int ans=bs(map.get(g[st]),in);
        			int c=bes(map.get(g[st]),in);
        			if(ans==-1) {
        				flag=1;
        				break;
        			}else {
        				in=ans;
        				map.get(g[st]).set(c, -1);
        				st++;
        			}
        				
        				
        		}else {
        			flag=1;
        			break;
        		}
        		}
        		if(flag==0) {
        			how++;
        		}
        	}
        	
        	System.out.println(n-how*6);
        	
        }else {
        	System.out.println(n);
        }
         
         
	}
	public static int bs(ArrayList<Integer> list,int val) {
		int st=0;
		int end=list.size()-1;
		int ans=-1;
		while(st<=end) {
			int mid=(st+end)/2;
			if(list.get(mid)<=val) {
			  st=mid+1;
			}else {
				ans=list.get(mid);
				end=mid-1;
			}
		}
		
		return ans;
	}
	public static int bes(ArrayList<Integer> list,int val) {
		int st=0;
		int end=list.size()-1;
		int ans=-1;
		while(st<=end) {
			int mid=(st+end)/2;
			if(list.get(mid)<=val) {
			  st=mid+1;
			}else {
				ans=mid;
				end=mid-1;
			}
		}
		
		return ans;
	}
}