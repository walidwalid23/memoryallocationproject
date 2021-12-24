#include <iostream>
using namespace std;


bool isAllocated(int block, int* allocatedBlocks, int allocatedLength) {

	for (int i = 0; i < allocatedLength; i++) {

		if (block == allocatedBlocks[i]) {
			return true;
		}
	}
	return false;

}


void firstFit(int processesNumber, int* processesSizes, int blocksNumber, int* blocksSizes) {
	int allocatedLength = 0;
	int* allocatedBlocks = new int[blocksNumber];
	int* allocatedProcesses = new int[processesNumber];
	int* allocatedBlocksNumber = new int[blocksNumber];
	int* allocatedProcessesNumber = new int[processesNumber];


	for (int i = 0; i < processesNumber; i++) {
		bool allocated = false;
		for (int j = 0; j < blocksNumber; j++) {
			if (processesSizes[i] <= blocksSizes[j] && !isAllocated(blocksSizes[j], allocatedBlocks, allocatedLength)) {

				//add the allocated blocks and proccesses to the allocation arrays
				allocatedBlocks[allocatedLength] = blocksSizes[j];
				allocatedProcesses[allocatedLength] = processesSizes[i];
				allocatedBlocksNumber[allocatedLength] = j + 1;
				allocatedProcessesNumber[allocatedLength] = i + 1;

				allocatedLength++;
				allocated = true;
				break;
			}

		}
		if (!allocated) {
			//if the proccess was not allocated to any block
			allocatedProcessesNumber[allocatedLength] = i + 1;
			allocatedProcesses[allocatedLength] = processesSizes[i];
			allocatedBlocks[allocatedLength] = 0;
			allocatedLength++;

		}

	}

	cout << "Processes Number" << "   " << "Processes Size" << "   " << "Allocated Block Size" << endl;
	for (int i = 0; i < allocatedLength; i++) {

		if (allocatedBlocks[i] == 0) {
			//if the process was not allocated to any block
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "              " << "Not Allocated" << endl;

		}
		else {
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "                " << allocatedBlocks[i] << endl;
		}

	}

}

void bestFit(int processesNumber, int* processesSizes, int blocksNumber, int* blocksSizes) {
	int allocatedLength = 0;
	int* allocatedBlocks = new int[blocksNumber];
	int* allocatedProcesses = new int[processesNumber];
	int* allocatedBlocksNumber = new int[blocksNumber];
	int* allocatedProcessesNumber = new int[processesNumber];

	//arranging the array of block sizes in ascending order
	for (int k = 0; k < blocksNumber; k++)
	{
		for (int x = k + 1; x < blocksNumber; x++)
		{
			if (blocksSizes[k] > blocksSizes[x])
			{
				int tempVar = blocksSizes[k];
				blocksSizes[k] = blocksSizes[x];
				blocksSizes[x] = tempVar;
			}
		}
	}

	//finding the bestfit
	for (int i = 0; i < processesNumber; i++) {
		bool allocated = false;
		for (int j = 0; j < blocksNumber; j++) {
			if (processesSizes[i] <= blocksSizes[j] && !isAllocated(blocksSizes[j], allocatedBlocks, allocatedLength)) {

				//add the allocated blocks and proccesses to the allocation arrays
				allocatedBlocks[allocatedLength] = blocksSizes[j];
				allocatedProcesses[allocatedLength] = processesSizes[i];
				allocatedBlocksNumber[allocatedLength] = j + 1;
				allocatedProcessesNumber[allocatedLength] = i + 1;

				allocatedLength++;
				allocated = true;
				break;
			}

		}
		if (!allocated) {
			//if the proccess was not allocated to any block
			allocatedProcessesNumber[allocatedLength] = i + 1;
			allocatedProcesses[allocatedLength] = processesSizes[i];
			allocatedBlocks[allocatedLength] = 0;
			allocatedLength++;

		}

	}

	cout << "Processes Number" << "   " << "Processes Size" << "   " << "Allocated Block Size" << endl;
	for (int i = 0; i < allocatedLength; i++) {

		if (allocatedBlocks[i] == 0) {
			//if the process was not allocated to any block
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "              " << "Not Allocated" << endl;

		}
		else {
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "                " << allocatedBlocks[i] << endl;
		}

	}

}

