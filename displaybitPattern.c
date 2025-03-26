#include <stdio.h>

void displayBitPattern(int val){
    int bit = (sizeof(val) * 4) - 1;
    unsigned int masked;
    for(masked = 1 << bit; masked > 0; masked >>= 1){
        if((bit + 1) % 4 == 0){
            printf(" ");
        }
        printf("%d", (val & masked) ? 1 : 0);
        bit--;
    }
}
int main(){
    displayBitPattern(2000000);
    return 0;
}