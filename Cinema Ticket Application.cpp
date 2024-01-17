#include <stdio.h>
#include <string.h>
#include<time.h>
const int I = 10;
float movie ();

void displayMovie();
void login();
void signup();
void search();
float fnb();
void food();
void beverage();
float merch ();
float calculateDiscount(float); 
float displayMerchandiseSet(int);

char movielist[I][30] = {"Evil Dead Rise", "Imaginur" }, username[I][20] = {"t"}, displayname[20];
float movieprice[I] = {20.50, 18}, foodprice[I] = {6.00, 7.50, 3.50, 9.50, 19.00, 22.00};
int password[I] = {1234}, totalMovie = 2, newuser=1, totalFnb = 6, qty[10], cartcounter, itemcount;
char foodlist[I][30] = {"Popcorn","Nachos","Chips", "1x Popcorn + 1x Drink","2x Popcorn + 2x Drinks","2x Nachos + 2x Drinks"};
char bevlist[I][30] = {"Coke","Lemon Tea", "Mineral", "Latte", "Cappucino", "Mocha" }, cart[11][30];
float bevprice[I] = {3.50, 3.50, 2.00, 7.00, 7.00, 7.00}, fnbprice=0, cartprice[10];
	
int main ()
{
	int nav;
	float total1=0, total2=0, total3=0;
	printf("\n\t**********------------------------------***********");
	printf("\n\t\t\tWelcome to CTA Cinemas\n\t----------------------------------------------------");
	printf("\n\n\t[1]\tLogin\n\t[2]\tSign Up\n\n\tEnter a number: ");
	scanf("%d", &nav);
	while (nav != 1 && nav != 2)
	{
		printf("\n\tInvalid menu. Please enter again.");
		printf("\n\n\t[1]\tLogin\n\t[2]\tSign Up\n\n\tEnter a number: ");
		scanf("%d", &nav);
	}
	if ( nav == 1)
	{
		login();
		total1 += movie(); //return the price for movie ticket
		total2 += fnb();
		total3 += merch();
		printf("\n\n\t******************************************\n\t\t\tCTA Cinemas\n");
		printf("\tAddresdfhcn");
		printf("\n\n\t\tFinal Receipt");
		printf("\n\n\tMovie Ticket\t\t\tRM %8.2f\n\tFood and Beverages\t\tRM %8.2f\n\tMerchandise\t\t\tRM %8.2f", total1, total2, total3);
		printf("\n\n\tTOTAL\t\t\t\tRM %8.2f", total1 + total2 + total3);
	}
		
	else
		signup();
	return 0;
}
void login()
{
	int i=-1, x, password0;
	char username0[20];
	printf("\n\t\t------------------------------------\n\t\t\t   Login Page\n\t\t------------------------------------");
	printf("\n\n\tEnter username: ");
	scanf("%s", username0);
	do
	{
		i++;
		x = strcmp(username[i], username0);		
	} while ( (i<I) && ( x != 0 ) );
	if (x == 0) //USERNAME EXIST
	{
		password0 = 0;
		printf("\tEnter password: ");
		scanf("%d", &password0);
		if (password0 == password[i])
		{
			printf("\n\t\t\tLogin success ^-^\n"); //PASSWORD MATCHED
			strcpy(displayname, username[i]);
		}
		else 
		{
			printf("\n\t\t\tWrong password -_-\n");
			main();
		}
	}
	else
	{
		printf("\n\t\tUser does not exist +.+\n");
		main();
	}
}
void signup()
{
	printf("\n\t----------------------------------------\n\t\tNew Members Registration\n\t----------------------------------------");
	printf("\n\n\tEnter new username: ");
	scanf("%s", username[newuser]);
	printf("\tEnter 4 digit password: ");
	scanf("%d", &password[newuser]);
	printf("\n\tPlease login again using your new account...\n");
	newuser++;
	login();
}

