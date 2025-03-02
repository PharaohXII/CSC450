/**
 * @file concurrency_threads.cpp
 * @brief Demonstrates concurrency using two threads.
 *
 * This program creates two threads: one counting up to 20 and another counting down to 0.
 * A mutex is used to synchronize console output and prevent interleaving issues.
 *
 * @Tomas Toledo
 * @date 2025-03-02
 */

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; ///< Mutex to synchronize console output

/**
 * @brief Counts up from 1 to 20.
 *
 * This function prints numbers from 1 to 20, using a mutex to ensure
 * thread-safe console output.
 */
void countUp() {
    for (int i = 1; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Counting Up: " << i << std::endl;
    }
}

/**
 * @brief Counts down from 20 to 0.
 *
 * This function prints numbers from 20 down to 0, using a mutex to ensure
 * thread-safe console output.
 */
void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Counting Down: " << i << std::endl;
    }
}

/**
 * @brief Main function that starts two threads for counting.
 *
 * This function creates and starts two threads: one for counting up and
 * another for counting down. The `join()` calls ensure that both threads
 * complete before the program exits.
 *
 * @return int Program exit status.
 */
int main() {
    std::thread t1(countUp);
    t1.join(); // Ensure t1 completes before starting t2

    std::thread t2(countDown);
    t2.join();

    return 0;
}
