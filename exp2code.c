#include <stdio.h>
#include<time.h>
#include<stdlib.h>

    
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
} 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
    clock_t  a,b,c;
    int arr[100000],arr2[100000];
    double d,e;
  FILE *fptr;
  int num;
  

  fptr = fopen("integers", "w");
  
  if (fptr != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
   
    return -1;
  }
  

int i=0;
  while (i!=100000) {
   num=rand()%100000;
    if (num != -1) {
      putw(num, fptr);
    }
    else {
      break;
    }
    ++i;
  }
  

  fclose(fptr);
  

  fptr = fopen("integers", "r");
  
i=0;
  while ( (num = getw(fptr)) != EOF ) {
     arr[i]=num;
     arr2[i]=num;
     i++;
  }
  
  printf("\nEnd of file.\n");
  

  fclose(fptr);

  
  for(int j=100;j<=100000;j+=100){
        a=clock();
      mergeSort(arr,0,j-1);
      b=clock();
      
      d=(double)(b-a)/CLOCKS_PER_SEC;
      printf("%f",d);
      printf("  ");
      quickSort(arr2,0,j-1);
       c=clock();
      e=(double)(c-b)/CLOCKS_PER_SEC;
      printf("%f\n",e);
      
      
  }
     
  
  return 0;
}





