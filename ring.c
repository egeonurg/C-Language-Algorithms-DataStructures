#include<stdio.h>
#define size 10

//Ring buffer basic construction and test 
// Ege Onur GÜL 


	int ring_buff[size] ={12,14,91,95,15,0,2,4,42} ; 
	int read_counter= 0 ; 
	int write_counter=0 ; 
	int i = 0 ; 
	int ret_val = 0  ; 
	int data = 0 ; 


int ring_read()
	{
			if(read_counter<size-1) // size-1 would be write register's position it will read until the position of write register 
			
				{
				
						ret_val = *(ring_buff + read_counter ); 
						*(ring_buff + read_counter ) = 0  ; 		
						read_counter ++ ; 
				
							return(ret_val) ; 	
				}
			
			else
			
				{
				
						read_counter = 0 ; 
			
						ret_val = *(ring_buff + read_counter ); 
			
						read_counter	 ++ ; 
				
							return(ret_val) ; 	
				}
	}
	
	
int ring_write(int data)

	{	
		
		
			if(write_counter<size-1)
				
				{				
					*(ring_buff + write_counter) = data ; 
					
					write_counter ++ ; 
				}
		
		
			else
		
				{				
					write_counter = 0 ; 
				
					*(ring_buff + write_counter) = data ; 
					
					write_counter ++ ; 
				}
		
		
		
	}
	
	
	
	


	
	
	int main()
		{
			
				for(i=0 ; i<3; i++)
					{
						scanf("%d",&data);
						ring_write(data) ; 
					}
				
				for(i=0 ; i<size-1; i++)
					{
						printf("%d\n",ring_read()); 
					}
		
		}
