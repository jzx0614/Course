// Class automatically generated by Dev-C++ New Class wizard

#ifndef ADDRESSING_H
#define ADDRESSING_H

// No description
class Addressing
{
    public:
        void set(char*,int,char*);
        int getformat(){return Format;};
        char* getmode(){return Mnem;};
        char* getop(){return Opcode;};
        void show();
    private:
        char Mnem[10];		
        char Opcode[3];
        int Format;
};

#endif // ADDRESSING_H

