// LINEAR SEARCH :  


#include <stdio.h>

int main() {
    int ele , n;
    printf("Enter Number Of Elements Of Array : ");
    scanf("%d", &n);
    int arr[n];

    // Input :
    printf("Enter Elements Of Array : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }    

    // Search : 
    printf("Enter Element to Search : ");
    scanf("%d", &ele);
    int f=0;
    for(int i=0; i<n; i++) {
        if(arr[i] == ele){
            f=1;
            break;
        }
    }

    if(f==1){
        printf("Element %d Found ", ele);
    }
    else{
        printf("Element %d NOT Found" , ele);
    }
    
    
    return 0;
}