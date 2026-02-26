class SharedResource {
    synchronized void printTable(int number) {
        for(int i=1;i<=5;i++) {
            System.out.println(Thread.currentThread().getName() +" : "+ (number*i));
            try {
                Thread.sleep(500); 
            } catch(InterruptedException e) {
                System.out.println("Thread interrupted: "+ e.getMessage());
            }
        }
    }
}
class WorkerThread extends Thread {
    SharedResource resource;
    int number;

    public WorkerThread(SharedResource res,int num,String name) {
        super(name);
        resource=res;
        number=num;
    }

    public void run() {
        resource.printTable(number);
    }
}
public class SyncDemo {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        WorkerThread t1=new WorkerThread(resource, 5, "Thread-1");
        WorkerThread t2=new WorkerThread(resource, 10, "Thread-2");

        t1.start();
        t2.start();
    }
}
