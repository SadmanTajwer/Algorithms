#include<stdio.h>
int M, a[50];

int lowerb(int c,int k)
{
    int d,t;
    t = (d+c+1)/2;
    if(c==0)
    {
        return 0;
    }
    else
    {
        for (d= 0;  d<=c; d++)
        {
            if(k == a[t])
            {
                c = t;
            }
            if(k > a[t])
            {
                d = t;
            }

            if(c == d+1)
            {

                if(a[c]==a[d])
                {
                    c = d;
                }
                break;
            }
            t = (d+c+1)/2;

        }return c;
    }

}

int higherb(int d,int f)
{
    int g ,t;
    g = M-1;
    t = (d+g+1)/2;
    for(d=0; d<=g; d++)
    {
        if(f<a[t])
        {
            g = t;
        }
        if(f == a[t])
        {
            d = t;
        }
        t = (d+g+1)/2;
        if(g==d)
            {
                d = M;
            }
        if(g == d+1)
        {
            if(a[g]==a[d])
            {
                d = g;
            }
            break;
        }
    }
    return d;
}

void searchb(int u, int h)
{
    int higher_value, lower_value ,midrange_value;
    if(h<a[0])
    {
        lower_value = 0;
        higher_value=0;
    }
    if(h > a[u-1])
    {
        higher_value = u;
        lower_value = lowerb(u-1,a[u-1]);
    }
    if(h >= a[0] && h <= a[u-1])
    {
        lower_value = 0;
        higher_value = u - 1;
        midrange_value = (lower_value + higher_value + 1)/2;
      for(lower_value=0 ; lower_value<=higher_value; lower_value--)
        {
            if(h>a[midrange_value])
            {
                lower_value = midrange_value;
            }
            if(h<a[midrange_value])
            {
                higher_value = midrange_value;
            }
            if(h==a[midrange_value])
            {
                lower_value = midrange_value;
            }
            if(higher_value == lower_value + 1)
            {
                break;
            }
            midrange_value = (lower_value + higher_value + 1)/2;

        }

    }
    higher_value = higherb(higher_value, a[higher_value]);
    lower_value  = lowerb(lower_value ,a[lower_value]);
    printf("%d %d", higher_value, lower_value);
}
int main()
{
    int S, i;
    scanf("%d", &M);
    scanf ("%d", &S);
    for(i=0 ; i<M ; i++)
    {
        scanf("%d", &a[i]);
    }
    searchb(M ,S);

}
