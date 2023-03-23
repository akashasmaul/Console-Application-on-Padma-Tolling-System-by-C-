package PadmaToll;

public class Proccess extends tax {
	static {
		System.out.println("\t\tWelcome to Padma Toll Plaza");
		System.out.println("\t\tDate: "+tax.date+"\n");
			}
	tax bd[];
	   
	   int count_t=0,choice,temp;
	   int hd_cost=0,md_cost=0,ld_cost=0,i;
	   int op;
	   
	   void toll() {
		   System.out.print("1.Heavy Duty\n2.Medium Duty\n3.Light Duty\n");
			System.out.print("\tSelect Vehicle type: ");
			this.choice  = cin.nextInt();
			if (choice==1)
		       {
				addcar();
				for( i=0; i<count_t ; i++)
				{
					bd[count_t]=new tax();
					count_t++;
					i++;
					
				}
               this.hd_cost +=700;
               this.count_t++; //this keep on increasing counts the total number of vehicle1
              
		       }
			else if (choice==2) {
				addcar();
				for( i=0; i<count_t ; i++)
				{
					bd[i]=new tax();
				}
		                   this.md_cost += 400;
		                   count_t++;
							}
		                   
			else if (choice==3) {
				addcar();
				for( i=0; i<count_t ; i++)
				{
					bd[i]=new tax();
				}
		                   this.ld_cost +=200;
		                   count_t++;
		                     }
			else {
				System.out.println("\tWrong input, try again: ");
				toll();
			}
	   }
	   
	void host(){
		System.out.print("\tMain Menu\n");
		System.out.print("\n1.Procced to Toll\n2.Search Vehicle\n3.Toll collection \n0.Exit \n");
		System.out.print("\tSelect option: ");
		this.op  = cin.nextInt(); 
		if (op==1) 
		{
			toll(); 
			host();
		}
		else if (op==2) {
			System.out.print("Enter the Reg no: ");
			int x  = cin.nextInt();

            for( i=0; i<count_t ; i++)
            {
                if(bd[i].searchcar(x)) //searches each element
                {
                    bd[i].printdetails();
                    break; //if element found loop breaks
                }
            }
            if(i>=count_t) //if total number of car exceeds then car number is found
            	System.out.println("No match found!");
        
            host(); }
		else if (op==3) {
			System.out.print("\n1.Heavy Duty\n2.Medium Duty\n3.Light Duty\n4.Total\n\t :"); //prints the total Toll collection
			int temp = cin.nextInt();
            if(temp==1)
            {
            	System.out.println("Total Heavy Duty Toll collection: "+hd_cost);
            	host();
            }
            	
            else if(temp==2)
            {
            	System.out.println("Total Medium Duty Toll collection: "+md_cost);
            	host();
            }            	
            else if(temp==3)
            {
            	System.out.println("Total Light Duty Toll collection: "+ld_cost);
            	host();
            }             	
            else if(temp==4)
            {
            	System.out.println("Total Toll collection: "+ld_cost+md_cost+hd_cost);
            	host();
            }             	 
            else
            	System.out.println("Enter a correct choice!\n");
            host(); }
		else if (op==0) 
		{
			System.out.println("Exiting!");
			System.exit(0);
		}
		else {
			System.out.println("\tEnter a correct choice!\n");
			host();
		}
}
}
//