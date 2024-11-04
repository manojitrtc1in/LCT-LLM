#include <iostream>
#include <vector>
#include <algorithm>


#include <utility>




using namespace std;


void makeTwoBigIntegersOfEqualLength(string &a,string &b);
int compareTwoBigIntegers(string a,string b);
string compareTwoBigIntegersPrint(string a,string b);
char addTwoChar(char first , char second,int &carry);
string addTwoBigIntegers(string a1,string b1);
char subtractTwoChar(char first,char second,int &carry);
string substractTwoBigIntegers(string a,string b);
string getZeroes(int a);
char multiplyTwoChar(char first,char second,int &carry);
string multiplyStringByChar(string a,char c);
string multiplyTwoBigIntegers(string a,string b);


bool isValid(string num){
	if(num[0]=='0'){
		return false;
	}
	return true;
}







void makeTwoBigIntegersOfEqualLength(string &a,string &b){
	int maximum = max(a.size(),b.size());
	int minimum = min(a.size(),b.size());
	int diffInLength = maximum - minimum;
	

	if(a.size()==maximum){
		string addInStart = "";
		while(diffInLength--){
			addInStart+='0';
		}
		b = addInStart + b;
	}
	else{
		string addInStart = "";
		while(diffInLength--){
			addInStart+='0';
		}
		a = addInStart + a;
	}
	

	

}







int compareTwoBigIntegers(string a1,string b1){
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
	makeTwoBigIntegersOfEqualLength(a,b);
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

string minOfTwoBigIntegers(string a,string b){
	if(compareTwoBigIntegers(a,b)==-1){
		return a;
	}
	else{
		return b;
	}
}

string maxOfTwoBigIntegers(string a,string b){
	if(compareTwoBigIntegers(a,b)==-1){
		return b;
	}
	else{
		return a;
	}
}

string compareTwoBigIntegersPrint(string a,string b){
	string printStatement = "";
	if(compareTwoBigIntegers(a,b)==0){
		printStatement = "Both strings are equal";
	}
	else if(compareTwoBigIntegers(a,b)==-1){
		printStatement = a + " is smaller than " + b;
	}
	else{
		printStatement = a +" is greater than " + b;
	}
	return printStatement;
}


char addTwoChar(char first , char second,int &carry){
	

	int f = first - '0';
	int s = second - '0';
	int sum = f + s + carry;
	carry = sum/10;
	sum = sum%10 + '0';
	return sum;
}


string addTwoBigIntegers(string a1,string b1){
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
		return substractTwoBigIntegers(b,a);
	}
	else if(bNegative == true){
		return substractTwoBigIntegers(a,b);
	}
	makeTwoBigIntegersOfEqualLength(a,b);
	

	

	


	

	string stringSum = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char append = addTwoChar(a[i],b[i],carry);
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

char subtractTwoChar(char first,char second,int &carry){
	

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

string substractTwoBigIntegers(string a1,string b1){
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
		return substractTwoBigIntegers(b,a);
	}
	else if(aNegative == true){
		return "-"+addTwoBigIntegers(a,b);
	}
	else if(bNegative == true){
		return addTwoBigIntegers(a,b);
	}
	makeTwoBigIntegersOfEqualLength(a,b);
	string negativeSignToBeAppend = "";
	if(compareTwoBigIntegers(a,b)==0){
		return "0";
	}
	else if(compareTwoBigIntegers(a,b)==-1){
		string temp = a;
		a = b;
		b = temp;
		negativeSignToBeAppend = "-";
	}
	string subtract = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char append = subtractTwoChar(a[i],b[i],carry);
		subtract += append;
	}
	int zeroIndex = subtract.size()-1;
	int count = 0;
	

	

	while(subtract[zeroIndex]=='0'){
		

		zeroIndex--;
	}
	subtract = subtract.substr(0,zeroIndex+1);
	subtract+=negativeSignToBeAppend;
	

	

	reverse(subtract.begin(),subtract.end());
	return subtract;
}

string getZeroes(int a){
	string ans = "";
	while(a--){
		ans+='0';
	}
	return ans;
}

