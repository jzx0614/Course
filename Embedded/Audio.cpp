#include <iostream>
#include <cstring>
using namespace std;


#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>

#include "Audio.h"

//==============================================================================
// Class Audio
//==============================================================================
Audio::Audio(int mode,char *FileName){	
	if(mode==PLAY)
			mode = O_WRONLY;
	else if(mode==REC_CD||mode==REC_MIC)
			mode = O_RDONLY;
 
	strcpy(filename,FileName);

	if ((audio_fd = open ("/dev/dsp", mode, 0)) == -1) {
		cerr << "open error: /dev/dsp\n";
	}
}

int Audio::Set_Sample_Parameters(){

	int format = AFMT_S16_NE;
	channels = 2;
	speed = 44100;
	
	
	if (ioctl (audio_fd, SNDCTL_DSP_SETFMT, &format) == -1) {
		cerr << "ioctl error: SNDCTL_DSP_SETFMT\n";
		return -1;
	}
	
	if (ioctl (audio_fd, SNDCTL_DSP_CHANNELS, &channels) == -1) {
		cerr << "ioctl error: SNDCTL_DSP_CHANNELS\n";
		return -1;
	}
	
	if (ioctl (audio_fd, SNDCTL_DSP_SPEED, &speed) == -1) {
		cerr << "ioctl error: SNDCTL_DSP_SPEED\n";
		return -1;
	}
	else 
		cout << "Support 44.1 KHz, Actual Speed: " << speed << endl;
	return 1;
}
void Audio::Play(){
	int music_fd;
	int count;
	if ((music_fd = open (filename, O_RDONLY, 0)) == -1) {
		cerr << "open error: " << filename << endl;
		return;
	}
	while ((count = read (music_fd, applicbuf, 2048)) > 0)
		write (audio_fd, applicbuf, count); 	
	close(music_fd);
}
int Audio::Set_Rec_Source(int mode){
	int mixer_fd;
	if ((mixer_fd = open ("/dev/mixer", O_WRONLY)) == -1) {
		cerr << "open error: /dev/mixer\n";
		return -1;
	}
	int rec_src = (mode==REC_CD) ?(1<<SOUND_MIXER_CD):(1<<SOUND_MIXER_MIC);
	if (ioctl(mixer_fd, SOUND_MIXER_WRITE_RECSRC, &rec_src) == -1) {
		cerr << "ioctl error: SOUND_MIXER_WRITE_RECSRC \n";
		return -1;
	}
	close (mixer_fd);
	return 1;
}
int Audio::Rec(){
	int music_fd;
	if((music_fd=open(filename,O_WRONLY|O_CREAT,0))==1){
		cerr << "open error: " << filename <<endl;
		return -1;
	}	
	int totalword =speed * channels * 2 * 60 * 3 / 2;
	int total_rec=0;
	int count;
	while(total_rec < totalword){
		count = (total_rec+2048 < totalword) ? 2048 : totalword-total_rec;
		read(audio_fd,applicbuf,count);
		write(music_fd,applicbuf,count);
	}
	close(music_fd);
	return 1;
}
Audio::~Audio(){
	close(audio_fd);
}

