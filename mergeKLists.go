package main

import (
	"fmt"
	"sort"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}

	result := &ListNode{}
	head := result
	for len(lists) > 0 {
		sort.Slice(lists, func(i, j int) bool {
			if lists[i] == nil {
				return false
			}
			if lists[j] == nil {
				return true
			}
			return lists[i].Val < lists[j].Val
		})
		result.Val = lists[0].Val
		if lists[0] != nil {
			if lists[0].Next != nil {
				lists[0] = lists[0].Next
			} else {
				lists = append(lists[:0], lists[1:]...)
			}
		}

		result.Next = &ListNode{}
		if len(lists) > 0 {
			result = result.Next
		}
	}
	result.Next = nil
	result = nil

	return head
}

func main() {
	data := []*ListNode{}
	list1_2 := &ListNode{
		Val:  53,
		Next: nil,
	}
	list1_1 := &ListNode{
		Val:  22,
		Next: list1_2,
	}
	//
	list2_2 := &ListNode{
		Val:  30,
		Next: nil,
	}
	list2_1 := &ListNode{
		Val:  20,
		Next: list2_2,
	}
	//
	list3_2 := &ListNode{
		Val:  9,
		Next: nil,
	}
	list3_1 := &ListNode{
		Val:  4,
		Next: list3_2,
	}
	data = append(data, list1_1, list2_1, list3_1)
	result := mergeKLists(data)
	for result != nil {
		fmt.Printf("%d  ", result.Val)
		result = result.Next
	}

}
