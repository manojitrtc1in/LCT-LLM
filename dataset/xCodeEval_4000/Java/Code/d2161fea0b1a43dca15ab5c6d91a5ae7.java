import java.util.Scanner;
import java.util.Arrays;
public class Test7   {
    int maxn = 3000;
    

    

    

    

    public static int hash(int front, int a, int b, int c, int d)   {
        if (a < 9) return (front * 2500 + d + (c * (c + 1)) / 2 + (b * (b + 1) * (b + 2)) / 6 + (a * (a + 1) * (a + 2) * (a + 3)) / 24);
        return front * 2500 + d + (c * (c + 1)) / 2 + (b * (b + 1) * (b + 2)) / 6 + (9 * 10 * 11 * 12) / 24 + 1 + 221 * (a - 9);
    }
    public static void main(String Args[])   {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] st = new int[n];
        int[] ed = new int[n];
        for (int i = 0; i < n; i++)   {
            st[i] = sc.nextInt() - 1;
            ed[i] = sc.nextInt() - 1;
        }    
        int sz = 6000000;
        int[] ans = new int[sz];
        int inf = 10000000;
        for (int i = 0; i < sz; i++) ans[i] = inf;
        ans[hash(0, 9, 9, 9, 9)] = 0;
        int[] ep = new int[4];
        int tp = 0; 

        int ft = 0; 

        int rm = 0; 

        int t = 0;
        int[] ord = new int[4];
        for (int front = 0; front <= n; front++)  {
            for (int a = 0; a < 9; a++)
            for (int b = 0; b <= Math.min(a, 9); b++)
            for (int c = 0; c <= b; c++)
            for (int d = 0; d <= c; d++)   {
            ft = front;
            

            if (a < 9 && front > 0)   {
                tp = st[front - 1];
            }    
            else tp = a - 9;
            

            t = ans[hash(front,a,b,c,d)];
            if (t < inf)  {
        

        

        

        

         

         

         

                rm = 0;
                if (a < 9)   {
                    ep[0] = 9 + a; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - a);
                    t++;
                    if (b == a)  {
                        ep[1] = 9;
                        ord[rm] = 1;
                        rm++;
                        t++;
                    }        
                    else ep[1] = b;
                    if (c == a)  {
                        ep[2] = 9;
                        ord[rm] = 2;
                        rm++;
                        t++; 
                    }        
                    else ep[2] = c;
                    if (d == a)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == a)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                else if (front < n) {
                    

                    ord[0] = 0;
                    rm = 1;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }    
                    if (c == 9) {
                        ord[rm] = 2;
                        rm++;
                    }    
                    if (d == 9) {
                        ord[rm] = 3;
                        rm++;
                    }    
                    ep[0] = 9 + st[front];
                    if (b == st[front])   {
                        ord[rm] = 1;
                        rm++;
                        t++;
                        ep[1] = 9;
                    }    
                    else ep[1] = b;
                    if (c == st[front])   {
                        ord[rm] = 2;
                        rm++;
                        t++;
                        ep[2] = 9;
                    }    
                    else ep[2] = c;
                    if (d == st[front])   {
                        ord[rm] = 3;
                        rm++;
                        t++;
                        ep[3] = 9;
                    }    
                    else ep[3] = d;
                    t+= Math.abs(tp - st[front]);   
                    while (rm > 0 && ft < n && st[ft] == st[front]){
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;   
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (b < 9 && b != a)   {
                    ep[0] = 9 + b; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - b);
                    t++;
                    ep[1] = Math.min(a, 9);
                    if (a >= 9) {
                         ord[rm] = 1;
                        rm++;
                    }    

                    if (c == b)  {
                        ep[2] = 9;
                        ord[rm] = 2;
                        rm++;
                        t++;
                    }        
                    else ep[2] = c;
                    if (d == b)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == b)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (c < 9 && c != a && c != b)   {
                    ep[0] = 9 + c; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - c);
                    t++;
                    ep[1] = b;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }                
                    ep[2] = Math.min(a, 9);
                    if (a >= 9) {
                        ord[rm] = 2;
                        rm++;
                    }                     
                    if (d == c)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == c)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (d < 9 && d != a && d != b && d != c)   {
                    ord[rm] = 0;
                    rm++;
                    ep[0] = 9 + d; 

                    t += Math.abs(tp - d);
                    t++;      
                    ep[1] = b;
                    ep[2] = c;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }       
                    if (c == 9) {
                        ord[rm] = 2;
                        rm++;
                    }    
                    ep[3] = Math.min(a, 9);
                    if (a >= 9) {
                        ord[rm] = 3;
                        rm++;
                    }      
                    

