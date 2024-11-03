




using namespace std;

int n;

int main()
{
    cin>>n;
    if(n == 1){cout<<0<<endl;
}
else if(n == 2){cout<<1<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
}
else if(n == 3){cout<<1<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
}
else if(n == 4){cout<<1<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
}
else if(n == 5){cout<<1<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
}
else if(n == 6){cout<<2<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
}
else if(n == 7){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
}
else if(n == 8){cout<<1<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
}
else if(n == 9){cout<<1<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
}
else if(n == 10){cout<<2<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
}
else if(n == 11){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
}
else if(n == 12){cout<<2<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
}
else if(n == 13){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
}
else if(n == 14){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 15){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
}
else if(n == 16){cout<<2<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
}
else if(n == 17){cout<<2<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 18){cout<<2<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 19){cout<<2<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
}
else if(n == 20){cout<<2<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
}
else if(n == 21){cout<<2<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
}
else if(n == 22){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 23){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 24){cout<<2<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*ebx]"<<endl;
}
else if(n == 25){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 26){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 27){cout<<2<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 28){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 29){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
}
else if(n == 30){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 31){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 32){cout<<2<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
}
else if(n == 33){cout<<2<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 34){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 35){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 36){cout<<2<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 37){cout<<2<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
}
else if(n == 38){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 39){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 40){cout<<2<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
}
else if(n == 41){cout<<2<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 42){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 43){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 44){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 45){cout<<2<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 46){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 1*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
}
else if(n == 47){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 48){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
}
else if(n == 49){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 50){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 51){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
}
else if(n == 52){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 53){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 54){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 55){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 56){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 57){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 58){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 59){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 60){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 61){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 62){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 63){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 64){cout<<2<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
}
else if(n == 65){cout<<2<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 66){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 67){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 68){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [4*ecx]"<<endl;
}
else if(n == 69){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 70){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 71){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [eax + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 72){cout<<2<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 73){cout<<2<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
}
else if(n == 74){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 75){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 76){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 77){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 78){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 79){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 80){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
}
else if(n == 81){cout<<2<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
}
else if(n == 82){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 83){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 84){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 85){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 86){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 87){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
}
else if(n == 88){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 89){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 90){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 91){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 92){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 2*edx]"<<endl;
}
else if(n == 93){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 94){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 95){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
}
else if(n == 96){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
}
else if(n == 97){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 98){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*eax]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 99){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
}
else if(n == 100){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 101){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 102){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 103){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 104){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 105){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 106){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 107){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 108){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 109){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 110){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 111){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 112){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*eax]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 113){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 114){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 115){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 116){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 117){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 118){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 119){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 120){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 121){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 122){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 123){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 124){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 125){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 126){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 127){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 128){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
}
else if(n == 129){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 130){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 131){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 132){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [4*ecx]"<<endl;
}
else if(n == 133){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 134){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 135){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 136){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
}
else if(n == 137){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 138){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 139){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [eax + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 140){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 141){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 142){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 143){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 144){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 145){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 146){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 147){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 148){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 149){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 150){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 151){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 152){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
}
else if(n == 153){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 154){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 155){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
}
else if(n == 156){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ebx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 157){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 158){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 159){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 160){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 161){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 162){cout<<3<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 163){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
}
else if(n == 164){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 165){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 166){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 167){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 168){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 169){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 170){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 171){cout<<3<<endl;
cout<<"lea ebx, [eax + 8*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 172){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 8*ecx]"<<endl;
}
else if(n == 173){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 174){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 175){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 176){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [8*edx]"<<endl;
}
else if(n == 177){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [eax + 8*edx]"<<endl;
}
else if(n == 178){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 179){cout<<4<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 180){cout<<3<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 181){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
}
else if(n == 182){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 183){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 184){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 185){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
}
else if(n == 186){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 187){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 8*ecx]"<<endl;
}
else if(n == 188){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 189){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 190){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 191){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 192){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
}
else if(n == 193){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 194){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 195){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
}
else if(n == 196){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [4*edx]"<<endl;
}
else if(n == 197){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [eax + 4*edx]"<<endl;
}
else if(n == 198){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 199){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 4*ecx]"<<endl;
}
else if(n == 200){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 201){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 202){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 203){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 204){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [4*edx]"<<endl;
}
else if(n == 205){cout<<3<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
}
else if(n == 206){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 207){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 208){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [8*edx]"<<endl;
}
else if(n == 209){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [eax + 8*edx]"<<endl;
}
else if(n == 210){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 211){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 212){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
}
else if(n == 213){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 214){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 215){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 216){cout<<3<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 217){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
}
else if(n == 218){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 219){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
}
else if(n == 220){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 221){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 222){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 2*edx]"<<endl;
}
else if(n == 223){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 224){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [8*edx]"<<endl;
}
else if(n == 225){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 226){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*eax]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 227){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 228){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 229){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 4*ebx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 230){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 231){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 232){cout<<4<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 233){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [eax + 8*edx]"<<endl;
}
else if(n == 234){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 8*edx]"<<endl;
}
else if(n == 235){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 236){cout<<4<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 237){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 8*ebx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 238){cout<<4<<endl;
cout<<"lea ebx, [eax + 4*eax]"<<endl;
cout<<"lea ecx, [eax + 1*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 239){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 240){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 241){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [eax + 8*edx]"<<endl;
}
else if(n == 242){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 243){cout<<3<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
}
else if(n == 244){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 245){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [eax + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 246){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 8*edx]"<<endl;
}
else if(n == 247){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*ebx]"<<endl;
cout<<"lea edx, [ecx + 8*ecx]"<<endl;
cout<<"lea eex, [ecx + 2*edx]"<<endl;
}
else if(n == 248){cout<<4<<endl;
cout<<"lea ebx, [8*eax]"<<endl;
cout<<"lea ecx, [ebx + 2*eax]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 249){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [eax + 8*edx]"<<endl;
}
else if(n == 250){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [ebx + 4*eax]"<<endl;
cout<<"lea edx, [ebx + 8*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}
else if(n == 251){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 2*ebx]"<<endl;
cout<<"lea edx, [ebx + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 8*edx]"<<endl;
}
else if(n == 252){cout<<4<<endl;
cout<<"lea ebx, [4*eax]"<<endl;
cout<<"lea ecx, [ebx + 8*eax]"<<endl;
cout<<"lea edx, [ecx + 4*ecx]"<<endl;
cout<<"lea eex, [ecx + 4*edx]"<<endl;
}
else if(n == 253){cout<<4<<endl;
cout<<"lea ebx, [eax + 2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ebx + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 8*ecx]"<<endl;
}
else if(n == 254){cout<<5<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 4*eax]"<<endl;
cout<<"lea edx, [eax + 4*ecx]"<<endl;
cout<<"lea eex, [ebx + 4*edx]"<<endl;
cout<<"lea efx, [eex + 8*edx]"<<endl;
}
else if(n == 255){cout<<4<<endl;
cout<<"lea ebx, [2*eax]"<<endl;
cout<<"lea ecx, [eax + 8*ebx]"<<endl;
cout<<"lea edx, [ecx + 2*ecx]"<<endl;
cout<<"lea eex, [edx + 4*edx]"<<endl;
}

    return 0;
}


