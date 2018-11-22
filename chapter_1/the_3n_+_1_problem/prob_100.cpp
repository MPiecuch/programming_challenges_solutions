/*
 * Author: Mateusz Piecuch
 * Problem: The 3n+1 Problem
 * UVA ID: 100
 * Date: 22.11.2018
 */

#include <cstdio>
#include <vector>
#include <map>

std::map<int, int> res_map;

void calc_3n_plus_1(int x) {
	std::vector<int> stack;
	while(!res_map[x] && x!=1) {
		stack.push_back(x);
		if(x%2==0) 
			x=x>>1;
		else
			x=x*3+1;
	}
	int last=x;
	for(int i=stack.size()-1;i>=0;i--) {
		res_map[stack[i]]=res_map[last]+1;
		last=stack[i];
	}
}

int main() {
	int i, j;
	res_map[1]=1;
	while(scanf("%d%d",&i,&j)!=EOF) {
		int result=0;
		int upper_bound=std::max(i,j);
		for(int x=std::min(i,j);x<=upper_bound;x++) {
			calc_3n_plus_1(x);
			result=std::max(result, res_map[x]);
		}
		printf("%d %d %d\n",i,j,result);
	}	

	return 0;
}
