#include<stdio.h>
#include<stdlib.h>
struct student//Creating structure student with three different types of variables
{
	char name[21];//to store name of student
	int id;//to store id of student
	float marks;//to store marks of student
};
void sorting(struct student s[],int n)//function to sort structure student according to ids of student
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(s[j].id<s[i].id)
			{
				struct student t=s[i];//allotiong s[i] to some temporary structure
				s[i]=s[j];//exchanging structure vlaues
				s[j]=t;//storing s[i] to s[j]
			}
		}
	}
}

int main()
{
	FILE *file;
	file=fopen("input_file.txt","r");//Opening input_file to get input
	int n;
	fscanf(file,"%d",&n);//Taking first input from input_file
	struct student std[n];//structure student array to store n students details
	for(int i=0;i<n;i++)
	{
		fscanf(file,"%s %d %f",std[i].name,&(std[i].id),&(std[i].marks));//Taking input from input_file
	}
	sorting(std,n);//Calling sorting function to sort structure array
	fclose(file);//Closing input_file
	file=fopen("output_file.txt","w");//Opening new output file to store output
	for(int i=0;i<n;i++)
	{
		fprintf(file,"%s %d %g\n",std[i].name,std[i].id,std[i].marks);//Storing structure array after being sorted
	}
	fclose(file);//Closing output_file 

}





