#include<stdio.h>
int N,a[100];

int searchLow(int y,int z)
{
    int p,m;
    m = (p+y+1)/2;
    if(y==0)
    {
        return 0;
    }
    else
    {
        for (p= 0;  p<=y; p++)
        {
            if(z == a[m])
            {
                y = m;
            }
            if(z > a[m])
            {
                p = m;
            }

            if(y == p+1)
            {

                if(a[y]==a[p])
                {
                    y = p;
                }
                break;
            }
            m = (p+y+1)/2;

        }return y;
    }

}

int searchHigh(int p,int q)
{
    int x,m;
    x = N-1;
    m = (p+x+1)/2;
    for(p=0; p<=x; p++)
    {
        if(q<a[m])
        {
            x = m;
        }
        if(q == a[m])
        {
            p = m;
        }
        m = (p+x+1)/2;
        if(x==p)
            {
                p = N;
            }
        if(x == p+1)
        {
            if(a[x]==a[p])
            {
                p = x;
            }
            break;
        }
    }
    return p;
}

void searchBound(int n, int s)
{
    int high,low,mid;
    if(s<a[0])
    {
        low = 0;
        high =0;
    }
    if(s>a[n-1])
    {
        high = n;
        low = searchLow(n-1,a[n-1]);
    }
    if(s>= a[0] && s<= a[n-1])
    {
        low = 0;
        high = n-1;
        mid = (low+high+1)/2;
      for(low=0 ; low<=high; low--)
        {
            if(s>a[mid])
            {
                low = mid;
            }
            if(s<a[mid])
            {
                high = mid;
            }
            if(s==a[mid])
            {
                low = mid;
            }
            if(high==low+1)
            {
                break;
            }
            mid = (low+high+1)/2;

        }

    }
    high = searchHigh(high,a[high]);
    low  = searchLow(low,a[low]);
    printf("%d %d", high, low);
}
int main()
{
    int S,i;
    scanf("%d", &N);
    scanf ("%d", &S);
    for(i=0;i<N;i++)
    {
        scanf("%d", &a[i]);
    }
    searchBound(N,S);

}
