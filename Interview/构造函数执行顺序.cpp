#include <iostream>  
#include <string>  
using namespace std;  
  
//抽象类A  
class A  
{  
public:  
    A()  
    {  
        cout<<"抽象类A的构造函数"<<endl;  
    }  
    //纯虚函数fun  
    virtual void fun1() = 0;  
};  
  
//抽象类B  
class B  
{  
public:  
    B()  
    {  
        cout<<"抽象类B的构造函数"<<endl;  
    }  
    //纯虚函数fun  
    virtual void fun2() = 0;  
};  
  
//普通类C  
class C  
{  
public:  
    C()  
    {  
        cout<<"类C的构造函数"<<endl;  
    }  
};  
  
//普通类D  
class D  
{  
public:  
    D()  
    {  
        cout<<"类D的构造函数"<<endl;  
    }  
};  
  
//普通类C  
class E  
{  
public:  
    E()  
    {  
        cout<<"类E的构造函数"<<endl;  
    }  
};  
  
//普通类D  
class F  
{  
public:  
    F()  
    {  
        cout<<"类F的构造函数"<<endl;  
    }  
};  
  
//普通类D  
class G  
{  
public:  
    G()  
    {  
        cout<<"类G的构造函数"<<endl;  
    }  
};  
  
//普通类D  
class H  
{  
public:  
    H()  
    {  
        cout<<"类H的构造函数"<<endl;  
    }  
};  

  
class Test: public A,public B,virtual public C,virtual public D,public E,public F  
{  
public:  
    Test():B(),A(),D(),C(),F(),E()  
    {  
        cout<<"类Test的构造函数"<<endl;  
    }  
    void fun1()  
    {  
    }  
    void fun2()  
    {  
    }  
private:  
    G g;  
    static H h;  
};  
  
H Test::h;  
/*
 执行顺序：
 1. 静态成员的构造函数  H
 2. 虚基类的构造函数（继承时有virutual的） C D
 3. 抽象类的构造函数 （有纯虚函数的) A B 
 4. 其他父类的构造函数 E F
 5. 成员变量的构造函数 G
 6. 自己的构造函数 test 
*/ 
int main(int argc, char* argv[])  
{    
    //最终的执行顺序为：
	//H -> C -> D -> A -> B -> E -> F -> G -> test 
    Test test;  
    return 0;  
}  
