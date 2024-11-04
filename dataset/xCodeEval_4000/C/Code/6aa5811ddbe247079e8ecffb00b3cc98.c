
#include<stdio.h>
#define N 100001
long long min2(long long a,long long b){
    if(a > b)return b;
    else return a;
}
void print_i(char * total,int start,int end){
    int i=start;
    while(1){
        if(start > end){
            if(i < end)break;
        }else if(start < end){
            if(i > end)break;
        }else{
            if(i!=end)break;
        }
        printf("%c",total[i]);
        if(start > end){
            i--;
        }else{
            i++;
        }
    }
}
void print_all(char * total,int *first,int *second){
    print_i(total,first[1],first[2]);
    printf(": %d",first[0]);
    if(second[0]!=-1){
        printf(", ");
        print_i(total,second[1],second[2]);
        printf(": %d",second[0]);
    }
    printf("\n");
}
int compare(char *total,int start1,int end1,int start2,int end2){
    int i=start1;
    int j=start2;
    while(1){
        if(start1 > end1){
            if(i < end1)break;
        }else if(start1 < end1){
            if(i > end1)break;
        }else{
            if(i!=end1)break;
        }
        if(start2 > end2){
            if(j < end2)break;
        }else if(start2 < end2){
            if(j > end2)break;
        }else{
            if(j!=end2)break;
        }

        if(total[i] > total[j]){
            return 1;
        }else if(total[i] < total[j]){
            return -1;
        }
        if(start1 > end1){
            i--;
        }else{
            i++;
        }
        if(start2 > end2){
            j--;
        }else{
            j++;
        }
    }
    int size1;
    if(start1 > end1){
        size1=start1-end1+1;
    }else{
        size1=end1-start1+1;
    }
    int size2;
    if(start2 > end2){
        size2=start2-end2+1;
    }else{
        size2=end2-start2+1;
    }
    if(size1 > size2){
        return 1;
    }else if(size1 < size2){
        return -1;
    }else{
        return 0;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    

    int c[N];
    int i,j;
    for(i=0;i < n;i++){
        scanf("%d",&c[i]);
    }
    struct data{
        int start;
        int end;
    };
    struct data a[N];
    char total[N];
    j=0;
    getchar();
    for(i=0;i < n;i++){
        a[i].start=j;
        while(1){
            char some=getchar();
            if(some=='\n' || some==EOF)break;
            total[j]=some;
            j++;
        }
        a[i].end=j-1;
    }
    
    long long first[3];
    long long second[3];
    

    int start1=a[0].start;
    int end1=a[0].end;

    int start2=a[0].end;
    int end2=a[0].start;

    int result=compare(total,start1,end1,start2,end2);
    if(result==-1){
        

        

        

        first[0]=0;
        first[1]=a[0].start;
        first[2]=a[0].end;
        second[0]=-1;
        second[1]=-1;
        second[2]=-1;

    }else{
        
        

        

        

        

        first[0]=c[0];
        first[1]=a[0].end;
        first[2]=a[0].start;
        second[0]=0;
        second[1]=a[0].start;
        second[2]=a[0].end;

    }
    

    int can=1;
    int result1,result2,result3,result4,result5;
    

    for(i=1;i < n;i++){
        
        

        

        start1=a[i].start;
        end1=a[i].end;

        start2=first[1];
        end2=first[2];

        result1=compare(total,start1,end1,start2,end2);

        

        start1=a[i].end;
        end1=a[i].start;

        start2=first[1];
        end2=first[2];

        result2=compare(total,start1,end1,start2,end2);
        

        start1=a[i].start;
        end1=a[i].end;

        start2=a[i].end;
        end2=a[i].start;

        result5=compare(total,start1,end1,start2,end2);

        if(second[0]!=-1){
            

            start1=a[i].start;
            end1=a[i].end;

            start2=second[1];
            end2=second[2];

            result3=compare(total,start1,end1,start2,end2);

            

            start1=a[i].end;
            end1=a[i].start;

            start2=second[1];
            end2=second[2];

            result4=compare(total,start1,end1,start2,end2);
        }
        if(result1==-1){
            

            

            

            if(result2==-1){
                

                

                

                

                

                can=0;
                break;
            }else{
                

                

                
                if(second[0]==-1){
                    

                    

                    

                    first[0]=first[0]+(long long)c[i];
                    first[1]=a[i].end;
                    first[2]=a[i].start;
                    second[0]=-1;
                    second[1]=-1;
                    second[2]=-1;
                }else{
                    

                    

                    

                    

                    if(result4==-1){
                        

                        

                        

                        
                        

                        first[0]=first[0]+(long long)c[i];
                        first[1]=a[i].end;
                        first[2]=a[i].start;
                        second[0]=-1;
                        second[1]=-1;
                        second[2]=-1;
                    }else{
                        

                        

                        

                        

                        first[0]=min2(first[0],second[0])+(long long)c[i];
                        first[1]=a[i].end;
                        first[2]=a[i].start;
                        second[0]=-1;
                        second[1]=-1;
                        second[2]=-1;
                    }
                }
            }
        }else{
            

            

            if(result2==-1){
                

                

                

                

                if(second[0]==-1){
                    

                    

                    

                    
                    first[0]=first[0];
                    first[1]=a[i].start;
                    first[2]=a[i].end;
                    second[0]=-1;
                    second[1]=-1;
                    second[2]=-1;

                }else{
                    

                    

                    

                    if(result3==-1){
                        

                        

                        

                        
                        first[0]=first[0];
                        first[1]=a[i].start;
                        first[2]=a[i].end;
                        second[0]=-1;
                        second[1]=-1;
                        second[2]=-1;
                    }else{
                        

                        

                        first[0]=min2(first[0],second[0]);
                        first[1]=a[i].start;
                        first[2]=a[i].end;
                        second[0]=-1;
                        second[1]=-1;
                        second[2]=-1;
                    }
                }
            }else{
                

                

                

                

                if(second[0]==-1){
                    

                    

                    

                    

                    if(result5==-1){
                        

                        

                        

                        
                        first[0]=first[0];
                        first[1]=a[i].start;
                        first[2]=a[i].end;
                        second[0]=-1;
                        second[1]=-1;
                        second[2]=-1;
                    }else{
                        

                        

                        

                        
                        long long tmp=first[0];
                        first[0]=first[0]+(long long)c[i];
                        first[1]=a[i].end;
                        first[2]=a[i].start;
                        second[0]=tmp;

                        second[1]=a[i].start;
                        second[2]=a[i].end;
                    }
                }else{
                    

                    

                    

                    

                    long long tmp_first=first[0];
                    long long tmp_second=second[0];
                    if(result3==-1){
                        

                        
                        first[0]=tmp_first;
                        first[1]=a[i].start;
                        first[2]=a[i].end;
                    }else{
                        

                        

                        first[0]=min2(tmp_first,tmp_second);
                        first[1]=a[i].start;
                        first[2]=a[i].end;
                    }
                    

                    if(result4==-1){
                        

                        

                        second[0]=tmp_first+(long long)c[i];
                        second[1]=a[i].end;
                        second[2]=a[i].start;
                    }else{
                        

                        

                        second[0]=min2(tmp_first,tmp_second)+(long long)c[i];
                        second[1]=a[i].end;
                        second[2]=a[i].start;
                    }
                    

                    

                    if(result5==-1){
                        

                        if(first[0] > second[0]){
                            

                        }else{
                            

                            

                            second[0]=-1;
                            second[1]=-1;
                            second[2]=-1;
                        }
                    }else{
                        

                        

                        

                        if(first[0] >= second[0]){
                            

                            first[0]=second[0];
                            first[1]=second[1];
                            first[2]=second[2];
                            second[0]=-1;
                            second[1]=-1;
                            second[2]=-1;
                        }else{
                            

                            

                            long long tmp=first[0];
                            first[0]=second[0];
                            second[0]=tmp;

                            tmp=first[1];
                            first[1]=second[1];
                            second[1]=tmp;

                            tmp=first[2];
                            first[2]=second[2];
                            second[2]=tmp;
                        }
                    }
                }
            }
        }
        

        

    }
    if(can){
        if(second[0]==-1){
            printf("%lld\n",first[0]);
        }else{
            printf("%lld\n",min2(first[0],second[0]));
        }
    }else{
        printf("-1\n");
    }
    return 0;
}
