#include <iostream>
#include <assert.h>
#include <cstdio>

using namespace std;

const int rozmiar_drzewa = 524288;

int drzewo_rosnace_min[rozmiar_drzewa*2];
int drzewo_malejace_min[rozmiar_drzewa*2];
long long int wartosci_w_drzewie[rozmiar_drzewa*2];
int drzewo_odejmowania_rosnacy[rozmiar_drzewa*2];
int drzewo_odejmowania_malejacy[rozmiar_drzewa*2];
int indexy_min_rosnacy[rozmiar_drzewa*2];
int indexy_min_malejacy[rozmiar_drzewa*2];
int drzewo_max_sumy[rozmiar_drzewa*2];

int dp_rosnacy[300000+1];
int dp_malejacy[300000+1];

int liczba_wierz;

void wstaw_wartosc(int a, int b, long long int ile) {
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    wartosci_w_drzewie[a] += ile;
    if(a != b) {
        wartosci_w_drzewie[b] += ile;
    }
    while(a/2 != b/2) {
        if(a%2 == 0) {
            wartosci_w_drzewie[a+1] += ile;
        }
        if(b%2 == 1) {
            wartosci_w_drzewie[b-1] += ile;
        }
        a/= 2;
        b/= 2;
    }
}

long long int zapytanie_wartosci(int index) {
    index += rozmiar_drzewa;
    long long int wyn = wartosci_w_drzewie[index];
    index /= 2;
    while(index > 0) {
        wyn += wartosci_w_drzewie[index];
        index /= 2;
        
    }
    return wyn;
}

void wstaw_odejmowanie_rosnace(int a, int b, int ile) {
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
    
        drzewo_odejmowania_rosnacy[a] += ile;
        drzewo_rosnace_min[a] += ile;
      drzewo_max_sumy[a] += ile;
    
    
    if(a != b) {
        drzewo_max_sumy[b] += ile;
        drzewo_odejmowania_rosnacy[b] += ile;
        drzewo_rosnace_min[b] += ile;
       
    }
    
    while(a / 2 != b / 2) {
        if(a%2 == 0) {
        
                drzewo_odejmowania_rosnacy[a+1] += ile;
                drzewo_rosnace_min[a+1] += ile;
           
            drzewo_max_sumy[a+1] += ile;
        }
        if(b%2 == 1) {
         
                drzewo_odejmowania_rosnacy[b-1] += ile;
                drzewo_rosnace_min[b-1] += ile;
           
            drzewo_max_sumy[b-1] += ile;
        }
        
        
            
            if(drzewo_rosnace_min[a] < drzewo_rosnace_min[a^1]) {
                drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a];
                indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a];
            } else if(drzewo_rosnace_min[a^1] < drzewo_rosnace_min[a]) {
                drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a^1];
                indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a^1];
            } else if(indexy_min_rosnacy[a] < indexy_min_rosnacy[a^1]) {
                drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a];
                indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a];
            } else {
                drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a^1];
                indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a^1];
            }
            drzewo_rosnace_min[a/2] += drzewo_odejmowania_rosnacy[a/2];
            
            
            if(drzewo_rosnace_min[b] < drzewo_rosnace_min[b^1]) {
                drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b];
                indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b];
            } else if(drzewo_rosnace_min[b^1] < drzewo_rosnace_min[b]) {
                drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b^1];
                indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b^1];
            } else if(indexy_min_rosnacy[b] < indexy_min_rosnacy[b^1]) {
                drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b];
                indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b];
            } else {
                drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b^1];
                indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b^1];
            }
            drzewo_rosnace_min[b/2] += drzewo_odejmowania_rosnacy[b/2];
        
        
        
        
        
        drzewo_max_sumy[a/2] = max(drzewo_max_sumy[a], drzewo_max_sumy[a^1]) + drzewo_odejmowania_malejacy[a/2] + drzewo_odejmowania_rosnacy[a/2];
        drzewo_max_sumy[b/2] = max(drzewo_max_sumy[b], drzewo_max_sumy[b^1]) + drzewo_odejmowania_malejacy[b/2] + drzewo_odejmowania_rosnacy[b/2];
        
        
        a/=2;
        b/=2;
    }
    
    for(int i = a/2; i > 0; i /= 2) {
        
            if(drzewo_rosnace_min[i*2] <= drzewo_rosnace_min[i*2+1]) {
                drzewo_rosnace_min[i] = drzewo_rosnace_min[i*2];
                indexy_min_rosnacy[i] = indexy_min_rosnacy[i*2];
            } else {
                drzewo_rosnace_min[i] = drzewo_rosnace_min[i*2+1];
                indexy_min_rosnacy[i] = indexy_min_rosnacy[i*2+1];
            }
            drzewo_rosnace_min[i] += drzewo_odejmowania_rosnacy[i];
      
        
        
        drzewo_max_sumy[i] = max(drzewo_max_sumy[i*2+1], drzewo_max_sumy[i*2]) +drzewo_odejmowania_malejacy[i] + drzewo_odejmowania_rosnacy[i];
        
        
    }

}

