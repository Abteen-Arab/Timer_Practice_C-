#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

int main()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int hour = now->tm_hour;
    int minute = now->tm_min;

    while (hour !=14)
    {
        std::this_thread::sleep_for(std::chrono::seconds(60));
        t = std::time(nullptr);
        now = std::localtime(&t);
        hour = now->tm_hour;
        minute = now->tm_min;
    }

    std::cout << "Good morning!" << std::endl;

    return 0;
}
