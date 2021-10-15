#include<iostream>
#include<math.h>
#include<vector>
#include <iomanip>
using namespace std;

class Figure{
    public:
    virtual float calc_perimeter() = 0;
    virtual float calc_field() = 0; 
};

class Circle : public Figure{
    public:
    int radius;

    Circle(int radius){
        this->radius = radius;
    }

    float calc_perimeter(){
        
        return 2 * 3.14 * this->radius;
    }

    float calc_field(){
        return 3.14 * radius * this->radius;
    }
};

class Square : public Figure{
    public:
    int side;

    Square(int side){
        this->side = side;
    }

    float calc_perimeter(){
        return 4 * this->side;
    }

    float calc_field(){
        return this->side * this->side;
    }
};

class Rectangle : public Figure{
    public:
    int oneSide, otherSide;

    Rectangle(int oneSide, int otherSide){
        this->oneSide = oneSide;
        this->otherSide = otherSide;
    }

    float calc_perimeter(){
        return 2 * this->oneSide + 2 * this->otherSide;
    }

    float calc_field(){
        return this->oneSide * this->otherSide;
    }
};

class Triangle : public Figure{
    public:
    int sideOne, sideTwo, sideThree;
    float halfPerimeter;

    Triangle(int sideOne, int sideTwo, int sideThree){
        this->sideOne = sideOne;
        this->sideTwo = sideTwo;
        this->sideThree = sideThree;
        this->halfPerimeter = (float(sideOne) + float(sideTwo) + float(sideThree)) / 2;
        
    }

    float calc_perimeter(){
        return this->halfPerimeter * 2;
    }

    float calc_field(){
        return sqrt(this->halfPerimeter * (this->halfPerimeter - this->sideOne) * (this->halfPerimeter - this->sideTwo) * (this->halfPerimeter - this->sideThree));
    }

};


int main(){
    int n;
    int x, y, z;
    vector<Figure*> vec;
    char fig;
    cout << "Number of figures: ";
    cin >> n;
    
    while(n--){
        cin >> fig;

        if(fig=='c'){
            cin >> x;
            Circle *instance = new Circle(x);
            vec.push_back(instance);
        }else if(fig=='s'){
            cin >> x ;
            Square *instance = new Square(x);
            vec.push_back(instance);
        }else if(fig=='r'){
            cin >> x >> y;
            Rectangle *instance = new Rectangle(x, y);
            vec.push_back(instance);
        }else if(fig=='t'){
            cin >> x >> y >> z;
            Triangle *instance = new Triangle(x, y, z);
            vec.push_back(instance);
        }
    }

    cin>>n;

    while(n--){
        cin >> fig >> x;

        if(fig=='p'){
            cout<<fixed<<setprecision(2)<<vec[x-1]->calc_perimeter()<<endl;
        }else if(fig=='a'){
            cout<<fixed<<setprecision(2)<<vec[x-1]->calc_field()<<endl;
        }
    }

    for(int i=0;i<vec.size();i++){
        delete vec[i];
    }

}