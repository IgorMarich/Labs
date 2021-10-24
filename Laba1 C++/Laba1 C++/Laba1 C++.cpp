#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cstdio>
#include <iostream>
 static int processArray(int arr[], int Array[] )
 {
    
     int ans = 0, a, b;
     printf("a = ");
     scanf("%d", &a);
     printf("b = ");
     scanf("%d", &b);
     srand( time(NULL) );
     printf("[");
     for (int i = 0; i < 15; i++)
     { 
         arr[i] = rand() % (b - a + 1) + a;
         printf(" %d ", arr[i]);
     }
     printf("]");
     
     
     for(int i = 0; i< 15; i++)
         if (arr[i] < -9 || arr[i] > 9 && arr[i] < 100)
         {
             Array[ans] = arr[i];
             ans++;
         }
     printf("\n[");
     for (int i = 0; i < ans; i++)
         
             printf("%d ",  Array[i]  );
         
     printf("]\n");
     return ans;
     

     

     return 0;
}
int main()
{
    int arr[15]{ 1 };
    int Array[15]{ 0 };
    int cnt = processArray(arr, Array);
    printf("cnt = %d", cnt );
    return 0;
        
}

