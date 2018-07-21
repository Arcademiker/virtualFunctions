#include <iostream>
#include <vector>

class A {
protected:
    int test;

public:
    virtual void move() { // or pure virtual = 0
        test = 0;
    };
    A(int start) {
        test = start;
    }
    int get_test() {
        return this->test;
    }
};

class B : public A {
public:
    B(int start) : A(start) {
        test = start;
    }
    void move() override {
        this->test = this->test+1;
    }
};

class C : public A {
public:
    C(int start) : A(start) {
        test = start;
    }
    void move() override {
        this->test = this->test-1;
    }
};

class collection {
private:
    std::vector<A*> Alist;
public:
    void add(A* a) {
        this->Alist.push_back(a);
    }
    A* get(int index) {
        return this->Alist.at(index);
    }
};

int main() {
    collection mycollection;
    B b(3);
    C c(2);
    A a(1);
    mycollection.add(&b);
    mycollection.add(&c);
    mycollection.add(&a);
    std::cout << mycollection.get(0)->get_test() << " " << mycollection.get(1)->get_test() << " " << mycollection.get(2)->get_test() << std::endl;
    mycollection.get(0)->move();
    mycollection.get(1)->move();
    mycollection.get(2)->move();
    std::cout << mycollection.get(0)->get_test() << " " << mycollection.get(1)->get_test() << " " << mycollection.get(2)->get_test() << std::endl;
}