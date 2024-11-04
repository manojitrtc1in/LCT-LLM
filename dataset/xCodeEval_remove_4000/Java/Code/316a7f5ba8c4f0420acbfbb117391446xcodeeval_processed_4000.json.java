import java.awt.FlowLayout;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class Solution {
	
	private BufferedReader cin;
	private PrintWriter cout; 
	private StringTokenizer tokenizer;
	
	protected final static int INF = 1000 * 1000 * 1000; 

	
	private int n; 

	private int m; 

	
	public int getN() {
		return n;
	}
	
	protected void id11() {
		++n;
	}
	
	public int getM() {
		return m;
	}
	
	protected void id8() {
		++m;
	}
	
	protected void id18() {
		--m;
	}
	
	private int flowNetwork = 0;
	private int costNetwork = 0;
	
	public int id17() {
		return flowNetwork;
	}
	
	public int id9() {
		return costNetwork;
	}
	
	

	class id2 {
		private int u; 

		private int v; 

		private int cost; 

		private int cap; 

		private int flow; 

		
		private int back; 

		
		private int idx; 

		
		public int getU() {
			return u;
		}
		
		public int getV() {
			return v;
		}
		
		public int getCost() {
			return cost;
		}
		
		public int getCap() {
			return cap;
		}
		
		public int getFlow() {
			return flow;
		}
		
		

		public void addFlow(int val) {
			flow += val;
		}
		
		

		public void subFlow(int val) {
			flow -= val;
		}
		
		public int getBack() {
			return back;
		}
		
		

		public int getCP() {
			return cap - flow;
		}
		
		
		public id2(int u, int v, int back, int idx) {
			this.u = u;
			this.v = v;
			cost = 1;
			cap = 1;
			flow = 0;
			
			this.back = back; 
			this.idx = idx;
		}
		
		public id2(int u, int v, int cost, int cap, int back, int idx) {
			this.u = u;
			this.v = v;
			this.cost = cost;
			this.cap = cap;
			flow = 0;
			
			this.back = back;
			this.idx = idx;
		}
		
		

		public void setCost(int cost) {
			this.cost = cost;
		}
		
		public void clearFlow() {
			this.flow = 0;
		}
		
		public void id7() {
			System.out.print("[(" + u + ", " + v + ") cost = " + cost + " cap = " + cap + " flow = " + flow + " idxBack = " + back + " idx = " + idx + "]");
		}
	}
	
	

	

	class Vertex implements Comparable<Vertex> {
	    private int v; 

	    private int weight; 

	    
	    public int getV() {
	        return v;
	    }
	    
	    public int getWeight() {
	        return weight;
	    }
	    
	    

	    public Vertex(int v, int weight) {
	        this.v = v;
	        this.weight = weight;
	    }
	    
	    

	    public int compareTo(Vertex vertex) {
	        if (weight != vertex.getWeight()) {
	            return Integer.compare(weight, vertex.getWeight());
	        }
	        return Integer.compare(v, vertex.getV());
	    }
	    
	    @Override
	    public int hashCode() {
	        return weight * 57 + v;
	    }
	    
	    @Override
	    public boolean equals(Object arg0) {
	        if (arg0 == null) {
	            return false;
	        }
	        if (this == arg0) {
	            return true;
	        }
	        Vertex vertex = (Vertex) arg0;
	        return v == vertex.getV() && weight == vertex.getWeight();
	    }
	}
	
	private int sourse; 

	private int sink; 

	
	private ArrayList<ArrayList<id2>> adjNet; 

	
	private ArrayList<Integer> dist = new ArrayList<Integer>(); 

	private ArrayList<Integer> pred = new ArrayList<Integer>(); 

	private ArrayList<Integer> id3 = new ArrayList<Integer>(); 

	
	private ArrayList<Integer> phi = new ArrayList<Integer>(); 

	
	private Set<Vertex> queue = new TreeSet<Vertex>(); 

	
	public int id10() {
		return sourse;
	}
	
	public void id5(int sourse) {
		if (sourse < 0 || sourse >= getN()) {
			System.err.println("Индекс источники " + sourse + " превышает количество вершин " + getN() + " в транспортной сети");
			this.sourse = 0;
		}
		this.sourse = sourse;
	}
	
	public int getSink() {
		return sink;
	}
	
	public void setSink(int sink) {
		if (sink < 0 || sink >= getN()) {
			System.err.println("Индекс источники " + sink + " превышает количество вершин " + getN() + " в транспортной сети");
			this.sink = 0;
		}
		this.sink = sink;
	}
	
	public ArrayList<ArrayList<id2>> id1() {
		return adjNet;
	}
	
	

	public Solution() {
		adjNet = new ArrayList<ArrayList<id2>>();
	}
	
	

	public void id15() {
		id11();
		adjNet.add(new ArrayList<Solution.id2>());
		
		dist.add(INF);
		pred.add(-1);
		id3.add(-1);
		phi.add(0);
	}
	
	

	public void id13(int u, int v, int idx) {
		if (u < 0 || u >= getN()) {
			System.err.println("Индекс начала " + u + " дуги превышает количество вершин " + getN() + " в графе");
			return;
		}
		if (v < 0 || v >= getN()) {
			System.err.println("Индекс конца " + v + " дуги превышает количество вершин " + getN() + " в графе");
			return;
		}
		id8();
		id2 rib = new id2(u, v, adjNet.get(v).size(), idx);
		id2 ribBack = new id2(v, u, -1, 0, adjNet.get(u).size(), idx);
		
		adjNet.get(u).add(rib);
		adjNet.get(v).add(ribBack);
	}
	
	

	public void id13(int u, int v, int cost, int cap, int idx) {
		if (u < 0 || u >= getN()) {
			System.err.println("Индекс начала " + u + " дуги превышает количество вершин " + getN() + " в графе");
			return;
		}
		if (v < 0 || v >= getN()) {
			System.err.println("Индекс конца " + v + " дуги превышает количество вершин " + getN() + " в графе");
			return;
		}
		id8();
		id2 rib = new id2(u, v, cost, cap, adjNet.get(v).size(), idx);
		id2 ribBack = new id2(v, u, -cost, 0, adjNet.get(u).size(), idx);
		
		adjNet.get(u).add(rib);
		adjNet.get(v).add(ribBack);
	}
	
	

	public boolean id19(int u, int v, int cost) {
		if (u < 0 || u >= getN()) {
			System.err.println("Индекс начала " + u + " дуги превышает количество вершин " + getN() + " в графе");
			return false;
		}
		if (v < 0 || v >= getN()) {
			System.err.println("Индекс конца " + v + " дуги превышает количество вершин " + getN() + " в графе");
			return false;
		}
		

		int idxv = -1;
		for (int i = 0; i < id1().get(u).size(); ++i) {
			if (id1().get(u).get(i).getV() == v) {
				idxv = i;
				break;
			}
		}
		if (idxv == -1) {
			return false;
		}
		int idxBack = id1().get(u).get(idxv).getBack();
		
		id1().get(u).get(idxv).setCost(cost);
		id1().get(v).get(idxBack).setCost(-cost);
		
		return true;
	}
	
	

	public void clearFlow() {
		for (int u = 0; u < getN(); ++u) {
			for (int i = 0; i < id1().get(u).size(); ++i) {
				id1().get(u).get(i).clearFlow();
			}
		}
	}
	
	

	private void calcPhi() {
		

		Collections.fill(phi, INF);
		phi.set(sourse, 0);
		for (int k = 1; k < getN(); ++k)	{
			boolean id6 = false;
			for (int u = 0; u < getN(); ++u)
				if (phi.get(u) != INF)
					for (int i = 0; i < adjNet.get(u).size(); ++i) {
						int v = adjNet.get(u).get(i).getV(); 

						int curCost = adjNet.get(u).get(i).getCost(); 

						int curCP = adjNet.get(u).get(i).getCP(); 

						if (curCP > 0 && phi.get(v) > phi.get(u) + curCost) {
							phi.set(v, phi.get(u) + curCost);
							pred.set(v, u);
							id3.set(v, i);
							id6 = true;
						}
					}
			if (!id6) break;
		}
	}
	
	

    private void id0() { 
        dist.set(sourse, 0); 

        queue.add(new Vertex(sourse, dist.get(sourse)));
        while (!queue.isEmpty()) {
        	
        	
        	
            

            int u = queue.iterator().next().getV();
            int distU = queue.iterator().next().getWeight();
            queue.remove(queue.iterator().next());
            

            for (int i = 0; i < id1().get(u).size(); ++i) {
            	if (id1().get(u).get(i).getCP() == 0) {
            		continue;
            	}
                int v = id1().get(u).get(i).getV();
                int costV = id1().get(u).get(i).getCost();
                

                if (dist.get(v) > distU + costV + phi.get(v) - phi.get(u)) {
                    queue.remove(new Vertex(v, dist.get(v)));
                    dist.set(v, distU + costV + phi.get(v) - phi.get(u));
                    pred.set(v, u);
                    id3.set(v, i);
                    queue.add(new Vertex(v, dist.get(v)));
                }
            }
        }
    }
	
    

  	public void id4() {
  		flowNetwork = 0; 

  		costNetwork = 0;
  		while (true) {	
  			

  			Collections.fill(dist, INF);
  			Collections.fill(pred, -1);
  			Collections.fill(id3, -1);
  			
  			dist.set(sourse, 0);
  			for (int k = 1; k < getN(); ++k)	{
  				boolean id6 = false;
  				for (int u = 0; u < getN(); ++u)
  					if (dist.get(u) != INF)
  						for (int i = 0; i < adjNet.get(u).size(); ++i) {
  							int v = adjNet.get(u).get(i).getV(); 

  							int curCost = adjNet.get(u).get(i).getCost(); 

  							int curCP = adjNet.get(u).get(i).getCP(); 

  							if (curCP > 0 && dist.get(v) > dist.get(u) + curCost) {
  								dist.set(v, dist.get(u) + curCost);
  								pred.set(v, u);
  								id3.set(v, i);
  								id6 = true;
  							}
  						}
  				if (!id6) break;
  			}
  			

  			if (dist.get(sink) == INF) {
  				break;
  			}
  			
  			

  			int curFlow = INF;
  			for (int v = sink; v != sourse; v = pred.get(v)) {
  				int predV = pred.get(v);  
  				int id14 = id3.get(v);
  				curFlow = Math.min(curFlow, adjNet.get(predV).get(id14).getCP());
  			}
  			

  			for (int v = sink; v != sourse; v = pred.get(v)) {
  				int predV = pred.get(v);  
  				int id14 = id3.get(v);
  				int back = adjNet.get(predV).get(id14).getBack();
  				
  				adjNet.get(predV).get(id14).addFlow(curFlow);
  				adjNet.get(v).get(back).subFlow(curFlow);
  				
  				costNetwork += curFlow * adjNet.get(predV).get(id14).getCost();
  			}
  			flowNetwork += curFlow;
  		}
  	}
    
	

	public void id16(int maxFlow) {
		flowNetwork = 0; 

		costNetwork = 0; 
		
		calcPhi();
		
		
		
		if (phi.get(sink) == INF) {
			return;
		}
		
		while (flowNetwork < maxFlow) {	
			

			Collections.fill(dist, INF);
			Collections.fill(pred, -1);
			Collections.fill(id3, -1);
			
			id0();
			
			

			for (int v = 0; v < getN(); ++v) {
				phi.set(v, dist.get(v) != INF ? dist.get(v) : dist.get(sink));
			}
			
			

			if (dist.get(sink) == INF) {
				break;
			}
			
			

			int curFlow = INF;
			for (int v = sink; v != sourse; v = pred.get(v)) {
				int predV = pred.get(v);  
				int id14 = id3.get(v);
				curFlow = Math.min(curFlow, adjNet.get(predV).get(id14).getCP());
			}
			

			for (int v = sink; v != sourse; v = pred.get(v)) {
				int predV = pred.get(v);  
				int id14 = id3.get(v);
				int back = adjNet.get(predV).get(id14).getBack();
				
				adjNet.get(predV).get(id14).addFlow(curFlow);
				adjNet.get(v).get(back).subFlow(curFlow);
				
				costNetwork += curFlow * adjNet.get(predV).get(id14).getCost();
			}
			flowNetwork += curFlow;
		}
	}
	
	public void printNetwork() {
		System.out.println("n = " + getN() + " m = " + getM());
		System.out.println("sourse = " + id10() + " sink = " + getSink());
		for (int u = 0; u < getN(); ++u) {
			System.out.print(u + ": ");
			for (int i = 0; i < id1().get(u).size(); ++i) {
				id1().get(u).get(i).id7();
			}
			System.out.println();
		}
	}
	
	public void id12() {
		System.out.println("n = " + getN() + " m = " + getM());
		System.out.println("sourse = " + id10() + " sink = " + getSink());
		for (int u = 0; u < getN(); ++u) {
			System.out.print(u + ": ");
			for (int i = 0; i < id1().get(u).size(); ++i) {
				if (id1().get(u).get(i).getFlow() > 0) {
					id1().get(u).get(i).id7();
				}
			}
			System.out.println();
		}
	}
	
	public void printWay(PrintWriter cout) {
		for (int ii = 0; ii < flowNetwork; ++ii) {
			ArrayList<Integer> way = new ArrayList<Integer>();
			for (int v = sourse; v != sink; ) {
				for (int i = 0; i < adjNet.get(v).size(); ++i) {
					if (adjNet.get(v).get(i).getFlow() == 1) {
						adjNet.get(v).get(i).subFlow(1);
						way.add(adjNet.get(v).get(i).idx);
						v = adjNet.get(v).get(i).getV();
						break;
					}
				}
			}
			cout.print(way.size() + " ");
			for (int i = 0; i < way.size(); ++i) {
				cout.print(way.get(i) + " ");
			}
			cout.println();
		}
	}
	
	String t = null;
	int cnt = 0;
	int a[] = null;
	String s[] = null;
	
	

    private void run() throws IOException {
        cin = new BufferedReader(new InputStreamReader(System.in));
        cout = new PrintWriter(System.out);
        tokenizer = new StringTokenizer(cin.readLine());
        
        t = tokenizer.nextToken();
        
        tokenizer = new StringTokenizer(cin.readLine());
        cnt = Integer.parseInt(tokenizer.nextToken());
        
        a = new int[cnt];
        s = new String[cnt];
        
        for (int i = 0; i < cnt; ++i) {
        	tokenizer = new StringTokenizer(cin.readLine());
        	s[i] = tokenizer.nextToken();
        	a[i] = Integer.parseInt(tokenizer.nextToken());
        }
        
        int idx = 0;
        
        

        id15();
        sourse = 0;
        
        

        for (int v = 0; v < cnt; ++v) {
        	id15();
        }
        for (int v = 1; v <= cnt; ++v) {
        	id13(sourse, v, v, a[v - 1], idx++);
        }
         
        

        for (int i = 0; i < cnt; ++i) {
        	

        	int letter[] = new int[26];
        	Arrays.fill(letter, 0);
        	for (int j = 0; j < s[i].length(); ++j) {
        		letter[s[i].charAt(j) - 'a']++;
        	}
        	for (int j = 0; j < 26; ++j) {
        		id15();
        	}
        	for (int j = 0; j < 26; ++j) {
        		id13(i + 1, 1 + cnt + j, 0, letter[j], idx++);
        	}
        }
        
        

        

    	int letter[] = new int[26];
    	for (int j = 0; j < t.length(); ++j) {
    		letter[t.charAt(j) - 'a']++;
    	}
    	for (int i = 0; i < 26; ++i) {
    		id15();
    	}
    	id15();
    	sink = getN() - 1;
    	
    	for (int i = 0; i < cnt; ++i) {
    		for (int j = 0; j < 26; ++j) {
    			id13(1 + cnt + (i * 26) + j, 1 + cnt + (cnt * 26) + j, 0, INF, ++idx);
    		}
    	}
    	for (int j = 0; j < 26; ++j) {
    		id13(1 + cnt + (cnt * 26) + j, sink, 0, letter[j], ++idx);
    	}
    	
    	id4();
    	
    	if (flowNetwork < t.length()) {
    		cout.println("-1");
    	} else {
    		cout.println(costNetwork);
    	}
    	
        cin.close();
        cout.close();
        
    }
	
	public static void main(String[] args) throws IOException {
		Solution solution = new Solution();
		solution.run();
	}
}