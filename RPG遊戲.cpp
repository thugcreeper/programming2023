#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define monstertotal 3

typedef struct {
    char name[100];
    int level, hp, speed, atk, exp;
} PlayerData;//自訂玩家資料結構 

typedef struct {
    char name[20];  
    int hp, speed, atk, giveexp;
} MonsterData;

void initplayer(PlayerData *p) {//要修改值是call by reference 故要用指標接收地址 
	printf("請輸入玩家的名字：");
    fgets(p->name, sizeof(p->name), stdin);
    strtok(p->name, "\r\n");
    p->level = 1;//p是指標，若要修改結構內的某個資料要用-> 
    p->hp = rand() % 251 + 350;//%251產生0-250的亂數 
    p->speed = rand() % 16 + 35;
    p->atk = rand() % 21 + 40;
    p->exp = 0;
}

void initmonster(MonsterData *p) {
    strcpy(p->name, "半獸人"); //複製"半獸人"到name 
    p->hp = rand() % 21 + 150;
    p->speed = rand() % 16 + 35;
    p->atk = rand() % 11 + 20;
    p->giveexp = 15;
}
void printplayerdata(PlayerData p){
	printf("%s\n",p.name);
	printf("等級 %d, 體力 %d, 速度 %d, 攻擊力 %d, 經驗值 %d\n",p.level,p.hp,p.speed,p.atk,p.exp);
	
}
void printmonsterdata(MonsterData p){
	printf("( 體力 %d, 速度 %d, 攻擊力 %d, 提供經驗值 %d )\n",p.hp,p.speed,p.atk,p.giveexp);
	
}

void atk_p2m(PlayerData player,MonsterData monster){
	printf("%s攻擊，造成半獸人失血 %d 點。\n",player.name,player.atk); 
}

void atk_m2p(PlayerData player,MonsterData monster){
	printf("半獸人攻擊，造成%s失血 %d 點。\n",player.name,monster.atk); 
}
int main() {
    char input[100];  
    srand((unsigned)time(NULL));  

    PlayerData player;
    MonsterData monster[monstertotal];
	int i;
	initplayer(&player);
	for(i=0;i<monstertotal;i++)
		initmonster(&monster[i]);
	for(i=0;i<monstertotal;i++){
		printplayerdata(player);
		printf("\n");
		printf("\n碰到一隻半獸人！ ");
		printmonsterdata(monster[i]);
		if(monster[i].speed>player.speed){
			atk_m2p(player,monster[i]);
			player.hp -= monster[i].atk;
		}
		while(player.hp>0 && monster[i].hp>0){
			atk_p2m(player,monster[i]);
			monster[i].hp -= player.atk;
			if(monster[i].hp>0){
				atk_m2p(player,monster[i]);
				player.hp -= monster[i].atk;
			}
			else
				printf("%s死了。\n",monster[i].name);	
		}
		if(player.hp<=0){
			printf("%s死了。\n",player.name);
			break;
		}
		else{
			printf("%s獲得經驗值 %d。\n",player.name,monster[i].giveexp);
			player.exp+=monster[i].giveexp;
			printf("\n");
		}
	}
	printplayerdata(player);
	
    return 0;
}
