Merge Two Sorted Linked List


Given two sorted linked lists, merge them inplace to produce a singular sorted linked list.

Example:

A: 2→3→7

B: 1→4→5

Resultant list, after merging A and B:

C: 1→2→3→4→5→7

Testing
Input 
The first line contains ‘T’ denoting the no of independent test cases.

For each test case the input has three lines:

Two space-separated intergers ‘n’ and ‘m’ denoting the size of the first list and second list respectively.
n space-separated integers denoting the elements of first list.
m space-separated integers denoting the elements of second list.
Output
For each test case, a line containing n+m space-separated integers denoting the elements of merged linked list.

Sample Input 
2
3 4
1 2 3
2 2 4 5
3 3
2 3 3
1 4 5
Expected output 
1 2 2 2 3 4 5
1 2 3 3 4 5