import java.io.*;
import java.util.*;

public class CodeForce {
    
    private static String getReg(char a) {
        return "e" + a + "x";
    }
    
    private static String []id0 = new String[256];
    static {
        for(int i = 0; i < id0.length; i++)
            id0[i] = getReg((char)('a' + i));
    }
    
    String []solution = new String[256];
    int sol_len = Integer.MAX_VALUE;
    
    private boolean []arr = new boolean[256];
    private String []sol = new String[256];
    
    private static String getCmd(String reg, int k, String reg2) {
        StringBuilder builder = new StringBuilder();
        builder.append("lea ");
        builder.append(reg);
        builder.append(", [");
        builder.append(k);
        builder.append('*');
        builder.append(reg2);
        builder.append(']');
        return builder.toString();
    }
    
    private static String getCmd(String reg, String reg2, String reg3) {
        StringBuilder builder = new StringBuilder();
        builder.append("lea ");
        builder.append(reg);
        builder.append(", [");
        builder.append(reg2);
        builder.append(" + ");
        builder.append(reg3);
        builder.append(']');
        return builder.toString();
    }
    
    private static String getCmd(String reg, String reg2, int k, String reg3) {
        StringBuilder builder = new StringBuilder();
        builder.append("lea ");
        builder.append(reg);
        builder.append(", [");
        builder.append(reg2);
        builder.append(" + ");
        builder.append(k);
        builder.append('*');
        builder.append(reg3);
        builder.append(']');
        return builder.toString();
    }
    
    private int []map = new int[256];
    
    private boolean solve(int m, int p, int val) {
        if(val > N) return false;
        else if(p > max_len) return false;
        else if(val == N) {
            if(p != max_len) return false;
            sol_len = p;
            for(int i = 0; i < p; i++)
                solution[i] = sol[i];
            return true;
        }
        
        Set<Integer> set = new HashSet<Integer>();
        for(int i = 0; i < m; i++) {
            for(int k = 2; k <= 8; k *= 2) {
                int x = k * map[i];
                if(x > N || arr[x]) continue;
                if(set.contains(x)) continue;
                set.add(x);
                map[m] = x;
                arr[x] = true;
                sol[p] = getCmd(id0[m], k, id0[i]);
                if(solve(m + 1, p + 1, x))
                    return true;
                arr[x] = false;
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 1; k <= 8; k *= 2) {
                    int x = map[i] + k * map[j];
                    if(x > N || arr[x]) continue;
                    if(set.contains(x)) continue;
                    set.add(x);
                    arr[x] = true;
                    map[m] = x;
                    if(k != 1) 
                        sol[p] = getCmd(id0[m], id0[i], k, id0[j]);
                    else 
                        sol[p] = getCmd(id0[m], id0[i], id0[j]);
                    if(solve(m + 1, p + 1, x))
                        return true;
                    arr[x] = false;
                }
            }
        }
        
        return false;
    }
    
    int max_len;
    int N;
    
    private void solve() throws IOException {
        N = nextInt();
        final String [][]ret = {
                { }, 
                { "lea ebx, [2*eax]"}, 
                { "lea ebx, [eax + 2*eax]"}, 
                { "lea ebx, [4*eax]"}, 
                { "lea ebx, [eax + 4*eax]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]"}, 
                { "lea ebx, [8*eax]"}, 
                { "lea ebx, [eax + 8*eax]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*eax]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*eax]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 4*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 2*ebx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 4*ebx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 4*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*ebx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [8*ebx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 4*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 4*ebx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + ebx]", "lea edx, [ecx + 8*ebx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 2*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [8*ebx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 2*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [ebx + 8*ebx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 2*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 2*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [4*eax]", "lea edx, [ecx + 8*eax]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [4*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 2*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 8*eax]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 2*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [ecx + 2*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [edx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [eax + 2*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [4*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 8*ebx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [eax + 8*ebx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 2*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 4*ebx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [eax + 2*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]", "lea eex, [ecx + 2*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [4*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [eax + 8*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 2*ecx]", "lea eex, [edx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 4*eax]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [eax + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 2*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 4*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [eax + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 2*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [edx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [eax + 4*ecx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [eax + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 2*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 2*ecx]", "lea eex, [edx + 4*ecx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [4*ecx]", "lea eex, [edx + 8*ecx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 4*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ebx + 4*ecx]", "lea eex, [edx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [eax + 4*ecx]", "lea eex, [edx + 2*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 8*eax]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [eax + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ebx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [eax + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ebx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ecx + 8*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 2*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 8*ebx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 4*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ecx + 8*eax]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 4*ebx]", "lea eex, [ecx + 4*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [ecx + 2*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ebx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [eax + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 8*eax]", "lea edx, [ebx + 2*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*eax]", "lea edx, [ecx + 8*ebx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [eax + 4*eax]", "lea ecx, [eax + ebx]", "lea edx, [ebx + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [eax + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [eax + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [ebx + 8*ebx]", "lea edx, [ecx + 8*ecx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [eax + 8*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ecx + 4*ecx]", "lea eex, [ecx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 4*ebx]", "lea edx, [ecx + 8*ecx]", "lea eex, [ecx + 2*edx]"}, 
                { "lea ebx, [8*eax]", "lea ecx, [ebx + 2*eax]", "lea edx, [ecx + 2*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 4*ecx]", "lea eex, [eax + 8*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [ebx + 4*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 4*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ebx + 4*ecx]", "lea eex, [ebx + 8*edx]"}, 
                { "lea ebx, [4*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [ebx + 8*ecx]", "lea eex, [edx + 8*edx]"}, 
                { "lea ebx, [eax + 2*eax]", "lea ecx, [eax + 2*ebx]", "lea edx, [ecx + 8*ecx]", "lea eex, [eax + 4*edx]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 2*eax]", "lea edx, [eax + 2*ecx]", "lea eex, [edx + 8*edx]", "lea efx, [ebx + 4*eex]"}, 
                { "lea ebx, [2*eax]", "lea ecx, [eax + 8*ebx]", "lea edx, [ecx + 2*ecx]", "lea eex, [edx + 4*edx]"}
        };
        System.out.println(ret[N-1].length);
        for(int i = 0; i < ret[N-1].length; i++)
            System.out.println(ret[N-1][i]);
        
        
    }
    
    public static void main(String[] args) {
        new CodeForce().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(new FileOutputStream(new File("output.txt")));
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    
    String nextLine() throws IOException {
        return reader.readLine();
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}
