#include "../include/DriverMissionHandler.hpp"
#include "../include/Util.hpp"
class InputHandler
{
public:
    InputHandler();
    ~InputHandler();

    void update(string &line);
private:
    DriverMissionHandler Snapp;
    Util UtilFunctions;
};
