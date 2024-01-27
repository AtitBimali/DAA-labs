#include<stdio.h>
int main(){
	int a[100], i, j, temp, n, count = 0;
	count++;
	
	printf("Enter no. of elements\t");
	count++;
	scanf("%d", &n);
	count++;
	
	printf("Enter %d numbers\t", n);
	count++;
	count = count + n + 1;
	count = count + n;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		count++;
	}
	count++;
	count = count + n;
	count = count + n - 1;
	for(i=1; i<n; i++){
		temp = a[i];
		count++;
		j = i-1;
		count++;
		while((temp<a[j]) && (j>=0)){
			a[j+1] = a[j];
			j = j - 1;
			count = count + 2;
		}
		a[j+1] = temp;
		count++;
	}
	printf("Sorted array: \t");
	count = count + 2;
	count  = count + n + 1;
	count = count + n;
	for(i=0; i<n; i++){
		printf("%d\t", a[i]);
		count = count + n;
	}
	printf("\nTotal steps = %d", count);
	return 0; 
}
