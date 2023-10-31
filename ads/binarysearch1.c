#include<stdio.h>
 
 
 
 
int main(){
	int arr[10],size,n,flag=0,temp,h,l,mid;
 
	printf("\n Enter the size of the array ");
	scanf("%d",&size);
 
	printf("\n Enter the %d array Elements ",size);
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
 
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
 
	printf("\n Enter the number to be found :");
	scanf("%d",&n);
 
	printf("\n The sorted array is \n ");
		for(int i =0;i<size;i++)
			printf("%d ",arr[i]);
 
	h = size ;
	l = 0;
	while(l<=h){
		mid =(h+l)/2;
 
		if(arr[mid]==n){
 
			flag=1;
			break;
		}else if(n>arr[mid]){
			l =mid+1;
		}else{
		    h = mid -1;
		}
 
	}
 
	if(flag==1){
		printf("\n Found at %d position  \n",mid+1);
	}else{
		printf("\n Not Found \n");
	}
 
}
