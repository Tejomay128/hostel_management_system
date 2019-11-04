#include "headerfile.h"

int main()
{
	struct student stud[N];
	struct room room[K/2];
	int size;
	initialize_s(stud, N);
	initialize_r(room,K/8,1);
	initialize_r(room,K/8,2);
	initialize_r(room,K/8,3);
	initialize_r(room,K/8,4);
	size=assign_all(stud, N);
	pref_lists(stud, N-size);
	stable_combination(stud, N-size);
  	printf("Based on the student data, the stable combinations are:\n");
  	assign_rooms(stud, room, N-size, K);
  													//Que C
  	int tick[K/2];                              
  	int i,j,l,rooms_per_floor;
  	for(i=0;i<K/2;i++)
  	{
  		tick[i]=0;
  	} 
  	i=0;
  	rooms_per_floor=K/8;
  	while(i<N_size)
  	{
  		j=find_index(stud,size,stud[i].roommate_id);
  		if(tick[i] == 0)
  		{
  			printf("\nPossible seat allotments(room nos.) for students with IDs %d and %d are:\n",stud[i].id,stud[j].id)
  			if(stud[i].p.floor_pref == stud[j].p.floor_pref)
  			{
  				for(l=1;l<=rooms_per_floor;l++)
  				{
  					printf("%d\t",1000*stud[i].p.floor_pref + l);
  					
  				}
  			}
  		}
  		i++;
  	}
	return 0;
}
