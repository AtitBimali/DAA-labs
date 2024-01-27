// Emperical analysis of Bubble sort using RAM model

#include<stdio.h>
int main(){
	int a[100], i, j, temp, n, count = 0;
	
	printf("Enter no. of elements\t");
	scanf("%d", &n);
	
	printf("Enter %d numbers\t", n);
	count = count + 7;
	for(i=0; i<n; i++){
		count = count + 4;
		scanf("%d", &a[i]);
	}
	count = count + 3;
	for(i=0; i<n; i++){
		count = count + 4;
		for(j=0; j<n-i-1; j++){
			temp = a[j];
			count = count + 5;
			if(a[j]>a[j+1]){
				count = count + 3;
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("Sorted elements:");
	count = count + 3;
	for(i=0; i<n; i++){
		count = count + 4;
		printf("%d\t", a[i]);
	}
	count = count + 3;
	printf("Total steps = %d", count);
	return 0;
}

