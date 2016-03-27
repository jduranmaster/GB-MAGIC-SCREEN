//*****************************************
//		Magic Screen for GameBoy. 
// Programmed by jduranmaster a.k.a. Ryoga
//*****************************************
#include <gb/gb.h>
#include <stdio.h>
#include <ctype.h>
#include <gb/console.h>
#include <gb/drawing.h>

unsigned char x = 10;
unsigned char y = 10;
int drawing_control = 0;

void clscr();
void cursor();
void print_title();
void print_marquee();
void print_solid_marquee();
void print_message_INTRO();
void print_message_usage();
void print_messageAtXY(int x, int y, char *c);

int main(){
	
	print_marquee();
	print_title();
	print_message_INTRO();
	waitpad(J_START);
	
	clscr();
	print_solid_marquee();
	cursor();
	
	return 0;
}

void cursor(){
	
	gotoxy(10, 10);
	
	while(1){
		if(joypad() == J_UP){
			y--;
		}
		if(joypad() == J_DOWN){
			y++;
		}
		if(joypad() == J_LEFT){
			x--;
		}
		if(joypad() == J_RIGHT){
			x++;
		}
		if(joypad() == J_SELECT){
			clscr();
			print_solid_marquee();
			gotoxy(0,0);
		}
		if(joypad() == J_A){
			if(drawing_control == 0){
				drawing_control = 1;
				color(WHITE, WHITE, SOLID);
			}else{
				drawing_control = 0;
				color(BLACK, WHITE, SOLID);
			}
		}
		if(joypad() == J_B){
			if(drawing_control == 1){
				drawing_control = 0;
				color(BLACK, WHITE, SOLID);
			}else{
				drawing_control = 1;
				color(WHITE, WHITE, SOLID);
			}
		}
		if(joypad() == J_START){
			clscr();
			print_marquee();
			print_title();
			print_message_usage();
			waitpad(J_START);
	
			clscr();
			print_solid_marquee();
			cursor();
		}
		
		plot_point(x,y);
		delay(35);
	}
}

void print_marquee(){
	gotoxy(0, 0);
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(154,138,4,4,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void print_solid_marquee(){
	gotoxy(0, 0);
	color(BLACK, WHITE, SOLID);
	box(156,140,2,2,M_NOFILL);
	box(155,139,3,3,M_NOFILL);
	box(154,138,4,4,M_NOFILL);
	box(153,137,5,5,M_NOFILL);
	box(152,136,6,6,M_NOFILL);
}

void print_messageAtXY(int x, int y, char *c){
	gotogxy(x,y);
	gprintf(c);
}

void print_title(){
	print_messageAtXY(4,1,"Magic Screen");
}

void print_message_usage(){
	print_messageAtXY(1,3,"Controls:");
	print_messageAtXY(1,4,"");
	print_messageAtXY(1,5,"A - EN. cursor");
	print_messageAtXY(1,6,"B - DIS. cursor");
	print_messageAtXY(1,7,"SELECT - Erase SCR");
	print_messageAtXY(1,8,"START - HOW TO...");
	print_messageAtXY(4,11,"PRESS START!");
	print_messageAtXY(8,14,"2014");
	print_messageAtXY(4,15,"Programmed by");
	print_messageAtXY(8,16,"Ryoga");
}

void print_message_INTRO(){
	print_messageAtXY(1,3,"This is a homebrew");
	print_messageAtXY(1,4,"software for the");
	print_messageAtXY(1,5,"Game Boy console.");
	print_messageAtXY(1,6," ");
	print_messageAtXY(1,7,"Controls:");
	print_messageAtXY(2,8,"A - EN. cursor");
	print_messageAtXY(2,9,"B - DIS. cursor");
	print_messageAtXY(4,11,"PRESS START!");
	print_messageAtXY(8,14,"2014");
	print_messageAtXY(4,15,"Programmed by");
	print_messageAtXY(8,16,"Ryoga");
}

void clscr(){
	int x, y;
	
  	for(y = 0; y < 20; y++){
    	for(x = 0; x < 30; x++){
      		gotoxy(x, y);
      		gprintf(" ");
		}
	}
	gotoxy(0,0);
}