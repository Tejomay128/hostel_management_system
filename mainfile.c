#include "heaerfile.h"
#define N 30
#define K 24

int main()
{
	struct student old_stud[N],new_stud[N];
	struct room room[K/2];
	int choice,sh_c,ns_c,os_c,dh_c;
	char repeat;
	initialize_s(old_stud, N);
	initialize_s(new_stud, N);
	sh_c=ns_c=os_c=dh_c=0;    // sh_c = students who want same hostel,ns_c = new students,os_c = seniors living outside,dh_c = students from different hostel
	assign(old_stud, new_stud, N, &sh_c, &ns_c, &os_c, &dh_c);
	repeat = 'y';
	while(repeat == 'y' || repeat == 'Y')    	//question A
	{
		printf("1. Print no. of seats filled in each floor\n2. Print no.of students who got rooms as per their first preference(rooms)\n");
		printf("3. Print no.of students who got rooms as per their second preference(students)\n4.Print no.of vaacnt seats in each floor\n");
		printf("Enter your choice(1,2,3,4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : {
						printf("\nNo. of seats filled in first floor : %d",ns_c);
						break;
					}
			case 2 : {

						break;
					}
			case 3 : {
						break;
					}
			case 4 : {
						break;
					}		
			default : {
						printf("\nNo such choice exists!!!!")
					}						
		}
		printf("\n\nDo you want to repeat? (y/n):");
		scanf("%d",&repeat);
	}
	return 0;
}
