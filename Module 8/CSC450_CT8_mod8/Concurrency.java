/** 
 * This Java application demonstrates concurrency by utilizing two threads.
 * One thread counts up to 20, and another counts down from 20 to 0.
 * Both threads run concurrently without synchronization.
 */
import java.util.logging.Logger;

public class Concurrency {
    private static final Logger LOGGER = Logger.getLogger(Concurrency.class.getName());

    public static void main(String[] args) {
        // Create instances of both counter threads
        Thread counterUp = new Thread(new CounterUp());
        Thread counterDown = new Thread(new CounterDown());

        // Start both threads simultaneously
        counterUp.start();
        counterDown.start();
    }
}

/**
 * CounterUp implements Runnable to count from 0 to 20.
 */
class CounterUp implements Runnable {
    private static final Logger LOGGER = Logger.getLogger(CounterUp.class.getName());

    @Override
    public void run() {
        StringBuilder output = new StringBuilder();
        for (int i = 0; i <= 20; i++) {
            output.setLength(0); // Reset buffer
            output.append("Counter Up: ").append(i);
            LOGGER.info(output.toString());
            try {
                Thread.sleep(100); // Simulate processing delay
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                LOGGER.severe("CounterUp interrupted: " + e.getMessage());
            }
        }
    }
}

/**
 * CounterDown implements Runnable to count from 20 to 0.
 */
class CounterDown implements Runnable {
    private static final Logger LOGGER = Logger.getLogger(CounterDown.class.getName());

    @Override
    public void run() {
        StringBuilder output = new StringBuilder();
        for (int i = 20; i >= 0; i--) {
            output.setLength(0); // Reset buffer
            output.append("Counter Down: ").append(i);
            LOGGER.info(output.toString());
            try {
                Thread.sleep(100); // Simulate processing delay
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                LOGGER.severe("CounterDown interrupted: " + e.getMessage());
            }
        }
    }
}
