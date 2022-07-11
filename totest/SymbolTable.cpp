#include "SymbolTable.h"
void tokenize (string cuts[], string s, string del = " "){
    if(int(s.find("(")) != -1){
        int start = 0;
        int end = (int)s.find(del);
        cuts[0] = s.substr(start, end - start);
        if(cuts[0] == "ASSIGN"){
            start = end + 1;
            end = (int)s.find(del, start);
            cuts[1] = s.substr(start, end - start);
            cuts[2] = s.substr(end + 1);
            return;
        }else if(cuts[0] == "CALL"){
            cuts[1] = s.substr(end + 1);
            return;
        }
    }
    int start = 0;
    int end = (int)s.find(del);
    int i = 0;
    while (end != -1 ) {
        if(i >= 4) break;
        cuts[i] = s.substr(start, end - start);
        i++;
        start = (int)end + (int)del.size();
        /*
        if((int)s.find("'", start + 1) != -1){
            end = (int)s.find("'", start  + 1);
            cuts[i] = s.substr(start, end);
            i++;
            start = (int)end + (int)del.size();
            end = (int)s.find(del, start);
            continue;
        }
        */
        end = (int)s.find(del, start);
    }
    cuts[i] = s.substr(start, end - start);
    return;
}
bool checkNum(string str){
    if (str[0] >= '0' && str[0] <= '9') {
        for (size_t i = 1; i < str.size(); i++) {
            if(str[i] < '0' || str[i] > '9') return false;
        }
        return true;
    }
    return false;
}
bool checkString(string str){
    // check const string
    if (str[0] == char(39) && str[str.size() - 1] == char(39))  {
        for (size_t i = 1; i < str.size() - 1; i++) {
            if( !((str[i] >= '0' &&  str[i] <= '9') ||
            ( (str[i] >= 'a') && (str[i] <= 'z')) ||
            ( str[i] >= 'A' && str[i] <= 'Z') ||
            str[i] == ' ') ) 
                return false;
        }
        return true;
    }
    return false;
}
bool checkName(string checkName) {
    if (checkName[0] < 'a' || checkName[0] > 'z') return false;
    for (int i = 1; i < (int)checkName.size(); i++) {
        if( (checkName[i] >= 'a' && checkName[i] <= 'z') ||
        (checkName[i] >= 'A' && checkName[i] <= 'Z') ||
        checkName[i] == '_' || (checkName[i]>= '0' && checkName[i] <= '9'))
            continue;
        else return false;
    }
    return true;
}
string cutFunc(string str, string rPara[]){
    string para = str.substr((int)str.find("("));
    str.erase((int)str.find("("));
    string aPara[100];
    for(int i = 0; i < 100; i++)
        aPara[i] = "";

    para.pop_back();
    para.erase(0,1);
    tokenize(aPara,para ,",");
    int i = 0;
    while(aPara[i].size() != 0){
        rPara[i] = aPara[i];
        i++;
    }
    return str;
}
bool checkFunc(string str){
    if((int)str.find('(') == -1) return false;
    string funcName;
    string aPara[100];
    //fill_n(aPara, 100, "");
    for(int i = 0; i < 100; i++)
        aPara[i] = "";
    funcName = cutFunc(str, aPara);
    if(!checkName(funcName)) return false;
    int i = 0;
    while(aPara[i].size() != 0){
        if(!checkName(aPara[i]) && !checkNum(aPara[i]) && !checkString(aPara[i])) return false;
        i++;
    }
    return true;
}
bool checkValueType(string str) {
    // checkNum
    if (str[0] >= '0' && str[0] <= '9') {
        for (size_t i = 1; i < str.size(); i++) {
            if(str[i] < '0' || str[i] > '9') return false;
        }
        return true;
    }
    // checkString
    else if (str[0] == char(39) && str[str.size() - 1] == char(39))  {
        for (size_t i = 1; i < str.size() - 1; i++) {
            if( !((str[i] >= '0' &&  str[i] <= '9') ||
            ( (str[i] >= 'a') && (str[i] <= 'z')) ||
            ( str[i] >= 'A' && str[i] <= 'Z') ||
            str[i] == ' ') ) 
                return false;
        }
        return true;
    }
    // checkName and checkFunc
    else {
        if(!checkName(str) && !checkFunc(str)) return false;
            return true;
    }
    return false;
}


