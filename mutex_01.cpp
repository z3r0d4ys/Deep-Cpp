/**
 * @file mutex_01.cpp
 *
 * @brief This example shows how to implement mutexes.
 *
 * @authors Muhammed Baki ALMACI
 *
 * @date:27/10/2021
 */

#include <iostream>
#include <map>
#include <string>

#include <osal_mutex.hpp>
#include <osal_thread.hpp>
#include <osal_timer.hpp>

std::map<std::string, std::string>  baykar_data;
osal::mutex                         baykar_mutex;

void write_data(const std::string &url, const std::string &data)
{
    // simulate a long process.
    std::cout << "A thread ready to operate critical section! \n";
    osal::this_thread::sleep_for(osal::timer::seconds(2));

    /**
     * Mutex locked in following line. Mutex will automatically released when this scope end.
     * So, we locked our critical process from other accesses.
     */
    osal::lock_guard<osal::mutex> guard(baykar_mutex);
    baykar_data[url] = data;
} // mutex released automatically.

int main()
{
    osal::thread t1(write_data, "GITHUB web page: ", "github.com");
    osal::thread t2(write_data, "GITHUB location: ", "USA");

    t1.join(); // wait until t1 thread is over.
    t2.join(); // wait until t1 & t2 threads are over.

    // safe to access baykar_data without lock now, as the threads are joined
    for (const auto &pair : baykar_data) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}
