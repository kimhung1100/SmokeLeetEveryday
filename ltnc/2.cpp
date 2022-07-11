#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> ar;
    int limit;
    cout << "Input the limit: ";
    cin >> limit;
    if(limit > 150 || limit < 10){
        cout << "Out of limit";
        return 0;
    }
    
    ar.resize(limit + 1);
    fill_n(ar.begin(),limit + 1, 0);
    for(int i = 3; i < limit + 1; i = i + 3){
        ar[i] = 1; // chia het cho 3
    }
    for(int i = 5; i < limit + 1; i = i + 5){
        if(ar[i] == 1)
            ar[i] = 3; // chia het cho 3 va 5
        else
            ar[i] = 2; // chia het cho 5
    }
    cout << "Numbers which is divisible by 3 and 5 is : ";
    bool firstPrint = false;
    for(int i = 0; i < limit + 1; i++){
        if(ar[i] == 3){
            if(firstPrint == false){
                cout << i; // chia het cho 3 va 5
                firstPrint = true;
            }else{
                cout << "," << i;
            }
        }
    }
    cout << endl << "Sum of numbers being divisible by either 3 or 5:";
    int sum = 0;
    for(int i = 0; i < limit + 1; i++){
        if(ar[i] == 1 || ar[i] == 2 || ar[i] == 3){
            //cout << " " << i << ","; // chia het cho 3 hoac 5
            sum+= i;
        }
            
    }
    cout << " " << sum << endl;
    /*
    cout << endl << "Sum will be = ";
    for(int i = 0; i < limit + 1; i++){
        bool firstPrint = false;
        if(ar[i] == 1 || ar[i] == 2){
            if(!firstPrint){
                cout << "+";
                firstPrint = true;
            }
            cout << i; // chia het cho 3 hoac 5
        }
    }
    */
    int countNotDivisible = 0;
    for(int i = 0; i < limit + 1; i++){
        if(ar[i] == 0){
            countNotDivisible ++; // khong chia het cho 3 hoac 5
        }
            
    }
    cout << "Count of numbers not being divisible by 3 or 5: " << countNotDivisible;
    return 0;
}