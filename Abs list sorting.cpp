#include <bits/stdc++.h>
using namespace std;
/*
The given list is sorted in ascending order based on the absolute values of its data.
So in the list, if a negative number x occurs after a negative number y it means x <= y.
And for the same reason if a positive number x occurs after a positive number y it means y <= x.
We will use this rule to modify the list. 
Whenever we encounter a negative number we will add that number to the front of the list and
whenever we encounter a positive number we will add that number to the end of the list.
Step 1: Create two node pointers, prev and curr. prev is pointing to the head and
curr is pointing to the 2nd node.
Step 2: Run a loop until curr become null.
inside the loop
  step 3: if curr’s data is less than prev’s data 
    follow this steps
       Step 4: connect prev->next with curr->next
       Step 5: connect curr->next with head
       Step 6: update curr=prev
    else
       Step 7: update prev=curr
  Step 8: move curr = curr->next
loop end */

struct Node
{
	Node* next;
	int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
	Node* newNode = new Node;
	newNode->next = (*head);
	newNode->data = data;
	(*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
	while (head != NULL)
	{
		cout << head->data;
		if (head->next != NULL)
			cout << " ";
		head = head->next;
	}
	cout << endl;
}


/*Your method shouldn't print anything
 it should transform the passed linked list */
// To sort a linked list by actual values.
// The list is assumed to be sorted by absolute
// values.
class Solution
{
public:
    Node* sortList(Node* head)
    {
        // Initialize previous and current nodes
        Node* prev = head;
        Node* curr = head->next;

        // Traverse list
        while (curr != NULL)
        {
            // If curr is smaller than prev, then
            // it must be moved to head
            if (curr->data < prev->data)
            {
                // Detach curr from linked list
                prev->next = curr->next;

                // Move current node to beginning
                curr->next = head;
                head = curr;

                // Update current
                curr = prev;
            }

            // Nothing to do if current element
            // is at right place
            else
                prev = curr;

            // Move current
            curr = curr->next;
        }
        
        return head;
    }
};

int main()
{

	int t = 0;
	int n = 0;
	cin >> t;
	while (t--)
	{
		Node* head = NULL;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			// push(&head, a);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			push(&head, arr[i]);
		}
		// printList(head);
		
		Solution ob;
		head=ob.sortList(head);

		printList(head);

	}
	return 0;
}
