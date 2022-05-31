/* 类模板 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;
 
/*
type 是占位符类型名称，可以在类被实例化的时候进行指定，可以使用一个逗号分隔的列表来定义多个泛型数据类型
下面的实例定义了类 Stack<>，并实现了泛型方法来对元素进行入栈出栈操作：
*/
template <class T>
class Stack { 
  private: 
    vector<T> elems;     // 创建了一个T类型的vector容器（可动态分配内存空间） 
 
  public: 
    void push(T const&);        // 入栈
    void pop();                 // 出栈
    T top() const;              // 返回栈顶元素
    bool empty() const{         // 如果为空则返回真
        return elems.empty(); 
    } 
}; 
 
/* 在外部定义模板中的函数 */
template <class T>
void Stack<T>::push (T const& elem)     // 将T类型的数据elem压入栈
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
} 
template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) {                // 若栈空则抛出一个异常
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
} 
template <class T>
T Stack<T>::top () const                // 只有被声明为const的成员函数才能被一个const类对象调用
/*
面向对象程序设计中，为了体现封装性（封装是面向对象编程中的把数据和操作数据的函数绑定在一起的一个概念，这样能避免受到外界的干扰和误用，从而确保了安全）
通常不允许直接修改类对象的数据成员，若要修改类对象，应调用公有成员函数来完成
为了保证const对象的常量性，编译器须区分不安全与安全的成员函数（即区分试图修改类对象与不修改类对象的函数）
*/

{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
} 
 
int main() 
{ 
    try { 
        Stack<int>    intStack;         // int 类型的栈 
        Stack<string> stringStack;      // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7);  
        cout << intStack.top() <<endl;  // 输出而不删除（弹出）
 
        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop();              // 输出后弹出
        stringStack.pop();              // pop第二次时是空栈，抛出错误信息
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() << endl;     // 接收到一个抛出的超出范围的错误信息
        return -1;
    } 
}
