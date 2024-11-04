

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class b {
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

		int t=s.nextInt();
		for(int ie=0;ie<t;ie++) {
			
			int n=s.nextInt();

			int[] arr=new int[n];
			int d=s.nextInt();
			
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			
			
			double st=0;
			double end=d;
			double gans=0;
			while(st<=end) {
				double mid=(st+end)/2;
				
				double t1=0;
				
				double t2=0;
				double s1=1;
				double s2=1;
				int g=0;
				for(int i=0;i<n+1;i++) {
					if(i==0) {
						if(arr[i]>mid) {
							t1=t1+(mid-0*1d)/s1;
							g=1;
							break;
						}
						
						t1=t1+(arr[i]-0*1d)/s1;
						s1++;
					}else if(i!=n){
					
					
					if(arr[i]>mid) {
						t1=t1+(mid-arr[i-1]*1d)/s1;
						g=1;
						break;
					}
					
					t1=t1+(arr[i]-arr[i-1]*1d)/s1;
					s1++;
					}else {
						
						t1=t1+(mid-arr[i-1]*1d)/s1;
						
						break;
					}
				}
				
				
				
				
				
				for(int i=n-1;i>=-1;i--) {
					if(i==n-1) {
						
						if(arr[i]<mid) {
							t2=t2+((d-mid)*1d)/s2;
							break;
						}
						
						t2=t2+(d-arr[i]*1d)/s2;
						s2++;
						
						
					}else if(i!=-1) {
					if(arr[i]<mid) {
						t2=t2+((arr[i+1]-mid)*1d)/s2;
						break;
					}
					
					t2=t2+(arr[i+1]-arr[i]*1d)/s2;
					s2++;
					}else {
						t2=t2+((arr[i+1]-mid)*1d)/s2;
						break;
					}
				}
				
				

				if(t1<t2) {
					gans=t1;
					st=mid+0.000001;
				}else if(Math.abs(t2-t1)<=0.000001) {
					gans=t1;
					break;
				}else {
					end=mid-0.000001;
				}
				
				
				
			}
			System.out.println(gans);
			
			
			
			
		}
	}
}