char multiplyTwoChar(char first,char second,int &carry){
	

	int f = first - '0';
	int s = second - '0';
	int result = f*s + carry;
	carry = result/10;
	char retrn = result%10+'0';
	

	

	

	

	

	return retrn;
}

string multiplyStringByChar(string a,char c){
	string ans = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
		char temp = multiplyTwoChar(a[i],c,carry);
		ans+=temp;
		

		

		

	}
	if(carry>0){
		ans+=carry+'0';
	}
	reverse(ans.begin(),ans.end());
	


	


	

	return ans;
}

string multiplyTwoBigIntegers(string a1,string b1){
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
        string temp = "-"+ multiplyTwoBigIntegers(a,b);
        return temp;
    }
    string result = "";

    string oneCharMult;
    for(int i=b.size()-1;i>=0;i--){
        oneCharMult = multiplyStringByChar(a,b[i]);
        oneCharMult = oneCharMult + getZeroes(b.size()-1-i);
        

        result = addTwoBigIntegers(oneCharMult,result);
        

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

string getMinimum(string integer,int lenOfString){
	string temp = "";
	int count = 0;
	

	

	

	


	int count1 = lenOfString/2;
	string s11Final;
	s11Final= integer.substr(0,count1);
	
	

	while(true){
		

		if(count1>0 && integer[count1]=='0'){
			count1--;
			

		}
		else{
			s11Final = integer.substr(0,count1);
			break;
		}
	}
	
	string s21Final;
	s21Final = integer.substr(count1);

	if(s21Final[0]=='0'){
		count = 0;
		while(count<100000){
			temp+='9';
			count++;
		}
		s21Final = temp;
	}

	int count2 = lenOfString/2;
	string s12Final = integer.substr(0,count2);
	string s22Final = integer.substr(count2);

	while(true){
		if(count2<lenOfString && integer[count2]=='0'){
			count2++;
		}
		else{
			s12Final = integer.substr(0,count2);
			s22Final = integer.substr(count2);
			break;
		}
	}

	
	if(s12Final[0]=='0'){
		if(temp.size()==0){
			count=0;
			while(count<100000){
				temp+='9';
				count++;
			}
		}
		s12Final = temp;
	}




	

	


	int count3 = lenOfString/2;
	string s31Final = integer.substr(0,count3+1);
	

	while(true){
		if(count3 >=0 && integer[count3]=='0'){
			count3--;
		}
		else{
			s31Final = integer.substr(0,++count3);
			break;
		}
	}
	

	string s32Final = integer.substr(count3);

	if(s32Final[0]=='0'){
		if(temp.size()==0){
			count = 0;
			while(count<100000){
				temp+='9';
				count++;
			}
		}
		s32Final = temp;
	}	
	int count4 = lenOfString/2;
	string s41Final = integer.substr(0,count4+1);
	string s42Final = integer.substr(count4+1);
	while(true){
		if(count4<lenOfString && integer[count4]=='0'){
			count4++;
		}
		else{
			s41Final = integer.substr(0,count4);
			s42Final = integer.substr(count4);
			break;
		}
	}

	
	

	

	if(s41Final[0]=='0'){
		if(temp.size()==0){
			while(count<100000){
				temp+='9';
			}
		}
		s41Final = temp;
	}

	

	


	

	


	

	


	

	


	

	


	

	


	

	


	

	


	

	

	

	

	

	

	


	

	

	

	

	

	

	

	


	string sum1 = addTwoBigIntegers(s11Final,s21Final);
	string sum2 = addTwoBigIntegers(s12Final,s22Final);
	string sum3 = addTwoBigIntegers(s31Final,s32Final);
	string sum4 = addTwoBigIntegers(s41Final,s42Final);

	return minOfTwoBigIntegers(minOfTwoBigIntegers(sum1,sum2),minOfTwoBigIntegers(sum3,sum4));
}



int main(){
	int lenOfString;
	cin>>lenOfString;
	string integer;
	cin>>integer;
	string ans = getMinimum(integer,lenOfString);
	cout<<ans<<endl;

	

	

	

	

	


	

	

	


	

	


	

	


}