void wstaw_odejmowanie_malejace(int a, int b, int ile) {
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
   
        drzewo_odejmowania_malejacy[a] += ile;
        drzewo_malejace_min[a] += ile;
    
    drzewo_max_sumy[a] += ile;
    
    
    if(a != b) {
        drzewo_max_sumy[b] += ile;
      
            drzewo_odejmowania_malejacy[b] += ile;
            drzewo_malejace_min[b] += ile;
        
    }
    
    while(a / 2 != b / 2) {
        if(a%2 == 0) {
                            drzewo_odejmowania_malejacy[a+1] += ile;
                drzewo_malejace_min[a+1] += ile;
            
            drzewo_max_sumy[a+1] += ile;
        }
        if(b%2 == 1) {
           
                drzewo_odejmowania_malejacy[b-1] += ile;
                drzewo_malejace_min[b-1] += ile;
            
            drzewo_max_sumy[b-1] += ile;
        }
        

        
    
            if(drzewo_malejace_min[a] < drzewo_malejace_min[a^1]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a];
            } else if(drzewo_malejace_min[a^1] < drzewo_malejace_min[a]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a^1];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a^1];
            } else if(indexy_min_malejacy[a] > indexy_min_malejacy[a^1]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a];
            } else {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a^1];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a^1];
            }
            drzewo_malejace_min[a/2] += drzewo_odejmowania_malejacy[a/2];
            
            
            if(drzewo_malejace_min[b] < drzewo_malejace_min[b^1]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b];
            } else if(drzewo_malejace_min[b^1] < drzewo_malejace_min[b]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b^1];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b^1];
            } else if(indexy_min_malejacy[b] > indexy_min_malejacy[b^1]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b];
            } else {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b^1];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b^1];
            }
            drzewo_malejace_min[b/2] += drzewo_odejmowania_malejacy[b/2];

        
        
        
        drzewo_max_sumy[a/2] = max(drzewo_max_sumy[a], drzewo_max_sumy[a^1]) + drzewo_odejmowania_malejacy[a/2] + drzewo_odejmowania_rosnacy[a/2];
        drzewo_max_sumy[b/2] = max(drzewo_max_sumy[b], drzewo_max_sumy[b^1]) + drzewo_odejmowania_malejacy[b/2] + drzewo_odejmowania_rosnacy[b/2];
        
        
        a/=2;
        b/=2;
    }
    
    for(int i = a/2; i > 0; i /= 2) {
       
            if(drzewo_malejace_min[i*2+1] <= drzewo_malejace_min[i*2]) {
                drzewo_malejace_min[i] = drzewo_malejace_min[i*2+1];
                indexy_min_malejacy[i] = indexy_min_malejacy[i*2+1];
            } else {
                drzewo_malejace_min[i] = drzewo_malejace_min[i*2];
                indexy_min_malejacy[i] = indexy_min_malejacy[i*2];
            }
            drzewo_malejace_min[i] += drzewo_odejmowania_malejacy[i];
        
        
        
        
        
        
        
        
        
        drzewo_max_sumy[i] = max(drzewo_max_sumy[i*2+1], drzewo_max_sumy[i*2]) +drzewo_odejmowania_malejacy[i] + drzewo_odejmowania_rosnacy[i];
        
        
    }

}

