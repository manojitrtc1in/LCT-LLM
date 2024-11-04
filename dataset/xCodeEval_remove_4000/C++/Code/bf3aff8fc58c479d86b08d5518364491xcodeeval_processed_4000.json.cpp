












using namespace std;
il int read(){
	rc c=' ';
	ri v=0,x=1;
	while((c<'0')||(c>'9')){if(c=='-') x=-1;c=getchar();}
	while((c>='0')&&(c<='9')){v=(v<<1)+(v<<3)+(c^48);c=getchar();}
	return v*x;
}
char str[110][110];
int t,n,m,a[110][110];
struct Node{
	pair<int,int> x;
	pair<int,int> y;
	pair<int,int> z;
};
vector<Node> ans;
il void id0(vec tmp0,vec tmp1);

il void id2(vec tmp0,vec tmp1);

il void id6(vec tmp0,vec tmp1);

il void id11(vec tmp0,vec tmp1);

il void id9(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id5(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id1(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id3(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id8(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id4(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id12(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id10(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id7(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31);

il void id0(vec tmp0,vec tmp1){
	Node tmp={tmp0[0],tmp0[1],tmp1[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp0[2]);
	new0.push_back(tmp1[0]);
	new1.push_back(tmp0[0]);
	new1.push_back(tmp0[1]);
	id2(new0,new1);
}

il void id2(vec tmp0,vec tmp1){
	Node tmp={tmp0[0],tmp0[1],tmp1[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp1[0]);
	new1.push_back(tmp0[0]);
	new1.push_back(tmp0[1]);
	new1.push_back(tmp1[1]);
	id6(new0,new1);
}

il void id6(vec tmp0,vec tmp1){
	Node tmp={tmp1[0],tmp1[1],tmp1[2]};
	ans.push_back(tmp);
}

il void id11(vec tmp0,vec tmp1){
	Node tmp={tmp1[0],tmp1[1],tmp1[2]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp1[0]);
	new0.push_back(tmp1[1]);
	new0.push_back(tmp1[2]);
	new1.push_back(tmp1[3]);
	id0(new0,new1);
}

il void id9(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp20[0],tmp20[1]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp30[0]);
	new1.push_back(tmp20[0]);
	new1.push_back(tmp20[1]);
	new1.push_back(tmp31[0]);
	id6(new0,new1);
}

il void id5(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp20[0],tmp31[0],tmp31[1]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp10[0]);
	new0.push_back(tmp20[1]);
	new1.push_back(tmp11[0]);
	new1.push_back(tmp20[0]);
	id2(new0,new1);
}

il void id1(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp20[0],tmp21[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp21[0]);
	new0.push_back(tmp30[0]);
	new1.push_back(tmp20[0]);
	new1.push_back(tmp31[0]);
	id2(new0,new1);
}

il void id3(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp20[0],tmp21[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp21[0]);
	new1.push_back(tmp20[0]);
	new1.push_back(tmp31[0]);
	new1.push_back(tmp31[1]);
	id6(new0,new1);
}

il void id8(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp21[0],tmp21[1]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp21[0]);
	new0.push_back(tmp21[1]);
	new0.push_back(tmp30[0]);
	new1.push_back(tmp31[0]);
	id0(new0,new1);
}

il void id4(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp21[0],tmp21[1]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp21[0]);
	new0.push_back(tmp21[1]);
	new1.push_back(tmp31[0]);
	new1.push_back(tmp31[1]);
	id2(new0,new1);
}

il void id12(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp11[1],tmp20[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp20[1]);
	new1.push_back(tmp20[0]);
	new1.push_back(tmp31[0]);
	new1.push_back(tmp31[1]);
	id6(new0,new1);
}

il void id10(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp11[1],tmp21[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp20[0]);
	new0.push_back(tmp21[0]);
	new1.push_back(tmp31[0]);
	new1.push_back(tmp31[1]);
	id2(new0,new1);
}

il void id7(vec tmp10,vec tmp11,vec tmp20,vec tmp21,vec tmp30,vec tmp31){
	Node tmp={tmp11[0],tmp11[1],tmp21[0]};
	ans.push_back(tmp);
	vec new0,new1;
	new0.push_back(tmp21[0]);
	new1.push_back(tmp21[1]);
	new1.push_back(tmp31[0]);
	new1.push_back(tmp31[1]);
	id6(new0,new1);
}

il void solve22(ri X1,ri X2,ri Y1,ri Y2){
	

	vec tmp[2];
	tmp[a[X1][Y1]].push_back(make_pair(X1,Y1));
	tmp[a[X1][Y2]].push_back(make_pair(X1,Y2));
	tmp[a[X2][Y1]].push_back(make_pair(X2,Y1));
	tmp[a[X2][Y2]].push_back(make_pair(X2,Y2));
	if(tmp[1].size()==1) id0(tmp[0],tmp[1]);
	if(tmp[1].size()==2) id2(tmp[0],tmp[1]);
	if(tmp[1].size()==3) id6(tmp[0],tmp[1]);
	if(tmp[1].size()==4) id11(tmp[0],tmp[1]);
	a[X1][Y1]=a[X1][Y2]=a[X2][Y1]=a[X2][Y2]=0;
}

il void solve23(ri X1,ri X2,ri Y1,ri Y2,ri Y3){
	

	vec tmp[5][2];
	tmp[1][a[X1][Y1]].push_back(make_pair(X1,Y1));
	tmp[1][a[X2][Y1]].push_back(make_pair(X2,Y1));
	tmp[2][a[X1][Y2]].push_back(make_pair(X1,Y2));
	tmp[2][a[X2][Y2]].push_back(make_pair(X2,Y2));
	tmp[3][a[X1][Y3]].push_back(make_pair(X1,Y3));
	tmp[3][a[X2][Y3]].push_back(make_pair(X2,Y3));
	if(!tmp[1][1].size()) solve22(X1,X2,Y2,Y3);
	else if(!tmp[3][1].size()) solve22(X1,X2,Y1,Y2);
	else{  
		if(tmp[1][1].size()==2&&tmp[3][1].size()==1){
			swap(tmp[1][0],tmp[3][0]);
			swap(tmp[1][1],tmp[3][1]);
		}
		ri siz1=tmp[1][1].size();
		ri siz2=tmp[2][1].size();
		ri siz3=tmp[3][1].size();
		if(siz1==1&&!siz2&&siz3==1)
			id9(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&!siz2&&siz3==2)
			id5(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==1&&siz3==1)
			id1(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==1&&siz3==2)
			id3(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==2&&siz3==1)
			id8(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==2&&siz3==2)
			id4(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&!siz2&&siz3==2)
			id12(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&siz2==1&&siz3==2)
			id10(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&siz2==2&&siz3==2)
			id7(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
	}
	a[X1][Y1]=a[X1][Y2]=a[X1][Y3]=a[X2][Y1]=a[X2][Y2]=a[X2][Y3]=0;
}

il void solve32(ri X1,ri X2,ri X3,ri Y1,ri Y2){
	

	vec tmp[5][2];
	tmp[1][a[X1][Y1]].push_back(make_pair(X1,Y1));
	tmp[1][a[X1][Y2]].push_back(make_pair(X1,Y2));
	tmp[2][a[X2][Y1]].push_back(make_pair(X2,Y1));
	tmp[2][a[X2][Y2]].push_back(make_pair(X2,Y2));
	tmp[3][a[X3][Y1]].push_back(make_pair(X3,Y1));
	tmp[3][a[X3][Y2]].push_back(make_pair(X3,Y2));
	if(!tmp[1][1].size()) solve22(X2,X3,Y1,Y2);
	else if(!tmp[3][1].size()) solve22(X1,X2,Y1,Y2);
	else{  
		if(tmp[1][1].size()==2&&tmp[3][1].size()==1){
			swap(tmp[1][0],tmp[3][0]);
			swap(tmp[1][1],tmp[3][1]);
		}
		ri siz1=tmp[1][1].size();
		ri siz2=tmp[2][1].size();
		ri siz3=tmp[3][1].size();
		if(siz1==1&&!siz2&&siz3==1)
			id9(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&!siz2&&siz3==2)
			id5(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==1&&siz3==1)
			id1(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==1&&siz3==2)
			id3(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==2&&siz3==1)
			id8(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==1&&siz2==2&&siz3==2)
			id4(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&!siz2&&siz3==2)
			id12(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&siz2==1&&siz3==2)
			id10(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
		if(siz1==2&&siz2==2&&siz3==2)
			id7(tmp[1][0],tmp[1][1],tmp[2][0],tmp[2][1],tmp[3][0],tmp[3][1]);
	}
	a[X1][Y1]=a[X1][Y2]=a[X2][Y1]=a[X2][Y2]=a[X3][Y1]=a[X3][Y2]=0;
}

il void solve33(ri X1,ri X2,ri X3,ri Y1,ri Y2,ri Y3){
	

	solve23(X1,X2,Y1,Y2,Y3);
	solve23(X2,X3,Y1,Y2,Y3);
}

il void work(){
	n=read(),m=read();
	for(ri i=1;i<=n;i++){
		scanf("%s",str[i]+1);
		for(ri j=1;j<=m;j++)
			a[i][j]=str[i][j]^48; 
	}
	ans.clear();
	for(ri i=1;i<=n;i+=2){
		if(i+2==n){
			for(ri j=1;j<=m;j+=2){
				if(j+2==m){
					solve33(i,i+1,i+2,j,j+1,j+2);
					break;
				}
				else solve32(i,i+1,i+2,j,j+1);
			}
			break;
		}
		for(ri j=1;j<=m;j+=2){
			if(j+2==m){
				solve23(i,i+1,j,j+1,j+2);
				break;
			}
			else solve22(i,i+1,j,j+1);
		}
	}
	printf("%d\n",(int)ans.size());
	for(ri i=0;i<(int)ans.size();i++){
		printf("%d %d ",ans[i].x.first,ans[i].x.second);
		printf("%d %d ",ans[i].y.first,ans[i].y.second);
		printf("%d %d\n",ans[i].z.first,ans[i].z.second);
	}
}
int main(){
	t=read();
	while(t--) work();
	return ~~(0-0);
}