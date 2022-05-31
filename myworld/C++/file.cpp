/* 文件 */
#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];
 
   // 以写模式打开文件
   ofstream outfile;            // ofstream 该数据类型表示输出文件流，用于创建文件并向文件写入信息
   outfile.open("afile.dat");   // 打开此文件
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);      // 从输入流读入一行不超过100的字符
 
   // 向文件写入用户输入的数据
   outfile << data << endl;
 
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();                // 此处相当于舍去缓冲区内的空白字符（忽略掉之前读语句留下的多余字符）        
/*
ignore() 是 istream 类的成员函数，它的原型是：
istream & ignore(int n =1, int delim = EOF);

此函数的作用是跳过输入流中的 n 个字符，或跳过 delim 及其之前的所有字符，哪个条件先满足就按哪个执行
两个参数都有默认值，因此 cin.ignore() 就等效于 cin.ignore(1, EOF)， 即跳过一个字符
*/
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile;             // 该数据类型表示输入文件流，用于从文件读取信息
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   /* 从文件中拿取内容写入数据 */
   infile >> data; 
   // 在屏幕上写入数据
   cout << data << endl;
   
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();
   return 0;
}
