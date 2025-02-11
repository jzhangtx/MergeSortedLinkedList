package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (node *ListNode) Print() {
	if node == nil {
		fmt.Println("")
	}

	fmt.Print(node.data)
	node = node.next
	for node != nil {
		fmt.Printf(", %d", node.data)
		node = node.next
	}
	fmt.Println("")
}

func MergeTwoSortedList(firstList, secondList *ListNode) *ListNode {
	if firstList == nil {
		return secondList
	}
	if secondList == nil {
		return firstList
	}

	pHead := firstList
	if firstList.data >= secondList.data {
		pHead = secondList
		secondList = secondList.next
	} else {
		firstList = firstList.next
	}

	pCur := pHead

	for firstList != nil && secondList != nil {
		if firstList.data < secondList.data {
			pCur.next = firstList
			firstList = firstList.next
		} else {
			pCur.next = secondList
			secondList = secondList.next
		}
		pCur = pCur.next
	}

	if firstList != nil {
		pCur.next = firstList
	} else {
		pCur.next = secondList
	}

	return pHead
}

func main() {
	for {
		fmt.Print("Number elements in list1 and list2: ")
		var countA, countB int
		fmt.Scan(&countA, &countB)
		if countA == 0 && countB == 0 {
			break
		}

		vec := GetArrayFromInput(countA, "Please enter the nodes in list1: ")
		listA := GetListFromArray(vec)

		vec = GetArrayFromInput(countB, "Please enter the nodes in list2: ")
		listB := GetListFromArray(vec)

		pHead := MergeTwoSortedList(listA, listB)
		fmt.Print("The merged list: ")
		pHead.Print()
	}
}
