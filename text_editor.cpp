#include<iostream>
#include<string>

const int MAX_LINES=30;
std::string textlines[MAX_LINES];
int linecount=0;

void getinput() {
    std::cout<<"enter lines of text (enter 'done' to finish ):\n";
    std::string line;
    while(linecount < MAX_LINES && std::getline(std::cin , line)&& line!="done"){
        textlines[linecount++]=line;
    }
    if (linecount == MAX_LINES &&line !="done"){
        std::cout<<"maximum number of lines reached.\n";
    }
}
void displaylines(){
    std::cout<<"\n---current Text ---\n";
    for(int i=0; i<linecount ; ++i){
        std::cout<<i+1<<":"<<textlines[i]<<std::endl;

    }
    std::cout <<"------------\n";}
void insertline(){
    if (linecount >=MAX_LINES){
        std::cout<<"cannot insert more lines . maximum capacity reached.\n";
        return;
    }
    int position;
    std::cout<<"enter the line number to insert at(1-"<<linecount+1<<"):";
    std::cin>>position;
    std::cin.ignore();
    
if (position >=1 && position <= linecount+1){
    std::cout<<"enter the new line of text:";
    std::string newline;
    std::getline(std::cin ,newline);
     for(int i=linecount;i>=position -1;--i){
        textlines[i+1]=textlines[i];
         }
         textlines[position -1]=newline;
         linecount++;
         std::cout<<"line inserted sucessfully.\n";
}else{
    std::cout<<"invalid line number.\n";
}
}
void deleteline(){
    if (linecount==0){
        std::cout<<"No lines to delete.\n";
        return;
    }
    int position;
    std::cout<<"enter the line number to delete (1-"<<linecount<<"):";
    std::cin>>position;
    
if (position >=1 && position <= linecount+1){
    
     for(int i=position -1;i< linecount -1;--i){
        textlines[i]=textlines[i+1];
         }
         
         linecount--;
         std::cout<<"line deleted sucessfully.\n";
}else{
    std::cout<<"invalid line number.\n";
}
};

int main(){
    getinput();
    displaylines();
    char choice ;
    do{
        std::cout<<"\nchoose an action(i-insert , d-delete,s-show,q-quit);";
        std::cin>>choice;
        std::cin.ignore();

        switch(choice){
            case'i':
                 insertline();
                 break;
            case'd':
               deleteline();
               break;
            case 's':
                displaylines();
                break;
            case 'q':
                std::cout<<"exiting editor.\n";
                break;
            default:
             std::cout<<"invalid choice.please try again.\n";
        }
    } while (choice !='q');
    return 0;
    }

   
