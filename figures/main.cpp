#include <iostream>
#include <vector>

class figure{
    protected:
        std::string name;
    public:
        figure(){
            //std::cout << "call base constructor\n";
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

    int ARRAY_SIZE = 100;
    std::vector<figure*> vec;

    for (int i = 0; i < ARRAY_SIZE; ++i){
        int random_num = random()%3;
        if (random_num == 0){
            triangle * t = new triangle();
            vec.push_back(t);
        }
        else if(random_num == 1) {
            square * s = new square();
            vec.push_back(s);
        }
        else {
            circle * c = new circle();
            vec.push_back(c);
        }
    }
    for (int i = 0; i < vec.size(); ++i){
        vec[i]->print();
        delete vec[i];
    }

    vec.clear();

    return 0;
}
