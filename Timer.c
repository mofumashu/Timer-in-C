//Timer - Mashu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int hour=0, min=0, sec=0, flag=0;

void Delay(ms){
    clock_t delay=ms + clock();
    while(delay>clock());
}

int counter(){
    while(!kbhit() && flag==0){
        if(min>59){
            min =0;
            ++hour;
        }if(sec>59){
            sec=0;
            ++min;
        }
        Data();
        Delay(1000);
        ++sec;
    }
    selec();
}

int selec(){
    switch(getch()){
        case 49: flag=0;
        break;
        case 50: flag=1;
        break;
        case 51: hour=min=sec=0;
                 flag=2;
                 Data();
        break;
        case 52: exit(0);
        break;
    }
}

int Data(){
    system("cls");
    printf("1. Start | 2. Pause | 3. Reset | 4. Exit\n");
    printf("****************************************\n");
    printf("                 %d:%d:%d",hour,min,sec);
    printf("\n****************************************");
}

main(){

    while(1){
        counter();
        Data(); 
    }
    
    return 0;
    
}
