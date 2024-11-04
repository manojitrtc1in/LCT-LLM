

import java.util.*;
import java.awt.List;
import java.io.*;

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
	public static void main(String[] args) throws Exception{
		
		Reader s=new Reader();
		
		
		
			int n=s.nextInt();
			Integer[] arr=new Integer[n];
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
				
			}
			
			Arrays.sort(arr);
			
			long ans=Long.MAX_VALUE;
			
			if(n==3) {
			for(long i=1;i<=1000000;i++) {
				long cost=0;
				
				for(int j=0;j<n;j++) {
					cost=cost+Math.abs((arr[j]-pow(i, j)));
					
				}
				
				if(ans>=cost) {
					ans=cost;
					
				}
					
			}
			}else if(n<=5) {
				for(long i=1;i<=1000;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}else if(n==6) {
				for(long i=1;i<=1000;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}else if(n<=9) {
				for(long i=1;i<=100;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}else if(n>=10&&n<=18) {
				for(long i=1;i<=10;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}else if(n<=32) {
				for(long i=1;i<=3;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}else {
				for(long i=1;i<=1;i++) {
					long cost=0;
					
					for(int j=0;j<n;j++) {
						cost=cost+Math.abs((arr[j]-pow(i, j)));
						
					}
					
					if(ans>=cost) {
						ans=cost;
						
					}
						
				}
			}
			
			System.out.println(ans);
			
	}
	
	public static long pow(long a,int b) {
		long res=1;
		while(b>0) {
			if(b%2!=0) {
				res=res*a;
			}
			
			a=a*a;
			b=b/2;
		}
			
		return res;
	}
	
}