void wstaw_odejmowanie(int a, int b, int ile, bool rosnacy) {
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
    if(rosnacy) {
        drzewo_odejmowania_rosnacy[a] += ile;
        drzewo_rosnace_min[a] += ile;
    } else {
        drzewo_odejmowania_malejacy[a] += ile;
        drzewo_malejace_min[a] += ile;
    }
    drzewo_max_sumy[a] += ile;
    
    
    if(a != b) {
        drzewo_max_sumy[b] += ile;
        if(rosnacy) {
            drzewo_odejmowania_rosnacy[b] += ile;
            drzewo_rosnace_min[b] += ile;
        } else {
            drzewo_odejmowania_malejacy[b] += ile;
            drzewo_malejace_min[b] += ile;
        }
    }
    
    while(a / 2 != b / 2) {
        if(a%2 == 0) {
            if(rosnacy) {
                drzewo_odejmowania_rosnacy[a+1] += ile;
                drzewo_rosnace_min[a+1] += ile;
            } else {
                drzewo_odejmowania_malejacy[a+1] += ile;
                drzewo_malejace_min[a+1] += ile;
            }
            drzewo_max_sumy[a+1] += ile;
        }
        if(b%2 == 1) {
            if(rosnacy) {
                drzewo_odejmowania_rosnacy[b-1] += ile;
                drzewo_rosnace_min[b-1] += ile;
            } else {
                drzewo_odejmowania_malejacy[b-1] += ile;
                drzewo_malejace_min[b-1] += ile;
            }
            drzewo_max_sumy[b-1] += ile;
        }
        
        if(rosnacy){
            
        
        
        if(drzewo_rosnace_min[a] < drzewo_rosnace_min[a^1]) {
            drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a];
            indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a];
        } else if(drzewo_rosnace_min[a^1] < drzewo_rosnace_min[a]) {
            drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a^1];
            indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a^1];
        } else if(indexy_min_rosnacy[a] < indexy_min_rosnacy[a^1]) {
            drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a];
            indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a];
        } else {
            drzewo_rosnace_min[a/2] = drzewo_rosnace_min[a^1];
            indexy_min_rosnacy[a/2] = indexy_min_rosnacy[a^1];
        }
        drzewo_rosnace_min[a/2] += drzewo_odejmowania_rosnacy[a/2];
        
        
        if(drzewo_rosnace_min[b] < drzewo_rosnace_min[b^1]) {
            drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b];
            indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b];
        } else if(drzewo_rosnace_min[b^1] < drzewo_rosnace_min[b]) {
            drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b^1];
            indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b^1];
        } else if(indexy_min_rosnacy[b] < indexy_min_rosnacy[b^1]) {
            drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b];
            indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b];
        } else {
            drzewo_rosnace_min[b/2] = drzewo_rosnace_min[b^1];
            indexy_min_rosnacy[b/2] = indexy_min_rosnacy[b^1];
        }
        drzewo_rosnace_min[b/2] += drzewo_odejmowania_rosnacy[b/2];
        }
        
        else {
            if(drzewo_malejace_min[a] < drzewo_malejace_min[a^1]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a];
            } else if(drzewo_malejace_min[a^1] < drzewo_malejace_min[a]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a^1];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a^1];
            } else if(indexy_min_malejacy[a] > indexy_min_malejacy[a^1]) {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a];
            } else {
                drzewo_malejace_min[a/2] = drzewo_malejace_min[a^1];
                indexy_min_malejacy[a/2] = indexy_min_malejacy[a^1];
            }
            drzewo_malejace_min[a/2] += drzewo_odejmowania_malejacy[a/2];
            
            
            if(drzewo_malejace_min[b] < drzewo_malejace_min[b^1]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b];
            } else if(drzewo_malejace_min[b^1] < drzewo_malejace_min[b]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b^1];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b^1];
            } else if(indexy_min_malejacy[b] > indexy_min_malejacy[b^1]) {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b];
            } else {
                drzewo_malejace_min[b/2] = drzewo_malejace_min[b^1];
                indexy_min_malejacy[b/2] = indexy_min_malejacy[b^1];
            }
            drzewo_malejace_min[b/2] += drzewo_odejmowania_malejacy[b/2];
            
            

        }
        
        
        
        
        
        
        drzewo_max_sumy[a/2] = max(drzewo_max_sumy[a], drzewo_max_sumy[a^1]) + drzewo_odejmowania_malejacy[a/2] + drzewo_odejmowania_rosnacy[a/2];
        drzewo_max_sumy[b/2] = max(drzewo_max_sumy[b], drzewo_max_sumy[b^1]) + drzewo_odejmowania_malejacy[b/2] + drzewo_odejmowania_rosnacy[b/2];
        
        
        a/=2;
        b/=2;
    }
    
    for(int i = a/2; i > 0; i /= 2) {
        if(rosnacy) {
            if(drzewo_rosnace_min[i*2] <= drzewo_rosnace_min[i*2+1]) {
                drzewo_rosnace_min[i] = drzewo_rosnace_min[i*2];
                indexy_min_rosnacy[i] = indexy_min_rosnacy[i*2];
            } else {
                drzewo_rosnace_min[i] = drzewo_rosnace_min[i*2+1];
                indexy_min_rosnacy[i] = indexy_min_rosnacy[i*2+1];
            }
            drzewo_rosnace_min[i] += drzewo_odejmowania_rosnacy[i];
        }
        else {
            if(drzewo_malejace_min[i*2+1] <= drzewo_malejace_min[i*2]) {
                drzewo_malejace_min[i] = drzewo_malejace_min[i*2+1];
                indexy_min_malejacy[i] = indexy_min_malejacy[i*2+1];
            } else {
                drzewo_malejace_min[i] = drzewo_malejace_min[i*2];
                indexy_min_malejacy[i] = indexy_min_malejacy[i*2];
            }
            drzewo_malejace_min[i] += drzewo_odejmowania_malejacy[i];
        }
        
     
        
        
        
        
        
        
        drzewo_max_sumy[i] = max(drzewo_max_sumy[i*2+1], drzewo_max_sumy[i*2]) +drzewo_odejmowania_malejacy[i] + drzewo_odejmowania_rosnacy[i];
        
        
    }
}

