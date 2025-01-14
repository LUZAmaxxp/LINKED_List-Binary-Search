# Linked List with Reversal and Binary Search in C

This project implements a **linked list** in the C programming language that provides the following functionality:

1. Create a linked list with user-defined nodes.
2. Optionally reverse the linked list.
3. Perform a binary search on the linked list to find a specified value.

## Features
- **Dynamic Node Creation**: Users can specify the number of nodes and their values.
- **Reversal of Linked List**: Users can reverse the linked list if desired.
- **Binary Search Simulation**: Since binary search typically works on arrays, this project simulates binary search by dividing linked list traversal.

## Usage Instructions
### Compilation
Use `gcc` to compile the code:
```bash
gcc linked_list_binary_search.c -o linkedlist
```

### Running the Program
Run the compiled executable:
```bash
./linkedlist
```

### Example Output
#### Step 1: Creating a Linked List
```
Enter the number of nodes: 5
Enter 5 values:
10 20 30 40 50
Original Linked List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL
```
#### Step 2: Reversing the Linked List
```
Do you want to reverse the linked list? (1 for Yes, 0 for No): 1
Reversed Linked List:
50 -> 40 -> 30 -> 20 -> 10 -> NULL
```
#### Step 3: Searching for a Value
```
Enter the value to search for: 30
Value 30 found in the linked list.
```

## Code Structure
- **Node Definition**: A `struct Node` represents each node in the linked list.
- **Linked List Functions**:
  - `createLinkedList(int n)`: Dynamically creates a linked list with `n` nodes.
  - `displayLinkedList(struct Node* head)`: Displays the linked list.
  - `reverseLinkedList(struct Node* head)`: Reverses the linked list.
  - `binarySearchLinkedList(struct Node* head, int target)`: Searches for a target value in the linked list using simulated binary search logic.

## Example Diagram
### Linked List Representation
```plaintext
Head -> [10] -> [20] -> [30] -> [40] -> [50] -> NULL
```
### Reversed Linked List
```plaintext
Head -> [50] -> [40] -> [30] -> [20] -> [10] -> NULL
```

### Binary Search Simulation
1. `getMiddleNode` helps simulate splitting the linked list.
2. Adjusts `start` and `length` to traverse halves.

## Improvements
- **Sorting Before Binary Search**: Binary search assumes sorted data; you can add a sorting function.
- **Enhanced Search**: Explore indexing strategies for faster searches in linked lists.

## Conclusion
This project demonstrates dynamic data structure management, traversal algorithms, and interactive user input handling in C.
