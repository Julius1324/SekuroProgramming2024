#include <iostream>
class Shape
{
    private:
    float area;
    float keliling;
public:
    virtual float calculateArea(){
        return 0;
    }
    virtual float calculateKeliling(){
        return 0;
    }

};
class Rectangle : public Shape
{
private:
 float width;
 float length;
public:
Rectangle(float panjang,float lebar){
this->width=lebar;
this->length=panjang;
}

float calculateArea(){
    float hasil =width*length;
    return hasil;
}
float calculateKeliling(){
    return 2*(width+length);
}
};

int main(){
    Rectangle rect(5.0,4.0);
    Shape* shape1 = &rect;
    std::cout<<shape1->calculateArea()<<std::endl;
    std::cout<<shape1->calculateKeliling()<<std::endl;
    return 0;
}