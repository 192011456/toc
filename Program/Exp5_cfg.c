// To write a C program to check whether a string belongs to the grammar
// S -> 0 S 0 | A
// A -> 1 A | ε

#include<stdio.h>
#include<string.h>

int checkValidity(char ip[], int l){

    int iv = 0;

    for(int i = 0;i<l;i++){
        if(ip[i] == '0' || ip[i] == '1')
            continue;
        else{
            iv = 1;
            break;
        }
    }

    return iv;
}

int main(){
    char input[100];
    int count1 = 0;
    int count2 = 0;
    while(1){

        printf("Enter a String : ");
        scanf("%s",&input);

        int l = strlen(input);

        int invalid = checkValidity(input,l);

        for(int i = 0;i<l;i++){
            if(input[i] == '1' && input[i+1] == '0' && input[i+2] == '1'){
                invalid = 1;
            }
        }
        if(invalid != 1){

            int count1 = 0;
            int count2 = 0;
            
            for(int i = 0;i<l;i++){
                if(input[i] == '0')
                    count1+=1;
                else if(input[i] == '1'){
                    break;
                }
            }

            for(int i = l-1;i>=0;i--){
                if(input[i] == '0')
                    count2+=1;
                else if(input[i] == '1'){
                    break;
                }
            }

            if(count1 > 0 && count2 > 0){
                if(count1 == count2)
                    printf("String Accepted ! \n\n");
                else    
                    printf("String Rejected ! \n\n");
            }
            else
                printf("String Rejected ! \n\n");
        }
        else
            printf("Enter a Valid String over E = {0,1}.\n1's and 0's should be in a continuos pattern. \n\n");
    }

    return 0;
}
