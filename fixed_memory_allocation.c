#include<stdio.h>

struct pblock
{
    int p_no;
    int psize;
    int alloc_mblock;
};

struct mblock
{
    int block_no;
    int msize;
    int allocated;
};

void get_process_details(struct pblock[]);
void get_memory_details(struct mblock[]);
void disp_process_details(struct pblock[]);
void disp_memory_details(struct mblock[]);
void allocate_first_fit(struct pblock[],struct mblock[]);
void allocate_best_fit(struct pblock[],struct mblock[]);
void allocate_worst_fit(struct pblock[],struct mblock[]);
void disp_allocation(struct pblock[]);
void first_fit();
void best_fit();
void worst_fit();


int i,j,k,total_process,total_memory,ch;

void main()
{
    printf("\n\tImplementation of Memory Allocation Methods for Fixed Partition\n\n");
    
    do{
        printf("\n Memory Allocation Methods Available: \n\n");
        printf("  1.First Fit\n");
        printf("  2.Best Fit\n");
        printf("  3.Worst Fit\n");
        printf("  4.Exit\n");
        
        printf("\n   Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: first_fit();
                    break;
                    
            case 2: best_fit();
                    break;
                    
            case 3: worst_fit();
                    break; 
                    
            case 4: printf("\n   --> Exited the program\n"); 
                    break;
                    
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
        
    }while(ch != 4);
}

void first_fit()
{
    printf("\n\n\tImplementation of First Fit Memory Allocation\n");
    
    printf("\n Enter the total number of processes: ");
    scanf("%d",&total_process);
    
    struct pblock process[total_process];
    
    printf("\n Enter the total number of memory blocks: ");
    scanf("%d",&total_memory);
    
    struct mblock memory[total_memory];
    
    get_process_details(process);
    get_memory_details(memory);
    
    disp_process_details(process);
    disp_memory_details(memory);
    
    allocate_first_fit(process,memory);
    
    printf("\n  First Fit Allocation:\n");
    disp_allocation(process);
}

void best_fit()
{
    printf("\n\n\tImplementation of Best Fit Memory Allocation\n");
    
    printf("\n\n Enter the total number of processes: ");
    scanf("%d",&total_process);
    
    struct pblock process[total_process];
    
    printf("\n Enter the total number of memory blocks: ");
    scanf("%d",&total_memory);
    
    struct mblock memory[total_memory];
    
    get_process_details(process);
    get_memory_details(memory);
    
    disp_process_details(process);
    disp_memory_details(memory);
    
    allocate_best_fit(process,memory);
    
    printf("\n  Best Fit Allocation:\n");
    disp_allocation(process);
}

void worst_fit()
{
    printf("\n\n\tImplementation of Worst Fit Memory Allocation\n");
    
    printf("\n\n Enter the total number of processes: ");
    scanf("%d",&total_process);
    
    struct pblock process[total_process];
    
    printf("\n Enter the total number of memory blocks: ");
    scanf("%d",&total_memory);
    
    struct mblock memory[total_memory];
    
    get_process_details(process);
    get_memory_details(memory);
    
    disp_process_details(process);
    disp_memory_details(memory);
    
    allocate_worst_fit(process,memory);
    
    printf("\n  Worst Fit Allocation:\n");
    disp_allocation(process);
}

void get_process_details(struct pblock process[])
{
    printf("\n   Enter the details of the processes: \n");
    
        for(i = 0; i < total_process; i++)
        {
            printf("\n\t   Enter the process number: ");
            scanf("%d",&process[i].p_no);
        
            printf("\t   Enter the process size of process %d: ",process[i].p_no);
            scanf("%d",&process[i].psize);
            
            process[i].alloc_mblock = -1;
        }
        
        printf("\n");
}

void get_memory_details(struct mblock memory[])
{
    printf("\n   Enter the details of the memory blocks: \n");
    
        for(i = 0; i < total_memory; i++)
        {
            printf("\n\t   Enter the memory block number: ");
            scanf("%d",&memory[i].block_no);
        
            printf("\t   Enter the memory size of block %d: ",memory[i].block_no);
            scanf("%d",&memory[i].msize);
            
            memory[i].allocated = 0;
        }
        
        printf("\n");
}

void disp_process_details(struct pblock process[])
{
    printf("\n");
    
    printf("\n   Process No.   Process Size\n");
    
    for(i = 0; i < total_process; i++)
    {
        printf("\t%d\t      %d\n",process[i].p_no,process[i].psize);
    }
    
    printf("\n");
}

void disp_memory_details(struct mblock memory[])
{
    printf("\n");
    
    printf("\n   Memory Block No.   Memory Size\n");
    
    for(i = 0; i < total_memory; i++)
    {
        printf("\t  %d\t\t   %d\n",memory[i].block_no,memory[i].msize);
    }
    
    printf("\n");
}

void disp_allocation(struct pblock process[])
{
    printf("\n\t   Process No.   Process Size        Block No.\n");
    
    for(i = 0; i < total_process; i++)
    {
        if(process[i].alloc_mblock == -1)
        {
            printf("\t\t%d\t      %d\t   Not Allocated\n",process[i].p_no,process[i].psize);
        }
        
        else
        {
            printf("\t\t%d\t      %d\t        %d\n",process[i].p_no,process[i].psize,process[i].alloc_mblock);
        }
    }
    
    printf("\n");
}

void allocate_first_fit(struct pblock process[],struct mblock memory[])
{
    for(i = 0; i < total_process; i++)
    {
        for(j = 0; j < total_memory; j++)
        {
            if(memory[j].allocated == 0)
            {
                if(process[i].psize <= memory[j].msize)
                {
                    process[i].alloc_mblock = memory[j].block_no;
                    memory[j].allocated = 1;
                    break;
                }
            }
        }
    }
}

void allocate_best_fit(struct pblock process[],struct mblock memory[])
{
    int min_size,min_block_no,min_index;
    
    for(i = 0; i < total_process; i++)
    {
        for(j = 0; j < total_memory; j++)
        {
            if(memory[j].allocated == 0)
            {
                if(process[i].psize <= memory[j].msize)
                {
                   min_size = memory[j].msize;
                   min_block_no = memory[j].block_no;
                   min_index = j;
                   
                   for(k = j+1; k < total_memory; k++)
                   {
                       if(memory[k].allocated == 0)
                       {
                           if(process[i].psize <= memory[k].msize && min_size > memory[k].msize)
                           {
                               min_size = memory[k].msize;
                               min_block_no = memory[k].block_no;
                               min_index = k;
                           }
                       }
                   }
                   
                   process[i].alloc_mblock = min_block_no;
                   memory[min_index].allocated = 1;
                   break;
                }
            }
        }
    }
}

void allocate_worst_fit(struct pblock process[],struct mblock memory[])
{
    int max_size,max_block_no,max_index;
    
    for(i = 0; i < total_process; i++)
    {
        for(j = 0; j < total_memory; j++)
        {
            if(memory[j].allocated == 0)
            {
                if(process[i].psize <= memory[j].msize)
                {
                   max_size = memory[j].msize;
                   max_block_no = memory[j].block_no;
                   max_index = j;
                   
                   for(k = j+1; k < total_memory; k++)
                   {
                       if(memory[k].allocated == 0)
                       {
                           if(process[i].psize <= memory[k].msize && max_size < memory[k].msize)
                           {
                               max_size = memory[k].msize;
                               max_block_no = memory[k].block_no;
                               max_index = k;
                           }
                       }
                   }
                   
                   process[i].alloc_mblock = max_block_no;
                   memory[max_index].allocated = 1;
                   break;
                }
            }
        }
    }
}