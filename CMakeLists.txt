cmake_minimum_required(VERSION 3.27)
project(CSS43_CPU_Scheduler)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSS43_CPU_Scheduler driver.c list.c CPU.c
               schedule_fcfs.c schedule_sjf.c schedule_priority.c schedule_rr.c
               schedule_priority_rr.c)

