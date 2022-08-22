# CS163_Prog2
#Ashley Maddix
#Spring 2018


What functions your ADT will need to have
Stack-		This program will consist of two abstract data types. One being a stack with a linear linked list of arrays. This stack will require at least four functions.
Push
This function will test three cases. First whether head is NULL, meaning that the first node in our list has yet to be created. In this case it will allocate memory for the head node in the list. Then it will proceed to create a dynamically allocated array (probably of size 5), that the head node has a pointer pointing to. Once this has been done it will take the value passed in by the user (probably a struct), and add it to the first index of out array. After this the index of out array will be increased by one. 
For the second condition, it will be looking to see that head is NOT NULL and and the index is less than 5. If this condition is met, then we will just add the struct passed in by the user, into the current index of our array, in our current node. As we do this we will then add one to the index of our array. 
The last condition we will test for is if our index is greater or equal to 5. If this tests true, then we will, like the first condition, allocate memory for a new head. But while doing this we will make sure to attach our old head to our new heads next. Then we will dynamically allocate another array of size 5, that our head node is pointing to. Once our node and array are created we will add the struct passed in from user into the first index of our new array in our new node. 
Pop
If head is NULL, then this function will just return 0 (since there’d be nothing to delete). It will then test if the index is greater than 0, and if it is then it will set the index of head’s array [index] to ‘\0’, then we will decrease index by one. Otherwise (the index is less then 0) we will delete head’s array. Then we will save head in a temp pointer, and set temp’s next = to head. Then we will delete temp. 
Display
This function will be created recursively. I the base condition will be if head is NULL, then it will return 0. If it is not NULL, then it will output information stored in the array’s current index. Then it will have an else if condition to test if the index that will be passed in the function is less than 5 (or the MAX size of array). If it tests true then it will call the function, increasing the index size by one. If it doesn't test true for either of these then is will call the function with head’s next. 
Peek- This function will just look at head’s array[index] (as long as head is NOT NULL), and it will save the information from the struct saved at that index, into a struct passed into the function (so that that information can be passed back to the client program). 
Queue- 	This data structure will also have four similar functions to stack.
Enqueue
This function will first test that rear is not NULL. If it is NULL, then we will allocate memory for rear, then copy our data into rear. We will also set rears next to rear. If rear is NOT NULL, then we will  create a temp pointer and set its next to rear’s next, then add temp after rear, re-assign rear to temp.
Dequeue
This function will first check if rear is NULL. If it is, then we will just return 0. Otherwise, if rears next is rear, then we will just set rear to NULL. If rears next is NOT NULL, then we will save rears next in a temp pointer, and set rears next to temps next. Then we will delete temp.
Peek & display
The functions for peek and display for our queue will be fairly similar to the peek and display for out stack, with slight changes to match our different data types.

How each function will report success/failure back to the calling routine.
Each function will have options to return 0 or 1, depending on what conditions test true. The number returned to main will most likely be saved in an int variable ‘worked’. Some of these functions may report their value back to main by being called in an if statement.

How each function will shield the client program from the details of the data structure
For one, I will have a struct variable that I will use to read in information from the user/ read back to user, that will be passed to the majority of my functions (maybe apart from the display functions).

What data structures you will be using and how each of the special cases. Consider drawing pointer diagrams with “before” and “after” diagrams for each special case
One data structure I will be using is a LLL of arrays. (in question 1, I have specified what I shall be doing for the special cases)
Another datatype I will be using is  a CLL. ( again, the I specified the the special cases in question 1).


EFFICIENCY WRITE UP 

 How well did the data structure selected perform for the assigned application?
Using a linear linked list of arrays for the data type for my stack, I think was a good choice. Being a stack, I needed to be able to continuously add and remove data from the ‘front’ of my data. If I were to use regular linear linked list, there would be a lot of memory overhead, since for each node ( piece of memory) added to my list there is an extra pointer (to the next node). In addition, if my data type was just an array, this would impractical since we could run into the problem of having to shift our data. We would also be restricted the memory of how big we initially allocate our array. Saying this, I this I think that a linear linked list of arrays was a good choice, since we can continuously add on nodes, but our data is being stored in a small array, so we don't need to allocate as many nodes.
As for our queue, I think that a circular list makes sense. In our queue we want to be able to add to the ‘end’ and remove from the ‘front’. With a circular list, we can easily do this if we hold onto the rear of our list. We can easily add right after rear, and remove from rear’s next. If we were to use an array we would not be able to change the size of our array, so once we remove something from the top, we would need to shift. 
Would a different data structure work better? If so, which one and why…
I don't think it would necessarily be better, but for our queue we should be able to accomplish the same task with a linear linked list, as long as we have a pointer to the head AND rear. But since doing this would be doing close to the same, and it's not much more difficult to use a circular linked list, it makes more sense to use a circular linked list and save having to use and extra pointer.
What was efficient about your design and use of the data structure?
I think that I was able to make use of a lot of general functions. For example I created a function to save the information taken from the variable that was sent in from user, and save that into the current index of my stack heads list array. I also created two other functions like this for my queue, one to save information into the ‘reply’ message ( which was used for the message sent from user), and the ‘sent’ message  (which was usd for the message the user is replying too). I also created handy functions that once called, would clear all the members of the message at stack_heads arrays current index. Like the save function, I also made two similar functions for my queue, were I would delete all the members of queue_rear->next’s messages being sent out, and all the messages being replied too.
What was not efficient?
Im sure that there were a lot of small things in my code that could probably be re-written in a more efficient way. ……………
What would you do differently if you had more time to solve the problem
I did notice that a few functions that I created for my queue and stack were very similar ( in their goal and how they accomplished it). And I wonder if I would have been able to re-use some of them. However the fact that they are in two seperate classes, I’m not sure if that would have been possible.
