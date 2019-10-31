#include <stdio.h>
#include <string.h>

struct preference				//only for 2nd,3rd and 4th year students
{
	int floor_pref;			//will take values as floor nos.
	int roommate_pref;		//will take 10 student IDs according to prefernce order
};

struct room 					//room data
{
	int room_no;  
	int id1; 			//student IDs who are occupying the rooms
	int id2;
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
	int id_roommate;
	struct preference p;
};

int main()
{
	FILE *fp;
	struct student st;
    fp=fopen("student.dat", "rb"); 	//change rb to ab for appending data to file
    if(fp==NULL) 
    { 
        printf("\nError opening file\n"); 
    }
    else
    {
    	printf("\nFile opened successfully\n"); 
	    for(int i=0;i<30;i++)		//for writing to file
    	{
    		printf("Enter id, name, year, dept, hostel no, preferred floor, preferred roommate:  ");
    		scanf("%d %s %d %s %d %d %d", &st.id, st.name, &st.year, st.dept, &st.hostel_no, &st.p.floor_pref, &st.p.roommate_pref);
    		fwrite (&st, sizeof(struct student), 1, fp); 
		}
		while(fread(&st, sizeof(struct student), 1, fp)) 	//for reading from file
        	printf ("%d %s %d %s %d %d %d\n", st.id, st.name, st.year, st.dept, st.hostel_no, st.p.floor_pref, st.p.roommate_pref);  
    	fclose(fp);
    }
   	return 0; 
} 	
		
