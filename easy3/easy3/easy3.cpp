#include <iostream>
#include <future>
#include <chrono>
#include <thread>

std::future<void> sleep(int millis) {
    return std::async(std::launch::async, [millis] {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
        });
}

int main() {
    int millis = 1000;
    auto t = std::chrono::steady_clock::now();
    sleep(millis).get();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t).count();
    std::cout << "Elapsed time: " << duration << "ms" << std::endl;

    return 0;
}
