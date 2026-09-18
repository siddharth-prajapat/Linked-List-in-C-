TWEET MANAGER SYSTEM

README / PROJECT DOCUMENTATION

C++ Data Structures Project

1. Project Information

Project Name

Tweet Manager System

Language

C++

Data Structures

Singly Linked List & Doubly Linked List

Project Type

BCA Data Structures Project

Institution

Dezyne É-COLE College

Authors

Pradeep Jatav & Gopal Prajapat

Date

16-05-2026

2. Project Overview

Tweet Manager System is a menu-driven C++ program that demonstrates the implementation of both Singly Linked List (SLL) and Doubly Linked List (DLL) through a practical tweet management application. Each tweet stores a Tweet ID, username and tweet content. The project focuses on dynamic memory management and linked-list operations.

3. Objectives

Understand the working of Singly and Doubly Linked Lists.

Implement dynamic memory allocation and deallocation.

Perform insertion and deletion at different positions.

Traverse linked-list nodes and display tweet information.

Search tweets using a username.

Count the total number of tweets/nodes.

Understand the difference between SLL and DLL operations.

4. Features

4.1 Singly Linked List

Insert at Beginning

Insert at End

Insert at Given Position

Display / Forward Traversal

Delete from Beginning

Delete from End

Delete from Given Position

Search Tweet by Username

Count Nodes

4.2 Doubly Linked List

Insert at Beginning

Insert at End

Insert at Given Position

Forward Traversal

Backward Traversal

Delete from Beginning

Delete from End

Delete from Given Position

Search Tweet by Username

Count Nodes

5. Tweet Data Structure

Each tweet contains the following information:

Tweet ID (automatically generated)

Username

Tweet Content

Example: TWEET1001 | Siddharth | Learning Data Structures!

6. Data Structure Design

6.1 Singly Linked List

Each node contains tweet data and a NEXT pointer:

HEAD → [ID | Username | Tweet | NEXT] → [ID | Username | Tweet | NEXT] → NULL

6.2 Doubly Linked List

Each node contains tweet data plus PREV and NEXT pointers:

NULL ←→ [PREV | ID | Username | Tweet | NEXT] ←→ [PREV | ID | Username | Tweet | NEXT] ←→ NULL

7. Project Structure

Tweet-Manager-System/
│
├── TweetManager.cpp
└── README.md

8. Technologies and Libraries

C++

Object-Oriented Programming

Pointers

Dynamic Memory Allocation

Singly Linked List

Doubly Linked List

iostream

string

conio.h

9. Main Menu

At startup, the program asks the user to select the required data structure:

1. Singly Linked List

2. Doubly Linked List

3. Exit

10. Time Complexity

Operation

Singly LL

Doubly LL

Insert at Beginning

O(1)

O(1)

Insert at End

O(1)

O(1)

Insert at Position

O(n)

O(n)

Delete Beginning

O(1)

O(1)

Delete End

O(n)

O(1)

Delete at Position

O(n)

O(n)

Traversal

O(n)

O(n)

Search by Username

O(n)

O(n)

Count Nodes

O(1)*

O(1)*

* The program maintains a countNode variable, allowing the current node count to be displayed directly.

11. SLL vs DLL

Feature

Singly Linked List

Doubly Linked List

Next Pointer

Yes

Yes

Previous Pointer

No

Yes

Forward Traversal

Yes

Yes

Backward Traversal

No

Yes

Delete from End

O(n)

O(1)

Memory Usage

Lower

Higher

Pointer Management

Simpler

More complex

12. Dynamic Memory Management

Nodes are dynamically created using new and released using delete. This allows the linked lists to grow and shrink during program execution.

13. Search Function

The program searches the linked list for tweets belonging to a given username. It traverses the list and displays every matching tweet, along with the total number of matches.

14. Learning Outcomes

Understanding linked-list node creation and linking.

Using pointers for dynamic data structures.

Implementing insertion and deletion algorithms.

Understanding forward and backward traversal.

Comparing Singly and Doubly Linked Lists.

Understanding basic time complexity of linked-list operations.

15. How to Compile and Run

Windows / Dev-C++:

Open the .cpp source file in Dev-C++ or another compatible C++ IDE.

Compile the program.

Run the executable.

Choose Singly Linked List or Doubly Linked List from the main menu.

Using MinGW / g++:

g++ TweetManager.cpp -o TweetManager.exe
TweetManager.exe

16. Notes

The program uses getch() from conio.h for instant menu selection.

conio.h is Windows-oriented and may not be available in all compilers.

The program uses system("cls") to clear the Windows console.

The project is intended for educational and Data Structures purposes.

17. Authors

Pradeep Jatav & Gopal Prajapat

Dezyne É-COLE College

Tweet Manager System — Project Documentation
