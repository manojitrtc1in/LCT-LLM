#include<cstdio>
#include<cmath>
#include<cstdlib>
#define je 1000000007
int edge[100001][3];
long long gajicyc[2][2][2];
long long gaji[2][2];
long long sv[2][2];
long long svcyc[2][2][2];
long long ans[2];
long long newans[2];
int rev[100001][3];
int already[100001];
int main(){
    int n,m;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&edge[i][0]);
        for(int j=1;j<=edge[i][0];j++){
            scanf("%d",&edge[i][j]);
            rev[abs(edge[i][j])][++rev[abs(edge[i][j])][0]] = i;
        }
    }
    ans[0] = 1; ans[1] = 0;
    for(int i=1;i<=n;i++){
        if(rev[i][0]==0){
            ans[0] = (ans[0] * 2) % je;
            ans[1] = (ans[1] * 2) % je;
        }else if(rev[i][0] == 1){
            if(already[rev[i][1]]) continue;
            gaji[0][0] = 1; gaji[0][1] = 1;
            gaji[1][0] = 0; gaji[1][1] = 0;
            int now_line = rev[i][1];
            int now_pnt = (abs(edge[now_line][1]) != i) + 1;
            while(1){
                

                already[now_line] = 1;
                for(int ii=0;ii<2;ii++){
                    for(int jj=0;jj<2;jj++){
                        sv[ii][jj] = gaji[ii][jj];
                        gaji[ii][jj] = 0;
                    }
                }
                if(edge[now_line][0] == 1){
                    if(edge[now_line][now_pnt]<0){
                        gaji[0][0] = sv[1][0]; gaji[0][1] = sv[0][1];
                        gaji[1][0] = sv[0][0]; gaji[1][1] = sv[1][1];
                    }else{
                        gaji[0][0] = sv[0][0]; gaji[0][1] = sv[1][1];
                        gaji[1][0] = sv[1][0]; gaji[1][1] = sv[0][1];
                    }
                    break;
                }else{
                    if(edge[now_line][now_pnt]<0){
                        if(edge[now_line][3-now_pnt]<0){
                            

                            gaji[0][0] = sv[1][0] + sv[1][1];
                            gaji[0][1] = sv[1][0] + sv[0][1];
                            gaji[1][0] = sv[0][0] + sv[0][1];
                            gaji[1][1] = sv[0][0] + sv[1][1];
                        }else{
                            

                            gaji[0][0] = sv[1][0] + sv[0][1];
                            gaji[0][1] = sv[1][0] + sv[1][1];
                            gaji[1][0] = sv[0][0] + sv[1][1];
                            gaji[1][1] = sv[0][0] + sv[0][1];
                        }
                    }else{
                        if(edge[now_line][3-now_pnt]<0){
                            

                            gaji[0][0] = sv[1][0] + sv[1][1];
                            gaji[0][1] = sv[0][0] + sv[1][1];
                            gaji[1][0] = sv[0][0] + sv[0][1];
                            gaji[1][1] = sv[1][0] + sv[0][1];
                        }else{
                            

                            gaji[0][0] = sv[0][0] + sv[1][1];
                            gaji[0][1] = sv[1][0] + sv[1][1];
                            gaji[1][0] = sv[1][0] + sv[0][1];
                            gaji[1][1] = sv[0][0] + sv[0][1];
                        }
                    }
                    

                    for(int ii=0;ii<2;ii++){
                        for(int jj=0;jj<2;jj++) gaji[ii][jj] %= je;
                    }
                    int next_pnt = abs(edge[now_line][3-now_pnt]);
                    if(rev[next_pnt][0] == 1) break;
                    else{
                        now_line = rev[next_pnt][1+(rev[next_pnt][1] == now_line)];
                        now_pnt = (abs(edge[now_line][1]) != next_pnt) + 1;
                    }
                }
            }
            

            newans[0] = ans[0] * ((gaji[0][0] + gaji[0][1]) % je) + ans[1] * ((gaji[1][0] + gaji[1][1]) % je);
            newans[1] = ans[1] * ((gaji[0][0] + gaji[0][1]) % je) + ans[0] * ((gaji[1][0] + gaji[1][1]) % je);
            ans[0] = newans[0] % je; ans[1] = newans[1] % je;
        }
    }
    

    for(int i=0;i<m;i++){
        if(edge[i][0] == 1){
            if(already[i]) continue;
            if(edge[i][1] < 0){
                gaji[0][0] = 0; gaji[0][1] = 1;
                gaji[1][0] = 1; gaji[1][1] = 0;
            }else{
                gaji[0][0] = 1; gaji[0][1] = 0;
                gaji[1][0] = 0; gaji[1][1] = 1;
            }
            int now_line = 0;
            if(rev[abs(edge[i][1])][1] == i){
                now_line = rev[abs(edge[i][1])][2];
            }else{
                now_line = rev[abs(edge[i][1])][1];
            }
            int now_pnt = (abs(edge[now_line][1]) != abs(edge[i][1])) + 1;
            already[i] = 1;
            while(1){
                

                already[now_line] = 1;
                for(int ii=0;ii<2;ii++){
                    for(int jj=0;jj<2;jj++){
                        sv[ii][jj] = gaji[ii][jj];
                        gaji[ii][jj] = 0;
                    }
                }
                if(edge[now_line][0] == 1){
                    if(edge[now_line][now_pnt]<0){
                        gaji[0][0] = sv[1][0]; gaji[0][1] = sv[0][1];
                        gaji[1][0] = sv[0][0]; gaji[1][1] = sv[1][1];
                    }else{
                        gaji[0][0] = sv[0][0]; gaji[0][1] = sv[1][1];
                        gaji[1][0] = sv[1][0]; gaji[1][1] = sv[0][1];
                    }
                    break;
                }else{
                    if(edge[now_line][now_pnt]<0){
                        if(edge[now_line][3-now_pnt]<0){
                            

                            gaji[0][0] = sv[1][0] + sv[1][1];
                            gaji[0][1] = sv[1][0] + sv[0][1];
                            gaji[1][0] = sv[0][0] + sv[0][1];
                            gaji[1][1] = sv[0][0] + sv[1][1];
                        }else{
                            

                            gaji[0][0] = sv[1][0] + sv[0][1];
                            gaji[0][1] = sv[1][0] + sv[1][1];
                            gaji[1][0] = sv[0][0] + sv[1][1];
                            gaji[1][1] = sv[0][0] + sv[0][1];
                        }
                    }else{
                        if(edge[now_line][3-now_pnt]<0){
                            

                            gaji[0][0] = sv[1][0] + sv[1][1];
                            gaji[0][1] = sv[0][0] + sv[1][1];
                            gaji[1][0] = sv[0][0] + sv[0][1];
                            gaji[1][1] = sv[1][0] + sv[0][1];
                        }else{
                            

                            gaji[0][0] = sv[0][0] + sv[1][1];
                            gaji[0][1] = sv[1][0] + sv[1][1];
                            gaji[1][0] = sv[1][0] + sv[0][1];
                            gaji[1][1] = sv[0][0] + sv[0][1];
                        }
                    }
                    

                    for(int ii=0;ii<2;ii++){
                        for(int jj=0;jj<2;jj++) gaji[ii][jj] %= je;
                    }
                    int next_pnt = abs(edge[now_line][3-now_pnt]);
                    if(rev[next_pnt][0] == 1) break;
                    else{
                        now_line = rev[next_pnt][1+(rev[next_pnt][1] == now_line)];
                        now_pnt = (abs(edge[now_line][1]) != next_pnt) + 1;
                    }
                }
            }
            

            newans[0] = ans[0] * ((gaji[0][0] + gaji[0][1]) % je) + ans[1] * ((gaji[1][0] + gaji[1][1]) % je);
            newans[1] = ans[1] * ((gaji[0][0] + gaji[0][1]) % je) + ans[0] * ((gaji[1][0] + gaji[1][1]) % je);
            ans[0] = newans[0] % je; ans[1] = newans[1] % je;
        }
    }
    

    for(int i=1;i<=n;i++){
        if(rev[i][0]==2 && rev[i][1] == rev[i][2]){
            int now_line = rev[i][1];
            already[now_line] = 1;
            if(edge[now_line][1] == edge[now_line][2]){
                long long tmp = (ans[0] + ans[1]) % je;
                ans[0] = tmp; ans[1] = tmp;
            }else{
                long long tmp = ans[0]; ans[0] = ans[1]; ans[1] = tmp;
                ans[0] = (ans[0] + ans[0]) % je;
                ans[1] = (ans[1] + ans[1]) % je;
            }
        }
    }

    for(int i=0;i<m;i++){
        if(!already[i]){
            

            int start_point = abs(edge[i][1]);
            for(int ii=0;ii<2;ii++){
                for(int jj=0;jj<2;jj++){
                    for(int kk=0;kk<2;kk++){
                        svcyc[ii][jj][kk] = gajicyc[ii][jj][kk];
                        gajicyc[ii][jj][kk] = 0;
                    }
                }
            }
            gajicyc[0][0][0] = 1;
            gajicyc[1][0][1] = 1;
            int now_line = i;
            int now_pnt = 1;
            while(true){
                already[now_line] = 1;
                for(int ii=0;ii<2;ii++){
                    for(int jj=0;jj<2;jj++){
                        for(int kk=0;kk<2;kk++){
                            svcyc[ii][jj][kk] = gajicyc[ii][jj][kk];
                            gajicyc[ii][jj][kk] = 0;
                        }
                    }
                }
                if(start_point == abs(edge[now_line][3-now_pnt])){
                    for(int ii=0;ii<2;ii++){
                        for(int jj=0;jj<2;jj++){
                            for(int kk=0;kk<2;kk++){
                                gajicyc[ii][jj][kk] = svcyc[ii][jj^((ii^(edge[now_line][3-now_pnt]<0))|(kk^(edge[now_line][now_pnt]<0)))][kk];
                            }
                        }
                    }
                    break;
                }else{
                    for(int ii=0;ii<2;ii++){
                        if(edge[now_line][now_pnt]<0){
                            if(edge[now_line][3-now_pnt]<0){
                                

                                gajicyc[ii][0][0] = svcyc[ii][1][0] + svcyc[ii][1][1];
                                gajicyc[ii][0][1] = svcyc[ii][1][0] + svcyc[ii][0][1];
                                gajicyc[ii][1][0] = svcyc[ii][0][0] + svcyc[ii][0][1];
                                gajicyc[ii][1][1] = svcyc[ii][0][0] + svcyc[ii][1][1];
                            }else{
                                

                                gajicyc[ii][0][0] = svcyc[ii][1][0] + svcyc[ii][0][1];
                                gajicyc[ii][0][1] = svcyc[ii][1][0] + svcyc[ii][1][1];
                                gajicyc[ii][1][0] = svcyc[ii][0][0] + svcyc[ii][1][1];
                                gajicyc[ii][1][1] = svcyc[ii][0][0] + svcyc[ii][0][1];
                            }
                        }else{
                            if(edge[now_line][3-now_pnt]<0){
                                

                                gajicyc[ii][0][0] = svcyc[ii][1][0] + svcyc[ii][1][1];
                                gajicyc[ii][0][1] = svcyc[ii][0][0] + svcyc[ii][1][1];
                                gajicyc[ii][1][0] = svcyc[ii][0][0] + svcyc[ii][0][1];
                                gajicyc[ii][1][1] = svcyc[ii][1][0] + svcyc[ii][0][1];
                            }else{
                                

                                gajicyc[ii][0][0] = svcyc[ii][0][0] + svcyc[ii][1][1];
                                gajicyc[ii][0][1] = svcyc[ii][1][0] + svcyc[ii][1][1];
                                gajicyc[ii][1][0] = svcyc[ii][1][0] + svcyc[ii][0][1];
                                gajicyc[ii][1][1] = svcyc[ii][0][0] + svcyc[ii][0][1];
                            }
                        }
                    }
                    for(int ii=0;ii<2;ii++){
                        for(int jj=0;jj<2;jj++){
                            for(int kk=0;kk<2;kk++) gajicyc[ii][jj][kk] %= je;
                        }
                    }
                    int next_pnt = abs(edge[now_line][3-now_pnt]);
                    now_line = rev[next_pnt][1+(rev[next_pnt][1] == now_line)];
                    now_pnt = (abs(edge[now_line][1]) != next_pnt) + 1;
                }
            }
            for(int jj=0;jj<2;jj++){
                for(int kk=0;kk<2;kk++){
                    gajicyc[0][jj][kk] = (gajicyc[0][jj][kk] + gajicyc[1][jj][kk]) % je;
                }
            }
            newans[0] = ans[0] * ((gajicyc[0][0][0] + gajicyc[0][0][1]) % je) + ans[1] * ((gajicyc[0][1][0] + gajicyc[0][1][1]) % je);
            newans[1] = ans[1] * ((gajicyc[0][0][0] + gajicyc[0][0][1]) % je) + ans[0] * ((gajicyc[0][1][0] + gajicyc[0][1][1]) % je);
            ans[0] = newans[0] % je; ans[1] = newans[1] % je;
        }
    }
    printf("%lld",ans[1]);
}
