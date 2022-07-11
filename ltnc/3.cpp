#include <iostream>
#include <vector>

using namespace std;
class Rectangle{
private:
    int width;
    int height;
public:
    Rectangle(){
        this->width = 0; this->height = 0;
    }
    void setRectangle(double width, double height){
        this->width = width; this->height = height;
    }
    ~Rectangle(){}
    double getArea(){
        return width * height;
    }
};
int main(){
    int numOfRetangle;
    cout << "How many retangle? ";
    cin >> numOfRetangle;
    if(numOfRetangle < 1 || numOfRetangle > 100){
        cout << "Out of number of retangle";
        return 0;
    }
    vector <Rectangle> arr;
    arr.resize(numOfRetangle);
    for(int i = 0; i < numOfRetangle; i ++){
        cout << "-----" << endl;
        cout << "Input width and height for retangle " << i + 1 << ":" << endl;
        int w, h;
        cout << "Width: ";
        cin >> w;
        cout << "Height: ";
        cin >> h;
        arr[i].setRectangle(w,h);
    }
    
    cout << "==========" << endl;
    for(int i = 0; i < numOfRetangle; i++){
        cout << "The area of retangle " << i+1 << ": " << arr[i].getArea() << endl;
    }
}