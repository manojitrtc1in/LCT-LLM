
using namespace std;



























const int mod = 1e9 + 7;




for(int i = 0; i < n; i++) \
    printf("%d ", array[i]);


template <typename T> inline void write(T x) {
   int i = 20;
   char buf[21];
   

   buf[20] = '\n';

   do {
      buf[--i] = x % 10 + '0';
      x /= 10;
   } while (x);
   do {
      putchar(buf[i]);
   } while (buf[i++] != '\n');
}

template <typename T> inline T readInt() {
   T n = 0, s = 1;
   char p = getchar();
   if (p == '-')
      s = -1;
   while ((p < '0' || p > '9') && p != EOF && p != '-')
      p = getchar();
   if (p == '-')
      s = -1, p = getchar();
   while (p >= '0' && p <= '9') {
      n = (n << 3) + (n << 1) + (p - '0');
      p = getchar();
   }

   return n * s;
}

void codex() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   

   freopen("input.txt", "r", stdin);
   

   freopen("output.txt", "w", stdout);

}

void id2() {
   int n = 10;
   int a[10];
   ff(i, n) cin >> a[i];

   int team_one = 0, team_two = 0;
   ff(i, n) {
      if (i % 2) {
         if (a[i] == 1) team_one++;
      }
      else {
         if (a[i] == 1) team_two++;
      }
   }

   


   if (team_two > team_one) cout << 1 << endl;
   else if (team_two < team_one) cout << 2 << endl;
   else cout << 0 << endl;
}

int id15(int n) {
   

   int binaryNum[32];

   

   int i = 0;
   while (n > 0) {

      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
   }

   int ans = 0;
   for (int j = i - 1; j >= 0; j--) ans = ans * 10 + binaryNum[j];
   return ans;
}

void id9() {
   int n, m, x;
   cin >> n >> m >> x;

   int a[n];
   unordered_map<int, int> mp;
   ff(i, n) {
      cin >> a[i];
      mp[a[i]] = i + 1;
   }

   sort(a, a + n, greater<int>());

   vi ans;
   ff(i, n) {
      if (a[i] >= m) {
         ans.push_back(mp[a[i]]);
         a[i] = 0;
      }
   }

   sort(a, a + n, greater<int>());

   ff(i, n) {
      if (ans.size() < x) {
         ans.push_back(mp[a[i]]);
      }
      else break;
   }

   sort(ans.begin(), ans.end());

   cout << ans.size() << " ";
   ff(i, ans.size()) cout << ans[i] << " ";
   cout << endl;
}

void count_binary() {
   int n;
   cin >> n;
   int a[n];
   ff(i, n) cin >> a[i];

   int cnt = 0;

   ff(k, n) {
      int binaryNum[32];
      int copy = a[k];
      

      int i = 0;
      while (copy > 0) {

         binaryNum[i] = copy % 2;
         copy = copy / 2;
         i++;
      }

      for (int j = i - 1; j > 0; j--) {
         if (binaryNum[j] == 1 and binaryNum[i - 1] == 1) cnt++;
      }
   }

   if (cnt > 1) cout << "Yes" << endl;
   else cout << "No" << endl;
}

class Solution {
public:
   long long numberOfWeeks(vector<int>& milestones) {

      vector<int>a(milestones);
      sort(a.begin(), a.end(), greater<int>());
      long long ans = 0;

      for (int i = 0; i < a.size() - 1; i += 2) {
         a[i] = a[i] - a[i + 1];
         ans += a[i + 1] * 2;
         a[i + 1] = 0;
      }

      ff(i, a.size()) cout << a[i] << " ";

      int r = 0, l = 0;
      for (int i = 1; i < milestones.size(); i++) {
         if (l == i) {
            ans++;
            milestones[l] -= 1;
            continue;
         }
         if (milestones[l] - milestones[i] > 0) {
            milestones[l] = milestones[l] - milestones[i];
            ans += milestones[i] * 2;
         }
         else if (milestones[l] - milestones[i] == 0) {
            l = i + 1; ans += milestones[i] * 2;
         }
         else if (milestones[i] > milestones[l]) {
            milestones[i]++;
         }
      }
      return ans;
   }
};

