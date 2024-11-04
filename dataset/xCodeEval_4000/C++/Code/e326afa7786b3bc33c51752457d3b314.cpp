#include <bits/stdc++.h>
using namespace std;
const int I=1e4+20;
int a,b,c,d,x[I],y[I];
int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<a;i++){
		if(y[i]==1){
			c=0;
			while(c<x[i]){
				cout<<"a";
				c++;
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==2){
			c=0;
			while(c<x[i]){
				if(c%2==0){
					cout<<"a";
					c++;
				}
				else{
					cout<<"b";
					c++;
				}
			}
				c=0;
				cout<<endl;
		}
		else if(y[i]==3){
			c=0;
			while(c<x[i]){
				if(c%3==0){
					cout<<"a";
					c++;
				}
				else if(c%3==1){
					cout<<"b";
					c++;
				}
				else{
					cout<<"c";
					c++;
				}
				
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==4){
			c=0;
			while(c<x[i]){
				if(c%4==0){
					cout<<"a";
					c++;
				}
				else if(c%4==1){
					cout<<"b";
					c++;
				}
				else if(c%4==2){
					cout<<"c";
					c++;
				}
				else if(c%4==3){
					cout<<"d";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==5){
			c=0;
			while(c<x[i]){
				if(c%5==0){
					cout<<"a";
					c++;
				}
				else if(c%5==1){
					cout<<"b";
					c++;
				}
				else if(c%5==2){
					cout<<"c";
					c++;
				}
				else if(c%5==3){
					cout<<"d";
					c++;
				}
				else if(c%5==4){
					cout<<"e";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==6){
			c=0;
			while(c<x[i]){
				if(c%6==0){
					cout<<"a";
					c++;
				}
				else if(c%6==1){
					cout<<"b";
					c++;
				}
				else if(c%6==2){
					cout<<"c";
					c++;
				}
				else if(c%6==3){
					cout<<"d";
					c++;
				}
				else if(c%6==4){
					cout<<"e";
					c++;
				}
				else if(c%6==5){
					cout<<"f";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==7){
			c=0;
			while(c<x[i]){
				if(c%7==0){
					cout<<"a";
					c++;
				}
				else if(c%7==1){
					cout<<"b";
					c++;
				}
				else if(c%7==2){
					cout<<"c";
					c++;
				}
				else if(c%7==3){
					cout<<"d";
					c++;
				}
				else if(c%7==4){
					cout<<"e";
					c++;
				}
				else if(c%7==5){
					cout<<"f";
					c++;
				}
				else if(c%7==6){
					cout<<"g";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==10){
			c=0;
			while(c<x[i]){
				if(c%10==0){
					cout<<"a";
					c++;
				}
				else if(c%10==1){
					cout<<"b";
					c++;
				}
				else if(c%10==2){
					cout<<"c";
					c++;
				}
				else if(c%10==3){
					cout<<"d";
					c++;
				}
				else if(c%10==4){
					cout<<"e";
					c++;
				}
				else if(c%10==5){
					cout<<"f";
					c++;
				}
				else if(c%10==6){
					cout<<"g";
					c++;
				}
				else if(c%10==7){
					cout<<"h";
					c++;
				}
				else if(c%10==8){
					cout<<"i";
					c++;
				}
				else if(c%10==9){
					cout<<"j";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==9){
			c=0;
			while(c<x[i]){
				if(c%9==0){
					cout<<"a";
					c++;
				}
				else if(c%9==1){
					cout<<"b";
					c++;
				}
				else if(c%9==2){
					cout<<"c";
					c++;
				}
				else if(c%9==3){
					cout<<"d";
					c++;
				}
				else if(c%9==4){
					cout<<"e";
					c++;
				}
				else if(c%9==5){
					cout<<"f";
					c++;
				}
				else if(c%9==6){
					cout<<"g";
					c++;
				}
				else if(c%9==7){
					cout<<"h";
					c++;
				}
				else if(c%9==8){
					cout<<"i";
					c++;				
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==8){
			c=0;
			while(c<x[i]){
				if(c%8==0){
					cout<<"a";
					c++;
				}
				else if(c%8==1){
					cout<<"b";
					c++;
				}
				else if(c%8==2){
					cout<<"c";
					c++;
				}
				else if(c%8==3){
					cout<<"d";
					c++;
				}
				else if(c%8==4){
					cout<<"e";
					c++;
				}
				else if(c%8==5){
					cout<<"f";
					c++;
				}
				else if(c%8==6){
					cout<<"g";
					c++;
				}
				else if(c%8==7){
					cout<<"h";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==11){
			c=0;
			while(c<x[i]){
				if(c%11==0){
					cout<<"a";
					c++;
				}
				else if(c%11==1){
					cout<<"b";
					c++;
				}
				else if(c%11==2){
					cout<<"c";
					c++;
				}
				else if(c%11==3){
					cout<<"d";
					c++;
				}
				else if(c%11==4){
					cout<<"e";
					c++;
				}
				else if(c%11==5){
					cout<<"f";
					c++;
				}
				else if(c%11==6){
					cout<<"g";
					c++;
				}
				else if(c%11==7){
					cout<<"h";
					c++;
				}
				else if(c%11==8){
					cout<<"i";
					c++;				
				}
				else if(c%11==9){
					cout<<"j";
					c++;
				}
				else if(c%11==10){
					cout<<"k";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==12){
			c=0;
			while(c<x[i]){
				if(c%12==0){
					cout<<"a";
					c++;
				}
				else if(c%12==1){
					cout<<"b";
					c++;
				}
				else if(c%12==2){
					cout<<"c";
					c++;
				}
				else if(c%12==3){
					cout<<"d";
					c++;
				}
				else if(c%12==4){
					cout<<"e";
					c++;
				}
				else if(c%12==5){
					cout<<"f";
					c++;
				}
				else if(c%12==6){
					cout<<"g";
					c++;
				}
				else if(c%12==7){
					cout<<"h";
					c++;
				}
				else if(c%12==8){
					cout<<"i";
					c++;				
				}
				else if(c%12==9){
					cout<<"j";
					c++;
				}
				else if(c%12==10){
					cout<<"k";
					c++;
				}
				else if(c%12==11){
					cout<<"l";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==13){
			c=0;
			while(c<x[i]){
				if(c%13==0){
					cout<<"a";
					c++;
				}
				else if(c%13==1){
					cout<<"b";
					c++;
				}
				else if(c%13==2){
					cout<<"c";
					c++;
				}
				else if(c%13==3){
					cout<<"d";
					c++;
				}
				else if(c%13==4){
					cout<<"e";
					c++;
				}
				else if(c%13==5){
					cout<<"f";
					c++;
				}
				else if(c%13==6){
					cout<<"g";
					c++;
				}
				else if(c%13==7){
					cout<<"h";
					c++;
				}
				else if(c%13==8){
					cout<<"i";
					c++;				
				}
				else if(c%13==9){
					cout<<"j";
					c++;
				}
				else if(c%13==10){
					cout<<"k";
					c++;
				}
				else if(c%13==11){
					cout<<"l";
					c++;
				}
				else if(c%13==12){
					cout<<"m";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==14){
			c=0;
			while(c<x[i]){
				if(c%14==0){
					cout<<"a";
					c++;
				}
				else if(c%14==1){
					cout<<"b";
					c++;
				}
				else if(c%14==2){
					cout<<"c";
					c++;
				}
				else if(c%14==3){
					cout<<"d";
					c++;
				}
				else if(c%14==4){
					cout<<"e";
					c++;
				}
				else if(c%14==5){
					cout<<"f";
					c++;
				}
				else if(c%14==6){
					cout<<"g";
					c++;
				}
				else if(c%14==7){
					cout<<"h";
					c++;
				}
				else if(c%14==8){
					cout<<"i";
					c++;				
				}
				else if(c%14==9){
					cout<<"j";
					c++;
				}
				else if(c%14==10){
					cout<<"k";
					c++;
				}
				else if(c%14==11){
					cout<<"l";
					c++;
				}
				else if(c%14==12){
					cout<<"m";
					c++;
				}
				else if(c%14==13){
					cout<<"n";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==15){
			c=0;
			while(c<x[i]){
				if(c%15==0){
					cout<<"a";
					c++;
				}
				else if(c%15==1){
					cout<<"b";
					c++;
				}
				else if(c%15==2){
					cout<<"c";
					c++;
				}
				else if(c%15==3){
					cout<<"d";
					c++;
				}
				else if(c%15==4){
					cout<<"e";
					c++;
				}
				else if(c%15==5){
					cout<<"f";
					c++;
				}
				else if(c%15==6){
					cout<<"g";
					c++;
				}
				else if(c%15==7){
					cout<<"h";
					c++;
				}
				else if(c%15==8){
					cout<<"i";
					c++;				
				}
				else if(c%15==9){
					cout<<"j";
					c++;
				}
				else if(c%15==10){
					cout<<"k";
					c++;
				}
				else if(c%15==11){
					cout<<"l";
					c++;
				}
				else if(c%15==12){
					cout<<"m";
					c++;
				}
				else if(c%15==13){
					cout<<"n";
					c++;
				}
				else if(c%15==14){
					cout<<"o";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==17){
			c=0;
			while(c<x[i]){
				if(c%17==0){
					cout<<"a";
					c++;
				}
				else if(c%17==1){
					cout<<"b";
					c++;
				}
				else if(c%17==2){
					cout<<"c";
					c++;
				}
				else if(c%17==3){
					cout<<"d";
					c++;
				}
				else if(c%17==4){
					cout<<"e";
					c++;
				}
				else if(c%17==5){
					cout<<"f";
					c++;
				}
				else if(c%17==6){
					cout<<"g";
					c++;
				}
				else if(c%17==7){
					cout<<"h";
					c++;
				}
				else if(c%17==8){
					cout<<"i";
					c++;				
				}
				else if(c%17==9){
					cout<<"j";
					c++;
				}
				else if(c%17==10){
					cout<<"k";
					c++;
				}
				else if(c%17==11){
					cout<<"l";
					c++;
				}
				else if(c%17==12){
					cout<<"m";
					c++;
				}
				else if(c%17==13){
					cout<<"n";
					c++;
				}
				else if(c%17==14){
					cout<<"o";
					c++;
				}
				else if(c%17==15){
					cout<<"p";
					c++;
				}
				else if(c%17==16){
					cout<<"q";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==16){
			c=0;
			while(c<x[i]){
				if(c%16==0){
					cout<<"a";
					c++;
				}
				else if(c%16==1){
					cout<<"b";
					c++;
				}
				else if(c%16==2){
					cout<<"c";
					c++;
				}
				else if(c%16==3){
					cout<<"d";
					c++;
				}
				else if(c%16==4){
					cout<<"e";
					c++;
				}
				else if(c%16==5){
					cout<<"f";
					c++;
				}
				else if(c%16==6){
					cout<<"g";
					c++;
				}
				else if(c%16==7){
					cout<<"h";
					c++;
				}
				else if(c%16==8){
					cout<<"i";
					c++;				
				}
				else if(c%16==9){
					cout<<"j";
					c++;
				}
				else if(c%16==10){
					cout<<"k";
					c++;
				}
				else if(c%16==11){
					cout<<"l";
					c++;
				}
				else if(c%16==12){
					cout<<"m";
					c++;
				}
				else if(c%16==13){
					cout<<"n";
					c++;
				}
				else if(c%16==14){
					cout<<"o";
					c++;
				}
				else if(c%16==15){
					cout<<"p";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==18){
			c=0;
			while(c<x[i]){
				if(c%18==0){
					cout<<"a";
					c++;
				}
				else if(c%18==1){
					cout<<"b";
					c++;
				}
				else if(c%18==2){
					cout<<"c";
					c++;
				}
				else if(c%18==3){
					cout<<"d";
					c++;
				}
				else if(c%18==4){
					cout<<"e";
					c++;
				}
				else if(c%18==5){
					cout<<"f";
					c++;
				}
				else if(c%18==6){
					cout<<"g";
					c++;
				}
				else if(c%18==7){
					cout<<"h";
					c++;
				}
				else if(c%18==8){
					cout<<"i";
					c++;				
				}
				else if(c%18==9){
					cout<<"j";
					c++;
				}
				else if(c%18==10){
					cout<<"k";
					c++;
				}
				else if(c%18==11){
					cout<<"l";
					c++;
				}
				else if(c%18==12){
					cout<<"m";
					c++;
				}
				else if(c%18==13){
					cout<<"n";
					c++;
				}
				else if(c%18==14){
					cout<<"o";
					c++;
				}
				else if(c%18==15){
					cout<<"p";
					c++;
				}
				else if(c%18==16){
					cout<<"q";
					c++;
				}
				else if(c%18==17){
					cout<<"r";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==19){
			c=0;
			while(c<x[i]){
				if(c%19==0){
					cout<<"a";
					c++;
				}
				else if(c%19==1){
					cout<<"b";
					c++;
				}
				else if(c%19==2){
					cout<<"c";
					c++;
				}
				else if(c%19==3){
					cout<<"d";
					c++;
				}
				else if(c%19==4){
					cout<<"e";
					c++;
				}
				else if(c%19==5){
					cout<<"f";
					c++;
				}
				else if(c%19==6){
					cout<<"g";
					c++;
				}
				else if(c%19==7){
					cout<<"h";
					c++;
				}
				else if(c%19==8){
					cout<<"i";
					c++;				
				}
				else if(c%19==9){
					cout<<"j";
					c++;
				}
				else if(c%19==10){
					cout<<"k";
					c++;
				}
				else if(c%19==11){
					cout<<"l";
					c++;
				}
				else if(c%19==12){
					cout<<"m";
					c++;
				}
				else if(c%19==13){
					cout<<"n";
					c++;
				}
				else if(c%19==14){
					cout<<"o";
					c++;
				}
				else if(c%19==15){
					cout<<"p";
					c++;
				}
				else if(c%19==16){
					cout<<"q";
					c++;
				}
				else if(c%19==17){
					cout<<"r";
					c++;
				}
				else if(c%19==18){
					cout<<"s";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==20){
			c=0;
			while(c<x[i]){
				if(c%20==0){
					cout<<"a";
					c++;
				}
				else if(c%20==1){
					cout<<"b";
					c++;
				}
				else if(c%20==2){
					cout<<"c";
					c++;
				}
				else if(c%20==3){
					cout<<"d";
					c++;
				}
				else if(c%20==4){
					cout<<"e";
					c++;
				}
				else if(c%20==5){
					cout<<"f";
					c++;
				}
				else if(c%20==6){
					cout<<"g";
					c++;
				}
				else if(c%20==7){
					cout<<"h";
					c++;
				}
				else if(c%20==8){
					cout<<"i";
					c++;				
				}
				else if(c%20==9){
					cout<<"j";
					c++;
				}
				else if(c%20==10){
					cout<<"k";
					c++;
				}
				else if(c%20==11){
					cout<<"l";
					c++;
				}
				else if(c%20==12){
					cout<<"m";
					c++;
				}
				else if(c%20==13){
					cout<<"n";
					c++;
				}
				else if(c%20==14){
					cout<<"o";
					c++;
				}
				else if(c%20==15){
					cout<<"p";
					c++;
				}
				else if(c%20==16){
					cout<<"q";
					c++;
				}
				else if(c%20==17){
					cout<<"r";
					c++;
				}
				else if(c%20==18){
					cout<<"s";
					c++;
				}
				else if(c%20==19){
					cout<<"t";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==21){
			c=0;
			while(c<x[i]){
				if(c%21==0){
					cout<<"a";
					c++;
				}
				else if(c%21==1){
					cout<<"b";
					c++;
				}
				else if(c%21==2){
					cout<<"c";
					c++;
				}
				else if(c%21==3){
					cout<<"d";
					c++;
				}
				else if(c%21==4){
					cout<<"e";
					c++;
				}
				else if(c%21==5){
					cout<<"f";
					c++;
				}
				else if(c%21==6){
					cout<<"g";
					c++;
				}
				else if(c%21==7){
					cout<<"h";
					c++;
				}
				else if(c%21==8){
					cout<<"i";
					c++;				
				}
				else if(c%21==9){
					cout<<"j";
					c++;
				}
				else if(c%21==10){
					cout<<"k";
					c++;
				}
				else if(c%21==11){
					cout<<"l";
					c++;
				}
				else if(c%21==12){
					cout<<"m";
					c++;
				}
				else if(c%21==13){
					cout<<"n";
					c++;
				}
				else if(c%21==14){
					cout<<"o";
					c++;
				}
				else if(c%21==15){
					cout<<"p";
					c++;
				}
				else if(c%21==16){
					cout<<"q";
					c++;
				}
				else if(c%21==17){
					cout<<"r";
					c++;
				}
				else if(c%21==18){
					cout<<"s";
					c++;
				}
				else if(c%21==19){
					cout<<"t";
					c++;
				}
				else if(c%21==20){
					cout<<"u";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==22){
			c=0;
			while(c<x[i]){
				if(c%22==0){
					cout<<"a";
					c++;
				}
				else if(c%22==1){
					cout<<"b";
					c++;
				}
				else if(c%22==2){
					cout<<"c";
					c++;
				}
				else if(c%22==3){
					cout<<"d";
					c++;
				}
				else if(c%22==4){
					cout<<"e";
					c++;
				}
				else if(c%22==5){
					cout<<"f";
					c++;
				}
				else if(c%22==6){
					cout<<"g";
					c++;
				}
				else if(c%22==7){
					cout<<"h";
					c++;
				}
				else if(c%22==8){
					cout<<"i";
					c++;				
				}
				else if(c%22==9){
					cout<<"j";
					c++;
				}
				else if(c%22==10){
					cout<<"k";
					c++;
				}
				else if(c%22==11){
					cout<<"l";
					c++;
				}
				else if(c%22==12){
					cout<<"m";
					c++;
				}
				else if(c%22==13){
					cout<<"n";
					c++;
				}
				else if(c%22==14){
					cout<<"o";
					c++;
				}
				else if(c%22==15){
					cout<<"p";
					c++;
				}
				else if(c%22==16){
					cout<<"q";
					c++;
				}
				else if(c%22==17){
					cout<<"r";
					c++;
				}
				else if(c%22==18){
					cout<<"s";
					c++;
				}
				else if(c%22==19){
					cout<<"t";
					c++;
				}
				else if(c%22==20){
					cout<<"u";
					c++;
				}
				else if(c%22==21){
					cout<<"v";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==23){
			c=0;
			while(c<x[i]){
				if(c%23==0){
					cout<<"a";
					c++;
				}
				else if(c%23==1){
					cout<<"b";
					c++;
				}
				else if(c%23==2){
					cout<<"c";
					c++;
				}
				else if(c%23==3){
					cout<<"d";
					c++;
				}
				else if(c%23==4){
					cout<<"e";
					c++;
				}
				else if(c%23==5){
					cout<<"f";
					c++;
				}
				else if(c%23==6){
					cout<<"g";
					c++;
				}
				else if(c%23==7){
					cout<<"h";
					c++;
				}
				else if(c%23==8){
					cout<<"i";
					c++;				
				}
				else if(c%23==9){
					cout<<"j";
					c++;
				}
				else if(c%23==10){
					cout<<"k";
					c++;
				}
				else if(c%23==11){
					cout<<"l";
					c++;
				}
				else if(c%23==12){
					cout<<"m";
					c++;
				}
				else if(c%23==13){
					cout<<"n";
					c++;
				}
				else if(c%23==14){
					cout<<"o";
					c++;
				}
				else if(c%23==15){
					cout<<"p";
					c++;
				}
				else if(c%23==16){
					cout<<"q";
					c++;
				}
				else if(c%23==17){
					cout<<"r";
					c++;
				}
				else if(c%23==18){
					cout<<"s";
					c++;
				}
				else if(c%23==19){
					cout<<"t";
					c++;
				}
				else if(c%23==20){
					cout<<"u";
					c++;
				}
				else if(c%23==21){
					cout<<"v";
					c++;
				}
				else if(c%23==22){
					cout<<"w";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==24){
			c=0;
			while(c<x[i]){
				if(c%24==0){
					cout<<"a";
					c++;
				}
				else if(c%24==1){
					cout<<"b";
					c++;
				}
				else if(c%24==2){
					cout<<"c";
					c++;
				}
				else if(c%24==3){
					cout<<"d";
					c++;
				}
				else if(c%24==4){
					cout<<"e";
					c++;
				}
				else if(c%24==5){
					cout<<"f";
					c++;
				}
				else if(c%24==6){
					cout<<"g";
					c++;
				}
				else if(c%24==7){
					cout<<"h";
					c++;
				}
				else if(c%24==8){
					cout<<"i";
					c++;				
				}
				else if(c%24==9){
					cout<<"j";
					c++;
				}
				else if(c%24==10){
					cout<<"k";
					c++;
				}
				else if(c%24==11){
					cout<<"l";
					c++;
				}
				else if(c%24==12){
					cout<<"m";
					c++;
				}
				else if(c%24==13){
					cout<<"n";
					c++;
				}
				else if(c%24==14){
					cout<<"o";
					c++;
				}
				else if(c%24==15){
					cout<<"p";
					c++;
				}
				else if(c%24==16){
					cout<<"q";
					c++;
				}
				else if(c%24==17){
					cout<<"r";
					c++;
				}
				else if(c%24==18){
					cout<<"s";
					c++;
				}
				else if(c%24==19){
					cout<<"t";
					c++;
				}
				else if(c%24==20){
					cout<<"u";
					c++;
				}
				else if(c%24==21){
					cout<<"v";
					c++;
				}
				else if(c%24==22){
					cout<<"w";
					c++;
				}
				else if(c%24==23){
					cout<<"x";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==25){
			c=0;
			while(c<x[i]){
				if(c%25==0){
					cout<<"a";
					c++;
				}
				else if(c%25==1){
					cout<<"b";
					c++;
				}
				else if(c%25==2){
					cout<<"c";
					c++;
				}
				else if(c%25==3){
					cout<<"d";
					c++;
				}
				else if(c%25==4){
					cout<<"e";
					c++;
				}
				else if(c%25==5){
					cout<<"f";
					c++;
				}
				else if(c%25==6){
					cout<<"g";
					c++;
				}
				else if(c%25==7){
					cout<<"h";
					c++;
				}
				else if(c%25==8){
					cout<<"i";
					c++;				
				}
				else if(c%25==9){
					cout<<"j";
					c++;
				}
				else if(c%25==10){
					cout<<"k";
					c++;
				}
				else if(c%25==11){
					cout<<"l";
					c++;
				}
				else if(c%25==12){
					cout<<"m";
					c++;
				}
				else if(c%25==13){
					cout<<"n";
					c++;
				}
				else if(c%25==14){
					cout<<"o";
					c++;
				}
				else if(c%25==15){
					cout<<"p";
					c++;
				}
				else if(c%25==16){
					cout<<"q";
					c++;
				}
				else if(c%25==17){
					cout<<"r";
					c++;
				}
				else if(c%25==18){
					cout<<"s";
					c++;
				}
				else if(c%25==19){
					cout<<"t";
					c++;
				}
				else if(c%25==20){
					cout<<"u";
					c++;
				}
				else if(c%25==21){
					cout<<"v";
					c++;
				}
				else if(c%25==22){
					cout<<"w";
					c++;
				}
				else if(c%25==23){
					cout<<"x";
					c++;
				}
				else if(c%25==24){
					cout<<"y";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
		else if(y[i]==26){
			c=0;
			while(c<x[i]){
				if(c%26==0){
					cout<<"a";
					c++;
				}
				else if(c%26==1){
					cout<<"b";
					c++;
				}
				else if(c%26==2){
					cout<<"c";
					c++;
				}
				else if(c%26==3){
					cout<<"d";
					c++;
				}
				else if(c%26==4){
					cout<<"e";
					c++;
				}
				else if(c%26==5){
					cout<<"f";
					c++;
				}
				else if(c%26==6){
					cout<<"g";
					c++;
				}
				else if(c%26==7){
					cout<<"h";
					c++;
				}
				else if(c%26==8){
					cout<<"i";
					c++;				
				}
				else if(c%26==9){
					cout<<"j";
					c++;
				}
				else if(c%26==10){
					cout<<"k";
					c++;
				}
				else if(c%26==11){
					cout<<"l";
					c++;
				}
				else if(c%26==12){
					cout<<"m";
					c++;
				}
				else if(c%26==13){
					cout<<"n";
					c++;
				}
				else if(c%26==14){
					cout<<"o";
					c++;
				}
				else if(c%26==15){
					cout<<"p";
					c++;
				}
				else if(c%26==16){
					cout<<"q";
					c++;
				}
				else if(c%26==17){
					cout<<"r";
					c++;
				}
				else if(c%26==18){
					cout<<"s";
					c++;
				}
				else if(c%26==19){
					cout<<"t";
					c++;
				}
				else if(c%26==20){
					cout<<"u";
					c++;
				}
				else if(c%26==21){
					cout<<"v";
					c++;
				}
				else if(c%26==22){
					cout<<"w";
					c++;
				}
				else if(c%26==23){
					cout<<"x";
					c++;
				}
				else if(c%26==24){
					cout<<"y";
					c++;
				}
				else{
					cout<<"z";
					c++;
				}
			}
			c=0;
			cout<<endl;
		}
	}
}

