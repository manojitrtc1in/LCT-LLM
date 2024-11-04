#include<iostream>
#include<numeric>
#include<memory.h>
using namespace std;

void Merge(long long int  arr[], long long int  head, long long int  mid, long long int  tail){
 long long int  lenA = mid - head + 1;
  long long int  lenB = tail - (mid + 1) + 1;
  long long int  A[lenA];
  long long int  B[lenB];

  

  long long int  i, j, k;
  for(i = 0; i < lenA; i++){
    A[i] = arr[head + i];   
  }
  for(j = 0; j < lenB; j++){
    B[j] = arr[mid + 1 + j];
  }
  

  i = 0;
  j = 0;
  k = head;
  

  while(i < lenA && j < lenB){
    if(A[i] < B[j]){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];  
      j++;
    }
    k++;
  }
  

  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }
  

  while(j < lenB){
    arr[k] = B[j];  
    j++;
    k++;
  }
}
void MergeSort(long long int array[], long long int front, long long int end){
                                         

    if (front < end) {                   

        long long int mid = (front+end)/2;         

        MergeSort(array, front, mid);    

        MergeSort(array, mid+1, end);    

        Merge(array, front, mid, end);   

    }
}
int  main(){
	

	long long int  number_of_battles;

	scanf("%lld",&number_of_battles);

	long long int  i;
	long long int  power[3];
	long long int  power_of_enemy[number_of_battles];
	for(i=0; i<3 ;++i){
		scanf("%lld", &power[i]);
	}
	for(i=0; i<number_of_battles; ++i){
		scanf("%lld",&power_of_enemy[i]);
	}

	MergeSort(power_of_enemy, 0, number_of_battles - 1);
	MergeSort(power, 0, 2);
	
	long long int r_point = number_of_battles - 1 , l_pointer = 0;
	long long int final_answer = 0;
	long long int p1 = power[0], p2 = power[1] , p3 = power[2] , p4 = power[0] + power[1] ,
	 p5 = power[0] + power[2], p6 = power[2] + power[1] , p7 = power[1] + power[2] + power[0]; 
	long long int win_number = 0;
	long long int number_of_p1_solved = 0, number_of_p2_solved = 0,  number_of_p3_solved =0,  number_of_others_solved=0;
		
	long long int p1_solved[number_of_battles ];
	long long int p2_solved[number_of_battles ];
	long long int p3_solved[number_of_battles ];
	long long int other_solved[number_of_battles ];
	memset(p1_solved,0,sizeof(p1_solved));
	memset(p2_solved,0,sizeof(p1_solved));
	memset(p3_solved,0,sizeof(p1_solved));
	memset(other_solved,0,sizeof(p1_solved));
	long long int zx=0, asd=0, asdd=0, olm=0;
	for(i = 0 ; i<number_of_battles ;i++){
		if(power_of_enemy[i]> p1) break;
		if(p1>= power_of_enemy[i]){
			p1_solved[zx] = power_of_enemy[i];
			zx++;
			number_of_p1_solved++;
		}
	}
	for(i = zx; i<number_of_battles; i++){

		if(p2>= power_of_enemy[i]){
			p2_solved[asd] = power_of_enemy[i];
			asd++;
			zx++;
			number_of_p2_solved++;
		}
		else break;
	}
	for(i = zx; i<number_of_battles; i++){

		if(p3>= power_of_enemy[i]){

			p3_solved[asdd] = power_of_enemy[i];
			asdd++;
			zx++;
			number_of_p3_solved++;
		}
		else break;
	}
	for(i = zx; i<number_of_battles; i++){
		other_solved[olm] = power_of_enemy[i];
		olm++;
		number_of_others_solved++;
	}
	for(i=0; i<number_of_battles; i++){
	

	}
	

	for(i=0; i<number_of_battles; i++){
	

	}
	

	for(i=0; i<number_of_battles; i++){
	

	}
	

	for(i=0; i<number_of_battles; i++){
		

	}
	
	

	

	if( other_solved[number_of_others_solved - 1] > (p1 + p2 + p3)  and number_of_others_solved > 0){
		int imppposible = -1;
		printf("%d\n", imppposible);
		return 0;
	}
	while(number_of_others_solved > 0){
		if(other_solved[number_of_others_solved - 1] > p6){

			final_answer++;
			number_of_others_solved--;
			continue;
		}
		if(other_solved[number_of_others_solved - 1] <= (p1 + p2)){
			final_answer ++;
			number_of_others_solved--;
			if(number_of_p3_solved > 0){
				number_of_p3_solved--;
				continue;
			}
			if(number_of_p2_solved > 0){
				number_of_p2_solved--;
				continue;
			}
			if(number_of_p1_solved > 0){
				number_of_p1_solved--;
				continue;
			}
			continue;
		}
		if(other_solved[number_of_others_solved -1] <= (p1 + p3) and other_solved[number_of_others_solved - 1]>(p1+ p2)){
			final_answer++;
			number_of_others_solved--;
			if(number_of_p2_solved > 0){
				number_of_p2_solved--;
				continue;
			}
			if(number_of_p1_solved > 0){
				number_of_p1_solved--;
				continue;
			}
			continue;
		}
		if(other_solved[number_of_others_solved -1]> (p1+p3)){
			final_answer++;
			number_of_others_solved--;
			if(number_of_p1_solved > 0){
				number_of_p1_solved--;
				continue;
			}
			continue;
		}	
	}
	long long int  left_boundary_of_number_of_p3_solved = 0;

	while( (number_of_p3_solved - left_boundary_of_number_of_p3_solved)> 0){ 

		final_answer++;
		number_of_p3_solved--;
		if(number_of_p2_solved > 0 and number_of_p1_solved > 0){
			number_of_p2_solved--;
			number_of_p1_solved--;
			continue;
		}
		if(number_of_p1_solved > 1 and number_of_p2_solved<= 0){
			number_of_p1_solved--;
			number_of_p1_solved--;
			continue;
		}
		if((number_of_p3_solved - left_boundary_of_number_of_p3_solved)> 0 and (p1+p2) >= p3_solved[left_boundary_of_number_of_p3_solved]){

			left_boundary_of_number_of_p3_solved++;
			continue;
		}
		if(number_of_p2_solved > 0 ){
			number_of_p2_solved--;
			continue;
		}
		if(number_of_p1_solved > 0){
			number_of_p1_solved--;
			if(number_of_p1_solved > 0){
				number_of_p1_solved--;
			}
			continue;
		}
		continue;
	}
	while(number_of_p2_solved > 0){
		final_answer++;
		number_of_p2_solved--;
		if(number_of_p1_solved <=0 and number_of_p2_solved > 0){
			number_of_p2_solved--;
			continue;
		}
		if(number_of_p1_solved > 0 and number_of_p2_solved<= 0){
			number_of_p1_solved--;
			if(number_of_p1_solved > 0){
				number_of_p1_solved--;
			}
			continue;
		}
		if(number_of_p1_solved > 0 and number_of_p2_solved > 0){
			number_of_p2_solved--;
			number_of_p1_solved--;
		}
		continue;
	}
	while(number_of_p1_solved > 0){
		final_answer++;
		number_of_p1_solved--;
		if(number_of_p1_solved > 0){
			number_of_p1_solved--;
		}
		if(number_of_p1_solved > 0){
			number_of_p1_solved--;
		}
		continue;
	}

	printf("%lld\n", final_answer);
	


	return 0;
}