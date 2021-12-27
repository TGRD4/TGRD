/*
控制台输出
        在此前已经介绍过，控制台的输出由 print( ) 和 println() 完成。这些方法都由类 PrintStream 定义，System.out 是该类对象的一个引用。

        PrintStream 继承了 OutputStream类，并且实现了方法 write()。这样，write() 也可以用来往控制台写操作。

        PrintStream 定义 write() 的最简单格式如下所示：

        void write(int byte-val)
        该方法将 byte-val 的低八位字节写到流中。

        实例
        下面的例子用 write() 把字符 "A" 和紧跟着的换行符输出到屏幕：
*/
import java.io.*;

//演示 System.out.write().
public class WriteDemo {
    public static void main(String[] args) {
        int b;
        b = 'A';
        System.out.write(b);//print/println更常用
        System.out.write('\n');
    }
}