bool checkInstruction(string cutS[]) {
    if(cutS[4] != "") return false;
    if(cutS[0] == "LINEAR" || cutS[0] == "QUADRATIC" || cutS[0] == "DOUBLE"){
        // check m and c is number
        if(cutS[0] == "QUADRATIC"){
            if(checkNum(cutS[1]) && checkNum(cutS[2]) && checkNum(cutS[3])) return true;
            else return false;
        }
        // linear and double
        if(cutS[3] != "") return false;
        if(checkNum(cutS[1]) && checkNum(cutS[2])) return true;
        return false;
    }else if(cutS[0] == "INSERT"){
        if(!checkName(cutS[1])) return false;
        if(checkNum(cutS[2])) return true;
        if(cutS[2] != "") return false;
        else return true;
    }else if(cutS[0] == "ASSIGN"){
        if(!checkName(cutS[1])) return false;
        if(!checkValueType(cutS[2])) return false;
        return true;
    }else if(cutS[0] == "CALL"){
        if(!checkFunc(cutS[1])) return false; // check func
        if(cutS[2] != "") return false;
        return true;
    }else if(cutS[0] == "BEGIN" || cutS[0] == "END"){
        if(cutS[1] != "" || cutS[2] != "") return false;
        return true;
    }else if(cutS[0] == "LOOKUP"){
        if(cutS[2] != "") return false;
        return true;
    }else if(cutS[0] == "PRINT"){
        if(cutS[1] != "" || cutS[2] != "") return false;
        return true;
    }
    else return false;
}
int SymbolTable:: insert(string id, string num){
    if(level != 0 && num != "") // InvalidDeclaration, khai bao ham o muc khac 0
        return -2;
    int countDoNt = -1;
    int s = hashSearch(getKey(id, level), countDoNt, id);
    if(s != -1){ // Redeclared
        if(typeE[s].levelE == level)
        return -1;
    }
    int count = 0; 
    int i = hashInsert(getKey(id, level) , count, id);
    if(i == -1) return -3; // Overflow
    else { // success
        if(num != ""){ // insert function
            int para = stoint(num);
            typeE[i] = Type(id, "", level, true,para,true);
        }
        else{
            typeE[i] = Type(id, "", level,false,-1,true);
        }
        //elements[i] = getKey(id);
        for(int i = level -1; i >=0 ; i--){ // find id in lower level
            int inActive = hashSearch(getKey(id,i), countDoNt, id);
            if(inActive < 0 || typeE[inActive].levelE == level) continue;
            if(typeE[inActive].active == true){
                typeE[inActive].active = false;
                break;
            }
        }
        return count;
    }return count;
}
string checkPara(string para){
    if(checkNum(para)) return "number";
    else if(checkString(para)) return "string";
    else if(checkName(para)) return "name";
    return para; // can't 
}
int SymbolTable :: searchForAssign(string id, int& count){
    int countDoNt = 0;
    int inActive = -1;
    //int t = 0;
    for(int i = level; i >=0 ; i--){ // find id in level and lower level
        countDoNt = 0;
        inActive = hashSearch(getKey(id,i), countDoNt, id);
        
        if(inActive < 0 || typeE[inActive].levelE != i) continue;
        if(typeE[inActive].active == true){
            count += countDoNt;
            return inActive;
            break;
        }
        countDoNt = 0;
    }
    return inActive;
}
int SymbolTable :: assign(string id, string value, string &error){
    if((int)value.find('(') != -1){ // assign func
        string funcName;
        string aPara[100];
        //fill_n(aPara, 100, "");
        for(int i = 0; i < 100; i++)
            aPara[i] = "";
        funcName = cutFunc(value, aPara);
        int count = 0;
        int iId = searchForAssign(id, count);
        int iFunc = searchForAssign(funcName, count);
        if(iFunc < 0) {// Undeclared, one or two of them undclared
            error = funcName;
            return -1; 
        }
        if (typeE[iFunc].func == false) {
            //error = funcName;
            return -2; //Typemismatch, nameFunc not a func
        }
        //if (typeE[iId].func == true) return -2; // Typemismatch, identify is a func
        if(typeE[iFunc].typ == "void"){
            return -2;
        }
        
        
        int countPara = 0;
        
        while(aPara[countPara].size() != 0) countPara ++;
        if(countPara != typeE[iFunc].para) return -2; //

        for(int i = 0; i < countPara; i++){ // check parameter in func
            if(checkPara(aPara[i]) == "name"){
                int iPara = searchForAssign(aPara[i], count);
                if(iPara < 0) {error = aPara[i]; return -1;} // Undeclared a para
                if(typeE[iPara].func == true) return -2;
                if(typeE[iPara].typ == "" && typeE[iFunc].getPara(i) == "") return -3; // para
                if(typeE[iPara].typ != "" && typeE[iFunc].getPara(i) != "" 
                &&typeE[iPara].typ != typeE[iFunc].getPara(i))
                    return -2; // TypeMisMatch
                // success
                if(typeE[iPara].typ == "") // suy dien
                    typeE[iPara].typ = typeE[iFunc].getPara(i);
                else if(typeE[iFunc].getPara(i) == "")
                    typeE[iFunc].writePara(i,typeE[iPara].typ);
                
            }
            else if(checkPara(aPara[i]) == "number"){
                if(typeE[iFunc].getPara(i) == "string") return -2; // typemismatch
                else if(typeE[iFunc].getPara(i) == "")  typeE[iFunc].getPara(i) = "number"; // suy dien
                // success aPara == number  
            }else if(checkPara(aPara[i]) == "string"){
                if(typeE[iFunc].getPara(i) == "number") return -2; //
                else if(typeE[iFunc].getPara(i) == "")  typeE[iFunc].getPara(i) = "string"; // suy dien
            }
        }
        if(iId < 0){
            error = id;
            return -1;
        }
        
        if (typeE[iId].typ != "" && typeE[iFunc].typ != "" && typeE[iId].typ != typeE[iFunc].typ){ 
            //error = value;
            return -2; // Typemismatch, two of them has type and differrent
        }
        
        if (typeE[iId].func == true) return -2; // Typemismatch, identify is a func

        if(typeE[iId].typ == "" && typeE[iFunc].typ == "")
            return -3; // TypeCannotBeInferred
        // success
        if(typeE[iId].typ != "" && typeE[iFunc].typ == "")
            typeE[iFunc].typ = typeE[iId].typ; // suy dien
        if(typeE[iFunc].typ != "" && typeE[iId].typ == "")
            typeE[iId].typ = typeE[iFunc].typ; // suy dien
        return count;
    }
    
    /////////////
    int count = 0;
    string typeValue = checkPara(value);
    int iId = searchForAssign(id, count);
    //int iValue = searchForAssign(value, count);
    //if(iValue < 0 ) {error = value; return -1;}
    if(typeValue == "number"){
        if(iId < 0) {error = id; return -1;} // undeclared
        if(typeE[iId].func == true) return -2;
        if(typeE[iId].typ == "string") return -2; //typemismatch
        //success
        else if(typeE[iId].typ == "") typeE[iId].typ = "number"; // suy dien
    }
    else if(typeValue == "string"){
        if(iId < 0) {error = id; return -1;} // undeclared
        if(typeE[iId].func == true) return -2;
        if(typeE[iId].typ == "number") return -2; //typemismatch
        //success
        else if(typeE[iId].typ == "") typeE[iId].typ = "number"; // suy dien
    }
    else if(typeValue == "name"){
        int iName = searchForAssign(value, count);
        if(iName < 0) {error = value; return -1;};
        if(typeE[iName].func == true) return -4; // call a func but not ()
        if(iId < 0) {error = id; return -1;} // undeclared
        if(typeE[iId].func == true) return -2;
        if(typeE[iId].typ == "" && typeE[iName].typ == "") return -3;
        else if(typeE[iId].typ == "" && typeE[iName].typ != "") // suy dien a <- b
            typeE[iId].typ = typeE[iName].typ;
        
        else if(typeE[iId].typ != "" && typeE[iName].typ == "")
            typeE[iName].typ = typeE[iId].typ; // suy dien a -> b
        else if(typeE[iId].typ != typeE[iName].typ) 
            return -2; // typemismatch
        //success
    }
    return count;
}
int SymbolTable :: call(string func, string& error){
    if(int(func.find("(")) == -1) return -2;
    string funcName;
    string funcPara[100];
    for(int i = 0; i < 100; i++)
        funcPara[i] = "";
    funcName = cutFunc(func, funcPara);
    int i = 0;
    int count = 0;
    int iFunc = searchForAssign(funcName, count);
    if(iFunc < 0) {error = funcName; return -1;}
    if(typeE[iFunc].func == false) return -2;
    int countParameter = 0;
    while(funcPara[countParameter] != "") countParameter ++;
    if(countParameter != typeE[iFunc].para) return -2;
    while(funcPara[i] != ""){
        if(iFunc < 0) return -1; // undeclared
        if(checkPara(funcPara[i]) == "name"){
            int iId = searchForAssign(funcPara[i], count);
            if(iId < 0) {error = funcPara[i]; return -1;} // undeclared para identify in func
            if(typeE[iId].func == true) return -2; // type mismatch goi ham trong para
            if(typeE[iFunc].getPara(i) != "" && typeE[iId].typ != "" 
            &&typeE[iFunc].getPara(i) != typeE[iId].typ)
                return -2; // Typemismatch kieu tham so thuc ko tuong ung
            if(typeE[iFunc].getPara(i) == "" && typeE[iId].typ != ""){
                typeE[iFunc].writePara(i, typeE[iId].typ); // suy dien vao ham
            }
            if(typeE[iFunc].getPara(i) != "" && typeE[iId].typ == ""){
                typeE[iId].typ = typeE[iFunc].getPara(i); // suy dien vao ide ??
            }
            if(typeE[iFunc].getPara(i) == "" && typeE[iId].typ == "")
                return -3;

        }else if(checkPara(funcPara[i]) == "number"){
            if(typeE[iFunc].getPara(i) == "string") return -2; // typemismatch
            else if(typeE[iFunc].getPara(i) == "") {
                typeE[iFunc].writePara(i,"number"); // suy dien vao ham
            }

        }else if(checkPara(funcPara[i]) == "string"){
            if(typeE[iFunc].getPara(i) == "number") return -2; // typemismatch
            else if(typeE[iFunc].getPara(i) == "") {
                typeE[iFunc].writePara(i, "string"); // suy dien vao ham
            }
        }
        i++;
    }
    // success
    if(typeE[iFunc].typ != "void" && typeE[iFunc].typ != "") return -3; //type cannot
    else{
        typeE[iFunc].typ = "void";
    }
    return count;
}
void SymbolTable :: deleteInLevel(int levelc){
    int countDump = 0;
    for(int i = 0; i < size; i++){
        if(typeE[i].levelE == levelc /*&& typeE[i].active == true*/){
            int activeId = searchForAssign(typeE[i].name, countDump);
            if(activeId < 0) continue;
            if(activeId >= 0)
                typeE[activeId].active = true;
            typeE[i].deleteDirPara();
            typeE[i] = Type(); // delete num
            //elements[i] = 0;
        }
    }
}

