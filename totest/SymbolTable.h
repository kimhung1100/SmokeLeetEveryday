#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"
long long int stollong(string num){
    long long int ans = 0;
    int size = num.size();
    for (int i = 0; i < size; i++){
        ans = ans * 10 + (num[i]- '0');
    }
    return ans;
}
int stoint(string num){
    int ans = 0;
    int size = num.size();
    for (int i = 0; i < size; i++){
        ans = ans * 10 + (num[i]- '0');
    }
    return ans;
}
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
class Type{
public:
    string name;
    string typ;
    int levelE;
    bool func;
    bool active;
    
    string* dirPara;
    int para;
    Type(){
        this -> name = "";
        this -> typ = "";
        this -> levelE = 0;
        this -> func = false;
        this -> para = 0;
        this -> active = false;
        this -> dirPara = nullptr;
    }
    void deleteType(){
        this -> deleteDirPara();
        this -> name = "";
        this -> typ = "";
        this -> levelE = 0;
        this -> func = false;
        this -> para = 0;
        this -> active = false;
    }
    ~Type(){
        /*
        if(dirPara)
            delete [] dirPara;
            */
    }
    Type(string name, string type, int levelE, bool func, int para, bool active = true){
        this -> name = name;
        this -> typ = type;
        this -> levelE = levelE;
        this -> func = func;
        this -> para = para;
        this -> active = active;
        DirPara(para);
        
    }
    void DirPara(int para){
        if(para >= 1){
            this ->dirPara = new string[para];
        }
        this -> para = para;
    }
    void writePara(int i, string paras){
        if(i < para && i >= 0)
        this -> dirPara[i] = paras;
    }
    string getPara(int index){
        if(index < para && index >= 0)
        return dirPara[index];
        return "-1";
    }
    void deleteDirPara(){
        if(para > 0 && dirPara != nullptr)
            delete [] dirPara;
        this -> dirPara = nullptr;
        para = 0;
    }
};

class SymbolTable
{
public:
    //Record record;
    //friend class Type;
    Type* typeE;
    int size;
    int c;
    int c2;
    string typeHash;
    int level;
    SymbolTable() {
        this -> typeE = nullptr;
        this -> size = 0;
        this -> level = 0;
        this -> c = 0;
        this -> c2 = 0;
        this -> typeHash = "";
        //record  = Record();
        //record.elements = nullptr;
    }
    
    
    ~SymbolTable() {
        /*
        record.deleteRecord();
        level = 0;
        */
        /*
        delete [] typeE;
        this -> typeE = nullptr;
        this -> size = 0;
        this -> level = 0;
        this -> c = 0;
        this -> c2 = 0;
        this -> typeHash = "";
        */
       if(typeE)
            delete [] typeE;
    }

    void initRecord(string type, int size, int c, int c2);
    string getKey(string id, int level);
    
    void del();
    void run(string filename);
    ///
    int hashInsert(string key, int& count, string id);
    int hashSearch(string key, int& count, string id);
    int h(long long int key);
    int h2(long long int key);
    int hp(string key,int i);
    ///

    int insert(string id, string num);
    int assign(string id, string value, string& error);
    int searchForAssign(string id, int& count);
    int searchForLookup(string id, int& count);
    int call(string func, string& error);
    void deleteInLevel(int levelc);
    int lookup(string id);
    void print();
};
int SymbolTable :: h(long long int key){
    return key % (int)size;
}
int SymbolTable :: h2(long long int key){
    return (key %  (size - 2)) + 1;
}
int SymbolTable :: hp(string key, int i){
    if(typeHash == "LINEAR"){
        return (h(stollong(key)) + c * i) % size;
    }else if(typeHash == "QUADRATIC"){

        return (h(stollong(key)) + c*i + c2*i*i) % size; 
    }else if(typeHash == "DOUBLE"){
        int h1= stollong(key)%size;
        int h2 = (stollong(key) % (size - 2)) + 1;
        //int h2 = 1 + chia_lay_du(key, size - 2);
        return (h1 + c * i * h2) % size;
        //return ((long long int)(h(key) + c*i*h2(key)) % size);
    }
    else return -1;
}
int SymbolTable :: hashInsert(string key, int& count, string id){
    int i = 0;
    while(i < size && i >= 0){
        int j = hp(key, i);
        if(j >= size && j < 0) {continue;}
        if(typeE[j].name == ""){
            //elements[i] = key;
            count = i;
            typeE[j].name = id;
            return j;
        }else{
            i = i + 1;
            count ++;
        }
    }
    return -1;
}
int SymbolTable :: hashSearch(string key, int& count, string id){
    int i = 0;
    while (i < size && i >= 0){
        int j = hp(key, i);
        if(j >= size && j < 0) {break;}
        if(typeE[j].name == id) {
            /*count = (i == 0 ? count + 1 : count);*/ return (int)j;
        }
        else if(typeE[j].name == "")
            return -1;
        else{
            i++;
            count++;
        }
    }
    return -1;
}
void SymbolTable :: initRecord(string type, int size, int c, int c2){
    this -> typeE = new Type[size];
    this -> size = size;
    this -> c = c;
    this -> c2 = c2;
    this -> typeHash = type;
    this -> level = 0;
}


string SymbolTable :: getKey(string id, int level1){
    int l = level1;
    string temp = to_string(l);
    for(unsigned int i = 0; i < id.size(); i++){
        int t = (id[i])-'0';
        temp.append(to_string(t));
    }
    //long long int templ = stollong(temp);

    //cout << templ << " <-" << endl;
    //cout << size << " " << c << " "<< c2 << endl;

    //templ = templ % size;
    return temp;
}


#endif