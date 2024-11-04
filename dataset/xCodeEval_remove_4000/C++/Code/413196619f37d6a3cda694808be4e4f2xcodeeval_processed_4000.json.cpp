


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
	

	long long int  id1;

	scanf("%lld",&id1);

	long long int  i;
	long long int  power[3];
	long long int  power_of_enemy[id1];
	for(i=0; i<3 ;++i){
		scanf("%lld", &power[i]);
	}
	for(i=0; i<id1; ++i){
		scanf("%lld",&power_of_enemy[i]);
	}

	MergeSort(power_of_enemy, 0, id1 - 1);
	MergeSort(power, 0, 2);
	
	long long int r_point = id1 - 1 , l_pointer = 0;
	long long int final_answer = 0;
	long long int p1 = power[0], p2 = power[1] , p3 = power[2] , p4 = power[0] + power[1] ,
	 p5 = power[0] + power[2], p6 = power[2] + power[1] , p7 = power[1] + power[2] + power[0]; 
	long long int win_number = 0;
	long long int id6 = 0, id0 = 0,  id5 =0,  id2=0;
		
	long long int id4[id1 ];
	long long int p2_solved[id1 ];
	long long int p3_solved[id1 ];
	long long int other_solved[id1 ];
	memset(id4,0,sizeof(id4));
	memset(p2_solved,0,sizeof(id4));
	memset(p3_solved,0,sizeof(id4));
	memset(other_solved,0,sizeof(id4));
	long long int zx=0, asd=0, asdd=0, olm=0;
	for(i = 0 ; i<id1 ;i++){
		if(power_of_enemy[i]> p1) break;
		if(p1>= power_of_enemy[i]){
			id4[zx] = power_of_enemy[i];
			zx++;
			id6++;
		}
	}
	for(i = zx; i<id1; i++){

		if(p2>= power_of_enemy[i]){
			p2_solved[asd] = power_of_enemy[i];
			asd++;
			zx++;
			id0++;
		}
		else break;
	}
	for(i = zx; i<id1; i++){

		if(p3>= power_of_enemy[i]){

			p3_solved[asdd] = power_of_enemy[i];
			asdd++;
			zx++;
			id5++;
		}
		else break;
	}
	for(i = zx; i<id1; i++){
		other_solved[olm] = power_of_enemy[i];
		olm++;
		id2++;
	}
	for(i=0; i<id1; i++){
	

	}
	

	for(i=0; i<id1; i++){
	

	}
	

	for(i=0; i<id1; i++){
	

	}
	

	for(i=0; i<id1; i++){
		

	}
	
	

	

	if( other_solved[id2 - 1] > (p1 + p2 + p3)  and id2 > 0){
		int id7 = -1;
		printf("%d\n", id7);
		return 0;
	}
	while(id2 > 0){
		if(other_solved[id2 - 1] > p6){

			final_answer++;
			id2--;
			continue;
		}
		if(other_solved[id2 - 1] <= (p1 + p2)){
			final_answer ++;
			id2--;
			if(id5 > 0){
				id5--;
				continue;
			}
			if(id0 > 0){
				id0--;
				continue;
			}
			if(id6 > 0){
				id6--;
				continue;
			}
			continue;
		}
		if(other_solved[id2 -1] <= (p1 + p3) and other_solved[id2 - 1]>(p1+ p2)){
			final_answer++;
			id2--;
			if(id0 > 0){
				id0--;
				continue;
			}
			if(id6 > 0){
				id6--;
				continue;
			}
			continue;
		}
		if(other_solved[id2 -1]> (p1+p3)){
			final_answer++;
			id2--;
			if(id6 > 0){
				id6--;
				continue;
			}
			continue;
		}	
	}
	long long int  id3 = 0;

	while( (id5 - id3)> 0){ 

		final_answer++;
		id5--;
		if(id0 > 0 and id6 > 0){
			id0--;
			id6--;
			continue;
		}
		if(id6 > 1 and id0<= 0){
			id6--;
			id6--;
			continue;
		}
		if((id5 - id3)> 0 and (p1+p2) >= p3_solved[id3]){

			id3++;
			continue;
		}
		if(id0 > 0 ){
			id0--;
			continue;
		}
		if(id6 > 0){
			id6--;
			if(id6 > 0){
				id6--;
			}
			continue;
		}
		continue;
	}
	while(id0 > 0){
		final_answer++;
		id0--;
		if(id6 <=0 and id0 > 0){
			id0--;
			continue;
		}
		if(id6 > 0 and id0<= 0){
			id6--;
			if(id6 > 0){
				id6--;
			}
			continue;
		}
		if(id6 > 0 and id0 > 0){
			id0--;
			id6--;
		}
		continue;
	}
	while(id6 > 0){
		final_answer++;
		id6--;
		if(id6 > 0){
			id6--;
		}
		if(id6 > 0){
			id6--;
		}
		continue;
	}

	printf("%lld\n", final_answer);
	


	return 0;
}