#include <iostream>
#include <vector>
#include <array>

typedef std::array<int, 2> vertex;

class figure{
    protected:
        std::string name;
        std::vector<vertex> rect;
    public:
        figure(){
            std::cout << "call base constructor\n";
        }

        void print_name() {  std::cout << "\nName: " << name << "\n"; };

        virtual void print_position() {
            std::cout << "Position: \nvertex 1: " << rect[0][0] << ", "  << rect[0][1] << "\n";
            std::cout << "vertex 2: " << rect[1][0] << ", "  << rect[1][1] << "\n";
            std::cout << "vertex 3: " << rect[2][0] << ", "  << rect[2][1] << "\n";
        };

        virtual ~figure(){
            //std::cout << "figure is destroyed\n";
        };
};

class triangle : public figure {
    public:
        triangle(vertex x1, vertex x2, vertex x3){
            name = "triangle";
            rect = {x1, x2, x3};
        }
        ~triangle(){
            std::cout << "triangle is destroyed\n";
        }
};

class square : public figure {
    public:
        square(vertex x1, vertex x2, vertex x3, vertex x4){
            name = "square";
            rect = {x1, x2, x3, x4};
        }

        void print_position() {
            figure::print_position();
            std::cout << "vertex 4: " << rect[3][0] << ", "  << rect[3][1] << "\n";
        };

        ~square(){
            std::cout << "square is destroyed\n";
        }
};

class circle : public figure {
private:
        int circle_radius;
    public:
        circle(vertex center, int radius){
            name = "circle";
            rect = {center};
            circle_radius = radius;
        }

        void print_position() {
            std::cout << "Position: \ncenter: " << rect[0][0] << ", "  << rect[0][1] << "\n";
            std::cout << "radius: " << circle_radius << "\n";
        };

        ~circle(){
            std::cout << "circle is destroyed\n";
        }
};

vertex get_vertex(){
    int random_x = random()%100;
    int random_y = random()%100;
    return {random_x, random_y};
};

int main() {

    int ARRAY_SIZE = 100;
    std::vector<figure*> vec;

    for (int i = 0; i < ARRAY_SIZE; ++i){
        int random_num = random()%3;
        if (random_num == 0){
            vertex pos1 = get_vertex();
            vertex pos2 = get_vertex();
            vertex pos3 = get_vertex();

            triangle * t = new triangle(pos1, pos2, pos3);
            vec.push_back(t);
        }
        else if(random_num == 1) {
            vertex pos1 = get_vertex();
            vertex pos2 = get_vertex();
            vertex pos3 = get_vertex();
            vertex pos4 = get_vertex();

            square * s = new square(pos1, pos2, pos3, pos4);
            vec.push_back(s);
        }
        else {
            vertex center = get_vertex();
            int radius = random()%100;

            circle * c = new circle(center, radius);
            vec.push_back(c);
        }
    }
    for (int i = 0; i < vec.size(); ++i){
        vec[i]->print_name();
        vec[i]->print_position();
        delete vec[i];
    }

    vec.clear();

    return 0;
}
