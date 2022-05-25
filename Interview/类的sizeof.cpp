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
	cout<<sizeof(base1)<<endl; //int �������Ϊ�˰��ֽڡ�2*8 = 16 
	cout<<sizeof(A)<<endl; //�麯��ָ��8�ֽڣ���64�� 
	cout<<sizeof(B)<<endl; //ͬ�� 
	cout<<sizeof(C)<<endl; //�������麯�����Ͳ��ù��Լ��ˡ��̳и������ָ�룬8. �ټ��ϴӸ���̳�������int��8+8=16 
	cout<<sizeof(D)<<endl; //���������࣬��û����̳У�8��2=16 
}
