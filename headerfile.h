#include <stdio.h>
#include <string.h>

struct preference				//only for 2nd,3rd and 4th year students
{
	int floor_pref;		
	int roommate_pref;	
};

struct room 					//room data
{
	int room_no;  
	int id1; 			//student IDs who are occupying the rooms
	int id2;
	int vacancy;
};

struct student 					//student data
{
	int id;						
	char name[100];
	int year;
	char dept[100];
	int hostel_no;
	int floor_no;
	int room_no;
	int id_roommate;
	struct preference p;
};

void initialize_s(struct student s[], int size); // initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'
void initialize_r(struct room r[], int size, int floor_no);    // // initialize everything to -1 except room nos.,that will be assigned as per no. of floors available per floor
void assign(struct student same_hostel[],struct student new_stud[],struct student outside[],struct student diff_hostel[],int size); //assigns the applications to four
																    //different arrays according to their 
																    //decreasing preferences of processing
