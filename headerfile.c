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

void assign(struct student same_hostel[],struct student new_stud[],struct student out_stud[],struct student diff_hostel[],int size)
{
	FILE *f; 							//assigns the applications to four
	struct student st; 						//different arrays according to their
	int sh_count,ns_count,os_count,dh_count;  			//decreasing preferences of processing
	sh_count=ns_count=os_count=dh_count=0;
	f=fopen("student.dat","rb");
	while(fread(&st, sizeof(struct student), 1, f))
	{
		if(st.hostel_no == 1)
		{
			same_hostel[sh_count]=st;
			sh_count++;
		}
		else if(st.hostel_no == -1)
		{
			if(st.year == 1)
			{
				new_stud[ns_count]=st;
				ns_count++;
			}
			else
			{
				out_stud[os_count]=st;
				os_count++;
			}	
		}
		else 
		{
			diff_hostel[dh_count]=st;
			dh_count++;
		}
	}
	fclose(f);
}
