#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
    private:
        int number;

    public:
        OpCommand(int num) : number(num) { };

    
};

class AddCommand : public Command {
	//AddCommand Code Here
    private:
        int number;
        Command* node1;

    public:
        AddCommand(Command* child1,int num) : node1(child1), number(num) { };

};

class SubCommand : public Command {
	//SubCommand Code Here
    private:
        int number;
        Command* node1;

    public:
        SubCommand(Command* child1,int num) : node1(child1), number(num) { };

};

class MultCommand : public Command {
	//MultCommand Code Here
    private:
        int number;
        Command* node1;

    public:
        MultCommand(Command* child1,int num) : node1(child1), number(num) { };

};

class SqrCommand : public Command {
	//SqrCommand Code Here
    private:
        int number:
        Command* node1;

    public:
        SqrCommand(Command* child1,int num) : node1(child1), number(num) { };
};

#endif //__COMMAND_CLASS__
