#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{   double T;
    int n,largest = 10000,i,j;
    cin>>T>>n;
    vector<double> w(n);
    for(int i=0; i<n; i++) cin >> w[i];
    for(int i=0; i<n; i++) {
        for(int j=0; j<largest; j++) {
            double maxsize = w[i]/(j+1);
            double minsize = maxsize*T;
            int no_of_cuts = j;
            for(int j=0; j<n; j++) {
                if ( j==i ) continue;
                int c1 = (int)ceil(w[j]/maxsize) - 1;
                if ( w[j]/(c1+1)<minsize ) goto next;
                no_of_cuts += c1;
                if ( no_of_cuts>=largest ) goto next;
            }

            if ( no_of_cuts<largest ) largest = no_of_cuts;
          next:
            continue;}}
    cout<<largest;
    return 0;
}
