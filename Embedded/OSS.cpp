#include <iostream>
#include <cstring>
using namespace std;
#include "Audio.h"

void usage(){
		cerr	<<	"usage: sound <options>\n" 
				<<	"options:\n"
				<<	"\tplay <filename>\n"
				<<	"\trec_mic <filename>\n"
				<<	"\trec_cd <filename>\n";
}
int main (int argc, char *argv []) {
	
	if(argc != 3){
		usage(); 
		return 0;
	}
	int mode;
	if(!strcmp(argv[1],"play")){
		mode=PLAY;
	}
	else if(!strcmp(argv[1],"rec_cd"))
		mode=REC_CD;
	else if(!strcmp(argv[1],"rec_mic"))
		mode=REC_MIC;
	else{
		usage();
		return 0;	
	}

	Audio *MusicDev = new Audio(mode,argv[2]);
	MusicDev->Set_Sample_Parameters();
	if(mode==PLAY){
		MusicDev -> Play();
	}
	else{
		if((MusicDev ->Set_Rec_Source(mode))!=-1){
			MusicDev -> Rec();
		}
	}
	delete MusicDev;

	return 0;
}
