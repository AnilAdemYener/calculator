#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __linux__
	#define PLATFORM_NAME "linux"
#endif

int filecheck(char filename[25]){
	if(access(filename,F_OK)!=-1){
		return 0;
	} else {
		return 1;
	}
}

void install(int byte){
	char nwversion[25];
	if (byte==32){
		strcpy(nwversion,"nwjs-v0.40.1-linux-ia32");
	} else if (byte==64){
		strcpy(nwversion,"nwjs-v0.40.1-linux-x64");
	}
	// internetten indir
	char command1[100] = "wget https://dl.nwjs.io/v0.40.1/";
	strcat(command1,nwversion);
	strcat(command1,".tar.gz");
	system(command1);
	// tarball çıkar
	char command2[100] = "tar -xvf ";
	strcat(command2,nwversion);
	strcat(command2,".tar.gz");
	system(command2);
	// klasörü yeniden adlandır
	char command3[100] = "mv ";
	strcat(command3,nwversion);
	strcat(command3," nw");
	system(command3);
	// tarball sil
	char command4[100] = "rm -rf ";
	strcat(command4,nwversion);
	strcat(command4,".tar.gz");
	system(command4);
	// sisteme kopyala
	system("sudo mkdir /usr/bin/calculator");
	system("sudo cp -r * /usr/bin/calculator/");
	system("sudo cp -r calculator.desktop ~/.local/share/applications/calculator.desktop");
	return;
}

void uninstall(){
	system("sudo rm -rf /usr/bin/calculator");
	system("sudo rm -rf ~/.local/share/applications/calculator.desktop");
	return;
}

int main(int argc, char *argv[]){
	if (strcmp(PLATFORM_NAME, "linux")==0){
		if (argc > 1){
			if (strcmp(argv[1],"--install")==0){
				if (strcmp(argv[2],"32")==0){
					install(32);	
				} else if (strcmp(argv[2],"64")==0){
					install(64);
				}
			} else if (strcmp(argv[1],"--uninstall")==0){
				uninstall();
			}
		} else {
			char filename[25];
			strcpy(filename,"nw");
			if (filecheck(filename)==0){
				system("nw/nw .");
			} else {
				printf("nw bulunamadı!\n");
			}
		}
	}
	return 0;
}
