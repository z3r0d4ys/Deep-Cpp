/**
 * @file event_flag_02.cpp
 *
 * @brief This example shows how to implement atomic variables.
 *
 * @authors Muhammed Baki ALMACI
 *
 * @date:09/01/2021
 */

#include <iostream>
#include <osal_thread.hpp>
#include <osal_event_flag.hpp>

int main()
{
    std::atomic <int> a = 0; // It is guaranteed to write "200,000" on the screen.
//    int a = 0;             // Undefined behaviour.

    osal::thread writeThread( [&] () {
                                 for(int i = 0; i < 100000; i++) {
                                     a++;
                                 }
                             }
    );

    osal::thread readThread( [&] () {
                                for(int i = 0; i < 100000; i++) {
                                    a++;
                                }
                            }
    );

    writeThread.join();
    readThread.join();

    std::cout << a << std::endl;
}
