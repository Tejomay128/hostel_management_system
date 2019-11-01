#include "headerfile.h"

void initialize_s(struct student s[],int size)                    // initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'
{
	int i;
	for(i=0;i<size;i++)
	{
		s[i].id=s[i].year=s[i].hostel_no=s[i].floor_no=s[i].room_no=s[i].id_roommate=-1;
		s[i].name[0]='\0';
		s[i].dept[0]='\0';
	}	
}

void initialize_r(struct room r[],int size,int floor_no)                    // initialize everything to -1 except room nos.,that will be assigned as per no.
{									    // of floors available per floor	
	int i;
	for(i=0;i<size;i++)
	{
		r[i].vacancy=-1;
		r[i].id1=-1;
		r[i].id2=-1;
		r[i].room_no=(1001*floor_no)+i;
	}	
}

int assign(struct student old_stud[],struct student new_stud[],int size, int *sh_c, int *ns_c, int *os_c, int *dh_c) 	//assigns the applications to four
{															//different arrays according to their
	FILE *f; 							    						//decreasing preferences of processing
	struct student st,same_hostel[size],out_stud[size],diff_hostel[size];
	int i,j; 																		
	f=fopen("student.dat","rb"); 															
	while(fread(&st, sizeof(struct student), 1, f))
	{
		if(st.hostel_no == 1)
		{
			same_hostel[sh_count]=st;
			(*sh_c)++;
		}
		else if(st.hostel_no == -1)
		{
			if(st.year == 1)
			{
				new_stud[ns_count]=st;
				(*ns_c)++;
			}
			else
			{
				out_stud[os_count]=st;
				(*os_c)++;
			}	
		}
		else 
		{
			diff_hostel[dh_count]=st;
			(*dh_c)++;
		}
	}
	j=0;
	fclose(f);
	for(i=0;i<sh_count;i++) 					//from here,the array old_stud[] is filled with details in preference order
	{
		old_stud[j]=same_hostel[i];         
		j++;
	}
	for(i=0;i<os_count;i++)
	{
		old_stud[j]=out_stud[i];
		j++;
	}
	for(i=0;i<size;i++)
	{
		old_stud[j]=diff_hostel[i];
	}
	return j;  									//the size of old_stud[] is returned
}

int new_stud_allocate(struct student new_stud[], struct room room[], int new_stud_size, int room_size)
{
	int ret_val, i, j, floor_room;
	floor_room=(room_size/4)-2;		// number of rooms on first floor, taking care of guest rooms
	i=j=0;
	ret_val=0;
	while((i<floor_room)&&(j<new_stud_size))
	{
		if(j+1 < new_stud_size)      //assigning rooms
		{
			new_stud[j].room_no=new_stud[j+1].room_no=room[i].room_no;		
			room[i].id1=new_stud[j+1].id_roomate=new_stud[j].id;
			room[i].id2=new_stud[j].id_roommate=new_stud[j+1].id;
			new_stud[j].hostel_no=new_stud[j+1].hostel_no=new_stud[j].floor_no=new_stud[j+1].floor_no=1;
			room[i].vacancy=1;
			i++;
			j=j+2;
		}	
		else
		{
			new_stud[j].room_no=room[i].room_no;
			room[i].id1=new_stud[j].id;
			new_stud[j].hostel_no=new_stud[j].floor_no=1;
			i++;
			j++;
		}
	}
	if(j<new_stud_size)		//if there are applicants left but rooms filled
	{
		ret_val=0;
	}
	else if(i<floor_room)		//if applicants are done before all rooms filled
	{
		if(new_stud_size%2 == 0)
			ret_val = 2*(floor_room-i);
		else
			ret_val = 2*(floor_room-i) + 1;
	}
	return ret_val;		//holds number of vacant seats on first floor
}
