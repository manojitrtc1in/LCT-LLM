

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
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
  
	
    public static void main(String[] args) throws Exception{
 
    	Reader s=new Reader();
    	StringBuilder sb=new StringBuilder();
 
    	int n=s.nextInt();
    	int q=s.nextInt();
    	int[] arr=new int[n];
    	
    	for(int i=0;i<n;i++) {
    		arr[i]=s.nextInt();
    	}
    	
    	int[] ans=new int[n];
    	int g=0;
    	for(int i=0;i<n;i++) {
    		if(arr[i]==q) {
    			g=1;
    			
    		}
    	}
    	
    	int flag=0;
    	int prev=0;
    	for(int i=0;i<n;i++) {
    		if(arr[i]==0) {
    			ans[i]=prev;
    		}else {
    			ans[i]=arr[i];
    			prev=arr[i];
    		}
    			
    	}
    	
    	HashMap<Integer,Integer> st=new HashMap<>();
    	HashMap<Integer,Integer> end=new HashMap<>();
    	
    	
    	if(g==0) {
    		int k=0;
    		for(int i=0;i<n;i++) {
    			if(arr[i]==0) {
    				k=1;
    				ans[i]=q;
    				break;
    			}
    		}
    		if(k==0) {
    			flag=1;
    		}
    	}
    	
    	
    	for(int i=0;i<n;i++) {
    		if(ans[i]==0) {
              ans[i]=1;   			
    		}else {
    			
    		}
    	}
    	for(int i=0;i<n;i++) {
    		if(st.containsKey(ans[i])) {
    			
    		}else {
    			st.put(ans[i], i);
    		}
    	}
    	for(int i=n-1;i>=0;i--) {
    		if(end.containsKey(ans[i])) {
    			
    		}else {
    			end.put(ans[i], i);
    		}
    	}
    	int[] tree=new int[4*n];
    	build(ans,tree,0,n-1,1);
    	for(Map.Entry<Integer, Integer> entry:st.entrySet()) {
    		int x=entry.getValue();
    		int y=end.get(entry.getKey());
    		int val=query(tree,0,n-1,1,x,y);
    		if(val<entry.getKey()) {
    			
    			flag=1;
    		}
    		
    		
    	}
    	
    	
    	if(flag==0)
    	{
    		sb.append("YES").append("\n");
    		for(int i=0;i<n;i++) {
    			sb.append(ans[i]+" ");
    			 
    		}
    	}else {
    		sb.append("NO").append("\n");
    	}
    		System.out.println(sb);
    }








































































































    public static void build(int[] arr,int[] tree,int st,int end,int pos) {
    	
    	if(st==end) {
    		tree[pos]=arr[st];
    		return;
    	}
    	
    	int mid=(st+end)/2;
    	
    	build(arr,tree,st,mid,2*pos);
    	build(arr,tree,mid+1,end,2*pos+1);
    	
    	tree[pos]=Math.min(tree[2*pos], tree[2*pos+1]);
    	
    }
    
    public static void update(int[] arr,int[] tree,int st,int end,int pos,int in,int val) {
    	if(st==end) {
    		tree[pos]=val;
    		arr[in]=val;
    		return;
    	}
    	
    	
    	int mid=(st+end)/2;
    	if(st<=in&&mid<=in) {
    		update(arr,tree,st,mid,2*pos,in,val);
    	}else  {
    		update(arr,tree,mid+1,end,2*pos+1,in,val);
    	}
    	
    	tree[pos]=Math.min(tree[2*pos], tree[2*pos+1]);
    }
    public static int query(int[] tree,int st,int end,int pos,int l,int r) {
    	
    	if(r<st||l>end) {
    		return Integer.MAX_VALUE;
    	}
    	
    	if(l<=st&&r>=end) {
    		return tree[pos];
    	}
    	
    	int mid=(st+end)/2;
    	int p1=query(tree,st,mid,2*pos,l,r);
    	int p2=query(tree,mid+1,end,2*pos+1,l,r);
    	
    	return Math.min(p1, p2);
    }


    
}

