#include <Ice/Ice.h>
#include <Hello.h>

using namespace std;
using namespace Demo;

int main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;

    try
    {

        ic = Ice::initialize(argc, argv);
        Ice::ObjectPrx base = ic->stringToProxy("hello:default -p 10000");
        HelloPrx hello = HelloPrx::checkedCast(base);
        if (!hello)
        {
            throw "Invalid proxy";
        }

        string result = "";
        result = hello->SayHello("liitdar");
        cout << "client's result: " << result << endl;
    }

    catch (const Ice::Exception& ex)
    {
        cerr << ex << endl;
        status = 1;
    }

    catch (const char* msg)
    {
        cerr << msg << endl;
        status = 1;
    }

    if (ic)
    {
        ic->destroy();
    }

    return status;

}
