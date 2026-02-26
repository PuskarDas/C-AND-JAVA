class CounterThread extends Thread {
    private int start;
    private int end;

    public CounterThread(String name,int l,int u) {
        super(name); 
        start=l;
        end=u;
    }

    @Override public void run() {
        for(int i=start;i<=end;i++) {
            System.out.println(Thread.currentThread().getName() +" : "+ i);
            try {
                Thread.sleep(1000); // pause for 5 milliseconds
            } catch(InterruptedException e) {
                System.out.println("Thread interrupted: "+ e.getMessage());
            }
        }
    }
}
public class CounterDemo {
    public static void main(String[] args) {
        String threadName="UserCounter"; 
        int lrange=10;
        int urange=15;

        CounterThread counter=new CounterThread(threadName,lrange,urange);
        counter.start();
    }
} 