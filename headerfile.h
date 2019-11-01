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
	int vacancy;		//holds -1 if room is vacant, 1 if room is occupied
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
	int roommate_id;
	struct preference p;
};

void initialize_s(struct student[], int);      					// initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'

void initialize_r(struct room[], int, int);    					// initialize everything to -1 except room nos.,that will be assigned as per no. of floors available per floor

int assign(struct student[],struct student[],int, int*, int*, int*, int*); //assigns the applications to four
																												//different arrays according to their 
																												//decreasing preferences of processing

int new_stud_allocate(struct student[], struct room[], int, int); 	//allocates rooms to new applicants

void old_stud_allocate(struct student[], struct room[], int, int, int*, int*, int*);	//allocates rooms to old students

int find_index(struct student[], int, int);   //returns index where id is found, if not found returns -1
