# Data-Structure-Programming-Practice

🤓 two scenarios for applying the basic knowledge of data structure

# Environment Setup

The experiments are implemented in **C language** using **Microsoft Visual Studio 2010 (VC2010)**. 

Make sure your system has the required C/C++ compilers configured for the environment.💻

# Application of Linear Linked List

📖 **the management program of bibliography lists**

_The specific requirements are as follows:_
	
 1️⃣ Read all recommended book details (ID, title, author, publisher, and publication year) from a .csv file and create a linked list.
 
 2️⃣ Prompt the user to input an operation choice:
 
a) Input 1: Add a new book and its details (create a new book node).

b) Input 2: Delete a book by its ID (remove the corresponding node). Display a prompt if the ID doesn’t exist.

c) Input 3: Modify the details of a book by its ID (update the existing node). Display a prompt if the ID doesn’t exist.

d) Input 4: Display the most recently published book(s) and their details (consider handling ties in the publication year).

e) Input 0: Free the linked list memory and exit the program (consider saving changes if possible).
# Binary Tree Traversal and Huffman Tree Application

💼 **the “evaluation tree” program helps HR departments classify employee performance**

🧑‍💼 _Background_

The “evaluation tree” program helps HR departments classify employee performance:

if (a < 60) b = "keep trying";  
else if (a < 70) b = "pass";  
else if (a < 80) b = "general";  
else if (a < 90) b = "good";  
else b = "excellent";

However, the distribution of performance levels is uneven in practice (see table below). This suggests the program can be further optimized using a Huffman tree.

Employee Distribution by Score Range:

| Score Range   | [0, 60) | [60, 70) | [70, 80) | [80, 90) | [90, 100] |
|---------------|---------|----------|----------|----------|-----------|
| Proportion    | 0.05    | 0.15     | 0.40     | 0.30     | 0.10      |


_The specific requirements are as follows:_

1️⃣ Construct a Huffman tree based on the proportions of the score ranges, treating them as node weights.

2️⃣ Traverse the Huffman tree built in step (1) and output the traversal result.
