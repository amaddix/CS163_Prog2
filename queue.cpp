
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

//constuctor for the messages were sending out. ( initiallizing
// the data)
replied_message::replied_message()
{
	queue_rear=NULL;
}

//destructor for the messages were sending out (will delete 
//all the messages.
replied_message::~replied_message()
{

	//if we have any messages in the queue
	if (queue_rear)
	{
		//create a temp pointer head to rear next (head)
		q_node * head=queue_rear->next;

		//set rear to next (turn from CLL -> LLL)
		queue_rear->next=NULL;
		//set rear to head.
		queue_rear=head;
		
		//while rear (head) is not null
		while (queue_rear)
		{
			//call function to clear eveything in list
			clear_reply();
			// if there are any responces, clear those too
			if (queue_rear->responce)
				clear_sent();
			//traverse head
			head=head->next;
		
			//delete the node at front
			delete queue_rear;	
			//set queue rear to next node
			queue_rear=head;
		}
		//set rear to NULL
		queue_rear=NULL;
	}
}

// function to save the message being sent out the the end of queue
int replied_message::enqueue(message sent_in, message peeked, bool a_responce)
{
	//if there is nothing in our list yet...
	if (!queue_rear)
	{
		//allocate memory for queue_rear
		queue_rear=new q_node;
		//if the message were sending out is a responce, then...
		if (a_responce)
		{
			//save that into the queue_rear information	
			queue_rear->responce=a_responce;
			// save the most recent message recived (as the message
			// they are responding to)
			save_message(peeked);
		}
		// save the information for the message being sent into the 
		// current node
		save_out(sent_in);	
		// set rears next to itself
		queue_rear->next=queue_rear;	
	}

	//if we already have information in the list
	else
	{
		// create a temp node 
		q_node * temp=new q_node;
		// set temps next as rears next (head)
		temp->next=queue_rear->next;
		//set rears next as temp (add after rear)
		queue_rear->next=temp;
		//change rear to be temp (the new rear)
		queue_rear=temp;
		//if were responding..
		if (a_responce)
		{
			queue_rear->responce=a_responce;
			//save message responding to 
			save_message(peeked);
		}
		//save infomation 
		save_out(sent_in);
	}

}

// function to save the information from sent_in into the 
// current rear
int replied_message::save_out(message & sent_in)
{
	//if this is a NOT a responce, then save the name
	// from sent in into reply
	if(!queue_rear->responce)
	{
		queue_rear->reply.name=sent_in.name;
		queue_rear->reply.number=sent_in.number;
		queue_rear->reply.email=sent_in.email;
		queue_rear->reply.nick=sent_in.nick;
	}
	// if they are responding then this info will be saved from the 
	// message they're replying to
	queue_rear->reply.date=sent_in.date;
	queue_rear->reply.time=sent_in.time;
	queue_rear->reply.subject=sent_in.subject;
	queue_rear->reply.body=sent_in.body;

	return 1;


}

//function to save the message being responded to ( if theyre 
// message is a responce
int replied_message::save_message(message & peeked)
{
	// save name info from message responding to into message sending
	// out
	queue_rear->reply.name=peeked.name;
	queue_rear->reply.number=peeked.number;
	queue_rear->reply.email=peeked.email;
	queue_rear->reply.nick=peeked.nick;

	//save information from message responding to 
	//as the information for massage responding to 
	queue_rear->sent.name=peeked.name;
	queue_rear->sent.number=peeked.number;
	queue_rear->sent.email=peeked.email;
	queue_rear->sent.nick=peeked.nick;
	queue_rear->sent.date=peeked.date;
	queue_rear->sent.time=peeked.time;
	queue_rear->sent.subject=peeked.subject;
	queue_rear->sent.body=peeked.body;

}

// function to 'send off' messages waiting to be sent (deletes 
// nodes from the front of list)
int replied_message::dequeue ()
{

	// if there is nothing in our list, do nothing...
	if (!queue_rear)
		return 0;

	// if queue _rear is pointin gto itself...
	else if (queue_rear->next== queue_rear)
	{
		// call function to clear the message being sent
		clear_reply();
		// if this is a repsonce, clear the responce too
		if (queue_rear->responce)
			clear_sent();

		//delete rear, set to null
		delete queue_rear;	
		queue_rear=NULL;
	}

	else
	{
		//have queue rear be node were deleting
		q_node * temp=queue_rear->next;
		//set rears next as temps next
		queue_rear->next=temp->next;
		clear_reply();
		if (temp->responce)
			clear_sent();
		//delete temp
		delete temp;
	}
	return 1;
}

