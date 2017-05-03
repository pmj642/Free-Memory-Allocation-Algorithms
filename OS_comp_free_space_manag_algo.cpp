#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
int firstFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a process
    int allocation[n], cnt = 0;;
	int i, j;
    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks according to its size ad assign to it
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
        if(j==m)
			cnt++; //increment the counter if process if unallocated
    }
    return cnt;
}

int bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], cnt = 0;
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        // If we could find a block for current process
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
		else
			cnt++;
    }
	return cnt;
}

int worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n], cnt = 0;
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
        // If we could find a block for current process
        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
        else
			cnt++;
    }
	return cnt;
}

void call_algo(int freeblocks[], int n_blocks, int process[], int n_process)
{
	int i, j, no_of_unalloc;
	clock_t timer;
	
	int tmp_freeblocks[n_blocks];
	for(i=0; i<n_blocks; ++i)
		tmp_freeblocks[i] = freeblocks[i];
		
	for(i=1; i<4; ++i)
	{
		if(i==2 || i==3)
			for(j=0; j<n_blocks; ++j)
				freeblocks[j] = tmp_freeblocks[j];
		timer = clock();
		switch(i)
		{
			case 1: no_of_unalloc = firstFit(freeblocks, n_blocks, process, n_process);
					break;

			case 2: no_of_unalloc = bestFit(freeblocks, n_blocks, process, n_process);
					break;

			case 3: no_of_unalloc = worstFit(freeblocks, n_blocks, process, n_process);
					break;
		}
		timer = (double(clock() - timer))/CLOCKS_PER_SEC;
		cout << "| " << setw(15) << left << no_of_unalloc << setw(9) << right << timer;
	}
	cout << endl;
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
	//formatted output
	cout << left << setw(12) << " " << "| " << setw(18) << " ";
	cout << "| " << setw(24) << "First Fit";
	cout << "| " << setw(24) << "Best Fit"<< "| " << setw(24) << "Worst Fit" << endl;
	cout << left << setw(12) << "Dataset #" << "| " << setw(18) << "Dataset Descrp.";
	for(i=0; i<3; ++i)
		cout << "| " << left <<  setw(15) << "#unalloc. proc" << right << setw(9) << "time";
	cout << endl;
	for(i=0; i<111; ++i)
		cout << '-';
	cout << endl;
	
	//read free block data
	for(i='0';i<'5';++i)
	{
		filename[5]=i;
	//	cout<<filename<<endl;
		
		freopen(filename,"r",stdin);
			
		cin>>no_of_freeblocks;
		cin.getline(block_data_type,15);

		cout << setw(12) << left << i << "| " << setw(18) << block_data_type;

		int free_blocks[no_of_freeblocks];
		 
		for(j=0;j<no_of_freeblocks;++j)
			cin>>free_blocks[j];

		call_algo(free_blocks, no_of_freeblocks, process, no_of_process);

		fclose(stdin);
	}
	
	return 0;	
}
