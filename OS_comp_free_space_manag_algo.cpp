#include<iostream>
#include<cstring>
using namespace std;

int call_algo(int n,int freeblocks[],int process[])
{
	switch(n)
	{
		case 1: firstfit(freeblocks,process);
				break;	
		
		case 2: bestfit(freeblocks,process);
				break;
				
		case 3: worstfit(freeblocks,process);
				break;
	}
}

int main()
{
	char i,filename[7];
	
	char block_data_type[15];		//sorted,reverse sorted or random
	int no_of_freeblocks,j;
	
	strcpy(filename,"input");
	filename[6]='\0';
	
	int no_of_process;
	//read the process data for once and all
	
	freopen("process.txt","r",stdin);
	cin>>no_of_process;
	
	int process[no_of_process];
	
	for(j=0;j<no_of_process;++j)
	cin>>process[j];
	
	fclose(stdin);
	
	//read free block data
		
	for(i='0';i<'5';++i)
	{
		filename[5]=i;
	//	cout<<filename<<endl;
		
		freopen(filename,"r",stdin);
			
		cin>>no_of_freeblocks;
		cin.getline(block_data_type,15);
		
		int free_blocks[no_of_freeblocks];
		 
		for(j=0;j<no_of_freeblocks;++j)
		cin>>free_blocks[j];
		
		fclose(stdin);
	}
	
	return 0;	
}
