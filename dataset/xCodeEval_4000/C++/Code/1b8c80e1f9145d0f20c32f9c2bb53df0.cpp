#include<stdio.h>
#include<string.h>
#include<immintrin.h>
#include<emmintrin.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2")
#pragma GCC optimize("-fno-strict-aliasing")

#define U unsigned
#define LL long long
#define UL U LL
#define mod 1000000007u
#define dmod 2000000016u
#define ymm __m256i

alignas(64) U a1[50016];
alignas(64) U a2[50016];
alignas(64) U flag1[50016];
alignas(64) U flag2[50016];
alignas(64) U fa1_0[50016];
alignas(64) U fa1_1[50016];
alignas(64) U fa2_0[50016];
alignas(64) U fa2_1[50016];

void calc_f(U n,U&f0,U&f1)
{
    U ans[2][2]={{1,0},{0,1}};
    U a[2][2]={{1,1},{1,0}};
    U t[2][2];
    while(n)
    {
        if(n&1)
        {
            for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                U tmp=0;
                for(int k=0;k<2;k++)
                    tmp=(tmp+(UL)ans[i][k]*a[k][j])%mod;
                t[i][j]=tmp;
            }
            memcpy(ans,t,16);
        }
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            U tmp=0;
            for(int k=0;k<2;k++)
                tmp=(tmp+(UL)a[i][k]*a[k][j])%mod;
            t[i][j]=tmp;
        }
        memcpy(a,t,16);
        n>>=1;
    }
    f0=ans[1][1];
    f1=ans[0][1];
}

void set_min(int k,int l,int r,int x)
{
    U*a=k==1?a1:a2;
    U*flag=k==1?flag1:flag2;
    U*fa0=k==1?fa1_0:fa2_0;
    U*fa1=k==1?fa1_1:fa2_1;
    
    U f0,f1;
    calc_f(x,f0,f1);
    
    while(l<=r&&(l&7))
    {
        if(flag[l]||a[l]>x)
        {
            flag[l]=0;
            a[l]=x;
            fa0[l]=f0;
            fa1[l]=f1;
        }
        l++;
    }
    while(l<=r&&(r&7)<7)
    {
        if(flag[r]||a[r]>x)
        {
            flag[r]=0;
            a[r]=x;
            fa0[r]=f0;
            fa1[r]=f1;
        }
        r--;
    }
    ymm v0=_mm256_set_epi32(0,0,0,0,0,0,0,0);
    ymm vx=_mm256_set_epi32(x,x,x,x,x,x,x,x);
    ymm f0_vec=_mm256_set_epi32(f0,f0,f0,f0,f0,f0,f0,f0);
    ymm f1_vec=_mm256_set_epi32(f1,f1,f1,f1,f1,f1,f1,f1);
    
    for(int i=l;i<r;i+=8)
    {
        ymm flag_vec=*(ymm*)(flag+i);
        ymm a_vec=*(ymm*)(a+i);
        ymm b=_mm256_or_si256(_mm256_cmpgt_epi32(flag_vec,v0),_mm256_cmpgt_epi32(a_vec,vx));
        
        *(ymm*)(flag+i)=v0;
        *(ymm*)(a+i)=_mm256_blendv_epi8(a_vec,vx,b);
        *(ymm*)(fa0+i)=_mm256_blendv_epi8(*(ymm*)(fa0+i),f0_vec,b);
        *(ymm*)(fa1+i)=_mm256_blendv_epi8(*(ymm*)(fa1+i),f1_vec,b);
    }
}

void set_max(int k,int l,int r,int x)
{
    U*a=k==1?a1:a2;
    U*flag=k==1?flag1:flag2;
    U*fa0=k==1?fa1_0:fa2_0;
    U*fa1=k==1?fa1_1:fa2_1;
    
    U f0,f1;
    calc_f(x,f0,f1);
    
    while(l<=r&&(l&7))
    {
        if(!flag[l]&&a[l]<x)
        {
            flag[l]=0;
            a[l]=x;
            fa0[l]=f0;
            fa1[l]=f1;
        }
        l++;
    }
    while(l<=r&&(r&7)<7)
    {
        if(!flag[r]&&a[r]<x)
        {
            flag[r]=0;
            a[r]=x;
            fa0[r]=f0;
            fa1[r]=f1;
        }
        r--;
    }
    ymm v0=_mm256_set_epi32(0,0,0,0,0,0,0,0);
    ymm vx=_mm256_set_epi32(x,x,x,x,x,x,x,x);
    ymm f0_vec=_mm256_set_epi32(f0,f0,f0,f0,f0,f0,f0,f0);
    ymm f1_vec=_mm256_set_epi32(f1,f1,f1,f1,f1,f1,f1,f1);
    
    for(int i=l;i<r;i+=8)
    {
        ymm flag_vec=*(ymm*)(flag+i);
        ymm a_vec=*(ymm*)(a+i);
        ymm b=_mm256_and_si256(_mm256_cmpeq_epi32(flag_vec,v0),_mm256_cmpgt_epi32(vx,a_vec));
        
        *(ymm*)(flag+i)=_mm256_blendv_epi8(flag_vec,v0,b);
        *(ymm*)(a+i)=_mm256_blendv_epi8(a_vec,vx,b);
        *(ymm*)(fa0+i)=_mm256_blendv_epi8(*(ymm*)(fa0+i),f0_vec,b);
        *(ymm*)(fa1+i)=_mm256_blendv_epi8(*(ymm*)(fa1+i),f1_vec,b);
    }
}

