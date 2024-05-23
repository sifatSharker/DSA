#include <iostream>
using namespace std;

class queue {
    int *arr;
    int front;
    int back;
    int size; // Added variable to store size of the queue
public:
    queue(int n) { // Modified constructor to accept size as parameter
        size = n;
        arr = new int[size];
        front = -1;
        back = -1;
    }

    void push(int x) {
        if (back == size - 1) { // Changed = to ==
            cout << "Overflow" << endl;
            return;
        }
        back++;
        arr[back] = x;
        if (front == -1) { // Changed = to ==
            front++;
        }
    }

    void pop() {
        if (front == -1 || front > back) {
            cout << "No elements" << endl; // Changed "end" to "endl"
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > back) {
            cout << "No elements" << endl; // Changed "end" to "endl"
            return -1;
        }
        return arr[front];
    }
    showqueue(){
      if (front == -1 || front > back) {
            cout << "No elements" << endl;
return -1;

    }
    cout<<"elements are "<<endl;
    for(int i=front;i<=back;i++){
        cout<<arr[i]<<endl;
    }
cout<<endl;}
};

int main() {
    int n, x;
    cout << "Enter the size of the queue: ";
    cin >> n;
    queue q(n); // Modified to pass size to the constructor
    cout << "Enter elements to push into the queue:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q.push(x);
    }


    cout << "Peek of the queue: " << q.peek() << endl;
    q.showqueue();



}
