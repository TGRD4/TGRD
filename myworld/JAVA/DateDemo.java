import java.util.Date;

public class DateDemo {
    public static void main(String[] args) {
        // 初始化 Date 对象
        Date date = new Date();//  系统自带时间类
        // 使用 Date类的 date 对象的 toString() 方法来打印当前日期和时间
        System.out.println(date.toString());
    }
}
/*
java.util 包提供了 Date 类来封装当前的日期和时间。
Date 类提供两个构造函数来实例化 Date 对象。
第一个构造函数使用当前日期和时间来初始化对象。Date( )
第二个构造函数接收一个参数，该参数是从 1970 年 1 月 1 日起的毫秒数。Date(long millisec)
 */