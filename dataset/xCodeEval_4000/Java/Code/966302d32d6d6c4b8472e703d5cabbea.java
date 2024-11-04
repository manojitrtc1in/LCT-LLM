

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
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
		int k=s.nextInt();
		long d=s.nextLong();
		long t=s.nextLong();
		
		long[][] car=new long[n][2];
		long max=Integer.MIN_VALUE;
		for(int i=0;i<n;i++) {
			car[i][0]=s.nextLong();
			car[i][1]=s.nextLong();
			max=Math.max(car[i][1], max);
		}
		
		Long[] gas=new Long[k+2];
		gas[0]=0l;
		for(int i=1;i<gas.length-1;i++) {
			gas[i]=s.nextLong();
			
		}
		gas[k+1]=d;
		Arrays.sort(gas);
		
		long min=Long.MAX_VALUE;
		long st=0;
		long end=max;
		
		long ans=-1;
		
		while(st<=end) {
			long mid=(st+end)/2;
			long time=0;
			int flag=0;
			for(int i=0;i<gas.length-1;i++) {
				long dist=gas[i+1]-gas[i];
				
				long g=0;
				if(dist>mid) {
					g=-1;
				}else {
					g=Math.min(dist, mid-dist);
				}
			
				if(g==-1) {
					flag=1;
				}else {
					time=time+g+(dist-g)*2;
					
				}
			}
			
			if(time>t) {
				flag=1;
			}
			
			
			
			if(flag==1) {
				st=mid+1;
			}else {
				ans=mid;
				end=mid-1;
			}
			
			
		}
		
		if(ans==-1) {
		System.out.println(-1);
		}else {
			for(int i=0;i<n;i++) {
				if(car[i][1]>=ans) {
					min=Math.min(min, car[i][0]);
				}
			}
			
			System.out.println(min);
		}
		
		
		
		
		
		
		
		
	}
	
	public static long bs(long d,long cap) {
		
		long ans=-1;
		long st=0;
		long end=d;
		while(st<=end) {
			long mid=(st+end)/2;
			if(mid*2+d-mid<=cap) {
				ans=mid;
				st=mid+1;
			}else {
				end=mid-1;
			}
			
		}
		
		
		return ans;
		
	}
}