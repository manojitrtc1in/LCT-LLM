#include<bits/stdc++.h>

#define printb(poerhwe) \
  if ((bool)poerhwe) printf("YES"); \
  else printf("NO");

#define tg(poerhwe) push_back(poerhwe)

#define pf(poerhwe) push_front(poerhwe)

using namespace std;

int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int tret;

  cin >> tret;

for(int tyuert = 0; tyuert < tret; tyuert++){

string csdddq;

   cin >> csdddq;

   bool jyuyui[26];

 fill(jyuyui, jyuyui+26, false);

 int csdfrwe = 0;

    int bnghty = 1;

    for(char dwret : csdddq){

        int uyiyuiuyt = int(dwret)-97;

        if(!jyuyui[uyiyuiuyt]){

            jyuyui[uyiyuiuyt] = true;

            csdfrwe++;

        }

        if(csdfrwe == 4){

            csdfrwe = 1;

            bnghty++;

            fill(jyuyui, jyuyui+26, false);

            jyuyui[uyiyuiuyt] = true;

        }

    }

    cout << bnghty << '\n';

}

} 