void id4() {
   int n;
   cin >> n;

   if (n % 4 >= 2) cout << "YES" << endl;
   else cout << "NO" << endl;
}

void id13() {
   int n;
   cin >> n;
   for (int i = n; i >= 1; i--) {
      cout << i << " ";
   }
   cout << "\n";
}

int id6(vector<int> arr, int l, int h, int p) {
   swap(arr[l], arr[p]);

   int i = l - 1, j = h + 1;
   int pivot = arr[i];
   while (1) {
      do {
         i++;
      } while (arr[i] < arr[p]);

      do {
         j--;
      } while (arr[j] > arr[p]);

      if (i >= j) return j;
      swap(arr[i], arr[j]);
   }
}

int kadane(vector<int> arr, int n) {
   

   int id8 = 0;

   

   int id10 = 0;

   

   for (int i = 0; i < n; i++)
   {
      

      

      id10 = id10 + arr[i];

      

      

      id10 = max(id10, 0);

      

      id8 = max(id8, id10);
   }

   return id8;
}

int id0(vector<int> arr, int l, int h) {
   int i = l - 1;
   int p = h;
   for (int j = l; j < h - 1; j++) {
      if (arr[j] < arr[p]) {
         i++;
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[i + 1], arr[h]);
   return i + 1;
}

int count_digits(int n) {
   int copy = n, c = 0;
   while (copy) {
      c++;
      copy /= 10;
   }
   return c;
}

int fact(int n) {
   int ans = 1;
   for (int i = 2; i <= n; i++) ans *= i;
   return ans;
}

bool pal_check(int n) {
   int copy = n, d = 0, rev = 0;
   while (n) {
      int p = n % 10;
      rev = rev * 10 + p;
      n /= 10;
   }
   if (copy == rev) return 1;
   else return 0;
}

vector<int> p;
vector<int> q;

void id5(vector<int>& arr) {
   for (int x : arr)
   {
      

      p.push_back(x);
   }
}

void id7(vector<int>& arr) {
   for (int x : arr)
   {
      

      q.push_back(x);
   }
}

void id14(int arr[], int n) {
   

   

   vector<vector<int> > L(n);

   

   L[0].push_back(0);

   

   for (int i = 1; i < n; i++)
   {
      

      for (int j = 0; j < i; j++)
      {
         if ((arr[i] <= arr[j]) &&
               (L[i].size() < L[j].size() + 1))
            L[i] = L[j];
      }

      

      L[i].push_back(i);
   }

   vector<int> max = L[0];
   for (vector<int> x : L)
      if (x.size() > max.size())
         max = x;

   

   id7(max);
}

void id11(int arr[], int n) {
   

   

   vector<vector<int> > L(n);

   

   L[0].push_back(0);

   

   for (int i = 1; i < n; i++)
   {
      

      for (int j = 0; j < i; j++)
      {
         if ((arr[i] >= arr[j]) &&
               (L[i].size() < L[j].size() + 1))
            L[i] = L[j];
      }

      

      L[i].push_back(i);
   }

   vector<int> max = L[0];
   for (vector<int> x : L)
      if (x.size() > max.size())
         max = x;

   

   id5(max);
}

int power(int x, int y, int p) {
   int res = 1;
   x = x % p;

   while (y > 0) {
      if (y & 1) res = (res * x) % p;
      y = y >> 1; 

      x = (x * x) % p;
   }
   return res;
}

int modInverse(int n, int p) {
   return power(n, p - 2, p);
}





int id12(int n, int r, int p) {
   

   if (n < r)
      return 0;
   

   if (r == 0)
      return 1;

   

   

   

   int fac[n + 1];
   fac[0] = 1;
   for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;

   return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int modFact(int n, int p) {
   if (n >= p) return 0;

   int result = 1;
   for (int i = 1; i <= n; i++) result = (result * i) % p;

   return result;
}

int nPr(int n, int r) {
   return (modFact(n, mod) / modFact(n - r, mod));
}

int id3(int arr[], int n, int output[][50], int k) {

   if (n == 0) {
      if (k == 0) {
         output[0][0] = 0;
         return 1;
      }
      else {
         return 0;
      }
   }
   int output1[1000][50];
   int output2[1000][50];
   int size1 = id3(arr + 1, n - 1, output1, k - arr[0]);

   

   

   int size2 = id3(arr + 1, n - 1,
                            output2, k);

   int i, j;

   

   

   for (i = 0; i < size1; i++) {

      

      

      

      output[i][0] = output1[i][0] + 1;

      

      

      output[i][1] = arr[0];
   }

   

   

   for (i = 0; i < size1; i++) {
      for (j = 1; j <= output1[i][0]; j++) {
         output[i][j + 1] = output1[i][j];
      }
   }

   

   

   for (i = 0; i < size2; i++) {
      for (j = 0; j <= output2[i][0]; j++) {
         output[i + size1][j] = output2[i][j];
      }
   }

   return size1 + size2;
}

void id1(int arr[], int n, int output[][50], int k) {
   int size = id3(arr, n, output, k);

   for (int i = 0; i < size; i++) {
      for (int j = 1; j <= output[i][0]; j++) {
         cout << output[i][j] << " ";
      }
      cout << endl;
   }
}

int g(string s, char c) {

   

   int n = s.size();
   if (n < 2)
      return 0;
   if (s[0] == s[n - 1])
      return g(s.substr(1, n - 2), c);
   if (s[0] == c)
      return g(s.substr(1, n - 1), c) + 1;
   if (s[n - 1] == c)
      return g(s.substr(0, n - 2), c) + 1;
   return -1;
}

int f(string s) {
   int n = s.size();

   if (n < 2)
      return 0;
   if (s[0] == s[n - 1])
      return f(s.substr(1, n - 2));
   int x = g(s.substr(0, n - 1), s[n - 1]), y = g(s.substr(1, n - 1), s[0]);
   if (y == -1 && x == -1)
      return -1;
   if (x == -1)
      return y + 1;
   if (y == -1 || x < y)
      return x + 1;
   return y + 1;
}

bool isvalid(int ff, string &s) {
   vector<int> arr(3, 0); int j = 0;
   ff(i, s.size()) {
      arr[s[i] - 'a']++;
      if (i >= ff - 1) {
         if (i >= ff) {
            arr[s[j] - 'a']--;
            j++;
         }
         if (arr[0] > arr[1] && arr[0] > arr[2]) return true;
      }
   }
   return false;
}



bool ok(int num, int x, int k) {
   int ans = 0;
   ans += (min(num, k) * (min(num, k) + 1)) / 2;
   num -= min(num, k);

   int temp = num * (2 * k - 1 + (num - 1) * (-1));
   temp /= 2;
   ans += temp;
   return (ans < x);
}








void solve() {
   int n, m; cin >> n >> m;
   string s; cin >> s;
   int k = 0;
   ffp(i, 2, n - 1) {
      if (s[i - 2] == 'a' and s[i - 1] == 'b' and s[i] == 'c') k++;
   }
   

   

   

   

   

   

   while (m--) {
      int p; char c; cin >> p >> c;
      p--; int ans = k;
      if (p - 1 >= 0 and p - 2 >= 0) {
         if (s[p - 2] == 'a' and s[p - 1] == 'b' and s[p] == 'c') {
            ans--;
         }






         if (s[p - 2] == 'a' and s[p - 1] == 'b' and c == 'c') {
            ans++;
         }
      }
      

      

      

      

      if (p - 1 >= 0 and p + 1 < n) {
         if (s[p - 1] == 'a' and s[p] == 'b' and s[p + 1] == 'c') {
            ans--;
         }
         if (s[p - 1] == 'a' and c == 'b' and s[p + 1] == 'c') {
            ans++;
         }
      }
      

      

      

      

      if (p + 1 < n and p + 2 < n) {
         if (s[p] == 'a' and s[p + 1] == 'b' and s[p + 2] == 'c') ans--;
         if (c == 'a' and s[p + 1] == 'b' and s[p + 2] == 'c') ans++;
         

         

         

         

      }
      k = ans;
      s[p] = c;
      cout << ans << endl;
   }

}

int32_t main() {
   codex();
   


   int t = 1;
   

   while (t--) {
      solve();
      cout << "\n";
   }

   cout.clear();
   cin.clear();
   return 0;
}









































































































































