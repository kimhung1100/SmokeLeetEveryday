#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream filein;
    ofstream fileout;
    filein.open("MAXEQUATION.INP");
    int n, m;
    filein >> n >> m;
    long long a[n],b[m];
    for(int i = 0; i < n; i++){
        filein >> a[i];
    }
    for(int i = 0; i < m; i++){
        filein >> b[i];
    }
    filein.close();
    sort(a, a+n);
    sort(b,b+n);
    
    // cung duong, // ca 2 lech duong
    /*
    if(a[0] > 0 && b[0]>0){
        max = a[m-1] * b[m-1] + a[m-1] + b[m-1];
    }else if(a[0] < 0 && b[0] < 0 && a[0]* -1 < a[m-1] && b[0]* -1 < b[m-1])
        max = a[m-1] * b[m-1] + a[m-1] + b[m-1];
    // cung am, // ca 2 lech am
    else if(a[0] < 0 && b[0] < 0)
        max = a[0] * b[0] + a[0] + b[0];
    else if (a[0] < 0 && b[0] > 0 && a[0]* -1 < a[m-1] && b[0]* -1 < b[m-1])
        max = a[m-1] * b[m-1] + a[m-1] + b[m-1];
    */
    // ca 2 lech duong
    
    // lech so le
    long long max = -1000000;
    if(a[0]*b[0]+a[0]+b[0]>max) max=a[0]*b[0]+a[0]+b[0];
    if(a[0]*b[m-1]+a[0]+b[m-1]>max) max=a[0]*b[m-1]+a[0]+b[m-1];
    if(a[n-1]*b[0]+a[n-1]+b[0]>max) max=a[n-1]*b[0]+a[n-1]+b[0];
    if(a[n-1]*b[m-1]+a[n-1]+b[m-1]>max) max=a[n-1]*b[m-1]+a[n-1]+b[m-1];

    fileout.open("MAXEQUATION.OUT");
    fileout << max;
    fileout.close();
    return 0;
}