import java.io.*;
import java.util.*;

public class id0 {

	static long[][] t;
	static long[] a;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		a = new long[n];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < n; i++)
			a[i] = Integer.parseInt(st.nextToken());
		
		t = new long[4 * n][7];
		
		build(1, 0, n-1);
		
		for(int i = 0; i < q; i++) {
			
			st = new StringTokenizer(br.readLine());
			int type = Integer.parseInt(st.nextToken());
			int xl = Integer.parseInt(st.nextToken());
			int yr = Integer.parseInt(st.nextToken());
			
			if(type == 1) {
				
				update(1, 0, n-1, xl-1, yr);
				
			}else {
				
				long[] res = sum(1, 0, n-1, xl-1, yr-1);
				
				if(res[6] == 1) {
					
					pw.println(res[4]);
					
				}else {
					
					pw.println((res[4] + (res[3] * (res[3] + 1) / 2)));
					
				}
				
				

				
			}
			
		}

		pw.flush();
		pw.close();
		
	}
	
	

	

	

	

	

	

	

	static void build(int v, int tl, int tr) {
	    if (tl == tr) {
	        t[v][0] = t[v][2] = a[tl];
	        t[v][1] = t[v][3] = t[v][4] = t[v][5] = t[v][6] = 1;
	        

	    } else {
	        int tm = (tl + tr) / 2;
	        build(v*2, tl, tm);
	        build(v*2+1, tm+1, tr);
	        
	        

	        t[v][0] = t[v*2][0];
	        t[v][2] = t[v*2+1][2];	        
	        

	        if(t[v*2][2] <= t[v*2+1][0]) {
	        	
	        	

	        	
	        	

	        	long midseg = (t[v*2][3] + t[v*2+1][1]) * (t[v*2][3] + t[v*2+1][1] + 1) / 2;
	        	
	        	

	        	t[v][6] = 1;
	        	
	        	

	        	if(t[v*2][6] == 1) {
	        		
	        		

	        		t[v][1] = t[v*2][3] + t[v*2+1][1];
	        		
	        		if(t[v*2+1][6] == 1) {
	        			
	        			t[v][4] = midseg;	        			
	        			
	        		}else {
	        			
	        			t[v][4] = midseg + t[v*2+1][4] - (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2);
	        			
	        		}
	        		
	        	}else {
	        		
	        		

	        		t[v][1] = t[v*2][1];
	        		

	        		t[v][6] = 0;
	        		
	        		if(t[v*2+1][6] == 1) {
	        			
	        			t[v][4] = t[v*2][4];	        			
	        			
	        		}else {
	        			
	        			t[v][4] = t[v*2][4] + midseg + t[v*2+1][4] - (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2);
	        			
	        		}
	        			        		
	        	}
	        	
	        	

	        	if(t[v*2+1][6] == 1) {
	        		
	        		

	        		t[v][3] = t[v*2][3] + t[v*2+1][1];
	        		
	        		if(t[v*2][6] == 1) {
	        			
	        			t[v][5] = midseg;	        			
	        			
	        		}else {
	        				        				  
	        			

	        			t[v][5] = midseg + t[v*2][5] - (t[v*2][3] * (t[v*2][3] + 1) / 2);
	        			
	        			

	        			
	        		}
	        		
	        	}else {
	        		
	        		

	        		t[v][3] = t[v*2+1][3];
	        		

	        		t[v][6] = 0;
	        		
	        		if(t[v*2][6] == 1) {
	        			
	        			t[v][5] = t[v*2+1][5];	        			
	        			
	        		}else {
	        			
	        			t[v][5] = t[v*2+1][5] + midseg + t[v*2][5] - (t[v*2][3] * (t[v*2][3] + 1) / 2);
	        			
	        		}
	        			        		
	        	}        	
	        	
	        }else {
	        	
	        	

		        t[v][1] = t[v*2][1];
		        t[v][3] = t[v*2+1][3];
		        
		        

		        t[v][6] = 0;
		        
		        

		        
		        

		        
		        t[v][4] = t[v*2][4] + ((t[v*2][6] == 0) ? (t[v*2][3] * (t[v*2][3] + 1) / 2) : 0) + ((t[v*2+1][6] == 0) ? t[v*2+1][4] : 0);
		        t[v][5] = t[v*2+1][5] + ((t[v*2+1][6] == 0) ? (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2) : 0) + ((t[v*2][6] == 0) ? t[v*2][5] : 0);
	        	
	        }
	        
	        

	        
	    }
	}
	
	static void update(int v, int tl, int tr, int pos, int new_val) {
	    if (tl == tr) {
	    	t[v][0] = t[v][2] = new_val;
	        t[v][1] = t[v][3] = 1;
	    } else {
	        int tm = (tl + tr) / 2;
	        if (pos <= tm)
	            update(v*2, tl, tm, pos, new_val);
	        else
	            update(v*2+1, tm+1, tr, pos, new_val);
	      

	        t[v][0] = t[v*2][0];
	        t[v][2] = t[v*2+1][2];	        
	        

	        if(t[v*2][2] <= t[v*2+1][0]) {
	        	
	        	

	        	long midseg = (t[v*2][3] + t[v*2+1][1]) * (t[v*2][3] + t[v*2+1][1] + 1) / 2;
	        	
	        	

	        	t[v][6] = 1;
	        	
	        	

	        	if(t[v*2][6] == 1) {
	        		
	        		

	        		t[v][1] = t[v*2][3] + t[v*2+1][1];
	        		
	        		if(t[v*2+1][6] == 1) {
	        			
	        			t[v][4] = midseg;	        			
	        			
	        		}else {
	        			
	        			t[v][4] = midseg + t[v*2+1][4] - (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2);
	        			
	        		}
	        		
	        	}else {
	        		
	        		

	        		t[v][1] = t[v*2][1];
	        		

	        		t[v][6] = 0;
	        		
	        		if(t[v*2+1][6] == 1) {
	        			
	        			t[v][4] = t[v*2][4];	        			
	        			
	        		}else {
	        			
	        			t[v][4] = t[v*2][4] + midseg + t[v*2+1][4] - (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2);
	        			
	        		}
	        			        		
	        	}
	        	
	        	

	        	if(t[v*2+1][6] == 1) {
	        		
	        		

	        		t[v][3] = t[v*2][3] + t[v*2+1][1];
	        		
	        		if(t[v*2][6] == 1) {
	        			
	        			t[v][5] = midseg;	        			
	        			
	        		}else {
	        			
	        			t[v][5] = midseg + t[v*2][5] - (t[v*2][3] * (t[v*2][3] + 1) / 2);
	        			
	        		}
	        		
	        	}else {
	        		
	        		

	        		t[v][3] = t[v*2+1][3];
	        		

	        		t[v][6] = 0;
	        		
	        		if(t[v*2][6] == 1) {
	        			
	        			t[v][5] = t[v*2+1][5];	        			
	        			
	        		}else {
	        			
	        			t[v][5] = t[v*2+1][5] + midseg + t[v*2][5] - (t[v*2][3] * (t[v*2][3] + 1) / 2);
	        			
	        		}
	        			        		
	        	}
	        	
	        	
	        	
	        }else {
	        	
	        	

		        t[v][1] = t[v*2][1];
		        t[v][3] = t[v*2+1][3];
		        
		        

		        t[v][6] = 0;
		        
		        

		        t[v][4] = t[v*2][4] + ((t[v*2][6] == 0) ? (t[v*2][3] * (t[v*2][3] + 1) / 2) : 0) + ((t[v*2+1][6] == 0) ? t[v*2+1][4] : 0);
		        t[v][5] = t[v*2+1][5] + ((t[v*2+1][6] == 0) ? (t[v*2+1][1] * (t[v*2+1][1] + 1) / 2) : 0) + ((t[v*2][6] == 0) ? t[v*2][5] : 0);
	        	
	        }
	    }
	}

	static long[] sum(int v, int tl, int tr, int l, int r) {
	    if (l > r) 
	        return null;
	    if (l == tl && r == tr) {
	        return t[v];
	    }
	    int tm = (tl + tr) / 2;
	    
	    long[] sega = sum(v*2, tl, tm, l, Math.min(r, tm));
	    long[] segb = sum(v*2+1, tm+1, tr, Math.max(l, tm+1), r);
	    long[] segc = new long[7];
	    
	    if(sega == null)
	    	return segb;
	    
	    if(segb == null)
	    	return sega;
	    
	    

	    segc[0] = sega[0];
	    segc[2] = segb[2];	        
        

        if(sega[2] <= segb[0]) {
        	
        	

        	long midseg = (sega[3] + segb[1]) * (sega[3] + segb[1] + 1) / 2;
        	
        	

        	segc[6] = 1;
        	
        	

        	if(sega[6] == 1) {
        		
        		

        		segc[1] = sega[3] + segb[1];
        		
        		if(segb[6] == 1) {
        			
        			segc[4] = midseg;	        			
        			
        		}else {
        			
        			segc[4] = midseg + segb[4] - (segb[1] * (segb[1] + 1) / 2);
        			
        		}
        		
        	}else {
        		
        		

        		segc[1] = sega[1];
        		

        		segc[6] = 0;
        		
        		if(segb[6] == 1) {
        			
        			segc[4] = sega[4];	        			
        			
        		}else {
        			
        			segc[4] = sega[4] + midseg + segb[4] - (segb[1] * (segb[1] + 1) / 2);
        			
        		}
        			        		
        	}
        	
        	

        	if(segb[6] == 1) {
        		
        		

        		segc[3] = sega[3] + segb[1];
        		
        		if(sega[6] == 1) {
        			
        			segc[5] = midseg;	        			
        			
        		}else {
        			
        			segc[5] = midseg + sega[5] - (sega[3] * (sega[3] + 1) / 2);
        			
        		}
        		
        	}else {
        		
        		

        		segc[3] = segb[3];
        		

        		segc[6] = 0;
        		
        		if(sega[6] == 1) {
        			
        			segc[5] = segb[5];	        			
        			
        		}else {
        			
        			segc[5] = segb[5] + midseg + sega[5] - (sega[3] * (sega[3] + 1) / 2);
        			
        		}
        			        		
        	}
        	
        	
        	
        }else {
        	
        	

        	segc[1] = sega[1];
        	segc[3] = segb[3];
	        
	        

        	segc[6] = 0;
	        
	        

        	segc[4] = sega[4] + ((sega[6] == 0) ? (sega[3] * (sega[3] + 1) / 2) : 0) + ((segb[6] == 0) ? segb[4] : 0);
	        segc[5] = segb[5] + ((segb[6] == 0) ? (segb[1] * (segb[1] + 1) / 2) : 0) + ((sega[6] == 0) ? sega[5] : 0);
        	
        }
        
        return segc;
	    
	}
	
}
