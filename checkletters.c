#include <stdio.h>

int main(){

    int letterCounts[26] = {0};
    int i;
    char ch;
    int answer = 1;

    while((ch=getchar())!='\n'){
        if(ch>=97 && ch<=122){
            letterCounts[(int)ch-97]++;
        }
    }

    while((ch=getchar())!='\n'){
        if(ch>=97 && ch<=122){
            letterCounts[(int)ch-97]--;
        }
    }

    for(i=0;i<26;i++){
        if(letterCounts[i]!=0){
            answer = 0;
            break;
        }
    }

    if(answer){
        printf("Anagram\n");
    }
    else{
        printf("Not Anagram\n");
    }

    return 0;
}
