// cho so tu nhien n <= 100. cho biet co bao nhieu cach
// phan tich so n thanh tong cua cac so nguyen duong

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    //create 2d vector array
    vector<vector<int>> array(n+1, vector<int>(n+1, 0));
    //fill array
    for(int i = 0; i <= n; i++){
        array[0][i] = 0;
        array[i][0] = 1;
    }
    for(int i= 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j <= i)
                array[i][j] = array[i-1][j];
            else
            array[i][j] = array[i-1][j] + array[i][j-1];
        }
    }
    cout << "So cach: "<< array[n][n] << endl; 
}