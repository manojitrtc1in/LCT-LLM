









using namespace std;


void id21(string &a,string &b);
int id8(string a,string b);
string id6(string a,string b);
char id22(char first , char second,int &carry);
string id14(string a1,string b1);
char id19(char first,char second,int &carry);
string id18(string a,string b);
string id2(int a);
char id12(char first,char second,int &carry);
string id15(string a,char c);
string id3(string a,string b);


bool isValid(string num){
	if(num[0]=='0'){
		return false;
	}
	return true;
}







void id21(string &a,string &b){
	int maximum = max(a.size(),b.size());
	int minimum = min(a.size(),b.size());
	int id25 = maximum - minimum;
	

	if(a.size()==maximum){
		string id24 = "";
		while(id25--){
			id24+='0';
		}
		b = id24 + b;
	}
	else{
		string id24 = "";
		while(id25--){
			id24+='0';
		}
		a = id24 + a;
	}
	

	

}







int id8(string a1,string b1){
	bool aNegative = false;
	bool bNegative = false;
	int negativeFactor = 1;
	if(a1[0]=='-'){
		aNegative = true;
	}
	if(b1[0]=='-'){
		bNegative = true;
	}
	if(aNegative == true && bNegative == false){
		return -1;
	}
	else if(aNegative == false && bNegative == true){
		return 1;
	}
	else if(aNegative == true && bNegative == true) {
		negativeFactor = -1;
	}
	string a,b;
	a = a1;
	b = b1;
	id21(a,b);
	for(int i = 0;i<a.size();i++){
		if(a[i]>b[i]){
			return 1*negativeFactor;
		}
		else if(a[i]<b[i]){
			return -1*negativeFactor;
		}
	}
	return 0;
}

string id20(string a,string b){
	if(id8(a,b)==-1){
		return a;
	}
	else{
		return b;
	}
}

string id16(string a,string b){
	if(id8(a,b)==-1){
		return b;
	}
	else{
		return a;
	}
}

string id6(string a,string b){
	string printStatement = "";
	if(id8(a,b)==0){
		printStatement = "Both strings are equal";
	}
	else if(id8(a,b)==-1){
		printStatement = a + " is smaller than " + b;
	}
	else{
		printStatement = a +" is greater than " + b;
	}
	return printStatement;
}


char id22(char first , char second,int &carry){
	

	int f = first - '0';
	int s = second - '0';
	int sum = f + s + carry;
	carry = sum/10;
	sum = sum%10 + '0';
	return sum;
}


string id14(string a1,string b1){
	bool aNegative = false;
	bool bNegative = false;
	string a,b;
	if(a1[0]=='-'){
		aNegative = true;
		a = a1.substr(1);
	}
	else{
		a = a1;
	}
	if(b1[0]=='-'){
		bNegative = true;
		b = b1.substr(1);
	}
	else{
		b = b1;
	}
	bool bothNegative = false;
	if(aNegative==true && bNegative == true){
		bothNegative = true;
	}
	else if(aNegative == true){
		return id18(b,a);
	}
	else if(bNegative == true){
		return id18(a,b);
	}
	id21(a,b);
	

	

	


	

	string stringSum = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char append = id22(a[i],b[i],carry);
		stringSum += append;
		


	}
	

	if(carry>0){
		stringSum+='1';
	}
	if(bothNegative==true){
		stringSum+='-';
	}
	reverse(stringSum.begin(),stringSum.end());
	

	return stringSum;
}

char id19(char first,char second,int &carry){
	

	int f = first - '0';
	int s = second - '0';

	

	

	int subtract = f - s + carry;
	

	if(subtract<0){
		carry = -1;
		subtract+=10;
	}
	else{
		carry = 0;
	}
	

	char sub = subtract+'0';
	

	return sub;
}

string id18(string a1,string b1){
	bool aNegative = false;
	bool bNegative = false;
	string a,b;
	if(a1[0]=='-'){
		aNegative = true;
		a = a1.substr(1);
	}
	else{
		a = a1;
	}
	if(b1[0]=='-'){
		bNegative = true;
		b = b1.substr(1);
	}
	else{
		b = b1;
	}
	bool bothNegative = false;
	if((aNegative==true && bNegative == true)){
		return id18(b,a);
	}
	else if(aNegative == true){
		return "-"+id14(a,b);
	}
	else if(bNegative == true){
		return id14(a,b);
	}
	id21(a,b);
	string id7 = "";
	if(id8(a,b)==0){
		return "0";
	}
	else if(id8(a,b)==-1){
		string temp = a;
		a = b;
		b = temp;
		id7 = "-";
	}
	string subtract = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char append = id19(a[i],b[i],carry);
		subtract += append;
	}
	int zeroIndex = subtract.size()-1;
	int count = 0;
	

	

	while(subtract[zeroIndex]=='0'){
		

		zeroIndex--;
	}
	subtract = subtract.substr(0,zeroIndex+1);
	subtract+=id7;
	

	

	reverse(subtract.begin(),subtract.end());
	return subtract;
}

