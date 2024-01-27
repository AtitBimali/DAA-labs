#include<stdio.h>
int main(){
	int a[100], i, j, temp, n, count = 0;
	count++;
	
	printf("Enter no. of elements: \t");
	count++;
	scanf("%d", &n);
	count++;
	
	printf("Enter %d numbers: \t", n);
	count = count + 2;
	count = count + n + 1;
	count = count + n;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		count++;
	}
	count++;
	count = count + n + 1;
	count = count + n;
	for(i=0; i<n; i++){
		count = count + 3;
		for(j=i+1; j<n; j++){
			count = count + 1;
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				count = count + 3;
			}
		}
	}
	printf("Sorted array: \t");
	count = count + 2;
	count  = count + n + 1;
	count = count + n;
	for(i=0; i<n; i++){
		printf("%d\t", a[i]);
		count = count++;
	}
	printf("\nTotal steps = %d", count);
	return 0; 
}
