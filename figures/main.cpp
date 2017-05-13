#include <iostream>
#include <vector>

class figure{
    protected:
        std::string name;
        int rects[4] = {0, 0, 0, 0};
    public:
        figure(){
            name = "untitled figure";
        }
        void set_rects() {};
        void print() {  std::cout << "Figures name: " << name << "\n"; };

};

class triangle : public figure {
    public:
        triangle(){
            name = "triangle";
        }
};

class square : public figure {
    public:
        square(){
            name = "square";
        }
};

class circle : public figure {
    public:
        circle(){
            name = "circle";
        }
};

int main() {

    int size = 10;
    figure arr[size];
    for (int i = 0; i < size; i++){
        int random_num = random()%3;
        std::cout << random_num << "  ";
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


//    for (int i = 0; i < size; i++){
//       std::cout << i << "  ";
//    }

    return 0;
}