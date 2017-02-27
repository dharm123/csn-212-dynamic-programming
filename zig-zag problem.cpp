#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int max(int a, int b)
 {  return (a > b) ? a : b; }

 int answer(int arr[], int n)
{
    /*Z[i][0] = Length of the longest Zig-Zag subsequence
          ending at index i and last element is greater
          than its previous element
     Z[i][1] = Length of the longest Zig-Zag subsequence
          ending at index i and last element is smaller
          than its previous element   */
    int Z[n][2];

    /* Initializing all values from 1  */
    for (int i = 0; i < n; i++)
        Z[i][0] = Z[i][1] = 1;

    int res = 1; // Initialize result

    /* Compute values in bottom up manner */
    for (int i = 1; i < n; i++)
    {
        // Consider all elements as previous of arr[i]
        for (int j = 0; j < i; j++)
        {
            // If arr[i] is greater, then check with Z[j][1]
            if (arr[j] < arr[i] && Z[i][0] < Z[j][1] + 1)
                Z[i][0] = Z[j][1] + 1;

            // If arr[i] is smaller, then check with Z[j][0]
            if( arr[j] > arr[i] && Z[i][1] < Z[j][0] + 1)
                Z[i][1] = Z[j][0] + 1;
        }

        
        if (res < max(Z[i][0], Z[i][1]))
            res = max(Z[i][0], Z[i][1]);
    }

    return res;
}
int main()
{int n;
cout<<"enter no. of elements"<<endl;
cin>>n;
int a[n],i;
for(i=0;i<n;i++)
{cin>>a[i];
}
cout<<answer(a, n)<<endl;


}
