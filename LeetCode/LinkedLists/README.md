# EASY
## Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

![merge](images/merge_ex1.jpg)


* Input: list1 = [1,2,4], list2 = [1,3,4]
* Output: [1,1,2,3,4,4]

Example 2:

* Input: list1 = [], list2 = []
* Output: []

Example 3:

* Input: list1 = [], list2 = [0]
* Output: [0]

## Middle Of Linked List
Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Example 1:

![mid1](images/lc-midlist1.jpg)

* Input: head = [1,2,3,4,5]
* Output: [3,4,5]
* Explanation: The middle node of the list is node 3.

Example 2:

![mid2](images/lc-midlist2.jpg)

* Input: head = [1,2,3,4,5,6]
* Output: [4,5,6]
* Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

##  Reverse Linked List 

Example 1:

![rev1](images/rev1ex1.jpg)

* Input: head = [1,2,3,4,5]
* Output: [5,4,3,2,1]

Example 2:

![rev1](images/rev2ex2.jpg)

* Input: head = [1,2]
* Output: [2,1]

Example 3:

* Input: head = []
* Output: []
##

# MEDIUM

##  Reverse Linked List II 

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

![rev2](images/rev2ex2.jpg)

* Input: head = [1,2,3,4,5],  left = 2, right = 4
* Output: [1,4,3,2,5]

Example 2:

* Input: head = [5], left = 1, right = 1
* Output: [5]
 
## Add Two Numbers 

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

![twoNums](images/addtwonumber1.jpg)

* Input: l1 = [2,4,3], l2 = [5,6,4]
* Output: [7,0,8]
* Explanation: 342 + 465 = 807

Example 2:

* Input: l1 = [0], l2 = [0]
* Output: [0]

Example 3:

* Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
* Output: [8,9,9,9,0,0,0,1]
