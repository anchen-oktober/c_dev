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

        virtual ~figure(){
            std::cout << "figure is destroyed\n";
        };
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

    int size = 100;
    figure **arr = new figure*[size];

    for (int i = 0; i < size; i++){
        int random_num = random()%3;
        if (random_num == 0){
            figure * t = new triangle();
            arr[i] = t;
        }
        else if(random_num == 1) {
            figure * s = new square();
            arr[i] = s;
        }
        else {
            figure * c = new circle();
            arr[i] = c;
        }
    }
    for (int i = 0; i < size; i++){
        arr[i]->print();
        delete arr[i];
    }

    return 0;
}
