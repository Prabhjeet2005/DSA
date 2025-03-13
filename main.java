import java.util.*;
import java.lang.*;
// ####### INHERITANCE ########
// class Base {
// int a=10;
// }

// class Derived extends Base {
// Derived(int a) {
// this.a = a;
// }
// void display() {
// System.out.println("Value of a in Base is: " + a);
// }
// }

// class main {

// public static void main(String[] args) {
// Derived d = new Derived(10);
// d.display();
// }
// }

// ####### INTERFACE #######
// interface area{
// public final static double pi = 3.14;
// public abstract void calcArea();
// }

// class Circle implements area{
// int radius;
// Circle(int radius){
// this.radius = radius;
// }
// public void calcArea(){
// double areaOfCircle = pi * radius * radius;
// System.out.println("Area Of Circle: "+areaOfCircle);
// }
// }

// class Rectangle implements area{
// int length,breadth;
// public Rectangle(int length,int breadth){
// this.length = length;
// this.breadth = breadth;
// }

// public void calcArea(){
// double a = length * breadth;
// System.out.println("Area of Rectangle is: "+a);
// }
// }

// class main{
// public static void main(String []args){
// Circle cobj = new Circle(2);
// Rectangle robj = new Rectangle(2,4);
// cobj.calcArea();
// robj.calcArea();
// }
// }



// class main{
//   abstract class base{
//     public abstract void start();
//   }
//   public class derived extends base{
//     public void start(){
//       System.out.print("Engine Started");
//     }
//   }
// public static void main(String []args){
//   main b = new main();
//   derived d = b.new derived();
//   d.start();
//   for(int i=0; i<10; i++){
//     System.out.println(i+1);
//   }
// }
// }


import java.io.*;

class main{
  public static void validateAge(int age) throws Exception{
    if(age > 18){
      System.out.println("Age Valid");
    }
    throw new Exception("Invalid Age");
  }
  public static void main(String[] args){
    try{
      int a = 1;
      int b = 0;
      int c = a/b;
      System.out.println("c: "+c);
    }catch(Exception e){
      System.out.println("Division by Zero error"+e.getMessage());
    }finally{
      System.out.println("Finally Block");
    }
    
    try {
      int age = 17;
      validateAge(age);
    } catch (Exception e) {
      System.out.println("Caught Exception: "+e.getMessage());
    }
  }

}
