



using namespace std;

const int id35 = 524288;

int drzewo_rosnace_min[id35*2];
int drzewo_malejace_min[id35*2];
long long int wartosci_w_drzewie[id35*2];
int drzewo_odejmowania_rosnacy[id35*2];
int drzewo_odejmowania_malejacy[id35*2];
int indexy_min_rosnacy[id35*2];
int indexy_min_malejacy[id35*2];
int drzewo_max_sumy[id35*2];

int dp_rosnacy[300000+1];
int dp_malejacy[300000+1];

int id32;

void id29(int a, int b, long long int ile) {
    a += id35;
    b += id35;
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

long long int id20(int index) {
    index += id35;
    long long int wyn = wartosci_w_drzewie[index];
    index /= 2;
    while(index > 0) {
        wyn += wartosci_w_drzewie[index];
        index /= 2;
        
    }
    return wyn;
}

void id13(int a, int b, int ile) {
    a += id35;
    b += id35;
    
    
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

void id25(int a, int b, int ile) {
    a += id35;
    b += id35;
    
   
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

void id36(int a, int b, int ile, bool id6) {
    a += id35;
    b += id35;
    
    if(id6) {
        drzewo_odejmowania_rosnacy[a] += ile;
        drzewo_rosnace_min[a] += ile;
    } else {
        drzewo_odejmowania_malejacy[a] += ile;
        drzewo_malejace_min[a] += ile;
    }
    drzewo_max_sumy[a] += ile;
    
    
    if(a != b) {
        drzewo_max_sumy[b] += ile;
        if(id6) {
            drzewo_odejmowania_rosnacy[b] += ile;
            drzewo_rosnace_min[b] += ile;
        } else {
            drzewo_odejmowania_malejacy[b] += ile;
            drzewo_malejace_min[b] += ile;
        }
    }
    
    while(a / 2 != b / 2) {
        if(a%2 == 0) {
            if(id6) {
                drzewo_odejmowania_rosnacy[a+1] += ile;
                drzewo_rosnace_min[a+1] += ile;
            } else {
                drzewo_odejmowania_malejacy[a+1] += ile;
                drzewo_malejace_min[a+1] += ile;
            }
            drzewo_max_sumy[a+1] += ile;
        }
        if(b%2 == 1) {
            if(id6) {
                drzewo_odejmowania_rosnacy[b-1] += ile;
                drzewo_rosnace_min[b-1] += ile;
            } else {
                drzewo_odejmowania_malejacy[b-1] += ile;
                drzewo_malejace_min[b-1] += ile;
            }
            drzewo_max_sumy[b-1] += ile;
        }
        
        if(id6){
            
        
        
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
        if(id6) {
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

int id9(int a, int b) {
    a += id35;
    b += id35;
    
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

int id19(int a, int b) {
    if(a > b ) {
        return a;
    }
    a += id35;
    b += id35;
    
    int id4 = a-id35;
    int id23 = b-id35;
    
    int id2 = drzewo_rosnace_min[a];
    int id28 = drzewo_rosnace_min[b];
    
    while (a /2 != b/2) {
        if(a%2 == 0) {
            if(drzewo_rosnace_min[a+1] < id2) {
                id2 = drzewo_rosnace_min[a+1];
                id4 = indexy_min_rosnacy[a+1];
            }
        }
        if(b%2 == 1) {
            if(drzewo_rosnace_min[b-1] <= id28) {
                id28 = drzewo_rosnace_min[b-1];
                id23 = indexy_min_rosnacy[b-1];
            }
        }
        
        id2 += drzewo_odejmowania_rosnacy[a/2];
        id28 += drzewo_odejmowania_rosnacy[b/2];
        
        a/=2;
        b/=2;
    }
    
    
    if(id28  < id2) {
        id2 = id28;
        id4 = id23;
    }
    
    for(int i = a/2; i > 0; i/=2){
        id2 += drzewo_odejmowania_rosnacy[i];
    }
    
    if(id2 == 1) return id4;
    
    return id32;
}

int id3(int a, int b) {

    if(a > b ) {
        return b;
    }
    
    a += id35;
    b += id35;
    
    
    
    int id4 = a-id35;
    int id23 = b-id35;
    
    int id2 = drzewo_malejace_min[a];
    int id28 = drzewo_malejace_min[b];
    
    while (a /2 != b/2) {
        if(a%2 == 0) {
            if(drzewo_malejace_min[a+1] <= id2) {
                id2 = drzewo_malejace_min[a+1];
                id4 = indexy_min_malejacy[a+1];
            }
        }
        if(b%2 == 1) {
            if(drzewo_malejace_min[b-1] < id28) {
                id28 = drzewo_malejace_min[b-1];
                id23 = indexy_min_malejacy[b-1];
            }
        }
        
        id2 += drzewo_odejmowania_malejacy[a/2];
        id28 += drzewo_odejmowania_malejacy[b/2];
        
        a/=2;
        b/=2;
    }
    
    
    if(id2  < id28) {
        id28 = id2;
        id23 = id4;
    }
    
    for(int i = a/2; i > 0; i/=2){
        id28 += drzewo_odejmowania_malejacy[i];
    }
    
    if(id28 == 1) return id23;
    
    return -1;
}

void id31(int index, int wyn) {
    index += id35;
    drzewo_rosnace_min[index] = wyn;
    indexy_min_rosnacy[index] = index-id35;
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


void id30(int index, int wyn) {
    index += id35;
    drzewo_malejace_min[index] = wyn;
    indexy_min_malejacy[index] = index-id35;
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

int id17(int index) {
    index += id35;
    int wyn = drzewo_rosnace_min[index];
    
    for(int i = index/2; i > 0; i/=2) {
        wyn += drzewo_odejmowania_rosnacy[i];
    }
    return wyn;
}

int id8(int index) {
    index += id35;
    int wyn = drzewo_malejace_min[index];
    for(int i = index/2; i > 0; i/=2) {
        wyn += drzewo_odejmowania_malejacy[i];
    }
    return wyn;
}

void id27(int index, int wart) {
    index += id35;
    
    drzewo_max_sumy[index] = wart;
    
    for(int i = index/2; i > 0; i /= 2) {
        drzewo_max_sumy[i] = max(drzewo_max_sumy[i*2], drzewo_max_sumy[i*2+1]);
    }
}

void id22() {
    for(int i = 0; i < id32; ++i) {
        id27(i, dp_rosnacy[i] + dp_malejacy[i]);
    }
}



void id7() {
    

    

    for(int i = 0; i < id32; ++i) {
        cout << id8(i) << " ";
    }
    cout << endl;
}


void id24() {
    dp_rosnacy[0] = 1;
    id31(0, 1);
    for(int i = 1; i < id32; ++i) {
        if(id20(i) > id20(i-1)) {
            dp_rosnacy[i] = dp_rosnacy[i-1]+1;
        } else {
            dp_rosnacy[i] = 1;
        }
        
        id31(i, dp_rosnacy[i]);
        
    }
    
    dp_malejacy[id32-1] = 1;
    id30(id32-1, 1);
    for(int i = id32-2; i >= 0; --i) {
        if(id20(i) > id20(i+1)) {
            dp_malejacy[i] = dp_malejacy[i+1]+1;
        } else {
            dp_malejacy[i] = 1;
        }
        
        id30(i, dp_malejacy[i]);
    }
}

void id21() {
    scanf("%d", &id32);
    

    for(int i = 0; i < id32; ++i) {
        int id18;
        scanf("%d", &id18);
        

        id29(i, i, id18);
    }
    id24();
    id22();
    
    int id5;
    scanf("%d", &id5);
   

    
    for(int i = 0; i < id5; ++i) {
        int a, b, c;
       

        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        
        
        
        long long int id10 = id20(b);
        long long int id15 = id10 + c;
        long long int id34 = id20(a);
        long long int id14 = id34 + c;
        id29(a, b, c);
        
        
        if(b < id32-1  ) {
            long long int id33 = id20(b+1);
            if(id10  < id33 && id15 >= id33) {
                int id11 = id19(b+1, id32-1);
                int id0 = id17(b);
                id13(b+1, id11-1, -id0);
                

                
            }
            
            if(id10 <= id33 && id15 > id33) {
               

                
                
                int id11 = id3(0, b-1);
                int id26 = id8(b+1);
                id25(id11+1, b, id26);
               

            }
        }
        
        if(a > 0) {
            long long int id1 = id20(a-1);
            if( id34 <= id1 && id14 > id1) {
                int id11 = id19(a+1, id32-1);
                int id16 = id17(a-1);
                id13(a, id11-1, id16);
                
                

            }
            
            
            if(id34 < id1 && id14 >= id1 ) {
                
                int id11 = id3(0, a-1);
                int id12 = id8(a);
                
                id25(id11+1, a-1, -id12);
                
                

            }
            
        }
        printf("%d\n", (drzewo_max_sumy[1]-1));
        

    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    id21();
    
    
    return 0;
}
