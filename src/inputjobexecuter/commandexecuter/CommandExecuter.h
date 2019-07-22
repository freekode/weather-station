#ifndef CommandExecuter_H
#define CommandExecuter_H

class CommandExecuter
{
public:
    virtual void execute(char *params[]) = 0;
};

#endif