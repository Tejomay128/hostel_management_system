#include <stdio.h>

void initialize(struct student s[],int size)                    // initilize data id=year=hostel_no=floor_no=room_no=id_roomate=-1, name=dept='\0'
{
	int i;
	for(i=0;i<size;i++)
	{
		s[i].id=s[i].year=s[i].hostel_no=s[i].floor_no=s[i].room_no=s[i].id_roomate=-1;
		s[i].name='\0';
		s[i].dept='\0';
	}	
}