                    while (rm > 0 && ft < n && st[ft] == d)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++; 
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                } 
            }    
        }    
            
            for (int b = 0; b <= 9; b++)
            for (int c = 0; c <= b; c++)
            for (int d = 0; d <= c; d++)
            for (int a = 9; a < 18; a++){
            ft = front;
            

            if (a < 9 && front > 0)   {
                tp = st[front - 1];
            }    
            else tp = a - 9;
            

            t = ans[hash(front,a,b,c,d)];
            if (t < inf)  {
        

        

        

        

         

         

         

                rm = 0;
                if (a < 9)   {
                    ep[0] = 9 + a; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - a);
                    t++;
                    if (b == a)  {
                        ep[1] = 9;
                        ord[rm] = 1;
                        rm++;
                        t++;
                    }        
                    else ep[1] = b;
                    if (c == a)  {
                        ep[2] = 9;
                        ord[rm] = 2;
                        rm++;
                        t++; 
                    }        
                    else ep[2] = c;
                    if (d == a)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == a)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                else if (front < n) {
                    

                    ord[0] = 0;
                    rm = 1;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }    
                    if (c == 9) {
                        ord[rm] = 2;
                        rm++;
                    }    
                    if (d == 9) {
                        ord[rm] = 3;
                        rm++;
                    }    
                    ep[0] = 9 + st[front];
                    if (b == st[front])   {
                        ord[rm] = 1;
                        rm++;
                        t++;
                        ep[1] = 9;
                    }    
                    else ep[1] = b;
                    if (c == st[front])   {
                        ord[rm] = 2;
                        rm++;
                        t++;
                        ep[2] = 9;
                    }    
                    else ep[2] = c;
                    if (d == st[front])   {
                        ord[rm] = 3;
                        rm++;
                        t++;
                        ep[3] = 9;
                    }    
                    else ep[3] = d;
                    t+= Math.abs(tp - st[front]);   
                    while (rm > 0 && ft < n && st[ft] == st[front]){
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;   
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (b < 9 && b != a)   {
                    ep[0] = 9 + b; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - b);
                    t++;
                    ep[1] = Math.min(a, 9);
                    if (a >= 9) {
                         ord[rm] = 1;
                        rm++;
                    }    

                    if (c == b)  {
                        ep[2] = 9;
                        ord[rm] = 2;
                        rm++;
                        t++;
                    }        
                    else ep[2] = c;
                    if (d == b)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == b)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (c < 9 && c != a && c != b)   {
                    ep[0] = 9 + c; 

                    ord[rm] = 0;
                    rm++;
                    t += Math.abs(tp - c);
                    t++;
                    ep[1] = b;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }                
                    ep[2] = Math.min(a, 9);
                    if (a >= 9) {
                        ord[rm] = 2;
                        rm++;
                    }                     
                    if (d == c)  {
                        ep[3] = 9;
                        ord[rm] = 3;
                        rm++;
                        t++;
                    }        
                    else ep[3] = d;
                    

                    while (rm > 0 && ft < n && st[ft] == c)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++;
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                }    
                ft = front;
                t = ans[hash(front,a,b,c,d)];
                rm = 0;
                if (d < 9 && d != a && d != b && d != c)   {
                    ord[rm] = 0;
                    rm++;
                    ep[0] = 9 + d; 

                    t += Math.abs(tp - d);
                    t++;      
                    ep[1] = b;
                    ep[2] = c;
                    if (b == 9) {
                        ord[rm] = 1;
                        rm++;
                    }       
                    if (c == 9) {
                        ord[rm] = 2;
                        rm++;
                    }    
                    ep[3] = Math.min(a, 9);
                    if (a >= 9) {
                        ord[rm] = 3;
                        rm++;
                    }      
                    

                    while (rm > 0 && ft < n && st[ft] == d)   {
                        rm--;
                        ep[ord[rm]] = ed[ft];
                        ft++;
                        t++; 
                    }    
                    Arrays.sort(ep);
                    ans[hash(ft, ep[3], ep[2], ep[1], ep[0])] = Math.min(ans[hash(ft, ep[3], ep[2], ep[1], ep[0])], t);
                } 
            }    
        }    
        }
        int ansmin = inf;
        for (int j = 9; j < 18; j++)   {
            if (ans[hash(n, j, 9, 9, 9)] < ansmin) ansmin = ans[hash(n, j, 9, 9, 9)];
        }    
        System.out.println(ansmin);
    }    
}    