// Bjarne p. 658  

#include <iostream>
#include <typeinfo>
// 添加自定义的头文件路径地址: c++11/print_compiler.hpp
// 这个头文件主要是用来打印当前环境的编译器信息
#include "print_compiler.hpp"

struct Poly {
    virtual void f() {}
};

struct Non_poly {};

struct D1
  : Poly
{};

struct D2
  : Non_poly
{};

void f(Non_poly& npr, Poly& pr)
{
    // 这里的npr和pr都是引用类型
    std::cout << "NPR NAME: "<<typeid(npr).name() << '\n' << std::endl;
    std::cout << "PR NAME: "<<typeid(pr).name() << '\n' << std::endl;
    // 打印npr和pr的类型信息
    // std::cout << "NPR TYPE: "<<typeid(npr).before(typeid(pr)) << '\n';
    // std::cout << "PR TYPE: "<<typeid(pr).before(typeid(npr)) << '\n';
    
}

int main (int argc, char* argv[]) 
{
    // 打印当前编译器的版本信息
    print_compiler();
    D1 d1;
    D2 d2;
    
    f(d2, d1);
    // f(*static_cast<Poly*>(nullptr), *static_cast<Null_poly*>(nullptr));

    return 0 ;
}