int SymbolTable :: searchForLookup(string id, int& count){
    int countDoNt = 0;
    int inActive = -1;
    //int t = 0;
    for(int i = level; i >=0 ; i--){ // find id in level and lower level
        countDoNt = 0;
        inActive = hashSearch(getKey(id,i), countDoNt, id);
        
        if(inActive < 0) continue;
        else if(inActive >= 0 && inActive < size) return inActive;
    }
    return inActive;
}

int SymbolTable :: lookup(string id){
    int count = 0;
    int ans = searchForAssign(id, count);
    if(ans < 0) return -1;
    else return ans; 
}
void SymbolTable :: print(){
    bool firstPrint = false;
    for(int i = 0; i < size; i++){
        if(typeE[i].name != ""){
            if(firstPrint == true) cout << ";";
            if(firstPrint == false){
                firstPrint = true;
            }
            cout << i << " " << typeE[i].name << "//" << typeE[i].levelE;
        }
    }
    if(firstPrint) cout << endl; 
}
void SymbolTable :: del(){
    /*int countDump = 0;
    for(int i = 0; i < size; i++){
        typeE[i].deleteType(); // delete num
        elements[i] = 0;
    }
    deleteRecord();
    level = 0;
    */
    //delete [] elements;
    /*
    for(int i = 0; i < size; i++){
        if(typeE[i].func == true){
            typeE[i].deleteType();
        }
    }*/
    
    for(int i = 0; i < size; i++){
        if(typeE[i].func == true && typeE[i].para > 0){
            typeE[i].deleteDirPara();
        }
        typeE[i] = Type();
    }
    /*
    if(typeE)
    delete [] typeE;
    */
    
}
void SymbolTable::run(string filename)
{
    ifstream fileIn;
    fileIn.open(filename);
    string line;
    bool inIt = false;
    while(!fileIn.eof()){
        getline(fileIn, line);
        string cutS[6];
        tokenize(cutS, line, " ");
        if (!checkInstruction(cutS)) {
            del();
            throw InvalidInstruction(line);
        }
        if(cutS[0] == "LINEAR" || cutS[0] == "QUADRATIC" || cutS[0] == "DOUBLE"){
            if(!inIt) {
                inIt = true;
                int m = stollong(cutS[1]);
                int c = stollong(cutS[2]);
                int c2 = 0;
                if(cutS[0] == "QUADRATIC")
                    c2 = stollong(cutS[3]);
                initRecord(cutS[0], m,c,c2);
            } else {
                del();
                throw InvalidInstruction(line);
            }
        }
        else if(cutS[0] == "BEGIN"){
            level ++;
            continue;
        }else if(cutS[0] == "END"){
            if(level == 0) {
                del();
                throw UnknownBlock();}
            deleteInLevel(level);
            level --;
        }
        else if(cutS[0] == "INSERT"){
            int state = insert(cutS[1], cutS[2]);
            if(state == -1){
                del();
                throw Redeclared(cutS[1]);
            } else if(state == -2){
                del();
                throw InvalidDeclaration(cutS[1]);
            } else if(state == -3) {
                del();
                throw Overflow(line);
            } else{
                cout << state << endl;
            }
        }
        else if(cutS[0] == "ASSIGN"){
            string error = "";
            int state = assign(cutS[1], cutS[2], error);
            if(state == -1){
                del();
                throw Undeclared(error);
            }else if(state == -2){
                del();
                throw TypeMismatch(line);
            }else if(state == -3){
                del();
                throw TypeCannotBeInferred(line);
            }else if(state == -4){
                del();
                throw InvalidInstruction(line);
            }
            else cout << state << endl;
        }
        else if(cutS[0] == "CALL"){
            string error = "";
            int state = call(cutS[1], error);
            if(state == -1){
                del();
                throw Undeclared(error);
            }else if(state == -2){
                del();
                throw TypeMismatch(line);
            }else if(state == -3){
                del();
                throw TypeCannotBeInferred(line);
            }else cout << state << endl;
        }
        else if(cutS[0] == "LOOKUP"){
            string id = cutS[1];
            int state = lookup(id);
            if(state < 0){
                del();
                throw Undeclared(id);
            }else cout << state << endl;

        }
        else if(cutS[0] == "PRINT"){
            print();
        }
        
    }
    if(level > 0) {
        del(); throw UnclosedBlock(level);
    }
    del();
    fileIn.close();
}