//dunction to clear all the members of the messages being sent out
int replied_message::clear_reply()
{
	queue_rear->reply.name=NULL;
	queue_rear->reply.number=NULL;
	queue_rear->reply.email=NULL;
	queue_rear->reply.nick=NULL;
	queue_rear->reply.date=NULL;
	queue_rear->reply.time=NULL;
	queue_rear->reply.subject=NULL;
	queue_rear->reply.body=NULL;
}

//function to clear all the members of the message being responded to
int replied_message::clear_sent()
{
	queue_rear->sent.name=NULL;
	queue_rear->sent.number=NULL;
	queue_rear->sent.email=NULL;
	queue_rear->sent.nick=NULL;
	queue_rear->sent.date=NULL;
	queue_rear->sent.time=NULL;
	queue_rear->sent.subject=NULL;
	queue_rear->sent.body=NULL;
}

//function to save the information of the message at the front of list
// into the variable peeked for client to use
int replied_message::peek ( message & peeked)
{
	if (queue_rear)
	{
		peeked.name=queue_rear->next->reply.name;
		peeked.number=queue_rear->next->reply.number;
		peeked.email=queue_rear->next->reply.email;
		peeked.nick=queue_rear->next->reply.nick;
		peeked.date=queue_rear->next->reply.date;
		peeked.time=queue_rear->next->reply.time;
		peeked.subject=queue_rear->next->reply.subject;
		peeked.body=queue_rear->next->reply.body;
		return 1;
	}

	return 0;
}

// function to display all the information from the message at the 
// front of the queue to user
int replied_message::display()
{
	if(queue_rear)
	{

		cout<<"Your message sext to :    "<<endl
			<<queue_rear->next->reply.name<<endl
			<<queue_rear->next->reply.number<<endl
			<<queue_rear->next->reply.email<<endl
			<<queue_rear->next->reply.nick<<endl
			<<"Date, time :"<<endl
			<<queue_rear->next->reply.date<<endl
			<<queue_rear->next->reply.time<<endl
			<<"Message  :"<<endl
			<<queue_rear->next->reply.subject<<endl
			<<queue_rear->next->reply.body<<endl;
	//if this message is a responce to a message, dsplay the message
	// being responded to too
		if(queue_rear->responce)
		{
			cout<<"Responce to message sent from :     "<<endl
				<<queue_rear->sent.name<<endl
				<<queue_rear->sent.number<<endl
				<<queue_rear->sent.email<<endl
				<<queue_rear->sent.nick<<endl
				<<"Date, time :"<<endl
				<<queue_rear->sent.date<<endl
				<<queue_rear->sent.time<<endl
				<<"Message :"<<endl
				<<queue_rear->sent.subject<<endl
				<<queue_rear->sent.body<<endl;
		}
		return 1;
	}
	return 0;
}

// function to use as wrapper for recursive count
int replied_message::count()
{
	int amount=0; // variable for the amount of 
	// messages waiting to be sent out of my list
	
	// if there is nothing in the list, return 0
	if (!queue_rear)
		return 0;

	// if the rear is not pointing to itself ...
	else if (queue_rear->next!=queue_rear)
	{
		//create a pointer to the head
		q_node * head=queue_rear->next;
		// create a pointer to hold onto temp
		q_node * rear_temp=queue_rear;

		// set rears next to null (making this a LLL)
		queue_rear->next=NULL;
		// set rear to head
		queue_rear=head;

		//call recursive function to count amount of nodes
		// in queue, and save into var amount
		amount=count(queue_rear);
	
		// after counting, set rear back to the rear
		queue_rear=rear_temp;
		// set the rears next to the front again
		queue_rear->next=head;

		return amount;
	}

	return 1;

}

// recursive function to count the number of messages waiting to be sent out
int replied_message::count (q_node * queue_rear)
{
	int counter=0; // var to count the amount of nodes

	// if the rear is null (w're empty, or hav reached end of LLL)
	if (!queue_rear)
		return 0;

	// increase counter by 1 
	++counter;

	// call the function using rears next , and add the counter...	
	// return the value of the counter once we have reached end of list
	return count(queue_rear->next)+counter;
}


