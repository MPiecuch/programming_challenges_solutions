/*
 * Author: Mateusz Piecuch
 * Problem: Jolly Jumpers
 * UVA ID: 10038
 * Date: 24.11.2018
 */

#include <cstdio>
#include <cstdlib>

bool used[3000];

int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0;i<n;i++) used[i]=false;
        int actual, last=-1;
        for(int i=0;i<n;i++) {
            scanf("%d",&actual);
            if(i>0) {
                int diff=abs(actual-last);
                used[diff]=true;
            }
            last=actual;
        }
        bool jolly=true;
        for(int i=1;i<n;i++)
            if(!used[i]) {
                jolly=false;
                break;
            }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
