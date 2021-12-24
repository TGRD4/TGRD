import java.io.*;
public class XisuoTest {
    public static void main(String[] args) {
        Xisuo empxisuo = new Xisuo("西索");
        // 调用这两个对象的成员方法
        empxisuo.empsex('男');
        empxisuo.empnumber("04");
        empxisuo.empcorps("原幻影旅团");
        empxisuo.empability(" [伸缩自如的爱] \t[轻薄的假象]");
        empxisuo.empworks(" 《全职猎人》");
        empxisuo.printXisuo();
    }
}
