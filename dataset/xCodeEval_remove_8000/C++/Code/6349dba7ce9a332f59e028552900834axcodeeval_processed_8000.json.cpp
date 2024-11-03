


using namespace std;



typedef pair<int,int> ii;
typedef long long LL;

const int MAX = 8*30;
const int MIN = INT_MIN;

int dp[10][MAX*4][MAX*4];
int btrck[10][MAX*4][MAX*4];

vector<ii> cur;
int mini = INT_MAX;
int low = 0, high = MAX*4;
int rec(int left, int sx, int sy){
    if(left == 0) return (sx == 0 and sy == 0) ? 0 : MIN;

    int &ret = dp[left][sx + 2*MAX][sy + 2*MAX], &bt = btrck[left][sx + 2*MAX][sy + 2*MAX];
    if(ret != -1) return ret;

    REP(i, 0, cur.size()){
        

        int x = cur[i].first, y = cur[i].second;
        int here = rec(left - 1, sx - x, sy - y);
        if(here != MIN and ret < here + x*x + y*y) ret = here + x*x + y*y, bt = i;
    }
    return ret;
}

bool last(int x, int y, int r){
    if(x*x + y*y > r) return false;
    if((x+1)*(x+1) + y*y <= r and (x-1)*(x-1) + y*y <= r) return false;
    swap(x, y);
    if((x+1)*(x+1) + y*y <= r and (x-1)*(x-1) + y*y <= r) return false;
    return true;
}

void dfs(int n, int sx, int sy){
    if(n == 0) return;
    int here = btrck[n][sx + 2*MAX][sy + 2*MAX];
    printf("%d %d\\n", cur[here].first, cur[here].second);
    dfs(n-1, sx - cur[here].first, sy - cur[here].second);
}

void solve(int n, int r){

    memset(dp, -1, sizeof dp);
    cur.clear();
    REP(i, -r, r+1) REP(j, -r, r+1) if(last(i, j, r*r))
        cur.push_back(ii(i, j));

    int ans = 0;
    REP(sx, -n*r, n*r+1) REP(sy, -n*r, n*r + 1) ans = max(ans, n*rec(n, sx, sy) - sx*sx - sy*sy);
    printf("yolo[%d][%d]=\"%d\\n", n, r, ans);

    REP(sx, -n*r, n*r + 1) REP(sy, -n*r, n*r + 1){
        int here = n*rec(n, sx, sy) - sx*sx - sy*sy;
        if(here == ans) { dfs(n, sx, sy);
            printf("\";");
            cout << endl;
            return ;
        }
    }
}
string yolo[10][31];
void init();
int main(){
    init();
    int n,m;
    cin >> n >> m;
    cout << yolo[n][m] << endl;

    return 0;
}


