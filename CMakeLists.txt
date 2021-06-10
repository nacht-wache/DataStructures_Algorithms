cmake_minimum_required(VERSION 3.5)

project(DS)

include_directories(
    Stack/ListBased_Template
    Stack/ArrayBased_Template
    Stack/ArrayBased_nonTemplate
    Queue/
    List/SinglyLinkedList_nonTemplate
    List/SinglyLinkedList_nonTemplate/lib
)

set(SinglyLinkedList_nonTemplate
    ${SinglyLinkedList_nonTemplate}
    ${CMAKE_CURRENT_SOURCE_DIR}/List/SinglyLinkedList_nonTemplate/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/List/SinglyLinkedList_nonTemplate/lib/member_functions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/List/SinglyLinkedList_nonTemplate/lib/member_functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/List/SinglyLinkedList_nonTemplate/lib/constructors.cpp
    )

set(QUEUE
    ${QUEUE}
    ${CMAKE_CURRENT_SOURCE_DIR}/Queue/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Queue/Queue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Queue/Queue.h
    )

set(Stack_ListBased_Template
    ${Stack_ListBased_Template}
    Stack/ListBased_Template/main.cpp
    Stack/ListBased_Template/ListBased_T.h
    )

set(StackArrayBased_Template
    ${StackArrayBased_Template}
    Stack/ArrayBased_Template/ArrayBased_T.h
    Stack/ArrayBased_Template/main.cpp
    )

set(StackArrayBased_nonTemplate
    ${StackArrayBased_nonTemplate}
    Stack/ArrayBased_nonTemplate/ArrayBased.h
    Stack/ArrayBased_nonTemplate/ArrayBased.cpp
    Stack/ArrayBased_nonTemplate/main.cpp
    )


add_executable(${PROJECT_NAME} ${SinglyLinkedList_nonTemplate})

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CMAKE_CXX_FLAGS "-Wall -Wextra"
)
