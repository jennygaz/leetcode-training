#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode( int x ) : val(x), next(nullptr) {}
  ListNode( int x, ListNode * next ) : val(x), next(next) {}
};

// O(n) time, O(n) space
ListNode * add_two_numbers( ListNode * l1, ListNode * l2 ){
  int carry = l1->val + l2->val;
  ListNode * head = new ListNode( carry % 10 ), * it = nullptr;
  l1 = l1->next;
  l2 = l2->next;
  it = head;
  carry /= 10;
  while( l1 and l2 ){
    carry = l1->val + l2->val + carry;
    it->next = new ListNode( carry % 10 );
    it = it->next;
    carry /= 10;
    l1 = l1->next;
    l2 = l2->next;
  }
  while( l1 ){
    carry = l1->val + carry;
    it->next = new ListNode( carry % 10 );
    it = it->next;
    carry /= 10;
    l1 = l1->next;
  }
  while( l2 ){
    carry = l2->val + carry;
    it->next = new ListNode( carry % 10 );
    it = it->next;
    carry /= 10;
    l2 = l2->next;
  }
  if( carry )
    it->next = new ListNode( carry );
  return head;
}