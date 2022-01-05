
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


#include "prog1.h"

int main()
{
	message sent_in; //variable for a stuct for the message sent in/ sent out
	message peeked; //variable for the message found when 'peeking'

	received_message received; //variable for the class for messages recieved.
	replied_message replied; // variable for the class for the messages sent out. 		

	char choose=0; // variable to tell which action the user would like to take
	bool a_responce; // bool var to tell send to functions to tell if
	// a sent message is a responce, or a message on its own.
	int amount=0; //amount of messages to be sent out of queue
	int freq=0;

	srand(time(NULL)); //seed the random number generator


	//Will continue to call menu and promping use for an action until they
	// enter the number to quit the program
	while (choose != '7')
	{

		choose='0'; //re-set choose to 0 each loop through

		menu(choose); //call menu function 

		// receive new message
		if (choose == '1')
		{
			cout<<"Please enter the following information "
				<<"about the message you received"<<endl<<endl
				<<"what is the name of the person you received the message from?"
				<<endl;
			receiving (sent_in, choose); // call function to get information 
			// about message from user

			//call function to save the information
			//gathered in 'recieving', and save it into our data type
			if (received.push(sent_in))
				cout<<"*** successfully added your incomming message ***"<<endl;
			else
				cout<<"*** looks like there was a problem with the information "
					<<"you entered ***"<<endl;
		}

		// veiw most recent
		if (choose == '2')
		{
			// call function to display most reecent
			//message received
			if (!received.display())
				cout<<"*** looks like there was nothing to display ***"<<endl;
		}

		//reply to most recent
		if ( choose == '3')
		{
			a_responce=1; //set to 1 to show that user IS responding
			received.peek(peeked); // call function to get last received
			//message from data type
			//received.pop(); // delete the most reciently recieved message
			cout<<"Please enter the following information "
				<<"about the message you are sending out"<<endl<<endl;

			receiving (sent_in, choose); //get information from user about the message
			// they are sending

			// save the information gatherd in 'recieving' and save in
			//out data type
			if (replied.enqueue(sent_in, peeked, a_responce))
				cout<<"*** successfully saved your outgoing message ***"<<endl;
			else
				cout<<"*** it looks like there was a problem with the "
					<<"information you added *** "<<endl;
		}
		//send out a message
		if (choose == '4')
		{
			a_responce=0; // set to 0 to show that user is NOT replying to message
			cout<<"Please enter the following information "
				<<"about the message you are sending out"<<endl<<endl
				<<"what is the name of the person you are sending a message to?"
				<<endl;
			receiving (sent_in, choose); // call function to get information about the 
			//message they are sending

			//save the information gatherd from user into the data structure
			if (replied.enqueue(sent_in, peeked, a_responce))
				cout<<"*** successfully saved your outgoing message ***"<<endl;
			else
				cout<<"*** it looks like there was a problem with the "
					<<"information you added *** "<<endl;
		}
		//disregard most recent
		if (choose == '5')
		{
			received.peek(peeked); //call function to get the most reciently
			//recived message and save in 'peeked'
			received.pop(); // call function to delete the most reciently
			//recived message
		}

		//view last sent
		if (choose == '6')
		{
			//function to display most reciently sent message
			if(!replied.display())
				cout<<"*** it looks like there was nothing to display ***"<<endl;
		}


		//calling call function to tell how many messages are 'waiting' to 
		//be sent, so we can send them	
		amount=replied.count();

		//I set amount to 4+ so that the fact im using rand is more noticable
		//(nothing will be deleted until there is at least 4 messages)
		//It could however just be 'if(amount)', then 1 message will be sent
		//each loop though our options
		if (amount > 3)
		{
			//set freq = to rand moded by the amount of messages that
			//are currently waiting to be sent out. 
			//this number represents how many messages will be sent out at
			//a time.
			freq=(rand() % amount);
			++freq;

			cout<<" *** "<<amount<<" messages pending to be sent out ***"<<endl;

			//call peeked so we can use the last sent out message (if they needed)
			replied.peek(peeked); 
			//'send' out a message for as long as i is less the freq
			for (int i=0; i<freq; ++i)
			{ 
				replied.dequeue(); //function to delete the most reciently sent
			}

			cout<<" *** "<<freq<<" messages sent out ***"<<endl;
		}

	}
}

