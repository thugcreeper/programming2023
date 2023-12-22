#include<stdio.h>
#include<string.h>

typedef struct {//自訂struct叫做fishdata 
    char name[20];
    char acname[40]; // 學名
    int length, weight;
    char environment;
} FishData;

void print(FishData fish) {
    printf("%s ", fish.name);
    printf("(%s): ", fish.acname);
    printf("average length %dcm,", fish.length);
    if (fish.weight != -1) {
        printf(" average weight %dg, ", fish.weight);
    }
	if(fish.environment == 'S') printf("seawater fish.\n"); 
	else if(fish.environment == 'F')printf("freshwater fish.\n");
}

int main() {
	FishData fish[10]={
				 {"Milk Fish","Chanos chanos",40,300,'S'},{"Black King Fish","Rachycentron canadum",150,40000,'S'},
				 {"Grass carp","Ctenopharyngodon idella	",150,35000,'F'},{"Gold Head Cichlid","Aulonocara baenschi",15,-1,'F'},
				 {"Ocellaris clownfish","Amphiprion ocellaris",4,-1,'S'},
				 };

    printf("Welcome to the NTOU Marine Education Encyclopedia!\n");

    char inputfish[20];
    while (1) {
        printf("\nInput the name of fish (\"quit\" to exit): ");
        fgets(inputfish, sizeof(inputfish), stdin);
		strtok(inputfish,"\r\n");//吃掉換行 
        inputfish[strcspn(inputfish, "\n")] = '\0';
        if (strcmp(inputfish, "quit") == 0) {//若字串=quit就退出 
        	printf("\nThank you for using the NTOU Marine Education Encyclopedia!");
            break;
        }
        if (strcmp(inputfish, fish[0].name) == 0) //strcmp比較陣列，若fish>f1namec會傳1，反之傳-1，相等傳0 
            print(fish[0]);
		else if (strcmp(inputfish, fish[1].name) == 0) 
            print(fish[1]);
		else if (strcmp(inputfish, fish[2].name) == 0) 
            print(fish[2]);
		else if (strcmp(inputfish, fish[3].name) == 0) 
            print(fish[3]);
		else if (strcmp(inputfish, fish[4].name) == 0) 
            print(fish[4]);
		else 
            printf("Sorry, we cannot find [%s] in our database.\n",inputfish);
    }

    return 0;
}


