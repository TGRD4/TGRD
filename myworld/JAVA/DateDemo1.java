import  java.util.*;
import java.text.*;

public class DateDemo1 {
    public static void main(String[] args) {

        Date dNow = new Date( );
        SimpleDateFormat ft = new SimpleDateFormat ("yyyy-MM-dd  hh:mm:ss");

        System.out.println("当前时间为: " + ft.format(dNow));
    }
}
/*
SimpleDateFormat 是一个以语言环境敏感的方式来格式化和分析日期的类。SimpleDateFormat 允许你选择任何用户自定义日期时间格式来运行。*/
/*
 yyyy 是完整的公元年，MM 是月份，dd 是日期，HH:mm:ss 是时、分、秒。
注意:有的格式大写，有的格式小写，例如 MM 是月份，mm 是分；HH 是 24 小时制，而 hh 是 12 小时制。
 */