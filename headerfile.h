#include <stdio.h>
#include <string.h>
#define N 30
#define K 24

struct preference				//only for 2nd,3rd and 4th year students
{
	int floor_pref;		
	int roommate_pref;
	int list[N];
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

void initialize_s(struct student s[], int size);      					// initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'

void initialize_r(struct room r[], int size, int floor_no);    					// initialize everything to -1 except room nos.,that will be assigned as per no. of floors available per floor

void display(struct student old_stud[],int size);

int assign(struct student old_stud[], struct student new_stud[], int size, int *sh_c, int *ns_c, int *os_c, int *dh_c); //assigns the applications to four
																												//different arrays according to their 
																												//decreasing preferences of processing

int new_stud_allocate(struct student new_stud[], struct room room[], int new_stud_size, int room_size); 	//allocates rooms to new applicants

void old_stud_allocate(struct student old_stud[], struct room room[], int old_stud_size, int room_size, int *r2, int *r3, int *r4);	//allocates rooms to old students

int find_index(struct student old_stud[], int size, int id);   //returns index where id is found, if not found returns -1

int check_preference(struct student for_check, struct student existing, struct student interested); 	//to check whether interested features higher in for_check's preferred list than existing

void stable_combination(struct student old_stud[], int old_stud_size);		//to assign roommates based on stable combination

void assign_rooms(struct student old_stud[], struct room room[], int old_stud_size, int room_size);		//to assign rooms based on stable combination and display roommates
