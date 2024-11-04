import java.io.*;
import java.util.*;

public class CF1602B {
























































































































































































































































































































































































public static void main(String[] args) throws IOException {




    BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in));

    String s = br.readLine();
    StringTokenizer st = new StringTokenizer(s);


    int t = Integer.parseInt(st.nextToken());
    for (int i = 0; i < t; i++) {
        ArrayList<Integer[]> order = new ArrayList<>();
        HashMap<Integer, ArrayList<Integer>> d = new HashMap<>();
        HashMap<Integer, Integer> freq = new HashMap<>();
        HashMap<Integer, ArrayList<Integer>> indices = new HashMap<>();

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Integer[] array = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < n; j++) {
            int val = Integer.parseInt(st.nextToken());
            freq.putIfAbsent(val, 0);
            freq.computeIfPresent(val, (z, x) -> x + 1);
            array[j]=val;
        }
        st = new StringTokenizer(br.readLine());
        int q = Integer.parseInt(st.nextToken());
        int max = 0;
        HashSet<Integer> steps=new HashSet<>();
        for (int j = 0; j < q; j++) {
            st = new StringTokenizer(br.readLine());
            int index = Integer.parseInt(st.nextToken());
            int iter = Integer.parseInt(st.nextToken());
            steps.add(iter);
            order.add(new Integer[]{index-1, iter});
            max = Math.max(iter, max);
        }
        ArrayList<Integer> stps=new ArrayList<>(steps);
        stps.sort(Integer::compareTo);
        HashMap<Integer,Integer[]> ret=getValue(array,n,freq,0,stps,new HashMap<>());
        for (Integer[] pair :
                order) {
            if (pair[1]==0)
                System.out.println(array[pair[0]]);

            else {
                if (ret.containsKey(pair[1])) {
                    Integer so = ret.get(pair[1])[pair[0]];
                    if (so == null)
                        System.out.println(0);
                    else
                        System.out.println(so);
                } else {
                    Integer so = ret.get(-1)[pair[0]];
                    if (so == null)
                        System.out.println(0);
                    else
                        System.out.println(so);
                }
            }
        }
    }
}
    public static HashMap<Integer,Integer[]> getValue(Integer[] vals,int siz,HashMap<Integer,Integer> freq,int step,ArrayList<Integer> steps,HashMap<Integer,Integer[]> ret) {


















        if (steps.get(0)==step){
            ret.put(step,vals);




















            steps.remove(0);
        }
        if (steps.size()==0) {
            return ret;
        }
        HashMap<Integer,Integer> newFreq=new HashMap<>();
        boolean changed=false;
        for (Integer distinct:
                freq.keySet()) {
            int val = freq.get(distinct);
            if (!changed && val!=distinct)
                changed=true;
            newFreq.putIfAbsent(val, 0);
            newFreq.computeIfPresent(val,(z,x)->x+val);
        }
        Integer[] newvals=new Integer[vals.length];
        for (int i = 0; i < vals.length; i++) {
            newvals[i]=freq.get(vals[i]);
        }
        if (!changed) {
            ret.put(-1,newvals);
            return ret;
        }
        return getValue(newvals,siz,newFreq,step+1,steps,ret);
    }
}
