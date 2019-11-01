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
		if(floor_no == 1)
			r[i].room_no = i+1001;
		else if(floor_no == 2)
			r[i].room_no = i+2001;
		else if(floor_no == 3)
			r[i].room_no = i+3001;
		else
			r[i].room_no = i+4001;
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
