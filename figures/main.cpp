#include <iostream>
#include <vector>

class figure{
    protected:
        std::string name;
    public:
        figure(){
            name;
        }
        void print() {  std::cout << "Figures name: " << name << "\n"; };

        ~figure() { std::cout << "figure is destroyed \n"; }
};

class triangle : public figure {
    public:
        triangle(){
            name = "triangle";
        }
        ~triangle(){
            std::cout << "triangle is destroyed\n";
        }
};

class square : public figure {
    public:
        square(){
            name = "square";
        }
        ~square(){
            std::cout << "square is destroyed\n";
        }
};

class circle : public figure {
    public:
        circle(){
            name = "circle";
        }
        ~circle(){
            std::cout << "circle is destroyed\n";
        }
};

int main() {

    int size = 10;
    figure arr[size];
    for (int i = 0; i < size; i++){
        int random_num = random()%3;
        if (random_num == 0){
            triangle t;
            arr[i] = t;
        }
        else if(random_num == 1) {
            square s;
            arr[i] = s;
        }
        else {
            circle c;
            arr[i] = c;
        }
    }
    for (int i = 0; i < size; i++){
        arr[i].print();
    }

    return 0;
}