import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class testMemory {
	static boolean f=false;
	static Scanner sc =new Scanner(System.in);
	public static boolean check(int x,int y) {
		    if(y==(x+1)||y==(x-1))
		        return true;
		    else
		        return false;
	}
	
	public static void run() {
		int k=sc.nextInt();
		int key[]=new int[k];
		for(int i=0;i<k;i++)
			key[i]=sc.nextInt();
		

		int l=sc.nextInt();
		int lock[]=new int[l];
		for(int i=0;i<l;i++)
			lock[i]=sc.nextInt();
		


	

		for(int i=0;i<k;i++) {
           for(int j=0;j<l;j++) {
        	   if(check(key[i],lock[j]))
        		   System.out.println(key[i]);
        	   return;
           }
		}
	}
	
	public static void EhabTheXorcist() {
		long u=sc.nextLong();
		long v=sc.nextLong();
		if(v<u) {
			System.out.println(-1);
			return;
		}
		if(u==0&&v==0) {
			System.out.println(0);
			return;
		}
			
		if(u==v) {
			System.out.println(1);
			System.out.println(u);
			return;
		}
		if((u&1)!=0&&(v&1)==0) {
			System.out.println(-1);
			return;
		}
		if((u&1)==0&&(v&1)!=0) {
			System.out.println(-1);
			return;
		}
		long x=(v>>1)-(u>>1);
		if(u==0) {
			System.out.println(2);
			System.out.println(x+" "+x);
			return;
		}
		long l=u;
		long r=v;
		while(l < r) {
			

			long m = (l>>1)+(r>>1);
			long t=m^u;
			long s=t+m;
			

			if(s==v) {
				System.out.println(2);
				System.out.println(m+" "+t);
				return;
			}
			else if(s>v) {
				r=m-1;
			}
			else {
				l=m+1;
			}
		}
		if(l==r) {
			if((l^r)==u&&l+r==v) {
				System.out.println(2);
				System.out.println(l+" "+r);
				return;
			}
		}
		System.out.println(3);
		System.out.println(u+" "+x+" "+x);
		
		
		
		
		
	}
	public static String input() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	public static int inputInt() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int x=0;
		try {
			st = new StringTokenizer(br.readLine());
			 x= Integer.parseInt(st.nextToken());
		} catch (IOException e) {
			

			e.printStackTrace();
		}
		
		return x;
	}
	public static void Hotelier() {
		 int n=Integer.parseInt(sc.nextLine());
		 StringBuilder s = new StringBuilder();
		 s.append(input());
		 

		 int []mask=new int[10];
		 for(int i=0;i<s.length();i++) {
			 
			 if(s.charAt(i)=='R') {
				 

				 for(int j=mask.length-1;j>=0;j--) {
					 if(mask[j]==0) {
						 mask[j]=1;
						 break;
					 }
				 }

			 }
			 

			 

			 else if(s.charAt(i)=='L') {
				 

				 for(int j=0;j<mask.length;j++) {
					 if(mask[j]==0) {
						 mask[j]=1;
						 break;
					 }
				 }
			 }
			 else {
				 System.out.println((char)s.charAt(i)+" "+i);
				 

				
			 }
			 

			 
		 }
		 for(int i=0;i<10;i++) {
			 System.out.print(mask[i]);
		 }
		 System.out.println();
	}
	public static void  GameWithString() {
		String s=input();
		Stack <Character>s1=new Stack<Character>();
		Stack <Character>s2=new Stack<Character>();
		for(int i=0;i<s.length();i++) {
			s1.push(s.charAt(i));
		}
		boolean f=true;
		while(!s1.isEmpty()) {
			if(!s2.isEmpty()) {
				if(s1.peek()==s2.peek()) {
					s1.pop();
					s2.pop();
					f=!f;
					continue;
				}
			}
		

				s2.push(s1.pop());

			
		}
		if(f)
			System.out.println("NO");
		else
			System.out.println("YES");


	}
	public static void SerejaAndSuffixes() {
		int n=sc.nextInt();
		int m=sc.nextInt();

		int a[]=new int[n];
		int max=0;
		for(int i=0;i<a.length;i++) {
			a[i]=sc.nextInt();
			if(a[i]>max)max=a[i];
			


		}
		boolean []mask=new boolean[max+1];
		int []temp=new int[n];
		temp[n-1]=1;
		mask[a[n-1]]=true;
		for(int i=n-2;i>=0;i--) {
			int x=temp[i+1];
			if(!mask[a[i]]) {
				mask[a[i]]=true;
				x++;
			}
			temp[i]=x;
		}
		for(int i=0;i<m;i++) {
			int y=sc.nextInt();
			System.out.println(temp[y-1]);
		}
		
		
	}
	public static void HitTheLottery() {
		int n=sc.nextInt();
		int count=0;
		int [] m= {100,20,10,5,1};
		for(int i=0;i<5;i++) {
			if(n>=m[i]) {
				int x=n/m[i];
				count+=x;
				n=n-x*m[i];
			}
		}
		System.out.println(count);

		
	}
	public static int lg(long x) {
		return (int)(Math.log10(x)/Math.log10(2));
	}
	public static void ANDORAndSquareSum() {
		int n=sc.nextInt();
		long m[]=new long[n];
		int a[]=new int[20];
		int maxb=0;
		for(int i=0;i<n;i++) {
			m[i]=sc.nextInt();
			long t=m[i];
			int bit=0;
			while(t>0) {
				if((t&1)!=0) {
					a[bit]++;
					if(a[bit]>maxb)
						maxb=a[bit];
				}
				bit++;
				t>>=1;
			}
		}
		long num[]=new long[maxb];
		for(int i=0;i<a.length;i++) {
			int j=0;
			while(a[i]>0) {
				num[j]=num[j]|(1<<i);
				j++;
				a[i]--;
			}
		}
		long sum=0;
		for(int i=0;i<num.length;i++) {
			sum+=(num[i]*num[i]);
		}
		System.out.println(sum);


		

		
	}
	public static void PolycarpTraining() {
		int n=sc.nextInt();
		

		

		LinkedList <Integer>l=new LinkedList<Integer>();
		for(int i=0;i<n;i++) {
			

			l.add(sc.nextInt());
		}
		
		Collections.sort(l);
		

		

		int days=1;
		for(int i=0;i<n;i++) {
			if(l.remove()>=days) {
				days++;
			}

		}
		System.out.println(days-1);
	}
	public static void PolycarpTraining2() {
		int n=sc.nextInt();
		int a[]=new int[n];
		

		

		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			

		}
		
		

		

		Arrays.sort(a);
		int days=1;
		for(int i=0;i<n;i++) {
			if(a[i]>=days) {
				days++;
			}

		}
		System.out.println(days-1);
	}

	
	public static void RequiredRemainder() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int n=sc.nextInt();
			int c1=(n-y)%x;

			System.out.println(n-c1);
			int c=((n-y)/x)*x+y;
			System.out.println(c);
	
			
		}
	}
    static int binarySearch( int arr[],int x,int l,int r) 
    { 

        while (l <= r) { 
            int m = l + (r - l) / 2; 
            
  
            

            if (arr[m] == x) 
                return m; 
  
            

            if (arr[m] < x) 
                l = m + 1; 
  
            

            else
                r = m - 1; 
        } 
  
        

        

        return -1; 
    } 
    
    public static void MultiplyBy2DivideBy6() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    		int n=sc.nextInt();
    		int c2=0;
    		int c3=0;
    		while(n%3==0) {
    			c3++;
    			n/=3;
    		}
    		while(n%2==0) {
    			c2++;
    			n>>=1;
    		}
    		if(n==1) {
    			if(c3>=c2) {
    				

    				System.out.println(c3+(c3-c2));
    			}
    			else
    				System.out.println(-1);
    			
    		}
    		else
    			System.out.println(-1);
    	}
    }
    public static void GameWithArray() {
    	int n=sc.nextInt();
    	int s=sc.nextInt();
		 PrintWriter out = new PrintWriter(System.out);
    	if((2*n)>=(s+1)) {
    	    out.println("NO");  

            out.flush();
    		
    	}
    	else {
             out.println("YES");  

             out.flush();
    		

    		for(int i=0;i<n-1;i++) {
                out.print(1+" ");  

                

    			s--;
    		}
            out.print(s);  

            out.flush();
            
    		

    		System.out.println();
    		System.out.println(s-1);
    	}
    }
    public static void GameWithArray2() {
    	int n=sc.nextInt();
    	int s=sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		int d=s/n;
		int mod=s%n;
		if(d<=1) {
    	    out.println("NO");  

            out.flush();
		}
		else {
			 out.println("YES");  

             out.flush();
    		

    		for(int i=0;i<n-1;i++) {
                out.print(d+" ");  

                

    			

    		}
            out.print(d+mod);  

            out.flush();
            
    		

    		System.out.println();
    		System.out.println(1);
		}
		
    }
    public static void MagicalSticks() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    		long a=sc.nextLong();
    		long x =(a*(a+1))/(2*a);
    		System.out.println(x);
    	}
    }
    
    public static void  QAQ() {
    	String s=sc.nextLine();
    	String word=s;
    	

    	

    	int count=0;
    	int []a=new int[s.length()];
    	for(int i=0;i<s.length();i++) {
    		if(word.charAt(i)=='Q') {
    			for(int j=i+1;j<s.length();j++) {
    				if(word.charAt(j)=='A') {
    	    			


    					if(a[j]!=0) {
    						count+=a[j]-1;
    					}
    					else {
    						a[j]=1;
    					for(int k=j+1;k<s.length();k++) {
    						if(word.charAt(k)=='Q') {
    						

    							a[j]++;
    							count++;
    						}
    					}
    					}
    				}
    			}
    		}
    	}
    	System.out.println(count);
    	
    }
    
    public static void PetrAndACombinationLock() {
    	int n=sc.nextInt();
    	int a[]=new int[n];
    	for(int i=0;i<n;i++) {
    		a[i]=sc.nextInt();
    	}
    	helper(0,a,n,0);
		System.out.println("NO");

    }
    private static void helper(int i,int a[],int n,int degree) {
    	if(f)return;
    	if(n==0) {
    		
    		

    		if(degree==0||degree==360||degree==-360) {
    			System.out.println("YES");
    			f=true;
    			System.exit(0);
    			
    		}
    		
    	}
    	else if(i>=a.length)return;
    	else {
    		

    		int dl=degree+a[i];
    		if(dl>360)
    			dl=dl-360;
    		int dr=degree-a[i];
    		if(dr<0)
    			dr=dr+360;
    		helper(i+1,a,n-1,dr);
    		helper(i+1,a,n-1,dl);

    	}
    }
    public static void Equalize() {
    	int x=Integer.parseInt(sc.nextLine());
    	String s=sc.nextLine();
    	String s2=sc.nextLine();
    	int count =0;
    	for(int i=0;i<x;i++) {
    		if(s.charAt(i)!=s2.charAt(i)) {
    			if(i<x-1) {
    				if(s.charAt(i+1)!=s2.charAt(i+1)&&s.charAt(i+1)!=s.charAt(i)) {
    					count++;
    					i++;
    				}
    				else {
    					count++;
    				}
    			}
    			else {
    				count++;
    			}
    		}
    	}
    	System.out.println(count);
    }
	private static double daysAtindex(long sum) {
		double t=(Math.sqrt(1+((sum)*8))-1)/2;
		return t;
	}
	
	public static void Packets() {
		double x=sc.nextDouble();
		System.out.println(((int)(Math.log10(x)/Math.log10(2)))+1);
		


		
	}
	
	public static void ReachMedian() {
		int n=sc.nextInt();
		int s=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		long count=0;
		if(a[n/2]<=s) {
			for(int i=n/2;i<n;i++) {
				if(s>a[i]) {
					count+=s-a[i];
				}
			}
		}
		else {
			for(int i=0;i<=n/2;i++) {
				if(s<a[i]) {
					count+=a[i]-s;
				}
			}
			
		}
		System.out.println(count);
	}
	public static void NumberGame() {
		int t=sc.nextInt();
		for(int p=0;p<t;p++) {
			int n=sc.nextInt();
			

			if(n==1) {
			   System.out.println("FastestFinger");

			}
			else if(n==2) {
				System.out.println("Ashishgup");

			}
			else if(n==3) {
				System.out.println("Ashishgup");

			}
			else if((n&1)==1) {
				System.out.println("Ashishgup");
			}
			else if(isPowerOfTwoMe(n)) {
				System.out.println("FastestFinger");
			}
			else if((n&2)==0) {
				System.out.println("Ashishgup");
			}
			else if(isPrime(n/2)){
				System.out.println("FastestFinger");

			}
			else {
				System.out.println("Ashishgup");

			}
		}

	}
	static boolean isPowerOfTwo(int n) 
	{ 
	    if(n==0) 
	    return false; 
	  
	return (int)(Math.ceil((Math.log10(n) / Math.log10(2)))) ==  
	       (int)(Math.floor(((Math.log10(n) / Math.log10(2))))); 
	} 
	static boolean isPowerOfTwoMe(int n) {
		return(n&-n)==n;
	}
    static boolean isPrime(int n) { 
    

    if (n%2==0) return false; 
    

    for(int i=3;i<=Math.sqrt(n);i+=2) { 
        if(n%i==0) 
            return false; 
    } 
    return true; 
} 
    
    public static void CodeforcesSubsequences() {
		PrintWriter out = new PrintWriter(System.out);
    	long k=sc.nextLong();
        char [] c= {'c','o','d','e','f','o','r','c','e','s'};
        int [] r= {1,1,1,1,1,1,1,1,1,1};
        int n=2;
        long s=1;
        int i=0;
        while(s<k) {
        	if(i>=10) {
        		i=0;
        		n++;
        	}
        	s/=r[i];
        	r[i]=n;
        	s*=r[i];
        	i++;
        	
        }
        

        for(int z=0;z<10;z++) {
        	for(int j=r[z];j>0;j--) {
        		out.print(c[z]);
        	}
        }
        out.flush();
    }
    public static void RationalLee() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    	  int n=sc.nextInt();
    	  int k=sc.nextInt();
    	  ArrayList <Integer> a=new ArrayList <Integer>(n+1);
    	  for(int i=0;i<n;i++) {
    		  a.add(sc.nextInt());
    	  }
    	  ArrayList <Integer> w=new ArrayList <Integer>(k+1);
    	  int countOnes=0;
    	  for(int i=0;i<k;i++) {
    		  int x=sc.nextInt();
    		  w.add(x);
    		  if(x==1)countOnes++;
    		 
    	  }
    	  Collections.sort(a);
    	  Collections.sort(w);
    	  long c=0;
    	  int r=a.size()-1;
    	  int l=0;
    	

    	  for(int i=w.size()-1;i>=0;) {
    		  if(countOnes>0) {
    			

    			  c+=(a.get(r)*2);
    			 

    			  r--;
    			  countOnes--;
    			  continue;
    		  }
    		  else if(w.get(i)!=1){
    			 

    			 c+=a.get(l)+a.get(r);
    			 r--;
    			 l+=(w.get(i)-1);
    			  
    		  }
    		  else {
    			  break;
    		  }
    		  i--;
    	  }
    	  System.out.println(c);
    	}
    }
    
    public static void RationalLee2() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    	  int n=sc.nextInt();
    	  int k=sc.nextInt();
    	  Integer a[]=new Integer[n];
    	  for(int i=0;i<n;i++) {
    		  a[i]=sc.nextInt();
    	  }
    	  Integer w[]=new Integer[k];
    	  int countOnes=0;
    	  for(int i=0;i<k;i++) {
    		  w[i]=sc.nextInt();
    		  if(w[i]==1)countOnes++;
    	  }
    	  Arrays.sort(a);
    	  Arrays.sort(w);
    	  long c=0;
    	  int r=a.length-1;
    	  int l=0;
    	

    	  for(int i=w.length-1;i>=0;) {
    		  if(countOnes>0) {
    			

    			  c+=(a[r]*2);
    			 

    			  r--;
    			  countOnes--;
    			  continue;
    		  }
    		  else if(w[i]!=1){
    			 

    			 c+=a[l]+a[r];
    			 r--;
    			 l+=(w[i]-1);
    			  
    		  }
    		  else {
    			  break;
    		  }
    		  i--;
    	  }
    	  System.out.println(c);
    	}
    }
	

	public static void main(String[] args) {
		

		

		















		

		

		 

		

		

		

		

		

		

		

		

		

		

	

		

		

		

		

		RationalLee2();



		

	}

}
