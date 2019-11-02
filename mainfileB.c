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
	pref_lists(stud, size);
  stable_combination(stud, size);
  printf("Based on the student data, the stable combinations are: ");
  assign_rooms(stud, room, size, K);
	return 0;
}
