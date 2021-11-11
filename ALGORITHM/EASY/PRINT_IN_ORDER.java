package ALGORITHM.EASY;

import java.util.concurrent.CountDownLatch;

public class PRINT_IN_ORDER{
    public static void main(String[] args) {
        try {
            CountDownLatch countDownLatch = new CountDownLatch(100);
            for (int i = 0; i < 100; i++) {
                new Thread(() -> {
                    System.out.println(Thread.currentThread().getName() + "正在运行");
                    countDownLatch.countDown();
                }).start();
            }
            System.out.println("完成");
            countDownLatch.await();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}