#include<stdio.h>

int main() {
    int x;
    float s = 1;
    int i ;
   scanf("%d",&x);
 for (i=0; i < i + 1; i++ )
    {
        s = (x / s + s) / 2;
        if (i == x + 1) { break; }
    }
     printf("%.3f",s);
}