int zapytanie_max_sumy(int a, int b) {
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
   int wyn_l = drzewo_max_sumy[a] ;
    int wyn_p = drzewo_max_sumy[b] ;
    
    
    while(a / 2 != b / 2) {
        if(a%2 == 0) {
            wyn_l = max(wyn_l, drzewo_max_sumy[a+1] );
        }
        if(b%2 == 1) {
            wyn_p = max(wyn_p, drzewo_max_sumy[b-1] );
        }
        wyn_l += drzewo_odejmowania_rosnacy[a/2] + drzewo_odejmowania_malejacy[a/2];
        wyn_p += drzewo_odejmowania_rosnacy[b/2] + drzewo_odejmowania_malejacy[b/2];
        a/=2;
        b/=2;
    }
    
    wyn_l = max(wyn_l, wyn_p);
    
    for(int i = a/2; i > 0; i/= 2){
        wyn_l += drzewo_odejmowania_malejacy[i] + drzewo_odejmowania_rosnacy[i];
    }
    return wyn_l;
}

int zapytanie_min_rosnacy(int a, int b) {
    if(a > b ) {
        return a;
    }
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
    int wyn_index_l = a-rozmiar_drzewa;
    int wyn_index_p = b-rozmiar_drzewa;
    
    int wyn_wart_l = drzewo_rosnace_min[a];
    int wyn_wart_p = drzewo_rosnace_min[b];
    
    while (a /2 != b/2) {
        if(a%2 == 0) {
            if(drzewo_rosnace_min[a+1] < wyn_wart_l) {
                wyn_wart_l = drzewo_rosnace_min[a+1];
                wyn_index_l = indexy_min_rosnacy[a+1];
            }
        }
        if(b%2 == 1) {
            if(drzewo_rosnace_min[b-1] <= wyn_wart_p) {
                wyn_wart_p = drzewo_rosnace_min[b-1];
                wyn_index_p = indexy_min_rosnacy[b-1];
            }
        }
        
        wyn_wart_l += drzewo_odejmowania_rosnacy[a/2];
        wyn_wart_p += drzewo_odejmowania_rosnacy[b/2];
        
        a/=2;
        b/=2;
    }
    
    
    if(wyn_wart_p  < wyn_wart_l) {
        wyn_wart_l = wyn_wart_p;
        wyn_index_l = wyn_index_p;
    }
    
    for(int i = a/2; i > 0; i/=2){
        wyn_wart_l += drzewo_odejmowania_rosnacy[i];
    }
    
    if(wyn_wart_l == 1) return wyn_index_l;
    
    return liczba_wierz;
}

