# include<iostream>
using namespace std;
class A{
public:
	virtual void f1(){
	}
};
class B: virtual A{
public:
	virtual void f1(){
	}
};
class C: virtual  A{
public:
	virtual void f1(){
	}
};
class E: virtual  A{
public:
	virtual void f1(){
	}
};
class D:  C, B,E{
public:
	virtual void f1(){
	}
};
int main (){
	cout<<sizeof(A)<<endl; 
	cout<<sizeof(B)<<endl;
	cout<<sizeof(C)<<endl; 
	cout<<sizeof(D)<<endl; 
	return 0; 
} 
