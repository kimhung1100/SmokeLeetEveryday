#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    double kWhTong, kWhMaylanh;
    cin >> kWhTong;
    cout << "Nhap so kWh may lanh" << endl;
    cin >> kWhMaylanh;
    double kWhThuong = kWhTong - kWhMaylanh;
    double giaTienCacMuc[6] ={1.678,1.735,2.015,2.536,2.834,2.927};
    double dienTieuDungTheoMuc[6]={0,0,0,0,0,0};
    double dienTieuDungMayLanh[6]={0,0,0,0,0,0};
    int mucDien = 0;
    for(int i = 0; i < 6; i++){
        int max;
        if(i <=1) max = 50;
        else if(i <= 4) max = 100;
        else max = 9999;
        if(kWhThuong> max){
            dienTieuDungTheoMuc[i] = max;
            kWhThuong -= dienTieuDungTheoMuc[i];
        }else{
            dienTieuDungTheoMuc[i] = kWhThuong;
            kWhThuong = 0;
            mucDien = i;
            break;
        }
    }
    for(int i = mucDien; i <6;i++ ){
        int max;
        if(i <=2) max = 50;
        else if(i <= 5) max = 100;
        else max = 9999;
        if(i == 5){
            dienTieuDungMayLanh[i] = kWhMaylanh;break;
        
        }
        if(kWhMaylanh> max){
            dienTieuDungMayLanh[i] = max - dienTieuDungTheoMuc[i];
            kWhMaylanh -= dienTieuDungMayLanh[i];
        }else{
            dienTieuDungMayLanh[i] = kWhMaylanh;
            kWhMaylanh = 0;
            mucDien = i;
            break;
        }
    }
    double tienDienThuong = 0, tienDienMayLanh = 0;
    for(int i = 0; i < 6; i++){
        tienDienThuong += dienTieuDungTheoMuc[i] * giaTienCacMuc[i];
        tienDienMayLanh += dienTieuDungMayLanh[i] * giaTienCacMuc[i];
    }
    cout << "----------------------------------------" << endl;
    cout << "Luong dien theo cac muc tien" << endl;
    cout << "     thuong     may lanh     gia tien cac muc" << endl;
    for(int i = 0; i < 6; i++){
        cout << "muc" << i+1 << ": "<< setw(8)<< dienTieuDungTheoMuc[i] << "     " << dienTieuDungMayLanh[i] <<"         "<< giaTienCacMuc[i]<< endl; 
    }
    cout << "----------------------------------------" << endl;
    cout << "tien dien thuong(thue 8%): " << tienDienThuong*1.08 << endl;
    cout << "tien dien may lanh(thue 8%): " << tienDienMayLanh*1.08 << endl;
    system ("pause");
}