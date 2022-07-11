#include <iostream>
#include <vector>
#include <queue>
#include <string>
//#include <string.h>
using namespace std;
class khachHang{
public:
    string name;
    long long money;
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<khachHang> list;

    for (int i = 0; i < n; i++){
        string name;
        long long money;
        cin >> name;
        cin >> money;
        khachHang kh;
        kh.name = name;
        kh.money = money;
        list.push_back(kh);
    }
    // xu ly chuyen tien
    for(int j = 0; j < m; j++){
        string nameA, nameB;
        long long money;
        cin >> nameA;
        cin >> nameB;
        cin >> money;
        int a = -1;
        int b = -1;
        for(int i = 0; i < n; i++){
            if(list[i].name == nameA && list[i].money >= money){
                a = i;
                break;
            }
        }
        if(a == -1)
            continue; //khong co tai khoan nay
        else{//success
            for(int i = 0; i < n; i++){
                if(list[i].name == nameB && list[i].money >= money){
                    b = i;
                    break;
                }
            }
            list[a].money -= money;
            list[b].money += money;
        }
        
    }


    //sap xep lai theo alphabet
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            string ab = list[i].name;
            string ac = list[j].name;
            int cmp = ac.compare(ab);
            if(cmp > 0){
            //if(list[i].name > list[j].name){
                khachHang temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        cout << list[i].name << " " << list[i].money << endl;
    }
}