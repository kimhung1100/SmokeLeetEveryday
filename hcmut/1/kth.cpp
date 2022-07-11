#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    ifstream filein;
    ofstream fileout;
    filein.open("DIGIT.INP");
    double n, m;
    int k;
    filein >> n >> m >> k;
    double num = n /m;
    for(int i = 0; i < k; i++){
        num = num * 10;
    }
    int numb = num;
    int ans = numb%10;
    fileout.open("DIGIT.OUT");
    fileout << ans;
    fileout.close();
    return 0;
}