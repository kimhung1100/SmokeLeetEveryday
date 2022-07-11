#include <iostream>
#include <string>
using namespace std;
int chia_lay_du(string n, int m)
    {
        string temp;
        int du;
        for(int i=0; i<int(n.length()); i++)
        {
            temp+=n[i];
            du=stoi(temp);
            if(du>=m)
            {
                du=du%m;
                temp=to_string(du);
            }
        }
        return du;
    }

int main(){
    string id = "tY";
    string temp = to_string(1);
    //temp.pop_back();
    for(unsigned int i = 0; i < id.size(); i++){
        int t = (id[i])-'0';
        temp.append(to_string(t));
    }
    cout << temp << endl;
    int h1= stoll(temp) % 176;
    int h2 = 1 + chia_lay_du(temp, 176 - 2);
    int h21 = (stoll(temp) % 174) + 1;
    cout << h21 << " "<< h2 << "h" << endl;
    cout << h1 <<" " << h2 << endl;
    cout << (651 * 1 * h21  + h1 )% 176<< endl;
    
    //cout << stollong(a);
}