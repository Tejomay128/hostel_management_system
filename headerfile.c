#include "headerfile.h"

void initialize_s(struct student s[],int size)                    // initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'
{
	int i;
	for(i=0;i<size;i++)
	{
		s[i].id=s[i].year=s[i].hostel_no=s[i].floor_no=s[i].room_no=s[i].roommate_id=-1;
		s[i].name[0]='\0';
		s[i].dept[0]='\0';
	}	
}

void initialize_r(struct room r[],int size,int floor_no)                    // initialize everything to -1 except room nos.,that will be assigned as per no.
{									    // of floors available per floor	
	int i;
	for(i=0;i<size;i++)
	{
		r[i + (floor_no-1)*size].vacancy=-1;
		r[i + (floor_no-1)*size].id1=-1;
		r[i + (floor_no-1)*size].id2=-1;
		r[i + (floor_no-1)*size].room_no=(1001*floor_no)+i;
	}	
}

int assign(struct student old_stud[],struct student new_stud[],int size, int *sh_c, int *ns_c, int *os_c, int *dh_c) 	//assigns the applications to four
{																														//different arrays according to their
	FILE *f; 							    																			//decreasing preferences of processing
	struct student st,same_hostel[size],out_stud[size],diff_hostel[size];
	int i,j,sh_count,ns_count,os_count,dh_count;
	sh_count=ns_count=os_count=dh_count=0; 																		
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
		j++;
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
			room[i].id1=new_stud[j+1].roommate_id=new_stud[j].id;
			room[i].id2=new_stud[j].roommate_id=new_stud[j+1].id;
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

int find_index(struct student old_stud[], int size, int id)  //returns index where id is found, if not found returns -1
{
	int i,pos=-1;
	for(i=0;i<size && pos==-1;i++)
	{
		if(id == old_stud[i].id)
		{
			pos = i;
		}
	}
	return pos;
}

void old_stud_allocate(struct student old_stud[], struct room room[], int old_stud_size, int room_size, int *r2, int *r3, int *r4)
{
	int x, y, z, i, j;
	i=0;
	while(i<old_stud_size)		//for assigning roommates based on roommate preference
	{
		j=find_index(old_stud, old_stud_size, old_stud[i].p.roommate_pref);
		if(old_stud[i].roommate_id==-1 && (old_stud[j].p.roommate_pref==old_stud[i].id || old_stud[j].roommate_id==-1))
		{											//if both don't have roommates or if both are each others' preferred roommate
			if(old_stud[j].roommate_id!=-1)
			{										//if other guy has a roommate he does not prefer
				x=find_index(old_stud, old_stud_size, old_stud[j].roommate_id);
				old_stud[x].roommate_id=-1;
			}
			old_stud[i].roommate_id=old_stud[j].id;		//assigning them as roommates
			old_stud[j].roommate_id=old_stud[i].id;
		}
		i++;
	}
	i=0;
	while(i<old_stud_size)		//for assigning roommates based on floor preference
	{
		if(old_stud[i].roommate_id == -1)
		{
			j=i+1;
			x=0;
			while(j<old_stud_size && x==0 && old_stud[j].roommate_id==-1)
			{
				if(old_stud[i].p.floor_pref==old_stud[j].p.floor_pref)
				{												//if both prefer same floor
					old_stud[i].roommate_id=old_stud[j].id;		//assigning them as roommates
					old_stud[j].roommate_id=old_stud[i].id;
					x=1;
				}
				j++;
			}
		}
		i++;
	}
	(*r2)=(*r3)=(*r4)=0;		//for storing index of next room on that floor to be occupied
	i=0;
	while(i<old_stud_size)		//for assigning rooms to roommate pairs
	{
		if(old_stud[i].room_no==-1)
		{
			j=find_index(old_stud, old_stud_size, old_stud[i].roommate_id);
			x=old_stud[i].p.floor_pref;		                //checking for floor preference      
			
			if(x==2 && (*r2)<(room_size/4))
			{
				y = *r2;
				(*r2)++;
			}
			else if(x==3 && (*r3)<(room_size/4))         //y stores index of room in room[]
			{
				y = *r3;
				(*r3)++;
			}
			else if(x==4 && (*r4)<(room_size/4))
			{
				y = *r4;
				(*r4)++;
			}
			z=((x-1)*(room_size)/4)+y;		
			room[z].id1=old_stud[i].id;		//updating room and student details
			room[z].id2=old_stud[j].id;
			room[z].vacancy=1;
			old_stud[i].hostel_no=old_stud[j].hostel_no=1;
			old_stud[i].floor_no=old_stud[j].floor_no=x;
			old_stud[i].room_no=old_stud[j].room_no=room[z].room_no;
		}
		i++;
	}
	(*r2)=2*((room_size/4)-(*r2));		//now *r2, *r3 and *r4 will store number of vacant seats in their respective floors
	(*r3)=2*((room_size/4)-(*r3));
	(*r4)=2*((room_size/4)-(*r4));
}
