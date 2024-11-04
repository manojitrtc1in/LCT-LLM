


  if ((bool)poerhwe) printf("YES"); \
  else printf("NO");





using namespace std;

int main(){

    ios::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    int tret;

  cin >> tret;

for(int tyuert = 0; tyuert < tret; tyuert++){

string id2;

   cin >> id2;

   bool jyuyui[26];

 fill(jyuyui, jyuyui+26, false);

 int id1 = 0;

    int id0 = 1;

    for(char dwret : id2){

        int id3 = int(dwret)-97;

        if(!jyuyui[id3]){

            jyuyui[id3] = true;

            id1++;

        }

        if(id1 == 4){

            id1 = 1;

            id0++;

            fill(jyuyui, jyuyui+26, false);

            jyuyui[id3] = true;

        }

    }

    cout << id0 << '\n';

}

} 
