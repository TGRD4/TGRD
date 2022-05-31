/* vector容器 */
/*
容器是用来管理某一类对象的集合，C++ 提供了各种不同类型的容器，比如 deque、list、vector、map 等
下面的程序演示了向量容器（一个 C++ 标准的模板），它与数组十分相似，唯一不同的是，向量在需要扩展大小的时候，会自动处理它自己的存储需求：
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 创建一个向量存储 int
    vector<int> vec; 
    int i;
    
    // 显示 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;
    // 推入 5 个值到向量中
    for(i = 0; i < 5; i++) {
        vec.push_back(i);
    }
    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;
    
    // 访问向量中的 5 个值
    for(i = 0; i < 5; i++) {
        cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }
    
    // 使用迭代器 iterator 访问值（使用迭代器读取vector中的每一个元素，只能读而不能修改）
    vector<int>::iterator v = vec.begin();      // 定义了一个vector<int>类型的迭代器
    while(v!=vec.end()) {
        cout << "value of v = " << *v << endl;  // 输出指针指向的值
        v++;                                    // 指针位置的移动
    }
/*
push_back( ) 成员函数在向量的末尾插入值，如果有必要会扩展向量的大小
size( ) 函数显示向量的大小
begin( ) 函数返回一个指向向量开头的迭代器
end( ) 函数返回一个指向向量末尾的迭代器
*/
   return 0;
}
