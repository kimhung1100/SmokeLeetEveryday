// Include additional libraries and write helper functions here
#include <iostream>
#include <vector>
using namespace std;
vector<int> canSeeTeacher(vector<int>& heights) {
    // To Do
    vector <int> result;
    int temp;
    unsigned int size = heights.size();
    
    //it2 = temp.begin();
    for(int i = (int)size - 1; i >= 0; i--){
        if(i == size -1){
            result.push_back(i);
            temp= heights[i];

        }else{
            if(heights[i] > temp){
                temp = heights[i];
                result.push_back(i);
            }
        }
    }
    for(unsigned int i = 0; i < result.size()/ 2; i++){
        int temp = result[i];
        result[i] = result[result.size() - 1 - i];
        result[result.size() - 1 - i] = temp;
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for(int i = 0; i < n; i++) cin >> heights[i];

    for(int i : canSeeTeacher(heights))
        cout << i << ' ';
}