#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <array>



# define M_PI           3.14159265358979323846

void problemA();    

void problemB();    

void problemC();    

void problemD();    

void problemE();    

void problemF();    

void problemG();    

void problemH();    

void problemI();    

void problemJ();    

void problemK();    

void problemL();    


using namespace std;




long long unsigned int decomposition(int rendu, int tab[], int n, long long unsigned int t[][5]){
    if(n==0)
        return 1;
    else if(rendu<tab[n])
        return t[rendu][n-1];
    else
        return t[rendu][n-1] + t[rendu-tab[n]][n];
}

void UVA357(){
    long long unsigned int t[30001][5]={{0}};

    int rendu=0;
    int tab[5]={1,5,10,25,50};
    int n=4;

    for(int i=0; i<5; ++i)
        t[0][i]=1;

    while(cin >> rendu){

        for(int i=1; i<=rendu; ++i){
            for(int j=0; j<5; ++j)
                t[i][j] = decomposition(i, tab, j, t);
        }


        if(t[rendu][4]!=1)
            cout << "There are " << t[rendu][4] << " ways to produce " << rendu << " cents change." << endl;
        else
            cout << "There is only 1 way to produce " << rendu << " cents change." << endl;
    }
}

void test2(){
    array<char, 10> tab{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    do{
        for(int i=0; i<tab.size(); ++i)
            cout << tab[i] << " ";
        cout << endl;
    }while(next_permutation(tab.begin(), tab.end(), [](char A, char B){return A<B;} ));

}

#include <sstream>

void test3(){
    string s;
    getline(cin, s);
    s+=' ';
    istringstream str(s);


    string mot;
    while(getline(str, mot, ' ')){
        cout << mot << " ";
    }

}

void palindromicCut2(){
    int n=0;
    int tab[128]={0};
    vector<string> pal;

    cin >> n;
    char c;
    for(int i=0; i<n; ++i){
        cin >> c;
        ++(tab[c]);
    }


    

    int nbP=0;
    for(int i='0'; i<='z'; ++i)
        if(tab[i]%2==1){
            pal.push_back("");
            pal[nbP]+=i;
            --tab[i];
            ++nbP;
        }

    int p=nbP;
    if(nbP<2){          

        nbP=1;
        if(pal.size()==0)
            pal.resize(nbP);

        for(int i='0'; i<='z'; ++i){
            while(tab[i]!=0){
                pal[0].insert(0, 1, i);
                pal[0].insert(pal[0].size(), 1, i);
                tab[i]-=2;
            }
        }

    }
    else{
        while((n-nbP)%(2*nbP)!=0 )
            nbP+=2;

        int nbLMAX = n/nbP;
        pal.resize(nbP);


        for(int i='0'; i<='z' && p<nbP; ++i)
            if(tab[i]!=0){
                pal[p]+=i;
                ++p;
                pal[p]+=i;
                ++p;

                tab[i]-=2;
                --i;
            }

        p=0;
        int nbL=1;
        for(int i='0'; i<='z'; ++i){
            while(tab[i]!=0){
                pal[p].insert(0, 1, i);
                pal[p].insert(pal[p].size(), 1, i);
                tab[i]-=2;
                nbL+=2;

                if(nbL>=nbLMAX){
                    ++p;
                    nbL=1;
                }
            }
        }
    }


    cout << nbP << endl;
    for(int i=0; i<nbP-1; ++i)
        cout << pal[i] << " ";
    cout << pal[nbP-1] << endl;

}



void palindromicCut(){
    int n=0;
    int tab[128]={0};
    vector<string> pal, pal2;

    cin >> n;
    char c;
    for(int i=0; i<n; ++i){
        cin >> c;
        ++(tab[c]);
    }


    

    int nbP=0;
    for(int i='0'; i<='z'; ++i)
        if(tab[i]%2==1){
            pal.push_back("");
            pal[nbP]+=i;
            --tab[i];
            ++nbP;
        }



    int p=nbP;
    if(nbP<2){          

        nbP=1;
        if(pal.size()==0)
            pal.resize(nbP);


        pal2.resize(nbP);
        int t1 = pal[0].size(),
            t2 = (n/2)-1;
        pal[0].resize(t1 + n/2);
        pal2[0].resize(n/2);

        for(int i='0'; i<='z'; ++i){
            while(tab[i]!=0){
                pal[0][t1]=i;
                pal2[0][t2]= i;
                ++t1;
                --t2;
                tab[i]-=2;
            }
        }

    }
    else{
        while((n-nbP)%(2*nbP)!=0 )
            nbP+=2;

        int nbLMAX = n/nbP;
        pal.resize(nbP);
        pal2.resize(nbP);
        int nbL1=(nbLMAX+1)/2,
            nbL2=nbLMAX/2;
        for(int j=0; j<nbP; ++j){
            pal[j].resize(nbL1);
            pal2[j].resize(nbL2);
        }

        for(int i='0'; i<='z' && p<nbP; ++i)
            if(tab[i]!=0){
                pal[p][0]=i;
                ++p;
                pal[p][0]=i;
                ++p;

                tab[i]-=2;
                --i;
            }


        p=0;
        int t=1;
        int nbL=1;
        for(int i='0'; i<='z'; ++i){
            while(tab[i]!=0){
                pal[p][t]=i;
                pal2[p][nbL2-t]=i;
                tab[i]-=2;
                nbL+=2;
                ++t;

                if(nbL>=nbLMAX){
                    ++p;
                    nbL=1;
                    t=1;
                }
            }
        }
    }


    cout << nbP << endl;
    for(int i=0; i<nbP-1; ++i)
        cout << pal2[i] << pal[i] << " ";
    cout << pal2[nbP-1] << pal[nbP-1] << endl;

}

#include <fstream>
#include <cstdlib>
int main()
{
    

    palindromicCut();


}


void test(){
    array<int, 4> tab2{1, 2, 3, 4};
    int tab[]={1,2,3,4};

    cout << *(tab+2) << endl << endl;

    do{
        for(int i=0; i<4; ++i)
            cout << tab2[i] << " ";
        cout << endl;
    }while(next_permutation(tab2.begin(), tab2.end()));

    cout <<  "min:" << *min_element(tab2.begin(), tab2.end())
         << " max:" << *max_element(tab2.begin(), tab2.end());

}




void problemA(){



}
struct SEGMENT{
    int dist;
    int teta;
};
void problemB(){
    vector<SEGMENT> tab;
    int n=0;
    double g=0;

    cin >> n >> g;
    tab.resize(n);
    for(int i=0; i<n; ++i)
        cin >> tab[i].dist >> tab[i].teta;

    for(int i=0; i<n; ++i){
        double v=0.0;
        for(int j=i; j<n; ++j){
            double delta = v*v + 2*g*cos((1.0*tab[j].teta/180)*M_PI)*tab[j].dist;
            double t = (-v + sqrt(delta)) / (g*cos((1.0*tab[j].teta/180)*M_PI));
            v += t*g*cos((1.0*tab[j].teta/180)*M_PI);
        }
        cout << fixed << setprecision(10) << v << endl;
    }


}

struct WORD{
    string mot;
    int nb;
};
struct WORD2{
    string mot;
    int nb;
    int rep;
};
struct USER{
    string user;
    vector<WORD> t;
};
bool comparer(const WORD2 &w1, const WORD2 &w2){
    return w1.nb>w2.nb || (w1.nb==w2.nb && w1.mot<w2.mot);
}
void problemC(){
    int n=0;
    vector<USER> tab;

    cin >> n;
    for(int i=0; i<n; ++i){
        string user, msg;
        cin >> user;

        int j=0;
        while(j<tab.size() && tab[j].user!=user)
            ++j;

        if(j==tab.size()){
            tab.push_back({user});
        }

        getline(cin, msg);
        msg+=' ';
        string s="";
        for(int k=1; k<msg.size(); ++k){
            if(msg[k]!=' ')
                s+=msg[k];
            else{
                int l=0;
                while(l<tab[j].t.size() && tab[j].t[l].mot!=s)
                    ++l;

                if(l==tab[j].t.size()){
                    tab[j].t.push_back({s, 1});
                }
                else
                    tab[j].t[l].nb++;

                s="";
            }
        }
    }


    vector<WORD2> res;

    for(int i=0; i<tab.size(); ++i){
        for(int j=0; j<tab[i].t.size(); ++j){
            int k=0;
            while(k<res.size() && res[k].mot!=tab[i].t[j].mot)
                ++k;

            if(k==res.size())
                res.push_back({tab[i].t[j].mot, tab[i].t[j].nb, 1});
            else{
                res[k].nb+=tab[i].t[j].nb;
                res[k].rep++;
            }

        }

    }




    for(int i=0; i<res.size(); ++i)
        if(res[i].rep<tab.size()){
            res.erase(res.begin()+i);
            --i;
        }

    sort(res.begin(), res.end(), comparer);

    if(res.size()==0)
        cout << "ALL CLEAR" << endl;
    else
    for(int i=0; i<res.size(); ++i)
        cout << res[i].mot << endl;

}

void problemD(){
}
void problemE(){
}
void problemF(){
}
void problemG(){



}

struct POINT{
    int x;
    int h;
};
struct BUILDING{
    int x;
    int h;
    int left;
    int right;
};
void problemH(){
    vector<BUILDING> tab;
    int n=0;

    cin >> n;
    tab.resize(n);
    for(int i=0; i<n; ++i)
        cin >> tab[i].x >> tab[i].h;

    int xmax=-1;
    for(int i=0; i<n; ++i){

        if(i>=xmax){
            double maxi=tab[i].h;
            xmax=i;
            for(int j=i+1; j<n; ++j){
                if((tab[j].h-tab[i].h)*1.0/(tab[j].x-tab[i].x)+tab[i].h>maxi){
                    maxi=(tab[j].h-tab[i].h)*1.0/(tab[j].x-tab[i].x)+tab[i].h;
                    xmax=j;
                }
            }
        }
        tab[i].right = xmax;
    }

    xmax=n;
    for(int i=n-1; i>=0; --i){

        if(i<=xmax){
            double maxi=tab[i].h;
            xmax=i;
            for(int j=i-1; j>=0; --j){
                if((tab[j].h-tab[i].h)*1.0/(tab[i].x-tab[j].x)+tab[i].h>maxi){
                    maxi=(tab[j].h-tab[i].h)*1.0/(tab[i].x-tab[j].x)+tab[i].h;
                    xmax=j;
                }
            }
        }

        tab[i].left = xmax;

    }

    

    


    for(int i=0; i<n; ++i){
        if(tab[tab[i].left].h == tab[i].h)
            tab[i].left=i;
        if(tab[tab[i].right].h == tab[i].h)
            tab[i].right=i;
    }


    for(int i=0; i<n; ++i){
        double expo=0.0;
        int l=tab[i].left;
        int r=tab[i].right;

        if(l==i)
            expo+=6;
        else{
            expo+= (1-(atan((tab[l].h-tab[i].h)*1.0/(tab[i].x-tab[l].x))/(M_PI/2)))*6;
        }
        

        if(r==i)
            expo+=6;
        else{
            expo+= (1-atan((tab[r].h-tab[i].h)*1.0/(tab[r].x-tab[i].x))/(M_PI/2))*6;
        }
        cout << fixed << setprecision(7) << expo << endl;
    }




}
void problemI(){
    vector<string> tab;
    array<char, 8> cons {'b', 'c', 'd', 'g', 'k', 'n', 'p', 't'};
    array<char, 8> cons2{'B', 'C', 'D', 'G', 'K', 'N', 'P', 'T'};
    array<char, 3> fin{'a', 'o', 'u'};

    string s;
    getline(cin, s);
    s+=' ';

    for(int i=0; i<s.size(); ++i){
        int j=tab.size();
        tab.push_back("");
        while(i<s.size() && s[i]!=' '){
            tab[j]+=s[i];
            ++i;
        }
    }


    tab[0][0]+=('a'-'A');

    for(int i=0; i<tab.size(); ++i){

        int ind=0;
        for(int j=1; j<8; ++j){
            if(abs(tab[i][0]-cons[j]) < abs(tab[i][0]-cons[ind]) ||
               (abs(tab[i][0]-cons[j]) == abs(tab[i][0]-cons[ind]) && abs('A'-cons[j]) < abs('A'-cons[ind])))
                ind=j;
        }
        tab[i][0]=cons[ind];

        int j=1;
        while(j<tab[i].size() && tab[i][j]!='-')
            ++j;

        while(j<tab[i].size()){
            if(find(cons.begin(), cons.end(), tab[i][j]) != cons.end())
                tab[i][j]=cons[ind];
            ++j;
        }


        int der = tab[i].size()-1;
        int m=0;
        while(m<8 && tab[i][der]!=cons[m] && tab[i][der]!=cons2[m])
            ++m;


        if(find(cons.begin() , cons.end() , tab[i][der]) != cons.end() ||
           find(cons2.begin(), cons2.end(), tab[i][der]) != cons2.end()){
            int indice=0;
            for(int f=1; f<fin.size(); ++f){
                if(abs(tab[i][der] - fin[f]) < abs(tab[i][der] - fin[indice]) ||
                   (abs(tab[i][der] - fin[f]) < abs(tab[i][der] - fin[indice]) && abs('A' - fin[f]) < abs('A' - fin[indice])))
                    indice=f;
            }
            tab[i]+=fin[indice];
            tab[i]+='h';
        }

    }


    tab[0][0]-=('a'-'A');

    for(int i=0; i<tab.size(); ++i){
        for(int j=0; j<tab[i].size(); ++j)
            if(tab[i][j]=='-'){
                tab[i].erase(tab[i].begin()+j);
                --j;
            }

    }
    for(int i=0; i<tab.size()-1; ++i)
        cout << tab[i] << " ";
    cout << tab[tab.size()-1] << endl;


}
void problemJ(){
}
void problemK(){
}
void problemL(){
}


