//Ashley Maddix, CS 163, Prog 2, Spring 2018

//main.cpp
//menu
//receiving

//stack.cpp
//constuctor
//destuctor
//push
//save_in
//pop
//peek
//display

//queue.cpp
//constructor
//destuctor
//enqueue
//save_out
//save_message 
//dequeue
//peek
//display

#include"prog1.h"

//constuctor for the class of messages received ( for our stack)
//funciton to initialize the data in this class
received_message::received_message()
{
	stack_head=NULL;
	stack_index=0;
}

//Destructor for the class of messages recived (for our stack)
//function to deallocate the data in this call
received_message::~received_message()
{	
	//if head is NOT nULL
	if ( stack_head!=NULL)
	{
		//traverse through head...
		s_node * current = stack_head;
		while (current != NULL)
		{
			//delete everything in list
			clear_index();
			//then delete list array
			delete current->list;
			// traverese
			current=current->next;
		}
		//delete head node
		delete stack_head;
		//set head to NULL
		stack_head=NULL;
	}
	//setn index to 0
	stack_index= 0;

}

//funciton to save the message information read in from user 
// (though 'sent_in') into the front our our stack
int received_message::push(message sent_in)
{
	//if there is nothing in our stack yet
	if (!stack_head)
	{
		// create a temp pointer fro s_node
		s_node * temp = new s_node;
		stack_head=temp; //set stack_head to be temp
		stack_head->next=NULL; // set it's next to be NULL
		stack_head->list= new message[MAX]; 
		//dynamicall allocate an array of messages (list)
		// of size MAX

		//call the function 'save_in' to save all the members 
		//of ...........'sent_in'
		save_in(sent_in);
	}
	
	//if there already a node and the index is not at the end of 
	// the array then save information from sent_in
	else if (stack_head && stack_index < MAX)
		save_in(sent_in);

	//if the index is at the end of array
	else if (stack_index = MAX)
	{
		// set index = to 0
		stack_index=0;
		// create temp variable and set next
		// to head
		s_node * temp= new s_node;
		temp->next=stack_head;
		//set head to temp
		stack_head= temp;
		// create a new array for stack list
		stack_head->list= new message[MAX];

		//call function to save data
		save_in(sent_in);
	}

	else
		return 0;


	++stack_index;
	return 1;
}

// function to save information from sent in into the
// current index of the heads array
int received_message::save_in(message & sent_in)
{

	if (sent_in.name)
	{
	stack_head->list[stack_index].name=sent_in.name;

	stack_head->list[stack_index].number=sent_in.number;

	stack_head->list[stack_index].email=sent_in.email;

	stack_head->list[stack_index].nick=sent_in.nick;
	
	stack_head->list[stack_index].blocked=sent_in.blocked;

	stack_head->list[stack_index].secret=sent_in.secret;

	stack_head->list[stack_index].date=sent_in.date;

	stack_head->list[stack_index].time=sent_in.time;

	stack_head->list[stack_index].subject=sent_in.subject;

	stack_head->list[stack_index].body=sent_in.body;
	return 1;
	}

	return 0;
}

//function to delete the most recent message from the stack
int received_message:: pop ()
{
	//if we dont have any messages yet, do nothing
	if (!stack_head)
		return 0;

	//set stack index to the previous index
	--stack_index;

	//if this is the last node in list, and were at the
	//last index..
	if (stack_head->next==NULL && stack_index==0)
	{
		//create a temp var to heads next
		s_node * temp=stack_head->next;
		//call function to clear everything in index
		clear_index();
		//delete the array and set head = to temp
		delete stack_head->list;
		stack_head=temp;
	}

	// if we are just at the last index of an array (but not 
	// the last node	
	 else if (stack_index==0)
	   {
		//create a temp var to head
		s_node * temp=stack_head;
		//call function to clear everything in the current 
		//arrays index
		clear_index();
		//delete stack_heads array
		delete stack_head->list;
		//set stack head to temps next
		stack_head=temp->next;
		//delete temp
		delete temp;
		//set stack index to the last index
		stack_index=MAX-1;
	   }

	//if we're in the middle of an array
	else
	{
		//clear current index of array
		clear_index();
		//set index to previous index
		--stack_index;
	}

	//increase index for 'push' 
	++stack_index;
	return 1;
}

// function to clear each member of the array of the current head
int received_message::clear_index()
{
		stack_head->list[stack_index].name=NULL;
		stack_head->list[stack_index].number=NULL;
		stack_head->list[stack_index].email=NULL;
		stack_head->list[stack_index].nick=NULL;

		stack_head->list[stack_index].blocked=0;
		stack_head->list[stack_index].secret=0;

		stack_head->list[stack_index].date=NULL;
		stack_head->list[stack_index].time=NULL;
		stack_head->list[stack_index].subject=NULL;
		stack_head->list[stack_index].body=NULL;
}
	
// function to look at the most recent message sent to the user
int received_message:: peek (message & peeked)
{
	//set index to previous index
	--stack_index;

	//if we have a head
	if (stack_head)
	{ 

		peeked.name=stack_head->list[stack_index].name;

		peeked.number=stack_head->list[stack_index].number;

		peeked.email=stack_head->list[stack_index].email;

		peeked.nick=stack_head->list[stack_index].nick;
	
		peeked.blocked=stack_head->list[stack_index].blocked;

		peeked.secret=stack_head->list[stack_index].secret;

		peeked.date=stack_head->list[stack_index].date;

		peeked.time=stack_head->list[stack_index].time;

		peeked.subject=stack_head->list[stack_index].subject;

		peeked.body=stack_head->list[stack_index].body;

		//increase index for push
		++stack_index;

		return 1;
	}

	return 0;
}

//function to display the information from the most recently recived message
int received_message:: display()
{
	--stack_index;

	//if we have any info in out stack
	if(stack_head)
	{

		cout<<"information about most recently received message"<<endl<<endl
		<<"Message recieved from :"<<endl;
		if (stack_head->list[stack_index].blocked)
			cout<<"(blocked user)"<<endl;

		cout<<stack_head->list[stack_index].name<<endl
			<<stack_head->list[stack_index].number<<endl
			<<stack_head->list[stack_index].email<<endl
			<<stack_head->list[stack_index].nick<<endl
			<<"Date, time :"<<endl
			<<stack_head->list[stack_index].date<<endl
			<<stack_head->list[stack_index].time<<endl
			<<"Message :"<<endl
			<<stack_head->list[stack_index].subject<<endl
			<<stack_head->list[stack_index].body<<endl;

		if (stack_head->list[stack_index].secret)
			cout<<" *** This is a secret conversation ***"<<endl;

		++stack_index;
		return 1;
	}
	return 0;
}
