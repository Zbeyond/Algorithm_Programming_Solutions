#include <iostream>  
#include <string>  
using namespace std;  
  
//������A  
class A  
{  
public:  
    A()  
    {  
        cout<<"������A�Ĺ��캯��"<<endl;  
    }  
    //���麯��fun  
    virtual void fun1() = 0;  
};  
  
//������B  
class B  
{  
public:  
    B()  
    {  
        cout<<"������B�Ĺ��캯��"<<endl;  
    }  
    //���麯��fun  
    virtual void fun2() = 0;  
};  
  
//��ͨ��C  
class C  
{  
public:  
    C()  
    {  
        cout<<"��C�Ĺ��캯��"<<endl;  
    }  
};  
  
//��ͨ��D  
class D  
{  
public:  
    D()  
    {  
        cout<<"��D�Ĺ��캯��"<<endl;  
    }  
};  
  
//��ͨ��C  
class E  
{  
public:  
    E()  
    {  
        cout<<"��E�Ĺ��캯��"<<endl;  
    }  
};  
  
//��ͨ��D  
class F  
{  
public:  
    F()  
    {  
        cout<<"��F�Ĺ��캯��"<<endl;  
    }  
};  
  
//��ͨ��D  
class G  
{  
public:  
    G()  
    {  
        cout<<"��G�Ĺ��캯��"<<endl;  
    }  
};  
  
//��ͨ��D  
class H  
{  
public:  
    H()  
    {  
        cout<<"��H�Ĺ��캯��"<<endl;  
    }  
};  

  
class Test: public A,public B,virtual public C,virtual public D,public E,public F  
{  
public:  
    Test():B(),A(),D(),C(),F(),E()  
    {  
        cout<<"��Test�Ĺ��캯��"<<endl;  
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
 ִ��˳��
 1. ��̬��Ա�Ĺ��캯��  H
 2. �����Ĺ��캯�����̳�ʱ��virutual�ģ� C D
 3. ������Ĺ��캯�� ���д��麯����) A B 
 4. ��������Ĺ��캯�� E F
 5. ��Ա�����Ĺ��캯�� G
 6. �Լ��Ĺ��캯�� test 
*/ 
int main(int argc, char* argv[])  
{    
    //���յ�ִ��˳��Ϊ��
	//H -> C -> D -> A -> B -> E -> F -> G -> test 
    Test test;  
    return 0;  
}  
