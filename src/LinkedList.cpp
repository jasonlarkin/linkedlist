#include <iostream>
using namespace std;


class LinkedList{

  struct Node {
    int x;
    Node *next; 
  };

public: 
  LinkedList(){
    head=NULL;
  }

  void addValue(int value){
    Node *node = new Node();
    node->x = value;
    node->next = head;
    head = node; 
  }

  int popValue(){
    Node *node = head;
    int ret = node->x;

    head = head->next;
    delete node;
    return ret;
  }

private:
  Node *head;

};


int main() {

  LinkedList list;

  list.addValue(5);
  list.addValue(10);
  list.addValue(20);

  cout << list.popValue() << endl;
  cout << list.popValue() << endl;
  cout << list.popValue() << endl;

  return 0;

}
