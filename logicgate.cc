#include<iostream>
#include<string>

using namespace std;

class logicgate
{
    string command;
    private:
        enum { OFF, ON};
        int InputA, InputB;
        void Init_Template();
        void GetGateInput_1();
        void GetGateInput_2();
        void validate_Gate_Command();
        bool MatchString(string str1, string str2);
        bool CompareCommand(string cmd);
        void getcommand();
        void parseCommand();
        void ClearTerminal();

        void __INIT_GATE();
        // OR gate
        int __RENDER_OR_GATE_ANSWER();
        void DISPLAY_OR_GATE_ANSWER();

        // AND Gate
        int __RENDER_AND_GATE_ANSWER();
        void DISPLAY_AND_GATE_ANSWER();

        // NOT Gate
        int __RENDER_NOT_GATE_ANSWER();
        void DISPLAY_NOT_GATE_ANSWER();

        // NAND Gate
        int __RENDER_NAND_GATE_ANSWER();
        void DISPLAY_NAND_GATE_ANSWER();

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
        "3. NOT Gate.",
        "4. NAND Gate."
        };
    cout<<endl;
    cout<<"Choose a option, which you want to test"<<endl;
    for (size_t i = 0; i < 4; i++)
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
    if((logicgate::InputA == logicgate::OFF || logicgate::InputA == logicgate::ON) && (logicgate::InputB == logicgate::OFF || logicgate::InputB == logicgate::ON)){
        if (logicgate::CompareCommand("1"))
        {
            logicgate::DISPLAY_OR_GATE_ANSWER();
        }else if(logicgate::CompareCommand("2")){
            logicgate::DISPLAY_AND_GATE_ANSWER();
        }else if(logicgate::CompareCommand("4")){
            logicgate::DISPLAY_NAND_GATE_ANSWER();
        }
        
    }else{


        if(logicgate::CompareCommand("3")){
                if (logicgate::InputA == logicgate::ON || logicgate::InputA == logicgate::OFF)
                {
                    logicgate::DISPLAY_NOT_GATE_ANSWER();
                }else{
                    cout<<"Invalid. Only 1 and 0 is acceptable. "<<endl;
                    logicgate::GetGateInput_1();
                }
        }else{
            cout<<"Invalid. Only 1 and 0 is acceptable. "<<endl;
            logicgate::GetGateInput_2();
        }
    }
};

int logicgate::__RENDER_OR_GATE_ANSWER(){
    if ((InputA == logicgate::OFF && InputB == logicgate::ON) || (InputA == logicgate::ON && InputB == logicgate::OFF) || (InputA == logicgate::ON && InputB == logicgate::ON))
    {
        return logicgate::ON;
    }else if(InputA == logicgate::OFF && InputB == logicgate::OFF){
        return logicgate::OFF;
    }else{
        cout<<"Unexpected error"<<endl;
        exit(0);
    }
    
}

int logicgate::__RENDER_AND_GATE_ANSWER(){
    if((InputA == logicgate::OFF && InputB == logicgate::OFF) || (InputA == logicgate::ON && InputB == logicgate::OFF) || (InputA == logicgate::OFF && InputB == logicgate::ON))
    {
        return logicgate::OFF;
    }else if(InputA == logicgate::ON && InputB == logicgate::ON){
        return logicgate::ON;
    }else{
        cout<<"Unexpected error"<<endl;
        exit(0);
    }
}

int logicgate::__RENDER_NOT_GATE_ANSWER(){
    if(InputA == logicgate::ON){
        return logicgate::OFF;
    }else if(InputA == logicgate::OFF){
        return logicgate::ON;
    }else{
        cout<<"Unexpected error"<<endl;
        exit(0);
    }
}

int logicgate::__RENDER_NAND_GATE_ANSWER(){
    logicgate::InputA = logicgate::__RENDER_AND_GATE_ANSWER();
    return logicgate::__RENDER_NOT_GATE_ANSWER();
}



void logicgate::DISPLAY_OR_GATE_ANSWER(){
    cout<<endl;
    cout<<"YOUR OR GATE OUTPUT IS: "<<logicgate::__RENDER_OR_GATE_ANSWER()<<endl;
}

void logicgate::DISPLAY_AND_GATE_ANSWER(){
    cout<<endl;
    cout<<"YOUR AND GATE OUTPUT IS: "<<logicgate::__RENDER_AND_GATE_ANSWER()<<endl;
}

void logicgate::DISPLAY_NOT_GATE_ANSWER(){
    cout<<endl;
    cout<<"YOUR NOT GATE OUTPUT IS: "<<logicgate::__RENDER_NOT_GATE_ANSWER()<<endl;
}

void logicgate::DISPLAY_NAND_GATE_ANSWER(){
    cout<<endl;
    cout<<"YOUR NAND GATE OUTPUT IS: "<<logicgate::__RENDER_NAND_GATE_ANSWER()<<endl;
}

void logicgate::GetGateInput_1(){
    cout<<"Input A: ";
    cin>>logicgate::InputA;
    logicgate::validate_Gate_Command();
}

void logicgate::GetGateInput_2()
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


void logicgate::__INIT_GATE()
{
    if(logicgate::CompareCommand("3")){
        logicgate::GetGateInput_1();
    }else{
        logicgate::GetGateInput_2();
    }
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

    }else if(logicgate::CompareCommand("1") || logicgate::CompareCommand("2") ||  logicgate::CompareCommand("3") ||  logicgate::CompareCommand("4")){
        logicgate::__INIT_GATE();
    
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