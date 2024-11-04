import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class Div656 {
	static Scanner sc =new Scanner(System.in);
	static PrintWriter out =new PrintWriter(System.out);
	
	public static void ThreePairwiseMaximums() {
		int t=sc.nextInt();
		outer:for(int o=0;o<t;o++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			int []n= {x,y,z};
			int a=0;
			int b=0;
			int c=0;
			for(int i=0;i<3;i++) {
				for(int j=0;j<3;j++) {
					for(int k=0;k<3;k++) {
						a=n[i];
						b=n[j];
						c=n[k];
						if(x==Math.max(a,b)&&y==Math.max(a, c)&&z==Math.max(b, c)) {
							System.out.println("YES");
							System.out.println(a+" "+b+" "+c);
							continue outer;
						}
					}
				}
			}
			System.out.println("NO");
		}
	}
	
	public static void RestorethePermutationyMerger() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			LinkedHashSet<Integer>s =new LinkedHashSet<Integer>();
			for(int i=0;i<2*n;i++) {
				s.add(sc.nextInt());
			}
			for(Integer a:s) {
				System.out.print(a+" ");
			}
			System.out.println();

			
		}
	}
	
	
	public static int aGoodStringRec(String s,int l,int r,char c,int[][]ch,int[]counterCh,int temp){
		if(l==r&&s.charAt(l)==c)return 0;
		else if(l==r&&s.charAt(l)!=c)return 1;
		

		

		

		int y=0;
		if(l>0) {
			y=ch[l-1][c-97];
			


		}
		int fH=(temp/2)-(ch[(l+r)/2][c-97]-y);
		int sH=(temp/2)-(ch[r][c-97]-ch[(l+r)/2][c-97]);
		int mid=(l+r)/2;
		

		int FT=fH+aGoodStringRec(s,mid+1,r,(char) (c+1),ch,counterCh,temp/2);
		

		

		int ST=sH+aGoodStringRec(s,l,mid,(char) (c+1),ch,counterCh,temp/2);
		

		return Math.min(FT,ST);
		
	}
	
	public static void aGoodString(){
		int t=sc.nextInt();
		sc.nextLine();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			sc.nextLine();
			String s=sc.nextLine();
			int [][]ch=new int[n][26];
			int []counterCh=new int[26];
			for(int i=0;i<s.length();i++) {
				counterCh[s.charAt(i)-97]++;
				for(int j=0;j<26;j++) {
					

					ch[i][j]=counterCh[j];
				}	
			}
		

			



























































			
			
			System.out.println(aGoodStringRec(s,0,n-1,'a',ch,counterCh,n));
			

		}
	}
	
	public static void MakeItGood() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			int a[]=new int[n];
			Integer b[]=new Integer[n];
			HashMap<Integer,Integer>h=new HashMap<Integer,Integer>();
			for(int i=0;i<n;i++){
				a[i]=sc.nextInt();
				b[i]=a[i];
				if(h.get(a[i])==null)h.put(a[i], 1);
				else h.put(a[i],h.get(a[i])+1);
			}
			if(n==1) {
				System.out.println(0);
				continue;
			}
			Arrays.sort(b);
			
			int l=0;int r=n-1;
			int m=0;
			int i=0;
			boolean f=true;
			while(l<r) {
				if(a[r]==b[i]) {
					h.put(a[r], h.get(a[r])-1);

					r--;
					i++;
				}
				else if(a[l]==b[i]&&f) {
					h.put(a[l], h.get(a[l])-1);

					l++;
					i++;
				}
				else if(a[l]==b[i]&&!f) {
					h.put(a[l], h.get(a[l])-1);

					m=l;
					f=true;
					i++;
					l++;
				}
				else {
					h.put(a[l], h.get(a[l])-1);
					f=false;
					l++;
				}
			}
            

			System.out.println(m);
			
				

		}
	}
	
	public static void MakeItGood2() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			int a[]=new int[n];
			Integer b[]=new Integer[n];
			HashMap<Integer,Integer>h=new HashMap<Integer,Integer>();
			for(int i=0;i<n;i++){
				a[i]=sc.nextInt();
				b[i]=a[i];
				if(h.get(a[i])==null)h.put(a[i], 1);
				else h.put(a[i],h.get(a[i])+1);
			}
			if(n==1) {
				System.out.println(0);
				continue;
			}
			Arrays.sort(b);
			
			int l=0;int r=n-1;
			int m=0;
			

			for(int i=0;i<b.length&&l<r;i++) {
				if(h.get(b[i])==null||h.get(b[i])==0)continue;
				if(a[l]==b[i]) {
					h.put(b[i],h.get(b[i])-1);
					l++;
				}
				else if(a[r]==b[i]) {
					h.put(b[i],h.get(b[i])-1);
 
					r--;
				}
				else {
					h.put(a[l],h.get(a[l])-1);
					for(int j=l+1;j<r;j++) {
						h.put(a[j],h.get(a[j])-1);

						if(a[j]==b[i]) {
							m=j;
							l=j+1;
							break;
						}
							
					}
				}
				

			}
			
			System.out.println(m);
			
				
 
		}
	}
	
	public static void ThreePairwiseMaximums2() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int z=sc.nextInt();
			if((x==y&&z<=x)||(x==z&&y<=x)||(y==z&&x<=y)) {
				System.out.println("YES");
				System.out.println(Math.max(x,Math.max(y,z))+" "+Math.min(x,Math.min(y,z))+" "+Math.min(x,Math.min(y,z)));
			}
			else {
				System.out.println("NO");
			}
		}
	}
	
	
	public static void RemovingLeaves() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			int k=sc.nextInt();
			int number[]=new int[n];
			LinkedList<Integer>[] vertex = new LinkedList[n];
			for(int i=0;i<n-1;i++) {
				int x=sc.nextInt();
				int y=sc.nextInt();
				number[x-1]++;number[y-1]++;
				if(vertex[x-1]==null) {
					vertex[x-1]=new LinkedList<Integer>();
				}
				vertex[x-1].add(y);
				if(vertex[y-1]==null)
					vertex[y-1]=new LinkedList<Integer>();
				vertex[y-1].add(x);			
			}
			if(n==2) {
				System.out.println(1);
				continue;
			}
			LinkedList<LinkedList<Integer>>nodes=new LinkedList<LinkedList<Integer>>();
			for(int i=0;i<vertex.length;i++) {
				if(vertex[i].size()>=k&&vertex[i].size()!=1) {
					vertex[i].addFirst(i+1);
					nodes.add(vertex[i]);
				}
				}
			
			vertex=null;
			

			

			

			int count=0;
			while(!nodes.isEmpty()) {
				LinkedList <Integer>temp=nodes.remove();
				int num=temp.remove();
				int cf=0;
				int size=temp.size();
				while(!temp.isEmpty()) {
					int v=temp.remove();
					if(number[v-1]==0){
						size--;
						continue;
					}
					if((number[v-1]-1)%k!=0)cf++;
				}
				int c=(size-cf)/k;
				if(c==size) {
					number[num-1]=0;
					

				}
				

				count+=(size-cf)/k;
			}
			System.out.println(count);
		}
	}
	
	public static void RemovingLeaves2() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			int k=sc.nextInt();
			HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
		
			for(int i=0;i<n-1;i++) {
				int x=sc.nextInt();
				int y=sc.nextInt();
				if(tree.get(x)==null)
					tree.put(x,new HashSet<Integer>());
				if(tree.get(y)==null)
					tree.put(y,new HashSet<Integer>());
				tree.get(x).add(y);
				tree.get(y).add(x);

			}
			if(k==1) {
				System.out.println(n-1);
				continue;
			}
			int start=0;
			for(int i=1;i<=n;i++) {
				if(tree.get(i).size()%k==0) {
					start=i;
					break;
				}
			}
			


			

			int[]count= {0};
			

			

			

			if(start==0) {
				start=1;
			}
			RemovingLeaves2Rec(tree,null,start,new Boolean [n],count,k);
			System.out.println(count[0]);

		}
		
	}
	public static void RemovingLeaves2Rec(HashMap<Integer,HashSet<Integer>>tree,Integer parent,Integer vertex,Boolean []nodes, int[]count,int k) {
		if(nodes[vertex-1]!=null)return;
		if(parent!=null&&tree.get(vertex).size()<=1) {
			nodes[vertex-1]=true;
			return ;
		}
		

		int c=0;
		for(Integer edge:tree.get(vertex)) {
			if(parent!=null&&edge==parent)continue;
			if(nodes[edge-1]==null) {
				RemovingLeaves2Rec(tree,vertex,edge,nodes,count, k);
						
			}
		    if(nodes[edge-1]==true) {
				c++;
			}
		}
		int d=c/k;
		int mod=c%k;
		count[0]+=d;
		

		if(mod!=0)
			nodes[vertex-1]=false;
		else
			nodes[vertex-1]=true;
		
		
		
		
		
		
	}
	public static boolean oc(String s) {
		String test="abacaba";
		

		boolean f=true;
		for(int i=0;i<s.length()&&f;i++) {
			if(s.charAt(i)!='?'&&test.charAt(i)!=s.charAt(i))
				f=false;
		}
		return f;
	}
	
	public static int nOc(String s) {
		String test="abacaba";
		int oc=0;
		for(int i=0;i<s.length();i++) {			
            if(i+7<=s.length()&&s.substring(i, i+7).equals(test)){
           	 oc+=1;
            }
		}
		return oc;
		
	}
	
	public static String changeToZ(String s) {
		String m="";
		for(int i=0;i<s.length();i++) {
			if(s.charAt(i)=='?') {
				m=m+'z';
			}
			else
				m=m+s.charAt(i);
		}
		return m;
	}
	
	public static void  AcaciusandString() {
		int t=sc.nextInt();
		sc.nextLine();
		for(int o=0;o<t;o++) {
			int n=sc.nextInt();
			sc.nextLine();
			String s=sc.nextLine();
			String test="abacaba";
			int oc=nOc(s);
			if(oc>1) {
				System.out.println("No");
			}
			else if(oc==1) {
				System.out.println("Yes");
				System.out.println(changeToZ(s));
			}
			else {
				String m="";
				boolean f=false;
				
				for(int i=0;i<s.length();i++) {
					if(i+7<=s.length()&&!f&&oc(s.substring(i,i+7))) {
						int occ=nOc(m+test+s.substring(i+7));
						boolean safe=occ<=1;
						if(safe) {
						    f=true;
						    m=m+test;
						    i+=6;
						    }
						else if(s.charAt(i)=='?'){
							m=m+'z';					
						}
						else {
							m=m+s.charAt(i);
						}
					}
					else if(s.charAt(i)=='?'){
						m=m+'z';					
					}
					else {
						m=m+s.charAt(i);
					}
			
				}
				if(f) {
					System.out.println("Yes");
					System.out.println(m);
				}
				else {
					System.out.println("No");
				}
			}

			
		}
	}
	
	public static void  DubiousCyrpto() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			long l=sc.nextLong();
			long r=sc.nextLong();
			long m=sc.nextLong();
			
			for(long i=l;i<=r;i++) {
				long n=m/i;
				long n1=n+1;
				long n2=n-1;
			

				if(n>0) {
					long mod=m-i*n;
					

					if(l+mod<=r) {
						long t1=i*n+i-(i+mod);
						long t2=i*n+(i+mod)-i;
						if(t1==m) {
							System.out.println(i+" "+i+" "+(long)(i+mod));
							break;
						}
						if(t2==m) {
							System.out.println(i+" "+(long)(i+mod)+" "+i);
							break;
						}
					}
				}
					
				
				if(n1>0) {
					long mod=m-i*n1;
					

					if(Math.abs(mod)<=(r-l)) {
						long t1=i*n1+i-(i+mod);
						long t2=i*n1+(i+mod)-i;
						if(t1==m) {
							System.out.println(i+" "+i+" "+(long)(i+mod));
							break;
						}
						if(t2==m) {
							System.out.println(i+" "+(long)(i+mod)+" "+i);
							break;
						}
					}
					
				}




































				}
				


			
		}
	}


	public static void main(String[] args) {
		

	

		

		

		

		

		

		AcaciusandString();
		

		


	}

}
