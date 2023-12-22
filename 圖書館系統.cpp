#include<stdio.h> 
#include<string.h>
typedef struct {
    char borrowerID[12], name[20];
    int count;
} BorrowerInfo;

typedef struct {
    char bookID[12], title[80], author[80];
    int count;
} BookInfo;

typedef struct {
    int year, month, day;
} DateInfo;

typedef struct {
    BorrowerInfo *borrower;
    BookInfo *book;
    DateInfo borrowDate, dueDate, returnDate;
} CirculateInfo;

void print(){
	printf("\nMenu of NTOU CSE Library Circulation System\n");
	printf(" 1. Borrow a book.\n");
 	printf(" 2. Return a book.\n");
 	printf(" 3. Print all the borrowers.\n");
 	printf(" 4. Print all the books.\n");
 	printf(" 5. Print all the circulation records.\n");
 	printf(" 6. Add a new borrower.\n");
 	printf(" 7. Add a new book.\n");
 	printf(" 8. Find top-1 popular books of a year.\n");
 	printf(" 9. Find top-1 borrowers of a year.\n");
 	printf("10. Create a monthly table of circulations of a year.\n");
 	printf(" 0. Exit.\n");
 	printf("Please choose one action: ");
}
int main(){
	BookInfo book[50];
	BorrowerInfo borrower[20];
	CirculateInfo record[200];
	int bookTotal = 0, borrowerTotal = 0, recordTotal = 0,action=-1;
	
 	while(action != 0){	
	 	print();
 		scanf("%d",&action);if (getchar() == '\r') getchar();
 		if(action==1){
			char tempid[100],tempbook[100];//站存borrower id、book id 
	    	printf("Input the borrower ID: ");fgets(tempid, sizeof(tempid), stdin);
	    	strtok(tempid, "\r\n");
			int falseborrower=1;//a flag to distinguish borrower
			for(int i=0;i<borrowerTotal;i++){
				if(strcmp(tempid,borrower[i].borrowerID)==0){
					falseborrower=0;
					record[recordTotal].borrower=&borrower[i];
				}
			}
			if(falseborrower)//if not equal to 0,do the statesment
				continue;
			printf("Input the book ID: ");
			fgets(tempbook, sizeof(tempbook), stdin); 
			strtok(tempbook, "\r\n");
			int falsebook=1;
			for(int i=0;i<bookTotal;i++){
				if(strcmp(tempbook,book[i].bookID)==0)
				{		
					falsebook=0;
					record[recordTotal].book = &book[i];
					printf("Input the borrowing date (year/month/day): ");
					scanf("%d/%d/%d",&record[recordTotal].borrowDate.year,&record[recordTotal].borrowDate.month,&record[recordTotal].borrowDate.day);				
					printf("Input the due date (year/month/day): ");
					scanf("%d/%d/%d",&record[recordTotal].dueDate.year,&record[recordTotal].dueDate.month,&record[recordTotal].dueDate.day);
					record[recordTotal].returnDate.year=0;
					record[recordTotal].returnDate.month=0;
					record[recordTotal].returnDate.day=0;
					printf("A circulation record has been created.");
					recordTotal++;
				}
			}
			if(falsebook)
				continue;
			}
		else if(action == 2){
			char tempid[100],tempbook[100];//站存borrower id、book id 
	    	printf("\nInput the borrower ID: ");
			fgets(tempid, sizeof(tempid), stdin);
	    	strtok(tempid, "\r\n");	
			printf("Input the book ID: ");
			fgets(tempbook, sizeof(tempbook), stdin);
			strtok(tempbook, "\r\n");
			int allfalse=1;
	    	for(int j=0;j<recordTotal;j++){
				if(strcmp(tempid,record[j].borrower->borrowerID)==0&&strcmp(tempbook,record[j].book->bookID)==0){
					allfalse=0;							
					printf("Input the returning date (year/month/day): ");
					scanf("%d/%d/%d",&record[j].returnDate.year,&record[j].returnDate.month,&record[j].returnDate.day);
					if (getchar() == '\r') getchar();
			    	printf("A book has been returned.\n");	
					break;
				}
			}
			if(allfalse)
				continue;
		}
		else if(action == 3){//print borrower
			printf("\nData of all borrowers:\n");
			for(int i=0;i<borrowerTotal;i++){
				printf("Borrower ID: %s, Name: %s\n", borrower[i].borrowerID, borrower[i].name);
			}
		}
		else if(action == 4){//print book
			printf("\nData of all books:\n");
			for(int i=0;i<bookTotal;i++){
				printf("Book ID: %s\n", book[i].bookID);
				printf(", title: %s\n", book[i].title);
				printf("authors: %s\n",book[i].author);
			}
		}
		else if(action == 5){
			printf("\nData of all circulation records:\n");
			for(int i=0;i<recordTotal;i++)
				printf("%s	%s	%d/%d/%d	%d/%d/%d	%d/%d/%d",record[i].borrower->borrowerID, record[i].book->bookID,record[i].borrowDate.year, record[i].borrowDate.month, record[i].borrowDate.day, record[i].dueDate.year,record[i].dueDate.month,record[i].dueDate.day,record[i].returnDate.year,record[i].returnDate.month,record[i].returnDate.day);
		}
		else if(action == 6){
			printf("\nBorrower ID: ");	fgets(borrower[borrowerTotal].borrowerID, sizeof(borrower[borrowerTotal].borrowerID), stdin);
			strtok(borrower[borrowerTotal].borrowerID, "\r\n");
			printf("Borrower Name: ");fgets(borrower[borrowerTotal].name, sizeof(borrower[borrowerTotal].name), stdin);
			strtok(borrower[borrowerTotal].name, "\r\n");
			borrowerTotal++;
		}
		else if(action == 7){
			printf("\nBook ID: ");	fgets(book[bookTotal].bookID, sizeof(book[bookTotal].bookID), stdin);
			strtok(book[bookTotal].bookID, "\r\n");
			printf("Book title: ");fgets(book[bookTotal].title, sizeof(book[bookTotal].title), stdin);
			strtok(book[bookTotal].title, "\r\n");
			printf("Authors: ");fgets(book[bookTotal].author, sizeof(book[bookTotal].author), stdin);
			strtok(book[bookTotal].author, "\r\n");
			bookTotal++;
		}
		else if (action == 8) {//find popular book
		    int year;
		    printf("Which year? ");
		    scanf("%d", &year);
		    for (int i = 0; i < bookTotal; i++)
		        book[i].count = 0;
		    for (int i = 0; i < recordTotal; i++) {
		        if (year == record[i].borrowDate.year) {
		            record[i].book->count++;
		        }
		    }		
		    int max = book[0].count;
		    for (int i = 1; i < bookTotal; i++) {
		        if (book[i].count > max) {
		            max = book[i].count;
		        }
		    }
		    printf("Data of all books:\n");
		    for(int i=0;i<bookTotal;i++){
		    	printf("The book [%s] has been borrowed %d time(s).\n",book[i].bookID, book[i].count);
			}
		    printf("\n--------------------------------------\n");
		    printf("Top-1 popular books in %d are:\n", year);
		    for(int i=0;i<bookTotal;i++){
		    	if(book[i].count==max)//Print out all book which are tied for first place 
					printf("The book [%s] has been borrowed %d time(s).\n",book[i].bookID, max);
			}
		    
		}
		else if (action == 9) {//find borrow king
		    int year;
		    printf("Which year? ");
		    scanf("%d", &year);
		    for (int i = 0; i < borrowerTotal; i++)
		        borrower[i].count = 0;
		    for (int i = 0; i < recordTotal; i++) {
		        if (year == record[i].borrowDate.year) {
		            record[i].borrower->count++;
		        }
		    }		
		    int max2 = borrower[0].count;
		    for (int i = 1; i < borrowerTotal; i++) {
		        if (borrower[i].count > max2) {
		            max2 = borrower[i].count;
		        }
		    }
		    printf("Data of all borrowers:\n", year);
		    for(int i=0;i<borrowerTotal;i++){
		    	printf("Borrower %s [%s] has borrowed %d book(s).\n",borrower[i].name, borrower[i].borrowerID, borrower[i].count);
			}
		    printf("\n--------------------------------------\n");
		    printf("Top-1 borrowers in 2023 are:\n");
		    for(int i=0;i<borrowerTotal;i++){
		    	if(borrower[i].count==max2)//Print out all borrower who are tied for first place
					printf("Borrower %s [%s] has borrowed %d book(s).\n",borrower[i].name, borrower[i].borrowerID, max2);
			}
		}
		else if(action ==0){
			printf("\nThanks for using NTOU CSE Library Circulation System!!");
		}
		else
			printf("error");
	}
	
	return 0;
}
