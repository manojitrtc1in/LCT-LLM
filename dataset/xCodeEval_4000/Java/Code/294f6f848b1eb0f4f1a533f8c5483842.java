

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
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

	public static void main(String[] args) throws Exception {

		Reader s=new Reader();
		
		int n=s.nextInt();
		int a=s.nextInt();
		int b=s.nextInt();
		StringBuilder sb=new StringBuilder();
		int flag=0;
		long v1=0;
		long v2=0;
		for(int i=0;i<n+1;i++) {
			
			if((n-1l*a*i)%b==0&&n-1l*a*i>=0) {
				v1=i;
				v2=(n-1l*a*i)/b;
				flag=1;
				break;
						
			}
		}
	
	

		if(flag==0) {
		   System.out.println(-1);
		}else {
			
			int[] ans=new int[n];
			
			int curr=1;
			int st=0;
			

			while(v1>0) {
				
			for(int i=st;i<st+a;i++) {
				curr++;
				if(i==st+a-1) {
					ans[i]=curr-a;
				}else {
					ans[i]=curr;
				}
			
			}
			st=st+a;
			v1--;
			}
			
			while(v2>0) {
				for(int i=st;i<st+b;i++) {
					curr++;
					if(i==st+b-1) {
						ans[i]=curr-b;
					}else {
						ans[i]=curr;
					}
				
				}
				st=st+b;
				v2--;
				}
			
			
			for(int i=0;i<n;i++) {
				sb.append(ans[i]).append(" ");
			}
			
		System.out.println(sb);	
		}
		
		
		
				
		
	}
	
	
}