ymm p_vec;
ymm p_inv_vec;
inline ymm mul_mod(ymm a,ymm b)
{
    ymm ans;
    
    ymm t1,t2;
    ymm ab_l,ab_h,ab_p;
    
    
    t1=_mm256_mul_epu32(a,b);
    t2=_mm256_mul_epu32(_mm256_srli_epi64(a,32),_mm256_srli_epi64(b,32));
    ab_l=_mm256_blend_epi32(t1,_mm256_slli_epi64(t2,32),0xaa);
    ab_h=_mm256_blend_epi32(_mm256_srli_epi64(t1,28),_mm256_slli_epi64(t2,4),0xaa);
    t1=_mm256_mul_epu32(ab_h,p_inv_vec);
    t2=_mm256_mul_epu32(_mm256_srli_epi64(ab_h,32),p_inv_vec);
    ab_p=_mm256_blend_epi32(_mm256_srli_epi64(t1,33),_mm256_srli_epi64(t2,1),0xaa);
    ans=_mm256_sub_epi32(ab_l,_mm256_mullo_epi32(ab_p,p_vec));
    ans=_mm256_sub_epi32(ans,_mm256_and_si256(_mm256_cmpgt_epi32(ans,p_vec),p_vec));
    
    return ans;
}

inline ymm add_mod(ymm a,ymm b)
{
    ymm t=_mm256_add_epi32(a,b);
    t=_mm256_sub_epi32(t,_mm256_and_si256(_mm256_cmpgt_epi32(t,p_vec),p_vec));
    return t;
}

void add(int k,int l,int r,int x)
{
    U*a=k==1?a1:a2;
    U*flag=k==1?flag1:flag2;
    U*fa0=k==1?fa1_0:fa2_0;
    U*fa1=k==1?fa1_1:fa2_1;
    U tx=x<0?x+dmod:x;
    
    U f0,f1,f2;
    calc_f(tx,f0,f1);
    f2=(f1+f0)%mod;
    

    while(l<=r&&(l&7))
    {
        a[l]+=tx;
        U t0=((UL)f0*fa0[l]+(UL)f1*fa1[l])%mod;
        U t1=((UL)f1*fa0[l]+(UL)f2*fa1[l])%mod;
        fa0[l]=t0;
        fa1[l]=t1;
        if(a[l]>=dmod)
        {
            a[l]-=dmod;
            if(x>0)flag[l]++;
        }
        else
        {
            if(x<0)flag[l]--;
        }
        l++;
    }
    while(l<=r&&(r&7)<7)
    {
        a[r]+=tx;
        U t0=((UL)f0*fa0[r]+(UL)f1*fa1[r])%mod;
        U t1=((UL)f1*fa0[r]+(UL)f2*fa1[r])%mod;
        fa0[r]=t0;
        fa1[r]=t1;
        if(a[r]>=dmod)
        {
            a[r]-=dmod;
            if(x>0)flag[r]++;
        }
        else
        {
            if(x<0)flag[r]--;
        }
        r--;
    }
    
    ymm v0=_mm256_set_epi32(0,0,0,0,0,0,0,0);
    ymm vx=_mm256_set_epi32(tx,tx,tx,tx,tx,tx,tx,tx);
    ymm f0_vec=_mm256_set_epi32(f0,f0,f0,f0,f0,f0,f0,f0);
    ymm f1_vec=_mm256_set_epi32(f1,f1,f1,f1,f1,f1,f1,f1);
    ymm f2_vec=_mm256_set_epi32(f2,f2,f2,f2,f2,f2,f2,f2);
    ymm dmod_vec=_mm256_set_epi32(dmod,dmod,dmod,dmod,dmod,dmod,dmod,dmod);
    ymm dmod1_vec=_mm256_set_epi32(dmod-1,dmod-1,dmod-1,dmod-1,dmod-1,dmod-1,dmod-1,dmod-1);
    ymm v1=_mm256_set_epi32(1,1,1,1,1,1,1,1);
    
    if(x<0)
    {
        for(int i=l;i<r;i+=8)
        {
            ymm flag_vec=*(ymm*)(flag+i);
            ymm a_vec=*(ymm*)(a+i);
            ymm fa0_vec=*(ymm*)(fa0+i);
            ymm fa1_vec=*(ymm*)(fa1+i);
            
            
            a_vec=_mm256_add_epi32(a_vec,vx);
            ymm b=_mm256_cmpgt_epi32(a_vec,dmod1_vec);

            

            for(int j=0;j<8;j++)
                if(!j[(U*)&a_vec]>=dmod)
                    flag[i+j]--;
            for(int j=0;j<8;j++)
            {
                a[i+j]=j[(U*)&a_vec];
                if(a[i+j]>=dmod)
                    a[i+j]-=dmod;
            }
            

            

            
            
            
            ymm t0=mul_mod(f0_vec,fa0_vec);
            ymm t1=mul_mod(f1_vec,fa1_vec);
            *(ymm*)(fa0+i)=add_mod(t0,t1);
            t0=mul_mod(f1_vec,fa0_vec);
            t1=mul_mod(f2_vec,fa1_vec);
            *(ymm*)(fa1+i)=add_mod(t0,t1);
            
        }
    }
    else
    {
        for(int i=l;i<r;i+=8)
        {
            ymm flag_vec=*(ymm*)(flag+i);
            ymm a_vec=*(ymm*)(a+i);
            ymm fa0_vec=*(ymm*)(fa0+i);
            ymm fa1_vec=*(ymm*)(fa1+i);
            
            
            a_vec=_mm256_add_epi32(a_vec,vx);
            ymm b=_mm256_cmpgt_epi32(a_vec,dmod1_vec);
            *(ymm*)(a+i)=_mm256_sub_epi32(a_vec,_mm256_and_si256(b,dmod_vec));
            *(ymm*)(flag+i)=_mm256_add_epi32(flag_vec,_mm256_and_si256(b,v1));
            
            
            
            ymm t0=mul_mod(f0_vec,fa0_vec);
            ymm t1=mul_mod(f1_vec,fa1_vec);
            *(ymm*)(fa0+i)=add_mod(t0,t1);
            t0=mul_mod(f1_vec,fa0_vec);
            t1=mul_mod(f2_vec,fa1_vec);
            *(ymm*)(fa1+i)=add_mod(t0,t1);
            
        }
    }
    
}

