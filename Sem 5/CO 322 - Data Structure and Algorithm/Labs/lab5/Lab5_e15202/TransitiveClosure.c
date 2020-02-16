#include <stdio.h>
#include <stdlib.h>

void transitiveClosure(int graph[][7]){
	int reach[7][7],i,j,k;

	for(i = 0;i < 7;i++){
		for(j = 0;j < 7;j++){
			reach[i][j] = graph[i][j];
		}
	}

	for(k = 0;k < 7;k++){
		for(i = 0;i < 7;i++){
			for(j = 0;j < 7;j++){
				if(reach[i][k] && reach[k][j]){
					reach[i][j] = 1;
				}else{
					if(reach[i][j]){
						reach[i][j] = 1;
					}else{
						reach[i][j] = 0;
					}
				}
				
			}
		}
	}

	for(i = 0;i < 7;i++){
		for(j = 0;j < 7;j++){
			printf("%d ",reach[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int graph[7][7] = { {1,1,1,0,0,0,0},
						{0,1,0,0,1,0,0},
						{0,0,1,0,0,1,0},
						{0,1,0,1,1,0,1},
						{0,0,0,0,1,0,1},
						{0,0,0,1,0,1,0},
						{0,1,0,0,0,0,1}
					  };
	transitiveClosure(graph); 
	return 0;
}