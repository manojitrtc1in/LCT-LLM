

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class d {
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
    	int m=s.nextInt();
    	int[] arr=new int[n];
    	int[] brr=new int[m];
    	for(int i=0;i<n;i++) {
    		arr[i]=s.nextInt();
    	}
    	for(int i=0;i<m;i++) {
    		brr[i]=s.nextInt();
    	}
    	
    	int ans=0;
    	for(int i=0;i<=513;i++) {
    		
    	int g=0;
    		String str2=Integer.toBinaryString(i);
    		for(int h=0;h<n;h++) {
    			int flag=0;
    		for(int j=0;j<m;j++) {
    			
    			String str=Integer.toBinaryString(arr[h]&brr[j]);
    			flag=0;
    			
    			int st=str.length()-1;
    			int st2=str2.length()-1;
    			while(st>=0) {
    				if(str.charAt(st)=='1') {
    					if(st2>=0) {
    						if(str2.charAt(st2)!='1') {
    							flag=1;
    							
    							break;
    						}
    					}else {
    						flag=1;
    						break;
    								
    					}
    					
    				}
    				
    				st--;
    				st2--;
    			}
    			if(flag==0) {
    				break;
    			}
    			
				
    		}
    		if(flag==1) {
    			g=1;
    			break;
    		}
    		
    		}
    		if(g==0) {
    			ans=i;
    			break;
    		}
    	}
    	
    	System.out.println(ans);
    	
    	
    }
}