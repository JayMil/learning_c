/*
 * Exercise 3-01 from
 * The C Programming Language
 *      by Brian W. Kernighan and Dennis M. Ritchie
 *
 * Re-write the binary search on page 58 to only have one test inside the loop
 *
 *  By Jake Milder
 */

#include <stdio.h>

/* binsearch:   find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n);

/* binsearch2:   find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch2(int x, int v[], int n);


/* populateArray:   put values into array equal to index. arr[size-1] == size-1 */
void populateArray(int arr[], int size);

/* printArray:  print values in array adding newlines at lineWidth */
void printArray(int arr[], int size, int lineWidth);

/* len: return the number of characters in a positive integer */
int len(int num);

int main(void) {
    int size = 1000000;
    int a[size];
    populateArray(a, size);

    int found = binsearch(2, a, size);
    printf("Found %d\n", found);
    return 0;

}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    
    if (low == high) /* found match */
        return mid;
    else
        return -1; /* no match */
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    
    return -1; /* no match */
}

int len(int num) {
    int count = 1;

    while (num >= 10) {
        num /= 10;
        count++;
    }

    return count;
}

void printArray(int arr[], int size, int maxLineWidth) {
    int currentLineWidth = 0;
    int numLen = 0;
    int inculdeSpace = 0;
    for (int i = 0; i < size; i++) {
        inculdeSpace = currentLineWidth > 0;
        numLen = inculdeSpace + len(arr[i]);
        currentLineWidth += numLen;
        if (currentLineWidth > maxLineWidth) {
            printf("\n");
            currentLineWidth = numLen;
            inculdeSpace = 0;
        }

        printf("%c%d", inculdeSpace ? ' ' : '\0', arr[i]);

    }
    printf("\n");
}

void populateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}


