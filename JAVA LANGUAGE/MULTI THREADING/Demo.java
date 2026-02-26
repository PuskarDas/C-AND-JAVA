class Display {
    synchronized void print(String threadName) {

        String[] words = {"I","Love","java","Very","Much"};
        for(String word:words) {
            System.out.println(threadName +": "+ word);
            try {
                Thread.sleep(500);
            } catch(InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}
class MyThread extends Thread {
    Display d;
    MyThread(Display disp,String name) {
        super(name);
        d=disp;
    }
    public void run() {
        d.print(getName());
    }
}
public class Demo {
    public static void main(String[] args) {

        Display obj=new Display();
        MyThread t1=new MyThread(obj, "Thread 1");
        MyThread t2=new MyThread(obj, "Thread 2");

        t1.start();
        t2.start();
    }
}
