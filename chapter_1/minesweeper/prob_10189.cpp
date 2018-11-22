/*
 * Author: Mateusz Piecuch
 * Problem: Minesweeper
 * UVA ID: 10189
 */

#include <cstdio>

char field[100][100];

int main() {
    int n,m,field_num=1;
    while(1) {
        scanf("%d %d\n",&n,&m);
        if(!n) break;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) 
                scanf("%c",&field[i][j]);
            getchar();
        }
        if(field_num>1) putchar('\n');
        printf("Field #%d:\n",field_num);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++)
                if(field[i][j]=='*')
                    putchar('*');
                else {
                    int mines=0;
                    for(int delta_i=-1;delta_i<=1;delta_i+=1)
                        for(int delta_j=-1;delta_j<=1;delta_j+=1)
                            if(i+delta_i>=0 && i+delta_i<n &&
                               j+delta_j>=0 && j+delta_j<m &&
                               field[i+delta_i][j+delta_j]=='*')
                                mines+=1;
                    printf("%d",mines);
                }
            putchar('\n');
        }
        field_num+=1;
    }
    return 0;
}
