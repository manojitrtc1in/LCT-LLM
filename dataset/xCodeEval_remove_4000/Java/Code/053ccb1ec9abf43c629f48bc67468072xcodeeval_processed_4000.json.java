

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class d {
	
	 public static void main(String[] args)  {
	
		 Scanner s=new Scanner(System.in);
        String str=s.next();
        pair[] arr=new pair[str.length()];
        for(int i=0;i<str.length();i++) {
        	pair p=new pair(0d,0);
        	arr[i]=p;
        }
        ArrayList<Integer> list=new ArrayList<>();
        ArrayList<Integer> list2=new ArrayList<>();
        double st=0;double e=1;
        for(int i=0;i<str.length();i++) {
        	
        	if(str.charAt(i)=='l') {
        		list.add(i+1);
        	}else {
        		list2.add(i+1);
        	}
        }
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<list2.size();i++) {
        	sb.append(list2.get(i)+"\n");
        }
        for(int i=list.size()-1;i>=0;i--) {
        	sb.append(list.get(i)+"\n");
        }
        
        System.out.println(sb);
       
	 }
}

class pair{
	double a;
	int b;
	public pair(double a,int b) {
		this.a=a;
		this.b=b;
	}
	
}


class comp implements Comparator<pair>{
	public int compare(pair g,pair h) {
		if(g.a>h.a) {
			return 1;
		}else if(g.a<h.a) {
			return -1;
		}else {
			return 0;
		}
	}
}