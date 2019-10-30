#include <stdio.h>

struct preference				//only for 2nd,3rd and 4th year students
{
	int floor_pref[3];			//will take values as floor nos.
	int roommate_pref[10];		//will take 10 student IDs according to prefernce order
};

struct room 					//room data
{
	int room_no;  
	int id1; 			//student IDs who are occupying the rooms
	int id2;
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

void initialize(struct student s[],int size);     // initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'
