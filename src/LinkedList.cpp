#include <iostream>
using namespace std;


class LinkedList{

  struct Node {
    int val;
    Node *next; 
  };

public: 
  LinkedList(){
    head = NULL;
    cur = NULL;
  }

  void addValue(int value){
    Node *node = new Node();
    node->val = value;
    node->next = head;
    head = node; 

    if( cur == NULL )
      cur = head;

  }

  void rewind(){
    cur = head;
  }

  void next(){
    if( cur != NULL )
      cur = cur->next;
  }

  int getValue(){
    if ( cur != NULL)
      return cur->val;
    return 0; //FIXME:exception
  }

  int hasValue(){
    return ( cur != NULL ? true : false );
  }

  int popValue(){
    Node *node = head;
    int ret = node->val;

    head = head->next;
    delete node;
    return ret;
  }

private:
  Node *head;
  Node *cur;

};


int main() {

  LinkedList list;

  list.addValue(5);
  list.addValue(10);
  list.addValue(20);

  cout << "rewind list" << endl;
  list.rewind();

  while( list.hasValue()){
      cout << "value = " << list.getValue() << endl;
      list.next();
  }

  cout << "rewind list" << endl;
  list.rewind();

  cout << "value = " << list.popValue() << endl;
  cout << "value = " << list.popValue() << endl;
  cout << "value = " << list.popValue() << endl;

  cout << "rewind list" << endl;
  list.rewind();

  while( list.hasValue()){
      cout << "value = " << list.getValue() << endl;
      list.next();
  }

  return 0;

}
