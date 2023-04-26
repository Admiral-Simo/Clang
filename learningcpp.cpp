#include <iostream>

class Person {
    public: 
        Person(std::string _name) : name(_name) {}
        void introduce() {
            std::cout << "My name is " << name << std::endl;
        }
    private:
        std::string name;
};

int main() {
    Person* simo_ptr = new Person("Mohamed");
    simo_ptr->introduce();

    delete simo_ptr;

    return 0;
}