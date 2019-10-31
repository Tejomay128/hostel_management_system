#include <stdio.h>
#include <string.h>

struct preference				//only for 2nd,3rd and 4th year students
{
	int floor_pref;			//will take values as floor nos.
	int roommate_pref;		//will take 10 student IDs according to prefernce order
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
void initialize_r(struct room r[], int size);
