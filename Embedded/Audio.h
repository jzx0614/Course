#ifndef _AUDIO_H_
#define _AUDIO_H_
#endif /*_AUDIO_H_*/
enum{
	PLAY,
	REC_CD,
	REC_MIC
};
class Audio{
	public:
		Audio(int,char *);
		int Set_Sample_Parameters();
		void Play();
		int Set_Rec_Source(int);
		int Rec();
		~Audio();	
	private:
		signed short applicbuf[2048];
		char filename[30];
		int channels;
		int speed;
		int audio_fd;
};
