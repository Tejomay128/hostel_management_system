#include "headerfile.h"
#define N 30
#define K 24

int main()
{
	struct student old_stud[N], new_stud[N];
	struct room room[K/2];
	int choice,sh_c,ns_c,os_c,dh_c, old_sz;
	int f1, f2, f3, f4, i, floor_pref_count, roommate_pref_count;
	f2=f3=f4=0;
	char repeat='\0';
	initialize_s(old_stud, N);
	initialize_s(new_stud, N);
	initialize_r(room,K/8,1);
	initialize_r(room,K/8,2);
	initialize_r(room,K/8,3);
	initialize_r(room,K/8,4);
	sh_c=ns_c=os_c=dh_c=0;    // sh_c = students who want same hostel,ns_c = new students,os_c = seniors living outside,dh_c = students from different hostel
	old_sz=assign(old_stud, new_stud, N, &sh_c, &ns_c, &os_c, &dh_c);
	f1=new_stud_allocate(new_stud, room, ns_c, K/2);
	old_stud_allocate(old_stud, room, old_sz, K/2, &f2, &f3, &f4);

	floor_pref_count=roommate_pref_count=0;
	for(i=0;i<old_sz;i++)
	{
		if(old_stud[i].floor_no == old_stud[i].p.floor_pref)
		{
			floor_pref_count++;
		}
		if(old_stud[i].roommate_id == old_stud[i].p.roommate_pref)
		{
			roommate_pref_count++;
		}
	}
	do 																			//question A
	{
		printf("1. Print no. of seats filled in each floor\n2. Print no.of students who got rooms as per their first preference(floor)\n");
		printf("3. Print no.of students who got rooms as per their second preference(students)\n4.Print no.of vaacnt seats in each floor\n");
		printf("Enter your choice(1,2,3,4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :	printf("\nNo. of seats filled in each floor:\n1-> %d\n2-> %d\n3-> %d\n4-> %d",(K/4)-f1-4, (K/4)-f2, (K/4)-f3, (K/4)-f4);
						break;

			case 2 : 	printf("\nNo.of students who got rooms as per their floor preference: %d",floor_pref_count);
						break;

			case 3 :    printf("\nNo.of students who got rooms as per their roommate preference: %d",roommate_pref_count);
						break;
					
			case 4 :	printf("\nNo. of seats vacant in each floor: 1-> %d\n2-> %d\n3-> %d4-> %d",f1, f2, f3, f4);
						break;	

			default : 	printf("\nWrong choice.");		
		}
		printf("\n\nDo you want to repeat? (y/n):");
		scanf("%c",&repeat);
	}while(repeat == 'y' || repeat == 'Y');
	return 0;
}
