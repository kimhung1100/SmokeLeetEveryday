#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
void primeNumberGen(int arr[], int n){
    arr[0] = -1;
    arr[1] = -1;
    int s = sqrt(n);
    for(int i = 2; i < s; i++){
        if(arr[i] == 0){
            for(int j = i * 2; j < 100000; j += i){
                arr[j] = -1;
            }
        }
    }
}
// divide two numbers
// first reference is string, second reference is int, third reference is int
// return a string of quotient and remainder
string divBN(string a, int b, int &remainder){
    string ans;
    int index = 0;
    int temp = a[0] - '0';
    int pretemp;
    while(temp < b){
        temp = temp * 10 + a[index + 1] - '0';
        index ++;
    }
    while(a.size()> index){
        pretemp = temp;
        ans += (temp / b) + '0';
        temp = temp % b * 10 + a[++index] - '0';
    }
    if(ans.length() == 0) ans = "0";
    remainder = pretemp%b;
    return ans;
}
int main(){
    int primeNumber[100000];
    fill_n(primeNumber, 100000, 0);
    primeNumberGen(primeNumber, 100000);
    
    
    string number;
    cin >> number;
    string n = number;
    //int remander = 0;
    // print prime factor
    for(int i = 2; i < 5000; i++){
        if(primeNumber[i] >= 0){
            int remander = 0;
            string a = divBN(n,i,remainder);
            while(remainder == 0){
                //cout << i << " ";
                primeNumber[i]++;
                n = divBN(n,i,remainder);
                string a = divBN(n,i,remainder);
            }
        }
    }
    for(int i = 0; i < (int)number.size(); i++){
        if(primeNumber[i] > 0){
            cout << i << " " << primeNumber[i] << endl;
        }
    }
}