//display the different action the user can choose from, and read in their choice
char menu (char & choose)
{
	cout<<endl<<endl<<endl;

	cout<<"1.	did you receive a new message?"<<endl
		<<"2.	view your most recent message?"<<endl
		<<"3.	reply to your most recent message?"<<endl
		<<"4.	send a message? "<<endl
		<<"5.	disregard your most recent message?"<<endl
		<<"*******************************************************"<<endl
		<<"6.	view your last sent message"<<endl
		<<"7.	quit"
		<<endl<<endl;

	cin>>choose;
	cin.ignore(100, '\n');

	return choose;
}

//function to read in information about a message from user
int receiving (message & sent_in, char choose)
{
	char temp[400]; //create statically allocated array to 
	//save information in initally
	char temp_char;
	if (choose != '3')
	{
		//they were prompted about senders/receivers name...
		cin.get( temp, 400, '\n');
		cin.ignore(100, '\n');

		//create a dynamically allocated array of size temp +1	
		sent_in.name= new  char[strlen(temp)+1];
		//save information saved from temp, into sent_in.name
		strcpy(sent_in.name, temp);

		//###################################################//	
		//repeat same steps for each member or our 'message' struct

		cout<<"Their phone number ?"<<endl;
		cin.get( temp, 400, '\n');
		cin.ignore(100, '\n');

		sent_in.number= new  char[strlen(temp)+1];
		strcpy(sent_in.number, temp);

		//###################################################//	

		cout<<"Their email address ?"<<endl;
		cin.get( temp, 400, '\n');
		cin.ignore(100, '\n');

		sent_in.email= new  char[strlen(temp)+1];
		strcpy(sent_in.email, temp);

		//###################################################//	

		cout<<"Their nickname?"<<endl;
		cin.get( temp, 400, '\n');
		cin.ignore(100, '\n');

		sent_in.nick= new  char[strlen(temp)+1];
		strcpy(sent_in.nick, temp);
	}

	// if we are recieving a message
	if (choose == '1')
	{

		cout<<"Is the person sending this message blocked? Y/N"<<endl;

		cin>>temp_char;
		cin.ignore (100, '\n');

		//if they said yes, save into sent in as true.
		if (temp_char == 'Y' || temp_char == 'y')
			sent_in.blocked=1;

		//other wise save as false
		else
			sent_in.blocked=0;


		cout<<"Is this a seceret conversation? Y/N"<<endl;
		cin>>temp_char;
		cin.ignore(100, '\n');

		if (temp_char == 'Y' || temp_char == 'y')
			sent_in.secret=1;

		else
			sent_in.secret=0;


	}

	//###################################################//	

	cout<<"What was the date of message received/ sent out?"<<endl;
	cin.get( temp, 400, '\n');
	cin.ignore(100, '\n');

	sent_in.date= new  char[strlen(temp)+1];
	strcpy(sent_in.date, temp);

	//###################################################//	

	cout<<"What was the time the message was received/ sent out?"<<endl;
	cin.get( temp, 400, '\n');
	cin.ignore(100, '\n');

	sent_in.time= new  char[strlen(temp)+1];
	strcpy(sent_in.time, temp);

	//###################################################//	

	cout<<"What is the messages subject line?"<<endl;
	cin.get( temp, 400, '\n');
	cin.ignore(100, '\n');

	sent_in.subject= new  char[strlen(temp)+1];
	strcpy(sent_in.subject, temp);

	//###################################################//	

	cout<<"What is the message's body?"<<endl;
	cin.get( temp, 400, '\n');
	cin.ignore(100, '\n');

	sent_in.body= new  char[strlen(temp)+1];
	strcpy(sent_in.body, temp);

}
