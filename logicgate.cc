#include<iostream>
#include<string>

using namespace std;

class logicgate
{
    string command;
    private:
        int InputA, InputB;
        void Init_Template();
        void GetGateInputCommand();
        void validate_Gate_Command();
        bool MatchString(string str1, string str2);
        bool CompareCommand(string cmd);
        void getcommand();
        void parseCommand();
        void ClearTerminal();

        // or gate
        void __INIT_OR_GATE();
        int __RENDER_OR_GATE_ANSWER();
        void DISPLAY_OR_GATE_ANSWER();

        // os based methods
        bool CheckOs(string OS);

    public:
        void run();
        
};

bool logicgate::CheckOs(string OS)
{
            string SystemOs;
            #if defined(_WIN32)
                SystemOs = "windows";
            #elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
                SystemOs = "unix";
            #elif defined(__APPLE__)
                SystemOs = "apple";
            #else
                SystemOs = "none";
            #endif

            return logicgate::MatchString(SystemOs, OS);
            
            
}

void logicgate::Init_Template()
{
    string options[] = {
        "1. OR Gate.",
        "2. AND Gate.",
        "3. NOT Gate."
        };
    cout<<endl;
    cout<<"Choose a option, which you want to test"<<endl;
    for (size_t i = 0; i < 3; i++)
    {
        cout<<endl;
        cout<<options[i]<<endl;
    }
    
};

bool logicgate::MatchString(string str1, string str2)
{
    if(str1.compare(str2) == 0){
        return true;
    }else{
        return false;
    }
};

bool logicgate::CompareCommand(string cmd)
{
    return logicgate::MatchString(command, cmd);
}

void logicgate::validate_Gate_Command()
{
    if((logicgate::InputA == 0 || logicgate::InputA == 1) && (logicgate::InputB == 0 || logicgate::InputB == 1)){
        logicgate::DISPLAY_OR_GATE_ANSWER();
    }else{
        cout<<"Input A and Input B is Invalid. Only 1 and 0 is acceptable. "<<endl;
        logicgate::GetGateInputCommand();
    }
};

int logicgate::__RENDER_OR_GATE_ANSWER(){
    if ((InputA == 0 && InputB == 1) || (InputA == 1 && InputB == 0) || (InputA == 1 && InputB == 1))
    {
        return 1;
    }else if(InputA == 0 && InputB == 0){
        return 0;
    }else{
        cout<<"Unexpected error"<<endl;
        exit(0);
    }
    
}

void logicgate::DISPLAY_OR_GATE_ANSWER(){
    cout<<endl;
    cout<<"YOUR OR GATE OUTPUT IS: "<<logicgate::__RENDER_OR_GATE_ANSWER()<<endl;
}

void logicgate::GetGateInputCommand()
{

    cout<<"Input A: ";
    cin>>logicgate::InputA;
    cout<<"Input B: ";
    cin>>logicgate::InputB;
    logicgate::validate_Gate_Command();
};
void logicgate::ClearTerminal()
{
    if (logicgate::CheckOs("apple"))
    {
        system("clear");
    }else if(logicgate::CheckOs("windows")){
        system("cls");
    }else{
        system("clear");
    }
    
};


void logicgate::__INIT_OR_GATE()
{
    logicgate::GetGateInputCommand();
}

void logicgate::parseCommand()
{
    if (logicgate::CompareCommand("help"))
    {
        logicgate::Init_Template();
    
    }else if(logicgate::CompareCommand("exit")){
        
        exit(0);
    }else if(logicgate::CompareCommand("clear")){
        logicgate::ClearTerminal();

    }else if(logicgate::CompareCommand("1")){
        logicgate::__INIT_OR_GATE();

    }else{
        cout<<"`"<<command<<"`"<<" Command Not found"<<endl;
    }
    
    
    logicgate::getcommand();
}

void logicgate::getcommand()
{
    cout<<">>> ";
    cin>>logicgate::command;
    logicgate::parseCommand();

}


void logicgate::run()
{
    logicgate::Init_Template();
    logicgate::getcommand();
    
}
int main()
{
    logicgate initlogic;
    initlogic.run();
    return 0;
}