void init(){
    yolo[1][1]="0\n-1 0\n";
    yolo[1][2]="0\n-2 0\n";
    yolo[1][3]="0\n-3 0\n";
    yolo[1][4]="0\n-4 0\n";
    yolo[1][5]="0\n-5 0\n";
    yolo[1][6]="0\n-6 0\n";
    yolo[1][7]="0\n-7 0\n";
    yolo[1][8]="0\n-8 0\n";
    yolo[1][9]="0\n-9 0\n";
    yolo[1][10]="0\n-10 0\n";
    yolo[1][11]="0\n-11 0\n";
    yolo[1][12]="0\n-12 0\n";
    yolo[1][13]="0\n-13 0\n";
    yolo[1][14]="0\n-14 0\n";
    yolo[1][15]="0\n-15 0\n";
    yolo[1][16]="0\n-16 0\n";
    yolo[1][17]="0\n-17 0\n";
    yolo[1][18]="0\n-18 0\n";
    yolo[1][19]="0\n-19 0\n";
    yolo[1][20]="0\n-20 0\n";
    yolo[1][21]="0\n-21 0\n";
    yolo[1][22]="0\n-22 0\n";
    yolo[1][23]="0\n-23 0\n";
    yolo[1][24]="0\n-24 0\n";
    yolo[1][25]="0\n-25 0\n";
    yolo[1][26]="0\n-26 0\n";
    yolo[1][27]="0\n-27 0\n";
    yolo[1][28]="0\n-28 0\n";
    yolo[1][29]="0\n-29 0\n";
    yolo[1][30]="0\n-30 0\n";
    yolo[2][1]="4\n-1 0\n1 0\n";
    yolo[2][2]="16\n-2 0\n2 0\n";
    yolo[2][3]="36\n-3 0\n3 0\n";
    yolo[2][4]="64\n-4 0\n4 0\n";
    yolo[2][5]="100\n-5 0\n5 0\n";
    yolo[2][6]="144\n-6 0\n6 0\n";
    yolo[2][7]="196\n-7 0\n7 0\n";
    yolo[2][8]="256\n-8 0\n8 0\n";
    yolo[2][9]="324\n-9 0\n9 0\n";
    yolo[2][10]="400\n-10 0\n10 0\n";
    yolo[2][11]="484\n-11 0\n11 0\n";
    yolo[2][12]="576\n-12 0\n12 0\n";
    yolo[2][13]="676\n-13 0\n13 0\n";
    yolo[2][14]="784\n-14 0\n14 0\n";
    yolo[2][15]="900\n-15 0\n15 0\n";
    yolo[2][16]="1024\n-16 0\n16 0\n";
    yolo[2][17]="1156\n-17 0\n17 0\n";
    yolo[2][18]="1296\n-18 0\n18 0\n";
    yolo[2][19]="1444\n-19 0\n19 0\n";
    yolo[2][20]="1600\n-20 0\n20 0\n";
    yolo[2][21]="1764\n-21 0\n21 0\n";
    yolo[2][22]="1936\n-22 0\n22 0\n";
    yolo[2][23]="2116\n-23 0\n23 0\n";
    yolo[2][24]="2304\n-24 0\n24 0\n";
    yolo[2][25]="2500\n-25 0\n25 0\n";
    yolo[2][26]="2704\n-26 0\n26 0\n";
    yolo[2][27]="2916\n-27 0\n27 0\n";
    yolo[2][28]="3136\n-28 0\n28 0\n";
    yolo[2][29]="3364\n-29 0\n29 0\n";
    yolo[2][30]="3600\n-30 0\n30 0\n";
    yolo[3][1]="8\n-1 0\n-1 0\n1 0\n";
    yolo[3][2]="32\n-2 0\n-2 0\n2 0\n";
    yolo[3][3]="76\n-3 0\n0 -3\n2 2\n";
    yolo[3][4]="130\n-4 0\n0 -4\n2 3\n";
    yolo[3][5]="224\n-3 -4\n-3 4\n5 0\n";
    yolo[3][6]="312\n-6 0\n3 -5\n3 5\n";
    yolo[3][7]="416\n-7 0\n3 -6\n3 6\n";
    yolo[3][8]="554\n-8 0\n0 -8\n5 6\n";
    yolo[3][9]="722\n-9 0\n4 -8\n4 8\n";
    yolo[3][10]="896\n-6 -8\n-6 8\n10 0\n";
    yolo[3][11]="1064\n-6 -9\n-6 9\n11 0\n";
    yolo[3][12]="1248\n-12 0\n6 -10\n6 10\n";
    yolo[3][13]="1512\n-13 0\n5 -12\n5 12\n";
    yolo[3][14]="1746\n-14 0\n7 -12\n7 12\n";
    yolo[3][15]="2016\n-9 -12\n-9 12\n15 0\n";
    yolo[3][16]="2264\n-9 -13\n-9 13\n16 0\n";
    yolo[3][17]="2600\n-17 0\n8 -15\n8 15\n";
    yolo[3][18]="2888\n-18 0\n8 -16\n8 16\n";
    yolo[3][19]="3218\n-19 0\n6 -18\n10 16\n";
    yolo[3][20]="3584\n-12 -16\n-12 16\n20 0\n";
    yolo[3][21]="3912\n-21 0\n6 -20\n12 17\n";
    yolo[3][22]="4344\n-22 0\n11 -19\n11 19\n";
    yolo[3][23]="4712\n-23 0\n11 -20\n11 20\n";
    yolo[3][24]="5138\n-13 -20\n-13 20\n24 0\n";
    yolo[3][25]="5612\n-20 15\n-7 -24\n24 7\n";
    yolo[3][26]="6062\n-26 0\n12 -23\n12 23\n";
    yolo[3][27]="6536\n-14 -23\n-14 23\n27 0\n";
    yolo[3][28]="6984\n-28 0\n14 -24\n14 24\n";
    yolo[3][29]="7520\n-28 -7\n7 28\n20 -21\n";
    yolo[3][30]="8084\n-27 -13\n0 30\n24 -18\n";
    yolo[4][1]="16\n-1 0\n-1 0\n1 0\n1 0\n";
    yolo[4][2]="64\n-2 0\n-2 0\n2 0\n2 0\n";
    yolo[4][3]="144\n-3 0\n-3 0\n3 0\n3 0\n";
    yolo[4][4]="256\n-4 0\n-4 0\n4 0\n4 0\n";
    yolo[4][5]="400\n-5 0\n-5 0\n5 0\n5 0\n";
    yolo[4][6]="576\n-6 0\n-6 0\n6 0\n6 0\n";
    yolo[4][7]="784\n-7 0\n-7 0\n7 0\n7 0\n";
    yolo[4][8]="1024\n-8 0\n-8 0\n8 0\n8 0\n";
    yolo[4][9]="1296\n-9 0\n-9 0\n9 0\n9 0\n";
    yolo[4][10]="1600\n-10 0\n-10 0\n10 0\n10 0\n";
    yolo[4][11]="1936\n-11 0\n-11 0\n11 0\n11 0\n";
    yolo[4][12]="2304\n-12 0\n-12 0\n12 0\n12 0\n";
    yolo[4][13]="2704\n-13 0\n-13 0\n13 0\n13 0\n";
    yolo[4][14]="3136\n-14 0\n-14 0\n14 0\n14 0\n";
    yolo[4][15]="3600\n-15 0\n-15 0\n15 0\n15 0\n";
    yolo[4][16]="4096\n-16 0\n-16 0\n16 0\n16 0\n";
    yolo[4][17]="4624\n-17 0\n-17 0\n17 0\n17 0\n";
    yolo[4][18]="5184\n-18 0\n-18 0\n18 0\n18 0\n";
    yolo[4][19]="5776\n-19 0\n-19 0\n19 0\n19 0\n";
    yolo[4][20]="6400\n-20 0\n-20 0\n20 0\n20 0\n";
    yolo[4][21]="7056\n-21 0\n-21 0\n21 0\n21 0\n";
    yolo[4][22]="7744\n-22 0\n-22 0\n22 0\n22 0\n";
    yolo[4][23]="8464\n-23 0\n-23 0\n23 0\n23 0\n";
    yolo[4][24]="9216\n-24 0\n-24 0\n24 0\n24 0\n";
    yolo[4][25]="10000\n-25 0\n-25 0\n25 0\n25 0\n";
    yolo[4][26]="10816\n-26 0\n-26 0\n26 0\n26 0\n";
    yolo[4][27]="11664\n-27 0\n-27 0\n27 0\n27 0\n";
    yolo[4][28]="12544\n-28 0\n-28 0\n28 0\n28 0\n";
    yolo[4][29]="13456\n-29 0\n-29 0\n29 0\n29 0\n";
    yolo[4][30]="14400\n-30 0\n-30 0\n30 0\n30 0\n";
    yolo[5][1]="24\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n";
    yolo[5][2]="96\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n";
    yolo[5][3]="218\n-3 0\n-3 0\n0 -3\n2 2\n3 0\n";
    yolo[5][4]="384\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n";
    yolo[5][5]="624\n-5 0\n-3 -4\n-3 4\n5 0\n5 0\n";
    yolo[5][6]="880\n-6 0\n-6 0\n0 -6\n3 5\n6 0\n";
    yolo[5][7]="1188\n-7 0\n-7 0\n0 -7\n3 6\n7 0\n";
    yolo[5][8]="1572\n-8 0\n-8 0\n0 -8\n5 6\n8 0\n";
    yolo[5][9]="2014\n-9 0\n-9 0\n4 -8\n4 8\n9 0\n";
    yolo[5][10]="2496\n-10 0\n-6 -8\n-6 8\n10 0\n10 0\n";
    yolo[5][11]="2984\n-11 0\n-6 -9\n-6 9\n11 0\n11 0\n";
    yolo[5][12]="3520\n-12 0\n-12 0\n0 -12\n6 10\n12 0\n";
    yolo[5][13]="4224\n-12 -5\n-12 5\n5 -12\n5 12\n13 0\n";
    yolo[5][14]="4870\n-14 0\n-14 0\n5 -13\n7 12\n14 0\n";
    yolo[5][15]="5616\n-15 0\n-9 -12\n-9 12\n15 0\n15 0\n";
    yolo[5][16]="6336\n-16 0\n-9 -13\n-9 13\n16 0\n16 0\n";
    yolo[5][17]="7224\n-17 0\n-17 0\n8 -15\n8 15\n17 0\n";
    yolo[5][18]="8056\n-18 0\n-18 0\n8 -16\n8 16\n18 0\n";
    yolo[5][19]="9008\n-19 0\n-18 6\n0 -19\n18 6\n18 6\n";
    yolo[5][20]="9984\n-20 0\n-12 -16\n-12 16\n20 0\n20 0\n";
    yolo[5][21]="10942\n-21 0\n-21 0\n6 -20\n12 17\n21 0\n";
    yolo[5][22]="12080\n-22 0\n-22 0\n11 -19\n11 19\n22 0\n";
    yolo[5][23]="13144\n-23 0\n-23 0\n11 -20\n11 20\n23 0\n";
    yolo[5][24]="14326\n-24 0\n-13 -20\n-13 20\n24 0\n24 0\n";
    yolo[5][25]="15624\n-20 -15\n-20 15\n7 -24\n7 24\n25 0\n";
    yolo[5][26]="16896\n-24 -10\n-24 10\n10 -24\n10 24\n26 0\n";
    yolo[5][27]="18184\n-27 0\n-14 -23\n-14 23\n27 0\n27 0\n";
    yolo[5][28]="19488\n-28 0\n-26 10\n0 -28\n22 17\n28 0\n";
    yolo[5][29]="20968\n-20 -21\n-20 21\n0 -29\n7 28\n29 0\n";
    yolo[5][30]="22480\n-30 0\n-27 -13\n0 30\n24 -18\n30 0\n";
    yolo[6][1]="36\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n";
    yolo[6][2]="144\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n";
    yolo[6][3]="324\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n";
    yolo[6][4]="576\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n";
    yolo[6][5]="900\n-5 0\n-5 0\n-5 0\n5 0\n5 0\n5 0\n";
    yolo[6][6]="1296\n-6 0\n-6 0\n-6 0\n6 0\n6 0\n6 0\n";
    yolo[6][7]="1764\n-7 0\n-7 0\n-7 0\n7 0\n7 0\n7 0\n";
    yolo[6][8]="2304\n-8 0\n-8 0\n-8 0\n8 0\n8 0\n8 0\n";
    yolo[6][9]="2916\n-9 0\n-9 0\n-9 0\n9 0\n9 0\n9 0\n";
    yolo[6][10]="3600\n-10 0\n-10 0\n-10 0\n10 0\n10 0\n10 0\n";
    yolo[6][11]="4356\n-11 0\n-11 0\n-11 0\n11 0\n11 0\n11 0\n";
    yolo[6][12]="5184\n-12 0\n-12 0\n-12 0\n12 0\n12 0\n12 0\n";
    yolo[6][13]="6084\n-13 0\n-13 0\n-13 0\n13 0\n13 0\n13 0\n";
    yolo[6][14]="7056\n-14 0\n-14 0\n-14 0\n14 0\n14 0\n14 0\n";
    yolo[6][15]="8100\n-15 0\n-15 0\n-15 0\n15 0\n15 0\n15 0\n";
    yolo[6][16]="9216\n-16 0\n-16 0\n-16 0\n16 0\n16 0\n16 0\n";
    yolo[6][17]="10404\n-17 0\n-17 0\n-17 0\n17 0\n17 0\n17 0\n";
    yolo[6][18]="11664\n-18 0\n-18 0\n-18 0\n18 0\n18 0\n18 0\n";
    yolo[6][19]="12996\n-19 0\n-19 0\n-19 0\n19 0\n19 0\n19 0\n";
    yolo[6][20]="14400\n-20 0\n-20 0\n-20 0\n20 0\n20 0\n20 0\n";
    yolo[6][21]="15876\n-21 0\n-21 0\n-21 0\n21 0\n21 0\n21 0\n";
    yolo[6][22]="17424\n-22 0\n-22 0\n-22 0\n22 0\n22 0\n22 0\n";
    yolo[6][23]="19044\n-23 0\n-23 0\n-23 0\n23 0\n23 0\n23 0\n";
    yolo[6][24]="20736\n-24 0\n-24 0\n-24 0\n24 0\n24 0\n24 0\n";
    yolo[6][25]="22500\n-25 0\n-25 0\n-25 0\n25 0\n25 0\n25 0\n";
    yolo[6][26]="24336\n-26 0\n-26 0\n-26 0\n26 0\n26 0\n26 0\n";
    yolo[6][27]="26244\n-27 0\n-27 0\n-27 0\n27 0\n27 0\n27 0\n";
    yolo[6][28]="28224\n-28 0\n-28 0\n-28 0\n28 0\n28 0\n28 0\n";
    yolo[6][29]="30276\n-29 0\n-29 0\n-29 0\n29 0\n29 0\n29 0\n";
    yolo[6][30]="32400\n-30 0\n-30 0\n-30 0\n30 0\n30 0\n30 0\n";
    yolo[7][1]="48\n-1 0\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n";
    yolo[7][2]="192\n-2 0\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n";
    yolo[7][3]="432\n-3 0\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n";
    yolo[7][4]="768\n-4 0\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n";
    yolo[7][5]="1224\n-5 0\n-5 0\n-5 0\n3 -4\n3 4\n4 -3\n4 3\n";
    yolo[7][6]="1740\n-6 0\n-6 0\n-6 0\n0 -6\n3 5\n6 0\n6 0\n";
    yolo[7][7]="2356\n-7 0\n-7 0\n-7 0\n0 -7\n3 6\n7 0\n7 0\n";
    yolo[7][8]="3102\n-8 0\n-8 0\n-8 0\n0 -8\n5 6\n8 0\n8 0\n";
    yolo[7][9]="3954\n-9 0\n-9 0\n-9 0\n4 -8\n4 8\n9 0\n9 0\n";
    yolo[7][10]="4896\n-10 0\n-10 0\n-10 0\n6 -8\n6 8\n8 -6\n8 6\n";
    yolo[7][11]="5872\n-11 0\n-11 0\n-11 0\n0 -11\n6 9\n11 0\n11 0\n";
    yolo[7][12]="6960\n-12 0\n-12 0\n-12 0\n0 -12\n6 10\n12 0\n12 0\n";
    yolo[7][13]="8280\n-13 0\n-12 -5\n-12 5\n5 -12\n5 12\n13 0\n13 0\n";
    yolo[7][14]="9564\n-14 0\n-14 0\n-14 0\n5 -13\n7 12\n14 0\n14 0\n";
    yolo[7][15]="11016\n-15 0\n-15 0\n-15 0\n9 -12\n9 12\n12 -9\n12 9\n";
    yolo[7][16]="12456\n-16 0\n-16 0\n-9 -13\n-9 13\n16 0\n16 0\n16 0\n";
    yolo[7][17]="14160\n-17 0\n-17 0\n-17 0\n8 -15\n8 15\n17 0\n17 0\n";
    yolo[7][18]="15816\n-18 0\n-18 0\n-18 0\n8 -16\n8 16\n18 0\n18 0\n";
    yolo[7][19]="17666\n-19 0\n-19 0\n-18 6\n0 -19\n18 6\n18 6\n19 0\n";
    yolo[7][20]="19584\n-20 0\n-20 0\n-20 0\n12 -16\n12 16\n16 -12\n16 12\n";
    yolo[7][21]="21500\n-21 0\n-21 0\n-21 0\n6 -20\n12 17\n21 0\n21 0\n";
    yolo[7][22]="23688\n-22 0\n-22 0\n-22 0\n11 -19\n11 19\n22 0\n22 0\n";
    yolo[7][23]="25808\n-23 0\n-23 0\n-23 0\n11 -20\n11 20\n23 0\n23 0\n";
    yolo[7][24]="28122\n-24 0\n-24 0\n-13 -20\n-13 20\n24 0\n24 0\n24 0\n";
    yolo[7][25]="30624\n-25 0\n-20 -15\n-20 15\n7 -24\n7 24\n25 0\n25 0\n";
    yolo[7][26]="33120\n-26 0\n-24 -10\n-24 10\n10 -24\n10 24\n26 0\n26 0\n";
    yolo[7][27]="35664\n-27 0\n-27 0\n-14 -23\n-14 23\n27 0\n27 0\n27 0\n";
    yolo[7][28]="38266\n-28 0\n-28 0\n-26 10\n0 -28\n22 17\n28 0\n28 0\n";
    yolo[7][29]="41200\n-29 0\n-29 0\n-29 0\n21 -20\n21 -20\n21 20\n21 20\n";
    yolo[7][30]="44076\n-30 0\n-30 0\n-27 -13\n0 30\n24 -18\n30 0\n30 0\n";

    yolo[8][1]="64\n-1 0\n-1 0\n-1 0\n-1 0\n1 0\n1 0\n1 0\n1 0\n";
    yolo[8][2]="256\n-2 0\n-2 0\n-2 0\n-2 0\n2 0\n2 0\n2 0\n2 0\n";
    yolo[8][3]="576\n-3 0\n-3 0\n-3 0\n-3 0\n3 0\n3 0\n3 0\n3 0\n";
    yolo[8][4]="1024\n-4 0\n-4 0\n-4 0\n-4 0\n4 0\n4 0\n4 0\n4 0\n";
    yolo[8][5]="1600\n-5 0\n-5 0\n-5 0\n-5 0\n5 0\n5 0\n5 0\n5 0\n";
    yolo[8][6]="2304\n-6 0\n-6 0\n-6 0\n-6 0\n6 0\n6 0\n6 0\n6 0\n";
    yolo[8][7]="3136\n-7 0\n-7 0\n-7 0\n-7 0\n7 0\n7 0\n7 0\n7 0\n";
    yolo[8][8]="4096\n-8 0\n-8 0\n-8 0\n-8 0\n8 0\n8 0\n8 0\n8 0\n";
    yolo[8][9]="5184\n-9 0\n-9 0\n-9 0\n-9 0\n9 0\n9 0\n9 0\n9 0\n";
    yolo[8][10]="6400\n-10 0\n-10 0\n-10 0\n-10 0\n10 0\n10 0\n10 0\n10 0\n";
    yolo[8][11]="7744\n-11 0\n-11 0\n-11 0\n-11 0\n11 0\n11 0\n11 0\n11 0\n";
    yolo[8][12]="9216\n-12 0\n-12 0\n-12 0\n-12 0\n12 0\n12 0\n12 0\n12 0\n";
    yolo[8][13]="10816\n-13 0\n-13 0\n-13 0\n-13 0\n13 0\n13 0\n13 0\n13 0\n";
    yolo[8][14]="12544\n-14 0\n-14 0\n-14 0\n-14 0\n14 0\n14 0\n14 0\n14 0\n";
    yolo[8][15]="14400\n-15 0\n-15 0\n-15 0\n-15 0\n15 0\n15 0\n15 0\n15 0\n";
    yolo[8][16]="16384\n-16 0\n-16 0\n-16 0\n-16 0\n16 0\n16 0\n16 0\n16 0\n";
    yolo[8][17]="18496\n-17 0\n-17 0\n-17 0\n-17 0\n17 0\n17 0\n17 0\n17 0\n";
    yolo[8][18]="20736\n-18 0\n-18 0\n-18 0\n-18 0\n18 0\n18 0\n18 0\n18 0\n";
    yolo[8][19]="23104\n-19 0\n-19 0\n-19 0\n-19 0\n19 0\n19 0\n19 0\n19 0\n";
    yolo[8][20]="25600\n-20 0\n-20 0\n-20 0\n-20 0\n20 0\n20 0\n20 0\n20 0\n";
    yolo[8][21]="28224\n-21 0\n-21 0\n-21 0\n-21 0\n21 0\n21 0\n21 0\n21 0\n";
    yolo[8][22]="30976\n-22 0\n-22 0\n-22 0\n-22 0\n22 0\n22 0\n22 0\n22 0\n";
    yolo[8][23]="33856\n-23 0\n-23 0\n-23 0\n-23 0\n23 0\n23 0\n23 0\n23 0\n";
    yolo[8][24]="36864\n-24 0\n-24 0\n-24 0\n-24 0\n24 0\n24 0\n24 0\n24 0\n";
    yolo[8][25]="40000\n-25 0\n-25 0\n-25 0\n-25 0\n25 0\n25 0\n25 0\n25 0\n";
    yolo[8][26]="43264\n-26 0\n-26 0\n-26 0\n-26 0\n26 0\n26 0\n26 0\n26 0\n";
    yolo[8][27]="46656\n-27 0\n-27 0\n-27 0\n-27 0\n27 0\n27 0\n27 0\n27 0\n";
    yolo[8][28]="50176\n-28 0\n-28 0\n-28 0\n-28 0\n28 0\n28 0\n28 0\n28 0\n";
    yolo[8][29]="53824\n-29 0\n-29 0\n-29 0\n-29 0\n29 0\n29 0\n29 0\n29 0\n";
    yolo[8][30]="57600\n-30 0\n-30 0\n-30 0\n-30 0\n30 0\n30 0\n30 0\n30 0\n";
}
