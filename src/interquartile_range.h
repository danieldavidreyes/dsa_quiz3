#include <iostream>
#include <iomanip>

// Peter Yungman was my partner

class Node {
    public:
        float value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

float interQuartile(Node* head)
{
  Node* p1 = head;
  Node* p3 = head->next->next;
  Node* p4 = head->next->next->next;
  while (p4 && p4->next && p4->next->next && p4->next->next->next && p4->next->next->next->next){
    p1 = p1->next;
    p3 = p3->next->next->next;
    p4 = p4->next->next->next->next;
  }
  int count = 0;
  while(p4->next!=nullptr){
    count++;
    p4=p4->next;
  }
  if (count == 0){ // TYPE 1
    float q1 = (p1->value+p1->next->value)/2;
    float q3 = (p3->value+p3->next->value)/2;
    return q3-q1;
  }
  if (count == 1){
    float q1 = (p1->value+p1->next->value)/2;
    float q3 = (p3->next->value+p3->next->next->value)/2;
    return q3-q1;
  }
  if (count == 2){
    float q1 = (p1->next->value);
    float q3 = (p3->next->next->value);
    return q3-q1;
  }
  if (count == 3){
     float q1 = (p1->next->value);
    float q3 = (p3->next->next->next->value);
    return q3-q1;
  }
    
    return 0.0;   
}