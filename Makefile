MergeSortedLinkedList: MergeSortedLinkedList.o
	g++ -g -o MergeSortedLinkedList.exe MergeSortedLinkedList.o -pthread    

MergeSortedLinkedList.o: MergeSortedLinkedList/MergeSortedLinkedList.cpp
	g++ -g  -c -pthread MergeSortedLinkedList/MergeSortedLinkedList.cpp
