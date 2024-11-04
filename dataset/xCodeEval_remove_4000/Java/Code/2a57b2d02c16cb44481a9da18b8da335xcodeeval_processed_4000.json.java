

import java.awt.List;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
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
        StringBuilder sb=new StringBuilder();
		
        
        int n=s.nextInt();
        int[] arr=new int[n];
        
        for(int i=0;i<n;i++) {
        	arr[i]=s.nextInt();
        }
        
        int[] ans=new int[n];
        
        ArrayList<Integer> left=new ArrayList<>();
        int curr=0;
        int count=0;
        for(int i=0;i<n;i++) {
        	count=arr[i]-curr;
        	if(arr[i]-curr>1) {
        		for(int j=0;j<count-1;j++) {
        			left.add(curr+1);
        			curr++;
        			
        		}
        		curr=arr[i];
        	}else {
        		curr=arr[i];
        	}
        	
        	
        }
       int flag=0;
        int mex=0;
        int st=0;
        for(int i=0;i<n;i++) {
        	if(arr[i]==mex) {
        		if(st<left.size()) {
        			ans[i]=left.get(st);
        			st++;
        		}else {
        			ans[i]=1000000;
        		}
        		
        	}else if((st<left.size()&&left.get(st)>arr[i])||(st==left.size())){
        		ans[i]=mex;
        		mex=arr[i];
        		
        	}else {
        		flag=1;
        		break;
        	}
        }
     

       if(flag==1) {
    	   sb.append(-1).append("\n");
       }else {
    	   for(int i=0;i<n;i++) {
    		  sb.append(ans[i]).append(" ");
    	   }
       }
System.out.println(sb);

	}
}