int zapytanie_min_malejacy(int a, int b) {

    if(a > b ) {
        return b;
    }
    
    a += rozmiar_drzewa;
    b += rozmiar_drzewa;
    
    
    
    int wyn_index_l = a-rozmiar_drzewa;
    int wyn_index_p = b-rozmiar_drzewa;
    
    int wyn_wart_l = drzewo_malejace_min[a];
    int wyn_wart_p = drzewo_malejace_min[b];
    
    while (a /2 != b/2) {
        if(a%2 == 0) {
            if(drzewo_malejace_min[a+1] <= wyn_wart_l) {
                wyn_wart_l = drzewo_malejace_min[a+1];
                wyn_index_l = indexy_min_malejacy[a+1];
            }
        }
        if(b%2 == 1) {
            if(drzewo_malejace_min[b-1] < wyn_wart_p) {
                wyn_wart_p = drzewo_malejace_min[b-1];
                wyn_index_p = indexy_min_malejacy[b-1];
            }
        }
        
        wyn_wart_l += drzewo_odejmowania_malejacy[a/2];
        wyn_wart_p += drzewo_odejmowania_malejacy[b/2];
        
        a/=2;
        b/=2;
    }
    
    
    if(wyn_wart_l  < wyn_wart_p) {
        wyn_wart_p = wyn_wart_l;
        wyn_index_p = wyn_index_l;
    }
    
    for(int i = a/2; i > 0; i/=2){
        wyn_wart_p += drzewo_odejmowania_malejacy[i];
    }
    
    if(wyn_wart_p == 1) return wyn_index_p;
    
    return -1;
}

void wstaw_drzewo_rosnace(int index, int wyn) {
    index += rozmiar_drzewa;
    drzewo_rosnace_min[index] = wyn;
    indexy_min_rosnacy[index] = index-rozmiar_drzewa;
    index /= 2;
    while (index > 0) {
        if(drzewo_rosnace_min[index*2] <= drzewo_rosnace_min[index*2+1]) {
            drzewo_rosnace_min[index] =  drzewo_rosnace_min[index*2];
            indexy_min_rosnacy[index] = indexy_min_rosnacy[index*2];
        } else {
            drzewo_rosnace_min[index] =  drzewo_rosnace_min[index*2+1];
            indexy_min_rosnacy[index] = indexy_min_rosnacy[index*2+1];
        }
        
        
        index /= 2;
    }
}


void wstaw_drzewo_malejace(int index, int wyn) {
    index += rozmiar_drzewa;
    drzewo_malejace_min[index] = wyn;
    indexy_min_malejacy[index] = index-rozmiar_drzewa;
    index /= 2;
    while (index > 0) {
        if(drzewo_malejace_min[index*2+1] <= drzewo_malejace_min[index*2]) {
            drzewo_malejace_min[index] =  drzewo_malejace_min[index*2+1];
            indexy_min_malejacy[index] = indexy_min_malejacy[index*2+1];
        } else {
            drzewo_malejace_min[index] =  drzewo_malejace_min[index*2];
            indexy_min_malejacy[index] = indexy_min_malejacy[index*2];
        }
        
        
        index /= 2;
    }
}

int zapytanie_mojej_rosnacy(int index) {
    index += rozmiar_drzewa;
    int wyn = drzewo_rosnace_min[index];
    
    for(int i = index/2; i > 0; i/=2) {
        wyn += drzewo_odejmowania_rosnacy[i];
    }
    return wyn;
}

int zapytanie_mojej_malejacy(int index) {
    index += rozmiar_drzewa;
    int wyn = drzewo_malejace_min[index];
    for(int i = index/2; i > 0; i/=2) {
        wyn += drzewo_odejmowania_malejacy[i];
    }
    return wyn;
}

void wstaw_max_sumy(int index, int wart) {
    index += rozmiar_drzewa;
    
    drzewo_max_sumy[index] = wart;
    
    for(int i = index/2; i > 0; i /= 2) {
        drzewo_max_sumy[i] = max(drzewo_max_sumy[i*2], drzewo_max_sumy[i*2+1]);
    }
}

