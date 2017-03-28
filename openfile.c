#include <stdio.h>
#include <errno.h>

int main() {
        char *filename;
	FILE *file;
 	filename="/home/sagus/CLionProjects/IQ/RMA01_9005_01_20160224T194902_623Z_02.IQ";
        file=fopen(filename, "r");
	if(file==NULL){
                printf("Err %d \n", errno);
                return 0;
        }
	fclose(file);
        return 0;
}
