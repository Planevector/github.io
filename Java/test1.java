public class test1{
int a=20;
void speak(){
System.out.println("hello"+"world"+a);
}
public static void main(String[] args){
    test1 t =new test1();
    t.a=18;
    t.speak();
}
}