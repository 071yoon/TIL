package threadExample;

class WorkerThread extends Thread {
    private int from;
    private int to;
    private long sum;
    WorkerThread(int from, int to) {
        this.from = from;
        this.to = to;
        this.sum = 0;
    }
    public void run() {
        System.out.println("from" + from + "to" + to);
        for(int i = from; i <= to; i++) {
            sum += i;
        }
    }
    public long getSum() {
        System.out.println(sum);
        return sum;
    }
}

public class MyThread{
    public static void main(String[] args) {

        long beforeTime = System.nanoTime();
        long sum = 0;

        WorkerThread[] workerThreads = new WorkerThread[5];

        // counter logic
        int counter = 100000;
        // if 10
        // [1,2] [3,4] [5,6] [7,8] [9,10]

        // if 100,000
        // 100,000 / 5 -> 20,000
        // from [i * 20,000 + 1] ~ to [(i + 1) * 20,000]

        for(int i = 0; i < 5; i++) {
            workerThreads[i] = new WorkerThread((i * counter / 5) + 1, (i + 1) * counter / 5);
        }

        /** run threads in order
         *  waits for one thread after another
         * */
//        try {
//            for(int i = 0; i < workerThreads.length; i++) {
//                workerThreads[i].start();
//                workerThreads[i].join();
//                sum += workerThreads[i].getSum();
//            }
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }

        /** run threads in concurrent
         *  only waits to check if all 5 has ended
         * */

//        for(int i = 0; i < workerThreads.length; i++) {
//            workerThreads[i].start();
//        }
//        try {
//            for(int i = 0; i < workerThreads.length; i++) {
//                workerThreads[i].join();
//                sum += workerThreads[i].getSum();
//            }
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }


        /** run counter logic in single thread
         *  adds up directly to sum
         */

//        for(int i = 1; i <= counter; i++) {
//            sum += i;
//        }

        long afterTime= System.nanoTime();
        long secDiffTime = (afterTime - beforeTime);

        System.out.println("합계 : " + sum);
        System.out.println("걸린 시간 (nano second) : " + secDiffTime);
    }
}