void inicjalizuj_max_sume() {
    for(int i = 0; i < liczba_wierz; ++i) {
        wstaw_max_sumy(i, dp_rosnacy[i] + dp_malejacy[i]);
    }
}



void wypisz() {
    

    

    for(int i = 0; i < liczba_wierz; ++i) {
        cout << zapytanie_mojej_malejacy(i) << " ";
    }
    cout << endl;
}


void oblicz_poczatkowe_ros_mal() {
    dp_rosnacy[0] = 1;
    wstaw_drzewo_rosnace(0, 1);
    for(int i = 1; i < liczba_wierz; ++i) {
        if(zapytanie_wartosci(i) > zapytanie_wartosci(i-1)) {
            dp_rosnacy[i] = dp_rosnacy[i-1]+1;
        } else {
            dp_rosnacy[i] = 1;
        }
        
        wstaw_drzewo_rosnace(i, dp_rosnacy[i]);
        
    }
    
    dp_malejacy[liczba_wierz-1] = 1;
    wstaw_drzewo_malejace(liczba_wierz-1, 1);
    for(int i = liczba_wierz-2; i >= 0; --i) {
        if(zapytanie_wartosci(i) > zapytanie_wartosci(i+1)) {
            dp_malejacy[i] = dp_malejacy[i+1]+1;
        } else {
            dp_malejacy[i] = 1;
        }
        
        wstaw_drzewo_malejace(i, dp_malejacy[i]);
    }
}

void wczytaj() {
    scanf("%d", &liczba_wierz);
    

    for(int i = 0; i < liczba_wierz; ++i) {
        int wys_wierzy;
        scanf("%d", &wys_wierzy);
        

        wstaw_wartosc(i, i, wys_wierzy);
    }
    oblicz_poczatkowe_ros_mal();
    inicjalizuj_max_sume();
    
    int liczba_zapytan;
    scanf("%d", &liczba_zapytan);
   

    
    for(int i = 0; i < liczba_zapytan; ++i) {
        int a, b, c;
       

        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        
        
        
        long long int poprzednia_wart_b = zapytanie_wartosci(b);
        long long int obecna_wartosc_b = poprzednia_wart_b + c;
        long long int poprzednia_wart_a = zapytanie_wartosci(a);
        long long int obecna_wartosc_a = poprzednia_wart_a + c;
        wstaw_wartosc(a, b, c);
        
        
        if(b < liczba_wierz-1  ) {
            long long int kolejna_wartosc = zapytanie_wartosci(b+1);
            if(poprzednia_wart_b  < kolejna_wartosc && obecna_wartosc_b >= kolejna_wartosc) {
                int szuk_index = zapytanie_min_rosnacy(b+1, liczba_wierz-1);
                int moja_wart_ros = zapytanie_mojej_rosnacy(b);
                wstaw_odejmowanie_rosnace(b+1, szuk_index-1, -moja_wart_ros);
                

                
            }
            
            if(poprzednia_wart_b <= kolejna_wartosc && obecna_wartosc_b > kolejna_wartosc) {
               

                
                
                int szuk_index = zapytanie_min_malejacy(0, b-1);
                int nast_wart_malejaca = zapytanie_mojej_malejacy(b+1);
                wstaw_odejmowanie_malejace(szuk_index+1, b, nast_wart_malejaca);
               

            }
        }
        
        if(a > 0) {
            long long int pop_wartosc = zapytanie_wartosci(a-1);
            if( poprzednia_wart_a <= pop_wartosc && obecna_wartosc_a > pop_wartosc) {
                int szuk_index = zapytanie_min_rosnacy(a+1, liczba_wierz-1);
                int pop_wart_rosnaca = zapytanie_mojej_rosnacy(a-1);
                wstaw_odejmowanie_rosnace(a, szuk_index-1, pop_wart_rosnaca);
                
                

            }
            
            
            if(poprzednia_wart_a < pop_wartosc && obecna_wartosc_a >= pop_wartosc ) {
                
                int szuk_index = zapytanie_min_malejacy(0, a-1);
                int moja_wart_mal = zapytanie_mojej_malejacy(a);
                
                wstaw_odejmowanie_malejace(szuk_index+1, a-1, -moja_wart_mal);
                
                

            }
            
        }
        printf("%d\n", (drzewo_max_sumy[1]-1));
        

    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    wczytaj();
    
    
    return 0;
}
