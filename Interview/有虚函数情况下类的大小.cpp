# include<iostream>
using namespace std;
 

class base1{
public:
	int a;
public:
	virtual void fun1(){}
	virtual void fun2(){}
};
class A{
	virtual void f1(){
		cout<<"I AM BASE CLASS A FUNCTION 1"<<endl;
	}
	virtual void f2(){
		cout<<"I AM BASE CLASS A FUNCTION 2"<<endl;
	} 
};
class B{
	int a; 
	virtual void f1(){
		cout<<"I AM BASE CLASS B FUNCTION 1"<<endl;
	}
	virtual void f2(){
		cout<<"I AM BASE CLASS B FUNCTION 2"<<endl;
	} 
};
class C :public B{
	virtual void f1(){
		cout<<"I AM SUB CLASS C FUNCTION 1"<<endl;
	}
	virtual void f2(){
		cout<<"I AM SUB CLASS C FUNCTION 2"<<endl;
	} 
	void f3(){
		cout<<"I AM SUB CLASS C FUNCTION 3"<<endl;
	} 
};
class D :public B,public A{
	virtual void f1(){
		cout<<"I AM SUB CLASS D FUNCTION 1"<<endl;
	}
	virtual void f2(){
		cout<<"I AM SUB CLASS D FUNCTION 2"<<endl;
	} 
};

int main(){
	cout<<sizeof(base1)<<endl; //int 被对齐成为了八字节。2*8 = 16 
	cout<<sizeof(A)<<endl; //虚函数指针8字节（×64） 
	cout<<sizeof(B)<<endl; //同上 
	cout<<sizeof(C)<<endl; //父类有虚函数，就不用管自己了。继承父类的虚指针，8. 再加上从父类继承下来的int，8+8=16 
	cout<<sizeof(D)<<endl; //有两个父类，且没有虚继承，8×2=16 
}
