#include <stdio.h>
#include <time.h>

int bin_search_book(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
        return -1;  /* no match */
    }
}

int bin_search_mine(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high && v[mid] != x)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (v[mid] == x)
    {
        return mid;
    }
    return -1;  /* no match */
}

int main()
{
    // make array of numbers
    int v[1000000];
    
    for (int i = 0; i < 1000000; i++)
    {
        v[i] = i;
    }

    clock_t t;
    t = clock();
    bin_search_book(3, v, 1000000);
    t = clock() - t;
    double time_taken = ((double) t/ CLOCKS_PER_SEC);

    printf("Book search took %f seconds\n", time_taken);

    t = clock();
    bin_search_mine(3, v, 1000000);
    t = clock() - t;
    time_taken = ((double) t/ CLOCKS_PER_SEC);

    printf("Mine search took %f seconds\n", time_taken);
}