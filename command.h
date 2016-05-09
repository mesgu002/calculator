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
    OpCommand(Command* cmd)
    {
        root = new UnaryOperator(cmd);
    }
    
};

class AddCommand : public Command {
	//AddCommand Code Here
    AddCommand( Command* cmd, int num)
    {
        root = new Add(cmd->get_root(), num);
    }
};

class SubCommand : public Command {
	//SubCommand Code Here
    SubCommand( Command* cmd, int num)
    {
        root = new Sub(cmd->get_root(), num);
    }
};

class MultCommand : public Command {
	//MultCommand Code Here
    MultCommand( Command* cmd, int num)
    {
        root = new Mult(cmd->get_root(), num);
    }
};

class SqrCommand : public Command {
	//SqrCommand Code Here
    SqrCommand( Command* cmd, int num)
    {
        root = new Sqr(cmd->get_root());
    }
};

#endif //__COMMAND_CLASS__