void worstFit(int processesNumber, int* processesSizes, int blocksNumber, int* blocksSizes) {
	int allocatedLength = 0;
	int* allocatedBlocks = new int[blocksNumber];
	int* allocatedProcesses = new int[processesNumber];
	int* allocatedBlocksNumber = new int[blocksNumber];
	int* allocatedProcessesNumber = new int[processesNumber];

	//arranging the array of block sizes in descending order
	for (int k = 0; k < blocksNumber; k++)
	{
		for (int x = k + 1; x < blocksNumber; x++)
		{
			if (blocksSizes[k] < blocksSizes[x])
			{
				int tempVar = blocksSizes[k];
				blocksSizes[k] = blocksSizes[x];
				blocksSizes[x] = tempVar;
			}
		}
	}

	//finding the Worst fit
	for (int i = 0; i < processesNumber; i++) {
		bool allocated = false;
		for (int j = 0; j < blocksNumber; j++) {
			if (processesSizes[i] <= blocksSizes[j] && !isAllocated(blocksSizes[j], allocatedBlocks, allocatedLength)) {

				//add the allocated blocks and proccesses to the allocation arrays
				allocatedBlocks[allocatedLength] = blocksSizes[j];
				allocatedProcesses[allocatedLength] = processesSizes[i];
				allocatedBlocksNumber[allocatedLength] = j + 1;
				allocatedProcessesNumber[allocatedLength] = i + 1;

				allocatedLength++;
				allocated = true;
				break;
			}

		}
		if (!allocated) {
			//if the proccess was not allocated to any block
			allocatedProcessesNumber[allocatedLength] = i + 1;
			allocatedProcesses[allocatedLength] = processesSizes[i];
			allocatedBlocks[allocatedLength] = 0;
			allocatedLength++;

		}

	}
	cout << "Processes Number" << "   " << "Processes Size" << "   " << "Allocated Block Size" << endl;
	for (int i = 0; i < allocatedLength; i++) {

		if (allocatedBlocks[i] == 0) {
			//if the process was not allocated to any block
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "              " << "Not Allocated" << endl;

		}
		else {
			cout << "        " << allocatedProcessesNumber[i] << "             " << allocatedProcesses[i] << "                " << allocatedBlocks[i] << endl;
		}

	}

}


int main()
{
	while (true) {
		//TAKE THE NUMBER OF MEMOMRY BLOCKS AND BLOCK SIZES
		int memoryBlocksNumber;
		cout << "Enter The Tottal Number of Memory Blocks:";
		cin >> memoryBlocksNumber;

		int* blockSizes = new int[memoryBlocksNumber];

		for (int i = 0; i < memoryBlocksNumber; i++) {
			cout << "Enter the size of Block " << i + 1 << ":";
			cin >> blockSizes[i];
		}

		//TAKE THE NUMBER OF PROCESSES AND PROCESSES SIZES
		int processesNumber;
		cout << "Enter The Number of Processes:";
		cin >> processesNumber;
		int* processesSizes = new int[processesNumber];

		for (int i = 0; i < processesNumber; i++) {
			cout << "Enter the size of Process " << i + 1 << ":";
			cin >> processesSizes[i];
		}
		//displaying data
		cout << "blocks sizes: " << endl;
		for (int i = 0; i < memoryBlocksNumber; i++) {

			cout << blockSizes[i] << "  ";
		}
		cout << endl;
		cout << "processes sizes: " << endl;
		for (int i = 0; i < processesNumber; i++) {

			cout << processesSizes[i] << "  ";
		}
		cout << endl;
		//ALLOCATION METHODS
		bool repeat = true;
		while (repeat) {
			repeat = false;
			cout << "Select:" << endl;
			cout << "1-First Fit" << endl;
			cout << "2-Best Fit " << endl;
			cout << "3-Worst Fit " << endl;
			int methodInput;
			cin >> methodInput;
			if (methodInput == 1) {
				cout << " First Fit:" << endl;
				firstFit(processesNumber, processesSizes, memoryBlocksNumber, blockSizes);
				cout << endl;
			}
			if (methodInput == 2) {
				cout << " Best Fit:" << endl;
				bestFit(processesNumber, processesSizes, memoryBlocksNumber, blockSizes);
				cout << endl;
			}
			if (methodInput == 3) {
				cout << " Worst Fit:" << endl;
				worstFit(processesNumber, processesSizes, memoryBlocksNumber, blockSizes);
				cout << endl;
			}
			/// 
			int userInput;
			cout << "Select:" << endl;
			cout << "1- To Choose Different Allocation Method" << endl;
			cout << "2- To Exit" << endl;
			cin >> userInput;
			if (userInput == 1) { repeat = true; }
			if (userInput == 2) { exit(0); }
		}
	}
	return 0;
}
