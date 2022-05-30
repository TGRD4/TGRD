/* c++多态 */
/* 和继承的差别就在，继承是一个派生类可以由多个基类继承过来，一个派生类存在多个基类的非私有成员;
而多态是指一个基类可以使多个派生类获得使用它非私有成员的权利 */
#include <iostream> 
using namespace std;
 
/* 1 */
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
/*
输出两个Parent class area :
导致错误输出的原因是，调用函数 area() 被编译器设置为基类中的版本，这就是所谓的静态多态，或静态链接 - 函数调用在程序执行前就准备好了。
有时候这也被称为早绑定，因为 area() 函数在程序编译期间就已经设置好了。
*/

/* 2 */
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
/* 虚函数 是在基类中使用关键字 virtual 声明的函数;在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接(默认指向基类函数)到该函数
我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用(不同派生类中的area函数)的函数，这种操作被称为动态链接，或后期绑定 */
      virtual int area()    // 加virtual进行修改（此时编译器看的是指针的内容(不同派生类中的area函数)，而不是指针的类型(基类area)）
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

/* 3 */
/* 纯虚函数 */
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // pure virtual function
      virtual int area() = 0;
};
//= 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数（不用在基类函数中给出具有实际意义的函数）

/* Shape类的多态表现（存在它的多个派生类） */
// Rectangle继承了Shape的所有非私有成员
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }      //公有函数的继承
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0):Shape(a, b) { }      
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
int main( ) {
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);
 
   // 存储矩形的地址
   shape = &rec;
   // 调用矩形的求面积函数 area
   shape->area();
 
   // 存储三角形的地址
   shape = &tri;
   // 调用三角形的求面积函数 area
   shape->area();
   
   return 0;
}