U query(int l,int r)
{
    U ans=0;
    while(l<=r&&(l&7))
    {
        ans=(ans+(UL)fa1_1[l]*fa2_0[l]+(UL)(fa1_0[l]+fa1_1[l])*fa2_1[l])%mod;
        l++;
    }
    while(l<=r&&(r&7)<7)
    {
        ans=(ans+(UL)fa1_1[r]*fa2_0[r]+(UL)(fa1_0[r]+fa1_1[r])*fa2_1[r])%mod;
        r--;
    }
    ymm ans_vec=_mm256_set_epi32(0,0,0,0,0,0,0,0);

    for(int i=l;i<r;i+=8)
    {
        ymm fa1_1_vec=*(ymm*)(fa1_1+i);
        ymm fa1_2_vec=add_mod(*(ymm*)(fa1_0+i),fa1_1_vec);
        ymm fa2_0_vec=*(ymm*)(fa2_0+i);
        ymm fa2_1_vec=*(ymm*)(fa2_1+i);
        ymm t=add_mod(mul_mod(fa1_1_vec,fa2_0_vec),mul_mod(fa1_2_vec,fa2_1_vec));
        ans_vec=add_mod(ans_vec,t);
    }

    for(int i=0;i<8;i++)
        ans=(ans+i[(U*)&ans_vec])%mod;
    return ans;
}

void cyc()
{
    int x=0,y=1,z;
    for(LL i=1;i<=20000000000ll;i++)
    {
        z=(x+y)%mod;
        x=y;
        y=z;
        if(x==0&&y==1)printf("%d\n",i);
    }
}

int main()
{
    p_vec=_mm256_set_epi32(mod,mod,mod,mod,mod,mod,mod,mod);
    p_inv_vec=_mm256_set_epi32(2305842993,2305842993,2305842993,2305842993,2305842993,2305842993,2305842993,2305842993);
    

    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a1+i);
        calc_f(a1[i],fa1_0[i],fa1_1[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a2+i);
        calc_f(a2[i],fa2_0[i],fa2_1[i]);
    }
    
    for(int i=0;i<q;i++)
    {
        int op,k,l,r,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d%d",&k,&l,&r,&x);
            set_min(k,l,r,x);
        }
        if(op==2)
        {
            scanf("%d%d%d%d",&k,&l,&r,&x);
            set_max(k,l,r,x);
        }
        if(op==3)
        {
            scanf("%d%d%d%d",&k,&l,&r,&x);
            add(k,l,r,x);
        }
        if(op==4)
        {
            scanf("%d%d",&l,&r);
            printf("%u\n",query(l,r)%mod);
        }
    }
}