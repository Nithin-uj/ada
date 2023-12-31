#include<stdio.h>
#include<stdlib.h>
#include<time.h>
double ssort (int arr[], int n);
void merge(int arr[], int l,int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    // L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;

    // Initial index of second subarray
    j = 0;

    // Initial index of merged subarray
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
 //   double time = ((double)e-s)/CLOCKS_PER_SEC;
}
void main(){
	int r;
	printf("ele : selection : merge\n");
	for(r=1000; r<=10000; r=r+1000){
		int size = r;
		int arr[size];
		for(int i=0; i<size; i++){
			arr[i] = rand();
		}
		double stime = ssort(arr,size);
		clock_t s = clock(),e;
		mergeSort(arr,0,size-1);
		e = clock();
		double mtime = ((double)e-s)/CLOCKS_PER_SEC;
		printf("%d : %f : %f \n",r,stime,mtime);
	}
}
double ssort(int arr[],int n){
	clock_t start,end;
	int i,j,small;
	start = clock();
	for(i=0; i<n-1; i++){
		small = i;
		for(j=i+1; j<n; j++){
			if(arr[j]<arr[small])
				small = j;
		}
		int temp = arr[small];
		arr[small] = arr[i];
		arr[i] = temp;
	}
	end = clock();
	double time = ((double)end-start)/CLOCKS_PER_SEC;
	return time;
}
