# TreeSearch_Library
We did this as project in DSA course with team size five.


# Mini-Project-Team56
## TA incharge
* Arpan Dasgupta

## Team Members email

* dhruv.hirpara@students.iiit.ac.in (Dhruv) 
* pamulapati.pallavi@students.iiit.ac.in (Pallavi)
* josh.ujwal@students.iiit.ac.in (Ujwal)
* yadavalli.lakshmi@students.iiit.ac.in (Lakshmi)
* aasish.eswar@students.iiit.ac.in (Raj)
#happy coding...



## Compilation Instructions
### Steps for greedy search

1. node_comparator should look like this 
```C
bool node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
    return a->value > b->value; // A sample comparator
}
```
2. Write this command on terminal to compile
 ```bash
 gcc node.c priority_queue.c main.c  
 ```
3. To run the File
```bash
./a.out
```
4. Give the test-case of your choice

### Steps for BFS

1. node_comparator should look like this 
```C
bool node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
    return a->seen_time < b->seen_time; // A sample comparator
}
```
2. Write this command on terminal to compile
 ```bash
 gcc node.c priority_queue.c main.c  
 ```
3. To run the File
```bash
./a.out
```
4. Give the test-case of your choice

### Steps for DFS

1. node_comparator should look like this 
```C
bool node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
    return a->seen_time > b->seen_time; // A sample comparator
}
```
2. Write this command on terminal to compile
 ```bash
 gcc node.c priority_queue.c main.c  
 ```
3. To run the File
```bash
./a.out
```
4. Give the test-case of your choice