string id2(int a){
	string ans = "";
	while(a--){
		ans+='0';
	}
	return ans;
}

char id12(char first,char second,int &carry){
	

	int f = first - '0';
	int s = second - '0';
	int result = f*s + carry;
	carry = result/10;
	char retrn = result%10+'0';
	

	

	

	

	

	return retrn;
}

string id15(string a,char c){
	string ans = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char temp = id12(a[i],c,carry);
		ans+=temp;
		

		

		

	}
	if(carry>0){
		ans+=carry+'0';
	}
	reverse(ans.begin(),ans.end());
	


	


	

	return ans;
}

string id3(string a1,string b1){
    bool aNegative = false;
    bool bNegative = false;
    string a,b;
    if(a1[0]=='-'){
        aNegative = true;
        a = a1.substr(1);
    }
    else{
        a = a1;
    }
    if(b1[0]=='-'){
        bNegative = true;
        b = b1.substr(1);
    }
    else{
        b = b1;
    }
    if(aNegative ^ bNegative ){
        string temp = "-"+ id3(a,b);
        return temp;
    }
    string result = "";

    string id9;
    for(int i=b.size()-1;i>=0;i--){
        id9 = id15(a,b[i]);
        id9 = id9 + id2(b.size()-1-i);
        

        result = id14(id9,result);
        

    }
    int zeroIndex = 0;
    

    

    while(result[zeroIndex]=='0'){
        

        zeroIndex++;
    }
    result = result.substr(zeroIndex);
    

    if(result.size()==0){
        result = "0";
    }
    return result;
}















































































			










































void printString(string &a){
	if(a.size()>9000){
		cout<<"Nahi Print Karunga "<<endl;
	}
	else{
		cout<<a<<endl;
	}
}

string getMinimum(string integer,int id10){
	string temp = "";
	int count = 0;
	

	

	

	


	int count1 = id10/2;
	string id4;
	id4= integer.substr(0,count1);
	
	

	while(true){
		

		if(count1>0 && integer[count1]=='0'){
			count1--;
			

		}
		else{
			id4 = integer.substr(0,count1);
			break;
		}
	}
	
	string id17;
	id17 = integer.substr(count1);

	if(id17[0]=='0'){
		count = 0;
		while(count<100000){
			temp+='9';
			count++;
		}
		id17 = temp;
	}

	int count2 = id10/2;
	string id13 = integer.substr(0,count2);
	string id11 = integer.substr(count2);

	while(true){
		if(count2<id10 && integer[count2]=='0'){
			count2++;
		}
		else{
			id13 = integer.substr(0,count2);
			id11 = integer.substr(count2);
			break;
		}
	}

	
	if(id13[0]=='0'){
		if(temp.size()==0){
			count=0;
			while(count<100000){
				temp+='9';
				count++;
			}
		}
		id13 = temp;
	}




	

	


	int count3 = id10/2;
	string id0 = integer.substr(0,count3+1);
	

	while(true){
		if(count3 >=0 && integer[count3]=='0'){
			count3--;
		}
		else{
			id0 = integer.substr(0,++count3);
			break;
		}
	}
	

	string id23 = integer.substr(count3);

	if(id23[0]=='0'){
		if(temp.size()==0){
			count = 0;
			while(count<100000){
				temp+='9';
				count++;
			}
		}
		id23 = temp;
	}	
	int count4 = id10/2;
	string id5 = integer.substr(0,count4+1);
	string id1 = integer.substr(count4+1);
	while(true){
		if(count4<id10 && integer[count4]=='0'){
			count4++;
		}
		else{
			id5 = integer.substr(0,count4);
			id1 = integer.substr(count4);
			break;
		}
	}

	
	

	

	if(id5[0]=='0'){
		if(temp.size()==0){
			while(count<100000){
				temp+='9';
			}
		}
		id5 = temp;
	}

	

	


	

	


	

	


	

	


	

	


	

	


	

	


	

	


	

	

	

	

	

	

	


	

	

	

	

	

	

	

	


	string sum1 = id14(id4,id17);
	string sum2 = id14(id13,id11);
	string sum3 = id14(id0,id23);
	string sum4 = id14(id5,id1);

	return id20(id20(sum1,sum2),id20(sum3,sum4));
}



int main(){
	int id10;
	cin>>id10;
	string integer;
	cin>>integer;
	string ans = getMinimum(integer,id10);
	cout<<ans<<endl;

	

	

	

	

	


	

	

	


	

	


	

	


}