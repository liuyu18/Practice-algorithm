cmake_minimum_required(VERSION 3.1.1)
project(palindromeList)
set(SRC_LIST  LinkedList.c ListNode.h palindromeList.c)
add_executable(palindromeList ${SRC_LIST})