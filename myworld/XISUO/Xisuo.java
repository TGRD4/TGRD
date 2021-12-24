import java.io.*;
public class Xisuo {
    String name;
    char sex;
    String number;
    String corps;
    String ability;
    String works;

    public Xisuo(String empname) {
        name = empname;
    }

    public void empsex(char empsex) {
        sex = empsex;
    }

    public void empnumber(String empnumber) {
        number = empnumber;
    }

    public void empcorps(String empcorps) {
        corps = empcorps;
    }

    public void empability(String empability) {
        ability = empability;
    }

    public void empworks(String empworks) {
        works = empworks;
    }

    public void printXisuo() {
        System.out.println("名字:" + name);//自动换行
        System.out.println("性别:" + sex);
        System.out.println("编号:" + number);
        System.out.println("军团" + corps);
        System.out.println("能力:" + ability);
        System.out.println("出自作品:" + works);
    }
}