float movie()
{
	int nav, movieNo, ticket=0, settings, i = 0, j, showtime;
	float ticketprice=0;
	
	printf("\n\n\t----------------------------------------------------\n\t\t\t");
	printf("CTA TICKET COUNTER\n\t----------------------------------------------------");
	printf("\n\n\t[1]\tBuy Ticket\n\t[2]\tMovie Settings\n\t[3]\tSearch Movie\n\n\tEnter a number: ");
	scanf("%d", &nav);
	while (nav != 1 && nav != 2 && nav != 3)
	{
		printf("\n\tInvalid menu. Please enter again.");
		printf("\n\n\t[1]\tBuy Ticket\n\t[2]\tMovie Settings\n\t[3]\tSearch Movie\n\n\tEnter a number: ");
		scanf("%d", &nav);
	}
	
	switch (nav)
	{
		case 1: //buy ticket
		
			do
			{
				displayMovie();
				printf("\n\n\tEnter a number: ");
				scanf("%d", &movieNo);
				fflush(stdin);
			} while (movieNo < 0 || movieNo > totalMovie ); //loop until user enter valid movie

			printf("\n\n\tMovie selected: [%s]", movielist[movieNo-1]);
			printf("\n\tEnter the number of tickets: ");
			scanf("%d", &ticket);
			ticketprice += ticket*movieprice[movieNo-1]; //ticket pricing
			printf("\n\t-------------------------------------------------");
			printf("\n\tYou are purchasing %d ticket(s) for %s\n", ticket, movielist[movieNo-1]);
			printf("\tTotal ticket price: RM %.2f", ticketprice);
			printf("\n\n\tPress [1] to CONFIRM PURCHASE or any digit to CANCEL.");
			printf("\n\tEnter a number: ");
			scanf("%d", &nav);
			
			if (nav == 1) //print ticket
			{
				time_t t = time(NULL);
				struct tm tm = *localtime(&t);
				printf("\n\n\t******************************************\n\t\t\tCTA Cinemas\n");
				printf("\n\t\t||||| ||| ||||| || ||||| ||");
				printf("\n\n\tHALL NAME\tHALL %d\n\tMOVIE TITLE\t%s", movieNo, movielist[movieNo-1]);

				printf("\n\tSHOW DATE\t%02d/%02d/%d",tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
				printf("\n\tSHOW TIME\t%04d\n\tTICKET FOR\t%d", (tm.tm_hour + 1 )*100, ticket);
				printf("\n\n\t-----------------------------------------\n");
				break;
			}
			else //cancel purchasing, directing back to prev page
			{
				printf("\nThe purchase of %d ticket(s) for %s has been canceled.\n\n", ticket, movielist[movieNo-1]);
				do
				{
					printf("\n\n\t[1] Browse Movie\t[2] CTA Cafe");
					printf("\n\tEnter a number: ");
					scanf("%d", &nav);
					if (nav==1)
						movie();
					else if (nav ==2)
						break;
					else
						printf("\n\tInvalid input. Please re-enter.");	
				} while (nav < 0  || nav > 3);
			}
			break;	
		
		
		case 2: //movie settings
		{
		
			displayMovie();
			printf("\n\n\t[0]\t+ new movie");
			do
			{
				printf("\n\n\tSelect a number: ");
				scanf("%d", &settings);
			} while (settings < 0 || settings > totalMovie);
			fflush(stdin);
			
			printf("\n\t----------------------------------------");
			if ( settings == 0) //add new movie
			{
				printf("\n\n\tTitle: ");
				gets( movielist[totalMovie]);
				printf("\n\tPrice: RM ");
				scanf("%f", &movieprice[totalMovie]);
				totalMovie++;
			}
			else //movie selected
			{
				printf("\n\t[1] Edit\t\t[2] Delete");
				printf("\n\tChoose an action: ");
				scanf("%d", &nav);
				if ( nav == 1) //edit
				{
					printf("\n\n\t----------------------------------------");
					printf("\n\n\t\t\tMovie Info");
					printf("\n\n\tTITLE:\t%s\n\tPRICE:\tRM %.2f", movielist[settings-1], movieprice[settings-1] );
					printf("\n\n\t[1] Edit Title\t\t[2] Edit Price\n\tChoose an action: ");
					scanf("%d", &nav);
					while ( nav != 1&& nav != 2)
					{
						printf("Invalid action. Please enter again.");
						printf("\n\n\t[1] Edit Title\t\t[2] Edit Price\n\tChoose an action: ");
						scanf("%d", &nav);
					}
					fflush(stdin);
				
					if (nav == 1) //edit title
					{
						printf("\n\tNew Title: ");
						gets(movielist[settings-1]);
					}
					else if (nav == 2) //edit price
					{
						printf("\n\tNew Price: RM");
						scanf("%f", &movieprice[settings-1]);
					}
				}
				else if (nav == 2) // delete movie
				{
					printf("\nDeleting [%s]......", movielist[settings-1]);
					printf("\n\n\t[1] Confirm\t[2] Cancel");
					printf("\n\tChoose an action: ");
					scanf("%d", &nav);
					if (nav == 1)
					{
						for (i = settings-1; i < totalMovie-1; i++) // process of deleting the element in an array and update index
						{
							strcpy(movielist[i], movielist[i+1]);
							movieprice[i] = movieprice[i+1];
						}	
						totalMovie--;
						printf("\nDeleting success...");
					}
				}
			}
			printf("\n\n\t\t\t  Updated Movie List"); // display new or current list of movies 
			for (int i=0; i<totalMovie; i++)
			{	
				printf("\n\n\t\t%-25s", movielist[i]);
				printf("\tRM %.2f", movieprice[i]);
			}
			do
			{
				printf("\n\n\t[1] Browse Movie\t[2] CTA Cafe");
				printf("\n\tEnter a number: ");
				scanf("%d", &nav);
				if (nav==1)
					movie();
				else if (nav ==2)
					break;
				else
					printf("\n\tInvalid input. Please re-enter.");	
			} while (nav < 0  || nav > 3);
			break;
		}
		case 3:
		{
			search();
			do
			{
				printf("\n\n\t[1] Browse Movie\t[2] CTA Cafe");
				printf("\n\tEnter a number: ");
				scanf("%d", &nav);
				if (nav==1)
					movie();
				else if (nav ==2)
					break;
				else
					printf("\n\tInvalid input. Please re-enter.");	
			} while (nav < 0  || nav > 3);	
		}					
	}
	return ticketprice;
}
void displayMovie()
{
	printf("\n\n\t\t----------------------------------------\n\t\t\t\t***MOVIE***\n\t\t----------------------------------------\n");
	for (int m=0; m<totalMovie; m++)
	{
		printf("\n\t[%d]\t%-30s\tRM %.2f", m+1, movielist[m], movieprice[m]);	
	}
}
void search()
{
	int i, x, nav;
	char searchmovie[50];
	fflush(stdin);
	printf("\n\t\tType a movie name:\t");
	gets(searchmovie);
	printf("\n\n\t----------------------------------------\n");
	i=-1;
	do
	{
		i++;
		x = strcmp(searchmovie, movielist[i]);
	} while ( x!=0 && i<totalMovie);
	if ( x==0)
	{
		printf("\n\tWe found [%s]!\n", searchmovie);
		printf("\n\tHere are the details>>\n\n\t HALL %d\t%s\t\tRM %.2f ", i+1, movielist[i], movieprice[i]);					
	}
	else
	{
		printf("\n\tWe cannot find [%s]", searchmovie);
		printf("\n\tMake sure the spelling is correct.");
	}
	do
	{
		printf("\n\n\t[1] Keep Searching\t\t[2] Back");	
		printf("\n\n\tEnter a number: ");
		scanf("%d", &nav);
	} while ( nav != 1 && nav != 2);
	
	if (nav == 1)
		search();
}
float fnb()
{
	int choice, i;
	
	printf(" \n ---------------------------------------------------------------------------");
	printf("\n|\t\t\t  Welcome To CTA Cinema Cafe\t\t            |");
	printf("\n ---------------------------------------------------------------------------");
	do
	{
		printf("\n\n\t[1] Food\t\t[2] Beverage\t\tPress [0] to exit");
		printf("\n\n\tSelect your Choice: ");
		scanf("%d", &choice);
	} while ( choice < 0 && choice > 2);
	
	if (choice == 1)
		food();
	else if (choice == 2)
		beverage();
	if (fnbprice==0)
	{
		do
		{
			printf("\n\n\t[1] Back to Food & Beverage\t\t[2] Go to Merchandise");
			printf("\n\n\tEnter a number: ");
			scanf("%d", &choice);
			if ( choice == 1)
				fnb();
			else if ( choice == 2)
				merch();
		} while (choice != 1 && choice != 2);
		
	}
	else
	{
		printf("\n\t*****************************************************\n\t\t\t\tCTA CAFE\n\n");
		for (i=0; i<cartcounter; i++)
		{
			printf("\t%-27s%2dx   %5.2f\t\t%5.2f\n\n",cart[i], qty[i], cartprice[i]/qty[i], cartprice[i] );
			itemcount += qty[i];
		}
		printf("\t-----------------------------------------------------\n");
		printf("\n\tItem count\t\t\t\t\t%5d", itemcount);
		printf("\n\tTotal Sales\t\t\t\t\tRM %5.2f", fnbprice);
		printf("\n\t*****************************************************");
	}	
	
	return fnbprice;
}
void food()
{
	int choice, next, i;
	char yn;

	printf(" \n\n    ---------------------------------------------------------------------\n\t\t\t\t    Food");
	printf(" \n    ---------------------------------------------------------------------\n");
	for ( i=0; i<6; i++) //display all menu
		printf("\n\t\t[%d] %-27s RM %5.2f", i+1, foodlist[i], foodprice[i]);
	printf("\n\n     ---------------------------------------------------------------------");
	
	while (cartcounter < 10) //max type of items that can be ordered is 10
	{
		do {
			printf("\n\n\t Select your Choice: ");
			scanf("%d", &choice);
		} while (choice < 1 || choice > 6);	
		
		strcpy(cart[cartcounter], foodlist[choice-1]);
		printf("\n\t Enter the quantity: ");
		scanf("%d", &qty[cartcounter]);
		cartprice[cartcounter] = qty[cartcounter]*foodprice[choice-1];
		fnbprice += cartprice[cartcounter];
		printf("\n\nAdd more item? (y/n): ");
		scanf(" %c", &yn);
		cartcounter++;
		if (yn == 'n')
			break;
	}
	do
	{
		printf("\n\t-------------------------------------");
		printf("\n\n\t[1] Add Drinks\t[2] Place Order");
		printf("\n\n\tSelect your Choice: ");
		scanf("%d", &next);	
		if (next == 1)
			beverage();
		else if (next == 2)
			break;
	} while (next !=1 && next != 2);
}
void beverage()
{
	char yn;
	int choice, i, next;
		
	printf(" \n\n    ---------------------------------------------------------------------");
	printf("\n\t\t\t           Beverage");
	printf(" \n    ---------------------------------------------------------------------\n\n");
	
	for ( i=0; i<6; i++) //display all drinks
		printf("\n\t[%d]\t%-20sRM %4.2f", i+1, bevlist[i], bevprice[i]);
	printf(" \n    ---------------------------------------------------------------------");
	while (cartcounter < 10)
	{
		do
		{	printf("\n\n\t Select your Choice: ");
			scanf("%d", &choice);	
		}	while (choice < 1 || choice > 6);
		
		strcpy(cart[cartcounter], bevlist[choice-1]);
		printf("\n\t Enter the quantity: ");
		scanf("%d", &qty[cartcounter]);
		cartprice[cartcounter] = qty[cartcounter]*bevprice[choice-1];
		fnbprice += cartprice[cartcounter];
		printf("\n\nAdd more item? (y/n): ");
		scanf(" %c", &yn);
		cartcounter++;
		if (yn == 'n')
			break;
	}
	do
		{
			printf("\n\t-------------------------------------");
			printf("\n\n\t[1] Cancel Order and Exit\t[2] Place Order");
			printf("\n\n\tSelect your Choice: ");
			scanf("%d", &next);	
		
			if (next == 1 )
				fnbprice = 0;
			else if (next != 2)
				printf("\n\n\tInvalid input. Please re-enter");
				
		} while (next !=1 && next != 2);

}
float merch()
{
	int numSets = 0, nav;
    char choice = 'y', dis, welc, sets, set;
    float totalPrice = 0.00; 
    
    printf("\n\n\t\t\t------------------------------------------\n\n ");
    printf("\t\t\t WELCOME TO CTA CINEMA MERCHANDISE CENTER");
    printf("\n\n\t\t\t------------------------------------------\n\n ");
 
    printf("---------------------\t\t---------------------\t\t---------------------");
    printf("\n SET [1]- RM 25.00\t\t  SET [2]- RM 30.00\t\t SET [3]- RM 70.00\n\n");
    printf("\tMug\t\t\tExclusive Water Bottle\t\t\tShirts\n ");
    printf("\tHat\t\t\t     Keychain\t\t\t     Action Figures\n");
    printf("---------------------\t\t---------------------\t\t---------------------");
    printf("\n\n\t\t                        BIG OFFER!                                \n ");
    printf("\t\t  When you purchase above RM 50,you get 5 percent discounts       \n");
    printf("\t\tWhen you purchase above RM 100, you get up to 10 percent discounts\n ");
    printf("\n\t\t------------------------------------------------------------------\n\n");
    
    while (choice == 'y')
	{
        int set;
        printf("\n     ENTER WHICH SET YOU WANT TO PURCHASE (1, 2, 3):          ");
        scanf("%d", &set);

        float price = displayMerchandiseSet(set); // Function call
        
        	if (price > 0)
			{
           		numSets++;
            	totalPrice += price;
        	}
        	printf("\nAdd another set? (y/n):\t");
        	scanf(" %c", &choice);
    }

    	printf("\n     CALCULATING TOTAL...           \n");
    	printf("     You purchased %d set(s).           \n\n", numSets);
   		printf("     Total price\t\t\t:\t  RM %5.2f\n\n ", totalPrice);
    // Calculate and apply discount
   		float discount = calculateDiscount(totalPrice);
    	if (discount > 0.00) 
		{
        	float discountPercentage = (discount / totalPrice) * 100.00;
        	printf("    Discount applied (%.2f%%)\t\t:\t- RM %5.2f\n", discountPercentage, discount);
        	totalPrice -= discount;
    	}
    	else 
			printf("    No discount applied.         \n");
    	printf("     Final price (after discount)\t:\t  RM %5.2f\n", totalPrice);
   		printf("\n\n\t----------------------------------------");
	
 	return totalPrice;   	
}
float calculateDiscount(float totalPrice) 
{
    float discount = 0.00;
    if (totalPrice >= 100.00) 
        discount = 0.10 * totalPrice; // 10% discount
	else if (totalPrice >= 50.00)
        discount = 0.05 * totalPrice; // 5% discount
        
    return discount;
}
float displayMerchandiseSet(int set) 
{
    float price;
    
    if (set == 1) {
        printf("\n\t\t[ YOU CHOSE CINEMA SHOP MERCHANDISE SET 1]\n");
        printf("\n\t\t\t[               MUGS AND HATS            ]\n");
        price = 25.00;

    } else if (set == 2) {
        printf("\n\t[YOU CHOSE CINEMA MOVIE MERCHANDISE SET 2]\n");
        printf("\t[  EXCLUSIVE WATER BOTTLE AND KEYCHAIN   ]\n");
        price = 30.00;

    } else if (set == 3) {
        printf("\n\t[YOU CHOSE CINEMA MOVIE MERCHANDISE SET 3]\n");
        printf("\t[     SHIRTS AND ACTION FIGURES          ]\n");
        price = 70.00;

    } else {
        printf("Invalid set.\n");
        price = 0.00;
    }
    
    return price;
}

